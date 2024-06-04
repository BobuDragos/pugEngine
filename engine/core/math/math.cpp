
#include "vector.h"
#include "random.cpp"


#include <cmath> // for std::cos, std::sin, std::atan2, std::sqrt

namespace core
{
  class Math {
    public:
      static constexpr double PI = 3.14159265358979323846;
      static constexpr double HALF_PI = PI / 2;
      static constexpr double QUARTER_PI = PI / 4;



      // Trigonometric functions
      static double cos(double angle) {
          return std::cos(angle);
      }

      static double sin(double angle) {
          return std::sin(angle);
      }

      // Convert Cartesian coordinates to polar coordinates
      // Returns a pair where first element is the radius and second element is the angle
      static std::pair<double, double> cartesianToPolar(double x, double y) {
          double radius = std::sqrt(x * x + y * y);
          double angle = std::atan2(y, x);
          return {radius, angle};
      }

      // Convert polar coordinates to Cartesian coordinates
      // Takes radius and angle as inputs and returns a pair of x and y
      static std::pair<double, double> polarToCartesian(double radius, double angle) {
          double x = radius * std::cos(angle);
          double y = radius * std::sin(angle);
          return {x, y};
      }
  };
}




