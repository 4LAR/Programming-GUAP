/*
  5 вариант

*/

#include <iostream>
using namespace std;

#include <cmath>

#include "b_classes.h"
#include "d_classes.h"

int main() {
	// смена кодировки
  system("chcp 65001"); // setlocale(LC_ALL, "Russian");

  D4 d4(1, 2, 3, 4, 5, 6);
  d4.show_D4();

	return 0;
}
