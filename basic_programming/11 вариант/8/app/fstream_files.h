
#include <iostream>
using namespace std;

#include <cmath>
#include <time.h>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>

#define NUMS_CHAR_LEN 10

// ������� ��� �������� ����� �� �������������
char *get_file_name(const char *promt = "", const char *error_promt = "", bool new_file = false) {

  ifstream input_file;

  int len;
  char *input_file_name;

  bool ok = false;
  while (!ok) {
    cout << promt;
    input_file_name = get_string(&len);
    if (len > 0) {
      ok = true;

      input_file.open(input_file_name);

      if (!input_file.good()) {
        if (new_file) {
          ofstream ost(input_file_name);
        } else {
          cout << error_promt << endl;
          ok = false;
        }

      }

      input_file.close();

    }
  }

  return input_file_name;
}

// ������� ��� ����������� �����
int check_num(char str) {
  char nums_char[NUMS_CHAR_LEN] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < NUMS_CHAR_LEN; i++) {
    if (nums_char[i] == str) {
      return i;
    }
  }
  return -1;
}

// ������� ��� �������� ����
void check_words(char *input_file_name, char *output_file_name) {

  ifstream input_file;
  ofstream output_file;

  // ��������� �����
  input_file.open(input_file_name);
  output_file.open(output_file_name);

  // �������� ���������� ��� �������� ���������� �������
  char c;

  int nums_count = 0;
  int str_len = 0;
  // ������ ��� ���������� ��������� ������
  char *str = (char*) malloc(sizeof(char));

  // ���� �� ����� �����
  while (input_file) {

    // ���� �� ����� 1 ������
    c = input_file.get();

    // ���������� ������, ���� ��� ����� ������ ��� �����
    if (c == '\n' || !input_file) {
      if (nums_count != 2) {
        str[str_len] = '\0';
        output_file << str << endl;
      }

      // �������� ��� ����������
      nums_count = 0;
      str_len = 0;
      str = (char*) malloc(sizeof(char));

    } else {
      // ��������� ������ � ������
      str = (char*) realloc(str, (++str_len + 1) * sizeof(char));
      str[str_len - 1] = c;
      // ���� � ������ ���� �����, �� ���������� � ��������� 1
      if (check_num(c) != -1) nums_count++;

    }

  }

  // ��������� �����
  input_file.close();
  output_file.close();

}
