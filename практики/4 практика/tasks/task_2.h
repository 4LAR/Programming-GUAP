#include <iostream>
using namespace std;

void pifagor(int i, int j, int k) {
  if (i*i+j*j==k*k) cout << "{ " << i << ";" << j << ";" << k << "}" << endl;
  pifagor(i++, j, k);
  pifagor(i, j++, k);
  pifagor(i, j, k++);
}
