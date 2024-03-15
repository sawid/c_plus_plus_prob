#include <iostream>
#include <sstream>
#include <string>

class Point {
private:
    int xCoordinate;
    int yCoordinate;

public:
    Point(int x = 0, int y = 0) : xCoordinate(x), yCoordinate(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend std::istream& operator>>(std::istream& is, Point& point);
};

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.xCoordinate << ", " << point.yCoordinate << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& point) {
    int x, y;

    // Read input from the stream
    is >> x >> y;

    // Check for valid input
    if (is.fail() || is.bad()) {
        is.setstate(std::ios::failbit); // Set the failbit to indicate improper input
        return is;
    }

    // Set the coordinates
    point.xCoordinate = x;
    point.yCoordinate = y;

    return is;
}

int main() {
    Point p;

    std::cout << "Enter a point (x y): ";
    if (!(std::cin >> p)) {
        std::cerr << "Invalid input!" << std::endl;
    } else {
        std::cout << "Point entered: " << p << std::endl;
    }

    return 0;
}
