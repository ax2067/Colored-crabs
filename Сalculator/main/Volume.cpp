#include "Volume.h"
using namespace std;

void Volume()
{
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
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			cout << "Введите длину основания: " << endl;
			cin >> length;
			cout << "Введите ширину основания: " << endl;
			cin >> width;
			cout << "Введите высоту параллелепипеда: " << endl;
			cin >> height;
			volume = length * width * height;
			cout << "Объём параллелепипеда = " << volume << endl;
			break;
		case 2:
			cout << "Введите высоту пирамиды: " << endl;
			cin >> height;
			cout << "Введите площадь основания: " << endl;
			cin >> square;
			volume = height * square / 3;
			cout << "Объём пирамиды = " << volume << endl;
			break;
		case 3:
			cout << "Введите высоту пирамиды: " << endl;
			cin >> height;
			cout << "Введите большего площадь основания: " << endl;
			cin >> square;
			cout << "Введите меньшего площадь основания: " << endl;
			cin >> square1;
			if (square < square1)
				cout << "Некорректные данные!" << endl;
			else {
				volume = (height * (square + square1 + sqrt(square * square1))) / 3;
				cout << "Объём усечённой пирамиды = " << volume << endl;
			}
			break;
		case 4:
			cout << "Введите радиус шара: " << endl;
			cin >> radius;
			volume = (4 / 3) * pi * pow(radius, 3);
			cout << "Объём шара = " << volume << endl;
			break;
		case 5:
			cout << "Введите высоту конуса: " << endl;
			cin >> height;
			cout << "Введите площадь основания конуса: " << endl;
			cin >> square;
			volume = height * square / 3;
			cout << "Объём конуса = " << volume << endl;
			break;
		case 6:
			cout << "Введите высоту конуса: " << endl;
			cin >> height;
			cout << "Введите радиус меньшего основания конуса: " << endl;
			cin >> radius1;
			cout << "Введите радиус большего основания конуса: " << endl;
			cin >> radius;
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
}