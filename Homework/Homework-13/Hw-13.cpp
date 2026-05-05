#include <iostream>
#include <map>
#include <string>
 

// Aidan Burmester Homework 13 //


int main() {
    
    
    // Create the two maps so i can use em //

    std::map<int, std::string> numbers1 = {
       
        {1, "1"},
        {2, "2"},
        {3, "3"},
        {4, "4"},
        {5, "5"},
        {6, "6"},
        {7, "7"},
        {8, "8"},
        {9, "9"}
    
    };

    std::map<int, int> numbers2 = {

        {1, 10},
        {2, 20},
        {3, 30},
        {4, 40},
        {5, 50},
        {6, 60},
        {7, 70},
        {8, 80},
        {9, 90}

    };

    // Put the maps together //

    std::map<int, std::string>::iterator it1 = numbers1.begin();
    std::map<int, int>::iterator it2 = numbers2.begin();


    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        it1->second += ", " + std::to_string(it2->second);

        ++it1;
        ++it2;
    }


    while (it2 != numbers2.end()) {
        numbers1[it2->first] = std::to_string(it2->second);
        ++it2;
    }

    // Spit out the interlaced map hopefully //

    std::cout << "Interlaced map (numbers1): ";
    for (const auto& pair : numbers1) {
        std::cout << pair.first << ": " << pair.second << " ";
    }
    
    std::cout << std::endl;

    return 0;

}