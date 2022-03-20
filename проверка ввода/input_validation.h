 
#include <iostream>

#define SYMB_LEN_DOUBLE 11

using namespace std;

double read_double() {
    // будущая строка
    char *char_str;
    int len;

    // словарь
    char symb[SYMB_LEN_DOUBLE] = "1234567890";

    int i, j;

    // флаг состояния
    bool ok = false;
    
    // флаг на существование точки
    bool dot = false;

    bool minus = false;

    while (true) {
        // возвращаем все флаги в исходное состояние
        ok = false;
        dot = false;
        minus = false;

        // читаем строку
        char_str = get_string(&len);

        // проходимся по каждой бекве строки
        for (i = 0; i < len; i++) {
            switch (char_str[i]) {
                // проверка на точку
                case('.'):
                    if (dot) 
                        ok = false;
                    else {
                        ok = true;
                        dot = true;
                    }
                    break;

                // проверка на знак минуса
                case('-'):
                    if (minus)
                        ok = false;
                    else {
                        ok = true;
                        minus = true;
                    }
                    break;

                // проверка на остальные символы
                default:
                    ok = false;
                    // проходимся по каждому символу словаря
                    for (j = 0; j < SYMB_LEN_DOUBLE; j++) {

                        // стравниваем символ со словарём
                        if (char_str[i] == symb[j]){
                            // если нашли символ в словаре, 
                            // то останавливаем цикл со словарём
                            ok = true;
                            break;
                        }
                    }

                    break;
            }
            
            // если мы не нашли символ, пишем ошибку
            if (!ok) {
                cout << "Вы ввели не число.\n";
                break;
            }
        }

        // если небыло ошибок, то останавливаем бесконечный цикл
        if (ok)
            break;

    }

    // переводим и возвращаем значение
    return atof(char_str);
}