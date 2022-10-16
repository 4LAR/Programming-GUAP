#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <GL/freeglut.h>
#include <cstdio>
//#include "Header.h"
//#include "stb_image.h"


char title[] = "BOX 3D";

GLfloat angle_y = 0.0f;
GLfloat angle_x = 0.0f;
GLfloat pos_x = 0.0f;
GLfloat pos_y = 1.0f;
GLfloat zoom = -15.0f;
GLuint texture;
GLuint texture1;
GLuint texture2;
int refreshMills = 15;

//РґР»СЏ СЃРІРµС‚Р°
GLfloat pos0[] = { 1, 1, 1, 0 };
GLfloat pos1[] = { 150.0, 0.0, 600.0, 1.0 };
GLfloat direction[] = { 1.0, 1.0, -100.0 };
GLfloat diffuseColor1[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat ambientColor0[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat diffuseColor0[] = { 1, 1, 0, 0.6 };

GLfloat diffuseColor2[] = { 0.3, 0.5, 0.1, 1.0 };
GLfloat ambientColor2[] = { 0.6, 0.8, 0.8, 1.0 };
GLfloat pos2[] = { 700.0, 123.0, 300.0, 1.0 };
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos0);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, pos1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 100.0);

    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseColor2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, ambientColor2);
    glLightfv(GL_LIGHT2, GL_POSITION, pos2);

    glLoadIdentity();
    glTranslatef(pos_x, pos_y, zoom);
    glRotatef(angle_x, 0.0f, 1.0f, 0.0f);
    glRotatef(angle_y, 1.0f, 0.0f, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHT0);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glBindTexture(GL_TEXTURE_2D, texture);

    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

    GLfloat miror[] = { 0.4, 0.4, 0.4, 1.0 };
    GLfloat dif[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat AMB[] = { 0.1, 0.4, 0.8, 1.0 };
    GLfloat EMIS[] = { 0.1, 0.2, 0.3, 1.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB); //СЂР°СЃСЃРµСЏРЅРЅС‹Р№ С†РІРµС‚
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror); //Р·РµСЂРєР°Р»СЊРЅС‹Р№ С†РІРµС‚
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif); //РґРёС„С„СѓР·РЅС‹Р№ С†РІРµС‚
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, EMIS); //РёРЅС‚РµРЅСЃРёРІРЅРѕСЃС‚СЊ РёР·Р»СѓС‡Р°РµРјРѕРіРѕ СЃРІРµС‚Р°

   glBindTexture(GL_TEXTURE_2D, texture2);
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambientColor0);
    glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 2.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 2.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, -1.0f);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 2.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 0.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 2.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, -1.0f);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 2.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 2.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 0.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, 0.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, 2.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 2.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 0.0f, -1.0f);


    glEnd();


    glTranslatef(0.0f, -2.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, texture1);
    //bg

    GLfloat miror2[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat dif2[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat AMB2[] = { 0.3, 0.4, 0.8, 1.0 };
    GLfloat EMIS2[] = { 0.1, 0.2, 0.3, 1.0 };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, AMB2); //СЂР°СЃСЃРµСЏРЅРЅС‹Р№ С†РІРµС‚
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, miror2); //Р·РµСЂРєР°Р»СЊРЅС‹Р№ С†РІРµС‚
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dif2); //РґРёС„С„СѓР·РЅС‹Р№ С†РІРµС‚
    //glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,EMIS); //РёРЅС‚РµРЅСЃРёРІРЅРѕСЃС‚СЊ РёР·Р»СѓС‡Р°РµРјРѕРіРѕ СЃРІРµС‚Р°



    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -2.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, 2.0f, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 2.0f, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -2.0f, 0.0f);


    glEnd();

    glFlush();
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    glutSwapBuffers();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // С†РІРµС‚ С„РѕРЅР°
    glClearDepth(1.0f);                   // РіР»СѓР±РёРЅР° С„РѕРЅР°
    glEnable(GL_DEPTH_TEST);   // РІСЂСѓР±Р°РµРј depth test
    glDepthFunc(GL_LEQUAL);    // С‚РёРї depth test
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
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


    case ('u'):
        pos0[0] = pos0[0] + 2;

        break;

    case ('i'):
        pos0[1] = pos0[1] + 2;
        break;

    case ('o'):
        pos0[2] = pos0[2] + 2;
        break;

    case ('p'):
        pos0[3] = pos0[3] + 2;
        break;

    case ('j'):
        pos0[0] = pos0[0] - 2;

        break;

    case ('k'):
        pos0[1] = pos0[1] - 2;
        break;

    case ('l'):
        pos0[2] = pos0[2] - 2;
        break;

    case (';'):
        pos0[3] = pos0[3] - 2;
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
    glutInitWindowSize(640, 480); // СЂР°Р·РјРµСЂС‹ РѕРєРЅР°
    glutInitWindowPosition(50, 50); // РїРѕР·РёС†РёСЏ РѕРєРЅР° РЅР° СЌРєСЂР°РЅРµ
    glutCreateWindow(title); // СЃРѕР·РґР°С‘Рј РѕРєРЅРѕ
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    initGL();

    // texture1 = LoadTexture("box_image1.bmp", 316, 316);
    // texture2 = LoadTexture("box_image1.bmp", 316, 316);


    //glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, texture);


    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(process_Normal_Keys);

    glutMainLoop();

    return 0;
}
