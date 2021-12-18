#include "Matrix.h"

int Matrix() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ElementValue[SIZE];
	setlocale(LC_CTYPE, "Russian");
	int answer;
	printf("Здравствуйте! Вы попали в раздел с матрицами!\n");
	do {

		printf("Работу с какой матрицей вы хотите осуществить?\n");
		printf("1 - матрица 2x2\n");
		printf("2 - матрица 3x3\n");
		printf("3 - матрица 4x4\n");
		printf("4 - выход\n");
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
			printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}

	} while (answer != 4);
	return 0;
}

