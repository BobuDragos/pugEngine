

#include "renderer.cpp"
#include "transform.cpp"

namespace core
{
  class gameobject
  {
    public:
      Transform transform;
      Renderer  renderer;
      // Collider  collider;
      
      virtual void start()
      {

      }

      virtual void update()
      {

      }
  };
}
