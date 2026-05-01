#include <iostream>
#include <vector>

// Aidan Burmester Hw12 //
  
int main() {



    // Initialize vectors //

    std::vector<int> numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> numbers2 = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    // Resize for extra space //

    numbers1.resize(numbers1.size());



    // Interlace vectors //

    std::vector<int>::iterator it1 = numbers1.begin();

    std::vector<int>::iterator it2 = numbers2.begin();

    while (it1 != numbers1.end() && it2 != numbers2.end()) {
        ++it1;
        it1 = numbers1.insert(it1, *it2);
        ++it1;
        ++it2;
    }

    while (it2 != numbers2.end()) {
        numbers1.insert(numbers1.end(), *it2);
        ++it2;
    }


    // Print result //

    std::cout << "Interlaced vector (numbers1): ";
    for (int num : numbers1) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl;

    return 0;
}