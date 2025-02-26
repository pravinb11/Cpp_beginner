#!/usr/bin/env python

# Copyright (c) 2021 Computer Vision Center (CVC) at the Universitat Autonoma de
# Barcelona (UAB).
#
# This work is licensed under the terms of the MIT license.
# For a copy, see <https://opensource.org/licenses/MIT>.

"""Example script to generate traffic in the simulation"""

import glob
import os
import sys
import time

try:
    sys.path.append(glob.glob('../carla/dist/carla-*%d.%d-%s.egg' % (
        sys.version_info.major,
        sys.version_info.minor,
        'win-amd64' if os.name == 'nt' else 'linux-x86_64'))[0])
except IndexError:
    pass

import carla

from carla import VehicleLightState as vls

import argparse
import logging
from numpy import random

def get_actor_blueprints(world, filter, generation):
    bps = world.get_blueprint_library().filter(filter)

    if generation.lower() == "all":
        return bps

    # If the filter returns only one bp, we assume that this one needed
    # and therefore, we ignore the generation
    if len(bps) == 1:
        return bps

    try:
        int_generation = int(generation)
        # Check if generation is in available generations
        if int_generation in [1, 2]:
            bps = [x for x in bps if int(x.get_attribute('generation')) == int_generation]
            return bps
        else:
            print("   Warning! Actor Generation is not valid. No actor will be spawned.")
            return []
    except:
        print("   Warning! Actor Generation is not valid. No actor will be spawned.")
        return []

def main():
    argparser = argparse.ArgumentParser(
        description=__doc__)
    argparser.add_argument(
        '--host',
        metavar='H',
        default='127.0.0.1',
        help='IP of the host server (default: 127.0.0.1)')
    argparser.add_argument(
        '-p', '--port',
        metavar='P',
        default=2000,
        type=int,
        help='TCP port to listen to (default: 2000)')
    argparser.add_argument(
        '-n', '--number-of-vehicles',
        metavar='N',
        default=1,
        type=int,
        help='Number of vehicles (default: 30)')
    argparser.add_argument(
        '-w', '--number-of-walkers',
        metavar='W',
        default=0,
        type=int,
        help='Number of walkers (default: 10)')
    argparser.add_argument(
        '--safe',
        action='store_true',
        help='Avoid spawning vehicles prone to accidents')
    argparser.add_argument(
        '--filterv',
        metavar='PATTERN',
        default='vehicle.*',
        help='Filter vehicle model (default: "vehicle.*")')
    argparser.add_argument(
        '--generationv',
        metavar='G',
        default='All',
        help='restrict to certain vehicle generation (values: "1","2","All" - default: "All")')
    argparser.add_argument(
        '--filterw',
        metavar='PATTERN',
        default='walker.pedestrian.*',
        help='Filter pedestrian type (default: "walker.pedestrian.*")')
    argparser.add_argument(
        '--generationw',
        metavar='G',
        default='2',
        help='restrict to certain pedestrian generation (values: "1","2","All" - default: "2")')
    argparser.add_argument(
        '--tm-port',
        metavar='P',
        default=8000,
        type=int,
        help='Port to communicate with TM (default: 8000)')
    argparser.add_argument(
        '--asynch',
        action='store_true',
        help='Activate asynchronous mode execution')
    argparser.add_argument(
        '--hybrid',
        action='store_true',
        help='Activate hybrid mode for Traffic Manager')
    argparser.add_argument(
        '-s', '--seed',
        metavar='S',
        type=int,
        help='Set random device seed and deterministic mode for Traffic Manager')
    argparser.add_argument(
        '--seedw',
        metavar='S',
        default=0,
        type=int,
        help='Set the seed for pedestrians module')
    argparser.add_argument(
        '--car-lights-on',
        action='store_true',
        default=False,
        help='Enable automatic car light management')
    argparser.add_argument(
        '--hero',
        action='store_true',
        default=False,
        help='Set one of the vehicles as hero')
    argparser.add_argument(
        '--respawn',
        action='store_true',
        default=False,
        help='Automatically respawn dormant vehicles (only in large maps)')
    argparser.add_argument(
        '--no-rendering',
        action='store_true',
        default=False,
        help='Activate no rendering mode')

    args = argparser.parse_args()

    logging.basicConfig(format='%(levelname)s: %(message)s', level=logging.INFO)

    vehicles_list = []
    walkers_list = []
    all_id = []
    client = carla.Client(args.host, args.port)
    client.set_timeout(10.0)
    
    synchronous_master = False
    random.seed(args.seed if args.seed is not None else int(time.time()))

    try:
        world = client.get_world()

        # Check if the map has a navigation mesh
        if world.get_map().get_spawn_points():
            print("Map has spawn points, likely has NavMesh.")
        else:
            print("Map may not have a NavMesh.")

        print("Check 1")
        loc = world.get_random_location_from_navigation()
        print("Check 2")
        if loc is None:
            print("No valid navigation location found!")
        else:
            print(f"Found location: {loc}")

        traffic_manager = client.get_trafficmanager(args.tm_port)
        traffic_manager.set_global_distance_to_leading_vehicle(2.5)
        if args.respawn:
            traffic_manager.set_respawn_dormant_vehicles(True)
        if args.hybrid:
            traffic_manager.set_hybrid_physics_mode(True)
            traffic_manager.set_hybrid_physics_radius(70.0)
        if args.seed is not None:
            traffic_manager.set_random_device_seed(args.seed)

        settings = world.get_settings()
        if not args.asynch:
            traffic_manager.set_synchronous_mode(True)
            if not settings.synchronous_mode:
                synchronous_master = True
                settings.synchronous_mode = True
                settings.fixed_delta_seconds = 0.05
            else:
                synchronous_master = False
        else:
            print("You are currently in asynchronous mode. If this is a traffic simulation, \
            you could experience some issues. If it's not working correctly, switch to synchronous \
            mode by using traffic_manager.set_synchronous_mode(True)")

        if args.no_rendering:
            settings.no_rendering_mode = True
        world.apply_settings(settings)

        blueprints = get_actor_blueprints(world, args.filterv, args.generationv)
        blueprintsWalkers = get_actor_blueprints(world, args.filterw, args.generationw)

        if args.safe:
            blueprints = [x for x in blueprints if int(x.get_attribute('number_of_wheels')) == 4]
            blueprints = [x for x in blueprints if not x.id.endswith('microlino')]
            blueprints = [x for x in blueprints if not x.id.endswith('carlacola')]
            blueprints = [x for x in blueprints if not x.id.endswith('cybertruck')]
            blueprints = [x for x in blueprints if not x.id.endswith('t2')]
            blueprints = [x for x in blueprints if not x.id.endswith('sprinter')]
            blueprints = [x for x in blueprints if not x.id.endswith('firetruck')]
            blueprints = [x for x in blueprints if not x.id.endswith('ambulance')]

        blueprints = sorted(blueprints, key=lambda bp: bp.id)

        spawn_points = world.get_map().get_spawn_points()
        ## Print spawn_points
        # for i, sp in enumerate(spawn_points):
        #     print(f"Spawn Point {i}: Location({sp.location.x}, {sp.location.y}, {sp.location.z}), "
        #             f"Rotation({sp.rotation.pitch}, {sp.rotation.yaw}, {sp.rotation.roll})")

        number_of_spawn_points = len(spawn_points)

        ## Print the number of spawn point
        # print(f"number of Spawn point is {number_of_spawn_points}")

        


        if args.number_of_vehicles < number_of_spawn_points:
            random.shuffle(spawn_points)
        elif args.number_of_vehicles > number_of_spawn_points:
            msg = 'requested %d vehicles, but could only find %d spawn points'
            logging.warning(msg, args.number_of_vehicles, number_of_spawn_points)
            args.number_of_vehicles = number_of_spawn_points

        # @todo cannot import these directly.
        SpawnActor = carla.command.SpawnActor
        SetAutopilot = carla.command.SetAutopilot
        FutureActor = carla.command.FutureActor
        

        
        # --------------
        # Spawn vehicles
        # --------------
        batch = []
        hero = args.hero

        print("Starting vehicle spawn process...")

        for n, transform in enumerate(spawn_points):
            if n >= args.number_of_vehicles:
                break
            
            blueprint = random.choice(blueprints)
            print(f"\n[Vehicle {n+1}] Selected Blueprint: {blueprint.id}")

            if blueprint.has_attribute('color'):
                color = random.choice(blueprint.get_attribute('color').recommended_values)
                blueprint.set_attribute('color', color)
                print(f"  - Assigned Color: {color}")
                
            if blueprint.has_attribute('driver_id'):
                driver_id = random.choice(blueprint.get_attribute('driver_id').recommended_values)
                blueprint.set_attribute('driver_id', driver_id)
                print(f"  - Assigned Driver ID: {driver_id}")

            if hero:
                blueprint.set_attribute('role_name', 'hero')
                print("  - Assigned Role: Hero")
                hero = False

            else:
                blueprint.set_attribute('role_name', 'autopilot')
                print("  - Assigned Role: Autopilot")

            # spawn the cars and set their autopilot and light state all together
            print(f"  - Spawning at location: ({transform.location.x}, {transform.location.y}, {transform.location.z})")
    
            batch.append(SpawnActor(blueprint, transform)
                .then(SetAutopilot(FutureActor, True, traffic_manager.get_port())))

        print("\nSending batch spawn request to server...")
        for response in client.apply_batch_sync(batch, synchronous_master):
            if response.error:
                logging.error(response.error)
                
            else:
                vehicles_list.append(response.actor_id)
                print(f"  - Vehicle Spawned with ID: {response.actor_id}")

        # print(f"\nTotal vehicles spawned: {len(vehicles_list)}")

        # Set automatic vehicle lights update if specified
        
        if args.car_lights_on:
            all_vehicle_actors = world.get_actors(vehicles_list)
            for actor in all_vehicle_actors:
                traffic_manager.update_vehicle_lights(actor, True)
                
        ## Print all the actors    
        all_vehicle_actors = world.get_actors(vehicles_list)
        for actor in all_vehicle_actors:
                print(f"Vehicle ID: {actor.id}, Type: {actor.type_id}, Location: ({actor.get_location().x}, {actor.get_location().y}, {actor.get_location().z})")

        # -------------
        # Spawn Walkers

        # create several pedestrians 
        print("CheckA 1")
        blueprints = world.get_blueprint_library().filter("walker.pedestrian.*")
        pedestrians = []
        print("CheckA 2")
        pedestrians.append(world.spawn_actor(random.choice(blueprints), world.get_random_location_from_navigation()))
        pedestrians.append(world.spawn_actor(random.choice(blueprints), world.get_random_location_from_navigation()))
        print("CheckA 3")

        # get the 3d bones from all pedestrians 
        for ped in pedestrians:
            bones = ped.get_bones()

        print("CheckA 4")
        # modify some bones 
        new_pose = []
        for bone in bones.bone_transforms:
            if bone.name == "crl_foreArm__L":
                bone.relative.rotation.pitch -= 90
                new_pose.append((bone.name, bone.relative))
            elif bone.name == "crl_foreArm__R":
                bone.relative.rotation.pitch -= 90
                new_pose.append((bone.name, bone.relative))

        # set the new pose 
        control = carla.WalkerBoneControlIn()
        control.bone_transforms = new_pose
        ped.set_bones(control)

        # blend the pose 
        actor.blend_pose(0.5)
        
        # -------------
        # some settings
        percentagePedestriansRunning = 0.0      # how many pedestrians will run
        percentagePedestriansCrossing = 0.0     # how many pedestrians will walk through the road

        print(f"Percentage of running pedestrians: {percentagePedestriansRunning}")
        print(f"Percentage of crossing pedestrians: {percentagePedestriansCrossing}")


        print("Check 1")

        if args.seedw:
            print("Check 2")
            world.set_pedestrians_seed(args.seedw)
            print("Check 3")
            random.seed(args.seedw)
            print("Check 4")
            print(f"Set world pedestrian seed to {args.seedw}")

        print("Check 5")
        

        # 1. take all the random locations to spawn
        spawn_points = []
        for i in range(args.number_of_walkers):
            print("Check 6")
            spawn_point = carla.Transform()
            print("Check 7")
            loc = world.get_random_location_from_navigation()
            print("Check 8")
            if (loc != None):
                print("Check 9")
                spawn_point.location = loc
                print("Check 10")
                spawn_points.append(spawn_point)
                print(f"Walker {i} will spawn at location: {loc}")
            else:
                print(f"Walker {i} has no valid spawn location")

        # 2. we spawn the walker object
        print("Check 11")
        batch = []
        walker_speed = []
        for spawn_point in spawn_points:
            walker_bp = random.choice(blueprintsWalkers)

            # set as not invincible
            if walker_bp.has_attribute('is_invincible'):
                walker_bp.set_attribute('is_invincible', 'false')

            # set the max speed
            if walker_bp.has_attribute('speed'):
                if (random.random() > percentagePedestriansRunning):
                    # walking
                    walker_speed.append(walker_bp.get_attribute('speed').recommended_values[1])
                else:
                    # running
                    walker_speed.append(walker_bp.get_attribute('speed').recommended_values[2])
            else:
                print("Walker has no speed")
                walker_speed.append(0.0)
            
            print(f"Walker {i} blueprint selected: {walker_bp.id}, speed: {walker_speed[-1]}")

            batch.append(SpawnActor(walker_bp, spawn_point))

        results = client.apply_batch_sync(batch, True)
        walker_speed2 = []
        for i in range(len(results)):
            if results[i].error:
                logging.error(results[i].error)
            else:
                walkers_list.append({"id": results[i].actor_id})
                walker_speed2.append(walker_speed[i])
                print(f"Walker {i} spawned with ID: {results[i].actor_id}")

        walker_speed = walker_speed2
        # 3. we spawn the walker controller
        batch = []
        walker_controller_bp = world.get_blueprint_library().find('controller.ai.walker')
        for i in range(len(walkers_list)):
            batch.append(SpawnActor(walker_controller_bp, carla.Transform(), walkers_list[i]["id"]))
            print(f"Walker {i} assigned AI controller")

        results = client.apply_batch_sync(batch, True)
        for i in range(len(results)):
            if results[i].error:
                logging.error(results[i].error)
            else:
                walkers_list[i]["con"] = results[i].actor_id
                print(f"Walker controller {i} spawned with ID: {results[i].actor_id}")

        # 4. we put together the walkers and controllers id to get the objects from their id
        for i in range(len(walkers_list)):
            all_id.append(walkers_list[i]["con"])
            all_id.append(walkers_list[i]["id"])

        print(f"Total actors (walkers + controllers): {len(all_id)}")

        all_actors = world.get_actors(all_id)

        # wait for a tick to ensure client receives the last transform of the walkers we have just created
        if args.asynch or not synchronous_master:
            world.wait_for_tick()
            print("World ticked in asynchronous mode")

        else:
            world.tick()
            print("World ticked in synchronous mode")

        # 5. initialize each controller and set target to walk to (list is [controler, actor, controller, actor ...])
        # set how many pedestrians can cross the road
        world.set_pedestrians_cross_factor(percentagePedestriansCrossing)
        print(f"Set pedestrian cross factor: {percentagePedestriansCrossing}")

        for i in range(0, len(all_id), 2):
            # start walker
            all_actors[i].start()
            # set walk to random point
            all_actors[i].go_to_location(world.get_random_location_from_navigation())
            # max speed
            all_actors[i].set_max_speed(float(walker_speed[int(i/2)]))
            print(f"Walker {i//2} (ID: {all_id[i+1]}) moving to {world.get_random_location_from_navigation()} with speed {float(walker_speed[int(i/2)])}")

        print('spawned %d vehicles and %d walkers, press Ctrl+C to exit.' % (len(vehicles_list), len(walkers_list)))

        # Example of how to use Traffic Manager parameters
        traffic_manager.global_percentage_speed_difference(30.0)

        while True:
            if not args.asynch and synchronous_master:
                world.tick()
            else:
                world.wait_for_tick()

    finally:

        if not args.asynch and synchronous_master:
            settings = world.get_settings()
            settings.synchronous_mode = False
            settings.no_rendering_mode = False
            settings.fixed_delta_seconds = None
            world.apply_settings(settings)

        print('\ndestroying %d vehicles' % len(vehicles_list))
        client.apply_batch([carla.command.DestroyActor(x) for x in vehicles_list])

        # stop walker controllers (list is [controller, actor, controller, actor ...])
        for i in range(0, len(all_id), 2):
            all_actors[i].stop()

        print('\ndestroying %d walkers' % len(walkers_list))
        client.apply_batch([carla.command.DestroyActor(x) for x in all_id])

        time.sleep(0.5)

if __name__ == '__main__':

    try:
        main()
    except KeyboardInterrupt:
        pass
    finally:
        print('\ndone.')
