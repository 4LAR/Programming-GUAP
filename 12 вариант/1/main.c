/*
  Напишите программу для расчѐта двух выражений. Предварительно подготовьте тестовые
  примеры по обеим формулам (в excel или с помощью калькулятора; результат вычисления по
  первой формуле должен совпадать со второй). Значение параметров тригонометрических функций
  должны задаваться пользователем в градусах.
*/

#include <stdio.h>  
#include <stdlib.h>
#include <locale.h> // Для смены языка
#include <math.h>   // Математические функции и константы

// Функция для перевода градусов в радианы
double grad_to_rad(double deg) {
  return (deg / ( 180 / M_PI ));
}

// Функция для рассчёта котангенса
double ctg(double rad) {
  return tan(M_PI/2 - rad);
}

// Функция для проверки ввода
double read_double(){
	double x;
	fflush(stdin);
	if (scanf("%lf", &x) != 1){
		printf("ERROR\n");
		exit(0);
	}
	return x;
}

// основной код
int main() {

  // ввод угла в градусах
  printf("Enter deg: ");
  double a = read_double();

  // перевод градусов в радианы
  a = grad_to_rad(a);

  // первое выражение
  double z1 = ( sin(4 * a) / (1 + cos(4 * a)) ) * ( cos(2 * a) / (1 + cos(2 * a)) );
  printf("Z1 = %f\n", z1);

  // второе выражение
  double z2 = ctg( (3/2) * M_PI - a );
  printf("Z2 = %f\n", z2);

  return 0;
}
