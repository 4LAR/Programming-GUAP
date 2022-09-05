// var 8
// Для обнаружения утечек памяти
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW
#endif
#endif


#include <iostream>
#include <limits>
#include <cmath>

using namespace std;
double check(int i);
int minimum(double *array, int n);
double sum(double *array, int n, bool *q);
void transform(double *array, int n, double *array2);

int main() {
	//setlocale(LC_ALL, "Rus");
	system("chcp 65001");

	int n;

	cout << "Введите длину массива: "; cin >> n;
	while (cin.fail() || n <= 0) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Ой, кажется вы пытаетесь создать несуществующий массив.\nВведите длину массива ещё раз: ";
		cin >> n;
		cout << endl;
	}

	cout << "Вводите элементы массива по порядку: \n";
	bool q = false;
	double* array = new double[n];
	double* array2 = new double[n];

	for (int i = 0; i < n; i++) {
		array[i] = check(i);
	}
	sum(array, n, &q);
	cout << "\n\nНомер первого минимального элемента массива: " << minimum(array, n);
	if (q) {
		cout << "\n\nCумма элементов массива, расположенных между \nпервым и вторым отрицательными элементами: " << sum(array, n, &q);
	}
	else {
		cout << "\n\nCумма элементов массива, расположенных между \nпервым и вторым отрицательными элементами: нет элементов";
	}
		transform(array, n, array2);

	cout << "\n\nПреобразованный массив: ";

	for (int i = 0; i < n; i++) {
		cout << array2[i] << '\t';
	}

	cout << endl << endl;
	delete[] array;
	delete[] array2;

	// Для обнаружения утечек памяти
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;
}

double check(int i) {
	double num;
	cout << "Arr[" << i << "] = "; cin >> num;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Ой, кажется вы ошиблись. Введите число ещё раз." << endl;
		cout << "Array[" << i << "] = "; cin >> num;
	}
	return num;
}

int minimum(double *array, int n){
	int p = 0;
	for (int i = 0; i < n; i++) {
		if (array[p] > array[i]) p = i;
	}
	return p;
}

double sum(double *array, int n, bool *q) {
	int min = 0, p, max = 0;
	double s = 0;
	for (int i = 0; i < n; i++)	{
		if (array[i] < 0) { min = i; break; }
	}
	p = min + 2;
	for (p; p < n; p++) {
		if (array[p] < 0) { *q = true; max = p; break; }
	}
	for (int i = min + 1; i < max; i++) {
		s += array[i];
	}
	return s;
}

void transform(double* array, int n, double* array2){
	int i2 = 0;

	for (int i = 0; i < n; i++) {
		if (abs(array[i]) <= 1) {
			array2[i2] = array[i];
			i2++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (abs(array[i]) > 1) {
			array2[i2] = array[i];
			i2++;
		}
	}
}
