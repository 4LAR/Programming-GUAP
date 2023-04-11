
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//void solve(double x[], double y[]);


void solve(double x[], double y[]) {
  //вычисление конечных разностей
  double dY1[4];
  double dY2[3];
  double dY3[2];
  double dY4[1];

  for (int i = 0; i < 4; i++) {
    dY1[i] = y[i + 1] - y[i];
  }

  for (int i = 0; i < 3; i++) {
    dY2[i] = dY1[i + 1] - dY1[i];
  }

  for (int i = 0; i < 2; i++) {
    dY3[i] = dY2[i + 1] - dY2[i];
  }
  dY4[0] = dY3[1] - dY3[0];

  //вычисление значений коэффициента полинома
  double h = x[1] - x[0];
  double a[5];
  a[0] = y[0];
  a[1] = dY1[0] / h / 1;
  a[2] = dY2[0] / (2 * pow(h, 2));
  a[3] = dY3[0] / (6 * pow(h, 3));
  a[4] = dY4[0] / (24 * pow(h, 4));

  int c;
  double iX, Yinterp, m;
  vector <double> input;
  int e = 1;
  while (e == 1) {
    //Ввод значений x
    input.clear();

    cout << "Введите количество дополнительных точек: ";
    cin >> c;
    for (int i = 0; i < c; i++) {
      cout << "x[" << i << "]= ";
      cin >> iX;
      input.push_back(iX);
    }

    cout << endl;
    //вычисления y по первой формуле ньютона

    for (int i = 0; i < c; i++) {
      m = 1;
      Yinterp = 0;

      for (int j = 0; j < 5; j++) {
        Yinterp += m * a[j];
        m *= input[i] - x[j];
      }
      cout << "Yinterp[" << i << "]= " << Yinterp << endl;
    }

    cout << "Если вы хотите ввести дополнительные значения, нажмите 1, нет - 0" << endl;
    cin >> e;
  }
}

int main() {
  system("chcp 65001");

  const int n = 5;

  //double x[n];
  //double y[n];

  // cout << "Введите узловые точки: \n";
  double x[] =  {1.0, 0.7, 0.4, 0.1, -0.2};
  double y[] = {2.5, 3.7, 4.2, 2.0, 0.0};
  for (int i = 0; i < n; i++) {
    //cout << "x[" << i << "] = "; //{ -3.1, -2.3, -1.5, -0.7, 0.1 }
    //cin >> x[i];


    //cout << "y[" << i << "] = "; //{ -0.4, -1.1, -0.3, 0.5, 2.4 }
    //cin >> y[i];
  }

  solve(x, y);

  return 0;
}
