/*
  19 вариант
  A = 7 2 6 7
      4 9 5 5
      2 3 4 9
      1 5 6 9
  B = 3 2 0 2
*/

#include <iostream>
using namespace std;

int n, i, j, k;
double d, s;

int main() {
  // смена кодировки
  system("chcp 65001");

  cout << "Размер матрицы A: ";
  cin >> n;

  double ** a = new double * [n];
  for (i = 0; i <= n; i++)
    a[i] = new double[n];
  double ** a1 = new double * [n];
  for (i = 0; i <= n; i++)
    a1[i] = new double[n];
  double * b = new double[n];
  double * x = new double[n];

  cout << "Ввод матрицы A" << endl;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cout << "a[" << i << "][" << j << "]= ";
      cin >> a[i][j];
      a1[i][j] = a[i][j];
    }
  }
  cout << "Ввод матрицы B" << endl;
  for (i = 1; i <= n; i++) {
    cout << "b[ " << i << "]= ";
    cin >> b[i];
  }

  for (k = 1; k <= n; k++) {
    for (j = k + 1; j <= n; j++) {
      d = a[j][k] / a[k][k]; // формула (1)
      for (i = k; i <= n; i++) {
        a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
      }
      b[j] = b[j] - d * b[k]; // формула (3)
    }
  }
  for (k = n; k >= 1; k--) {
    d = 0;
    for (j = k + 1; j <= n; j++) {
      s = a[k][j] * x[j]; // формула (4)
      d = d + s; // формула (4)
    }
    x[k] = (b[k] - d) / a[k][k]; // формула (4)
  }

  cout << "Корни системы: " << endl;
  for (i = 1; i <= n; i++)
    cout << "x[" << i << "]=" << x[i] << " " << endl;
  return 0;
}
