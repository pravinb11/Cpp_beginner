#include <iostream>
#include <vector>

void double_data(int *int_ptr);
void double_data(int *int_ptr) {
        *int_ptr *= 2;
        // *int_ptr = *int_ptr * 2;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display (const std::vector<std::string> *const v){
    for (auto str: *v)
        std::cout<< str << " ";
    std::cout<<std::endl;
    // (*v).at(0)="Funny";
    // v = nullptr;
}

void display(int *array, int sentinel){
    while (*array != sentinel)
        std::cout<<*array++ << " ";
    std::cout << std::endl;
}
int main (){
    // Passing pointers to a function
    // Pass-by-reference with pointer parameters
    // We can use pointers and the dereference operator to achieve pass-by-reference
    // The function parameter is a pointer
    // The actual parameter can be a pointer or address of a variable.
    int high_score = 100;
    std::cout << "The value of high_score is "<<high_score<<std::endl;
    double_data(&high_score);
    std::cout << "The value of high_score is "<<high_score<<std::endl;

    int *int_ptr {&high_score};
    std::cout << "The value of *int_ptr is "<<*int_ptr<<std::endl;
    double_data(int_ptr);
    std::cout << "The value of *int_ptr is "<<*int_ptr<<std::endl;
    
    int x {100}, y{200};
    std::cout << "The value of x " << x <<" and y is "<<y<<std::endl;
    swap (&x, &y);
    std::cout << "The value of x " << x <<" and y is "<<y<<std::endl;
    
    std::vector<std::string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);

    int scores[] {100,98,85,-1};
    display(scores,-1);
    return 0;
}