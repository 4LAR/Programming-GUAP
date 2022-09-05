#include <iostream>
#include <cmath>

using namespace std;

// старая версия прокрутки
double **rotate_old(double **arr, int size) {
  double **arr_out = (double**)malloc(size * sizeof(double*));
  for(int i = 0; i < size; i++) {
      arr_out[i] = (double*)malloc(size * sizeof(double));
  }

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      arr_out[size - 1 - i][size - 1 - j] = arr[i][size - 1 - j];
    }
  }

  return arr_out;
}

// вроде адекватная версия прокрутки
double **rotate(double **arr, int size, bool forward) {
  int b;
  for (int i = 0; i < size / 2; i++)
    for (int j = i; j < size - 1 - i; j++) {
      if (!forward) {
        b = arr[i][j];
        arr[i][j] = arr[j][size - 1 - i];
        arr[j][size - 1 - i] = arr[size - 1 - i][size - 1 - j];
        arr[size - 1 - i][size - 1 - j] = arr[size - 1 - j][i];
        arr[size - 1 - j][i] = b;
      } else {
        b = arr[i][j];
        arr[i][j] = arr[size - 1 - j][i];
        arr[size - 1 - j][i] = arr[size - 1 - i][size - 1 - j];
        arr[size - 1 - i][size - 1 - j] = arr[j][size - 1 - i];

        arr[j][size - 1 - i] = b;
      }

    }
    return arr;
}
