#include <iostream>
#include <string>

class Divide {
private:
	int a;
	int b;
	int absDiv(int x, int y) {
		if (y == 0)
			throw Divide();
		return absDiv(y, x % y);
	}
public:
	void input(int c, int z) {
		a = c;
		b = z;
	}
	void mult(int x) {
		a *= x;
		std::cout << "�����:  " << a << '/' << b << std::endl;
	}
	void div(int x) {
		b *= x;
		std::cout << "�����:  " << a << '/' << b << std::endl;
	}
	void sum(int x) {
		a += (x * b);
		std::cout << "�����:  " << a << '/' << b << std::endl;
	}
	void sub(int x) {
		a -= (x * b);
		std::cout << "�����:  " << a << '/' << b << std::endl;
	}
	void show() {
		std::cout << "������� �����:  " << a << '/' << b << std::endl;
	}
	int peredacha() {
		return absDiv(a, b);
	}
	void reduct(int x) {
		a /= x;
		b /= x;
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	int a, b, m;
	char c = 'y';
	std::cout << "������� ���������: " << std::endl;
	std::cin >> a;
	std::cout << "������� �����������: " << std::endl;
	std::cin >> b;
	try {
		if (b == 0) {
			throw Divide();
		}
	}
	catch(_exception&e){
		std::cerr << "��������� 0 � �����������!" << std::endl;
	}
	Divide obj;
	obj.input(a, b);
	do {
		obj.reduct(obj.peredacha());
		obj.show();
		std::cout << "1: ��������� � ����� �����" << std::endl;
		std::cout << "2: ������ �� ����� �����" << std::endl;
		std::cout << "3: �������� ����� �� �����" << std::endl;
		std::cout << "4: ��������� ����� �� �����" << std::endl;
		std::cout << "�������� �������� -> ";
		std::cin >> m;
		switch (m)
		{
		case 1:
			std::cout << "������� ���������: " << std::endl;
			std::cin >> a;
			obj.sum(a);
			break;
		case 2:
			std::cout << "������� ����������: " << std::endl;
			std::cin >> a;
			obj.sub(a);
			break;
		case 3:
			std::cout << "������� ���������" << std::endl;
			std::cin >> a;
			obj.mult(a);
			break;
		case 4:
			std::cout << "������� ��������" << std::endl;
			std::cin >> a;
			try {
				if (a == 0) {
					throw 121 ;
				}
				obj.div(a);
			}
			catch (int i) {
				std::cout << i << "���������� ������� ������� �� 0!" << std::endl;
			}
			obj.div(a);
			break;
		default:
			std::cout << "������ �����!" << std::endl;
		}
		std::cout << "���������� ������?(y/n)" << std::endl;
		std::cin >> c;
	} while (c != 'n');

	return 0;
}