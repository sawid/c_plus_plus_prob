#include <iostream>
#include <vector>
#include <memory>

// Base class
class SpaceObject {
public:
    virtual void draw() const {
        std::cout << "Drawing a generic space object.\n";
    }

    virtual ~SpaceObject() {}
};

// Derived classes
class Martian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Martian with green antennas.\n";
    }
};

class Venutian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Venutian with a shiny, silver surface.\n";
    }
};

class Plutonian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Plutonian with a cold, blue glow.\n";
    }
};

class SpaceShip : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a SpaceShip with sleek, aerodynamic wings.\n";
    }
};

class LaserBeam : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a LaserBeam with a bright, red streak.\n";
    }
};

class Mercurian : public SpaceObject {
public:
    void draw() const override {
        std::cout << "Drawing a Mercurian with a swift, silver shadow.\n";
    }
};

// ScreenManager class
class ScreenManager {
private:
    std::vector<std::unique_ptr<SpaceObject>> objects;

public:
    void addObject(std::unique_ptr<SpaceObject> obj) {
        objects.push_back(std::move(obj));
    }

    void refreshScreen() const {
        for (const auto& obj : objects) {
            obj->draw();
        }
    }
};

// Main function to demonstrate functionality
int main() {
    ScreenManager manager;

    // Add objects to the manager and refresh the screen
    manager.addObject(std::make_unique<Martian>());
    manager.addObject(std::make_unique<Venutian>());
    manager.addObject(std::make_unique<Plutonian>());
    manager.addObject(std::make_unique<SpaceShip>());
    manager.addObject(std::make_unique<LaserBeam>());

    // Demonstrate adding a Mercurian object
    manager.addObject(std::make_unique<Mercurian>());

    // Refresh the screen
    manager.refreshScreen();

    return 0;
}
