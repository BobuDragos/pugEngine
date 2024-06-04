#include <iostream>

namespace core
{
  struct Vector3
  {
    float x, y, z, w;
    static Vector3 zero;
    static Vector3  one;
    static Vector3 random;

  /***** CONSTRUCTORS *****/
    
    Vector3() : Vector3(0,0,0,1) {}

    Vector3(double _x, double _y = 0.0f, double _z = 0.0f, double _w = 1.0f) : x(_x), y(_y), z(_z), w(_w) {}

  /***** OPERATORS *****/

    Vector3& operator=(const Vector3& other) 
    {
      // Check for self-assignment
      if (this == &other) 
        return *this;

      this->x = other.x;
      this->y = other.y;
      this->z = other.z;
      this->w = other.w;
      return *this;
    }

    Vector3& operator+=(const Vector3& other) 
    {
      this->x += other.x;
      this->y += other.y;
      this->z += other.z;
      return *this;
    }

    Vector3& operator*=(double scalar) 
    {
      this->x *= scalar;
      this->y *= scalar;
      this->z *= scalar;
      return *this;
    }

    Vector3 operator*(double scalar) const 
    {
      return Vector3(this->x * scalar, this->y * scalar, this->z * scalar, this->w);
    }

    Vector3 operator-(const Vector3& other) const 
    {
      return Vector3(this->x - other.x, this->y - other.y, this->z - other.z, this->w);
    }

    Vector3 operator+(const Vector3& other) const {
      return Vector3(this->x + other.x, this->y + other.y, this->z + other.z, this->w);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3& vec) {
      os << "x: " << vec.x << "  "
         << "y: " << vec.y << "  "
         << "z: " << vec.z << "  "
         << "w: " << vec.w << "\n";
      return os;
    }

    // Normalize the vector
    // Vector3 normalize() const {
    //   double mag = magnitude();
    //   if (mag == 0.0) {
    //       std::cerr << "Cannot normalize zero vector" << std::endl;
    //       exit(1);
    //   }
    //   return *this / mag;
    // }

    // Dot product of two vectors
    double dot(const Vector3& other) const {
      return x * other.x + y * other.y + z * other.z;
    }

    // Magnitude (length) of the vector
    // double magnitude() const {
    //   return sqrt(x * x + y * y + z * z);
    // }

    // Scalar division
    Vector3 operator/(double scalar) const {
      if (scalar == 0.0) {
          std::cerr << "Division by zero" << std::endl;
          exit(1);
      }
      return Vector3(x / scalar, y / scalar, z / scalar, w);
    }



  };

  Vector3 Vector3::zero = Vector3(0, 0, 0, 1);
  Vector3 Vector3::one  = Vector3(1, 1, 1, 1);

}
