/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой.

  Вариант 12
    В одномерном массиве, состоящем из n целых элементов, вычислить:
      1. количество положительных элементов массива;
      2. сумму элементов массива, расположенных после последнего элемента, равного 0.
    Преобразовать массив таким образом, чтобы сначала располагались все элементы, целая
    часть которых не превышает 1, а потом – все остальные.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

#include "functions.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  draw_line(20);

  // ввод элементов массива
  int size;
  while (true) {
    cout << "Введите размер массива: ";
    size = read_int();

    if (size > 0) {
      break;
    } else {
      cout << "Массив в данном задании не может быть меньше 1 элемента." << endl;
    }
  }

  double *arr = (double*) malloc(size * sizeof(double));

  for (int i = 0; i < size; i++){
    cout << "array [" << i << "] = ";
    arr[i] = read_double();
  }

  draw_line(20);
  draw_float_array(arr, size); // выводим массив
  draw_line(20);

  int count_positive_els = get_count_positive_els(arr, size);
  if (count_positive_els > 0) 
    cout << "Положительных элементов в массиве: " << count_positive_els << endl;
  else
    cout << "В массиве нет положительных элементов." << endl; 

  int summ = sum_els_from_last_zero(arr, size);
  if (summ > -1) 
    cout << "Сумма элементов массива, расположенных после последнего элемента, равного 0: " << summ << endl;
  else
    cout << "В массиве нет элементов равных 0." << endl; 

  // удаление массивов
  delete(arr);

	return 0;
}
