/*
The Standard Template Library

* What is the STL
* Generic programming/ Meta-programming
    * Preprocessor macros
    * Function templates
    * Class templates
* STL Containers
* STL Iterators
* STL Algorithms
* Array
* Vector
* Deque
* List and Forward List
* Set and Multi Set
* Map and Multi Map
* Stack and Queue
* Priority Queue
* Algorithms

*/

/*
What is the STL?
* A library of powerful, reusable, adaptable, generic classes and functions
* Implemented using C++ templates
* Implements common data structres and algorithms
* Huge class library!!
* Developed by Alexander Stepanov (1994)

* Assortment of commonly used containers
* Known time and size complexity
* Tried and tested - Reusability!!
* Consistent, fast, and type-safe
* Extensible
*/

/*
Elements of the STL
* Containers
    * Collections of objects or primitive types 
      (array, vector, deque, stack, set, map, etc.)
* Algorithms
    * Functions for processing sequences of elements from containers
    (find, max, count, accumulate, sort, etc.)
* Iterators
    * Generate sequences of element from containers
    (forward, reverse, by value, by reference, constant, etc.)
*/

/*
#include<vector>
#include<algorithm>
std::vector<int> v {1,5,3};

A simple example - We can use a sort algorithm to sort

std::sort(v.begin(), v.end());

here v.begin() is an iterator

A simple example - reverse a vector
std::reverse(v.begin(), v.end());

A simple example - accumulate

int sum {};
sum = std::accumulate(v.begin(),v.end,0);
std::cout << sum << std::endl;
*/

/*
Types of Containers
* Sequence containers
    * array, vector, list, forward_list, deque
* Associative containers
    * set, multi set, map, multi map
* Container adapters
    * stack, queue, priority queue
*/

/*
Types of Iterators
* Input iterators - from the container to the program
* Output iterators - from the program to the container
* Forward iterators - navigate one item at a time in one direction
* Bi-directional iterators - navigate one item at a time both directions
* Random access iterators - directly access a container item 
*/

/*
Types of Algorithms
* There are about 60 algorithms in the STL
* Algorithms are divided into Non-modifying and modifying, depending
upon does the algorithm modifies the sequence it acts upon. 
*/