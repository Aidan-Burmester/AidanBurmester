#include <iostream>

// Area calculation functions

constexpr double pi{3.1415926535897};
    constexpr double areasquare(double side) {
        return side * side;
    }
    constexpr double areaRectangle(double length, double width) {
        return length * width;
    }
    constexpr double areaCircle(double radius) {
        return pi * radius * radius;
    }
    constexpr double areaCylinder(double radius, double height) {
        return 2 * pi * radius * height + 2 * areaCircle(radius);
    }
int main () 
    {
      
        // Display menu

        int choice;
        std::cout << "Choose a shape to calculate the area: " << std::endl
                    << "1. Square" << std::endl
                    << "2. Rectangle" << std::endl
                    << "3. Circle" << std::endl
                    << "4. Cylinder" << std::endl
                    << "Enter your choice (1-4): ";
        std::cin >> choice;
double height{}, width{}, length{}, radius{};
      
// Run selected option

            switch (choice) {
            case 1:
                std::cout << "Enter the side length of the square: ";
                std::cin >> length;
                std::cout << "Area of the square: " << areasquare(length) << std::endl;
                break;
            case 2:
                std::cout << "Enter the length and width of the rectangle: ";
                std::cin >> length >> width;
                std::cout << "Area of the rectangle: " << areaRectangle(length, width) << std::endl;
                break;
            case 3:
                std::cout << "Enter the radius of the circle: ";
                std::cin >> radius;
                std::cout << "Area of the circle: " << areaCircle(radius) << std::endl;
                break;
            case 4:
                std::cout << "Enter the radius and height of the cylinder: ";
                std::cin >> radius >> height;
                std::cout << "Area of the cylinder: " << areaCylinder(radius, height) << std::endl;
                break;
            default:
                std::cout << "Invalid. Enter a number between 1 and 4." << std::endl;
    }

    return 0;

    }