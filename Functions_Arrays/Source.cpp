#include <iostream>
#include <conio.h>
#include <ctime> 
using namespace std;

const int n = 256;
int arr[n];
int a = 0;
int b = 0;
int n1 = 0;

int FillRand(int a, int b);
void Print(int n1, int arr[]);
void ReversePrint(int n1, int arr[]);
int sum(int n1, int arr[]);
/*int Avg(int a, int b);
int minValueIn(int a, int b);
int maxValueIn(int a, int b);
int shiftLeft(int a, int b);
int shiftRight(int a, int b);
int UniqueRand(int a, int b);
*/
void main()
{
	setlocale(LC_ALL, "");
	cout << "��������� ��� ������ � ���������";
	char key = 0;
	int number_of_function = 0;
	while (key != (char)27)
	{
		cout << endl << "������� ���������� ����� � ������� -> "; 
		cin >> n1;
		cout << endl << "�������� ������ ���������� �������:"<<endl<<"1 - ������ ����� �������" << endl << "2 - ��������� ������ ���������� �������" << endl << "3 - ��������� ������ ����������� ���������� �������" << endl <<" - > ";
		cin >> number_of_function;
		if (number_of_function == 1)
		{
			for (int i = 0; i < n1; i++)
			{
				cin >> arr[i];
			}
		}
		else if (number_of_function == 2)
		{
			cout << "������� ������ ������ ������� ->";
			cin >> a;
			cout << "������� ������� ������ ������� ->";
			cin >> b;
			srand(time(NULL));
			for (int i = 0; i < n1; i++)
			{
				arr[i] = FillRand(a, b);
			}
		}
		cout << "������� ������ �� �����? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 2)
		{
			cout << endl << "��� ���������� ������ �� ����������� )" << endl;
			Print(n1, arr);
		}
		else
		{
			Print(n1, arr);
		};
		cout << endl << "������� ������ ���������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) ReversePrint(n1, arr);
		cout << endl << "������� ����� ����� �������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << sum(n1, arr);
		
		cout << endl << "��������� ��������� ��� ���? (��� ����������� ������� ����� �������, ��� ������ esc) -> ";
		key = _getch();
	}
}

int FillRand(int a, int b)
{
	int c=0;
	c =a + rand() % (b+1);
	return c;
}
void Print(int n1, int arr[])
{
	for (int i = 0; i < n1; i++)
	{
		cout << arr[i] << "  ";
	}
}
void ReversePrint(int n1, int arr[])
{
	for (int i = (n1-1); i >= 0; i--)
	{
		cout << arr[i] << "  ";
	}
}
int sum(int n1, int arr[])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
