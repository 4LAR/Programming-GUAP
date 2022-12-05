
#include <iostream>
using namespace std;

#include <time.h>
#include <string.h>

class T_end_d {
public:
  T_end_d(); // конструктор по умолчанию
  T_end_d(struct tm *u); // конструктор с аргуметами
  T_end_d(const T_end_d & ref_T_end_d); // конструктор копирования
  ~T_end_d();

  void show(const char *promt);

private:
  struct tm *saved_time;
};

// конструктор по умолчанию
T_end_d::T_end_d() {
  const time_t timer = time(NULL);
  saved_time = localtime(&timer);
}

// конструктор с аргуметами
T_end_d::T_end_d(struct tm *u) {
  saved_time = u;
}

// конструктор копирования
T_end_d::T_end_d(const T_end_d & ref_T_end_d) {
  saved_time  = ref_T_end_d.saved_time;
  cout << "Класс скопирован." << endl;
}

// деструктор
T_end_d::~T_end_d() {
  cout << "Стработал деструктор" << endl;
}

// вывод времени
void T_end_d::show(const char *promt = "") {
  char s[40];
  char *tmp;
  for (int i = 0; i < 40; i++)
    s[i] = 0;

  int length = strftime(s, 40, "%d.%m.%Y %H:%M:%S", saved_time);
  tmp = (char*)malloc(sizeof(s));

  strcpy(tmp, s);
  cout << promt << "Текущее время и дата: ";
  puts(tmp);
}
