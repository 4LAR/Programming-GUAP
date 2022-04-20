#include <iostream>
#include <cmath>

using namespace std;

// рисует разделяющую линию (-----------------------)
void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}

// рандом от a до b
int random_int(int a, int b) {
	return a + rand() % b;
}

// проверка ввода (double)
double read_double(){
	double x;
  while ( (scanf("%lf",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

// проверка ввода (int)
int read_int(){
	int x;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}