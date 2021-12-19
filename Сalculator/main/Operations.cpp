#include "Operations.h"
using namespace std;

struct Leksema //���������, ����������� ����� ����� ��� ��������
{
	char type; // ��������
	double value;//�����
};

int get_rang(char ch) { // ����� ��������� ���������
	if (ch == '^')return 3;
	if (ch == '+' || ch == '-')return 1;
	if (ch == '*' || ch == '/')return 2;
	else return 0;
}

bool maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) {// �������������� �������,������������ �������
	//��� bool, ����� ��� ������������� �����-���� ������ ���������� "false"
	double a, b, c;
	a = Stack_n.top().value; // ����������� �������� �������� � �����
	Stack_n.pop(); //��������� ������� ����� �� ����� � �������
	switch (Stack_o.top().type) {
	case '+':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b + a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); // ��������� �������� �������� ������� � ���� � �������
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
			cerr << "������" << endl;
			return false;
		}
		else {
			Stack_n.pop();
			c = b / a;
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}
	default:
		cout << "������" << endl;
		return false;
	}	return true;
}

int Operations(){
	setlocale(LC_ALL, "RUSSIAN");
	char ch;
	cout << " \t ������������, ��� ������ � ��������������� ������������!\n ";
	cout << "   ����� ��������������� �������������, ��� ������ ���������� � ��� �������������! ( ��������, ������� 'hi')\n ";
	cout << "   ������� ���������: ";
	bool flag = 1;
	double value;
	string  str;
	cin >> str;
	stack <Leksema> Stack_n;
	stack <Leksema> Stack_o;
	Leksema item;
	while (true) {
		ch = cin.peek();
		if (ch == '\n')break;
		if (ch == ' ') {
			cin.ignore();
			continue;
		}
		if (ch >= '0' && ch <= '9' || ch == '-' && flag == 1) { // ��������� �����
			cin >> value;
			item.type = '0';
			item.value = value;
			Stack_n.push(item);
			flag = 0;
			continue;
		}
		if (ch == '+' || ch == '-' && flag == 0 || ch == '*' || ch == '/' || ch == '^') { // ��������� ��������
			if (Stack_o.size() == 0) {
				item.type = ch;
				item.value = 0;
				Stack_o.push(item);
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && get_rang(ch) > get_rang(Stack_o.top().type)) {
				item.type = ch;
				item.value = 0;
				Stack_o.push(item);
				cin.ignore();
				continue;
			}
			if (Stack_o.size() != 0 && get_rang(ch) <= get_rang(Stack_o.top().type)) {
				if (maths(Stack_n, Stack_o, item) == false) {
					system("pause");
					return 0;
				}
				continue;
			}
		}
		if (ch == '(') {
			item.type = ch;
			item.value = 0;
			Stack_n.push(item);
			Stack_o.push(item);
			cin.ignore();
			continue;
		}
		if (ch == ')') {
			while (Stack_n.top().value != '(') {
				if (maths(Stack_n, Stack_o, item) == false) {
					system("pause");
					return 0;
				}
				else
					continue;
			}
			cin.ignore();
			Stack_o.pop();
			continue;
		}
		else {
			cout << "\n����������� �������� ������\n";
			system("pause");
			return 0;
		}
	}
	while (Stack_o.size() != 0) { // �������� �������������� ������� �� ��� ���, ���� � ����� � ���������� �� ����� 0 ���������
		if (maths(Stack_n, Stack_o, item) == false) {
			system("pause");
			return 0;
		}
		else
			continue;
	}
	cout << " �����: " << Stack_n.top().value << endl;
	return 0;
}

