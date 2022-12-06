/*
  Здесь реализуются функции для ПРОРИСОВКИ
*/

#include <iostream>
#include <GL/freeglut.h>

#include <cmath>

/*
  mat_dif - цвет рассеянного отражения материала
  mat_spec - цвет зеркального отражения материала
  mat_amb - цвет фонового отражения материала
  mat_shininess - коэффициент блеска
*/

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
}

float mat_dif_Dodecahedron[] = {0.9f, 0.9f, 0.9f, 0.5f};
float mat_spec_Dodecahedron[] = {0.9f, 0.9f, 0.9f};
float mat_amb_Dodecahedron[] = {0.9f, 0.9f, 0.9f};
float mat_shininess_Dodecahedron = 0.1f * 128;

float mat_dif_Cube[] = {0.9f, 0.2f, 0.2f, 1.0f};
float mat_spec_Cube[] = {0.9f, 0.2f, 0.2f};
float mat_amb_Cube[] = {0.9f, 0.2f, 0.2f};
float mat_shininess_Cube = 0.1f * 128;

float mat_dif_light[] = {0.9f, 0.9f, 0.0f, 1.0f};
float mat_spec_light[] = {0.9f, 0.9f, 0.0f};
float mat_amb_light[] = {0.9f, 0.9f, 0.0f};
float mat_shininess_light = 0.1f * 128;

float matl_dif_light[] = {0.9f, 0.9f, 0.9f, 1.0f};
GLfloat light_position[3][4] = {
  {0.0, 0.0, -15.0, 0.0},
  {0.0, -15.0, 0.0, 0.0},
  {0.0, 0.0, 0.0, 0.0}
};

// функция для отображения и включения света
void set_light(GLenum name, GLfloat *light_position) {
  glLightfv(name, GL_DIFFUSE, matl_dif_light);
  glLightfv(name, GL_POSITION, light_position);
  glLightf(name, GL_SPOT_CUTOFF, 360);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_light);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_light);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_light);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_light);

  glTranslatef(light_position[0], light_position[1], light_position[2]);
  glutSolidSphere(0.2, 32, 32);
  glTranslatef(-light_position[0], -light_position[1], -light_position[2]);

  glEnable(name);
}

void Display(void) {
  glLoadIdentity();

  move();

  gluLookAt(
    cos(global::cam_y_rotate) * sin(global::cam_xz_rotate) * global::cam_zoom,
    sin(global::cam_y_rotate) * global::cam_zoom,
    cos(global::cam_y_rotate) * cos(global::cam_xz_rotate) * global::cam_zoom,
	  0, 0, 0,
	  0.0f, 1.0f, 0.0f
  );

  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glEnable(GL_DEPTH_TEST);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /* включаем освещение и источник света */
  glEnable(GL_LIGHTING);
  set_light(GL_LIGHT0, light_position[0]);
  set_light(GL_LIGHT1, light_position[1]);
  // set_light(GL_LIGHT2, light_position[2]);

  glTranslatef(5, 0, 5);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Cube);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Cube);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Cube);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Cube);
  glutSolidCube(2);

  glTranslatef(-10, -2, -10);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Cube);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Cube);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Cube);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Cube);
  glutSolidSphere(2, 10, 10);

  glTranslatef(5, 2, 5);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Dodecahedron);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Dodecahedron);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Dodecahedron);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Dodecahedron);
  glutSolidDodecahedron();

  glFlush();
}

void Reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLfloat) w / h, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}
