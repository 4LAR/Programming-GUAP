#include <iostream>
#include <cstdlib>
#include <cctype>

#include <ctime>

#include "lib.h"
#include "kalk.h"

using namespace std;



int main() {
	// смена кодировки
	system("chcp 65001");

	int r = random_double(1, 999);

	// калькулятор
	menu(1, r);

	// прогрессия
	menu(2, r);

	// меню
	menu(0, r);
	return 0;
} 
