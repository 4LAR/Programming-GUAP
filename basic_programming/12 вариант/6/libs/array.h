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

// Найти номер первой из строк, содержащих хотя бы один положительный элемент.
int get_index(double **arr, int size_x, int size_y) {
  int x, y;
  bool find = false;
  for (y = 0; y < size_y; y++) {
    for (x = 0; x < size_x; x++) {
      if (arr[y][x] > 0) {
        cout << "Индекс первой строки содержащей положительный элемент: " << y << endl;
        find = true;
        break;
      }
    }
    if (find) break;
  }

  if (!find) {
    cout << "Строк с положительными элементами не существует." << endl;
    return -1;
  } else {
    return y;
  }
}

double **read_double_arr(double **arr, int size_x, int size_y, bool random = false) {
  int x, y;

  for (y = 0; y < size_y; y++)
    for (x = 0; x < size_x; x++) {
      if (random) {
        arr[y][x] = random_int(-10, 10);
      } else {
        cout << "Array[" << y << "][" << x << "] = ";
        arr[y][x] = read_value("", true, true, false);
      }
    }

    return arr;
}
