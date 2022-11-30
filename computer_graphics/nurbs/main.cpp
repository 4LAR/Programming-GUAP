#include <iostream>
#include <cmath>

#include <GL/freeglut.h>

#define W_WIDTH 1280
#define W_HEIGHT 720

// camera

// угол поворота камеры
double angle_x=0.0;
double angle_y=-5000.0;
// координаты вектора направления движения камеры
float lx=0.0f, ly=0.0f, lz=-1.0f;
// XZ позиция камеры
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
GLfloat ambientColor1[] = { 0.2, 0.2, 0.2, 1.0 };
GLfloat diffuseColor1[] = { 0, 1, 0, 0.6 };
GLfloat emis1[] = { 0.1, 0.1, 0.1, 0.1 };

GLfloat light_position[4] = {1.0, 1.0, 1.0, 1.0};

float mat_dif_light[] = {0.0f, 0.0f, 0.0f, 1.0};

// model

static float vertices[] = {
  1.0f, 1.0f, -1.0f,
  -1.0f, 1.0f, -1.0f,
  -1.0f, 1.0f,  1.0f,
  1.0f, 1.0f,  1.0f,

  1.0f, -1.0f,  1.0f,
  -1.0f, -1.0f,  1.0f,
  -1.0f, -1.0f, -1.0f,
  1.0f, -1.0f, -1.0f,

  1.0f,  1.0f, 1.0f,
  -1.0f,  1.0f, 1.0f,
  -1.0f, -1.0f, 1.0f,
  1.0f, -1.0f, 1.0f,

  1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f,  1.0f, -1.0f,
  1.0f,  1.0f, -1.0f,

  -1.0f,  1.0f,  1.0f,
  -1.0f,  1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
  -1.0f, -1.0f,  1.0f,

  1.0f,  1.0f, -1.0f,
  1.0f,  1.0f,  1.0f,
  1.0f, -1.0f,  1.0f,
  1.0f, -1.0f, -1.0f

};

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
    int m = 2; // 2
    for (u = 0; u < size_numb_y; u++) {
        for (v = 0; v < size_numb_x; v++) {
            ctlpoints[u][v][0] = m * ((GLfloat)u - 1.5);
            ctlpoints[u][v][1] = m * ((GLfloat)v - 1.5);

            if ((u == 1 || u == 2) && (v == 1 || v == 2))
                ctlpoints[u][v][2] = 1.0;
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

  glTranslatef(0.0f, 0.0f, 0.0f);

  glRotatef(-90.0, 1.0, 0.0, 0.0);
  gluBeginSurface(theNurb);

  gluNurbsSurface(theNurb,
      size_numb_x + size_numb_y, knots, size_numb_x + size_numb_y, knots,
      size_numb_x * 3, 3, &ctlpoints[0][0][0],
      size_numb_x, size_numb_y, GL_MAP2_VERTEX_3);

  gluEndSurface(theNurb);

  glEnableClientState(GL_VERTEX_ARRAY);
  for (int i = 1; i < 4; i++) {
    glTranslatef(0.0f, 0.0f, i + 2);
    glScalef(i, i, i);

    glVertexPointer(3, GL_FLOAT, 0, &vertices);
    // glDrawArrays(GL_QUADS, 0, sizeof(vertices) / sizeof(float));
    glDrawArrays(GL_QUADS, 0, 24);
  }
  glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();

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
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowPosition(150, 50);
  glutInitWindowSize(W_WIDTH, W_HEIGHT);
  glutCreateWindow("nurbs");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

  init();

  init_surface();

  GLfloat mat_diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 100.0 };

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);

  theNurb = gluNewNurbsRenderer();
  gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
  gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);

  glutKeyboardFunc(keyDown);
  glutKeyboardUpFunc(keyUp);

  glutPassiveMotionFunc(mouseMove);

  glutTimerFunc(0, timer, 0);

  glutMainLoop();

  return 0;
}
