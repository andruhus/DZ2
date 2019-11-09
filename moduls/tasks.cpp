#include <iostream>
#include <conio.h>
#include "modulsh.h"
#include <math.h>
#include <string>
using namespace std;

void swarer(int n, int** a, int* chart, int j, int q)
{
	for (int i = 0; i < n; i++)
	{
		int temp = a[i][j];
		a[i][j] = a[i][q];
		a[i][q] = temp;
	}
	int y = chart[j];
	chart[j] = chart[q];
	chart[q] = y;
}

int partition(int *arr,int low,int high,int n,int**a)
{
	// pivot (Element to be placed at right position)
	int pivot = arr[high];

	int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than the pivot
			if (arr[j] < pivot)
			{
				i++;    // increment index of smaller element
				swarer(n, a, arr, i, j);
			}
		}
		swarer(n, a, arr, i + 1, high);
		return (i + 1);
}

void quickSort(int*arr,int low,int high,int n,int**a)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[pi] is now
		   at right place */
		int pi = partition(arr, low, high,n,a);

		quickSort(arr, low, pi - 1,n,a);  // Before pi
		quickSort(arr, pi + 1, high,n,a); // After pi
	}
}

long long int fact(int i)
{
	long long int fac = 1;
	while (i > 0)
	{
		fac *= i;
		i--;
	}
	return fac;
}

float count(float eps)
{
	int i = 0;
	float sum = 0;
	while (abs(pow(-2, i) / fact(i)) >= eps)
	{
		sum += pow(-2, i) / fact(i);
		i++;
	}
	return sum;
}

void triangle(int n, int m)
{
	int num = 1;
	for (int i = 0; i < n; i++)
	{

		float x1, x2, x3, y1, y2, y3;
		x1 = rand() % (2 * m) - m;
		x2 = rand() % (2 * m) - m;
		x3 = rand() % (2 * m) - m;
		y1 = rand() % (2 * m) - m;
		y2 = rand() % (2 * m) - m;
		y3 = rand() % (2 * m) - m;
		if (abs((x3 - x1) * (x2 - x1) + (y3 - y1) * (y2 - y1)) <= 0.1)
		{
			cout << num << " point" << endl;
			cout << "a:" << x1 << " " << y1 << endl;
			cout << "b:" << x2 << " " << y2 << endl;
			cout << "c:" << x3 << " " << y3 << endl;
			num++;
			cout << endl;
		}
		if (abs((x3 - x2) * (x1 - x2) + (y3 - y2) * (y1 - y2)) <= 0.1)
		{
			cout << num << " point" << endl;
			cout << "a:" << x1 << " " << y1 << endl;
			cout << "b:" << x2 << " " << y2 << endl;
			cout << "c:" << x3 << " " << y3 << endl;
			num++;
			cout << endl;
		}
		if (abs((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3)) <= 0.1)
		{
			cout << num << " point" << endl;
			cout << "a:" << x1 << " " << y1 << endl;
			cout << "b:" << x2 << " " << y2 << endl;
			cout << "c:" << x3 << " " << y3 << endl;
			num++;
			cout << endl;
		}
		
	}
	cout << "That is all" << endl;
}

int firstT(char* a, char* t, int na, int nt)
{
	int z = 0;
	for (int i = 0; i < na - nt + 1; i++)
	{
		bool l = true;
		for (int k = 0; k < nt; k++)
		{
			if (t[k] != a[i + k])
			{
				l = false;
			}
		}
		if (l)
			z = i;
	}
	return z;
	
}

bool isPol(char* a, int n)
{
	for (int i = 0; i < n / 2; i++)
		if (a[i] != a[n - 1 - i])
			return false;
	return true;

}

char* polindr(char* a, int &n)
{
	for (int i = 0; i < n; i++)
	{
		char* b = new char[n + i];
		for (int j = 0; j < n; j++)
			b[j] = a[j];
		for (int j = n; j < n + i; j++)
			b[j] = a[n + i - j - 1];
		if (isPol(b, n + i))
		{
			n = n + i;
			return b;
		}
	}
}

void task5solution(int** a, int m, int n)
{
	int* chart = new int[m];

	for (int j = 0; j < m; j++)
	{
		int p = 0;

		for (int i = 0; i < n; i++)
			if (a[i][j] < 0 && abs(a[i][j]) % 2 != 0) p += abs(a[i][j]);

		chart[j] = p;
	}

	quickSort(chart, 0, m-1,n,a);



	for (int i = 0; i < m; i++)
	{
		cout << chart[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] <<" ";
		cout << endl;
	}
}

void task1()
{
	float eps;
	cout << "Enter eps: ";
	cin >> eps;
	cout << count(eps) << endl;
}

void task2()
{
	int n;
	int m;
	cout << "Enter the number of points: ";
	cin >> n;
	cout << "Enter the interval: ";
	cin >> m;
	triangle(n, m);
}

void task3()
{
	int nt, na;
	cout << "enter the size of a great string: ";
	cin >> na;
	cout << "enter the great string ";
	char* a = new char[na];
	for (int i = 0; i < na; i++)
		cin >> a[i];
	cout << "enter the size of a small string: ";
	cin >> nt;
	cout << "enter the small string ";
	char* t = new char[nt];
	for (int i = 0; i < nt; i++)
		cin >> t[i];
	cout << "The first index is " << firstT(a, t, na, nt)+1 << endl;
}

void task4()
{
	int n = 0;
	cout << "Enter the size of the string: ";
	string temp = "";
	while (temp == "")
	{
		getline(cin, temp);
	}
	bool Anumber = 1;
	for (char t : temp)
		if (t < 48 || t > 57)
			Anumber = 0;
	cout << endl;
	if (Anumber)
	{
		for (int i = 0; i < temp.size(); i++)
			n += ((temp[i] - 48) * pow(10,temp.size() - i - 1));
		cout << "I consider your n as a number" << endl;
	}
	else
	{
		for (char q : temp)
			n += (int)q;
		cout << "I consider your n as a string, which I have converted in number" << endl;
	}
	cout << endl;
	if (n > 100)
	{
		cout << "Your n is " << n << " but n must be less than 100" << endl;
		cout << "so n = " << n % 100 << endl;
		n = n % 100;
	}
	else
	{
		cout << "Your n is " << n << endl;
	}
	cout << "Now enter your string: ";
	char* a = new char[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	a = polindr(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void task5()
{
	int m, n;
	cout << "Enter the size of the matrix" << endl;
	cin >> n >> m;
	cout << "Now enter the matrix" << endl;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	task5solution(a, m, n);
}
