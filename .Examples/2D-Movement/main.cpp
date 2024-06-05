

#include "../../engine/engine.cpp"
using namespace core;


#include "GameManager.cpp"
#include "Obstacle.cpp"
#include "Player.cpp"
#include "Star.cpp"

GameManager gameManager;
// Obstacle obstacle;
Player player;
// Star star;

void loop()
{
  gameManager.update();
  player.update();
}


int main (int argc, char** argv)
{
  opengl::setLoop(loop);
  opengl::glutSetup(&argc, argv);
  return 0;
}
