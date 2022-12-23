
/*
  Здесь реализуются функции для ТЕНИ
*/


#include <iostream>
#include <GL/freeglut.h>

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
  extern float light_xy_rotate;
  extern float light_y_rotate;
  extern float obj_pos[3];
  extern  float light_pos[4];
}

void draw_shadow() {
  // измененгие позиции тени
  glTranslatef((global::obj_pos[0] - global::light_pos[0]) / global::light_pos[1], -1.9, (global::obj_pos[2] - global::light_pos[2]) / global::light_pos[1]);
  // маштабирование тени в зависимости от положения источника оп высоте
  glScalef(1 + abs(global::obj_pos[0] - global::light_pos[0]) / (global::light_pos[1] * 5), 0.01, 1 + abs(global::obj_pos[2] - global::light_pos[2]) / (global::light_pos[1] * 5));
  // отрисовка тени
  glutSolidCube(2);

}
