
/*
Generic programming with class Templates

What is a C++ class template?
It is similar to function templates
but instead of creating generic function, we create generic class
* Similar to the function template, but at the class level
* Allows plugging-in any data type
* Compiler generates the appropriate class from the blueprint


* Lets say we want a class to hold items where the item has 
a name and an integer

class Item {
private:
    std::string name;
    int value;
public:
    Item(std::string name, int value)
        : name{name}, value{value}
    {}
    std::string get_name() const {return name;}
    int get_value const{return value; }
};

* But we we'd like our Item class to be able to hold any type of
data in addition to the string
* We cant overload class names
* We dont want to use dynamic polymorphism

template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value)
        : name{name}, value{value}
    {}
    std::string get_name() const {return name;}
    T get_value const{return value; }
};

Item<int> item1 {"Larry", 1};
Item<double> item2 {"House", 1000.0};
Item<std::string> item3 {"Frank", "Boss"};
std::vector<Item<int>> vec;

*/

/*
Multiple types as template parameters
* We can have multiple template parameters
* And their types can be different

template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

My_Pair <std::string, int> p1 {"Frank", 100};
My_Pair <int, double> p2 {124, 13.6};
std::vector<My_Pair<int,double>> vec;

It is already implemented in c++
#include<utility>

std::pair<std::string, int> p1 {"Frank", 100};
std::cout << p1.first;      //frank
std::cout << p1.second;      //100
*/
#include <iostream>
#include <utility>
#include<vector>
#include<string>

// Template classes are typically completely contained in header files
// So, we would have the template class in item.h and no item.cpp file
// would be used

template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value) : name{name}, value{value}
    {}
    std::string get_name() const {return name;}
    T get_value() const{return value; }
};

template <typename T1, typename T2>
struct My_Pair {
    T1 first;
    T2 second;
};

int main(){
    
    return 0;
}