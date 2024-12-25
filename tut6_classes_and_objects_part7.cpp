/* Shallow vs. Deep Copying
Consider a class that contains a pointer as a data member
Constructor allocates storage dynamically and initializes the pointer
Destructor releases the memory allocated by the constructor
What happens in the default copy constructor?

Default copy constructor
* memberwise copy
* Each data member is copied from the source object
* The pointer is copied NOT what it points to (shallow copy)
* Problem: when we release the storage in the destructor, the other object 
still refers to the released storage.

Shallow copy

class Shallow {
private:
    int *data;              // POINTER
public:
    Shallow(int d);             // Constructor
    Shallow(const Shallow &source);  // Copy
Constructor
    ~Shallow();  // Destructor
};

Shallow::Shallow(int d) {
    data = new int;         // allocate storage 
    *data = d;
}

Shallow::~Shallow() {
    delete data;        // free storage
    cout<<"Destructor freeing data"<<endl; 
}

Shallow copy constructor
Shallow::Shallow(const Shallow &source)
    : data(source.data) {
        cout << "Copy constructor - shallow"
             << endl;
}

Shallow copy - only the pointer is copied - not what it is pointing to !
Problem: source and the newly created object BOTH point to the same data area!

Sample main - will likely crash

int main() {
    Shallow obj1 {100};
    display_shallow(obj1);
    // obj1's data has been released!

    obj1.set_data_value(1000);
    Shallow obj2 {obj1};
    cout << "Hello world"<<endl;
    return 0;
}


*/
#include<iostream>

using namespace std;

class Shallow {
private:
    int *data;              // POINTER
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() {return *data; }
    int* get_data_value_pointer() {return data; }
    Shallow(int d);             // Constructor
    Shallow(const Shallow &source);  // Copy Constructor
    ~Shallow();  // Destructor
};

Shallow::Shallow(int d) {
    cout<<"In shallow constructor"<<endl;
    data = new int;         // allocate storage 
    *data = d;
    cout<< data<<endl;
}

// Shallow copy constructor
Shallow::Shallow(const Shallow &source)
    : data(source.data) {
        cout << "Copy constructor - shallow copy" << endl;
        cout<< data<<endl;
}

Shallow::~Shallow() {
    delete data;        // free storage
    cout<<"Destructor freeing data"<<endl; 
}

void display_shallow(Shallow s){
    cout<<"In display shallow"<<endl;
    cout<<s.get_data_value() <<endl;
}

int main() {
    cout<<"Check 1"<<endl;
    Shallow obj1 {100};
    cout<<"Check 2 obj1 "<<obj1.get_data_value() <<" "<<obj1.get_data_value_pointer()<<endl;
    display_shallow(obj1);
    cout<<"Check 3 "<<obj1.get_data_value_pointer()<<endl;
    // obj1's data has been released!

    obj1.set_data_value(1000);
    cout<<"Check 4 "<<obj1.get_data_value_pointer()<<endl;
    Shallow obj2 {obj1};
    cout<<"Check 5 "<<obj1.get_data_value_pointer() << " obj1 " << obj1.get_data_value()<< " obj2 " << obj2.get_data_value()<<endl;
    cout << "Hello world"<<endl;
    return 0;
}