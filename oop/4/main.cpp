/*
  9 вариант (19 mod 10) + 1

    Создать класс Работник фирмы(фио, образование, Год поступления на
  работу, оклад). В классе должен быть метод вывода данных о работнике. На основе класса
  работника фирмы создать производные классы Стажер(должность, продолжительность
  испытательного строка, надбавка за прилежность), Руководящий работник(наименование
  отдела, количество подчиненных, надбавка за руководство), Директор(количество
  отделов, надбавка). В производных классах предусмотреть методы для расчета зарплаты и
  вычисления стажа работы, для Директора – подсчет количества подчиненных.

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "libs/time.h"

#include "Employee.h"
#include "Intern.h"
#include "Leading_worker.h"
#include "Director.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  //Employee test_employee((char*)"Столяров Никита Сергеевич", 2021);
  //test_employee.show_info();

  // Стажер
  Intern intern((char*)"test1", 2021, 13000, (char*)"Дэбил", 100, 1000);
  intern.info();

  draw_line();

  // Руководящий работник
  Leading_worker leading_worker((char*)"test2", 2021, 20000, (char*)"Завод для дэбилов", 10);
  leading_worker.info();

  draw_line();

  // Директор
  Director director((char*)"test3", 2021, 999999, 2, 100);
  director.info();

	return 0;
}
