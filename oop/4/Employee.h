
#include <iostream>
using namespace std;

class Employee {
public:
  Employee(char* full_name, int Year_of_admission);

  void show_info();

private:
  char* full_name;       // ФИО
  int year_of_admission;  // Год поступления на работу
  double salary;          // Оклад

};

// конструктор
Employee::Employee(char* Full_name, int Year_of_admission) {
  full_name = Full_name;
  year_of_admission = Year_of_admission;
}

// вывод информации
void Employee::show_info() {
  //cout << "ФИО: " << full_name << end;
  printf("ФИО: %s\n", full_name);
  cout << "Год поступления на работу: " << year_of_admission << endl;
}
