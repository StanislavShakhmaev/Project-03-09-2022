#include <iostream>
using namespace std;

int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
double Div(int a, int b);

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello functions" << endl;
	int a, b;
	cout << "������� 2 �����: ";
	cin >> a >> b;
	int c = Add(a, b);
	cout << a << " + " << b << " = " << c << endl;
	cout << a << " - " << b << " = " << Sub(a, b) << endl;
	cout << a << " * " << b << " = " << Mul(a, b) << endl;
	cout << a << " / " << b << " = " << Div(a, b) << endl;

}

int Add(int a, int b)
{
	//addition -��������
	int c = a + b;
	return c;
}
int Sub(int a, int b)
{
	// subtruction - ���������
	return a - b;
}
int Mul(int a, int b)
{
	// multiplication - ���������
	return a * b;
}
double Div(int a, int b)
{
	return (double)a / b;
}
