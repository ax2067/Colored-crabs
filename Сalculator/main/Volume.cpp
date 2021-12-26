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
		printf("����� �����...\n");
		printf("1 - ...���������������\n");
		printf("2 - ...��������\n");
		printf("3 - ...��������� ��������\n");
		printf("4 - ...����\n");
		printf("5 - ...������\n");
		printf("6 - ...���������� ������\n");
		printf("7 - �����\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			cout << "������� ����� ���������: " << endl;
			cin >> length;
			cout << "������� ������ ���������: " << endl;
			cin >> width;
			cout << "������� ������ ���������������: " << endl;
			cin >> height;
			volume = length * width * height;
			cout << "����� ��������������� = " << volume << endl;
			break;
		case 2:
			cout << "������� ������ ��������: " << endl;
			cin >> height;
			cout << "������� ������� ���������: " << endl;
			cin >> square;
			volume = height * square / 3;
			cout << "����� �������� = " << volume << endl;
			break;
		case 3:
			cout << "������� ������ ��������: " << endl;
			cin >> height;
			cout << "������� �������� ������� ���������: " << endl;
			cin >> square;
			cout << "������� �������� ������� ���������: " << endl;
			cin >> square1;
			if (square < square1)
				cout << "������������ ������!" << endl;
			else {
				volume = (height * (square + square1 + sqrt(square * square1))) / 3;
				cout << "����� ��������� �������� = " << volume << endl;
			}
			break;
		case 4:
			cout << "������� ������ ����: " << endl;
			cin >> radius;
			volume = (4 / 3) * pi * pow(radius, 3);
			cout << "����� ���� = " << volume << endl;
			break;
		case 5:
			cout << "������� ������ ������: " << endl;
			cin >> height;
			cout << "������� ������� ��������� ������: " << endl;
			cin >> square;
			volume = height * square / 3;
			cout << "����� ������ = " << volume << endl;
			break;
		case 6:
			cout << "������� ������ ������: " << endl;
			cin >> height;
			cout << "������� ������ �������� ��������� ������: " << endl;
			cin >> radius1;
			cout << "������� ������ �������� ��������� ������: " << endl;
			cin >> radius;
			if (radius < radius1)
				cout << "������������ ������!" << endl;
			else {
				volume = (pi * height * (pow(radius, 2) + radius * radius1 + pow(radius1, 2))) / 3;
				cout << "����� ���������� ������ = " << volume << endl;
			}
			break;
		case 7:
			cout << "������ ��������. ��� ����������� ������� ����� ������";
			break;
		default:
			if (switch_on > 7)
			{
				cout << "������� ���������� �������" << endl;
			}
			break;
		}
	} while (switch_on != 7);
}