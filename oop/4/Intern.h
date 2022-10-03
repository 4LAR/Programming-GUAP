
#include "Employee.h"

class Intern: public Employee {
public:
  // Intern(): Employee((char*)"Столяров Никита Сергеевич", 2021) {
  //
  // }

  Intern(char* Job_title, char* Duration, double Diligence_bonus);

private:
  char* job_title;
  char* duration;
  double diligence_bonus;
};

Intern::Intern(char* Job_title, char* Duration, double Diligence_bonus) {
  job_title = Job_title;
  duration = Duration;
  diligence_bonus = Diligence_bonus;
}
