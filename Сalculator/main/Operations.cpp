#include <iostream>
#include <stack>
#include <cmath>
#include <Windows.h>
#include "Operations.h"

using namespace std;

const double Pi = acos(-1); //��������� �������� ����� ��
const double e = 2.7182818284;

double Sin(double x) { //������� ��� ���������� �������� ������
	return (round(sin(x * Pi /180) * 10000000) / 10000000);
}


double Cos(double x) { //������� ��� ���������� �������� ��������
	return (round(cos(x * Pi / 180) * 10000000) / 10000000);
}

double Log(double x, double y) { //������� ��� ���������� �������� ��������
	return log(y) / log(x);
}

double ctg(double x) { //������� ��� ������� ����������
	double a = cos(x * Pi / 180);
	double b = sin(x * Pi / 180);
	return (a / b);
}

struct Leksema //���������, ����������� ����� ����� ��� ��������
{
	char type; // 0 ��� �����, "+" ��� �������� �������� � �.�.
	double value; //�������� (������ ��� �����). � �������� �������� ������ "0"
};

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //�������������� �������, ������� ���������� �������
	//������� ����� ��� bool, ����� ��� ������������� �����-���� ������ ���������� "false"
	double a, b, c;
	a = Stack_n.top().value; //������� ������� ����� �� ����� � �������
	Stack_n.pop(); //��������� ������� ����� �� ����� � �������
	switch (Stack_o.top().type) {  //����������� ��� ������� �������� �� ����� � ����������
	case '+': //���� ��� ������� �������� �� ����� � ���������� ��������
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); //��������� �������� �������� ������� � ���� � �������
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
			cerr << "\n�� 0 ������ ������!\n";
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
			cerr << "\n�������� �������� ��� ��������!\n";
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
			cerr << "\n�������� �������� ��� ����������!\n";
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
			cerr << "\n�������� �������� ��� ���������!\n";
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
		cerr << "\n������!\n";
		return false;
		break;
	}
	return true;
}

int getRang(char Ch) { //������� ���������� ��������� ��������: "1" ��� �������� � ���������, "2" ��� ��������� � ������� � �.�.
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

	cout << "   ������! ��� ��������� - �����������!\n";
	cout << "����������� �� ������������: \n";
	cout << "   1) �� �������� ������������� \n";
	cout << "   2) � ������ ������ �������� ����� 1 \n";

	cout << "��� �������������� ����� �� ������� 'p' \n��� ������������� ����� � ������� 'exp(1)'\n��� ������������� ��������� ������� 'log a b' '\n��� ������������� �������� ������� 'tan a'\n";
	cout << "   ������� ���������: ";
	char Ch, Char;//����������, � ������� ����� ������������ ������� �������������� ������
	double value;
	bool run, check;
	run = true;
	string  str;
	cin >> str;
	if (str != "Hey" && str != "������������" && str != "Hi" && str != "Hello" && str != "Hellow" && str != "������" && str != "��" && str != "����" && str != "hey" && str != "����������" && str != "������������" && str != "hi" && str != "hello" && str != "hellow" && str != "������" && str != "��" && str != "����") {
		cout << "�� ������ ����� ������� =(";
		run = false;
		cout << endl;
		system("pause");
		return 0;
	}
	else {
		check = true;
	}

	bool flag = 1; //����� ��� ����, ����� ��������� ������ �������� ������� ����� (-5) �� ��������� (2-5)
	stack <Leksema> Stack_n; //���� � �������
	stack <Leksema> Stack_o; //���� � ����������
	Leksema item; //������ ���� Leksema
	while (run) {
		Ch = cin.peek(); //������� �� ������ ������
		if (Ch == '\n')break; //���� ��������� ����� ������, ������� �� �����
		if (Ch == ' ') { //������������� ��������
			cin.ignore();
			continue;
		}

		if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e' || Ch == 'l') { //���� ��������� �������
			char foo[3]; //������ �� 3 ������� ��� ����������� ���� ����������� �������
			for (int i = 0; i < 3; i++) {
				Ch = cin.peek();
				foo[i] = Ch;
				cin.ignore();
			}
			if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') { //���� ����������� ������� - �����
				item.type = 's';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}
			if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { //���� ����������� ������� - �������
				item.type = 'c';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}
			if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { //���� ����������� ������� - �������
				item.type = 't';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}
			if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { //���� ����������� ������� - ���������
				item.type = 'g';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}
			if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') { //���� ����������� ������� - ����������
				item.type = 'e';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}

			if (foo[0] == 'l' && foo[1] == 'o' && foo[2] == 'g') { //���� ����������� ������� - ����������
				item.type = 'l';
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				continue;
			}
		}
		if (Ch == 'p') { //���� ��������� ����� ��
			item.type = '0';
			item.value = Pi;
			Stack_n.push(item); //����� �������� � ���� � �������
			flag = 0;
			cin.ignore();
			continue;
		}
		if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) { //���� ��������� �����
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item); //����� �������� � ���� � �������
			flag = 0;
			continue;
		}
		if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { //���� ��������� ��������
			if (Stack_o.size() == 0) { //���� ���� � ���������� ����
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) > getRang(Stack_o.top().type)) { //���� ���� � ���������� �� ����, �� ��������� ������� �������� ���� ������� � ����� � ����������
				item.type = Ch;
				item.value = 0;
				Stack_o.push(item); //�������� �������� � ���� � ����������
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && getRang(Ch) <= getRang(Stack_o.top().type)) {//���� ���� � ���������� �� ����, �� ��������� ������� �������� ���� ���� ����� ������� � ����� � ����������
				if (Maths(Stack_n, Stack_o, item) == false) { //���� ������� ������ "false", �� ���������� ������
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (Ch == '(') { //���� ��������� ������������� ������
			item.type = Ch;
			item.value = 0;
			Stack_o.push(item); //�������� �������� � ���� � ����������
			cin.ignore();
			continue;
		}
		if (Ch == ')') { //���� ��������� ������������� ������
			while (Stack_o.top().type != '(') {
				if (Maths(Stack_n, Stack_o, item) == false) { //���� ������� ������ "false", �� ���������� ������
					system("pause");
					return 0;
				}
				else continue; //���� ��� ������	
			}
			Stack_o.pop();
			cin.ignore();
			continue;
		}
		else { //���� �������� �����-�� �������� ������
			cout << "\n������� ������� ���������!\n";
			system("pause");
			return 0;
		}
	}
	while (Stack_o.size() != 0) { //�������� �����. ������� �� ��� ���, ���� � ����� � ���������� �� ����� 0 ���������
		if (Maths(Stack_n, Stack_o, item) == false || run == false) { //���� ������� ������ "false", �� ���������� ������
			system("pause");
			return 0;
		}
		else continue; //���� ��� ������	
	}
	if (Stack_o.size() == 0 && Stack_n.size() == 0)
		if (check) {
			cout << "� ���� ������!" << endl;
			return 0;
		}
		else {
			cout << "����� ����������� ��� ���? =)" << endl;
			return 0;
		}
	if (run == true) {
		if (Stack_n.top().value)
			cout << "   �����: " << Stack_n.top().value << endl; //������� �����
		return 0;
	}
	cout << "   �����: " << Stack_n.top().value << endl; //������� �����
	return 1;
}
