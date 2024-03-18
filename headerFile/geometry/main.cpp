// main.cpp

#include <iostream>
#include "geometry.h"

int main() {
    int choice;
    double radius, length, width, base, height;

    do {
        std::cout << "Geometry Calculator\n"
                  << "1. Calculate Circle Area\n"
                  << "2. Calculate Rectangle Area\n"
                  << "3. Calculate Triangle Area\n"
                  << "4. Calculate Sphere Volume\n"
                  << "5. Calculate Cylinder Volume\n"
                  << "6. Calculate Cone Volume\n"
                  << "7. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter radius of the circle: ";
                std::cin >> radius;
                std::cout << "Area of the circle: " << Geometry::circleArea(radius) << std::endl;
                break;
            case 2:
                std::cout << "Enter length and width of the rectangle: ";
                std::cin >> length >> width;
                std::cout << "Area of the rectangle: " << Geometry::rectangleArea(length, width) << std::endl;
                break;
            case 3:
                std::cout << "Enter base and height of the triangle: ";
                std::cin >> base >> height;
                std::cout << "Area of the triangle: " << Geometry::triangleArea(base, height) << std::endl;
                break;
            case 4:
                std::cout << "Enter radius of the sphere: ";
                std::cin >> radius;
                std::cout << "Volume of the sphere: " << Geometry::sphereVolume(radius) << std::endl;
                break;
            case 5:
                std::cout << "Enter radius and height of the cylinder: ";
                std::cin >> radius >> height;
                std::cout << "Volume of the cylinder: " << Geometry::cylinderVolume(radius, height) << std::endl;
                break;
            case 6:
                std::cout << "Enter radius and height of the cone: ";
                std::cin >> radius >> height;
                std::cout << "Volume of the cone: " << Geometry::coneVolume(radius, height) << std::endl;
                break;
            case 7:
                std::cout << "Exiting program...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}
// g++ main.cpp -o geometry_calculator
