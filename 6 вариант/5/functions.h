#include <iostream>
#include <cmath>

using namespace std;

// функция для нахождения минимального элемента (возвращает индификатор)
int get_min_el(double *arr, int size) {
  int min = arr[0];
  int id = 0;

  for (int i = 1; i < size; i++) {
    // если число меньше чем то что записано в min, то перезаписываем его
    if (arr[i] < min) {
      id = i;
      min = arr[i];
    }
  }

  return id;
}

// функция для получения индификаторов первого или последнего положительного элемента
int get_positive_el(double *arr, int size, bool last=false) {
  int id = -1;

  // цикл по всему массиву
  for (int i = 1; i < size; i++) {
    if (arr[i] > 0) {
      // если мы возвращаем первый элемент, то возвращаем индификатор здесь
      if (!last)
        return i;
      else
        id = i;
    }
  }

  // если мы возвращаем последний элемент, то возвращаем индификатор здесь
  return id;
}

// функция для сортировки (сначала 0, потом всё остальное)
double *sort(double *arr, int size) {
  // создаём новый массив
  double *new_arr = (double*) malloc(size * sizeof(double));
  int j = 0;

  // сначала записываем все нули
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0)
      new_arr[j++] = arr[i];
  }

  // потом записываем в массив всё остальное
  for (int i = 0; i < size; i++) {
    if (arr[i] != 0)
      new_arr[j++] = arr[i];
  }

  return new_arr;
}
