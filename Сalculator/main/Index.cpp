#include "Index.h"


using namespace std;
int main()
{
	setlocale(LC_ALL, "en_US.UTF8");
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
		printf("6 - Нахождение объёма фигур.\n");
		printf("7 - Выход из программы.\n");
		cin >> way;
		switch (way)
		{
		case 1: printf("\033c");
             Operations(); break;//------- модуль Ксюши
		case 2: printf("\033c");
			Conversion(); break; //-------- модуль Иры
		case 3: Matrix(); break; //-------- модуль Ани
		case 4: printf("\033c"); 
                 Sqares(); break; //-------- модуль Лёши
		case 5: printf("\033c");
		    Additionally(); break; //-------- модуль Саши
		case 6: printf("\033c");
			Volume(); break;
		case 7: printf("\033c");
        printf("Спасибо за эксплуатацию нашего калькулятора! Ожидаем отзывов, комментариев и пожеланий."); break; ////// --------- хто нибудь придумайте прощальную фразу(!)UPD[sano]:!!!Придумал вроде!!!
		default: printf("\033c");
			printf("Некорректный вариант. Выберите, пожалуйста, ещё раз!\n");
		}
		cin.clear(); // то возвращаем cin в 'обычный' режим работы
		cin.ignore(32767, '\n'); // удаляем все

	} while (way != 7);
	return 0;
}
