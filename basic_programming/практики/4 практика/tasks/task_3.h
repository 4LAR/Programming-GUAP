#include <iostream>
using namespace std;

void piramid(int width) {
  draw_line(width, "*");
  if (width > 1) piramid(width - 1);
}

void rhombus(int height) {
  
}
