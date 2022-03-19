/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой.

  Вариант 12
    В одномерном массиве, состоящем из n вещественных элементов, вычислить:
    1. номер максимального по модулю элемента массива;
    2. сумму модулей элементов массива, расположенных после первого положительного
    элемента.
  Преобразовать массив таким образом, чтобы сначала располагались все элементы, целая
  часть которых лежит в интервале 𝑎, 𝑏 , а потом – все остальные.

*/

#include <iostream>
#include <cmath>
#include "lib.h"
#define size 10
//const int size = 10;

using namespace std;

int main() {
	// смена кодировки
  system("chcp 65001");

  float arr[size];

  draw_line(20);

  // ввод элементов массива
  for (int i = 0; i < size; i++){
    cout << "array [" << i << "] = ";
    scanf("%f", &arr[i]);
  }

  draw_line(20);

  // выводим массив
  draw_float_array(arr, size);

  draw_line(20);

  // Номер максимального по модулю элемента массива
  int max_id = 0;
  for (int i = 1; i < size; i++) {
    if (fabs(arr[i]) > fabs(arr[max_id]))
      max_id = i;
  }

  cout << "Номер максимального по модулю элемента массива: " << max_id << endl;

  // Сумма модулей после позитивного элемента
  bool positive = false;
  float summ = 0;
  for (int i = 0; i < size; i++) {
    if (!positive && arr[i] > 0) {
      positive = true;
    } else if (positive){
      summ += fabs(arr[i]);
    }
  }

  if (!positive)
    cout << "В массиве нет положительных элементов массива\n";
  else
    cout << "Сумма элементов массива после 1 положительного элемента: " << summ << endl;

  draw_line(20);

  //
  int a, b;

  cout << "Введите диапазон [a, b]\n";

  cout << "A = ";
  scanf("%d", &a);

  cout << "B = ";
  scanf("%d", &b);

  for (int i = a; i < b + 1; i++){
    cout << arr[i] << "\t";
  }

  for (int i = 0; i < size; i++) {
    if (i < a || i > b)
      cout << arr[i] << "\t";
  }
  cout << endl;

  draw_line(20);

	return 0;
}
