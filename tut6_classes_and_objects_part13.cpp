/*
Structs vs Classes
* In addition to define a class we can declare a struct
* struct comes from the C programming language
* Essentially the same as a class except
    * members are public by default 

class ----

class Person {
    std::string name;
    std::string get_name();
};

Person p;
p.name = "Frank"; // compiler error - private by default 
std::cout << p.get_name();  // compiler error - private by default

struct --

struct Person {
    std::string name;
    std::string get_name(); // Why if name is public ?
};

Person p;
p.name = "Frank"; // OK - public
std::cout << p.get_name();  // OK - public


Some general guideliness

* struct
    * Use struct for passive objects with public access
    * Don't declare methods in struct

* class
    * Use class for active objects with private access
    * Implement getters/setters as needed
    * Implement member methods as needed
*/

 #include<iostream>
using namespace std;

// class Person {
// // public:
//     std::string name;
//     std::string get_name() {return name;}
// };


struct Person {
    std::string name;
    std::string get_name() {return name;} // Why if name is public ?
};


int main()
{
    Person p;
    p.name = "Frank"; // OK - public
    std::cout << p.get_name() << std::endl;  // OK - public

    return 0;
}