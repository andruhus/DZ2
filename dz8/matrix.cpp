#include <iostream>
#include "dz8h.h"
using namespace std;



int** vved(int& n, int& m)
{
	cout << "Enter Number of rows: ";
	cin >> n;
	cout << "Enter Number of columns: ";
	cin >> m;
	cout << "Now enter the matrix" << endl;
	int** mas = new int* [n];
	for (int i = 0; i < n; i++)
		mas[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
	return mas;
}

void gity(int** a, int n,int q)
{
	for (int i = q; i < n - q; i++)
		cout << a[q][i] << " ";

	for (int i = q + 1; i < n - q; i++)
		cout << a[i][n - 1-q] << " ";

	for (int i = n - 2 - q; i >= q; i--)
		cout << a[n - 1 - q][i] << " ";

	for (int i = n - 2 - q; i >= q+1; i--)
		cout << a[i][q] << " ";
	q++;
	if (q < n / 2)
		gity(a, n, q);
	else
		return;
}


void swap(int& a, int& b)
{
	int y = a;
	a = b;
	b = y;
}

int pos(int* a, int poch, int kin)
{
	int pivot = a[poch];
	int i = poch +1;
	int j = kin;
	while(i<j)
	{ 
	do
	{
		i++;
	} while (a[i] <= pivot);
	do{
		j--;
	} while (a[j] >= pivot);
	if (i < j) swap(a[i], a[j]);
	}
	return j;
}

void Quick_sort(int* a, int poch, int kin)
{
	if (poch < kin)
	{
		int j = pos(a, poch, kin);
		Quick_sort(a, poch, j-1);
		Quick_sort(a, j+1, kin);

	}
}

void task1()
{
	cout << "	An M × N matrix is given. Derive its elements located in columns with odd numbers(1, 3, ...).Output items to produce column - wise, do not use conditional operator." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colms; j += 2)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void task2()
{
	cout << "	A square matrix A of order M is given (M is an odd number). Start-first from element A1, 1 and moving counterclockwise, output all of it spiral elements : first column, last row, last table - bets in reverse order, first line in reverse order, remaining twenty elements of the second column, etc .; the last one displays the central cop matrix." << endl;
	int rows = 0, colms = 0;
	cout << "!!!WARNING!!! Enter the equal number of rows and columns" << endl;
	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);
	int q = 0;
	gity(mas,rows,q);
	if (rows % 2 == 1)
		cout << mas[rows / 2][rows / 2];
	cout << endl;
}

void task3()
{
	cout << "	A matrix of size M × N is given. Find row and column numbers for element of the matrix closest to the average value of all its ele -cops." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	float ser = 0.0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colms; j++)
			ser += (float)mas[i][j];
	ser /= ((float)rows * (float)colms);


	int y = 0, w = 0;
	float e = abs((float)mas[0][0] - ser);

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < colms; j++)
			if (abs((float)mas[i][j] - ser) < e)
			{ 
				e = abs( (float)mas[i][j] - ser );
				y = i;
				w = j;
			}
	cout << y+1 << " " << w+1 << endl;
}

void task4()
{
	cout << "	Given an integer matrix of size M × N. Find its number rows, all of whose elements are different." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	for (int i = 0; i < rows; i++)
	{
		int q = mas[i][0];
		bool z = 0;
		for (int j = 0; j < colms; j++)
			if (q != mas[i][j])
				z++;
		if (z)
		{
			for (int j = 0; j < colms; j++)
				cout << mas[i][j] << " ";
			cout << endl;
		}
	}
}

void task5()
{
	cout << "	Given a matrix of size M × N. Find the maximum among the elements those columns that are ordered either ascending or descending niyu.If there are no ordered columns in the matrix, then print 0." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	int res = 0;

	for (int i = 0; i < rows; i++)
	{
		bool k = 1;
		int u = mas[i][0];
		int u_ind = 0;
		for (int j = 1; j < colms; j++)
			if (mas[i][j] > u)
			{
				u = mas[i][j];
				u_ind = j;
			}
		for (int x = 0; x < rows; x++)
			if (mas[i][u_ind] > mas[x][u_ind])
				k = false;
		if (k) res = u;
	}

	cout << res << endl;

}

void task6()
{
	cout << "	A matrix of size M × N is given (N is an even number). Swap left and right halves of the matrix." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	for (int i = 0; i < rows/2; i++)
		for (int j = 0; j < colms; j++)
		{
			int t = mas[i][j];
			mas[i][j] = mas[rows - 1 - i][colms - 1 - j];
			mas[rows - 1 - i][colms - 1 - j] = t;
		}

	for (int i = 0; i < rows; i++)
	{ 
		for (int j = 0; j < colms; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void task7()
{
	cout << "	Given a matrix of size M × N and an integer K (1 ≤ K ≤ N). After column matrix with number K insert a column of units." << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	int k; cin >> k;
	
	int** mas1 = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas1[i] = new int[colms+1];

	for (int i = 0; i < colms + 1; i++)
	{
		if (i <= k)
			for (int j = 0; j < rows; j++)
				mas1[j][i] = mas[j][i];
		else if (i == k + 1)
			for (int j = 0; j < rows; j++)
				mas1[j][i] = 1;
		else
			for (int j = 0; j < rows; j++)
				mas1[j][i] = mas[j][i -1];
	}
		
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colms+1; j++)
			cout << mas1[i][j] << " ";
		cout << endl;
	}
		
}

void task8()
{
	cout << "	Given a matrix of size M × N. Arrange its rows so that their the first elements formed an increasing sequence" << endl;
	int rows = 0, colms = 0;

	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);

	for (int i = 0; i < rows; i++)
		Quick_sort(mas[i], 0, colms-1);


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colms; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
}

void task9()
{
	cout << "	A square matrix A of order M is given. Find the arithmetic mean elements of each diagonal parallel to the side(starting with singleton diagonal A1, 1)." << endl;
	int rows = 0, colms = 0;
	cout << "!!!WARNING!!! Enter the equal number of rows and columns" << endl;
	int** mas = new int* [rows];
	for (int i = 0; i < rows; i++)
		mas[i] = new int[colms];

	mas = vved(rows, colms);
	int* serlintrap = new int[rows];
	for (int i = 0; i < rows; i++)
	{

		serlintrap[i] = 0;
		int o = i;
		int j = rows - 1;
		while (j > 0 && o < rows - 1)
		{
			serlintrap[i] += mas[i][j];
			j--;
			o++;
		}
		serlintrap[i] /= (i + 1);
		cout << i << serlintrap[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
		cout << serlintrap[i] << " ";
	cout << endl;
}