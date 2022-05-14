#include <iostream>

//using namespace std;
// ������� �������� �����
char* wordDelete(char* mas, int i) {
	const int N = 256;
	char S[N];
	float value = 0;
	//32 �� ���� ������, 46 - "."
	bool wordEnebl = false;
	for (int j = 0; j < i; j++) {
		if ((int)mas[j] != 32 && (int)mas[j] != 46)
		{
			wordEnebl = true;
		}
	}
		if (!wordEnebl) {
			std::cout << "���� ��� �������� ����������";
			return 0;
		}

	//32 �� ���� ������, 46 - ".", 33 - "!", 63 = "?", 43 - "+", 45 - "-"
	int numberWord = 1;
	for (int j = 0; j < i; j++) {
		if ((int)mas[j] == 32 && ((int)mas[j + 1] != 32 && (int)mas[j + 1] != 46) /* ����� ����� ��������� ����� ������� > */  && (int)mas[j + 1] != 33 && (int)mas[j + 1] != 63 && (int)mas[j + 1] != 43 && (int)mas[j + 1] != 45) {
			numberWord++;
		}
	}
	int a = -1;
	while ((a > numberWord) || (a < 0)) {
		std::cout << "������� ����� ����� ��� �������� �� ������ " << numberWord << ": ";
		std::cin.getline(S, N);
		while (!is__int(S)) {
			std::cerr << "������� ����� �����:";
			std::cin.getline(S, N);
		}
		a = atoi(S);

		//std::cin >> a;
	}
	a--;
	//�������� �������
	int** WordPosition = new int* [numberWord];

	//������������ 2 ������� ������������� ������
	// ���������� ������� ������� �������� �� ������� �� 2�������
	for (int j = 0; j < numberWord; j++) {
		WordPosition[j] = new int[2];
	}

	//���������� 2 ������� ������������� ������ ��������� ����
	bool flag = false;
	int WordPositionCounter = 0;
		//������� � ������� �����
	WordPosition[0][0] = 0;
	for (int j = 1; j < i; j++) {
		if (flag) {
			if ((int)mas[j] != 32 && (int)mas[j] != 46 /* ����� ����� ��������� ����� ������� > */  && (int)mas[j] != 33 && (int)mas[j] != 63 && (int)mas[j] != 43 && (int)mas[j] != 45) {
				WordPosition[WordPositionCounter][0] = j;
				flag = false;
				//���������� ������
			}
		}
		else {
			if (((int)mas[j] == 32 && (int)mas[j + 1] != 32) || (int)mas[j] == 46) {
				WordPosition[WordPositionCounter][1] = j - 1;
				//���������� ����� �����
				WordPositionCounter++;
				flag = true;
			}
		}
	}

	// ������ �����
	//�������� 2 ������� ������������� ������ ��������� ����
	for (int j = WordPosition[a][0]; j <= WordPosition[a][1]; j++) {
		mas[j] = '\0'; //������� �������� �� ������ �����, �� ��� ��� ���� �� �������� ���� ����
	}

	for (int j = 0; j < numberWord; j++) {
		delete[] WordPosition[j];
	}

	delete[] WordPosition;
	return mas;
}

void outputarry1(char* mas, int i) {
	for (int j = 0; j < i; j++) {
		std::cout << "x[" << j << "] =" << mas[j] << std::endl;
	}
}

void outputarry2(char* mas, int i) {
	for (int j = 0; j < i; j++) {
		std::cout << mas[j];
	}
}
