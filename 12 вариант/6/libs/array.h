#include <iostream>
#include <cmath>

using namespace std;

void draw_float_array(double *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
  cout << endl;
}

void draw_float_double_array(double **arr, int size_x, int size_y) {
  for (int y = 0; y < size_y; y++) {
    for (int x = 0; x < size_x; x++) {
      cout << arr[y][x] << "\t";
    }
    cout << endl;
  }
}
