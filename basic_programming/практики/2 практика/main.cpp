#include <iostream>
#include <cmath>
#include <ctime>

#include "lib.h"
#include "zad_1.h"
#include "zad_2.h"

using namespace std;


int main() {
  srand(time(0));
  system("chcp 65001");

  zad_1();

  draw_line(20);
  zad_2();

  return 0;
}
