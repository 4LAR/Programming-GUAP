/*
	Вычислить и вывести на экран в виде таблицы значения функции 𝐹 на интервале
	𝑋нач, 𝑋кон с шагом 𝑑𝑥. Вид функции 𝐹 определяется индивидуальным вариантом.
	Коэффициенты 𝑎, 𝑏, 𝑐 являются действительными числами. Значения 𝑎, 𝑏, 𝑐, 𝑋нач, 𝑋кон, 𝑑𝑥
	вводятся с клавиатуры.

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "lib.h"

using namespace std;

int main() {
	// смена кодировки
  system("chcp 65001");

  double a = 0;
  double b = 0;
  double c = 0;

  double xMin = 0;
  double xMax = 0;
  double dx = 0;

  draw_line(20);

  cout << "a = ";
  scanf("%lf", &a);

  cout << "b = ";
  scanf("%lf", &b);

  cout << "c = ";
  scanf("%lf", &c);

  draw_line(20);

  cout << "xMin = ";
  scanf("%lf", &xMin);

  cout << "xMax = ";
  scanf("%lf", &xMax);

  cout << "dx = ";
  scanf("%lf", &dx);

  draw_line(20);

  double y = 0;
  cout << "| " << setw(7) << "X | " << setw(11) << "Y |\n";
  draw_line(20);
  for (double x = xMin; x < xMax + dx; x += dx) {
    if ( (x < 3) && (b != 0) ) {
      y = a * pow(x, 2) - b * x + c;
    } else if ( (x > 3) && (b == 0) ) {
      y = (x - a) / (x - c);
    } else {
      y = x / c;
    }
    cout << "| " << setw(4) << x << " | " << setw(8) << y << " |\n";
  }

  draw_line(20);

	return 0;
}
