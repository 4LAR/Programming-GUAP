/*
  2 вариант ( (26 % 25) + 1 )

    Используя память, пропорциональную n, хранить массив целых чисел
  A, содержащий n элементов.
    Элементы массива A могут принимать случайные значения от
  -((n div 2) - 1) до (n div 2). То есть, если в массиве хранится 10 элементов, то
  эти элементы должны быть в диапазоне от -4 до 5.
    Разработать алгоритм, который осуществляет заполнение массива A
  случайными значениями, и по выбору пользователя выполняет одну из двух
  функций.

  - Подсчитать сумму всех элементов, имеющих положительные значения
  - Подсчитать количество элементов с положительными значениями

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"
#include "libs/array.h"

#include "functions.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  int size = 0;
  while (true) {
    size = read_value("Размер массива: ", true, true, false);

    if (size > 0)
      break;

    else
      cout << "Размер массива должен быть больше 0." << endl;
  }

  draw_line(20);

  int* arr = (int*)malloc(size * sizeof(int));

  int rand_min = - ((size / 2) - 1);
  int rand_max = size / 2;

  cout << "Числа генерируются в диапазоне от " << rand_min << " до " << rand_max << endl;

  for (int i = 0; i < size; i++) {
    arr[i] = random_int(rand_min, rand_max);
  }

  draw_int_array(arr, size);

  

	return 0;
}
