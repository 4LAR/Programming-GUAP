
#include <iostream>
using namespace std;

// Руководящий работник
class Leading_worker: public Employee {
public:
  Leading_worker(char* full_name, int Year_of_admission, double Salary, char* Name_department, int Count_subordinates);

  void info();

protected:
  char* name_department; // наименование отдела
  int count_subordinates; // количество подчиненных
};

Leading_worker::Leading_worker(char* full_name, int Year_of_admission, double Salary, char* Name_department, int Count_subordinates) :Employee(full_name, Year_of_admission, Salary) {
  name_department = Name_department;
  count_subordinates = Count_subordinates;
}

void Leading_worker::info() {
  cout << "Руководящий работник" << endl;
  show_info();
  printf("Наименование отдела: %s\n", name_department);
  cout << "Количество подчиненных: " << count_subordinates << endl;
}
