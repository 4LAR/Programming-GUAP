#include <iostream>
#include <Windows.h>
#include "header.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//#define DEBUG true

int main() {

	// смена кодировки
  system("chcp 65001");

	char c, a;
	int i = 0;
	char* z1 = new char[i];
	std::cout << ("Введите текст. Включите точку ('.') в предложение, чтобы остановить ввод: ") << std::endl;
	do {
		c = getchar();
		a = putchar(c);
		char* z2 = new char[i + 1];
		for (int j = 0; j < i; j++) {
			z2[j] = z1[j];
		}

		i++;
		delete[] z1;
		z1 = z2;
		z1[i - 1] = a;

	} while (c != '.');

#ifdef DEBUG
	outputarry1(z1, i);

#endif // DEBUG
	wordDelete(z1, i);
	outputarry2(z1, i);
	delete[] z1;
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
