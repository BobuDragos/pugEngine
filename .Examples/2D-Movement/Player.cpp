



class Player : public gameobject 
{
  public:
    void start() override
    {
      transform.position = Vector3::zero;
    }
    
    void update() override
    {
      float horiz = Input::getAxisRaw("Horizontal");
      float vert  = Input::getAxisRaw("Vertical");

      transform.translate(Vector3(horiz, vert, 0));
    }

    // void onCollisionEnter(gameobject other) override
    // {
    //   if(other.transform.name == "Star")
    //   {
    //     // TextRenderer::display("You Win", Vector3::zero, 10, Color::red);
    //   }
    // }
};


