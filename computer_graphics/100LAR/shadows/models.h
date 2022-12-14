
/*
  Здесь храянтся модели
*/

#include <iostream>
#include <GL/freeglut.h>

const int size_numb_x = 4;
const int size_numb_y = 4;

GLfloat ctlpoints[size_numb_x][size_numb_y][3];
GLfloat knots[size_numb_x + size_numb_y] = {
  0.0, 0.0, 0.0, 0.0,
  1.0, 1.0, 1.0, 1.0
};

GLUnurbsObj* theNurb;

// создание nurb поверхности
void init_surface(void) {
  int u, v;
  int m = 20; // 2
  for (u = 0; u < size_numb_y; u++) {
    for (v = 0; v < size_numb_x; v++) {
      ctlpoints[u][v][0] = m * ((GLfloat)u - 1.5);
      ctlpoints[u][v][1] = m * ((GLfloat)v - 1.5);
    }
  }
  theNurb = gluNewNurbsRenderer();
  gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 10.0);
  gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
  gluNurbsProperty(theNurb, GLU_AUTO_LOAD_MATRIX, false);
}

// отрисовка nurb поверхности
void draw_nurb() {
  gluBeginSurface(theNurb);

  glRotatef(-90.0, 1.0, 0.0, 0.0);
  gluNurbsSurface(theNurb,
      size_numb_x + size_numb_y, knots, size_numb_x + size_numb_y, knots,
      size_numb_x * 3, 3, &ctlpoints[0][0][0],
      4, 4, GL_MAP2_VERTEX_3);

  gluEndSurface(theNurb);
  glRotatef(90.0, 1.0, 0.0, 0.0);
}
