import rclpy
from rclpy.node import Node
from carla_msgs.msg import CarlaEgoVehicleControl
import sys
import termios
import tty

class KeyboardControlNode(Node):
    def __init__(self):
        super().__init__('keyboard_vehicle_control')
        self.publisher_ = self.create_publisher(CarlaEgoVehicleControl, '/carla/hero/vehicle_control_cmd', 10)
        self.get_logger().info('Keyboard control node started. Use WASD keys to drive.')
        self.run()

    def get_key(self):
        fd = sys.stdin.fileno()
        old_settings = termios.tcgetattr(fd)
        try:
            tty.setraw(fd)
            key = sys.stdin.read(1)
        finally:
            termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
        return key

    def run(self):
        throttle = 0.0
        steer = 0.0
        brake = 0.0
        reverse = False

        while rclpy.ok():
            key = self.get_key()

            if key == 'w':
                throttle = min(throttle + 0.1, 1.0)
            elif key == 's':
                throttle = max(throttle - 0.1, 0.0)
            elif key == 'a':
                steer = max(steer - 0.1, -1.0)
            elif key == 'd':
                steer = min(steer + 0.1, 1.0)
            elif key == ' ':  # Spacebar for braking
                brake = min(brake + 0.2, 1.0)
            elif key == 'r':  # Toggle reverse
                reverse = not reverse
            elif key == 'q':  # Quit
                self.get_logger().info('Exiting keyboard control node.')
                break
            
            msg = CarlaEgoVehicleControl()
            msg.throttle = throttle
            msg.steer = steer
            msg.brake = brake
            msg.hand_brake = False
            msg.reverse = reverse
            msg.manual_gear_shift = False
            
            self.publisher_.publish(msg)
            self.get_logger().info(f'Published: Throttle={throttle}, Steer={steer}, Brake={brake}, Reverse={reverse}')


def main(args=None):
    rclpy.init(args=args)
    node = KeyboardControlNode()
    rclpy.shutdown()

if __name__ == '__main__':
    main()