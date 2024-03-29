/*
  6 вариант

  Создать класс Массив, содержащий:
  - одномерный целочисленный массив
  - размерность массива определяется суммой двух последних цифр шифра студента (если
    сумма получается меньше 12, то размерность массива будет равна 12)
  - поле, для хранения длины массива
  - конструктор, в котором осуществляется ввод данных в массив
  - расчетные функции (согласно варианта)
  - функцию вывода исходного массива
  - задействовать механизм обработки исключительных ситуаций (не менее 2-3 ситуаций)
  - одну из ситуаций обработать с использованием собственного класса исключений
    (класс исключений не должен быть пустым!!!)

  В одномерном массиве, состоящем из n вещественных элементов, вычислить:
    • минимальный элемент массива;
    • сумму элементов массива, расположенных между первым и последним положительными
    элементами.
  Преобразовать массив таким образом, чтобы сначала располагались все элементы, равные
  нулю, а потом — все остальные.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "libs/array.h"

#include "exception.h"
#include "array.h"

int main() {
  draw_line(60);
	// смена кодировки
  system("chcp 65001");

  // размер массива (2 + 6)
  Array array(8);
  array.show();

  try {
    cout << "Минимальный элемент массива: " << array.get_arr()[array.get_min()] << endl;

  } catch (MyException &ex) {
    // cout << "Мы поймали " << ex.what() <<endl;
  }

  cout << "Сумма между первым положительным и последним: " << array.get_sum() << endl;

  array.my_sort();
  array.show();

	return 0;
}
