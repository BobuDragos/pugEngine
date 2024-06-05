
#include "physics/physics.cpp"
#include "core/core.cpp"
using namespace core;





#include <GL/freeglut_std.h>
#include <GL/freeglut.h>
unsigned char prevKey;
#include <stdio.h>
// #include "engine/engine.cpp"

class opengl
{
  public:
    static void (*loop)();
    static void setLoop(void (*func)())
    {
      printf("Loop function set.\n");
      loop = func;
    }

    static void display(void)
    {
      if(loop)
        loop();

      // // Reset key states if needed
      // Input::resetKeyStates();

      glutSwapBuffers();
      glFlush();
      glutPostRedisplay();

    }

    static void reshape(int w, int h)
    {
      // printf("ReshapeFunction \n");
      
      glViewport(0,0,(GLsizei) w, (GLsizei) h);
    }

    static void keyboard(unsigned char key, int x, int y) 
    {
      // printf("key pressed: %c \n", key);
      if (key == 27)
          exit(0);

      Input::updateKeyState(key, true);
    }

    static void keyUp(unsigned char key, int x, int y) 
    {
      Input::updateKeyState(key, false);
    }

    static void mouse(int button, int state, int x, int y)
    {
      // printf("mouse %d \n", state);

      // if(state == 0)
      //   keyPressed(button + '0', x, y);

      // if (state == 1)
        // keyReleased(button + '0', x, y);
    }

    static void glutSetup(int *argc, char** argv) 
    {
      glutInit(argc, argv);
      glutInitWindowSize(480, 480); // 480x640
      glutInitWindowPosition(0,0);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
      glutCreateWindow("Canvas");

      glutReshapeFunc(reshape);
      glutDisplayFunc(display);
      glutKeyboardFunc(keyboard);
      glutKeyboardUpFunc(keyUp); // Register key release event
      glutMouseFunc(mouse);


        // user's code here somehow
        // smth like;
        // main::setup();

      glutMainLoop();
    }
};


void (*opengl::loop)() = nullptr;
