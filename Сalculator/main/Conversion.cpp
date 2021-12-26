#include "Conversion.h"
using namespace std;

void Conversion()
{
	setlocale(LC_CTYPE, "Russian");
	int number, operation;
	char tmp[33];
	do
	{
		printf("Выберите, в какой системе счисления будете работать: \n");
		printf("1 - Десятеричной\n");
		printf("2 - Восьмеричной\n");
		printf("3 - Шестнадцатеричной\n");
		printf("4 - Выход\n");
		cin >> operation;
		switch (operation)
		{
		case 1:
			Conversion1();
			break;
		case 2:
			Conversion2();
			break;
		case 3:
			Conversion3();
			break;
		case 4:
			cout << "Работа окончена. Для продолжения нажмите любую кнопку." << endl;
			break;
		default:
			if (operation > 4)
			{
				cout << "Введите корректный вариант" << endl;
			}
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (operation != 4);
}