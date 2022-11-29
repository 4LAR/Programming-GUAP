//
// /*
//
// */
//
// #include <iostream>
// using namespace std;
//
// #include <cstring>
//
//
// // opengl
// #include <GL/glut.h>
//
// //
// #include <cstdlib>
//
// void initGL() {
//   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
//   glClearDepth(1.0f);                   // Set background depth to farthest
//   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
//   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//   glShadeModel(GL_SMOOTH);   // Enable smooth shading
//   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
// }
//
// int* read_obj_file() {
//   FILE *obj_file = fopen("monkey.obj", "r");
//
//   char v;
//   double x, y, z;
//
//   char lineHeader[128];
//
//   while (!feof(obj_file)) {
//     fscanf(obj_file, "%s", &lineHeader);
//     if (strcmp(lineHeader, "v" ) == 0) {
//       fscanf(obj_file, "%lf %lf %lf\n", &x, &y, &z);
//
//       cout << v << x << y << z << endl;
//     }
//
//   }
//
// }
//
// int main(int argc, char** argv) {
//   glutInit(&argc, argv);            // Initialize GLUT
//   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
//   glutInitWindowSize(640, 480);   // Set the window's initial width & height
//   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
//   glutCreateWindow("test");
//
//   read_obj_file();
//
//   glutMainLoop();
//
//   return 0;
// }

// #include <GL/glut.h>
// #include <stdlib.h>
//
// /* GLUT callback Handlers */
// static void resize(int width, int height)
// {
//     const float ar = (float) width / (float) height;
//
//     glViewport(0, 0, width, height);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
//
//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity() ;
// }
//
// static void display(void)
// {
//     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//     glBegin(GL_QUADS);
//     int size = 2;
//      // левая грань
//      glVertex3f( -size / 2, -size / 2, -size / 2);
//      glVertex3f( -size / 2,  size / 2, -size / 2);
//      glVertex3f( -size / 2,  size / 2,  size / 2);
//      glVertex3f( -size / 2, -size / 2,  size / 2);
//      // правая грань
//      glVertex3f(  size / 2, -size / 2, -size / 2);
//      glVertex3f(  size / 2, -size / 2,  size / 2);
//      glVertex3f(  size / 2,  size / 2,  size / 2);
//      glVertex3f(  size / 2,  size / 2, -size / 2);
//      // нижняя грань
//      glVertex3f( -size / 2, -size / 2, -size / 2);
//      glVertex3f( -size / 2, -size / 2,  size / 2);
//      glVertex3f(  size / 2, -size / 2,  size / 2);
//      glVertex3f(  size / 2, -size / 2, -size / 2);
//      // верхняя грань
//      glVertex3f( -size / 2, size / 2, -size / 2);
//      glVertex3f( -size / 2, size / 2,  size / 2);
//      glVertex3f(  size / 2, size / 2,  size / 2);
//      glVertex3f(  size / 2, size / 2, -size / 2);
//      // задняя грань
//      glVertex3f( -size / 2, -size / 2, -size / 2);
//      glVertex3f(  size / 2, -size / 2, -size / 2);
//      glVertex3f(  size / 2,  size / 2, -size / 2);
//      glVertex3f( -size / 2,  size / 2, -size / 2);
//      // передняя грань
//      glVertex3f( -size / 2, -size / 2,  size / 2);
//      glVertex3f(  size / 2, -size / 2,  size / 2);
//      glVertex3f(  size / 2,  size / 2,  size / 2);
//      glVertex3f( -size / 2,  size / 2,  size / 2);
//     glEnd();
//     glutSwapBuffers();
// }

//
// static void key(unsigned char key, int x, int y)
// {
//     switch (key)
//     {
//         case 27 :
//         case 'q':
//             exit(0);
//             break;
//     }
//     glutPostRedisplay();
// }
//
// static void idle(void)
// {
//     glutPostRedisplay();
// }
//
// /* Program entry point */
// int main(int argc, char *argv[])
// {
//     glutInit(&argc, argv);
//     glutInitWindowSize(640,480);
//     glutInitWindowPosition(10,10);
//     glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//
//     glutCreateWindow("GLUT quadPoly");
//
//     glutReshapeFunc(resize);
//     glutDisplayFunc(display);
//     glutKeyboardFunc(key);
//     glutIdleFunc(idle);
//
//     glClearColor(0,0,0,0);
//
//     glutMainLoop();
//
//     return EXIT_SUCCESS;
// }


#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
//globals
GLuint elephant;
float elephantrot;
char ch='1';
//other functions and main
//wavefront .obj loader code begins
void loadObj(char *fname)
{
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    elephant=glGenLists(1);
    fp=fopen(fname,"r");
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(elephant, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read==4&&ch=='v')
            {
                glVertex3f(x,y,z);
            }
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}
//wavefront .obj loader code ends here
void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
    //glOrtho(-25,25,-2,2,0.1,100);
    glMatrixMode(GL_MODELVIEW);
}
void drawElephant()
{
    glPushMatrix();
    glTranslatef(0,-10.00,-105);
    glColor3f(1.0,0.23,0.27);
    glScalef(20,20,20);
    glRotatef(elephantrot,0,1,0);
    glCallList(elephant);
    glPopMatrix();
    elephantrot=elephantrot+0.6;
    if(elephantrot>360)elephantrot=elephantrot-360;
}
void display(void)
{
    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    drawElephant();
    glutSwapBuffers(); //swap the buffers
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,450);
    glutInitWindowPosition(20,20);
    glutCreateWindow("ObjLoader");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    loadObj("monkey.obj");//replace elepham.obj withp orsche.obj or radar.obj or any other .obj to display it
    glutMainLoop();
    return 0;
}
