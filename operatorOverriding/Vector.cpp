#include <iostream>

class Vector {
private:
    double x;
    double y;
    double z;

public:
    // Constructor
    Vector(double x_val = 0.0, double y_val = 0.0, double z_val = 0.0)
        : x(x_val), y(y_val), z(z_val) {}

    // Setter functions to set vector components
    void setComponents(double x_val, double y_val, double z_val) {
        x = x_val;
        y = y_val;
        z = z_val;
    }

    // Getter functions to get vector components
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Function to display the vector
    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")";
    }

    // Overloading + operator for vector addition
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // Overloading - operator for vector subtraction
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // Overloading * operator for scalar multiplication
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    // Function to calculate dot product of two vectors
    double dotProduct(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Function to calculate cross product of two vectors
    Vector crossProduct(const Vector& other) const {
        return Vector(y * other.z - z * other.y,
                      z * other.x - x * other.z,
                      x * other.y - y * other.x);
    }
};

int main() {
    // Create vectors
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    // Display vectors
    std::cout << "Vector v1: ";
    v1.display();
    std::cout << std::endl;

    std::cout << "Vector v2: ";
    v2.display();
    std::cout << std::endl;

    // Vector addition
    Vector sum = v1 + v2;
    std::cout << "Vector sum (v1 + v2): ";
    sum.display();
    std::cout << std::endl;

    // Vector subtraction
    Vector diff = v1 - v2;
    std::cout << "Vector difference (v1 - v2): ";
    diff.display();
    std::cout << std::endl;

    // Scalar multiplication
    double scalar = 2.0;
    Vector scaled = v1 * scalar;
    std::cout << "Scaled vector (v1 * " << scalar << "): ";
    scaled.display();
    std::cout << std::endl;

    // Dot product
    double dot = v1.dotProduct(v2);
    std::cout << "Dot product of v1 and v2: " << dot << std::endl;

    // Cross product
    Vector cross = v1.crossProduct(v2);
    std::cout << "Cross product of v1 and v2: ";
    cross.display();
    std::cout << std::endl;

    return 0;
}
