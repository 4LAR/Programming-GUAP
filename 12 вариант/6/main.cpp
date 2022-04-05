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
  clear_scr();

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

  // Найти номер первой из строк, содержащих хотя бы один положительный элемент.
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

  // Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.
  // уплотняем матрицу удаляя строки
  double **new_arr_y = (double**)malloc(sizeof(double*));
  int size_y_new_arr = 0;
  bool ok = false;
  for (y = 0; y < size_y; y++) {
    ok = false;
    for (x = 0; x < size_x; x++) {
      if (arr[y][x] != 0) {
        ok = true;
        break;
      }
    }
    if (ok) {
      new_arr_y = (double**) realloc(new_arr_y, (++size_y_new_arr) * sizeof(double*));
      new_arr_y[size_y_new_arr-1] = (double*)malloc(size_x * sizeof(double));

      for (int j = 0; j < size_x; j++) {
        new_arr_y[size_y_new_arr-1][j] = arr[y][j];
      }
    }
  }
  
  // для отладки
  //draw_float_double_array(new_arr_y, size_x, size_y_new_arr); 
  //draw_line(20);

  double **new_arr_x = (double**)malloc(size_y_new_arr * sizeof(double*));
  int size_x_new_arr = 0;
  for (x = 0; x < size_x; x++) {
    ok = false;
    for (y = 0; y < size_y_new_arr; y++) {
      if (new_arr_y[y][x] != 0) {
        ok = true;
      break;
      } 
    }
    if (ok) {
      size_x_new_arr++;
      for (int j = 0; j < size_y_new_arr; j++) {
        new_arr_x[j] = (double*) realloc(new_arr_x[j], (size_x_new_arr) * sizeof(double));
        new_arr_x[j][size_x_new_arr-1] = new_arr_y[j][x];
      }
    }
  }

  draw_float_double_array(new_arr_x, size_x_new_arr, size_y_new_arr);
  
  // очистка памяти
  for(y = 0; y < size_y; y++) {
      free(arr[y]);
  }
  free(arr);

  for(y = 0; y < size_y_new_arr; y++) {
      free(new_arr_y[y]);
  }
  free(new_arr_y);

  for(y = 0; y < size_y_new_arr; y++) {
      free(new_arr_x[y]);
  }
  free(new_arr_x);
  
	return 0;
}
