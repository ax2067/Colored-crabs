#include "matrix2.h"
using namespace std;

void matrix2() {
	int row = 2, col = 2;
	int i, j;
	int** a = new int* [row];
	for (i = 0; i < row; i++)
		a[i] = new int[col];
	printf("Введите элемент матрицы\n");
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			printf("M[");
			printf("%d", i + 1);
			printf("]");
			printf("[");
			printf("%d", j + 1);
			printf("]: ");
			cin >> a[i][j];
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
		printf("3 - найти обратную матрицу\n");
		printf("4 - выход\n");
		cin >> operation;
		determinant = a[0][0] * a[1][1] - a[0][1] * a[1][0];
		switch (operation)
		{
		case 1:
			printf("\nОпределитель исходной матрицы: ");
			printf("%d\n", determinant);
			break;
		case 2:
			if (determinant)
				printf("\n Ранг матрицы равен 2!\n ");
			else if (a[0][0] || a[0][1] || a[1][0] || a[1][1])
				printf("\n Ранг матрицы равен 1!\n ");
			else
				printf("\n Это нулевая матрица!");
			break;
		case 3:
			float delta;
			delta = 1 / (float)determinant;
			if (determinant) {
				float min1, min2, min3, min4;
				min1 = a[1][1];
				min2 = -a[1][0];
				min3 = -a[0][1];
				min4 = a[0][0];
				int trow = 2, tcol = 2;
				printf("\nОбратная матрица: \n");
				float b[3][3];
				b[0][0] = delta * min1;
				b[1][0] = delta * min2;
				b[0][1] = delta * min3;
				b[1][1] = delta * min4;
				for (i = 0; i < trow; i++)
				{
					for (j = 0; j < tcol; j++)
						cout << setw(9) << b[i][j] << "  ";
					cout << endl;
				}
			}
			else
				printf("\n У этой матрицы не будет обратной, т.к. её определитель равен 0!\n ");
			break;
		case 4: break;
		default:printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}
	} while (operation != 4);
}