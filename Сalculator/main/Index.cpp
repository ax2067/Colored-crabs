#include <iostream>
#include <ctime> 
#include <cstdlib> 
#include <iomanip>
#include <Windows.h>
#include "Matrix.h"
#include "Operations.h"
///////-------Примечание: если в вашем модуле есть ещё пару модулей - вы и им даёте заголовки, см модуль "Matrix.cpp"-------///////
// Просто раскомментируйте свой заголовок, не забудьте его создать "ctrl+shift+a", создаёте не новый проект, не новое решение, а просто файл!!!!
// Пожалуйста, подумайте про "printf("\033c");" - нужно ли это? (очищение строки)
//#include "Operations.h"  
#include "Conversion.h"
//#include "Function.h"
//#include "Trigonometry.h"
//#include "Additionally.h"
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	int way;
	printf("Привет, привет!Это калькулятор для студентов. Он упростит жизнь студентов в диком мире математики!\n");
	Sleep(3000);
	printf("\033c");
	do {
		printf("Чтобы выбрать желаемое действие - введите соответствующее ему число.\n");
		printf("1 - Операции над числами.\n");
		printf("2 - Конвертация в двоичный/шестнадцатиричный код.\n");
		printf("3 - Работы с матрицами.\n");
		printf("4 - Операции с функциями и нахождение площадей и объёмов различных фигур.\n");
		printf("5 - Дополнительные операции (факториал, НОК и НОД).\n");
		printf("6 - Выход из программы.\n");
		cin >> way;
		switch (way)
		{
		case 1: printf("\033c");
             Operations(); break;//------- модуль Ксюши
		case 2: printf("\033c");
			Conversion(); break; //-------- модуль Иры
		case 3: Matrix(); break; //-------- модуль Ани
		case 4: printf("\033c"); 
/*			Function();*/ break; //-------- модуль Лёши
		case 5: printf("\033c");
/*		    Additionally();*/ break; //-------- модуль Саши
		case 6: printf("\033c");
			printf("Пока-пока!"); break; ////// --------- хто нибудь придумайте прощальную фразу(!)
		default: printf("\033c");
			printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}
		cin.clear(); // то возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // удаляем все

	} while (way != 6);
	return 0;
}