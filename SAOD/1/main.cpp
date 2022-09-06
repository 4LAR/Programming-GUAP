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

// заполнение массива
int* generate_arr(int* arr, int size, int rand_min, int rand_max) {
  for (int i = 0; i < size; i++) {
    arr[i] = random_int(rand_min, rand_max);
  }

  return arr;
}

int main() {
	// смена кодировки
  system("chcp 65001");

  // сид для рандома
  srand(time(NULL));

  int size = 0;

  // ввод размера массива
  while (true) {
    size = read_value("Размер массива: ", true, true, false);

    if (size > 0)
      break;

    else
      cout << "Размер массива должен быть больше 0." << endl;
  }

  draw_line(20);

  // создаём массив
  int* arr = (int*)malloc(size * sizeof(int));

  // диапазон чисел для заполнения через рандом
  int rand_min = - ((size / 2) - 1);
  int rand_max = size / 2;

  // заполняем
  arr = generate_arr(arr, size, rand_min, rand_max);

  int num;
  bool run = true;

  int sum;
  int count;

  // цикл для меню
  while (run) {
    if (num != 2 && num != 3)
      clear_scr();

    // вывод меню и информации о массиве
    cout << "Числа сгенерированны в диапазоне от " << rand_min << " до " << rand_max << endl;
    cout << "Массив: ";
    draw_int_array(arr, size, " ");
    draw_line(40);
    cout << "1 - Перегенерировать массив." << endl;
    cout << "2 - Подсчитать сумму всех элементов, имеющих положительные значения." << endl;
    cout << "3 - Подсчитать количество элементов с положительными значениями." << endl << endl;
    cout << "0 - Выход" << endl;
    draw_line(40);

    // ввод пункта меню
    num = read_value(" >> ", true, true, false);

    switch (num) {
      // Перегенерировать массив
      case (1):
        arr = generate_arr(arr, size, rand_min, rand_max);
        break;

      // Подсчитать сумму всех элементов, имеющих положительные значения
      case (2):
        clear_scr();
        sum = get_sum_pos(arr, size);
        if (sum > 0) {
          cout << "Сумма положительных элементов: " << sum << endl;
        } else 
          cout << "В массиве нет положительных элементов." << endl;
        draw_line(40);
        break;

      // Подсчитать количество элементов с положительными значениями.
      case (3):
        clear_scr();
        count = get_count_pos(arr, size);
        if (sum > 0) {
          cout << "Количество положительных элементов: " << count << endl;
        } else 
          cout << "В массиве нет положительных элементов." << endl;
        draw_line(40);
        break;

      // выход
      case (0):
        run = false;
        break;
    }
  }

  clear_scr();
  free(arr);
	return 0;
}
