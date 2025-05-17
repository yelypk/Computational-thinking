#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <tgmath.h>

#include <string.h>

// прототипи функцій
int main();
int mainmenu();
int backtomenu();
int myinput();
float myfloatinput();
int task1();
int task2();
float myf(float x);
int sign(float x);
int fillMatrixManually(int* arr, int n);
int fillMatrixRandomly(int* arr, int n);
int PrintMatrix(int* arr, int n);


// перевірки вводу
int myinput()
{
	char line[256];
	int i = 0;
	while (1)
	{
		if (fgets(line, sizeof(line), stdin)) {
			if (1 == sscanf(line, "%d", &i)) {
				// 1 - кількість зчитаних змінних
				break;
			}
			else
			{
				fprintf(stdout, "Incorrect number format, lets try again:\n");
			}
		}
		else
		{
			fprintf(stdout, "Input error, lets try again:\n");
		}
	}
	fprintf(stdout, "Parsed decimal number: %d \n", i);
	return i;
}

float myfloatinput()
{
	char line[256];
	float i = 0;
	while (1)
	{
		if (fgets(line, sizeof(line), stdin)) {
			if (1 == sscanf(line, "%f", &i)) {
				// 1 - кількість зчитаних змінних
				break;
			}
			else
			{
				fprintf(stdout, "Incorrect number format, lets try again:\n");
			}
		}
		else
		{
			fprintf(stdout, "Input error, lets try again:\n");
		}
	}
	fprintf(stdout, "Parsed float number: %f \n", i);
	return i;
}


// навігація

int main()
{
	fprintf(stdout, "Modul 4 topic: Ukazivniki, funcii, recursii\n");
	fprintf(stdout, "Created by student KM-42 Posheliuk Elizaveta Andriyovna\n");
	fprintf(stdout, "Task 18\n");
	mainmenu();

	return 0;
}

int mainmenu()
{
	fprintf(stdout, "============ main menu ============\n");
	fprintf(stdout, "enter number for your navigation choise:\n");
	fprintf(stdout, "1 - task 1, 2 - task 2, 3 - end and exit\n");


	while (1)
	{
		int choice = myinput();
		int stop = 0;
		switch (choice)
		{
		case 1:
			task1();
			backtomenu();
			stop = 1;
			break;
		case 2:
			task2();
			backtomenu();
			stop = 1;
			break;
		case 3:
			return 0;
		default:
			fprintf(stdout, "Wrong input, lets try again:\n");
			break;
		}
		if (stop == 1)
		{
			break;
		}
	}


	return 0;

}

int backtomenu()
{
	fprintf(stdout, "xxxxxxxx end task xxxxxxxx\n");
	fprintf(stdout, "enter number for your navigation choise:\n");
	fprintf(stdout, "1 - return to main menu, 3 - end and exit\n");

	while (1)
	{
		int choice = myinput();
		int stop = 0;

		switch (choice)
		{
		case 1:
			stop = 1;
			break;
		case 3:
			return 0;
		default:
			fprintf(stdout, "Wrong input, lets try again:\n");
			break;
		}
		if (stop == 1)
		{
			break;
		}
	}

	mainmenu();
	return 0;
}

// функції

//Написати функцію, яка у квадратній матриці зсуває крайні елементи за кільцем, тобто, перший рядок заміщає останній стовпець, останній стовпець — останній рядок, останній рядок — перший стовпець, а перший стовпець — перший рядок
int task1()
{
	fprintf(stdout, "Task 1. Write a function that rotates the outer elements of a square matrix in a circular manner, that is: the first row replaces the last column, the last column replaces the last row, the last row replaces the first column, and the first column replaces the first row.\n");
	int arr[256];
	int arrnew[256];

	fprintf(stdout, "Enter the matrix dimension n (more then 1 and less or equal 16):\n");
	int n = 0;
	while (1)
	{
		n = myinput();
		if (n > 1 && n <= 16)
		{
			break;
		}
		else
		{
			fprintf(stdout, "Incorrect number, lets try again:\n");
		}
	}

	fprintf(stdout, "If you want to fill matrix manually - please enter 1, if you want to fill matrix by random - please enter 2\n");
	while (1)
	{
		int choice = myinput();
		if (choice == 1)
		{
			fillMatrixManually(arr, n);
			break;
		}
		else if (choice == 2)
		{
			fillMatrixRandomly(arr, n);
			break;
		}
		else
		{
			fprintf(stdout, "Wrong input, lets try again:\n");
		}
	}

	PrintMatrix(arr, n);

	memcpy(arrnew, arr, sizeof(arr));

	// обмін крайніх елементів
	for (int i = 0; i < n; i++)
	{
		arrnew[i] = arr[(n - i - 1) * n];
		arrnew[n * i + (n - 1)] = arr[i];
		arrnew[(n - 1) * n + (n - i - 1)] = arr[n * i + (n - 1)];
		arrnew[n * i] = arr[(n - 1) * n + i];

	}

	fprintf(stdout, "Result:\n");
	PrintMatrix(arrnew, n);

	return 0;
}

//Шляхом розподілу відрізка навпіл знайти з точністю 0.0001 корінь рівняння cos(2/x) - 2sin(1/x) + 1/x = 0
int task2()
{
	fprintf(stdout, "Task 2. Using the bisection method, find the root of the equation cos(2/x) - 2sin(1/x) + 1/x = 0 with an accuracy of 0.0001\n");
	fprintf(stdout, "Enter the left border of the segment:\n");
	float a = 0;
	int signa = 1;
	while (1)
	{
		a = myfloatinput();
		fprintf(stdout, "f(a) = %f\n", myf(a));
		signa = sign(myf(a));

		if (a != 0.0f)
		{
			break;
		}
		else
		{
			fprintf(stdout, "Incorrect number, a=0 is infinite point, lets try again:\n");
		}
	}

	fprintf(stdout, "Enter the right border of the segment:\n");
	float b = 0;
	while (1)
	{
		b = myfloatinput();
		int signb = 1;
		fprintf(stdout, "f(b) = %f\n", myf(b));
		signb = sign(myf(b));

		if (b > a && b != 0 && signa != signb)
		{
			break;
		}
		else
		{
			fprintf(stdout, "Incorrect number, lets try again:\n");
		}
	}

	float eps = 0.0001f;
	float x = 0;
	while (fabs(b - a) > eps)
	{
		x = (a + b) / 2;
		if (x == 0.0)
		{
			fprintf(stdout, "x=0 is infinite point, lets try again:\n");
			break;
		}
		if (sign(myf(x)) == signa)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}

	if (x != 0.0f)
	{
		fprintf(stdout, "Result:\n");
		fprintf(stdout, "x = %f\n", x);
		fprintf(stdout, "f(x) = %f\n", myf(x));
		fprintf(stdout, "err = %f\n", fabs(b - a));
	}


	return 0;
}
// функція f(x) = cos(2/x) - 2sin(1/x) + 1/x
float myf(float x)
{
	return cos(2 / x) - 2 * sin(1 / x) + 1 / x;
}

int sign(float x)
{
	if (x > 0)
	{
		return 1;
	}
	else if (x < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int fillMatrixManually(int* arr, int n)
{
	fprintf(stdout, "Enter the elements of the matrix:\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(stdout, "Row number %d:\n", i + 1);
		for (int j = 0; j < n; j++)
		{
			fprintf(stdout, "Enter element %d:\n", j + 1);
			arr[i * n + j] = myinput();
		}
	}
	return 0;
}

int fillMatrixRandomly(int* arr, int n)
{
	fprintf(stdout, "Enter the range of random numbers:\n");
	fprintf(stdout, "From:\n");
	int from = myinput();
	fprintf(stdout, "To:\n");
	int to = myinput();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i * n + j] = rand() % (to - from + 1) + from;
		}
	}
	return 0;
}


int PrintMatrix(int* arr, int n)
{
	fprintf(stdout, "Matrix:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fprintf(stdout, "%d \t", arr[i * n + j]);
		}
		fprintf(stdout, "\n");
	}
	return 0;
}