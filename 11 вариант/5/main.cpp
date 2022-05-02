/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой.

  Вариант 11
    В одномерном массиве, состоящем из n вещественных элементов, вычислить:
    1. номер минимального по модулю элемента массива;
    2. сумму модулей элементов массива, расположенных после первого отрицательного
    элемента.
  Сжать массив, удалив из него все элементы, величина которых находится в интервале
   𝑎, 𝑏 . Освободившиеся в конце массива элементы заполнить нулями.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

int main() {
	// смена кодировки
  system("chcp 65001");

  draw_line(20);

  // ввод элементов массива
  int size;
  while (true) {
    cout << "Введите размер массива: ";
    size = read_int();

    if (size > 1) {
      break;
    } else {
      cout << "Массив в данном задании не может быть меньше 2 элементов." << endl;
    }
  }

  double *arr = (double*) malloc(size * sizeof(double));

  for (int i = 0; i < size; i++){
    cout << "array [" << i << "] = ";
    arr[i] = read_int();
  }

  draw_line(20);

  // выводим массив
  draw_float_array(arr, size);

  draw_line(20);

  // Номер минимального по модулю элемента массива
  int min_id = 0;
  for (int i = 1; i < size; i++) {
    if (fabs(arr[i]) < fabs(arr[min_id]))
      min_id = i;
  }

  cout << "Номер(индекс) минимального по модулю элемента массива: " << min_id << endl;

  // Сумма модулей после позитивного элемента
  bool negative = false;
  float summ = 0;
  for (int i = 0; i < size; i++) {
    if (!negative && arr[i] < 0) {
      negative = true;
    } else if (negative){
      summ += fabs(arr[i]);
    }
  }

  if (!negative)
    cout << "В массиве нет отрицательныйх элементов массива\n";
  else
    cout << "Сумма модулей элементов массива после 1 отрицательного элемента: " << summ << endl;

  draw_line(20);

  // ввод диапазона
  int a, b, k;
  cout << "Введите диапазон [a, b]\n";
  while (true) {
    cout << "A = ";
    a = read_int();
    cout << "B = ";
    b = read_int();

    // меняем местами числа, если пользователь их перепутал
    if (a > b) {
      k = a;
      a = b;
      b = k;
    }

    // если числа одинаковые, то вводим заново
    if (a == b) {
      cout << "A и B не могут быть одинаковыми." << endl;
      draw_line(20);

    } else {
      // если всё ок выходим из цикла
      break;
    }

  }

  // пересобираем массив
  double *new_arr = (double*) malloc(size * sizeof(double));
  int j = 0;
  for (int i = 0; i < size; i++) {
    if (!((arr[i] >= a) && (arr[i] <= b))) {
      new_arr[j++] = arr[i];
    }
  }

  for (int i = j; i < size; i++) {
    new_arr[i] = 0;
  }

  // выводим новый массив
  draw_line(20);
  draw_float_array(new_arr, size);
  draw_line(20);

  // удаление массивов
  free(arr);
  free(new_arr);

	return 0;
}
