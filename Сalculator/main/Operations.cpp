#include <iostream>
#include <stack>
#include <cmath>
#include <Windows.h>
#include "Operations.h"

using namespace std;

const double Pi = acos(-1); //Объявляем значение числа Пи
const double e = 2.7182818284;

double Sin(double x) { //Функция для округления значение синуса
	return (round(sin(x * Pi /180) * 10000000) / 10000000);
}


double Cos(double x) { //Функция для округления значение косинуса
	return (round(cos(x * Pi / 180) * 10000000) / 10000000);
}

double Log(double x, double y) { //Функция для округления значение косинуса
	return log(y) / log(x);
}

double ctg(double x) { //Функция для расчета котангенса
	double a = cos(x * Pi / 180);
	double b = sin(x * Pi / 180);
	return (a / b);
}

struct Leksema //Структура, описывающая любое число или операцию
{
	char type; // 0 для чисел, "+" для операции сложения и т.д.
	double value; //Значение (только для чисел). У операций значение всегда "0"
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //Математическая функция, которая производит расчеты
	//Функция имеет тип bool, чтобы при возникновении какой-либо ошибки возвращать "false"
	double a, b, c;
	a = Stack_n.top().value; //Берется верхнее число из стека с числами
	Stack_n.pop(); //Удаляется верхнее число из стека с числами
	switch (Stack_o.top().type) {  //Проверяется тип верхней операции из стека с операциями
	case '+': //Если тип верхней операции из стека с операциями сложение
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); //Результат операции кладется обратно в стек с числами
		Stack_o.pop();
		break;

	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '^':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = pow(b, a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '/':
		b = Stack_n.top().value;
		if (a == 0) {
			cerr << "\nНа 0 делить нельзя!\n";
			return false;
		}
		else {
			Stack_n.pop();
			c = (b / a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 's':
		c = Sin(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'c':
		c = Cos(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 't':
		if (Cos(a) == 0) {
			cerr << "\nНеверный аргумент для тангенса!\n";
			return false;
		}
		else {
			c = 1 / ctg(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'g':
		if (Sin(a) == 0) {
			cerr << "\nНеверный аргумент для котангенса!\n";
			return false;
		}
		else {
			c = ctg(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'e':
		c = exp(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'l':
		b = Stack_n.top().value;
		if (a == 1 || a <= 0 || b <= 0) {
			cerr << "\nНеверный аргумент для логарифма!\n";
			return false;
		}
		else {
			Stack_n.pop();
			c = Log(b, a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	default:
		cerr << "\nОшибка!\n";
		return false;
		break;
	}
	return true;
}

int getRang(char Ch) { //Функция возвращает приоритет операции: "1" для сложения и вычитания, "2" для умножения и деления и т.д.
	if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e' || Ch == 'l')return 4;
	if (Ch == '^')return 3;
	if (Ch == '+' || Ch == '-')return 1;
	if (Ch == '*' || Ch == '/')return 2;
	else return 0;
}

int Operations()
{
	setlocale(LC_ALL, "en_US.UTF8");
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);

	cout << "   Привет! Это программа - калькулятор!\n";
	cout << "Руководство по эксплуатации: \n";
	cout << "   1) Не забудьте поздороваться \n";
	cout << "   2) В случае ошибки смотрите пункт 1 \n";

	cout << "Для испрользования числа Пи введите 'p' \nДля использования числа Е введите 'exp(1)'\nДля использования логарифма введите 'log a b' '\nДля использования тангенса введите 'tan a'\n";
	cout << "   Введите выражение: ";
	char Ch, Char;//Переменная, в которую будет записываться текущий обрабатываемый символ
	double value;
	bool run, check;
	run = true;
	string  str;
	cin >> str;
	if (str != "Hey" && str != "Здравствуйте" && str != "Hi" && str != "Hello" && str != "Hellow" && str != "Привет" && str != "Йо" && str != "Прив" && str != "hey" && str != "здравствуй" && str != "здравствуйте" && str != "hi" && str != "hello" && str != "hellow" && str != "привет" && str != "йо" && str != "прив") {
		cout << "Вы забыли самое главное =(";
		run = false;
		cout << endl;
		system("pause");
		return 0;
	}
	else {
		check = true;
	}

	bool flag = 1; //Нужен для того, чтобы программа смогла отличить унарный минус (-5) от вычитания (2-5)
	stack <Leksema> Stack_n; //Стек с числами
	stack <Leksema> Stack_o; //Стек с операциями
	Leksema item; //Объект типа Leksema
	while (run) {
		Ch = cin.peek(); //Смотрим на первый символ
		if (Ch == '\n')break; //Если достигнут конец строки, выходим из цикла
		if (Ch == ' ') { //Игнорирование пробелов
			cin.ignore();
			continue;
		}

		if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e' || Ch == 'l') { //Если прочитана функция
			char foo[3]; //массив на 3 символа для определения типа прочитанной функции
			for (int i = 0; i < 3; i++) {
				Ch = cin.peek();
				foo[i] = Ch;
				cin.ignore();
			}
			if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') { //Если прочитанная функция - синус
				item.type = 's';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}
			if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { //Если прочитанная функция - косинус
				item.type = 'c';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}
			if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { //Если прочитанная функция - тангенс
				item.type = 't';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}
			if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { //Если прочитанная функция - котангенс
				item.type = 'g';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}
			if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') { //Если прочитанная функция - экспонента
				item.type = 'e';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}

			if (foo[0] == 'l' && foo[1] == 'o' && foo[2] == 'g') { //Если прочитанная функция - экспонента
				item.type = 'l';
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				continue;
			}
		}
		if (Ch == 'p') { //Если прочитано число Пи
			item.type = '0';
			item.value = Pi;
			Stack_n.push(item); //Число кладется в стек с числами
			flag = 0;
			cin.ignore();
			continue;
		}
		if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) { //Если прочитано число
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item); //Число кладется в стек с числами
			flag = 0;
			continue;
		}
		if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { //Если прочитана операция
			if (Stack_o.size() == 0) { //Если стек с операциями пуст
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) > getRang(Stack_o.top().type)) { //Если стек с операциями НЕ пуст, но приоритет текущей операции выше верхней в стеке с операциями
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item); //Операция кладется в стек с операциями
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) <= getRang(Stack_o.top().type)) {//Если стек с операциями НЕ пуст, но приоритет текущей операции ниже либо равен верхней в стеке с операциями
				if (Maths(Stack_n, Stack_o, item) == false) { //Если функция вернет "false", то прекращаем работу
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (Ch == '(') { //Если прочитана открывающаяся скобка
			item.type = Ch;
			item.value = 0;
			Stack_o.push(item); //Операция кладется в стек с операциями
			cin.ignore();
			continue;
		}
		if (Ch == ')') { //Если прочитана закрывающаяся скобка
			while (Stack_o.top().type != '(') {
				if (Maths(Stack_n, Stack_o, item) == false) { //Если функция вернет "false", то прекращаем работу
					system("pause");
					return 0;
				}
				else continue; //Если все хорошо	
			}
			Stack_o.pop();
			cin.ignore();
			continue;
		}
		else { //Если прочитан какой-то странный символ
			cout << "\nНеверно введено выражение!\n";
			system("pause");
			return 0;
		}
	}
	while (Stack_o.size() != 0) { //Вызываем матем. функцию до тех пор, пока в стеке с операциями не будет 0 элементов
		if (Maths(Stack_n, Stack_o, item) == false || run == false) { //Если функция вернет "false", то прекращаем работу
			system("pause");
			return 0;
		}
		else continue; //Если все хорошо	
	}
	if (Stack_o.size() == 0 && Stack_n.size() == 0)
		if (check) {
			cout << "И тебе привет!" << endl;
			return 0;
		}
		else {
			cout << "Может попробовать еще раз? =)" << endl;
			return 0;
		}
	if (run == true) {
		if (Stack_n.top().value)
			cout << "   Ответ: " << Stack_n.top().value << endl; //Выводим ответ
		return 0;
	}
	cout << "   Ответ: " << Stack_n.top().value << endl; //Выводим ответ
	return 1;
}
