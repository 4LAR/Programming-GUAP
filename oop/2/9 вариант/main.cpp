/*
  9 вариант

    Определите класс t_end_d, которому при его создании передается текущее системное
  время и дата в виде параметров конструктора. Этот класс должен включать функциючлен, выводящую время и дату на экран. (Для нахождения и вывода на экран этих данных
  воспользуйтесь стандартной библиотечной функцией.)


*/

#include <iostream>
using namespace std;

#include <time.h>

#include "time.h"

int main() {
	// смена кодировки
  system("chcp 65001");
  T_end_d t_end_d_noargs;
  t_end_d_noargs.show("[по умолчанию]");

  T_end_d t_end_d_copy = t_end_d_noargs;
  t_end_d_copy.show("[скопированный]");

  const time_t timer = time(NULL);
  struct tm *t = localtime(&timer);
  t -> tm_hour = 2;

  T_end_d t_end_d_args(t);
  t_end_d_args.show("[с аргументами]");

	return 0;
}
