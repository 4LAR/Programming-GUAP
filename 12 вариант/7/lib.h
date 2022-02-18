#include <iostream>

using namespace std;

// функция рисующая полосу для разделения
void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}

void draw_float_array(float *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
  cout << endl;
}
