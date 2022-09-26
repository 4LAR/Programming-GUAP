/*
  1 вариант (20 mod 10) + 1

    Разработать класс «Прямоугольник». Определить в нем конструкторы и деструктор,
  перегрузить операцию пересечения прямоугольников (операция “*”), операцию
  вычисления площади прямоугольника, операции сравнения (по площади).

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "rectangle.h"

int main() {
	// смена кодировки
  system("chcp 65001");
  draw_line();

  //Rectangle rectangle_1;
  Rectangle rectangle_1(0, 0, 3, 3);
  Rectangle rectangle_2(4, 1, 4, 3);

  cout << "Площадь 1 прямоугольника: " << rectangle_1.get_area() << endl;
  cout << "Площадь 2 прямоугольника: " << rectangle_2.get_area() << endl;

  //cout << rectangle_1.get_area() << endl;

  // сравнение
  cout << (rectangle_1 > rectangle_2) << endl;
  cout << (rectangle_2 > rectangle_1) << endl;
  cout << (rectangle_2 == rectangle_1) << endl;

  // пересечение
  draw_line();
  cout << (rectangle_1 * rectangle_2) << endl;

	return 0;
}
