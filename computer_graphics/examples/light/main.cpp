#include <iostream>
using namespace std;
#include <cmath>

#include <GL/glut.h>

/* параметры материала шара */

// угол поворота камеры
float angle=0.0;
// координаты вектора направления движения камеры
float lx=0.0f,lz=-1.0f;
// XZ позиция камеры
float x=0.0f,z=5.0f, y=1.0f;

int refreshMills = 15;

float mat_dif[] = {
  0.9f,
  0.2f,
  0.0f
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

void Display(void)

{

  glLoadIdentity();

  gluLookAt(   x, y,     z,
		  x+lx, 1.0f,  z+lz,
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

  glutSolidSphere(2.0, 32, 32);

  glFlush();

}

void Reshape(int w, int h)

{

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluPerspective(40.0, (GLfloat) w / h, 1, 100.0);

  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();

  glViewport(0, 0, (GLsizei) w, (GLsizei) h);

}

float fraction = 1.0f;
float fraction_angle = 0.1f;

void process_Normal_Keys(unsigned char key, int x, int y) {

    switch (key) {

    case ('w'):
      x += lx * fraction;
      z += lz * fraction;
      break;

    case ('s'):
      x -= lx * fraction;
      z -= lz * fraction;
      break;
    }

}

void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT :
			angle -= fraction_angle;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT :
			angle += fraction_angle;
			lx = sin(angle);
			lz = -cos(angle);
			break;
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

  glutInitWindowSize(500, 500);

  glutCreateWindow("Test");

  glutReshapeFunc(Reshape);

  glutDisplayFunc(Display);

  glutTimerFunc(0, timer, 0);

  glutSpecialFunc(processSpecialKeys);
  glutKeyboardFunc(process_Normal_Keys);

  glutMainLoop();

}
