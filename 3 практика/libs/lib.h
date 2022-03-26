#include <iostream>
#include <cmath>

using namespace std;

void draw_line(int size) {
  for (int i = 0; i < size; i++)
    cout << '-';
  cout << endl;
}

int random_int(int a, int b) {
	return a + rand() % b;
}

int get_N(int r, int n) {
  int out = r % (n + 1);
  if (out < 1)
    return out + 1;
  else
    return out;
}

double read_double(){
	double x;
  while ( (scanf("%lf",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

int read_int(){
	int x;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}
