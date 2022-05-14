#include <iostream>
#include <Windows.h>
#include "proverka.h"
#include "header.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


//#define DEBUG

int main() {


	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//i размер массива чаров

	char c, a;
	int i = 0;
	char* z1 = new char[i]; //создание одномерного массива
	std::cout << ("Введите текст. Включите точку ('.') в предложение, чтобы остановить ввод: ") << std::endl;
	////i размер массива чаров
	do {
							//c = getchar();//Символ считывается как переменная типа unsigned char, преобразованная к целому.
							//a = putchar(c);//записывает символ, находящийся в младшем байте ch, в файл stdout.
		a = getchar();
		//расширение динамического массива с помошью второго на 1 больше
		char* z2 = new char[i + 1];
		for (int j = 0; j < i; j++) {
			z2[j] = z1[j];
		}

		i++;
		//удаление старого массива, переназначение старого на нового на один больше
		delete[] z1;
		z1 = z2;
		z1[i - 1] = a;

	} while (a != '.');
	std::cin.ignore();
	std::cin.clear();

	// отладка
#ifdef DEBUG //==if
	outputarry1(z1, i);
	// отладка
#endif // DEBUG					//#ifndef Директива проверяет наличие противоположного условия, установленного #ifdef .
	wordDelete(z1, i);			//Если идентификатор не был определен или его определение было удалено с помощью, условие имеет значение true
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
