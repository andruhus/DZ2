#include <iostream>
#include <math.h>
using namespace std;

int suma(int* a, int n)
{
	int q = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0)
			q += a[i];
	return q;
}

int dobutok(int* a, int n)
{
	int max = abs(a[0]);
	int inmax = 0;
	int min = abs(a[1]);
	int inmin = 1;
	if (max < min)
	{
		inmax = 1;
		inmin = 0;
		int j = max;
		max = min;
		min = j;
	}
	for (int i = 0; i < n; i++)
	{
		if (abs(a[i]) > max)
		{
			max = abs(a[i]);
			inmax = i;
		}
		if (abs(a[i]) < min)
		{
			min = abs(a[i]);
			inmin = i;
		}

	}
	if (inmin < inmax)
	{
		int j = inmax;
		inmax = inmin;
		inmin = j;
	}
	int dob = 1;
	for (int i = inmax; i <= inmin; i++)
		dob *= a[i];
	return dob;
}

void poradok(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
		for (int j = i+1; j < n; j++)
			if (a[i] < a[j])
			{
				int y = a[i];
				a[i] = a[j];
				a[j] = y;
			}
}

void sevenoct()
{
	int n;
	cin >> n;
	while (n <= 1)
	{
		cout << "Wrong N" << endl;
		cin >> n;
	}
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	int sum = suma(mas, n);
	int dob = dobutok(mas, n);
	poradok(mas, n);
	cout << sum << " " << dob << endl;
	int* parr = mas;
	for (int i = 0; i < n; i++)
	{
		cout << *parr << " ";
		parr++;
	}
		
}