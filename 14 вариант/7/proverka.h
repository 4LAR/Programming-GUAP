#include <iostream>
#include <cmath>
using namespace std;


bool is__int(const char* S) { /*ФУНКЦИЯ ПРОВЕРКИ ВВЕДЁННОЙ СТРОКИ НА ЧИСЛОВОЙ ХАРАКТЕР*/
    const char* temp = "0123456789";
    unsigned point_count = 0;
    //Целочисленный тип без знака
    for (int i = 0; i < strlen(S); i++)
    {				//strlen() возвращает длину строки, оканчивающейся нулевым символом, на которую указывает str
        if ((i > 0) && (S[i] == '+' || S[i] == '-'))
            return false;
        if (S[i] == '.')
        {
            point_count++;
            if (point_count > 1) return false;
        }
        if (!strchr(temp, S[i])) return false;// Возвращает указатель
        //Таким образом, он также может быть найден для получения указателя на конец строки.
    }
    return true;

}