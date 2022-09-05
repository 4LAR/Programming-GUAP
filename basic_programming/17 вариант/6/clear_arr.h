#include <iostream>
#include <cmath>

using namespace std;

// функция для перестановки элементов (тут работает какя-то странная магия)
double **replace_diag(double **arr, int size) {
  int iteration;
  int max, max_i, max_j, i, j;

  for (iteration = 0; iteration < size; iteration++) {
    max_i = 0;
    max_j = 1;
    for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
        if (!(i == j && i < iteration)){
          if (arr[i][j] > arr[max_i][max_j]) {
            max_i = i;
            max_j = j;
          }
        }
      }
    }

    max = arr[max_i][max_j];
    arr[max_i][max_j] = arr[iteration][iteration];
    arr[iteration][iteration] = max;

  }
  return arr;

}

// функция для нахождения строки состоящей из отрицательных элементов
int get_row(double **arr, int size) {
  bool state;
  for (int y = 0; y < size; y++) {
    state = true;
    for (int x = 0; x < size; x++) {
      if (arr[y][x] > 0) {
        state = false;
        break;
      }
    }
    if (state) return y;
  }
  return -1;
}
