#include <iostream>
#include <cmath>

// Подсчитать сумму всех элементов, имеющих положительные значения
int get_sum_pos(int* arr, int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] > 0)
      sum += arr[i];
  }

  return sum;
}

// Подсчитать количество элементов с положительными значениями
void get_count_pos(int count) {
  if (count > 0) {
    cout << "Количество положительных элементов: " << count << endl;
  } else
    cout << "В массиве нет положительных элементов." << endl;
}
