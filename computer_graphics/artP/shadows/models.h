
/*
  Здесь храянтся модели
*/

#include <iostream>
#include <GL/freeglut.h>

float mat_dif_grass[] = {0.0f, 1.0f, 0.8f, 1.0f};
float mat_spec_grass[] = {0.0f, 1.0f, 0.8f};
float mat_amb_grass[] = {0.0f, 1.0f, 0.8f};
float mat_shininess_grass = 0.1f * 128;

// отрисовка пола
void draw_floor() {
  glTranslatef(0, -1, 0);
  glScalef(50, 1, 50);

  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb_grass);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif_grass);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec_grass);
  glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess_grass);

  glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f,  1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f,  1.0f);
  glEnd();

  glTranslatef(0, 1, 0);
  glScalef(0.02, 1, 0.02);
}
