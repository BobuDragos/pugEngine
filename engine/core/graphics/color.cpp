
#include "color_mapping.cpp"

#include <stdexcept>

namespace core
{
  struct Color
  {
    float r, g, b, a;
    static Color black;
    static Color white;
    static Color red;
    static Color green;
    static Color blue;
    static Color yellow;
    static Color cyan;
    static Color purple;

    // Constructor for grayscale color
    Color(double _value)
        : Color(_value, _value, _value, 1.0f) {}
    // Constructor for RGB color
    Color(double _r, double _g, double _b)
        : Color(_r, _g, _b, 1.0f) {}
    // Main constructor for RGBA color
    Color(double _r, double _g, double _b, double _a)
        : r(_r), g(_g), b(_b), a(_a) {}

  // Constructor for named color
    Color(const std::string& colorName)
        : Color(colorName, 1.0f) {}

    Color(const std::string& colorName, double _a) 
    {
      auto it = namedColors.find(colorName);
      if (it != namedColors.end()) {
          r = std::get<0>(it->second);
          g = std::get<1>(it->second);
          b = std::get<2>(it->second);
          a = _a;
      } else {
          throw std::invalid_argument("Unknown color name");
      }
    }

  };

  Color Color::black  = Color(0.0, 0.0, 0.0, 1.0);
  Color Color::white  = Color(1.0, 1.0, 1.0, 1.0);
  Color Color::red    = Color(1.0, 0.0, 0.0, 1.0);
  Color Color::green  = Color(0.0, 1.0, 0.0, 1.0);
  Color Color::blue   = Color(0.0, 0.0, 1.0, 1.0);
  Color Color::yellow = Color(1.0, 1.0, 0.0, 1.0);
  Color Color::cyan   = Color(0.0, 1.0, 1.0, 1.0);
  Color Color::purple = Color(0.5, 0.0, 0.5, 1.0);

}
