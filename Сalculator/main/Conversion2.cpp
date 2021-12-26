#include "Conversion2.h"
using namespace std;

void Conversion2()
{
	int switch_on, number;
	char tmp[33];
	do {
		printf("Вы работаете в восьмеричной системе счисления\n");
		printf("Выполнить перевод в...\n");
		printf("1 - двоичную систему счисления\n");
		printf("2 - десятичную систему счисления\n");
		printf("3 - шестнадцатеричную систему счисления\n");
		printf("4 - Выход\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			printf("Введите число:\n");
			cin >> oct >> number;
			_itoa_s(number, tmp, 2);
			cout << "Число в двоичной системе счисления: " << tmp << endl;
			break;
		case 2:
			printf("Введите число:\n");
			cin >> oct >> number;
			cout << "Число в десятеричной системе счисления: " << dec << number << endl;
			break;
		case 3:
			printf("Введите число:\n");
			cin >> oct >> number;
			cout << "Число в шестнадцатеричной системе счисления: " << hex << number << endl;
			break;
		case 4:
			cout << "Работа окончена. Для продолжения нажмите любую кнопку." << endl;
			break;
		default:
			if (switch_on > 4)
			{
				cout << "Введите корректный вариант" << endl;
			}
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (switch_on != 4);
}
