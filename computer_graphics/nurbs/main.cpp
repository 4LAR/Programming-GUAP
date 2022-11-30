#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"

#define W_WIDTH 1280
#define W_HEIGHT 720

// camera

double angle_x=0.0;
double angle_y=-5000.0;
float lx=0.0f, ly=0.0f, lz=-1.0f;
float x=0.0f, y=0.0f, z=10.0f;

int refreshMills = 60;

float fraction = -0.5f;
float fraction_angle = 0.1f;

float light_fraction = -0.5f;

bool use_mouse = true;

bool forward = false;
bool back = false;
bool left = false;
bool right = false;

// nurbs

const int size_numb_x = 4;
const int size_numb_y = 4;

GLfloat ctlpoints[size_numb_x][size_numb_y][3];
GLfloat knots[size_numb_x + size_numb_y] = {
  0.0, 0.0, 0.0, 0.0,
  1.0, 1.0, 1.0, 1.0
};
int showPoints = 0;

GLUnurbsObj* theNurb;

// lihgt
GLfloat ambientColor_light[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat diffuseColor_light[] = { 1, 1, 1, 1.0 };
GLfloat emis_light[] = { 1.0, 1.0, 1.0, 1.0 };

// GLfloat light_position[4] = {10.0, 5.0, -10.0, 1.0};
GLfloat light_position[4] = {30.0, 10.0, 0.0, 1.0};
GLfloat light_direction[3] = {0.0, 0.0, 0.0};

float mat_dif_light[] = {1.0f, 1.0f, 1.0f, 1.0};

// texture
GLuint theTorus;
GLuint texture;

// fog

bool   fog_bool = false;
GLuint filter;
GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR };
GLuint fogfilter = 0;
GLfloat fogColor[4] = { 0.5f, 0.5f, 0.5f, 1.0f };

void fog_on() {
  glEnable(GL_FOG);                       // Включает туман (GL_FOG)
  glFogi(GL_FOG_MODE, fogMode[fogfilter]);// Выбираем тип тумана
  glFogfv(GL_FOG_COLOR, fogColor);        // Устанавливаем цвет тумана
  glFogf(GL_FOG_DENSITY, 0.05f);          // Насколько густым будет туман
  glHint(GL_FOG_HINT, GL_DONT_CARE);      // Вспомогательная установка тумана
  glFogf(GL_FOG_START, 1.0f);             // Глубина, с которой начинается туман
  glFogf(GL_FOG_END, 5.0f);               // Глубина, где туман заканчивается.
}

// functions

void move() {
  // camera
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
  // camera
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

    // fog
  case ('f'):
    fog_bool = !fog_bool;
    if (fog_bool) glDisable(GL_FOG);
    else glEnable(GL_FOG);
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

  // camera
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

void gen() {
  theTorus = glGenLists (1);
  float mod = 2.0;
  float mod_scale = 2.8;
  glNewList(theTorus, GL_COMPILE);
  glRotatef(90.0, 1.0, 0.0, 0.0);
  for (int i = 1; i < 5; i++) {
    // glRotatef(i * 50, 0.0, 1.0, 0.0);
    glTranslatef(0.0f, -i * mod, 0.0f);

    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glBindTexture (GL_TEXTURE_2D, texture);

    if (i == 2) {
      glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f,  1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
      glEnd();

    } else if (i == 1) {
      glutSolidTeapot(2);

    } else {
      glutSolidSphere(i, 10, 10);
    }

    // glutSolidDodecahedron();

    // glutSolidTeapot((float)(i / 1));


    // glutSolidCube(i);

    glTranslatef(0.0f, i * mod, 0.0f);
  }
  glRotatef(-90.0, 1.0, 0.0, 0.0);

  glEndList();
}

void mouseMove(int xx, int yy) {
  if (use_mouse) {
    angle_x -= (W_WIDTH/2 - xx) * sensivity;
    if ((angle_y + (W_HEIGHT/2 - yy) * sensivity < -4998.3) && (angle_y + (W_HEIGHT/2 - yy) * sensivity > -5001.3)) {
      angle_y += (W_HEIGHT/2 - yy) * sensivity;
    }

    lx = sin(angle_y) * sin(angle_x);
    ly = -cos(angle_y);
    lz = -sin(angle_y) * cos(angle_x);
    glutWarpPointer(
      W_WIDTH / 2,
      W_HEIGHT / 2
    );
  }
}

void init_surface(void) {
    int u, v;
    int m = 50; // 2
    for (u = 0; u < size_numb_y; u++) {
        for (v = 0; v < size_numb_x; v++) {
            ctlpoints[u][v][0] = m * ((GLfloat)u - 1.5);
            ctlpoints[u][v][1] = m * ((GLfloat)v - 1.5);

            if ((u == 1 || u == 2) && (v == 1 || v == 2))
                ctlpoints[u][v][2] = 3.0;
            // else
            //     ctlpoints[u][v][2] = -1.0;
        }
    }
}

void display(void) {
  glLoadIdentity();
  move();
  gluLookAt(x, y, z,
  	  x+lx, y+ly,  z+lz,
  	  0.0f, 1.0f,  0.0f );

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0.3, 0.3, 1);
  glPushMatrix();
  glEnable(GL_DEPTH_TEST);

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseColor_light);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambientColor_light);
  glLightfv(GL_LIGHT0, GL_EMISSION, emis_light);

  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
  glTranslatef(light_position[0], light_position[1], light_position[2]);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_light);
  glutSolidSphere(0.2, 32, 32);
  glTranslatef(-light_position[0], -light_position[1], -light_position[2]);

  glTranslatef(0.0f, 0.0f, 0.0f);
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  gluBeginSurface(theNurb);

  glDisable(GL_TEXTURE_2D);
  glBindTexture (GL_TEXTURE_2D, texture);
  gluNurbsSurface(theNurb,
      size_numb_x + size_numb_y, knots, size_numb_x + size_numb_y, knots,
      size_numb_x * 3, 3, &ctlpoints[0][0][0],
      4, 4, GL_MAP2_VERTEX_3);

  gluEndSurface(theNurb);

  glTranslatef(-50.0f, -50.0f, 11.0f);

  int x;
  for (int y = 0; y < 4; y++) {
    glTranslatef(0.0f, 15.0f, 0.0f);
    for (x = 0; x < 4; x++) {
      glTranslatef(15.0f, 0.0f, 0.0f);
      glCallList(theTorus);

    }
    glTranslatef(-15.0f * x, 0.0f, 0.0f);
  }

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
  glFlush();
}

void init(void) {
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_MAP2_VERTEX_3);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
}

void reshape(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(40.0, (GLfloat) w / h, 1, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(1000/refreshMills, timer, 0);
}

int main(int argc, char** argv) {
  std::cout << "HELLO WORLD" << std::endl;

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(150, 50);
  glutInitWindowSize(W_WIDTH, W_HEIGHT);
  glutCreateWindow("nurbs");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

  int width, height, nrChannels;
  unsigned char *data = stbi_load("snow.png", &width, &height, &nrChannels, 0);

  glGenTextures(1, &texture);
  std::cout << texture << std::endl;
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

  // stbi_image_free(data);

  init();
  fog_on();
  gen();

  init_surface();

  GLfloat mat_diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
  GLfloat mat_specular[] = { 0.5, 0.5, 0.5, 1.0 };
  GLfloat mat_emission[] = { 0.5, 0.5, 0.5, 1.0 };
  // GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat mat_shininess[] = { 128.0 };

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);

  theNurb = gluNewNurbsRenderer();
  gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 50.0);
  gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);
  gluNurbsProperty(theNurb, GLU_AUTO_LOAD_MATRIX, false);

  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);

  glutPassiveMotionFunc(mouseMove);

  glutTimerFunc(0, timer, 0);

  glutMainLoop();

  return 0;
}
