
/*

    Вывести несколько пересекающихся объектов, как минимум один из них должен
  быть прозрачным. Включить 3 источника света, задать свойства поверхностей и
  источников. Организовать раздельное вращение источников света вокруг
  неподвижной сцены, управляемое с клавиатуры или мышью.

*/

#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#include "move.h" // функции для ПЕРЕДВИЖЕНИЯ
#include "draw.h" // функции для ПРОРИСОВКИ

#define TITLE "Depth buffer & Transparency"

#define W_WIDTH 1280
#define W_HEIGHT 720

#define FPS 60

namespace global {
  float cam_xz_rotate = 0;
  float cam_y_rotate = 0;
  float cam_zoom = 14;
  bool light_run = true;
}

// замена while
void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(1000/FPS, timer, 0);
}

// ну тут уже ОЧЕВИДНО
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowPosition(150, 50);
  glutInitWindowSize(W_WIDTH, W_HEIGHT);
  glutCreateWindow(TITLE);

  // передаём функции для прорисовки
  glutReshapeFunc(Reshape);
  glutDisplayFunc(Display);

  //
  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

  // передаём функции для определения нажатых клавиш
  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);
  glutMouseWheelFunc(MouseWheel);

  // таймер
  glutTimerFunc(0, timer, 0);

  // чтоб окно не закрывалось
  glutMainLoop();
}
