#include <iostream>

using namespace std;

int main()
{
    // Character type
    char middle_initial {'J'};
    cout <<"My middle initial is "<< middle_initial<<std::endl;

    // Integer types
    unsigned short int exam_score {55};
    cout << "My exam score was "<< exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented << " countries represented in my meeting" <<endl;

    long people_in_florida {20610000};
    cout << "There are about " << people_in_florida << " people in Florida" <<endl;

    long long people_on_earth {7'600'000'000};
    cout << "There are about " << people_on_earth << " people on earth" <<endl;

    long long distance_to_alpha_centauri {9'461'000'000'000};
    cout<< "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers" <<endl;

    return 0;
}