/* Deep copying with the Copy Constructor
User-provided copy constructor

* Create a copy of the pointed-to data
* Each copy will have a pointer to unique storage in the heap
* Deep copy when you have a raw pointer as a class data member


*/
#include<iostream>

using namespace std;

class Deep {
private:
    int *data;              // POINTER
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() {return *data; }
    int* get_data_value_pointer() {return data; }
    Deep(int d);             // Constructor
    Deep(const Deep &source);  // Copy Constructor
    ~Deep();  // Destructor
};

Deep::Deep(int d) {
    cout<<"In Deep constructor"<<endl;
    data = new int;         // allocate storage 
    *data = d;
    cout<< data<<endl;
}

// Deep copy constructor
// Deep copy-create new storage and copy values  
/*
Deep::Deep(const Deep &source)
{
    data = new int;
    *data = *source.data;
    cout << "Copy constructor - Deep copy" << endl;
}
*/
// Delegate to Deep(int) and pass in the int (*source.data) source is pointing to  
Deep::Deep(const Deep &source)
    : Deep(*source.data) {
        cout << "Copy constructor - Deep copy" << endl;
}


Deep::~Deep() {
    delete data;        // free storage
    cout<<"Destructor freeing data"<<endl; 
}

void display_Deep(Deep s){
    cout<<"In display Deep"<<endl;
    cout<<s.get_data_value() <<endl;
}

int main() {
    cout<<"Check 1"<<endl;
    Deep obj1 {100};
    cout<<"Check 2 obj1 "<<obj1.get_data_value() <<" "<<obj1.get_data_value_pointer()<<endl;
    display_Deep(obj1);
    cout<<"Check 3 "<<obj1.get_data_value_pointer()<<endl;
    // obj1's data has been released!

    obj1.set_data_value(1000);
    cout<<"Check 4 "<<obj1.get_data_value_pointer()<<endl;
    Deep obj2 {obj1};
    cout<<"Check 5 "<<obj1.get_data_value_pointer() << " obj1 " << obj1.get_data_value()<< " obj2 " << obj2.get_data_value()<<endl;
    cout << "Hello world"<<endl;
    return 0;
}