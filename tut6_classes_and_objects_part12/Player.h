/*
Static Class Members
* Class data members can be declared as static
    * A single data member that belongs to the class, not the objects
    * Useful to store class-wide information

* Class functions can be declared as static
    * Independent of any objects
    * Can be called using the class name 

class Player {
private:
    static int num_players;
public:
    static int get_num_players();
    . . .
};

Player class - initialize the static data
Typically in Player.cpp

#include "Player.h"

int Player::num_players = 0;

Player class - implement static method

// It has access to only static data members 
int Player::get_num_players() {
    return num_players;
}

Player class - update the constructor

Player::Player (std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    ++num_players;
}

Player::~Player() {
    --num_players;
}

*/

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include<string>

class Player
{
private:
    static int num_players;
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() {return name;}
    int get_health() { return health; }
    int get_xp() {return xp;}
    Player(std::string name_val="None", int health_val=0, int xp_val=0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player();

    static int get_num_players();
    
};

#endif