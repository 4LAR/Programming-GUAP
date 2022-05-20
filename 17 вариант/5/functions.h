#include <iostream>
#include <cmath>

using namespace std;

// функция для нахождения в массиве количества положительныйх элементов
int get_count_positive_els(double *arr, int size) {
  int count_positive_els = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > 0) {
      count_positive_els++;
    }
  }

  return count_positive_els;
}

// функция для получения суммы элементов после 0
int sum_els_from_last_zero(double *arr, int size) {
  int id = -1;
  int summ = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      id = i;
    }
  }

  if (id < 0) return -1;
  
  for (int i = id; i < size; i++) summ += arr[i];

  return summ;

}