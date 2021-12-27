#include "Additionally.h"
using namespace std;

int NOD(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}

int NOK(int a, int b)
{
    return ((a*b) / NOD(a, b));
}
int Additionally() {
    char ElementValue[SIZE];
	setlocale(LC_ALL, "RUS");
    char letmeout;
    int x, y;
    do {
        cout << "Введите последовательно 2 числа: " << endl;
        cin >> ElementValue;
        if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
            printf("Ошибка - введен неправильный символ....\n");
            system("pause");
            return 0;
        }
        else  x = atoi(ElementValue);
        cin >> ElementValue;
        if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
            printf("Ошибка - введен неправильный символ....\n");
            system("pause");
            return 0;
        }
        else  y = atoi(ElementValue);
        cout << "НОД этих чисел = " << NOD(x, y) << endl;
        cout << "НОК этих чисел = " << NOK(x, y) << endl;
        cout << "Чтобы повторить - введите любой символ. Чтобы закончить - введите '0'" << endl;
        cin >> ElementValue;
        if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
            printf("Ошибка - введен неправильный символ....\n");
            system("pause");
            return 0;
        }
        else  letmeout = atoi(ElementValue);
        printf("\033c");
    } while (letmeout != '0');
    return 0;
}