#include "matrix3.h"
using namespace std;

int matrix3() {
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	char ElementValue[SIZE];
	int row = 3, col = 3;
	int i, j;
	float k;
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
			cin >> ElementValue;
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
	int** ptr = a;
	int operation;
	int determinant;
	do {
		printf("Вам необходимо: \n");
		printf("1 - найти определитель матрицы\n");
		printf("2 - найти ранг матрицы\n");
		printf("3 - найти обратную матрицу\n");
		printf("4 - сложение матриц\n");
		printf("5 - разность матриц\n");
		printf("6 - умножение матрицы на число\n");
		printf("7 - выход\n");
		cin >> ElementValue;
		if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
			printf("Ошибка - введен неправильный символ....\n");
			system("pause");
			return 0;
		}
		else operation = atoi(ElementValue);
		switch (operation)
		{
		case 1:
			printf("\033c");
			printf("\nОпределитель исходной матрицы: ");
			a = ptr;
			determinant = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
			printf("%d\n", determinant);
			break;
		case 2:
			printf("\033c");
			int minor1, minor2, minor3;
			minor1 = a[0][0] * a[1][1] - a[0][1] * a[1][0];
			minor2 = a[0][0] * a[1][2] - a[0][2] * a[1][0];
			minor3 = a[0][1] * a[1][2] - a[0][2] * a[1][1];
			determinant = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
			if (determinant)
				printf("\n Ранг матрицы равен 3!\n ");
			else if (minor1 || minor2 || minor3)
				printf("\n Ранг матрицы равен 2!\n ");
			else if (a[0][0] || a[0][1] || a[0][2] || a[1][0] || a[1][1] || a[1][2] || a[2][0] || a[2][1] || a[2][2])
				printf("\n Ранг матрицы равен 1!\n ");
			else
				printf("\n Это нулевая матрица!");
			break;
		case 3:
			printf("\033c");
			determinant = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
			float delta;
			delta = 1 / (float)determinant;
			if (determinant) {
				int min1, min2, min3, min4, min5, min6, min7, min8, min9;
				min1 = a[1][1] * a[2][2] - a[1][2] * a[2][1];
				min2 = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]);
				min3 = a[1][0] * a[2][1] - a[1][1] * a[2][0];
				min4 = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]);
				min5 = a[0][0] * a[2][2] - a[0][2] * a[2][0];
				min6 = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]);
				min7 = a[0][1] * a[1][2] - a[0][2] * a[1][1];
				min8 = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]);
				min9 = a[0][0] * a[1][1] - a[0][1] * a[1][0];
				int trow = 3, tcol = 3;
				printf("\nОбратная матрица: \n");
				float b[3][3];
				b[0][0] = delta * min1;
				b[1][0] = delta * min2;
				b[2][0] = delta * min3;
				b[0][1] = delta * min4;
				b[1][1] = delta * min5;
				b[2][1] = delta * min6;
				b[0][2] = delta * min7;
				b[1][2] = delta * min8;
				b[2][2] = delta * min9;
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
		case 4:
			printf("\033c");
			int b[3][3];
			printf("Введите элемент матрицы, которую необходимо сложить с исходной\n");
			for (i = 0; i < row; i++)
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
						printf("Ошибка - введен неправильный символ....\n");
						system("pause");
						return 0;
					}
					else  b[i][j] = atoi(ElementValue);
				}
			printf("\nВведённая матрица: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << b[i][j] << "  ";
				cout << endl;
			}
			printf("\nИсходная матрица: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			int c[3][3];
			printf("Результат сложения: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = b[i][j] + a[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			}
			break;
		case 5:
			printf("\033c");
			printf("Введите элемент матрицы, которую необходимо отнять от исходной\n");
			for (i = 0; i < row; i++)
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
						printf("Ошибка - введен неправильный символ....\n");
						system("pause");
						return 0;
					}
					else  b[i][j] = atoi(ElementValue);
				}
			printf("\nВведённая матрица: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << b[i][j] << "  ";
				cout << endl;
			}
			printf("\nИсходная матрица: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			printf("Результат разности: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = a[i][j] - b[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			}
			break;
		case 6:
			printf("\033c");
			printf("Введите число, которое надо умножить на исходную матрицу: \n");
			cin >> ElementValue;
			if (static_cast<int>(ElementValue[0]) > 57 || static_cast<int>(ElementValue[0]) < 48) {
				printf("Ошибка - введен неправильный символ....\n");
				system("pause");
				return 0;
			}
			else  k = atoi(ElementValue);
			printf("\nИсходная матрица: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
					cout << setw(4) << a[i][j] << "  ";
				cout << endl;
			}
			printf("Результат перемножения: \n");
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++) {
					c[i][j] = k * a[i][j];
					cout << setw(4) << c[i][j] << "  ";
				}
				cout << endl;
			} break;
		case 7:
			printf("\033c");
			cout << "Работа окончена. Для продолжения нажмите любую кнопку." << endl;
			break;
		default:printf("\033c");
			printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (operation != 7);
	return 0;
}
