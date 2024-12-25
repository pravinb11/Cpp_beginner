/*
*** Constructor Initialization lists ***

Previous way:
Player::Player() {
    name = "None";   // assignment not initialization
    health = 0;
    xp = 0;
}

Better way:
Player::Player()
    : name{"None"}, health{0}, xp{0} {
}

This happens before the body is ever executed, here the order in which the 
members are initialized is not necessarily the order we provide in the initialization lists.
The data members will be initialized in the order they are declared in the class declaration. 

Single args constructor
Player(std::string)

Previous way:
Player::Player(std::string name_val) {
    name = "name_val";   // assignment not initialization
    health = 0;
    xp = 0;
}

Better way:
Player::Player(std::string name_val)
    : name{"name_val"}, health{0}, xp{0} {
}


Three args constructor
Player(std::string, int, int)

Previous way:
Player::Player(std::string name_val, int health_val, int xp_val) {
    name = "name_val";   // assignment not initialization
    health = health_val;
    xp = xp_val;
}

Better way:
Player::Player(std::string name_val, int health_val, int xp_val)
    : name{"name_val"}, health{health_val}, xp{xp_val} {
}

*/


/*
*** Delegating Constructors ***
Often the code for constructors is very similar
Duplicated code can lead to erros
C++ allows delegating constructors
- code for one constructor can call another in the initialization list
- avoids duplicating code
*/

#include<iostream>
using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;
// This order decides the initialization, not the order in which it is initialized in function.
public:
// Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

/*
Player::Player(){
    name = "None";
    health = 0;
    xp = 0;
}

Player::Player(std::string name_val){
    name = "name_val";
    health = 0;
    xp = 0;
}

Player::Player(std::string name_val, int health_val, int xp_val){
    name = "name_val";
    health = health_val;
    xp = xp_val;
}
*/

/*
Player::Player()
    :name{"None"}, health{0}, xp{0} {
}

Player::Player(std::string name_val)
    :name{"name_val"}, health{0}, xp{0} {
}

Player::Player(std::string name_val, int health_val, int xp_val)
    :name{"name_val"}, health{health_val}, xp{xp_val} {
}
*/

// Delegating Constructors
// Player::Player(std::string name_val, int health_val, int xp_val)
//     :name{"name_val"}, health{health_val}, xp{xp_val} {
// }
// No args is a delegating constructor -- Pass on constructor    
Player::Player()
    :Player {"None", 0, 0} {
    cout <<"No-args constructor" <<endl;
}

Player::Player(std::string name_val)
    :Player {name_val, 0, 0} {
    cout <<"One-args constructor" <<endl;
}

Player::Player(std::string name_val, int health_val, int xp_val)
    :name{"name_val"}, health{health_val}, xp{xp_val} {
    cout <<"Three-args constructor" <<endl;
}


int main() {

    cout<<"Check 1 "<<endl;
    Player empty;
    cout<<"Check 2 "<<endl;
    Player frank{"Frank"};
    cout<<"Check 3 "<<endl;
    Player villain{"Villain", 100, 55};

    return 0;
}

