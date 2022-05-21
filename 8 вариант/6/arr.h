#include <iostream>
#include <cmath>

using namespace std;

// Сумма элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент
double get_summ(double **arr, int size_x, int size_y) {
  double summ = 0;

  bool negative = false;
  for (int x = 0; x < size_x; x++) {
    negative = false;
    for (int y = 0; y < size_y; y++) {
      if (arr[y][x] < 0) {
        negative = true;
        break;
      }
    }
    if (negative) {
      for (int y = 0; y < size_y; y++) {
        summ += arr[y][x];
      }
    }

  }

  return summ;
}

// создание характиристики
double *get_info_arr(double **arr, int size_x, int size_y) {
  double *info = (double*)malloc(size_x * sizeof(double));
  for (int i = 0; i < size_x; i++) info[i] = 0;
  for (int x = 0; x < size_x; x++) {
    for (int y = 0; y < size_y; y++) {
      if ((arr[y][x] < 0) && ((int)arr[y][x] % 2 != 0)) {
        info[x] += abs(arr[y][x]);
      }
    }
  }

  return info;
}
