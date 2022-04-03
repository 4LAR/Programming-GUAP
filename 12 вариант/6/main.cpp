/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 12
    Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.
  Найти номер первой из строк, содержащих хотя бы один положительный элемент.

*/

#define RANDOM_NUMS true

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

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

  // рандом
  srand(time(NULL));

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
      if (RANDOM_NUMS) {
        arr[y][x] = random_int(-10, 10);
      } else {
        cout << "Array[" << y << "][" << x << "] = ";
        arr[y][x] = read_value("", true, true, false);
      }
    }

  draw_line(20);
  draw_float_double_array(arr, size_x, size_y);
  draw_line(20);

  // строка с положительным элементом
  bool find = false;
  for (y = 0; y < size_y; y++) {
    for (x = 0; x < size_x; x++) {
      if (arr[y][x] > 0) {
        cout << "Индекс первой строки содержащей положительный элемент: " << y << endl;
        find = true;
        break;
      }
    }
    if (find) break;
  }

  if (!find) {
    cout << "Строк с положительными элементами не существует." << endl;
  }

  draw_line(20);

  // уплотняем матрицу


  // очистка памяти
  for(y = 0; y < size_y; y++) {
      free(arr[y]);
  }
  free(arr);

	return 0;
}
