// Homework 09: Aidan Burmester //

#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception //
class CustomException : public exception {
public:
    const char* what() const noexcept override {
        return "Error in nestedFunction";
    }
};

// Safe division //
double divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(a) / b;
}

    // Check array access //
int accessArray(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    return arr[index];
}

// Inner thrower //
void nestedFunction() {
    throw CustomException();
}

        // Catch and rethrow //
void outerFunction() {
    try {
        nestedFunction();
    }
    catch (const CustomException& e) {
        cout << "Caught exception in outerFunction: " << e.what() << endl;
        throw; // rethrow to main
    }
}

// Program entry //
int main() {

    // Nested exception //
    try {
        outerFunction();
    }
    catch (const CustomException& e) {
        cout << "Caught rethrown exception in main: " << e.what() << endl;
    }

    cout << endl;

    // Division input //
    try {
        int numerator, denominator;

        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;

        double result = divide(numerator, denominator);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl;

    // Array access input //
    try {
        int size;
        cout << "Enter array size: ";
        cin >> size;

        int* arr = new int[size];

        cout << "Enter " << size << " integers: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }

        int index;
        cout << "Enter index to access: ";
        cin >> index;

        int value = accessArray(arr, size, index);
        cout << "Value at index " << index << ": " << value << endl;

        delete[] arr;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}