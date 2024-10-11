#include <iostream>
#include <climits>
// #include <cfloat>

int main()
{   
    //  sizeof operator
    std::cout<<"The size of char is "<<sizeof(char) <<" bytes."<< std::endl;
    std::cout<<"The size of int is "<<sizeof(int) <<" bytes."<< std::endl;
    std::cout<<"The size of double is "<<sizeof(double) <<" bytes."<< std::endl;
    std::cout<<"The size of unsigned int is "<<sizeof(unsigned int) << " bytes."<<std::endl;
    std::cout<<"The size of short is "<<sizeof(short) << " bytes."<<std::endl;
    std::cout<<"The size of long is "<<sizeof(long) << " bytes."<<std::endl;
    std::cout<<"The size of long long is "<<sizeof(long long) <<" bytes."<< std::endl;

    std::cout<<"The size of float is "<<sizeof(float) <<" bytes."<< std::endl;
    std::cout<<"The size of double is "<<sizeof(double) <<" bytes."<< std::endl;
    std::cout<<"The size of long double is "<<sizeof(long double) <<" bytes."<< std::endl;

    std::cout<<"The minimum value of char is "<<CHAR_MIN <<std::endl;
    std::cout<<"The minimum value of int is "<<INT_MIN <<std::endl;
    std::cout<<"The minimum value of short is "<<SHRT_MIN <<std::endl;
    std::cout<<"The minimum value of long is "<<LONG_MIN <<std::endl;
    std::cout<<"The minimum value of long long is "<<LONG_LONG_MIN <<std::endl;

    int age {21};
    std::cout<<"The size of age is "<<sizeof(age) <<" bytes."<< std::endl;
    std::cout<<"The size of age is "<<sizeof age <<" bytes."<< std::endl;

    // What is a constant?
    const int months_of_year {12};
    std::cout<<months_of_year<<std::endl;
    // literal constant
    std::cout << "Hello\tthere\nmy friend\n"<<std::endl; 
    int x = 12;
    float y = 1.56;

    // const double pi {3.1415926};
    // Preprocessor, dont use constant like this in modern c++
    #define pi 3.1415926
    std::cout<<"The value of pi is "<<pi<<std::endl;
    
    // Arrays
    // int test_scores [5];
    
    
    
     
    return 0;
}