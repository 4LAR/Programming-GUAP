
/*

    Вывести трехмерную сцену с движущимся объектом, который отбрасывает тень
  на другой объект (напр. плоскость). Тень должна перемещаться вместе с
  движением объекта исходя из взаимного положения источника света, объекта,
  который отбрасывает тень и объектов, на которые тень проецируется

*/

#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#include "models.h" // функция для отрисовки пола
#include "shadows.h" // функции для работы ТЕНИ
#include "move.h" // функции для ПЕРЕДВИЖЕНИЯ
#include "draw.h" // функции для ПРОРИСОВКИ

#define TITLE "Shadows"

#define W_WIDTH 1280
#define W_HEIGHT 720

#define FPS 60

namespace global {
  float cam_xz_rotate = 0;
  float cam_y_rotate = 0.5;
  float cam_zoom = 30;
  float light_xy_rotate = 0;
  float light_y_rotate = 0;
  float obj_pos[3] = {0, 0, 0};
  float light_pos[4] = {0.0, 4.0, 0.0, 0.0};
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
