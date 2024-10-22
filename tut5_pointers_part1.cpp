/*
What is a pointer?
-> A pointer is a variable whose value is an address
Why use Pointers? Can't I just use the variable or function itself?
-> If you have a complex data that is defined outside a function, and you want to
access the data within the function, you cant because the variable name is out of scope.
So you can pass the data to the function by value and make a copy of it or
you can make a reference to a pointer parameter and access that data within the function. 
Pointers can be used to operate on arrays very efficiently. Pointers and arrays are interrelated.
We can allocate memory dynamically on the heap or free store.
. This memory doesnt even have a variable name.
. The only way to get to it is via a pointer.
With OO. pointers are how polymorphism works!

-? 
Declaring pointers
int *int_ptr;
double* double_ptr;
char *char_ptr;
string *string_ptr;

Initializing pointer variables to 'point nowhere'
variable_type *pointer_name {null_ptr};
int *int_ptr {};
double* double_ptr {nullptr};
char *char_ptr {nullptr};
string *string_ptr {nullptr};
How to read --> double_ptr is a pointer to double 

Accessing and storing addresses in pointers
& the address operator --> Evaluates to the address of its operand



Deferencing pointers
Dynamic memory allocation
Pointer arithmetic
Pointers and arrays
Pass-by-reference with pointers
const and pointers
Using pointers to functions
Potential pointer pitfalls
*/

#include <iostream>
#include<vector>

int main () {    
    

    int num {10};
    std::cout << "Value of num is: " << num <<std::endl;
    std::cout << "The size of num is: " << sizeof num <<std::endl;
    std::cout << "The address of num is: " << &num <<std::endl;

    // Accessing pointer address

    int *p;
    std::cout << "Value of p is: " << p <<std::endl;
    std::cout << "Address of p is: " << &p <<std::endl;
    std::cout << "Size of p is: " << sizeof p <<std::endl;
    p = nullptr;
    std::cout << "Value of p is: " << p <<std::endl;

    // Don't confuse the size of a pointer and the size of what it points to
    // All pointers in a program have the same size
    // They may be pointing to very large or very small types

    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    std::vector<std::string> *p4 {nullptr};
    std::string *p5 {nullptr};
    std::cout << "Size of p1 is: " << sizeof p1 <<std::endl;
    std::cout << "Size of p2 is: " << sizeof p2 <<std::endl;
    std::cout << "Size of p3 is: " << sizeof p3 <<std::endl;
    std::cout << "Size of p4 is: " << sizeof p4 <<std::endl;
    std::cout << "Size of p5 is: " << sizeof p5 <<std::endl;

    // Typed pointers
    // The compiler will make sure that the address stored in a pointer variable is of the correct type

    int score {10};
    double high_temp {100.7};
    int *score_ptr {nullptr};
    score_ptr = &score;
    std::cout << "The value at score_ptr is: " << *score_ptr <<std::endl;
    // score_ptr = &high_temp; // compiler error, size is not problem but type conflict

    // Storing an address in pointer variable
    // Pointers are variables so they can change
    // Pointers can be null
    // Pointers can be uninitialized

    double high_temp1 {100.7};
    double low_temp1 {37.2};
    double *temp_ptr1;
    temp_ptr1 = &high_temp1;
    temp_ptr1 = &low_temp1;
    temp_ptr1 = nullptr;

    // Deferencing a pointer 
    // Access the data we're pointing to - dereferencing a pointer
    // If score_ptr is a pointer and has a valid address
    // Then you can access the data at the address contained in the score_ptr using the dereference operator *
    int score1 {100};
    int *score_ptr1 {&score1};
    std::cout << "The value at address of score_ptr1 is "<<*score_ptr1 <<std::endl;
    *score_ptr1 = 200;
    std::cout << "The value at address of score_ptr1 is "<<*score_ptr1 <<std::endl;
    std::cout << "The value of score1 is "<<score1 <<std::endl;

    std::string name {"Frank"};
    std::string *string_ptr {&name};
    std::cout<<"The value at address of string_ptr is "<< *string_ptr<<std::endl;
    name = "James";
    std::cout<<"The value at address of string_ptr is "<< *string_ptr<<std::endl;

    std::vector<std::string> stooges {"James", "Frank", "Larry"};
    std::vector<std::string> *stooges_ptr;
    stooges_ptr = &stooges;
    std::cout <<"The value of first element of stooges is "<<(*stooges_ptr).at(0)<<std::endl;
    for (auto stooge: stooges)
        std::cout<<stooge<<std::endl;
    
    for (auto stooge: *stooges_ptr)
        std::cout<<stooge<<" ";
    std::cout<<std::endl;
    
    
    
    return 0;
}