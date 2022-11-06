/*
  17 вариант



*/

#include <iostream>
using namespace std;

#include <cmath>

#include "b_classes.h"
#include "d_classes.h"
#include "shows.h"


int main() {
	// смена кодировки
  system("chcp 65001"); // setlocale(LC_ALL, "Russian");

  D3 d3(100, 200, 300, 400, 500, 600);
  d3.show_d3();

	return 0;
}
