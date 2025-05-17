#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// прототипи функцій
int fillarray(int* x, int* y, int n);
float distance(int x1, int y1, int x2, int y2);
int calculatePathLenghts(int* paths, float* dist, int n, int p, int* x, int* y);
int narayanPermutations(int* paths, int n, int p);
int nextPermutation(int* a, int n);
int myinput();
int main();
float Q_rsqrt(float number);

// перевірки вводу

int myinput()
{
char line[256];
int i;
while (1)
{
	if (fgets(line, sizeof(line), stdin)) {
		if (1 == sscanf(line, "%d", &i)) {
			// 1 - кількість зчитаних змінних
			break;
		}
		else
		{
			fprintf(stdout, "wrong number format. Try again!\n");
		}
	}
	else
	{
		fprintf(stdout, "input ERROR - try again!\n");
	}
}
fprintf(stdout, "decimal number entered: %d \n", i);
return i;
}

// функції

int main()
{
fprintf(stdout, "enter points number\n");
int n = myinput();

time_t start=time(0);

int* x = (int*)malloc(n * sizeof(int)); 
// виділення пам'яті під масив x
if (x == NULL)
{
	fprintf(stdout, "memory allocation error\n");
	free(x);
	return 1;
}

int* y = (int*)malloc(n * sizeof(int));
// виділення пам'яті під масив y
if (y == NULL)
{
	fprintf(stdout, "memory allocation error\n");
	free(x);
	free(y);
	return 1;
}
fillarray(x, y, n);

int p = 1; // кількість шляхів, які потрібно знайти. Формула кількості перестановок n!
for (int i = 1; i <= n; i++)
{
	p *= i;
}

int* paths = (int*)malloc(p * n * sizeof(int));
if (paths == NULL)
{
	fprintf(stdout, "memory allocation error\n");
	free(x);
	free(y);
	free(paths);
	return 1;
}
float* dist = (float*)malloc(p * sizeof(float));
if (dist == NULL)
{
	fprintf(stdout, "memory allocation error\n");
	free(x);
	free(y);
	free(paths);
	free(dist);
	return 1;
}

narayanPermutations(paths, n, p);
calculatePathLenghts(paths, dist,n,p,x,y);
float min = dist[0];
int minIndex = 0;
for (int i = 1; i < p; i++)
{
	if (dist[i] < min)
	{
		min = dist[i];
		minIndex = i;
	}
}
fprintf(stdout, "min path length: %f\n", min);
fprintf(stdout, "min path: ");
for (int i = 0; i < n; i++)
{
	fprintf(stdout, "%d ", paths[minIndex * n + i]);
}

time_t end = time(0);
fprintf(stdout, "\ntime: %f\n", difftime(end , start));

free(x);
free(y);
free(paths);
free(dist);
return 0;
}

// генерація всіх можливих шляхів за допомогою алгоритму Нараяна (де n - кількість точок, p - кількість шляхів)
int narayanPermutations(int* paths, int n, int p)
{
int* a = (int*)malloc(n * sizeof(int));
if (a == NULL)
{
	fprintf(stdout, "memory allocation error\n");
	free(a);
	return 1;
}
for (int i = 0; i < n; i++)
{
	a[i] = i;
}
int i = 0;
while (i < p)
{
	for (int j = 0; j < n; j++)
	{
		paths[i * n + j] = a[j];
	}
	i++;
	nextPermutation(a, n);
}
free(a);
return 0;
}


// генерація наступної перестановки
int nextPermutation(int* a, int n)
{
int i = n - 2;
while (i != -1 && a[i] >= a[i + 1])
{
	i--;
}
if (i == -1)
{
	return 0;
}
int j = n - 1;
while (a[j] <= a[i])
{
	j--;
}
int temp = a[i]; // обмін елементів місцями методом бульбашки
a[i] = a[j];
a[j] = temp;
for (int k = i + 1; k < (n + i + 1) / 2; k++)
{
	temp = a[k]; // обмін елементів місцями методом бульбашки
	a[k] = a[n + i - k];
	a[n + i - k] = temp;
}
return 0;
}

// обчислення довжини шляхів
int calculatePathLenghts(int* paths, float* dist, int n, int p, int* x, int* y)
{
for (int i = 0; i < p; i++)
{
	dist[i] = 0;
	for (int j = 0; j < n - 1; j++)
	{
		dist[i] += distance(x[paths[i * n + j]], y[paths[i * n + j]], x[paths[i * n + j + 1]], y[paths[i * n + j + 1]]); //без повернення в початкову точку
	}
}
return 0;
}





// заповнення масивів випадковими числами
int fillarray(int* x, int* y, int n)
{
for (int i = 0; i < n; i++)
{
	x[i] = rand() % 1000; //діапозон для рандомного числа - від 0 до 1000
	y[i] = rand() % 1000;
}
return 0;
}

float distance(int x1, int y1, int x2, int y2)
{
return Q_rsqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// швидке обчислення квадратного кореня із DOOM за допомогою магічної константи. ДЯКУЮ ДЖОН КАРМАК! :*
float Q_rsqrt(float number)
{
const float x2 = number * 0.5F;
const float threehalfs = 1.5F;

union {
	float f;
	uint32_t i;
} conv = { number }; 
conv.i = 0x5f3759df - (conv.i >> 1);
conv.f *= threehalfs - x2 * conv.f * conv.f;
return 1/conv.f;
}