#include <stdlib.h>

#include <GL/glut.h>

/* параметры материала шара */

float mat_dif[] = {
  0.9 f,
  0.2 f,
  0.0 f
};

float mat_spec[] = {
  0.8 f,
  0.8 f,
  0.9 f
};

float mat_amb[] = {
  0.2 f,
  0.0 f,
  0.2 f
};

float mat_shininess = 0.1 f * 128;

/* параметры источника света */

GLfloat light_position[] = {
  5.0,
  5.0,
  5.0,
  0.0
};

void Display(void)

{

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

  gluLookAt(0.0 f, 0.0 f, 7.0 f, /* положение камеры */

    0.0 f, 0.0 f, 0.0 f, /* центр сцены */

    0.0 f, 1.0 f, 0.0 f); /* положит. направление оси y */

}

#pragma argsused

void Keyboard(unsigned char key, int x, int y)

{

  switch (key)

  {
  case 27:
    exit(0);
    break;
  }

}

int main(int argc, char ** argv) {
  glutInit( & argc, argv);

  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

  glutInitWindowPosition(150, 50);

  glutInitWindowSize(500, 500);

  glutCreateWindow("Test");

  glutReshapeFunc(Reshape);

  glutDisplayFunc(Display);

  glutKeyboardFunc(Keyboard);

  glutMainLoop();

}
