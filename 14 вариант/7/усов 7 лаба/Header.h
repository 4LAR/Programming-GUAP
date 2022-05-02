//char* arrayExtension(char* mas, ) {
//	
//}
// функция удаление слова
char* wordDelete(char* mas, int i) {
	int numberWord = 1;
	for (int j = 0; j < i; j++){
		if ((int)mas[j] == 32){
			numberWord++;
		}
	}
	int a;
	std::cout << "введите номер слова для удаления не больше:" << numberWord<< std::endl;
	do {
		std::cin >> a;
	} while (a > numberWord);
	a--;
	int** WordPosition = new int*[numberWord];
	//формирование 2 мерного динамического масива 
	for (int j = 0; j < numberWord; j++){
		WordPosition[j] = new int [2];
	}
	//заполнение 2 мерного динамического масива размерами слов
	bool flag = false;
	int WordPositionСounter = 0;
	WordPosition[0][0] = 0;
	for (int j = 1; j < i; j++){
		if (flag) {
			if ((int)mas[j] != 32) {
				WordPosition[WordPositionСounter][0] = j;
				flag = false;
			}
		}else {
			if(((int)mas[j] == 32 && (int)mas[j+1] != 32) || (int)mas[j] == 46){
				WordPosition[WordPositionСounter][1] = j-1;
				WordPositionСounter++;
				flag = true;
			}
		}
	}
	//проверка работы програмы
	/*for (int j = 0; j < numberWord; j++) {
		for (int h = 0; h < 2; h++) {
			std::cout << "WordPosition[" << j << "] [" << h << "] = " << WordPosition[j][h] << std::endl;
		}
	}*/
	for (int j = WordPosition[a][0]; j <= WordPosition[a][1]; j++){
		mas[j] = ' ';
	}
	for (int j = 0; j < numberWord; j++){
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
		std::cout <<mas[j];
	}
}