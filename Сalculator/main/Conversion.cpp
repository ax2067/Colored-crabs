#include "Conversion.h"
using namespace std;

void Conversion()
{
	setlocale(LC_CTYPE, "Russian");
	int number, operation;
	char tmp[33];
	do
	{
		printf("��������, � ����� ������� ��������� ������ ��������: \n");
		printf("1 - ������������\n");
		printf("2 - ������������\n");
		printf("3 - �����������������\n");
		printf("4 - �����\n");
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
			cout << "������ ��������. ��� ����������� ������� ����� ������." << endl;
			break;
		default:
			if (operation > 4)
			{
				cout << "������� ���������� �������" << endl;
			}
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (operation != 4);
}