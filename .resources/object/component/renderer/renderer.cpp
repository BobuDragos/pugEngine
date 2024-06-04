


namespace Core
{
namespace object
{
namespace component
{

class renderer: public component 
{


//class Sphere : Shape {};
//class Cube   : Shape {};

//virtual class Shape : Vector4 {};

class Quad 
{
  public:
    Vector3 bottomLeft;
    Vector3 topRight;

    Quad(Vector3 _bottomLeft, Vector3 _topRight)
        : bottomLeft(_bottomLeft), topRight(_topRight) {}

    Quad()
        : Quad(Vector3(0,0,0), Vector3(1,1,1)) {}

    void show()
    {
      Vector3 topLeft(bottomLeft.x, topRight.y, 0.0, 1.0);
      Vector3 bottomRight(topRight.x, bottomLeft.y, 0.0, 1.0);

      glBegin(GL_POLYGON);
          glVertex4f(bottomLeft.x, bottomLeft.y, bottomLeft.z, bottomLeft.w);
          glVertex4f(bottomRight.x, bottomRight.y, bottomRight.z, bottomRight.w);
          glVertex4f(topRight.x, topRight.y, topRight.z, topRight.w);
          glVertex4f(topLeft.x, topLeft.y, topLeft.z, topLeft.w);
      glEnd();
    }

    void translate(Vector3 offset)
    {
      bottomLeft += offset;
      topRight += offset;
    }

    void rotate(float angleDegrees) {
        float angleRadians = angleDegrees * M_PI / 180.0f;
        float cosAngle = cos(angleRadians);
        float sinAngle = sin(angleRadians);

        Vector3 center = Vector3((bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2, 0);
        
        auto rotatePoint = [cosAngle, sinAngle, center](Vector3 point) {
            float x = point.x - center.x;
            float y = point.y - center.y;
            float newX = x * cosAngle - y * sinAngle + center.x;
            float newY = x * sinAngle + y * cosAngle + center.y;
            return Vector3(newX, newY, point.z);
        };

        bottomLeft = rotatePoint(bottomLeft);
        topRight = rotatePoint(topRight);
    }

    void scale(float scaleFactor) {
        Vector3 center = Vector3((bottomLeft.x + topRight.x) / 2, (bottomLeft.y + topRight.y) / 2, 0);
        
        bottomLeft = (bottomLeft - center) * scaleFactor + center;
        topRight = (topRight - center) * scaleFactor + center;
    }
};

class Line 
{
    Vector3 start;
    Vector3 finish; //end

    //LineType Enum 
    void show()
    {
      glBegin(GL_LINES);
        glVertex4f(start.x, start.y, start.z, start.w);
        glVertex4f(finish.x, finish.y, finish.z, finish.w);
      glEnd();
    }
};

class Point 
{
  public:
    Vector3 pos;

    Point(Vector3 _pos)
        : pos(_pos) {}
    Point()
        : pos(Vector3(0,0,0)) {}

    void show()
    {
      glBegin(GL_POINTS); 
        glVertex4f(pos.x, pos.y, pos.z, pos.w);
      glEnd();
    }

    void translate(Vector3 offset)
    {
      pos.x += offset.x;
      pos.y += offset.y;
      pos.z += offset.z;
    }
};

//class Primitive 
//{
//    Vector2 a;
//    Vector2 b;
//    Primitive() {}
//};


void background(Color c)
{
  glClearColor( c.r, c.g, c.b, c.a);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

/***** ***** ***** ***** ***** *****
              MODIFIERS
 ***** ***** ***** ***** ***** *****/

void fill()
{
  glPolygonMode(GL_FRONT, GL_FILL);
}

void noFill()
{
  glPolygonMode(GL_BACK, GL_LINE);
}

void strokeWeight(double weight)
{
  glPointSize(weight);
  glLineWidth(weight);
}

void stroke(Color c)
{
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glColor4f(c.r,c.g,c.b,c.a);
}

/***** ***** ***** ***** ***** *****
             PRIMITIVES
 ***** ***** ***** ***** ***** *****/

void point(Vector3 pos)
{
  glBegin(GL_POINTS); 
    glVertex4f(pos.x, pos.y, pos.z, pos.w);
  glEnd();
}

void line(Vector3 start, Vector3 finish)
{
  glBegin(GL_LINES);
    glVertex4f(start.x, start.y, start.z, start.w);
    glVertex4f(finish.x, finish.y, finish.z, finish.w);
  glEnd();

}

void rect(Vector3 bottomLeft, Vector3 topRight)
{
    Vector3 topLeft(bottomLeft.x, topRight.y, 0.0, 1.0);
    Vector3 bottomRight(topRight.x, bottomLeft.y, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glVertex4f(bottomLeft.x, bottomLeft.y, bottomLeft.z, bottomLeft.w);
        glVertex4f(bottomRight.x, bottomRight.y, bottomRight.z, bottomRight.w);
        glVertex4f(topRight.x, topRight.y, topRight.z, topRight.w);
        glVertex4f(topLeft.x, topLeft.y, topLeft.z, topLeft.w);
    glEnd();
}


void circle(Vector3 center, double r, double segments = 1000){
  double π = 3.14159; 
  glBegin(GL_POLYGON);
  for (int i = 0; i< segments; i++)
  {
    double θ = 2.0f * π * i/segments;

    float x = r * cosf(θ);
    float y = r * sinf(θ);

    glVertex4f(x, y, center.x, center.w);
  }
  glEnd();
}
};
}
}
}


