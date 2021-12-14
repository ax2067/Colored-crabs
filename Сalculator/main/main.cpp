#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	char quit;
	while (quit != 'n')
	{
		setlocale(LC_ALL, "RUS");
		printf("Привет, привет!Это калькулятор для студентов.Он упростит жизнь студентов с диком мире математики!\n");
		Sleep(5000);
		printf("\033c");
		printf("Чтобы выбрать желаемое действие - введите соответствующее ему число.\n");
		printf("1 - Операции над числами.\n");
		printf("2 - Конвертация в двоичный/шестнадцатиричный код.\n");
		printf("3 - Работы с матрицами.\n");
		printf("4 - Операции с функциями и нахождение площадей различных фигур.\n");
		printf("Любое другое значение - Выход из программы.\n");
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			printf("\033c");
			operations(); break;
		case 2:
			printf("\033c");
			convertations(); break;
		case 3:
			printf("\033c");
			matrix(); break;
		case 4:
			printf("\033c");
			functions(); break;
		default:
			break;
		}
		cout << "\n\n\n";
		printf("Введите 'n' чтобы закончить работу проекта или любой символ, чтобы продолжить.\n\n");
		cin >> quit;
	}
}