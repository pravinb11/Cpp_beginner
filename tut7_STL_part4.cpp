
/*
multiple types as template parameters
* when we use the function we provide the template parameters
* often the compiler can deduce them from the function arguments

func<int,double>(10, 20.2);
func('A',12.4); 

*/
#include <iostream>
#include <string>

template<typename T>
T min(T a, T b){
    return (a < b) ? a:b;
}

template<typename T1, typename T2>
void func(T1 a, T1 b){
    std::cout << a << " "<< b << std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person &rhs) const{
        return this->age < rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p){
    os << p.name;
    return os;
}

template<typename T>
void my_swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    
    std::cout << "Start" << std::endl;
    std::cout << min<int>(2,3) <<std::endl;
    std::cout << min(4,8) <<std::endl;
    std::cout << min('A','B') <<std::endl;
    std::cout << min(12.5,9.5) <<std::endl;
    
    Person p1 {"Curly", 15};
    Person p2 {"Moe", 30};
    
    Person p3 = min(p1,p2);
    std::cout<<p3.name << " is younger."<<std::endl;


    func<Person,Person>(p1,p2);
    func<int,int>(10,20);

    my_swap(p1,p2);
    func<Person,Person>(p1,p2);

    int x{100};
    int y{200};
    func<int,int>(x,y);
    my_swap(x,y);
    func<int,int>(x,y);
    return 0;
}