/*
The Standard Template Library
Generic Programming with function templates

What is a C++ Template?
* A template is a generic blueprint that the compiler uses 
to generate specialized functions and classes. 
* The idea with template is that we define a template with a 
placeholder type, and then we plug in the actual type we want 
when we need it. 
* Then the compiler generates the specific function or class that we need.
* Remember, all of this happens at compile time. So
we get the benefit of compile doing type checking for us before the program executes.
* C++ template supports the concept of generic programming or meta-programming.
* C++ templates can be very very complex. 
* The error message provided by compiler can be very difficult to understand.

--- 
max function as a template function
* We can replace type we want to generalize with a name, say T.
* But now this wont compile

T max(T a, T b) {
    return (a > b) ? a : b;
}

--
We need to tell the compiler this is a template function
We also need to tell it that T is the template parameter

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

Now this will compile, but it will not generate any code. 
It's simply a template or a blueprint. 
Code is not generated by the compiler until the user uses a
specialized version of the template. 

-- 
We may also use class instead of typename -> they both are equivalent.
template <class T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

---
* Now the compiler can generate the appropriate function from the template
* Note, this happens at compile-time!

int a {10};
int b {20};

std::cout << max<int>(a,b);

Vectors, unique pointer, shared pointers and so forth 
are implemented as template classes. 

---
* Many times the compiler can deduce the type and the template parameter
is not needed.
* Depending on the type of a and b, the compiler will figure it out

std::cout << max<double>(c, d);
std::cout << max(c,d);

*/

/*
multiple types as template parameters
* when we use the function we provide the template parameters
* often the compiler can deduce them from the function arguments

func<int,double>(10, 20.2);
func('A',12.4); 

*/
#include <iostream>
#include <string>

#define MAX(a,b) ((a>b) ? a : b)
#define SQUARE(a) ((a)*(a))


int main(){
    std::cout << MAX(10,20) << std::endl;   // 20
    std::cout << MAX(2.4,3.5) << std::endl;   // 3.5
    std::cout << MAX('A','C') << std::endl;   // C

    std::cout << SQUARE(5) << std::endl;         // Expect 25
    std::cout << 100/ SQUARE(5) << std::endl;        // Expect 4

    return 0;
}