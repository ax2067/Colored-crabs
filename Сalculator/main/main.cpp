#include <iostream>
#include <ctime> 
#include <cstdlib> 
#include <iomanip>
#include <Windows.h>
#include "Matrix.h"
//#include "Operations.h"
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int way;
	printf("Привет, привет!Это калькулятор для студентов.Он упростит жизнь студентов в диком мире математики!\n");
	Sleep(5000);
	printf("\033c");
	do {

		printf("Чтобы выбрать желаемое действие - введите соответствующее ему число.\n");
		printf("1 - Операции над числами.\n");
		printf("2 - Конвертация в двоичный/шестнадцатиричный код.\n");
		printf("3 - Работы с матрицами.\n");
		printf("4 - Операции с функциями и нахождение площадей различных фигур.\n");
		printf("5 - Дополнительные операции (факториал, НОК и НОД).\n");
		printf("6 - Выход из программы.\n");
		cin >> way;
		switch (way)
		{
		case 1: printf("\033c");
/*		Operations(); */ break;//------- модуль Ксюши
		case 2: printf("\033c");
/*			Conversion();*/ break; //-------- модуль Иры
		case 3: Matrix(); break; //-------- модуль Ани
		case 4: printf("\033c"); 
/*			Function();*/ break; //-------- модуль Лёши
		case 5: printf("\033c");
/*		    Additionally();*/ break; //-------- модуль Саши
		default: printf("\033c");// -------- с Никиты память(!)
			printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}

	} while (way != 6);
}