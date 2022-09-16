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
	cout << "Программа для работы с массивами";
	char key = 0;
	int number_of_function = 0;
	while (key != (char)27)
	{
		cout << endl << "Введите количество чисел в массиве -> "; 
		cin >> n1;
		cout << endl << "Выберете способ заполнения массива:"<<endl<<"1 - ввести числа вручную" << endl << "2 - заполнить массив случайными числами" << endl << "3 - заполнить массив уникальными случайными числами" << endl <<" - > ";
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
			cout << "Введите нижний предел массива ->";
			cin >> a;
			cout << "Введите верхний предел массива ->";
			cin >> b;
			srand(time(NULL));
			for (int i = 0; i < n1; i++)
			{
				arr[i] = FillRand(a, b);
			}
		}
		cout << "Вывести массив на экран? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 2)
		{
			cout << endl << "Для дальнейшей работы он понадобится )" << endl;
			Print(n1, arr);
		}
		else
		{
			Print(n1, arr);
		};
		cout << endl << "Вывести массив наооборот? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) ReversePrint(n1, arr);
		cout << endl << "Вывести сумму чисел массива? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << sum(n1, arr);
		
		cout << endl << "Выполнить программу еще раз? (для продолжения нажмите любую клавишу, для выхода esc) -> ";
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
