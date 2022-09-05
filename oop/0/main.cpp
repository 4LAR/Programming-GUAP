/*

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

#define size_x 5
#define size_y 2

void get_pos_min_arr(double **arr, int s_x, int s_y, int *r_x, int *r_y) {

  // min = {num, x, y}
  double min[3] = {arr[0][0], 0, 0};

  for (int y = 0; y < s_y; y++) {
    for (int x = 0; x < s_x; x++) {
      if (arr[y][x] < min[0]) {
        min[0] = arr[y][x];
        min[1] = x;
        min[2] = y;
      }
    }
  }
  
  (*r_x) = min[1];
  (*r_y) = min[2];

}

int main() {
	// смена кодировки
  system("chcp 65001");

  // создаем и вводим массив
  double **A = read_double_arr(create_arr(size_x, size_y), size_x, size_y, "A");
  draw_line(20);
  double **B = read_double_arr(create_arr(size_x, size_y), size_x, size_y, "B");
  draw_line(20);
  double **C = read_double_arr(create_arr(size_x, size_y), size_x, size_y, "C");
  draw_line(20);

  int x, y;

  // выводим массив
  cout << "A" << endl;
  draw_float_double_array(A, size_x, size_y);
  
  get_pos_min_arr(A, size_x, size_y, &x, &y);
  cout << "Минимальное число в массиве A расположно [" << y << ", " << x << "]" << endl;
  cout << "B" << endl;
  draw_float_double_array(B, size_x, size_y);
  get_pos_min_arr(B, size_x, size_y, &x, &y);
  cout << "Минимальное число в массиве B расположно [" << y << ", " << x << "]" << endl;

  cout << "C" << endl;
  draw_float_double_array(C, size_x, size_y);
  get_pos_min_arr(C, size_x, size_y, &x, &y);
  cout << "Минимальное число в массиве C расположно [" << y << ", " << x << "]" << endl;


	return 0;
}
