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
        cout << "������� ��������������� 2 �����: " << endl;
        cin >> x >> y;
        cout << "��� ���� ����� = " << NOD(x, y) << endl;
        cout << "��� ���� ����� = " << NOK(x, y) << endl;
        cout << "����� ��������� - ������� ����� ������. ����� ��������� - ������� '0'" << endl;
        cin >> letmeout;
        printf("\033c");
    } while (letmeout != '0');
    return 0;
}