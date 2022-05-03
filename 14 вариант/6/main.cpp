/*
  Вариант 14
    Осуществить циклический сдвиг элементов квадратной матрицы размерности N на N
    вправо на k элементов таким образом: элементов 1-й строки сдвигаются в последний столбец
    сверху вниз, из него – в последнюю строку справа налево, из неѐ – в первый столбец снизу верх, из
    него – в первую строку; для остальных элементов аналогично.
*/

#define RANDOM_NUMS false

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// работа с массивами
#include "libs/array.h"
#include "rotate.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // очистка терминала
  //clear_scr();

  // рандом
  srand(time(NULL));

  int x, y, b;
  int size;

  // ввод размеров массива
  while (true) {
    cout << "Введите размер массива (N): ";
    size = read_int();

    if (size < 1) {
      cout << "Массив не может содержать 0 элементов." << endl;
    } else break;
  }

  // создаём новый массив
  double **arr = (double**)malloc(size * sizeof(double*));
  for(int i = 0; i < size; i++) {
      arr[i] = (double*)malloc(size * sizeof(double));
  }

  // ввод значений массива
  arr = read_double_arr(arr, size, size, RANDOM_NUMS);

  draw_line(20);
  draw_float_double_array(arr, size, size);
  draw_line(20);

  cout << "Сколько раз провернуть массив: ";
  int rotate_count = read_int();

  // вот это поворот
  for (int i = 0; i < abs(rotate_count); i++) {
    arr = rotate(arr, size, (rotate_count > 0));
  }

  draw_line(20);
  draw_float_double_array(arr, size, size);
  draw_line(20);

  // очистка памяти
  for(y = 0; y < size; y++) {
    free(arr[y]);
  }
  free(arr);

	return 0;
}
