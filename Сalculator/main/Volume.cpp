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
		printf("����� �����...\n");
		printf("1 - ...���������������\n");
		printf("2 - ...��������\n");
		printf("3 - ...��������� ��������\n");
		printf("4 - ...����\n");
		printf("5 - ...������\n");
		printf("6 - ...���������� ������\n");
		printf("7 - �����\n");
		cin >> ElementValue;
		if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
			printf("������ - ������ ������������ ������....\n");
			system("pause");
			return 0;
		}
		else  switch_on = atoi(ElementValue);
		switch (switch_on)
		{
		case 1:
			cout << "��������� ��� �����: ����� ���������, ������ ���������, ������ ��������������� " << endl;
			cout << "������� ����� ���������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  length = atoi(ElementValue);
			cout << "������� ������ ���������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  width = atoi(ElementValue);
			cout << "������� ������ ���������������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			volume = length * width * height;
			cout << "����� ��������������� = " << volume << endl;
			break;
		case 2:
			cout << "��������� ��� �����: ������ ��������, ������� ��������� " << endl;
			cout << "������� ������ ��������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "������� ������� ���������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			volume = height * square / 3;
			cout << "����� �������� = " << volume << endl;
			break;
		case 3:
			cout << "��������� ��� �����: ������ ��������, ������� �������� � �������� ��������� " << endl;
			cout << "������� ������ ��������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "������� �������� ������� ���������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			cout << "������� �������� ������� ���������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  square1 = atoi(ElementValue);
			if (square < square1)
				cout << "������������ ������!" << endl;
			else {
				volume = (height * (square + square1 + sqrt(square * square1))) / 3;
				cout << "����� ��������� �������� = " << volume << endl;
			}
			break;
		case 4:
			cout << "��������� ��� �����: ������" << endl;
			cout << "������� ������ ����: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  radius = atoi(ElementValue);
			volume = (4 / 3) * pi * pow(radius, 3);
			cout << "����� ���� = " << volume << endl;
			break;
		case 5:
			cout << "��������� ��� �����: ������ ������, ������� ��������� ������" << endl;
			cout << "������� ������ ������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "������� ������� ��������� ������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  square = atoi(ElementValue);
			volume = height * square / 3;
			cout << "����� ������ = " << volume << endl;
			break;
		case 6:
			cout << "��������� ��� �����: ������ ������, ������ �������� � �������� ��������� ������" << endl;
			cout << "������� ������ ������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  height = atoi(ElementValue);
			cout << "������� ������ �������� ��������� ������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  radius1 = atoi(ElementValue);
			cout << "������� ������ �������� ��������� ������: " << endl;
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  radius = atoi(ElementValue);
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
	return 0;
}