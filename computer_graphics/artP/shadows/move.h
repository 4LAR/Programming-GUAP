/*
  Здесь реализуются функции для ПЕРЕДВИЖЕНИЯ
*/

#include <GL/freeglut.h>

namespace global {
  extern float cam_xz_rotate;
  extern float cam_y_rotate;
  extern float cam_zoom;
  extern float light_xy_rotate;
  extern float light_y_rotate;
  extern float obj_pos[3];
}

bool left = false;
bool right = false;
bool up = false;
bool down = false;

bool obj_left = false;
bool obj_right = false;
bool obj_up = false;
bool obj_down = false;

bool light_left = false;
bool light_right = false;
bool light_up = false;
bool light_down = false;

// отпущенные клавишы
void keyUp(unsigned char key, int xx, int yy) {
  switch (key) {
    // camera
    case ('a'):
      left = false;
      break;

    case ('d'):
      right = false;
      break;

    case ('w'):
      up = false;
      break;

    case ('s'):
      down = false;
      break;

    // объект
    case ('h'):
      obj_left = false;
      break;

    case ('k'):
      obj_right = false;
      break;

    case ('u'):
      obj_up = false;
      break;

    case ('j'):
      obj_down = false;
      break;

    // свет
    case ('1'):
      light_left = false;
      break;

    case ('2'):
      light_right = false;
      break;

    case ('3'):
      light_up = false;
      break;

    case ('4'):
      light_down = false;
      break;

    // выход
    case 27:
       exit (0);
       break;
  }
}

// нажатые клавишы
void keyDown(unsigned char key, int xx, int yy) {
  switch (key) {
    // camera
    case ('a'):
      left = true;
      break;

    case ('d'):
      right = true;
      break;

    case ('w'):
      up = true;
      break;

    case ('s'):
      down = true;
      break;

    // объект
    case ('h'):
      obj_left = true;
      break;

    case ('k'):
      obj_right = true;
      break;

    case ('u'):
      obj_up = true;
      break;

    case ('j'):
      obj_down = true;
      break;

    // свет
    case ('1'):
      light_left = true;
      break;

    case ('2'):
      light_right = true;
      break;

    case ('3'):
      light_up = true;
      break;

    case ('4'):
      light_down = true;
      break;
  }
}

float fraction = 0.05;
float cam_y_rotate_max = 1.5;

float obj_fraction = 0.1;
float light_fraction = 0.1;
// функция для рассчётов передвижений
void move() {
  // camera
  if (left) {
    global::cam_xz_rotate -= fraction;
  }
  if (right) {
    global::cam_xz_rotate += fraction;
  }
  if (up && (global::cam_y_rotate + fraction < cam_y_rotate_max)) {
    global::cam_y_rotate += fraction;
  }
  if (down && (global::cam_y_rotate - fraction > -cam_y_rotate_max)) {
    global::cam_y_rotate -= fraction;
  }

  // объект
  if (obj_up) {
    global::obj_pos[2] -= obj_fraction;
  }
  if (obj_down) {
    global::obj_pos[2] += obj_fraction;
  }
  if (obj_right) {
    global::obj_pos[0] += obj_fraction;
  }
  if (obj_left) {
    global::obj_pos[0] -= obj_fraction;
  }

  // свет
  if (light_left) {
    global::light_pos[2] -= light_fraction;
  }
  if (light_right) {
    global::light_pos[2] += light_fraction;
  }
  if (light_up) {
    global::light_pos[0] += light_fraction;
  }
  if (light_down) {
    global::light_pos[0] -= light_fraction;
  }

}

float fraction_zoom = 1.0;
// прокрутка колеса мыши
void MouseWheel(int button, int dir, int x, int y) {
  if (dir > 0) {
    global::cam_zoom -= fraction_zoom;
  } else {
    global::cam_zoom += fraction_zoom;
  }
}
