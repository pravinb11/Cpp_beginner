#include <iostream>

int main(){

    // Array initialization
    int test_scores [5] {100, 95, 99, 87, 88};
    std::cout <<"The size of test_scores is "<<sizeof(test_scores)<<std::endl;
    int high_score_per_level [10] {3,5}; // init to 3, 5 and remaining to 0
    const double days_in_year {365};
    // double hi_temperatures [days_in_year] {0}; 

    int another_array [] {1,2,3,4,5};

    int arr[5];
    arr[10] = 100;  // Accessing memory out of bounds

    //

    char vowels[] {'a', 'e', 'i', 'o', 'u'};

    std::cout<<"The first vowel is "<<vowels[0]<<std::endl;
    std::cout<<"The last vowel is "<<vowels[4]<<std::endl;

    // std::cin>>vowels[5]; // Out of bounds -- don't do this!!

    // Declaring, initializing, and accessing arrays
    double hi_temps [] {90.1, 89.8, 77.5, 81.6};
    std::cout<<"The first high temperature is: " << hi_temps[0] << std::endl;

    hi_temps[0] = 100.7; // set the first element in hi_temps to 100.7
    std::cout<<"The first high temperature is now: " << hi_temps[0] << std::endl;

    // This is only declaration
    int test_score [5];
    for (size_t i = 0; i < std::size(test_score); i++)
    {
        std::cout<<i+1<<" score at index "<<i<< ":" <<test_score[i]<< std::endl;
    }

    int test_score1 [5] {};
    for (size_t i = 0; i < std::size(test_score1); i++)
    {
        std::cout<<i+1<<" score at index "<<i<< ":" <<test_score1[i]<< std::endl;
    }

    int test_score2 [5] {100,90};
    for (size_t i = 0; i < std::size(test_score2); i++)
    {
        std::cout<<i+1<<" score at index "<<i<< ":" <<test_score2[i]<< std::endl;
    }

    int test_score3 [] {100,90,80,70,60};
    for (size_t i = 0; i < std::size(test_score3); i++)
    {
        std::cout<<i+1<<" score at index "<<i<< ":" <<test_score3[i]<< std::endl;
    }
    
    // This doesnt work
    // std::cout<<"Test score at last index: "<<test_score3[-1]<< std::endl;

    // Declaring multi-dimensional arrays
    // Element_Type array_name [rows][cols]

    int movie_rating [3][4];

    int movie_rating1 [3][4]
    {
        {0, 4, 3, 5},
        {2, 3, 3, 5},
        {1, 4, 4, 5}
    };
}