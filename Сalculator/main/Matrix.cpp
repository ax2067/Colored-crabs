#include "Matrix.h"

int Matrix() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ElementValue[SIZE];
	setlocale(LC_CTYPE, "Russian");
	int answer;
	printf("������������! �� ������ � ������ � ���������!\n");
	do {

		printf("������ � ����� �������� �� ������ �����������?\n");
		printf("1 - ������� 2x2\n");
		printf("2 - ������� 3x3\n");
		printf("3 - ������� 4x4\n");
		printf("4 - �����\n");
		cin >> answer;
		switch (answer)
		{
		case 1: printf("\033c");
			matrix2(); break;
		case 2: printf("\033c");
			matrix3(); break;
		case 3: printf("\033c");
			matrix4(); break;
		case 4: printf("\033c"); break;
		default: printf("\033c");
			printf("������������ �������. ��������, ����������, ��� ���!\n");
		}

	} while (answer != 4);
	return 0;
}

