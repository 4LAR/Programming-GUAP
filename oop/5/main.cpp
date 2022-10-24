/*
  19 вариант



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
	// смена кодировки
  system("chcp 65001");

  D3 d3();
  D3 d4();

  d3.show_d3();
  d4.show_d4();

	return 0;
}
