#include <iostream>
#include <vector>

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

    // vectors are dynamic arrays. Container in the c++ Standard Template Library
    std::vector<char> vowelss (5);
    std::vector<int> test_scores4;
    // the 10 integer will be automatically set to 0
    std::vector<int> test_scores5 (10);

    std::vector<char> vowelsss {'a', 'e', 'i', 'o', 'u'};
    std::vector<int> test_scores6 {100, 98, 89, 85, 93};

    // Here 365 is vector length, and 80.0 is what you want all elements to initialize
    std::vector<double> hi_temperatures (365, 80.0);


    // Accessing vector elements using subscript operation
    std::vector<int> test_scores7 {100, 95, 99, 87, 88};
    for (size_t i = 0; i < test_scores7.size(); i++)
    {
        std::cout<<i+1<<" score of vector test+scores7 at index "<<i<< ":" <<test_scores7[i]<< std::endl;
    }

    // Accessing vector elements using at method
    for (size_t i = 0; i < test_scores7.size(); i++)
    {
        std::cout<<i+1<<" score of vector test+scores7 at index "<<i<< ":" <<test_scores7.at(i)<< std::endl;
    }

    // We are actually creating object of vector class, at is a method name.

    // Changing the contents of vector elements - vector syntax

    // std::vector <int> test_score8 {100, 95, 99, 87, 88};
    // for (size_t i = 0; i < test_score8.size(); i++)
    // {
    //     std::cout<<"Enter the " <<i<<" element ";
    //     std::cin>>test_score8.at(i);
    // }

    // for (size_t i = 0; i < test_score8.size(); i++)
    // {
    //     std::cout<<i+1<<" score of vector test+score8 at index "<<i<< ":" <<test_score8.at(i)<< std::endl;
    // }
    
    // Vectors grow in size
    std::vector <int> test_score9 {100, 95, 99};
    std::cout<<"The size of vector is "<<test_score9.size()<<std::endl;
    test_score9.push_back(80);
    test_score9.push_back(90);
    std::cout<<"The new size of vector is "<<test_score9.size()<<std::endl;

    // Vectors have bounds checking --> this will throw an error
    // std::vector <int> test_score10 {100, 95};
    // std::cin>> test_score10.at(5);

    // Example of 2D vector --> It is a vector of vectors
    std::vector <std::vector<int>> movie_ratings
    {
        {1, 2, 3, 4},
        {1, 2, 4, 4},
        {1, 3, 4, 5}
    };
    std::cout<<" The size of movie ratings is "<<movie_ratings[0].size()<<std::endl;
    for (size_t i = 0; i < movie_ratings.size(); i++)
    {
        for (size_t j = 0; j < movie_ratings[0].size(); j++)
        {
            std::cout<<"The movie rating for reviewer "<<i<<" are "<<j<<" rating is "<<movie_ratings[i][j]<<std::endl;
        }
        
    }
    
    for (size_t i = 0; i < movie_ratings.size(); i++)
    {
        for (size_t j = 0; j < movie_ratings[0].size(); j++)
        {
            std::cout<<"The movie rating for reviewer "<<i<<" are "<<j<<" rating is "<<movie_ratings.at(i).at(j)<<std::endl;
        }
        
    }
    

}