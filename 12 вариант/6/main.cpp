/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 12
    Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.
  Найти номер первой из строк, содержащих хотя бы один положительный элемент.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

// работа с массивами
#include "libs/array.h"

int read_size_arr(const char *promt = "") {
  int size;
  while (true) {
    size = read_value(promt, false, false, false);
    if (size > 0) {
      break;
    } else {
      cout << "Размер должен быть больше 1." << endl;
    }
  }
}

int main() {
	// смена кодировки
  system("chcp 65001");

  // ввод размеров массива
  int size_x = read_size_arr("Ширина массива: ");
  int size_y = read_size_arr("Высота массива: ");

  // создаём новый массив

  // уплотняем матрицу


  // строка с положительным элементом

	return 0;
}
