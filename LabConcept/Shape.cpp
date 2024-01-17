#include <iostream>

using namespace std;
const int PI_S = 3.14;
class Shape
{
private:
    /* data */
public:
    // Shape(/* args */);

    Shape()
    {

    }

    float getArea()
    {
        cout << "Hello";
    }

    virtual float getPerimeter();
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int inputRadius) : radius(inputRadius)
    {

    }

    float getArea()
    {
        return 3.14 * radius * radius;
    }

    float getPerimeter()
    {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;
public:
    Rectangle(int inputlength, int inputwidth):length(inputlength), width(inputwidth)
    {

    }
    float getArea() override
    {
        return length * width;
    }

    float getPerimeter()
    {
        return 2 * (length + width);
    }
};

