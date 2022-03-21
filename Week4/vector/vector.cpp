#include "vector.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

#define PI 3.14159265

/*
double absValue(double num)
{
    return (num > 0 ? num : -num);
}

double sqrt_a(double num, double eps = 0.001)
{
    double current = 0;
    double next = 1;

    while (absValue(next - current) >= eps) {
        current = next;
        next = 0.5 * (current + (num / current));
    }

    return next;
}*/

double length(const Vector3D &vector)
{
    double squaredLen = vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
    return sqrt(squaredLen);
}

double scalarProduct(const Vector3D &a, const Vector3D &b) //, double degrees) 
{
    /*
    double lenA = length(a);
    double lenB = length(b);
    double radians = (degrees / 180.0) * PI;

    return lenA * lenB * cos(radians);
    */

    return a.x * b.x + a.y * b.y + a.z * b.z;
}

bool arePerpendicular(const Vector3D &a, const Vector3D &b) 
{
    return scalarProduct(a, b) == 0;
}

Vector3D vectorProduct(const Vector3D &a, const Vector3D &b)
{
    // ...
    Vector3D vector;
    return vector;
}

void serialize(const Vector3D &vector, char *path)
{
    ofstream fileStream(path, ios_base::binary);
    if (!fileStream.is_open()) {
        cerr << "Could not open the file";
        return;
    }

    fileStream.write((const char *)&vector, sizeof(vector));

    fileStream.close();
}

Vector3D deserialize(char *path) 
{
    Vector3D vector;

    ifstream fileStream(path, ios_base::binary);
    if (!fileStream.is_open()) {
        cerr << "Could not open the file";
        return vector;
    }

    fileStream.read((char *)&vector, sizeof(vector));

    fileStream.close();
    return vector;
}
