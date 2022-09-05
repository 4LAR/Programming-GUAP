#include <iostream>
#include <cstdlib>
#include <cctype>

#include <ctime>

using namespace std;

int random_double(int a, int b) {
	return a + rand() % b;
}

int get_N(int r, int n) {
	return r % n + 1;
}

double alg_prog_while(int k) {
	int i = 0;
	int s = 1;
	while (i < k) {
		i++;
		s += 1;
	}
	return s;
}

double alg_prog_for(int k) {
	int s = 1;
	for (int i = 0; i < k; i++)
		s++;

	return s;
}

double alg_prog(int id, int k) {
	cout << "4 Задание" << endl;
	int x = 0;
	switch (id) {
		case (1):
			cout << "While" << endl;
			x = alg_prog_while(k);
			break;
		case (2):
			cout << "While" << endl;
			x = alg_prog_for(k);
			break;
	}
	cout << "Результат: " << x << endl;
	return x;
}

double add_razn_umn(int id, double a, double b, double c) {
	cout << "3 Задание" << endl;
	double x = 0;
	switch (id) {
		case (1):
			cout << "Сумма" << endl;
			x = a + b + c;
			break;
		case (2):
			cout << "Вычитание" << endl;
			x = a - b - c;
			break;
		case (3):
			cout << "Умножение" << endl;
			x = a * b * c;
			break;
	}
	cout << "Результат: " << x << endl;
	return x;
}

void menu(int m = 0, int r = 0){
	draw_line(20);
	double x = 0;
	if (m == 0){
		cout << "Меню" << endl;
		cout << "1 - Калькулятор\n2 - прогрессия\n";

		while (m != 1 && m != 2){
			cout << "menu >> ";
			scanf("%d", &m);
		}
		draw_line(20);
	}
	
	switch (m) {
		case (1):
			double a, b, c;
			cout << "A = ";
			scanf("%lf", &a);
			cout << "B = ";
			scanf("%lf", &b);
			cout << "C = ";
			scanf("%lf", &c);

			x = add_razn_umn(get_N(r, 3), a, b, c);

			cout << x << endl;

			break;
		case (2):
			int k;
			cout << "K = ";
			scanf("%d", &k);

			x = alg_prog(get_N(r, 2), k);

			cout << x << endl;

			break;
	}
}