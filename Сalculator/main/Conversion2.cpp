#include "Conversion2.h"
using namespace std;

void Conversion2()
{
	int switch_on, number;
	char tmp[33];
	do {
		printf("�� ��������� � ������������ ������� ���������\n");
		printf("��������� ������� �...\n");
		printf("1 - �������� ������� ���������\n");
		printf("2 - ���������� ������� ���������\n");
		printf("3 - ����������������� ������� ���������\n");
		printf("4 - �����\n");
		cin >> switch_on;
		switch (switch_on)
		{
		case 1:
			printf("������� �����:\n");
			cin >> oct >> number;
			_itoa_s(number, tmp, 2);
			cout << "����� � �������� ������� ���������: " << tmp << endl;
			break;
		case 2:
			printf("������� �����:\n");
			cin >> oct >> number;
			cout << "����� � ������������ ������� ���������: " << dec << number << endl;
			break;
		case 3:
			printf("������� �����:\n");
			cin >> oct >> number;
			cout << "����� � ����������������� ������� ���������: " << hex << number << endl;
			break;
		case 4:
			cout << "������ ��������. ��� ����������� ������� ����� ������." << endl;
			break;
		default:
			if (switch_on > 4)
			{
				cout << "������� ���������� �������" << endl;
			}
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (switch_on != 4);
}
