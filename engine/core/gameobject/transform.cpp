
// #include "../math/vector.h"

namespace core
{
  class Transform 
  {
    public:
      Vector3 position;
      Vector3 rotation;
      Vector3 scale;
      
      void translate (Vector3 offset)
      {
        this->position += offset;
      }
  };
}


