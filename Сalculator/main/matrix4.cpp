#include "matrix4.h"
using namespace std;// ------- ����������� �������� ����������� ���� ����� �������� printf("\033c");

int matrix4() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ElementValue[SIZE];
	int row = 4, col = 4;
	int i, j;
	float k;
	int** a = new int* [row];
	for (i = 0; i < row; i++)
		a[i] = new int[col];
	printf("������� ������� �������\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
		{
			printf("M[");
			printf("%d", i + 1);
			printf("]");
			printf("[");
			printf("%d", j + 1);
			printf("]: ");
						cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("������ - ������ ������������ ������....\n");
				system("pause");
				return 0;
			}
			else  a[i][j] = atoi(ElementValue);
		}
	}
	printf("\n�������� �������: \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			cout << setw(4) << a[i][j] << "  ";
		cout << endl;
	}
	int operation;
	int determinant;
	do {
		printf("��� ����������: \n");
		printf("1 - ����� ������������ �������\n");
		printf("2 - ����� ���� �������\n");
		printf("3 - �������� ������\n");
		printf("4 - �������� ������\n");
		printf("5 - ��������� ������� �� �����\n");
		printf("6 - �����\n");
		cin >> operation;
		determinant = a[0][0] * ((a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[2][1] * a[3][2] * a[1][3]) - (a[1][3] * a[2][2] * a[3][1] + a[3][2] * a[2][3] * a[1][1] + a[2][1] * a[3][3] * a[1][2])) - a[0][1] * ((a[1][0] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][0] + a[2][0] * a[3][2] * a[1][3]) - (a[1][3] * a[2][2] * a[3][0] + a[3][3] * a[2][0] * a[1][2] + a[2][3] * a[3][2] * a[1][0])) + a[0][2] * ((a[1][0] * a[2][1] * a[3][3] + a[1][1] * a[2][3] * a[3][0] + a[2][0] * a[3][1] * a[1][3]) - (a[1][3] * a[2][1] * a[3][0] + a[3][3] * a[2][0] * a[1][1] + a[2][3] * a[3][1] * a[1][0])) - a[0][3] * ((a[1][0] * a[2][1] * a[3][2] + a[1][1] * a[2][2] * a[3][0] + a[2][0] * a[3][1] * a[1][2]) - (a[1][2] * a[2][1] * a[3][0] + a[3][2] * a[2][0] * a[1][1] + a[2][2] * a[3][1] * a[1][0]));
		switch (operation)
		{
		case 1:
			printf("\033c");
			printf("\n������������ �������� �������: ");
			printf("%d\n", determinant);
			break;
		case 2:
			printf("\033c");
			int min1, min2, min3, min4;
			min1 = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[1][0] * a[0][2] * a[2][1] - (a[0][2] * a[1][1] * a[2][0] + a[0][1] * a[1][0] * a[2][2] + a[0][0] * a[1][2] * a[2][1]);
			min2 = a[0][1] * a[1][2] * a[2][3] + a[0][2] * a[1][3] * a[2][1] + a[1][1] * a[0][3] * a[2][2] - (a[0][3] * a[1][2] * a[2][1] + a[0][2] * a[1][1] * a[2][3] + a[0][1] * a[1][3] * a[2][2]);
			min3 = a[1][0] * a[2][1] * a[3][2] + a[1][1] * a[2][2] * a[3][0] + a[2][0] * a[1][2] * a[3][1] - (a[1][2] * a[2][1] * a[3][0] + a[1][1] * a[2][0] * a[3][2] + a[1][0] * a[2][2] * a[3][1]);
			min4 = a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[2][1] * a[1][3] * a[3][2] - (a[1][3] * a[2][2] * a[3][1] + a[1][2] * a[2][1] * a[3][3] + a[1][1] * a[2][3] * a[3][2]);
			int minor1, minor2, minor3, minor4, minor5, minor6, minor7, minor8, minor9;
			minor1 = a[0][0] * a[1][1] - a[0][1] * a[1][0];
			minor2 = a[0][1] * a[1][2] - a[0][2] * a[1][1];
			minor3 = a[0][2] * a[1][3] - a[0][3] * a[1][2];
			minor4 = a[1][0] * a[2][1] - a[1][1] * a[2][0];
			minor5 = a[1][1] * a[2][2] - a[1][2] * a[2][1];
			minor6 = a[1][2] * a[2][3] - a[1][3] * a[2][2];
			minor7 = a[2][0] * a[3][1] - a[2][1] * a[3][0];
			minor8 = a[2][1] * a[3][2] - a[2][2] * a[3][1];
			minor9 = a[2][2] * a[3][3] - a[2][3] * a[3][2];
			if (determinant)
				printf("\n ���� ������� ����� 4!\n ");
			else if (min1 || min2 || min3 || min4)
				printf("\n ���� ������� ����� 3!\n ");
			else if (minor1 || minor2 || minor3 || minor4 || minor5 || minor6 || minor7 || minor8 || minor9)
				printf("\n ���� ������� ����� 2!\n ");
			else if (a[0][0] || a[0][1] || a[0][2] || a[0][3] || a[1][0] || a[1][1] || a[1][2] || a[1][3] || a[2][0] || a[2][1] || a[2][2] || a[2][3] || a[3][0] || a[3][1] || a[3][2] || a[3][3])
				printf("\n ���� ������� ����� 1!\n ");
			else
				printf("\n ��� ������� �������!");
			break;
		case 3:
			printf("\033c");
			int b[4][4];
			printf("������� ������� �������, ������� ���������� ������� � ��������\n");
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
				{
					printf("M[");
					printf("%d", i + 1);
					printf("]");
					printf("[");
					printf("%d", j + 1);
					printf("]: ");
					cin >> b[i][j];
				}
			printf("\n�������� �������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << b[i][j] << "  ";
				cout << endl;
			}
			printf("\n�������� �������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			int c[3][3];
			printf("��������� ��������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = b[i][j] + a[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			}
		case 4: 
			printf("\033c");
			printf("������� ������� �������, ������� ���������� ������ �� ��������\n");
			for (i = 0; i < row; i++)
				for (j = 0; j < col; j++)
				{
					printf("M[");
					printf("%d", i + 1);
					printf("]");
					printf("[");
					printf("%d", j + 1);
					printf("]: ");
					cin >> b[i][j];
				}
			printf("\n�������� �������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << b[i][j] << "  ";
				cout << endl;
			}
			printf("\n�������� �������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			printf("��������� ��������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = a[i][j] - b[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			}break;
		case 5: 
			printf("\033c");
			printf("������� �����, ������� ���� �������� �� �������� �������: \n");
			cin >> k;
			printf("\n�������� �������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			printf("��������� ������������: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = k * a[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			}break;
		case 6: printf("\033c");
			cout << "������ ��������. ��� ����������� ������� ����� ������." << endl;
			break;
		default: printf("\033c"); printf("������������ �������. ��������, ����������, ��� ���!\n");
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (operation != 6);
	return 0;
}
