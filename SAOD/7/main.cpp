/*
  3 вариант (26 % 24 + 1)

  Список ребер

    Прямоугольное изображение задано графом, так что каждая вершина
  является пикселем изображения, ребра соединяют соседние пиксели по
  горизонтали и вертикали. Требуется:

    1) проверить соответствует ли описанный граф изображению (нет
  пропущенных пикселей);

    2) Найти и «закрасить» замкнутые контура на изображении.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <iomanip>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "list_ribs.h"

int main() {
  // смена кодировки
  system("chcp 65001");

  List_ribs list_ribs(10, 10);
  list_ribs.link(0, 0, 0, 1);
  list_ribs.link(0, 1, 0, 2);
  list_ribs.link(0, 2, 0, 3);
  list_ribs.link(0, 3, 1, 3);

  list_ribs.link(1, 3, 1, 2);
  list_ribs.link(1, 2, 1, 1);
  list_ribs.link(1, 1, 1, 0);
  list_ribs.link(1, 0, 0, 0);

  list_ribs.link(5, 5, 5, 6);
  list_ribs.link(5, 6, 5, 7);

  // List_ribs list_ribs(4, 4);
  // list_ribs.link(0, 0, 0, 1);
  // list_ribs.link(0, 1, 0, 2);
  // list_ribs.link(0, 2, 0, 3);
  // list_ribs.link(0, 3, 1, 3);
  // list_ribs.link(1, 3, 2, 3);
  // list_ribs.link(2, 3, 3, 3);
  // list_ribs.link(3, 3, 3, 2);
  // list_ribs.link(3, 2, 3, 1);
  // list_ribs.link(3, 1, 3, 0);
  // list_ribs.link(3, 0, 2, 0);
  // list_ribs.link(2, 0, 1, 0);
  // list_ribs.link(1, 0, 0, 0);
  //
  // list_ribs.link(1, 1, 1, 2);
  // list_ribs.link(2, 1, 2, 2);


  list_ribs.show_list();
  if (list_ribs.check()) {
    cout << "Граф соответсвует изображению (нет пропущенных пикселей)" << endl;
  } else {
    cout << "Граф не соответсвует изображению (есть пропущенные пиксели)" << endl;
  }
  list_ribs.show_image();

  return 0;
}
