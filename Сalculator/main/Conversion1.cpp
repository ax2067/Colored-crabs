#include "Conversion1.h"
using namespace std;

void Conversion1()
{
	int switch_on, number;
	char tmp[33];
	do {
		printf("Вы работаете в десятичной системе счисления\n");
		printf("Выполнить перевод в...\n");
		printf("1 - двоичную систему счисления\n");
		printf("2 - восьмеричную систему счисления\n");
		printf("3 - шестнадцатеричную систему счисления\n");
		printf("4 - Выход\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			printf("Введите число:\n");
			cin >> number;
			_itoa_s(number, tmp, 2);
			cout << "Число в двоичной системе счисления: " << tmp << endl;
			break;
		case 2:
			printf("Введите число:\n");
			cin >> number;
			cout << "Число в восьмеричной системе счисления: " << oct << number << endl;
			break;
		case 3:
			printf("Введите число:\n");
			cin >> number;
			cout << "Число в шестнадцатеричной системе счисления: " << hex << number << endl;
			break;
		case 4:
			cout << "Работа окончена.";
			break;
		default:
			if (switch_on > 4)
			{
				cout << "Введите корректный вариант" << endl;
			}
			break;
		}
	} while (switch_on != 4);
}