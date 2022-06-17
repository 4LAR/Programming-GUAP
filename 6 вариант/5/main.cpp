/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой.

  Вариант 17
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

// функции для лабы (get_count_positive_els, sum_els_from_last_zero, get_new_arr)
#include "functions.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  // рисование линий в консоли (--------------------------)
  draw_line(20);

  // ввод размера массива с проверкой
  int size;
  while (true) {
    cout << "Введите размер массива: ";
    size = read_int();

    if (size > 0) {
      break;
    } else {
      cout << "Массив не может содержать 0 элементов." << endl;
    }
  }

  // создаём массив
  double *arr = (double*) malloc(size * sizeof(double));

  // вводим массив
  for (int i = 0; i < size; i++){
    cout << "array [" << i << "] = ";
    arr[i] = read_double();
  }

  draw_line(20);
  draw_float_array(arr, size); // выводим массив
  draw_line(20);

  // нахождение минимального элемента
  int min_el_id = get_min_el(arr, size);
  cout << "Минимальный элемент массива: " << arr[min_el_id] << endl;
  cout << "Индификатор минимального элемена массива: " << min_el_id << endl;

  draw_line(20);

  // получаем индификаторы первого и полижительного элемента
  int first_id = get_positive_el(arr, size);
  int last_id = get_positive_el(arr, size, true);

  int summ = 0;

  // условия для проверка (между числами должны находится ещё числа)
  if (first_id != -1 && last_id != -1) {
    if (first_id != last_id &&  first_id + 1 != last_id) {
      for (int i = first_id; i < last_id; i++) {
        summ += arr[i];
      }
      cout << "Сумма элементов массива между первым и последним элементами массива: " << summ << endl;
    } else {
      cout << "Между первым и последним элементом массива нет чисел." << endl;
    }
  } else {
    cout << "В массиве нет двух положительных элементов." << endl;
  }

  // получаем сортированный массив
  double *new_arr = sort(arr, size);
  draw_line(20);
  draw_float_array(new_arr, size); // выводим массив
  draw_line(20);

  // удаление массивов
  free(arr);
  free(new_arr);

	return 0;
}
