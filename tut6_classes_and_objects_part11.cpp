/*
Using const with classes

* Pass arguments to class member methods as const
* We can also create const objects
* What happens if we call member functions on const objects?
* const-correctness

Creating a const object
* villain is a const object so it's attributes cannot change

const Player villain {"villain", 100, 55};

villain.set_name("Nice guy");       // ERROR
std::cout << villain.get_name() << std::endl;       // ERROR

--
const Player villain {"Villain", 100, 55};

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;
}
display_player_name(villain);   // ERROR

-- What we have to do is to tell the compiler that, that func will not modify it

const methods

class Player {
private:
    . . .
public:
    std::string get_name() const;
    // ERROR if code in get_name modifies this object
    . . .
};

---
const-correctness

const Player villain {"Villain", 100, 55};

villain.set_name("Nice guy");       // ERROR
std::cout << villain.get_name() << std::endl;   // OK
*/

#include<iostream>
using namespace std;

class Player
{
private:
    std::string name;
    int health;
    int xp;
public:
    std::string get_name() const {
        // xp =100;        // Not allowed
        return name;
    }

    void set_name(std::string name_val) { 
        name = name_val; 
    }

    // Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player {"None",0,0}{
}

Player::Player(std::string name_val)
    : Player{name_val,0,0} {
}

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val},xp{xp_val}{
}

void display_player_name(const Player &p) {
    cout<< p.get_name() <<endl;
}

int main()
{
    const Player villain {"Villain", 100, 55};
    // villain.set_name("Hero"); // Not allowed
    cout << villain.get_name() << endl;
    Player hero{"Hero", 100, 15};

    return 0;
}