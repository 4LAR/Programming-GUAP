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

  while ( (scanf("%lf",&x) ) != 1 ) {
      printf("Неверное введенное значение, попробуйте еще: ");
      while(getchar() != '\n');
  }
  return x;
}

double z_1(double a){
  return ( sin(4 * a) / (1 + cos(4 * a)) ) * ( cos(2 * a) / (1 + cos(2 * a)) );
}

double z_2(double a){
  return ctg( (3/2) * M_PI - a );
}


// основной код
int main() {
  // смена кодировки
  system("chcp 65001");

  // ввод угла в градусах
  printf("Введите угол (в градусах): ");
  double a = read_double();

  // перевод градусов в радианы
  a = grad_to_rad(a);

  // первое выражение
  double z1 = z_1(a);
  printf("Z1 = %f\n", z1);

  // второе выражение
  double z2 = z_1(a);
  printf("Z2 = %f\n", z2);

  if (z1 == z1) {
    printf("Ответы равны\n");
  } else {
    printf("Ответы не равны\n");
  }

  return 0;
}
