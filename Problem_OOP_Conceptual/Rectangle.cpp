// Write a C++ program to create a class called Rectangle that has private member variables for length and width. 
// Implement member functions to calculate the rectangle's area and perimeter.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Rectangle
{
private:
    int length;
    int width;
public:
    Rectangle(int length, int width) : length(length), width(width)
    {

    }

    int getArea()
    {
        return length * width;
    }

    float getPerimeter()
    {
        return (length * 2) + (width * 2) ;
    }
};

int main()
{
    Rectangle rec(15, 18);
    cout << rec.getArea() << endl;
    cout << rec.getPerimeter();
    return 0;
}
