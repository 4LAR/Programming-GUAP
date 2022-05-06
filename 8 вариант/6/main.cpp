/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 8
    Характеристикой столбца целочисленной матрицы назовѐм сумму модулей его
    отрицательных нечѐтных элементов. Переставляя столбцы заданной матрицы, расположить их в
    соответствии с ростом характеристик.
  Найти сумму элементов в тех столбцах, которые содержат хотя бы один отрицательный
  элемент.

*/

#define RANDOM_NUMS false

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// работа с массивами
#include "libs/array.h"
#include "arr.h"

int read_size_arr(const char *promt = "") {
  int size;
  while (true) {
    cout << promt;
    size = read_int();
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
    cout << "Ширина массива: ";
    size_x = read_size_arr();
    cout << "Высота массива: ";
    size_y = read_size_arr();

    if (size_x < 1 || size_y < 1) {
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
  cout << "Сумма элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент: " << get_summ(arr, size_x, size_y) << endl;

  // получение характеристики
  double *info = get_info_arr(arr, size_x, size_y);

  // вывод массива и иформации о нём
  draw_float_array(info, size_x);
  draw_line(20);
  draw_float_double_array(arr, size_x, size_y);
  draw_line(20);

  double temp;

  // Сортировка массива пузырьком
  for (int i = 0; i < size_x - 1; i++) {
    for (int j = 0; j < size_x - i - 1; j++) {
      if (info[j] > info[j + 1]) {
        // меняем элементы местами
        temp = info[j];
        info[j] = info[j + 1];
        info[j + 1] = temp;

        // меняем столбцы местами
        for (int y = 0; y < size_y; y++) {
          temp = arr[y][j];
          arr[y][j] = arr[y][j + 1];
          arr[y][j + 1] = temp;
        }
      }
    }
  }

  draw_line(20);
  draw_float_array(info, size_x);
  draw_line(20);
  draw_float_double_array(arr, size_x, size_y);
  draw_line(20);

  // очистка памяти
  for(y = 0; y < size_y; y++) {
      free(arr[y]);
  }
  free(arr);
  free(info);

	return 0;
}
