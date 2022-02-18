/*
  Задания на лабораторную работу приводятся в каждом варианте. При написании программ
  можно использовать как динамические, так и нединамические массивы. Размерность последних
  задаѐтся именованной константой

  Вариант 12
    Уплотнить заданную матрицу, удаляя из неѐ строки и столбцы, заполненные нулями.
  Найти номер первой из строк, содержащих хотя бы один положительный элемент.

*/

#include <iostream>
#include <cmath>
#include "lib.h"

const int size_x = 3;
const int size_y = 3;

using namespace std;

// функция вывода массива
void read_arr(double arr[size_y][size_x]) {
  for (int y = 0; y < size_y; y++){
    for (int x = 0; x < size_x; x++){
      cout << "arr [" << y << "][" << x << "] = ";
      scanf("%lf", &arr[y][x]);
    }
  }
}

// функция вывода массива
void draw_array(double arr[size_y][size_x]) {
  for (int y = 0; y < size_y; y++){
    for (int x = 0; x < size_x; x++){
      cout << arr[y][x] << "\t";
    }
    cout << endl;
  }
}

int main() {
	// смена кодировки
  system("chcp 65001");

  draw_line(20);

  double arr[size_y][size_x];

  read_arr(arr); // вводим элементы массива
  draw_line(20);
  draw_array(arr); // выводим массив
  draw_line(20);

  // уплотняем матрицу


  // строка с положительным элементом

	return 0;
}
