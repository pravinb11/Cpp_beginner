/*
Move Constructor
* Sometimes when we execute code the compiler creates unnamed temporary values
int total {0};
total = 100 + 200;
* 100 + 200 is evaluated and 300 stored in an unnamed temp value
* the 300 is then stored in the variable total
* then the temp value is discarded

* The same happens with objects as well

When it is useful?
* Sometimes copy constructors are called many times automatically due to the copy semantics of  C++
* Copy constructors doing deep copying can have a significant performance bottleneck
* C++11 introduced move semantics and the move constructor
* Move constructor moves an object rather than copy it.
* Optional but recommended when you have a raw pointer
* Copy elision - C++ may optimize copying away completely (RVO-Return value optimization)

r-value references
* Used in moving semantics and perfect forwarding
* Move semantics is all about r-value references
* Used by move constructor and move assignment operator to efficiently move and object
rather than copy it
* R-value reference operator (&&)

int x {100}
int &l_ref = x;     // l-value reference
l_ref = 10;         // change x to 10

int &&r_ref =200;       // r-value ref
r_ref = 300;            // change r_ref to 300

int &&x_ref = x;        // Compiler error

l-value reference parameters

int x {100};        // x is an l-value
void func(int &num);    // A

func(x);        // calls A-x is an l-value
func(200);      // Error - 200 is an r-value

error: cannot bind non-const lvalue 
reference of type 'int&' to an rvalue of type 'int'

r-value reference parameters

int x {100};        // x is an l-value
void func(int &&num);   // B

func(200);      // calls B-200 is an r-value
func(x);        // Error - x is an l-value

error: cannot bind rvalue reference of type 'int&&' to lvalue of type 'int'
 
overloading:

int x {100};        // x is an l-value
void func(int &num);   // A
void func(int &&num);   // B

func(x);        // calls A - x is an l-value
func(200);      // calls B - 200 is an r-value

-----------------
What does it do?
* Instead of making a deep copy of the move constructor
* moves the resource
* simply copies the address of the resource from source to the current object
* And, nulls out the pointer in the source pointer

syntax -r-value reference
Type::Type (Type &&source);
Player::Player(Player &&source);
Move::Move (Move &&source);
*/
#include<iostream>
#include<vector>
using namespace std;

class Move{
private:
    int *data;          //raw pointer
public:
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data;}
    Move(int d);        // Constructor
    Move(const Move &source);   // Copy constructor
    Move(Move &&source) noexcept;        // Move constructor
    ~Move();                    // Destructor
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout<<"Constructor for: "<< d <<endl;
}

Move::Move(const Move &source){
    data = new int;             // allocate storage and copy
    *data = *source.data;
    cout<<"Copy constructor - deep copy for: "<< *data <<endl;
}

Move::Move(Move &&source) noexcept
    : data{source.data} {
        source.data = nullptr;
        cout<<"Move constructor - moving resource. "<<*data<<endl;
}

Move::~Move(){
    if(data != nullptr) {
        cout<<"Destructor freeing data for: "<<*data<<endl;
    } else {
        cout<<"Destructor freeing data for nullptr."<<endl;
    }
    delete data;
}
// 'Steal' the data and then null out the source pointer

int main() {
    // Inefficient copying
    vector<Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    // Copy constructors will be called to copy the temps 
    return 0;
}