/*
The Standard Template Library

Generic Programming with macros

* Generic programming
 "Writing code that works with a variety of types as arguments,
 as long as those argument types meet specific syntactic and 
 semantic requirements", Bjarne Stroustrup

* Macros ***beware***

* Function templates

* Class templates
*/

/*
Macros (#define)

* C++ preprocessor directives
* No type information
* Simple substitution

#define MAX_SIZE 100

#define PI 3.14159

if (num > MAX_SIZE)
    std::cout << "Too big";

double area = PI * r * r;

the pre processor will remove the #define and replace the MAX_SIZE
where we have defined MAX_SIZE in the program. 
Then the processed file is sent to compiler
*/

/*
max function

* Suppose we need a function to determine the max of 2 integers

int max(int a, int b) {
    return (a>b) ? a : b;
}

int x = 100;
int  y = 200;
std::cout<<max(x,y);    // displays 200

Now suppose we need to determine the max of 2 doubles, and 2 chars

int max(int a, int b) {
    return (a>b) ? a : b;
}

double max(double a, double b) {
    return (a>b) ? a : b;
}

char max(char a, char b) {
    return (a>b) ? a : b;
}

we dont want to write the max function for different types of paramters

One way is to use Macros with parameters

#define MAX(a,b) ((a>b) ? a : b)

std::cout << MAX(10,20) << std::endl;   // 20
std::cout << MAX(2.4,3.5) << std::endl;   // 3.5
std::cout << MAX('A','C') << std::endl;   // C

The preprocessor will replace MAX also the argument. We only have a single Macro.

*/

/*
Macros with argument s(#define)
* We have to be careful with macros

#define SQUARE(a) a*a

result = SQUARE(5);         // Expect 25
result = 5*5;               // Get 25 (after preprocessor substitution)

result = 100/ SQUARE(5);        // Expect 4
result = 100/ 5*5;        // Get 100 (after preprocessor substitution)

---
When using Macros wrap up all the arguments in paranthesis
#define SQUARE(a) ((a)*(a))   // note the paranthesis

result = SQUARE(5);         // Expect 25
result = ((5)*(5));               // Get 25 (after preprocessor substitution)

result = 100/ SQUARE(5);        // Expect 4
result = 100/ ((5)*(5));        // Now we Get 4 (after preprocessor substitution)

*/
#include <iostream>
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