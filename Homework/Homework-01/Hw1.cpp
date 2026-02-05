#include <iostream>
#include <string>
#include <bitset>
#include <limits>

int main() {
    int decimalinput;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalinput;

    std::string binaryoutput = std::bitset<std::numeric_limits<int>::digits + 1>(decimalinput).to_string();

    size_t first_one = binaryoutput.find('1');
    if (first_one != std::string::npos) {
        binaryoutput = binaryoutput.substr(first_one);
    } else {
        binaryoutput = "0"; 
    }
    std::cout << "Binary representation: " << binaryoutput << std::endl;
    return 0;
}