/*
  19 вариант -> 20 вариант (алмаз)



*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "libs/time.h"

#include "b_classes.h"
#include "d_classes.h"
#include "shows.h"


int main() {
  draw_line(60);
	// смена кодировки
  system("chcp 65001");

  D4 d4(100, 200, 300, 400, 500, 600, 700);
  d4.show_D4();

	return 0;
}
