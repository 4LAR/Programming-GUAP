/*
  19 Вариант

  (a / x) + b * pow(M_E, c * x) = 0

  a = 2.37; b = -0.99; c = 0.56
  ε = 5·10-4
*/

#include <iostream>
using namespace std;

// #include "libs/lib.h"

#include <cmath>
#include <iomanip>

#define _USE_MATH_DEFINES

// класс реализующий метод ХОРД
class Method_HORD {
public:
  Method_HORD(double, double, double, double);
  double func(double);
  double derivative_func(double);
  double double_derivative_func(double);
  double find(double, double);

private:
  double a, b, c;
  double epsilon;
};

// конструктор
Method_HORD::Method_HORD(double _a, double _b, double _c, double _epsilon) {
  a = _a;
  b = _b;
  c = _c;
  epsilon = _epsilon;

  cout << "Исходные данные: " << endl;
  cout << "  A = " << a << endl;
  cout << "  B = " << b << endl;
  cout << "  C = " << c << endl;
  cout << "  E = " << epsilon << endl;
}

// double Method_HORD::find(double min, double max) {
//   while (fabs(max - min) > epsilon) {
//     min = max - (max - min) * func(max) / (func(max) - func(min));
//     max = min - (min - max) * func(min) / (func(min) - func(max));
//     cout << min << " " << max << endl;
//   }
//
//   return max;
// }

// нахождение корня
// double Method_HORD::find(double a, double b) {
//   double t;
//
//   while (fabs(b - a) >= epsilon) {
//     t = a + (func(b) * (b - a)) / (func(b) - func(a));
//
//     if (func(a) * func(t) < 0) {
//       b = t;
//     } else if (func(t) * func(b) < 0) {
//       a = t;
//     } else
//       return t;
//   }
//
//   return t;
// }

// функция
double Method_HORD::func(double x) {
  return (a / x) + b * exp(c * x);
}

// функция
double Method_HORD::derivative_func(double x) {
  return (b * c) * exp(c * x) - (a / pow(x, 2));
}

// функция
double Method_HORD::double_derivative_func(double x) {
  return (b * c * c) * exp(c * x) + (a * a) / pow(x, 3);
}


double Method_HORD::find(double a, double b) {
  int iterCount = 0;
  double d, c;
	while (abs(abs(b) - abs(a)) > 2 * epsilon) {
		if (func(a) * double_derivative_func(a) > 0) {
			d = a - func(a) / derivative_func(a);
			c = (a * func(b) - b * func(a)) / (func(b) - func(a));
			a = d;
			b = c;
		} else if (func(b) * double_derivative_func(b) > 0) {
			d = b - func(b) / derivative_func(b);
			c = (a * func(b) - b * func(a)) / (func(b) - func(a));
			b = d;
			a = c;
		}
		iterCount++; // узнать кол-во итераций
    cout << iterCount << " " << a << " " << b << endl;
	}
	return (a + b) / 2;
}



int main() {
  // смена кодировки
  system("chcp 65001");

  // изначальные данные
  double a = 2.37;
  double b = -0.99;
  double c = 0.56;
  double epsilon = 5 * pow(10, -4);

  Method_HORD method_HORD(a, b, c, epsilon);

  // рассчёт
  cout << method_HORD.find(0.1, 300) << endl;

  return 0;
}
