
#include <iostream>
using namespace std;

class Employee {
public:
  Employee(char* full_name, int Year_of_admission, double Salary);

  void show_info();

protected:
  char* full_name;       // ФИО
  int year_of_admission;  // Год поступления на работу
  double salary;          // Оклад

};

// конструктор
Employee::Employee(char* Full_name, int Year_of_admission, double Salary) {
  full_name = Full_name;
  year_of_admission = Year_of_admission;
  salary = Salary;

  //if (director) count_subordinates++;
}

// вывод информации
void Employee::show_info() {
  //cout << "ФИО: " << full_name << end;
  printf("ФИО: %s\n", full_name);
  cout << "Год поступления на работу: " << year_of_admission << endl;
  cout << "Оклад: " << salary << " руб" << endl;
}
