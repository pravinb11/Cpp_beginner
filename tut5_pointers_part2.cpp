#include <iostream>

int main()
{
    // Dynamic memory allocation
    int *int_ptr {nullptr};
    int_ptr = new int;  // allocate an integer on the heap
    std::cout<<int_ptr<<std::endl;
    *int_ptr = 10;
    std::cout<<"The value of int_ptr is "<<*int_ptr<<std::endl;
    // using delete to dellocate storage
    delete int_ptr; // frees the allocated storage
    
    int *array_ptr {nullptr};
    int size {5};

    std::cout << "How big do you want the array? "<<std::endl;
    
    // std::cin >>size;
    array_ptr = new int[size]; // allocate array on the heap/ Free store 
    *array_ptr = 100;
    std::cout<<"The value of array_ptr is "<<*array_ptr<<std::endl;
    // We can access the array here 
    delete [] array_ptr; // free allocated storage
    std::cout<<"The address of array_ptr is " << array_ptr<<std::endl;
    std::cout<<"The value of array_ptr is "<<*array_ptr<<std::endl;
    
    // Relationship between Arrays and Pointers
    int scores[] {100, 95, 89};
    std::cout<<scores<<std::endl;
    int *score_ptr {scores};
    std::cout <<"Value of score_ptr: "<< score_ptr << std::endl;
    
    std::cout<<"\n Array subscript notation --------------" << std::endl;
    std::cout << scores[0] << std::endl;
    std::cout << scores[1] << std::endl;
    std::cout << scores[2] << std::endl;

    
    std::cout<<"\n Pointer subscript notation --------------" << std::endl;
    std::cout << score_ptr[0] << std::endl;
    std::cout << score_ptr[1] << std::endl;
    std::cout << score_ptr[2] << std::endl;

    std::cout<<"\n Pointer offset notation --------------" << std::endl;
    std::cout << *score_ptr << std::endl;
    std::cout << *(score_ptr+1) << std::endl;
    std::cout << *(score_ptr+2) << std::endl;

    std::cout<<"\n Array offset notation --------------" << std::endl;
    std::cout << *scores << std::endl;
    std::cout << *(scores+1) << std::endl;
    std::cout << *(scores+2) << std::endl;

    // When we add one observe the change in value of score_ptr
    // This is basis of pointer arithmetic
    
    std::cout << score_ptr << std::endl; // 0x7ffea7bc0bdc
    std::cout << (score_ptr+1) << std::endl; // 0x7ffea7bc0be0
    std::cout << (score_ptr+2) << std::endl; // 0x7ffea7bc0be4
    std::cout << (score_ptr+3) << std::endl; // 0x7ffea7bc0be8
    std::cout << (score_ptr+4) << std::endl; // 0x7ffea7bc0bec

    // increments a pointer to point to the next array element
    int_ptr++;
    // decrements a pointer to point to the previous array element
    int_ptr--;

    // Pointer arithmetic
    // Substracting two pointers
    // Determine the number of elements between the pointers
    // Both pointers must point to the same data type
    // int *int_ptr1 {nullptr};
    // int *int_ptr2 {nullptr};
    // *int_ptr1 = 10;
    // *int_ptr2 = 10;
    // int n = int_ptr2 - int_ptr1;

    // Comparing two pointers == and !=
    // Determine if two pointers point to the same location
    // Does not compare the data where they point
    std::string s1 {"Frank"};
    std::string s2 {"Frank"};

    std::string *p1 {&s1};
    std::string *p2 {&s2};
    std::string *p3 {&s1};

    std::cout << (p1 == p2) << std::endl; // 0 False as they are pointing to different address
    std::cout << (p1 == p3) << std::endl; // 1 True as they are pointing to same address

    std::cout << (*p1 == *p2) << std::endl; // 1 True
    std::cout << (*p1 == *p3) << std::endl; // 1 True

    // Pointer arithmetic
    int scores1[] {100, 95, 89, 68, -1};
    // -1 is called sentinel value
    int *score_ptr1 {scores1};

    while (*score_ptr1 != -1){
        std::cout << *score_ptr1 << std::endl;
        score_ptr1 ++;
    }

    // Dereference and increment together
    score_ptr1 = scores1;
    while (*score_ptr1 != -1)
        std::cout << *score_ptr1++ <<std::endl;

    std::cout<<"\n ----------------------- " <<std::endl;
    char name[] {"Frank"};
    
    char *char_ptr1 {nullptr};
    char *char_ptr2 {nullptr};
    char_ptr1 = &name[0];
    char_ptr2 = &name[3];

    std::cout<<"In the string "<<name<<", "<<*char_ptr2<<" is "<<(char_ptr2-char_ptr1)<<" characters away from "<<*char_ptr1 <<std::endl;

    // Pointer to constants
    // The data pointed to by the pointers is constant and cannot be changed
    // The pointer iteself can change and point somewhere else.
    int high_score {100};
    int low_score {65};
    const int *score_ptr2 {&high_score};
    // *score_ptr2 = 86;   // ERROR
    score_ptr2 = &low_score;  // OK
    high_score = 100;

    // Constant pointers
    // The data pointed to by the pointers can be changed
    // The pointer itself cannot change and point somewhere else

    int *const score_ptr3 { &high_score };
    *score_ptr3 = 86; // OK
    // score_ptr3 = &low_score; // ERROR

    // Constant pointers to constants
    // The data pointed by the pointer is constant and cannot be changed.
    // The pointer itself cannot change and point somewhere else.

    const int *const score_ptr4 {&high_score};
    // *score_ptr4 = 86; // ERROR
    // score_ptr4 = &low_score; // ERROR
    return 0;
}