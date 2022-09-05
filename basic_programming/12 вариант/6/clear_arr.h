#include <iostream>
#include <cmath>

using namespace std;

double **clear_height_double_arr(double **arr, int size_x, int size_y, int *new_size_y) {

  int x, y;

  double **new_arr_y = (double**)malloc(sizeof(double*));
  (*new_size_y) = 0;
  bool ok = false;
  for (y = 0; y < size_y; y++) {
    ok = false;
    for (x = 0; x < size_x; x++) {
      if (arr[y][x] != 0) {
        ok = true;
        break;
      }
    }
    if (ok) {
      new_arr_y = (double**) realloc(new_arr_y, (++(*new_size_y)) * sizeof(double*));
      new_arr_y[(*new_size_y)-1] = (double*)malloc(size_x * sizeof(double));

      for (int j = 0; j < size_x; j++) {
        new_arr_y[(*new_size_y)-1][j] = arr[y][j];
      }
    }
  }

  return new_arr_y;

}

double **clear_width_double_arr(double **arr, int size_x, int size_y, int *new_size_x) {

  int x, y;

  bool ok;
  double **new_arr_x = (double**)malloc(size_y * sizeof(double*));
  (*new_size_x) = 0;
  for (x = 0; x < size_x; x++) {
    ok = false;
    for (y = 0; y < size_y; y++) {
      if (arr[y][x] != 0) {
        ok = true;
        break;
      }
    }
    if (ok) {
      (*new_size_x)++;
      for (int j = 0; j < size_y; j++) {
        new_arr_x[j] = (double*) realloc(new_arr_x[j], ((*new_size_x)) * sizeof(double));
        new_arr_x[j][(*new_size_x)-1] = arr[j][x];
      }
    }
  }

  return new_arr_x;
}
