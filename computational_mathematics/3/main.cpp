
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define AUTO_INPUT true

void solve(double x[], double y[], int n) {
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

  input.clear();

  double delta = 0;
  c = n;
  for (int i = 0; i < c - 1; i++) {
    delta = (x[i] - x[i + 1]) / 2;
    input.push_back(x[i] - delta);
  }

  // cout << "Введите количество дополнительных точек: ";
  // cin >> c;
  // for (int i = 0; i < c; i++) {
  //   cout << "x[" << i << "]= ";
  //   cin >> iX;
  //   input.push_back(iX);
  // }

  cout << endl;
  //вычисления y по первой формуле ньютона

  for (int i = 0; i < c - 1; i++) {
    m = 1;
    Yinterp = 0;

    for (int j = 0; j < 5; j++) {
      Yinterp += m * a[j];
      m *= input[i] - x[j];
    }
    cout << "Yinterp[" << input.at(i) << "]= " << Yinterp << endl;
  }

}

int main() {
  system("chcp 65001");

  int n;
  double *x;
  double *y;
  if (AUTO_INPUT) {
    n = 5;
    x = (double*)malloc(n * sizeof(double));
    y = (double*)malloc(n * sizeof(double));
    x[0] = 1.0;
    x[1] = 0.7;
    x[2] = 0.4;
    x[3] = 0.1;
    x[4] = -0.2;

    y[0] = 2.5;
    y[1] = 3.7;
    y[2] = 4.2;
    y[3] = 2.0;
    y[4] = 0.0;

    cout << "x = { ";
    for (int i = 0; i < n; i++)
      cout << x[i] << " ";
    cout << "}\ny = { ";
    for (int i = 0; i < n; i++)
      cout << y[i] << " ";
    cout << "}";
    
  } else {
    cout << "количество уловых точек: ";
    cin >> n;
    x = (double*)malloc(n * sizeof(double));
    y = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
      cout << "x[" << i << "] = ";
      cin >> x[i];
      cout << "y[" << i << "] = ";
      cin >> y[i];
      cout << endl;
    }
  }

  solve(x, y, n);

  return 0;
}
