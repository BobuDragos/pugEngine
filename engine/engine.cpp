
#include "physics/physics.cpp"
#include "core/core.cpp"






#include <GL/freeglut_std.h>
#include <GL/freeglut.h>
unsigned char prevKey;
#include <stdio.h>
// #include "engine/engine.cpp"
using namespace core;

class opengl
{
  public:
    static void display(void)
    {
      // printf("DisplayFunction: \n");
      // loop();

      // // Reset key states if needed
      // Input::resetKeyStates();

      glutSwapBuffers();
      glFlush();
      glutPostRedisplay();


if (Input::getKeyDown(KEY_A)) {
        // Handle A key pressed
        printf("A HAS BEEN PRESSED \n");
    }

    if (Input::getKey(KEY_D)) {
        // Handle D key held down
        printf("D HAS BEEN PRESSED \n");
    }

    float horizontal = Input::getAxisRaw("Horizontal");
    float vertical = Input::getAxisRaw("Vertical");

    // // if (horizontal != 0)
    // printf("%d", (int)horizontal);
    // printf("\n");
    // printf("%f", vertical);
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

