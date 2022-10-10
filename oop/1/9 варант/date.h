#include <iostream>
using namespace std;

class Date{
  public:
    void set_date(int, int, int);
    bool IsValid();
    void show(const char* promt);
    
  private:
    int day;
    int month;
    int year;

};

// ввод даты
void Date::set_date(int Day, int Month, int Year) {
  day = Day;
  month = Month;
  year = Year;
}

// проверка на корректность даты
bool Date::IsValid() {
  if (year < 1) return false;
  if (month < 1 || month > 12) return false;
  if (day < 1 || day > 31) return false;

  if (
    month == 4 || month == 6 ||
    month == 9 || month == 11
  ) return (day <= 30);

  return true;
}

// вывод даты
void Date::show(const char* promt = "") {
  cout << promt;
  cout << day << ".";
  cout << month << ".";
  cout << year << endl;
}
