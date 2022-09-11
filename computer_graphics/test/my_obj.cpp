


#include <iostream>
using namespace std;

#include<GL/gl.h>
#include<GL/glut.h>

#include "obj_reader.h"

Obj obj;

void reshape(int w,int h) {
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
  //glOrtho(-25,25,-2,2,0.1,100);
  glMatrixMode(GL_MODELVIEW);
}

void display(void) {

  obj.draw();

}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(800,450);
  glutInitWindowPosition(20,20);
  glutCreateWindow("ObjLoader");

  bool ok = obj.open("monkey.obj");

  if (ok) {
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    //glutIdleFunc(display);

    glutMainLoop();
  }



  return 0;


}
