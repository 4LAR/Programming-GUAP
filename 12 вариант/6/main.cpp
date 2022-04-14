/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 12
    Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.
    Найти номер первой из строк, содержащих хотя бы один положительный элемент.

*/

#define RANDOM_NUMS false

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
#include "clear_arr.h"

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

  // очистка терминала
  //clear_scr();

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
  arr = read_double_arr(arr, size_x, size_y, RANDOM_NUMS);

  draw_line(20);
  draw_float_double_array(arr, size_x, size_y);
  draw_line(20);

  // Найти номер первой из строк, содержащих хотя бы один положительный элемент.
  get_index(arr, size_x, size_y);

  draw_line(20);

  // Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.

  int size_y_new_arr;
  // уплотняем по высоте
  arr = clear_height_double_arr(arr, size_x, size_y, &size_y_new_arr);

  int size_x_new_arr;
  // уплотняем по ширине
  arr = clear_width_double_arr(arr, size_x, size_y_new_arr, &size_x_new_arr);

  // выводим новый массив
  draw_float_double_array(arr, size_x_new_arr, size_y_new_arr);

  // очистка памяти
  for(y = 0; y < size_y; y++) {
      free(arr[y]);
  }
  free(arr);

	return 0;
}
