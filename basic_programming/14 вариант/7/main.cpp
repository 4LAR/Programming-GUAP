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
	//i ������ ������� �����

	char c, a;
	int i = 0;
	char* z1 = new char[i]; //�������� ����������� �������
	std::cout << ("������� �����. �������� ����� ('.') � �����������, ����� ���������� ����: ") << std::endl;
	////i ������ ������� �����
	do {
							//c = getchar();//������ ����������� ��� ���������� ���� unsigned char, ��������������� � ������.
							//a = putchar(c);//���������� ������, ����������� � ������� ����� ch, � ���� stdout.
		a = getchar();
		//���������� ������������� ������� � ������� ������� �� 1 ������
		char* z2 = new char[i + 1];
		for (int j = 0; j < i; j++) {
			z2[j] = z1[j];
		}

		i++;
		//�������� ������� �������, �������������� ������� �� ������ �� ���� ������
		delete[] z1;
		z1 = z2;
		z1[i - 1] = a;

	} while (a != '.');
	std::cin.ignore();
	std::cin.clear();

	// �������
#ifdef DEBUG //==if
	outputarry1(z1, i);
	// �������
#endif // DEBUG					//#ifndef ��������� ��������� ������� ���������������� �������, �������������� #ifdef .
	wordDelete(z1, i);			//���� ������������� �� ��� ��������� ��� ��� ����������� ���� ������� � �������, ������� ����� �������� true
	outputarry2(z1, i);
	delete[] z1;
	// ��� ����������� ������ ������
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();
	return 0;

}
