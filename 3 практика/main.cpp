#include <iostream>
using namespace std;

#include "libs/lib.h"

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

// кал для практики
#include "draw_els.h"
#include "menu.h"

int main() {
  system("chcp 65001");

  draw_line(20);

  triangle(10);

  draw_line(20);

  square(10, 10);

  draw_line(20);

  arrow(3, 6);

  return 0;
}
