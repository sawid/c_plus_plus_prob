// geometry.h

#ifndef GEOMETRY_H
#define GEOMETRY_H

#define _USE_MATH_DEFINES
#include <cmath>

namespace Geometry {

    // Function to calculate the area of a circle
    inline double circleArea(double radius) {
        return M_PI * radius * radius;
    }

    // Function to calculate the area of a rectangle
    inline double rectangleArea(double length, double width) {
        return length * width;
    }

    // Function to calculate the area of a triangle
    inline double triangleArea(double base, double height) {
        return 0.5 * base * height;
    }

    // Function to calculate the volume of a sphere
    inline double sphereVolume(double radius) {
        return (4.0 / 3.0) * M_PI * radius * radius * radius;
    }

    // Function to calculate the volume of a cylinder
    inline double cylinderVolume(double radius, double height) {
        return M_PI * radius * radius * height;
    }

    // Function to calculate the volume of a cone
    inline double coneVolume(double radius, double height) {
        return (1.0 / 3.0) * M_PI * radius * radius * height;
    }

} // namespace Geometry

#endif // GEOMETRY_H
