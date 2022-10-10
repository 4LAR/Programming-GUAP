/*
  9 вариант
  
    Дата задана с помощью целочисленных полей day , month, year. Предусмотреть метод
  IsValid, проверяющий возможна ли заданная дата. 

*/

// раскомментировать если жалуется на scanf
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

#include <cmath>

#include "date.h"

// (говно) Ввод целого числа с проверкой
int read_int(const char* promt = ""){
	int x;
  cout << promt;
  while ( (scanf("%d",&x) ) != 1 ) {
    printf("Неверное введенное значение, попробуйте еще: ");
    while(getchar() != '\n');
  }
  return x;
}

int main() {

	// смена кодировки
  // setlocale(LC_ALL, "Russian");
  system("chcp 65001");

  Date date;

  int day = read_int("День: ");
  int month = read_int("Месяц: ");
  int year = read_int("Год: ");
  
  date.set_date(day, month, year);
  date.show("Введённая дата: ");

  if (date.IsValid())
    cout << "Дата введена корректно." << endl;
  else
    cout << "Дата введена не корректно." << endl;

	return 0;
}
