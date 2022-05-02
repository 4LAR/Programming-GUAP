#include <iostream>

// функция удаление слова
char* wordDelete(char* mas, int i) {
	int numberWord = 1;
	for (int j = 0; j < i; j++) {
		if ((int)mas[j] == 32) {
			numberWord++;
		}
	}
	int a = -1;
	while ((a > numberWord) || (a < 0)) {
			std::cout << "\nвведите номер слова для удаления не больше " << numberWord << ": ";
			std::cin >> a;
	}
	a--;
	int** WordPosition = new int*[numberWord];

	//формирование 2 мерного динамического масива
	for (int j = 0; j < numberWord; j++) {
		WordPosition[j] = new int [2];
	}

	//заполнение 2 мерного динамического масива размерами слов
	bool flag = false;
	int WordPositionCounter = 0;
	WordPosition[0][0] = 0;
	for (int j = 1; j < i; j++) {
		if (flag) {
			if ((int)mas[j] != 32) {
				WordPosition[WordPositionCounter][0] = j;
				flag = false;
			}
		} else {
			if (((int)mas[j] == 32 && (int)mas[j+1] != 32) || (int)mas[j] == 46) {
				WordPosition[WordPositionCounter][1] = j-1;
				WordPositionCounter++;
				flag = true;
			}
		}
	}

	for (int j = WordPosition[a][0]; j <= WordPosition[a][1]; j++) {
		mas[j] = '\0';
	}

	for (int j = 0; j < numberWord; j++) {
		delete [] WordPosition[j];
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
