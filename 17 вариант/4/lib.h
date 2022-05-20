#include <iostream>

using namespace std;

// функция рисующая полосу для разделения
void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}

// проверка ввода. Кривая, но работает.
double read_double(){
	double x;
  // lf - double
  while ( (scanf("%lf", &x) ) != 1 ) {
      printf("Неверное введенное значение, попробуйте еще: ");
      while(getchar() != '\n');
  }
  return x;
}
