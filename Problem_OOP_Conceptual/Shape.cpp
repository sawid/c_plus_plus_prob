//Write a C++ program to implement a class called Shape with virtual member functions for 
// calculating area and perimeter. Derive classes such as Circle, Rectangle, and Triangle from 
// the Shape class and override virtual functions accordingly.
#include <iostream>

using namespace std;

class Shape
{
public:
    // Shape();
    virtual float getArea() = 0;
    virtual float getPerimeter() = 0;
};