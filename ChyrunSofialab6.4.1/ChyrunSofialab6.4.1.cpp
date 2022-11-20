// ChyrunSofialab6.4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Lab_06_4.cpp
// < Чирун Софія >
// Лабораторна робота № 6.4.1
// Опрацювання та впорядкування одновимірних динамічних масивів   
// Варіант 18

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int Create(double* a, int size, const double Low, const double High)
{
	for (int i = 0; i < size; i++) 
	{
		a[i] = rand() % (int)pow(10, 2);
		a[i] = Low + (a[i] / pow(10, 2)) * (High - Low);
	}
	return *a;
}

double Sum(double* mas, int size) 
{
	double s = 0;
	for (int i = 0; i < size; i++)
		s += mas[i];
	return s;
}

int SumCriteria(double* mas, int size)
{
	int s = 0, l = size, i, k = 0;
	for (i = size - 1; i >= 0; i--)
		if (mas[i] < 0) 
		{
		   l = i;
		   break;
		}
	k = i + 1;
	if (l < size - 1)
	   for (int i = l + 1; i < size; i++)
		   s += trunc(mas[i]);
	if (k == 0)
	   for (i = 0; i < size; i++)
		   s += trunc(mas[i]);
	return s;
}

int Count(double* mas, int size, int C) 
{
	int s = 0;
	for (int i = 0; i < size; i++)
		if (mas[i] < C)
		   s++;
	return s;
}

void Print(double* a, int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(7) << a[i];
	    cout << endl;
}

int Max(double* a, int size)
{
	double max = a[0];
	int l = 0;
	for (int i = 1; i < size; i++)
		if (a[i] > max)
		{
		   max = a[i];
		   l = i;
		}
    cout << "max = " << max << endl;
	return l + 1;
}

void Sort(double* a, int size, int imax)
{
	double l;
	l = a[imax];
	a[imax] = a[0];
	a[0] = l;
	int j = 1;
	for (int i = 1; i < size; i++)
		if (a[i]<(a[0] + a[0] * 0.2) && a[i] > (a[0] - a[0] * 0.2))
		{
		   l = a[i];
		   a[i] = a[j];
		   a[j] = l;
		   j++;
		}
}

int main()
{
	srand((unsigned)time(NULL)); 
	int n, C;
	cout << "n="; cin >> n; cout << endl;
	double* a = new double[n]; 
	double Low = -99;
	double High = 99;
	int imax;
	Create(a, n, Low, High);
	Print(a, n);
    cout << endl << "Sall = " << Sum(a, n) << endl;
	cout << "C="; cin >> C; cout << endl;
	cout << "Count=" << Count(a, n, C) << endl;
	cout << "SumCount=" << SumCriteria(a, n) << endl;
	imax = Max(a, n);
	cout << "iMax=" << imax << endl;
    Sort(a, n, imax - 1);
	Print(a, n);
	return 0;
}
