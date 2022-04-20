 #include <iostream>
#include <cmath>

using namespace std;

// вывод массива в консоль
void draw_float_array(double *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
  cout << endl;
}

// ввод массива с клавиатуры
double *read_float_array(double *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << "array[" << i << "] = ";
    arr[i] = read_double();
  }
  return arr;
}

// количество элементов массива, равных 0
int get_count_zero(double *arr, int size) {
  // находим элементы
  int count_zero = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) 
      count_zero++;
  }

  // выводим
  if (count_zero == 0) 
    cout << "В массиве нет элеметов равных 0." << endl;
  else
    cout << "Количество элементов массива, равных 0: " << count_zero << endl;

  return count_zero;
}

// минимальный элемент
int get_min_index(double *arr, int size) {
  int min_index = 0;
  for (int i = 1; i < size; i++) {
    if (arr[min_index] > arr[i]) {
      min_index = i;
    }
  }
  cout << "Минимальный элемент массива: arr[" << min_index << "] = " << arr[min_index] << endl;

  return min_index;
}

// сумма элементов массива, расположенных после минимального элемента.
double get_summ(double *arr, int size, int min_index) {
  if (min_index < size-1) {
    double summ = 0;
    for (int i = min_index + 1; i < size; i++) {
      summ += arr[i];
    }

    cout << "Cумма элементов массива, расположенных после минимального элемента: " << summ << endl;
    return summ;
  } else {
    cout << "Минимальный элемент является последним в данном массиве." << endl;
    return -1;
  }
}
// Упорядочить элементы массива по возрастанию модулей элементов.
double *sort_arr(double *arr, int size) {
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size-1; i++) {
      if (abs(arr[i]) > abs(arr[i+1])) {
        swap(arr[i], arr[i+1]);
      }
    }
  }

  return arr;
}