/*
try catch --> This is for exception handling.
Four steps
1. Hit the exception
2. Throw the exception
3. Catch the exception
4. Perform the corrective action
try {
This block contains the code in which we put the code that might contain
exception.
}
catch () {
Whenever some exception is found in try block, it is immediately thrown 
to Catch() block. Now catch() block will have the responsibility to handle
the exception.
}
*/

#include <iostream>

int main ()
{
    int a, b, c;
    std::cout<<"\n Enter two numbers: ";
    std::cin>>a>>b;
    try
    {
        if (b != 0)
        {
            c = a / b;
            std::cout << "\n Division = " << c << std::endl;
        }
        else
        {
            throw(b);
        }
        
    }
    catch(int b)
    {
        std::cerr << "Divide by "<<b << std::endl;
    }

    return 0;
    
}