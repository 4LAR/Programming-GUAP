//char* arrayExtension(char* mas, ) {
//	
//}
// ������� �������� �����
char* wordDelete(char* mas, int i) {
	int numberWord = 1;
	for (int j = 0; j < i; j++){
		if ((int)mas[j] == 32){
			numberWord++;
		}
	}
	int a;
	std::cout << "������� ����� ����� ��� �������� �� ������:" << numberWord<< std::endl;
	do {
		std::cin >> a;
	} while (a > numberWord);
	a--;
	int** WordPosition = new int*[numberWord];
	//������������ 2 ������� ������������� ������ 
	for (int j = 0; j < numberWord; j++){
		WordPosition[j] = new int [2];
	}
	//���������� 2 ������� ������������� ������ ��������� ����
	bool flag = false;
	int WordPosition�ounter = 0;
	WordPosition[0][0] = 0;
	for (int j = 1; j < i; j++){
		if (flag) {
			if ((int)mas[j] != 32) {
				WordPosition[WordPosition�ounter][0] = j;
				flag = false;
			}
		}else {
			if(((int)mas[j] == 32 && (int)mas[j+1] != 32) || (int)mas[j] == 46){
				WordPosition[WordPosition�ounter][1] = j-1;
				WordPosition�ounter++;
				flag = true;
			}
		}
	}
	//�������� ������ ��������
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