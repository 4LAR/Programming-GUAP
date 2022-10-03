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

  double x, y, width, height;

  x = read_value("1 Прямоугольник (X): ", true, true, false);
  y = read_value("1 Прямоугольник (Y): ", true, true, false);
  width = read_value("1 Прямоугольник (Width): ", true, true, false);
  height = read_value("1 Прямоугольник (Height): ", true, true, false);

  Rectangle rectangle_1(x, y, width, height);

  x = read_value("2 Прямоугольник (X): ", true, true, false);
  y = read_value("2 Прямоугольник (Y): ", true, true, false);
  width = read_value("2 Прямоугольник (Width): ", true, true, false);
  height = read_value("2 Прямоугольник (Height): ", true, true, false);

  Rectangle rectangle_2(x, y, width, height);

  draw_line();
  cout << "Площадь 1 прямоугольника: " << rectangle_1.get_area() << endl;
  cout << "Площадь 2 прямоугольника: " << rectangle_2.get_area() << endl;

  //cout << rectangle_1.get_area() << endl;

  // сравнение
  draw_line();
  cout << "(rectangle_1 > rectangle_2)" << endl;
  if (rectangle_1 > rectangle_2)
    cout << "1 прямоугольник больше чем 2." << endl;
  else
    cout << "2 прямоугольник больше чем 1." << endl;

  draw_line();
  cout << "(rectangle_1 < rectangle_2)" << endl;
  if (rectangle_1 > rectangle_2)
    cout << "2 прямоугольник меньше чем 1." << endl;
  else
    cout << "1 прямоугольник меньше чем 2." << endl;

  draw_line();
  cout << "(rectangle_2 == rectangle_1)" << endl;
  if (rectangle_2 == rectangle_1)
    cout << "1 и 2 прямоугольники равны по площади." << endl;
  else
    cout << "1 и 2 прямоугольники не равны по площади." << endl;

  // пересечение
  draw_line();
  cout << "(rectangle_1 * rectangle_2)" << endl;
  if (rectangle_1 * rectangle_2)
    cout << "1 и 2 прямоугольники пересекаются" << endl;
  else
    cout << "1 и 2 прямоугольники не пересекаются" << endl;

  draw_line();

	return 0;
}
