#include<iostream>
#include<cmath>

using namespace std;

double f(double x) {
  return (sin(0.7 * x + 0.5)) / (1.1 + cos(x * x * x + 0.5));
}

double simpsonIntegral(double a, double b, int n) {
	const double width = (b - a) / n;

	double simpson_integral = 0;
	for (int step = 0; step < n; step++) {
		const double x1 = a + step * width;
		const double x2 = a + (step + 1) * width;

		simpson_integral += (x2 - x1) / 6.0 * (f(x1) + 4.0 * f(0.5 * (x1 + x2)) + f(x2));
	}

	return simpson_integral;
}

// a = 0.3
// b = 1.0
// n = 8

int main() {
  system("chcp 65001");

	double a, b;
	int n;
	cout << "Введите а: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите n: ";
	cin >> n;
	cout << "Метод Симпсона" << endl;
	cout << simpsonIntegral(a, b, n);
	return 0;
}
