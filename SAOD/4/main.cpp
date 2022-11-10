/*
  26 вариант

  26 % 25 + 1 = 2

  Линейное опрабирование
  2000 сигментов
  цццБцц


*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>
#include <time.h>
#include <iomanip>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

//
#include "hash.h"

int menu() {
  int id;
  while (true) {
    draw_line(30);
    cout << "1) Сгенерировать ключ" << endl;
    cout << "2) Ввести ключ вручную" << endl;
    cout << "3) Сгенерировать список ключей" << endl;
    cout << "4) Вывести список ключей" << endl;
    cout << "5) Очистить список ключей" << endl;
    cout << "6) Экспортировать в файл" << endl << endl;
    cout << "0) Выход" << endl;
    id = read_value(" >>> ", false, false, false);
    if (id >= 0 && id <= 6) {
      return id;

    } else {
      cout << "Этого нет в меню" << endl;

    }
  }

}

int main() {
  // смена кодировки
  system("chcp 65001");

  srand(time(NULL));

  /*
    i (int) = число
    c (char) = буква
  */

  My_hash my_hash("iiicii", 6);

  int menu_i;
  while (true) {
    menu_i = menu();

    switch (menu_i) {
    case (0):
      return 0;
      break;

    case (1):
      my_hash.generate();
      break;

    case (2):
      my_hash.generate(false);
      break;

    case (3):
      int count;
      while (true) {
        count = read_value("Количество ключей: ", false, false, false);
        if (count > 0) {
          for (int i = 0; i < count; i++)
            my_hash.generate();
          break;
        } else
          cout << "Число должно быть больше 0." << endl;
      }
      break;

    case (4):
      my_hash.draw_hash_list();
      break;

    case (5):
      my_hash.clear_hash_list();
      break;

    case (6):
      int file_name_length;
      cout << "Название файла: ";
      char* file_name = get_string(&file_name_length);
      my_hash.export_to_file(file_name);
      break;

    }

  }

  cout << my_hash.generate() << endl;

  return 0;
}
