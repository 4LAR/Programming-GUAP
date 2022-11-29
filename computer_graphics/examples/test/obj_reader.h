


#include <iostream>
using namespace std;

#include <stdio.h>

#include <GL/gl.h>
#include <GL/glut.h>

class Obj {
  public:
    //
    bool open(const char* file_name) {
      FILE *file;

      file = fopen(file_name, "r");

      if (!file) {
        return false;

      } else {
        list = glGenLists(1);
        glPointSize(2.0);
        glNewList(list, GL_COMPILE);


        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(file))) {
            read = fscanf(file,"%c %f %f %f", &ch,&x,&y,&z);
            if(read == 4 && ch=='v') {
                glVertex3f(x,y,z);
            }


        }
        glEnd();
        glPopMatrix();
        glEndList();
        fclose(file);

      }

      return true;
    }

    //
    void draw() {
      glClearColor (0.0,0.0,0.0,1.0);
      glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();

      glPushMatrix();
      glTranslatef(0,-10.00,-105);
      glColor3f(1.0,0.23,0.27);
      glScalef(20,20,20);

      glCallList(list);

      glPopMatrix();

      glutSwapBuffers(); //swap the buffers
    }

  private:
    GLfloat x, y, z;
    char ch;
    int read;

    GLuint list;



};
