#include <iostream>
#include <math.h>
#include "class_h.h"
using namespace std;

bool per(int a, int i, int j, int n, int m)
{
	if (a == 1)
		return i == 0 || j == 0 || i == n - 1 || j == m - 1;
	else if (a == 2)
		return i == 0 || j == 0 || i + j == n - 1;
	else if (a == 3)
		return j == m - 1 || i + j == int(n / 2) || i - j == int(n / 2);
	else if (a == 4)
		return i + j == int(n / 2)  || i - j == int(n / 2) || i + j == 3 * int(n / 2)|| j - i == int(n / 2);

}

void paint()
{
	int n, m,a;
	cout << "What you want to be painted?" << endl;
	cin >> a;
	switch(a)
	{
	case 1: cout << "Enter 2 integers "; cin >> n >> m; break;
	case 2: cout << "Enter an integer "; cin >> n; m = n; break;
	case 3: cout << "Enter an integer "; cin >> n; m = n * 2; n *= 4; break;
	case 4: cout << "Enter an integer "; cin >> n; n *= 2; n++; m = n; break;
	default: cout << "I can not paint this " << endl; break;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (per(a, i, j, n, m)) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

}