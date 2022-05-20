#include <iostream>
#include <cmath>

using namespace std;

// функция для вывода линии в консоль (используется для разделения вывода)
void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}

// проверка ввода. (возвращает double)
double read_double(){
	double x;
  while ( (scanf("%lf",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

// проверка ввода. (возвращает int)
int read_int(){
	int x;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

// функция для вывода одномерного массива
void draw_float_array(double *arr, int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << "\t";
  cout << endl;
}
