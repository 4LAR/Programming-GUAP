
#include <iostream>
using namespace std;

class D1: public B1, protected B2 {

};

class D2: protected D1 {

};


/* Основные классы */
class D3: private D2 {

};

class D4: public D2 {

};
