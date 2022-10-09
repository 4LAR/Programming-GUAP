
#include <iostream>
using namespace std;

// Директор
class Director: public Employee {
public:
  Director(char* full_name, int Year_of_admission, double Salary, int Amoun_departments, int Allowance);

  void info();

protected:
  int amoun_departments; // количество отделов
  int allowance; // надбавка
};

Director::Director(char* full_name, int Year_of_admission, double Salary, int Amoun_departments, int Allowance) :Employee(full_name, Year_of_admission, Salary) {
  amoun_departments = Amoun_departments;
  allowance = Allowance;
}

void Director::info() {
  cout << "Директор" << endl;
  show_info();
  cout << "Количество отделов: " << amoun_departments << endl;
  cout << "Надбавка: " << allowance << " руб"<< endl;
}
