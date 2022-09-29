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
float Avg(int n1, int arr[]);
int minValueIn(int n1, int arr[]);
int maxValueIn(int n1, int arr[]);
void shiftLeft(int n1, int arr[], int a);
void shiftRight(int n1, int arr[], int a);
void sort(int n1, int arr[]);
void UniqueRand(int n1, int arr[]);

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
		else if (number_of_function == 3)
		{
			UniqueRand(n1, arr);
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
		}
		cout << endl << "������� ������ ���������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) ReversePrint(n1, arr);
		cout << endl << "������� ����� ����� �������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << sum(n1, arr);
		cout << endl << "������� ������� �������������� ����� �������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << Avg(n1, arr);
		cout << endl << "������� ����������� �������� �������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << minValueIn(n1, arr);
		cout << endl << "������� ������������ �������� �������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << maxValueIn(n1, arr);
		cout<<endl<<"������������� ������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1)
		{
			sort(n1, arr);
			Print(n1, arr);
		}
		cout << endl << "����� �������� ������? (1 - ��, 2 - ���) - > "; cin >> number_of_function;
		if (number_of_function == 1)
		{
			cout<<"�������� ������� � ������� ����� �������� ������ (1 - �����, 2 - ������) - > "; cin >> number_of_function;
			if (number_of_function == 1)
			{
				cout << "�� ������� ����� ����� �������� ������? - > "; cin >> a;
				shiftLeft(n1, arr, a);
				Print(n1, arr);
			}
			else if (number_of_function == 2)
			{
				cout << "�� ������� ����� ����� �������� ������? - > "; cin >> a;
				shiftRight(n1, arr, a);
				Print(n1, arr);
			}
		}
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
float Avg(int n1, int arr[])
{
	float c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	c = c / n1;
	return c;
}
int minValueIn(int n1, int arr[])
{
	int c = arr[0];
	for (int i = 1; i < n1; i++)
	{
			if (c > arr[i]) c = arr[i];
	}
	return c;
}
int maxValueIn(int n1, int arr[])
{
	int c = arr[0];
	for (int i = 1; i < n1; i++)
	{
		if (c < arr[i]) c = arr[i];
	}
	return c;
}
void shiftLeft(int n1, int arr[], int a)
{
	a = a % 10;
	for (int i = 0; i < a; i++)
	{
		int tmp = arr[0];
		for (int i = 0; i < n1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n1 - 1] = tmp;
	}
}
void shiftRight(int n1, int arr[], int a)
{
	shiftLeft(n1, arr, n1-a);
}
void sort(int n1, int arr[])
{
	for (int i = 0; i < n1; i++)
	{
		for (int j = i + 1; j < n1; j++)
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void UniqueRand(int n1, int arr[])
{
	for (int i = 0; i < n1; i++)
	{
		bool unique;
		do
		{
			arr[i] = rand() % n1;
			unique = true;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
	}
}