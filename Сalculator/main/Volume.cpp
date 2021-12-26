#include "Volume.h"
using namespace std;

int Volume()
{
	char ElementValue[SIZE];
	int switch_on;
	float height, width, length, volume, square, radius, radius1, square1;
	const float pi = 3.1415926;
	do
	{
		setlocale(LC_CTYPE, "Russian");
		printf("Найти объём...\n");
		printf("1 - ...параллелепипеда\n");
		printf("2 - ...пирамиды\n");
		printf("3 - ...усечённой пирамиды\n");
		printf("4 - ...шара\n");
		printf("5 - ...конуса\n");
		printf("6 - ...усечённого конуса\n");
		printf("7 - Выход\n");
		cin >> ElementValue;
		if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
			printf("Ошибка - введен неправильный символ....\n");
			system("pause");
			return 0;
		}
		else  switch_on = atoi(ElementValue);
		switch (switch_on)
		{
		case 1:
			cout << "Параметры для ввода: длина основания, ширина основания, высота параллелепипеда " << endl;
			cout << "Введите длину основания: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  length = atoi(ElementValue);
			cout << "Введите ширину основания: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  width = atoi(ElementValue);
			cout << "Введите высоту параллелепипеда: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			volume = length * width * height;
			cout << "Объём параллелепипеда = " << volume << endl;
			break;
		case 2:
			cout << "Параметры для ввода: высота пирамиды, площадь основания " << endl;
			cout << "Введите высоту пирамиды: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "Введите площадь основания: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			volume = height * square / 3;
			cout << "Объём пирамиды = " << volume << endl;
			break;
		case 3:
			cout << "Параметры для ввода: высота пирамиды, площадь большего и меньшего основания " << endl;
			cout << "Введите высоту пирамиды: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "Введите большего площадь основания: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			cout << "Введите меньшего площадь основания: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  square1 = atoi(ElementValue);
			if (square < square1)
				cout << "Некорректные данные!" << endl;
			else {
				volume = (height * (square + square1 + sqrt(square * square1))) / 3;
				cout << "Объём усечённой пирамиды = " << volume << endl;
			}
			break;
		case 4:
			cout << "Параметры для ввода: радиус" << endl;
			cout << "Введите радиус шара: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  radius = atoi(ElementValue);
			volume = (4 / 3) * pi * pow(radius, 3);
			cout << "Объём шара = " << volume << endl;
			break;
		case 5:
			cout << "Параметры для ввода: высота конуса, площадь основания конуса" << endl;
			cout << "Введите высоту конуса: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "Введите площадь основания конуса: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			volume = height * square / 3;
			cout << "Объём конуса = " << volume << endl;
			break;
		case 6:
			cout << "Параметры для ввода: высота конуса, радиус большего и меньшего основания конуса" << endl;
			cout << "Введите высоту конуса: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "Введите радиус меньшего основания конуса: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  radius1 = atoi(ElementValue);
			cout << "Введите радиус большего основания конуса: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  radius = atoi(ElementValue);
			if (radius < radius1)
				cout << "Некорректные данные!" << endl;
			else {
				volume = (pi * height * (pow(radius, 2) + radius * radius1 + pow(radius1, 2))) / 3;
				cout << "Объём усечённого конуса = " << volume << endl;
			}
			break;
		case 7:
			cout << "Работа окончена. Для продолжения нажмите любую кнопку";
			break;
		default:
			if (switch_on > 7)
			{
				cout << "Введите корректный вариант" << endl;
			}
			break;
		}
	} while (switch_on != 7);
	return 0;
}