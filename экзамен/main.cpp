/*
  Экзамен

*/

#include <iostream>
using namespace std;

#include "libs/lib.h"
#include <cmath>

#include <cstdio>

// проверка ввода
#include "libs/simple_char.h"
#include "libs/input_validation.h"

#include "structs.h"
#include "files.h"

int main() {
	// смена кодировки
  system("chcp 65001");

  char c;

  char *input_file_name = get_file_name("Имя входного файла: ", "Невозможно прочитать файл. Возможно его не существует.");
  //char *output_file_name = get_file_name("Имя выходного файла: ", "Невозможно записать или создать файл.");

  FILE *input_file;
  FILE *output_file;

  bool slovo_flag = false;

  char *slovo = (char*) malloc(sizeof(char));

  int size = 0;

  // 0 - nothing, 1 - slovo, 2 - number, 3 - other
  int type_slovo = 0;

  list *number_list = create((char*)"", -1);
  list *slovo_list = create((char*)"", -1);

  input_file = fopen(input_file_name, "r");
  //output_file = fopen(output_file_name, "w");

  while (!feof(input_file)) {
    fscanf(input_file, "%c", &c);

    if (!isspace(c)) {
      slovo_flag = true;
      size++;
      slovo = (char*) realloc(slovo, ((size) + 1) * sizeof(char));
      slovo[size - 1] = c;

      if (check_num(c) != -1) {
        if (type_slovo == 0 || type_slovo == 2)
          type_slovo = 2;
        else
          type_slovo = 3;

      } else {
        if (type_slovo == 0 || type_slovo == 1)
          type_slovo = 1;
        else
          type_slovo = 3;

      }

    } else {
      if (slovo_flag) {
        slovo[size+1] = '\0';
        if (type_slovo == 1) {
          add_element_end(slovo, size, slovo_list);
        } else if (type_slovo == 2) {
          add_element_end(slovo, size, number_list);
        }
       
          
        
      }
      slovo = (char*) malloc(sizeof(char));
      slovo_flag = false;
      size = 0;

      type_slovo = 0;

    }

    

  }

  cout << endl;
  
  draw_line(20);
  cout << " < Слова > " << endl;
  draw_list(slovo_list, 1);
  draw_line(20);
  cout << " < Числа > " << endl;
  draw_list(number_list, 2);

  // закрываем файлы
  fclose(input_file);
  //fclose(output_file);

	return 0;
}
