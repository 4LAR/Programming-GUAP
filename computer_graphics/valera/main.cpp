
#include <iostream>

#include <GL/freeglut.h> // opengl
#include <cstdio>

char title[] = "3D Valera";

GLfloat angle_y = 0.0f;
GLfloat angle_x = 0.0f;
GLfloat pos_x = 0.0f;
GLfloat pos_y = 0.0f;
GLfloat zoom = -7.0f;
int refreshMills = 15;

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  glLoadIdentity();
  glTranslatef(pos_x, pos_y, zoom);
  glRotatef(angle_x, 0.0f, 1.0f, 0.0f);
  glRotatef(angle_y, 1.0f, 0.0f, 0.0f);

  glBegin(GL_QUADS);

    glColor3f(1.0f, 0.0f, 0.0f);
    // x, y, z
    glVertex3f( 1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f,  1.0f);
    glVertex3f( 1.0f, 1.0f,  1.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f( 1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f,  1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, 1.0f);

    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f( 1.0f,  1.0f, -1.0f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f,  1.0f,  1.0f);
    glVertex3f(-1.0f,  1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,  1.0f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f,  1.0f, -1.0f);
    glVertex3f(1.0f,  1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f,  1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();

  glFlush();

  glPopMatrix();
  glutSwapBuffers();
}

// инициализируем всякий кал
void initGL() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // цвет фона
  glClearDepth(1.0f);                   // глубина фона
  glEnable(GL_DEPTH_TEST);   // врубаем depth test
  glDepthFunc(GL_LEQUAL);    // тип depth test
  glShadeModel(GL_SMOOTH);   //
  glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  //
}

void process_Normal_Keys(unsigned char key, int x, int y) {

    switch (key) {

    // rot_x
    case ('a'):
        angle_x -= 10;
        break;

    case ('d'):
        angle_x += 10;
        break;

    // rot_y
    case ('w'):
        angle_y -= 10;
        break;

    case ('s'):
        angle_y += 10;
        break;

    // zoom
    case ('z'):
        zoom += 1;
        break;

    case ('x'):
        zoom -= 1;
        break;

    default:
        break;

    // pos_x
    case ('q'):
        pos_x -= 0.1;
        break;

    case ('e'):
        pos_x += 0.1;
        break;

    // pos_y
    case ('r'):
        pos_y += 0.1;
        break;

    case ('f'):
        pos_y -= 0.1;
        break;

    }

}

void reshape(GLsizei width, GLsizei height) {

  if (height == 0) height = 1;
  GLfloat aspect = (GLfloat)width / (GLfloat)height;


  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, timer, 0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480); // размеры окна
  glutInitWindowPosition(50, 50); // позиция окна на экране
  glutCreateWindow(title); // создаём окно

  initGL();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutTimerFunc(0, timer, 0);
  glutKeyboardFunc(process_Normal_Keys);

  glutMainLoop();

  return 0;
}