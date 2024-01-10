#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
    // Shape();
    virtual float getArea() = 0;
    virtual float getPerimeter() = 0;
};

class Circle : public Shape
{
private:
    int radius;
public:
    Circle(int inputRadius) : radius(inputRadius) 
    {

    }

    float getArea() override
    {
        return M_PI * radius * radius;
    }

    float getPerimeter() override
    {
        return 2 * M_PI * radius;
    }
};

int main()
{
    Circle circleObject(5);
    cout << circleObject.getArea();
    return 0;
}



