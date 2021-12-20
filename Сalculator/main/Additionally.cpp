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
	setlocale(LC_ALL, "RUS");
    char letmeout;
    int x, y;
    do {
        cout << "Введите последовательно 2 числа: " << endl;
        cin >> x >> y;
        cout << "НОД этих чисел = " << NOD(x, y) << endl;
        cout << "НОК этих чисел = " << NOK(x, y) << endl;
        cout << "Чтобы повторить - введите любой символ. Чтобы закончить - введите '0'" << endl;
        cin >> letmeout;
        printf("\033c");
    } while (letmeout != '0');
    return 0;
}