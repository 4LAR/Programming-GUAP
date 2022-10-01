
#include <iostream>

#include <GL/glut.h> // opengl
#include <cstdio>

char title[] = "Каловые массы 3D";

GLfloat angle_y = 0.0f;
GLfloat angle_x = 0.0f;
GLfloat zoom = 0.0f;
int refreshMills = 15;

GLuint texture;

GLuint LoadTexture( const char * filename )
{

  GLuint texture;

  int width, height;

  unsigned char * data;

  FILE * file;

  file = fopen( filename, "rb" );

  if ( file == NULL ) return 0;
  width = 16;
  height = 16;
  data = (unsigned char *)malloc( width * height * 3 );
  //int size = fseek(file,);
  fread( data, width * height * 3, 1, file );
  fclose( file );

 for(int i = 0; i < width * height ; ++i)
{
   int index = i*3;
   unsigned char B,R;
   B = data[index];
   R = data[index+2];

   data[index] = R;
   data[index+2] = B;

}


glGenTextures( 1, &texture );
glBindTexture( GL_TEXTURE_2D, texture );
glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );


glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
free( data );

return texture;
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 0.0f, -7.0f);  // Move right and into the screen
   glRotatef(angle_x, 0.0f, 1.0f, 0.0f);
   glRotatef(angle_y, 1.0f, 0.0f, 0.0f);

   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glBindTexture (GL_TEXTURE_2D, texture);

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      //glColor3f(0.0f, 1.0f, 0.0f);     // Green
      
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0f, 1.0f, -1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, 1.0f,  1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      //glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0f, -1.0f,  1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, -1.0f,  1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      //glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0f,  1.0f, 1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f,  1.0f, 1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      //glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glTexCoord2f(0.0, 0.0); glVertex3f( 1.0f, -1.0f, -1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f,  1.0f, -1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      //glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glTexCoord2f(0.0, 0.0); glVertex3f(-1.0f,  1.0f,  1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(-1.0f,  1.0f, -1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      //glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glTexCoord2f(0.0, 0.0); glVertex3f(1.0f,  1.0f, -1.0f);
      glTexCoord2f(0.0, 1.0); glVertex3f(1.0f,  1.0f,  1.0f);
      glTexCoord2f(1.0, 1.0); glVertex3f(1.0f, -1.0f,  1.0f);
      glTexCoord2f(1.0, 0.0); glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube

   glFlush();
   glDisable(GL_TEXTURE_2D);

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
    std::cout << key << std::endl;

    switch (key) {
    case ('a'):
        angle_x -= 10;
        break;

    case ('d'):
        angle_x += 10;
        break;

    case ('w'):
        angle_y += 10;
        break;

    case ('s'):
        angle_y -= 10;
        break;
    
    default:
        break;
    }
    
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); // врубаем "двойной буфер"
    glutInitWindowSize(640, 480); // размеры окна
    glutInitWindowPosition(50, 50); // позиция окна на экране
    glutCreateWindow(title); // создаём окно

    texture= LoadTexture( "test2.bmp" );

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    initGL();
    
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(process_Normal_Keys);

    glutMainLoop();

    return 0;
}