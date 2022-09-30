#include <iostream>
#include <conio.h>
#include <ctime> 
using namespace std;

const int n = 256;
int arr[n];
int a = 0;
int b = 0;
int n1 = 0;
const int rows = 3;
const int cols = 2;

void FillRand(int n1, int arr[], int a, int b);
void FillRand(int n1, double arr[], int a, int b);
void FillRand(int n1, float arr[], int a, int b);
void FillRand(int n1, char arr[], int a, int b);

void Print(int n1, int arr[]);

void ReversePrint(int n1, int arr[]);

int sum(int n1, int arr[]);
double sum(int n1, double arr[]);
float sum(int n1, float arr[]);
char sum(int n1, char arr[]);
//int sum(int n1, int arr[rows][cols]);
//double sum(int n1, double arr[rows][cols]);
//float sum(int n1, float arr[rows][cols]);
//char sum(int n1, char arr[rows][cols]);

float Avg(int n1, int arr[]);

int minValueIn(int n1, int arr[]);

int maxValueIn(int n1, int arr[]);

void shiftLeft(int n1, int arr[], int a);

void shiftRight(int n1, int arr[], int a);

void sort(int n1, int arr[]);

void UniqueRand(int n1, int arr[]);

void Search(int n1, int arr[]);

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
			FillRand(n1, arr, a, b);
		}
		else if (number_of_function == 3)
		{
			UniqueRand(n1, arr);
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
		}
		cout << endl << "Вывести массив наооборот? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) ReversePrint(n1, arr);
		cout << endl << "Вывести сумму чисел массива? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << sum(n1, arr);
		cout << endl << "Вывести среднее арифметическое чисел массива? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << Avg(n1, arr);
		cout << endl << "Вывести минимальное значение массива? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << minValueIn(n1, arr);
		cout << endl << "Вывести максимальное значение массива? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1) cout << maxValueIn(n1, arr);
		cout<<endl<<"Отсортировать массив? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1)
		{
			sort(n1, arr);
			Print(n1, arr);
		}
		cout << endl << "Будем сдвигать массив? (1 - да, 2 - нет) - > "; cin >> number_of_function;
		if (number_of_function == 1)
		{
			cout<<"Выберете сторону в которую будем сдвигать массив (1 - влево, 2 - вправо) - > "; cin >> number_of_function;
			if (number_of_function == 1)
			{
				cout << "На сколько чисел будем сдвигать массив? - > "; cin >> a;
				shiftLeft(n1, arr, a);
				Print(n1, arr);
			}
			else if (number_of_function == 2)
			{
				cout << "На сколько чисел будем сдвигать массив? - > "; cin >> a;
				shiftRight(n1, arr, a);
				Print(n1, arr);
			}
		}
		Search(n1, arr);
		cout << endl << "Выполнить программу еще раз? (для продолжения нажмите любую клавишу, для выхода esc) -> ";
		key = _getch();
	}
}

void FillRand(int n1, int arr[], int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		arr[i] = a + rand() % (b - a);
	}
}
void FillRand(int n1, double arr[], int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		arr[i] = a + rand()/100 % (b - a);
	}
}
void FillRand(int n1, float arr[], int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		arr[i] = a + rand() % (b - a);
	}
}
void FillRand(int n1, char arr[], int a, int b)
{
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
	{
		arr[i] = a + rand() % (b - a);
	}
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
double sum(int n1, double arr[])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
char sum(int n1, char arr[])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
float sum(int n1, float arr[])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
/*int sum(int n1, int arr[rows][cols])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
double sum(int n1, double arr[rows][cols])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
char sum(int n1, char arr[rows][cols])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
float sum(int n1, float arr[rows][cols])
{
	int c = 0;
	for (int i = 0; i < n1; i++)
	{
		c = c + arr[i];
	}
	return c;
}
*/
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
void Search(int n1, int arr[])
{
	for (int i = 0; i < n1; i++)
	{
		sort(n1, arr);
		int counter = 0;
		int buffer = arr[i-1];
		for (int j = i; j < n1; j++)
		{
			if (arr[i] == arr[j])
			{
				counter++;
			}
		}
		if (arr[i] != buffer)
		{
			if (counter > 1)
			{
				cout << arr[i] << "  " << "В количестве - > " << counter << endl;
			}
		}
	}
}