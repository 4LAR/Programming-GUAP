#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#define W_WIDTH 1280
#define W_HEIGHT 720

/* параметры материала шара */

// угол поворота камеры
double angle_x=0.0;
double angle_y=0.0;
// координаты вектора направления движения камеры
float lx=0.0f, ly=0.0f, lz=-1.0f;
// XZ позиция камеры
float x=1.0f, y=1.0f, z=5.0f;

int refreshMills = 60;

float fraction = -1.0f;
float fraction_angle = 0.1f;

bool use_mouse = true;

bool forward = false;
bool back = false;
bool left = false;
bool right = false;

float mat_dif[] = {
  0.9f,
  0.9f,
  0.9f
};

float mat_spec[] = {
  0.8f,
  0.8f,
  0.9f
};

float mat_amb[] = {
  0.2f,
  0.0f,
  0.2f
};

float mat_shininess = 0.1f * 128;

/* параметры источника света */
GLfloat light_position[] = {
  5.0,
  5.0,
  5.0,
  0.0
};

void drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void Reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, (GLfloat) w / h, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

}

void move() {
  if (forward) {
    z -= lz * fraction;
    x -= lx * fraction;
    y -= ly * fraction;
  }

  if (back) {
    z += lz * fraction;
    x += lx * fraction;
    y += ly * fraction;
  }

  if (left) {
    z += lx * fraction;
    x -= lz * fraction;
  }

  if (right) {
    z -= lx * fraction;
    x += lz * fraction;
  }

}

void keyUp(unsigned char key, int xx, int yy) {
  switch (key) {
  case ('w'):
    forward = false;
    break;

  case ('s'):
    back = false;
    break;

  case ('a'):
    left = false;
    break;

  case ('d'):
    right = false;
    break;

  // включить (выключить курсор)
  case ('g'):
    use_mouse = !use_mouse;
    break;

  // выход
  case 27:
     //glutDestroyWindow ( Win.id );
     exit (0);
     break;

  }
}

void keyDown(unsigned char key, int xx, int yy) {
  switch (key) {
  case ('w'):
    forward = true;
    break;

  case ('s'):
    back = true;
    break;

  case ('a'):
    left = true;
    break;

  case ('d'):
    right = true;
    break;

  }
}

double sensivity = 0.001;

void mouseMove(int xx, int yy) {
  if (use_mouse) {
    angle_x -= (W_WIDTH/2 - xx) * sensivity;
    angle_y += (W_HEIGHT/2 - yy) * sensivity;
  	lx = sin(angle_x);
  	lz = -cos(angle_x);
    ly = sin(angle_y);
    glutWarpPointer(
      W_WIDTH / 2,
      W_HEIGHT / 2
    );
  }
}

void Display(void) {

  move();

  glLoadIdentity();

  gluLookAt(x, y, z,
		  x+lx, y+ly,  z+lz,
		  0.0f, 1.0f,  0.0f );

  glClearColor(0, 0.3, 0.3, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  drawText(0, 0, "hello world");

  glEnable(GL_DEPTH_TEST);

  /* устанавливаем параметры источника света */
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  /* включаем освещение и источник света */
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  /* задаем материал и отображаем шар */
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

  glTranslatef(0.0f, -2.0f, 0.0f);

  //glutSolidSphere(2.0, 5, 5);
  //glutSolidCube(2.0);
  glutSolidTeapot(2);

  glTranslatef(-10.0f, 0.0f, 10.0f);
  glutSolidCube(2.0);

  glTranslatef(10.0f, 0.0f, 10.0f);
  glutSolidSphere(2.0, 32, 32);

  glFlush();

}

void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(1000/refreshMills, timer, 0);
}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(150, 50);
  glutInitWindowSize(W_WIDTH, W_HEIGHT);
  glutCreateWindow("light");
  glutReshapeFunc(Reshape);
  glutDisplayFunc(Display);

  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

  //glutSpecialFunc(processSpecialKeys);
  //glutKeyboardFunc(process_Normal_Keys);

  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);

  glutPassiveMotionFunc(mouseMove);

  glutTimerFunc(0, timer, 0);

  //glutMouseFunc(mouseButton);
  //glutPassiveMotionFunc(mouseMove);
	//glutMotionFunc(mouseMove);

  glutMainLoop();

}
