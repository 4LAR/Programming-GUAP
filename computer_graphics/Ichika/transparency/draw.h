/*
  Здесь реализуются функции для ПРОРИСОВКИ
*/

#include <iostream>
#include <GL/freeglut.h>

#include <cmath>

/*
  mat_dif - цвет рассеянного отражения материала (прозрачность задаётся 4 параметром)
  mat_spec - цвет зеркального отражения материала
  mat_amb - цвет фонового отражения материала
  mat_shininess - коэффициент блеска
*/

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
  extern bool light_run;
}

// метериалы объектов
// двенадцатигранник (прозрачность задаётся 4 параметром в GL_DIFFUSE)
float mat_dif_Dodecahedron[] = {0.9f, 0.9f, 0.9f, 0.5f};
float mat_spec_Dodecahedron[] = {0.9f, 0.9f, 0.9f};
float mat_amb_Dodecahedron[] = {0.9f, 0.9f, 0.9f};
float mat_shininess_Dodecahedron = 0.1f * 128;

// куб
float mat_dif_Cube[] = {0.9f, 0.2f, 0.2f, 1.0f};
float mat_spec_Cube[] = {0.9f, 0.2f, 0.2f};
float mat_amb_Cube[] = {0.9f, 0.2f, 0.2f};
float mat_shininess_Cube = 0.1f * 128;

// шар
float mat_dif_Sphere[] = {0.2f, 0.9f, 0.2f, 1.0f};
float mat_spec_Sphere[] = {0.2f, 0.9f, 0.2f};
float mat_amb_Sphere[] = {0.2f, 0.9f, 0.2f};
float mat_shininess_Sphere = 0.1f * 128;

// чайник
float mat_dif_Teapot[] = {0.2f, 0.2f, 0.9f, 1.0f};
float mat_spec_Teapot[] = {0.2f, 0.2f, 0.9f};
float mat_amb_Teapot[] = {0.2f, 0.2f, 0.9f};
float mat_shininess_Teapot = 0.1f * 128;

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
float light_position[3][4] = {
  {0.0, 0.0, 0.0, 0.0},
  {0.0, 0.0, 0.0, 0.0},
  {0.0, 0.0, 0.0, 0.0}
};

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
  glClearColor(0.7, 0.7, 0.7, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // без этого буквально все элементы становятся 3D (видно сквозь объекты)
  glEnable(GL_DEPTH_TEST);

  // включаем смешивание цвета (для прозрачности)
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // перемещение испочников света
  if (global::light_run) light_tick += light_position_fraction;
  float light_position_rotate[4];

  /* включаем освещение */
  glEnable(GL_LIGHTING);

  /* настриваем источники света */
  // крутится вокруг сцены (XZ)
  light_position_rotate[0] = light_position[0][0] + (cos(light_tick) * light_position_radius);
  light_position_rotate[1] = light_position[0][1];
  light_position_rotate[2] = light_position[0][2] + (sin(light_tick) * light_position_radius);
  set_light(GL_LIGHT0, light_position_rotate);

  // крутится вокруг сцены (XY)
  light_position_rotate[0] = light_position[1][0] + (sin(light_tick) * light_position_radius);
  light_position_rotate[1] = light_position[1][1] + (cos(light_tick) * light_position_radius);
  light_position_rotate[2] = light_position[1][2];
  set_light(GL_LIGHT1, light_position_rotate);

  // крутится вокруг сцены (XYZ)
  light_position_rotate[0] = light_position[2][0] + (sin(light_tick) * light_position_radius);
  light_position_rotate[1] = light_position[2][1] + (sin(light_tick) * light_position_radius);
  light_position_rotate[2] = light_position[2][2] + (cos(light_tick) * light_position_radius);
  set_light(GL_LIGHT2, light_position_rotate);

  // красный куб
  glTranslatef(5, 0, 5);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Cube);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Cube);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Cube);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Cube);
  glutSolidCube(2);

  // зелёный шар
  glTranslatef(-10, -2, -10);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Sphere);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Sphere);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Sphere);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Sphere);
  glutSolidSphere(2, 10, 10);

  // синий чайник
  glTranslatef(5, 2, 5);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_Teapot);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_Teapot);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_Teapot);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_Teapot);
  glutSolidTeapot(0.5);

  // двенадцатигранник
  glTranslatef(0, 0, 0);
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
