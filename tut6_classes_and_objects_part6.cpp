// Copy constructor
/*
When objects are copied C++ must create a new object from an existing object

When is a copy of an object made?
passing object by value as a parameter
returning an object from a function by value
constructing one object based on another of the same class

C++ must have a way of accomplishing this so it provides a compiler-defined
copy constructor if you dont
*/

/* First use case: Pass object by-value
Player hero {"Hero", 100, 20};

void display_player(Player p){
    // p is a COPY of hero in this example
    // use p
    // Destructor for p will be called
}

display_player(hero);
*/

/* Return object by value
Player enemy;

Player create_super_enemy() {
    Player an_enemy{"Super Enemy", 1000, 1000};
    return an_enemy; // A COPY of an_enemy is returned
}

enemy = create_super_enemy();

*/

/* Construct one object based on another
Player hero {"Hero", 100, 100};

Player another_hero {hero}; // A COPY of hero is made 

*/

/*
If you don't provide you own way of copying objects by value then
the compiler provides a default way of copying objects

Copies the values of each data member to the new object
    default memberwise copy

Perfectly fine in many cases

Beware if you have a pointer data member
    Pointer will be copied
    Not what it is pointing to
    Shallow vs. Deep copy  

Best practices:
Provide a copy constructor when you class has raw pointer members
Provide the copy constructor with a const reference parameter
Use STL classes as they already provide copy constructors
Avoid using raw pointer data members if possible
*/

/* Declaring the Copy Constructor
It has same name as class, in parameter list it has a single object passed as of same type
Why by reference and const, if we pass by value then we have to make a copy of it
const prevents any modification to the source object 
Type::Type (const Type &source);

Prototype for copy constructor
Player::Player(const Player &source);

Account::Account(const Account &source);

*/

/* Implementing the Copy Constructor
Type::Type(const Type &source) {
    // code or initialization list to copy the object
}

Player::Player(const Player &source)
    : name{source.name},
      health {source.health},
      xp {source.xp} {
}

Account::Account (const Account &source)
    : name{source.name},
      balance{source.balance}{
}
*/
#include<iostream>

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:
    std::string get_name() {return name;}
    int get_health() {return health;}
    int get_xp() {return xp; }
    Player(std::string name_val="None", int health_val=0, int xp_val=0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player(){
        std::cout<<"Destructor called for: " +name <<std::endl;
    }
};

Player::Player(std::string name_val, int health_val, int xp_val)
    : name{name_val}, health{health_val}, xp{xp_val} {
    std::cout<<"Three-args constructor for: "+ name <<std::endl;
}
 
Player::Player(const Player &source)
    // : name{source.name}, health{source.health}, xp{source.xp} {
    // Delegating
    : Player{source.name, source.health, source.xp}{
    std::cout<<"Copy constructor - made a copy of: "<<source.name<<std::endl;
}

void display_player(Player p){
    std::cout<<"Name: "<<p.get_name() <<std::endl;
    std::cout<<"Health: "<<p.get_health() <<std::endl;
    std::cout<<"XP: "<<p.get_xp() <<std::endl;
}

int main(){
    Player empty{"XXXX",0,0};
    display_player(empty);
    Player my_new_object(empty);
    Player frank{"Frank"};
    Player hero {"Hero",100};
    Player villain{"Villain",100, 55};

    return 0;
}