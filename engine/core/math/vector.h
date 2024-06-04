#include <iostream>

namespace core {
  struct Vector3 {
    float x, y, z, w;
    static Vector3 zero;
    static Vector3 one;

    // Constructors
    Vector3();
    Vector3(double _x, double _y = 0.0f, double _z = 0.0f, double _w = 1.0f);

    // Operators
    Vector3& operator=(const Vector3& other);
    Vector3& operator+=(const Vector3& other);
    Vector3& operator*=(double scalar);
    Vector3 operator*(double scalar) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator/(double scalar) const;
    
    // Friend functions
    friend std::ostream& operator<<(std::ostream& os, const Vector3& vec);

    // Member functions
    double dot(const Vector3& other) const;
  };
}
