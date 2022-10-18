#include <iostream>
using namespace std;
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

int refreshMills = 0;

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

void Display(void) {

  glLoadIdentity();

  gluLookAt(x, y, z,
		  x+lx, y+ly,  z+lz,
		  0.0f, 1.0f,  0.0f );

  glClearColor(0, 0.3, 0.3, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

  // glBegin(GL_QUADS);

  //   glVertex3f( 1.0f, 1.0f, -1.0f);
  //   glVertex3f(-1.0f, 1.0f,  1.0f);
  //   glVertex3f( 1.0f, 1.0f,  1.0f);
  //   glVertex3f(-1.0f, 1.0f, -1.0f);


  //   glVertex3f( 1.0f, -1.0f,  1.0f);
  //   glVertex3f(-1.0f, -1.0f,  1.0f);
  //   glVertex3f(-1.0f, -1.0f, -1.0f);
  //   glVertex3f( 1.0f, -1.0f, -1.0f);


  //   glVertex3f( 1.0f,  1.0f, 1.0f);
  //   glVertex3f(-1.0f,  1.0f, 1.0f);
  //   glVertex3f(-1.0f, -1.0f, 1.0f);
  //   glVertex3f( 1.0f, -1.0f, 1.0f);


  //   glVertex3f( 1.0f, -1.0f, -1.0f);
  //   glVertex3f(-1.0f, -1.0f, -1.0f);
  //   glVertex3f(-1.0f,  1.0f, -1.0f);
  //   glVertex3f( 1.0f,  1.0f, -1.0f);


  //   glVertex3f(-1.0f,  1.0f,  1.0f);
  //   glVertex3f(-1.0f,  1.0f, -1.0f);
  //   glVertex3f(-1.0f, -1.0f, -1.0f);
  //   glVertex3f(-1.0f, -1.0f,  1.0f);


  //   glVertex3f(1.0f,  1.0f, -1.0f);
  //   glVertex3f(1.0f,  1.0f,  1.0f);
  //   glVertex3f(1.0f, -1.0f,  1.0f);
  //   glVertex3f(1.0f, -1.0f, -1.0f);
  // glEnd();

   //glutSolidSphere(2.0, 5, 5);
   //glutSolidCube(2.0);
   glutSolidTeapot(2);

  // glTranslatef(-10.0f, 0.0f, 10.0f);
  // glutSolidSphere(2.0, 32, 32);

  // glTranslatef(10.0f, 0.0f, 10.0f);
  // glutSolidSphere(2.0, 32, 32);

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

float fraction = -1.0f;
float fraction_angle = 0.1f;

bool use_mouse = true;

void process_Normal_Keys(unsigned char key, int xx, int yy) {
    switch (key) {
    case ('w'):
      z -= lz * fraction;
      x -= lx * fraction;
      y -= ly * fraction;
      break;

    case ('s'):
      z += lz * fraction;
      x += lx * fraction;
      y += ly * fraction;
      break;

    case ('a'):
      z += lx * fraction;
      x -= lz * fraction;
      break;

    case ('d'):
      z -= lx * fraction;
      x += lz * fraction;
      break;

    // включить (выключить курсор)
    case ('g'):
      use_mouse = !use_mouse;
      break;

    }

}

void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_LEFT :
			angle_x -= fraction_angle;
			lx = sin(angle_x);
			lz = -cos(angle_x);
			break;
		case GLUT_KEY_RIGHT :
			angle_x += fraction_angle;
			lx = sin(angle_x);
			lz = -cos(angle_x);
			break;

    case GLUT_KEY_UP :
			angle_y += fraction_angle;
			ly = sin(angle_y);
			break;
		case GLUT_KEY_DOWN :
			angle_y -= fraction_angle;
			ly = sin(angle_y);
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


void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, timer, 0);
}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(150, 50);
  glutInitWindowSize(W_WIDTH, W_HEIGHT);
  glutCreateWindow("light");
  glutReshapeFunc(Reshape);
  glutDisplayFunc(Display);


  glutSpecialFunc(processSpecialKeys);
  glutKeyboardFunc(process_Normal_Keys);

  glutPassiveMotionFunc(mouseMove);

  glutTimerFunc(0, timer, 0);

  //glutMouseFunc(mouseButton);
  //glutPassiveMotionFunc(mouseMove);
	//glutMotionFunc(mouseMove);

  glutMainLoop();

}
