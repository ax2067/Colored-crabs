#include "matrix4.h"
using namespace std;// ------- просмотреть очищение консольного окна после операции printf("\033c");

int matrix4() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ElementValue[SIZE];
	int row = 4, col = 4;
	int i, j;
	int** a = new int* [row];
	for (i = 0; i < row; i++)
		a[i] = new int[col];
	printf("Введите элемент матрицы\n");
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++)
		{
			printf("M[");
			printf("%d", i + 1);
			printf("]");
			printf("[");
			printf("%d", j + 1);
			printf("]: ");
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  a[i][j] = atoi(ElementValue);
		}
	}
	printf("\nИсходная матрица: \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			cout << setw(4) << a[i][j] << "  ";
		cout << endl;
	}
	int operation;
	int determinant;
	do {
		printf("Вам необходимо: \n");
		printf("1 - найти определитель матрицы\n");
		printf("2 - найти ранг матрицы\n");
		printf("3 - выход\n");
		cin >> operation;
		determinant = a[0][0] * ((a[1][1] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][1] + a[2][1] * a[3][2] * a[1][3]) - (a[1][3] * a[2][2] * a[3][1] + a[3][2] * a[2][3] * a[1][1] + a[2][1] * a[3][3] * a[1][2])) - a[0][1] * ((a[1][0] * a[2][2] * a[3][3] + a[1][2] * a[2][3] * a[3][0] + a[2][0] * a[3][2] * a[1][3]) - (a[1][3] * a[2][2] * a[3][0] + a[3][3] * a[2][0] * a[1][2] + a[2][3] * a[3][2] * a[1][0])) + a[0][2] * ((a[1][0] * a[2][1] * a[3][3] + a[1][1] * a[2][3] * a[3][0] + a[2][0] * a[3][1] * a[1][3]) - (a[1][3] * a[2][1] * a[3][0] + a[3][3] * a[2][0] * a[1][1] + a[2][3] * a[3][1] * a[1][0])) - a[0][3] * ((a[1][0] * a[2][1] * a[3][2] + a[1][1] * a[2][2] * a[3][0] + a[2][0] * a[3][1] * a[1][2]) - (a[1][2] * a[2][1] * a[3][0] + a[3][2] * a[2][0] * a[1][1] + a[2][2] * a[3][1] * a[1][0]));
		switch (operation)
		{
		case 1:
			printf("\nОпределитель исходной матрицы: ");
			printf("%d\n", determinant);
			break;
		case 2:
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
				printf("\n Ранг матрицы равен 4!\n ");
			else if (min1 || min2 || min3 || min4)
				printf("\n Ранг матрицы равен 3!\n ");
			else if (minor1 || minor2 || minor3 || minor4 || minor5 || minor6 || minor7 || minor8 || minor9)
				printf("\n Ранг матрицы равен 2!\n ");
			else if (a[0][0] || a[0][1] || a[0][2] || a[0][3] || a[1][0] || a[1][1] || a[1][2] || a[1][3] || a[2][0] || a[2][1] || a[2][2] || a[2][3] || a[3][0] || a[3][1] || a[3][2] || a[3][3])
				printf("\n Ранг матрицы равен 1!\n ");
			else
				printf("\n Это нулевая матрица!");
			break;
		case 3: break;
		default:printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}
	} while (operation != 3);
	return 0;
}
