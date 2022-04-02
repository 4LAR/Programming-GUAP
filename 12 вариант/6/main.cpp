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
  return size;
}

int main() {
	// смена кодировки
  system("chcp 65001");

  int x, y;
  int size_x, size_y;
  // ввод размеров массива
  while (true) {
    size_x = read_size_arr("Ширина массива: ");
    size_y = read_size_arr("Высота массива: ");

    if (size_x < 1 || size_y < 0) {
      cout << "Массив не может содержать 0 элементов." << endl;
    } else break;
  }
  
  // создаём новый массив
  double **arr = (double**)malloc(size_y * sizeof(double*));
  for(int i = 0; i < size_y; i++) {
      arr[i] = (double*)malloc(size_x * sizeof(double));
  }

  // ввод значений массива
  for (y = 0; y < size_y; y++)
    for (x = 0; x < size_x; x++) {
      //cout << "Array[" << y << "][" << x << "] = ";
      //arr[y][x] = read_value("", true, true, false);
      arr[y][x] = random_int(-10, 10);
    }
      
  draw_float_double_array(arr, size_x, size_y);
  // уплотняем матрицу


  // строка с положительным элементом

	return 0;
}
