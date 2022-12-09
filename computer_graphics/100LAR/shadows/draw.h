/*
  Здесь реализуются функции для ПРОРИСОВКИ
*/

#include <iostream>
#include <GL/freeglut.h>

#include <cmath>

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
  extern float light_xy_rotate;
  extern float light_y_rotate;
}

// метериалы объектов

// настройки света
// материал объекта для визуализации источника
float mat_dif_light[] = {0.9f, 0.9f, 0.0f, 1.0f};
float mat_spec_light[] = {0.9f, 0.9f, 0.0f};
float mat_amb_light[] = {0.9f, 0.9f, 0.0f};
float mat_shininess_light = 0.1f * 128;

// материал света
float matl_dif_light[] = {0.9f, 0.9f, 0.9f, 1.0f};

// перемещение света
float light_position_fraction = 0.02;
float light_position_radius = 10;
float light_tick = 0;
// центр вращения XYZ и W (если поставить не 0, то будет точечный источник света)
float light_position[4] = {0.0, 5.0, 0.0, 0.0};

// функция для отображения и включения света
void set_light(GLenum name, GLfloat *light_position) {
  // материал света
  glLightfv(name, GL_DIFFUSE, matl_dif_light);
  glLightfv(name, GL_POSITION, light_position);
  glLightf(name, GL_SPOT_CUTOFF, 360);

  // материал объекта который визуализирует источник света
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_light);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_light);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_light);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_light);

  glTranslatef(light_position[0], light_position[1], light_position[2]);
  glutSolidSphere(0.2, 32, 32);
  glTranslatef(-light_position[0], -light_position[1], -light_position[2]);

  // включаем свет
  glEnable(name);
}

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
  glClearColor(0, 0.3, 0.3, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // без этого буквально все элементы становятся 3D (видно сквозь объекты)
  glEnable(GL_DEPTH_TEST);

  // включаем смешивание цвета (для прозрачности)
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  /* включаем освещение */
  glEnable(GL_LIGHTING);

  /* настриваем источники света */
  // light_position_rotate[0] = light_position[0][0] + (cos(light_tick) * light_position_radius);
  // light_position_rotate[1] = light_position[0][1];
  // light_position_rotate[2] = light_position[0][2] + (sin(light_tick) * light_position_radius);
  // set_light(GL_LIGHT0, light_position_rotate);

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
