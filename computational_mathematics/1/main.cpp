/*
  19 Вариант

  (a / x) + b * pow(M_E, c * x) = 0

  a = 2.37; b = -0.99; c = 0.56
  ε = 5·10-4
*/

#include <iostream>
using namespace std;

#include <cmath>
#include <iomanip>

#define _USE_MATH_DEFINES

#define DEFAULT_VAREBLES true
#define DEFAULT_RANGE true

// проверка ввода
double read_double(const char* promt = ""){
	double x;
  cout << promt;
  while ( (scanf("%lf",&x) ) != 1 ) {
    cout << "Неверное введенное значение, попробуйте еще." << endl << promt;
    while(getchar() != '\n');
  }
  return x;
}

// класс реализующий метод ХОРД
class Method_HORD {
public:
  Method_HORD(double, double, double, double);
  double func(double);
  double derivative_func(double);
  double double_derivative_func(double);
  double find(double, double);

  int iterCount;
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
  iterCount = 0;
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
    //cout << iterCount << " " << a << " " << b << endl;
		cout << "TEST: " << (a + b) / 2 << endl;
	}
	return (a + b) / 2;
}

int main() {
  // смена кодировки
  system("chcp 65001");

  // переменные для подстановки в функцию
  double a, b, c, epsilon;
  if (DEFAULT_VAREBLES) {
    a = 2.37;
    b = -0.99;
    c = 0.56;
    epsilon = 5 * pow(10, -4);
  } else {
    a = read_double("A = ");
    b = read_double("B = ");
    c = read_double("C = ");
    epsilon = read_double("E = ");
  }

  // диапазон
  double xMin, xMax;
  if (DEFAULT_RANGE) {
    xMin = 0.1;
    xMax = 10;
  } else {
    while (true) {
      xMin = read_double("xMin = ");
      xMax = read_double("xMax = ");

      if (xMax <= xMin) {
        cout << "xMin не может быть больше или равен xMax." << endl;
      } else if (xMin <= 0) {
        cout << "xMin не может быть меньше или равен 0." << endl;
      } else break;
    }
  }

  Method_HORD method_HORD(a, b, c, epsilon);

  // рассчёт
	double out = method_HORD.find(xMin, xMax);
  printf("Найденый корень: %lf\n", out);
	printf("F(%lf) = %lf\n", out, method_HORD.func(out));
  cout << "Потребовалось " << method_HORD.iterCount << " итераций." << endl;

  return 0;
}
