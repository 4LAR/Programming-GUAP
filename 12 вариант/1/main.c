#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

double grad_to_rad(double deg) {
  return (deg / ( 180 / M_PI ));
}

double ctg(double rad) {
  return tan(M_PI/2 - rad);
}

double read_double(){
	double x;
	fflush(stdin);
	if (scanf("%lf", &x) != 1){
		printf("ERROR\n");
		exit(0);
	}
	return x;
}

int main() {
  //setlocale(LC_ALL, "C");

  printf("Enter deg: ");
  double a = read_double();

  a = grad_to_rad(a);

  double z1 = ( sin(4 * a) / (1 + cos(4 * a)) ) * ( cos(2 * a) / (1 + cos(2 * a)) );
  printf("Z1 = %f\n", z1);

  double z2 = ctg( (3/2) * M_PI - a );
  printf("Z2 = %f\n", z2);

  return 0;
}
