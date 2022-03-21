#ifndef VECTOR
#define VECTOR

/*
double absValue(double num);
double sqrt(double num, double eps = 0.001);
*/

struct Vector3D 
{
    int x;
    int y;
    int z;
};

double determinant(double a11, double a12, double a21, double a22);
double length(const Vector3D &vector);
double scalarProduct(const Vector3D &a, const Vector3D &b);//, double angle);
bool arePerpendicular(const Vector3D &a, const Vector3D &b);
Vector3D vectorProduct(const Vector3D &a, const Vector3D &b);
void serialize(const Vector3D &vector, char *path);
Vector3D deserialize(char *path);


#endif // VECTOR
