/*
  Здесь реализуются функции для ПРОРИСОВКИ
*/

#include <iostream>
#include <GL/freeglut.h>

#include <string>
#include <cmath>

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
  extern float light_xy_rotate;
}

// метериалы объектов
float mat_dif_cube[] = {1.0f, 0.0f, 0.0f, 1.0f};
float mat_spec_cube[] = {1.0f, 0.0f, 0.0f};
float mat_amb_cube[] = {1.0f, 0.0f, 0.0f};
float mat_shininess_cube = 0.1f * 128;

float mat_dif_Sphere[] = {0.0f, 1.0f, 0.0f, 1.0f};
float mat_spec_Sphere[] = {0.0f, 1.0f, 0.0f};
float mat_amb_Sphere[] = {0.0f, 1.0f, 0.0f};
float mat_shininess_Sphere = 0.1f * 128;

float mat_dif_Tetrahedron[] = {0.0f, 0.0f, 1.0f, 1.0f};
float mat_spec_Tetrahedron[] = {0.0f, 0.0f, 1.0f};
float mat_amb_Tetrahedron[] = {0.0f, 0.0f, 1.0f};
float mat_shininess_Tetrahedron = 0.1f * 128;

void Display(void) {
  glLoadIdentity();

  // рассчитываем передвижение для камеры
  move();

  // задаём параметры камере
  gluLookAt(
    cos(global::cam_y_rotate) * sin(global::cam_xz_rotate) * global::cam_zoom,
    sin(global::cam_y_rotate) * global::cam_zoom,
    cos(global::cam_y_rotate) * cos(global::cam_xz_rotate) * global::cam_zoom,
	  0, 0, 0,
	  0.0f, 1.0f, 0.0f
  );

  // фон
  glClearColor(0.3, 0.3, 0.3, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // без этого буквально все элементы становятся 3D (видно сквозь объекты)
  glEnable(GL_DEPTH_TEST);

  // включаем смешивание цвета (для прозрачности)
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /* включаем освещение */
  glEnable(GL_LIGHTING);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_cube);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_cube);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_cube);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_cube);
  glutSolidCube(2);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Sphere);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Sphere);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Sphere);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Sphere);
  glTranslatef(3, 0, 0);
  glutSolidSphere(1, 32, 32);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Tetrahedron);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Tetrahedron);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Tetrahedron);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Tetrahedron);
  glTranslatef(-6, 0, 0);
  glutSolidTetrahedron();

  // для того чтобы поверхность нормально реагировала на свет
  glEnable(GL_AUTO_NORMAL);

  glPopMatrix();
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
