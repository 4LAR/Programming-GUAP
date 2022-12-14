
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
}

void draw_shadow(float* light_position) {
  // измененгие позиции тени
  glTranslatef((global::obj_pos[0] - light_position[0]) / light_position[1], -1.9, (global::obj_pos[2] - light_position[2]) / light_position[1]);
  // маштабирование тени в зависимости от положения источника оп высоте
  glScalef(1 + abs(global::obj_pos[0] - light_position[0]) / (light_position[1] * 5), 0.1, 1 + abs(global::obj_pos[2] - light_position[2]) / (light_position[1] * 5));
  // отрисовка тени
  glutSolidTeapot(1);

}
