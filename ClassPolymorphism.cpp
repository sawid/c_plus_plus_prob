#include <iostream>

class Vehicle {
    public:
    int speed;
    void print_speed() const 
    virtual void movement();
}

class Jet : public Vehicle{
    public:
        int speed;
    void movement() {
        moveForward();
        moveUp();
    }
}

class Boat : public Vehicle {
    public:
    void movement() {
        moveForward();
    }
}