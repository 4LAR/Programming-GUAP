/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 17
    -Путѐм перестановки элементов квадратной вещественной матрицы добиться того, чтобы еѐ
    максимальный элемент находился в левом верхнем углу, следующий по величине – в позиции
    (2,2), следующий по величине – в позиции (3,3) и т.д., заполнить, таким образом, всю главную
    диагональ.
    -Найти номер первой их строк, не содержащих ни одного положительного элемента.
*/

#define RANDOM_NUMS false

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// работа с массивами
#include "libs/array.h"
#include "clear_arr.h"

// функция для ввода размера матрицы (с проверкой)
int read_size_arr(const char *promt = "") {
  int size;
  while (true) {
    cout << promt;
    size = read_int();
    if (size > 0) {
      break;
    } else {
      cout << "Размер должен быть больше 0." << endl;
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
  int size;

  // ввод размера массива
  size = read_size_arr("Размер квадратной матрицы: ");

  // создаём новый массив
  double **arr = (double**)malloc(size * sizeof(double*));
  for(int i = 0; i < size; i++) {
      arr[i] = (double*)malloc(size * sizeof(double));
  }

  // ввод значений массива
  arr = read_double_arr(arr, size, size, RANDOM_NUMS);

  // выводим массив
  draw_line(20);
  draw_float_double_array(arr, size, size);
  draw_line(20);

  // нахождение строки состоящией из отрицательных элементов
  int row = get_row(arr, size);
  if (row == -1)
    cout << "В массиве нет строк которые бы состояли только из отрицательных чисел." << endl;
  else
    cout << "Номер первой из строк, не содержащий ни одного положительного элемента: " << (row + 1) << endl;

  // переставляем элементы
  arr = replace_diag(arr, size);

  // выводим новый массив
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
