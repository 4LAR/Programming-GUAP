
/*

  Выполнить на выбор один из вариантов:
  - Шейдер с сохранением данных в текстуре,
  - Процедурный, текстурный шейдер,
  - Традиционные шейдер,
  - Фрагментный шейдер,
  - Вершинный шейдер.
  Примеры из пакета с компилятором Cg не допускаются

*/

#include <iostream>
#include <cmath>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "shader.h" // функции для ШЕЙДЕРОВ
#include "move.h" // функции для ПЕРЕДВИЖЕНИЯ
#include "draw.h" // функции для ПРОРИСОВКИ

#include <fstream>
#include <string>

#define TITLE "Shader"

#define W_WIDTH 1280
#define W_HEIGHT 720

#define FPS 60

namespace global {
  float cam_xz_rotate = 0;
  float cam_y_rotate = 0.2;
  float cam_zoom = 14;
  float light_xy_rotate = 0;
  float light_y_rotate = 0;
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

  GLenum err = glewInit();
  if (GLEW_OK != err) {
    std::cout << "GLEW ERROR: " << glewGetErrorString(err) << std::endl;
  }

  // загружаем шейдер с файла
  std::string f_shader_str = "";
  std::ifstream inp;
  inp.open("shader.frag");
  while (inp) {
    f_shader_str += inp.get();
  }
  inp.close();
  f_shader_str.at(f_shader_str.length() - 1) = '\0';

  // make_shader(GL_FRAGMENT_SHADER, f_shader_str);
  if (!make_shader(GL_FRAGMENT_SHADER, f_shader_str)) {
    std::cout << "ERROR SHADER" << std::endl;
    exit(0);
  }

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
