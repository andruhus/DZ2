#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)
#include "modulsh.h"
using namespace std;




/*static char* enterchar(char* a, int& n, char t)
{
	n++;
	char* b = new char[n];
	for (int i = 0; i < n - 1; i++)
	{
		b[i] = a[i];
	}
	b[n - 1] = t;
	delete[] a;
	return b;
}*/




void task6()
{
	FILE* f = fopen("C:\\Users\\aaade\\Desktop\\Files for labs\\text.txt", "r");
	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	int i = 0;
	bool flag = false;
	while (i <= strlen(text) - 2)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			text[i] = 32;
			text[i + 1] = 32;
			i += 2;
			while (i <= strlen(text) - 1)
			{
				//if (text[i] == 32)
					//flag = true;
				// if (flag) break;
				if (text[i] == 10)
				{
					cout << endl;
					break;
				}
				cout << text[i];
				text[i] = 32;
				i++;
			}
		}
		// if (flag) break;
		i++;
	}
	fclose(f);
	f = fopen("C:\\Users\\aaade\\Desktop\\Files for labs\\text.txt", "w");
	fwrite(text, sizeof(char), 1000, f);
	fclose(f);
}








class Vector
{
public:
	double x = 1, y = 1;
	void Const(double c)
	{
		x *= c; y *= c;
	}
	double Norm()
	{
		return sqrt(x * x + y * y);
	}
	void Onscreen()
	{
		cout << x << " " << y << endl;
	}
	void Infile(ofstream& a)
	{
		a << x << " " << y;
	}
};

Vector sum(Vector a, Vector b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

double mul(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

void task7()
{
	ofstream q;
	q.open("C:\\Users\\aaade\\Desktop\\Files for labs\\4.txt");
	Vector a;
	Vector b;
	Vector c;
	char wer;
	cin >> wer;
	switch (wer)
	{
	case 's': c = sum(a, b); break;
	case 'm': cout << mul(a,b); break;
	case 'n': cout << c.Norm(); break;
	case 'c':  c.Const(2); break;
	case 'f': c.Infile(q); break;
	case 'v': c.Onscreen(); break;
	default: cout << "We dont know your function" << endl; break;

	}
	q.close();


}








int intcast(char* s, int& i)
{
	int temp = 0;
	int sign = 0;
	if (s[i] == '-')
	{
		sign = 1;
		i++;
	}
	while ((int)s[i] >= 48 && (int)s[i] <= 57)
	{
		temp += ((int)s[i] - 48);
		temp *= 10;
		i++;
	}
	temp /= 10;
	if (sign == 1)
		temp = -temp;
	return temp;
}

void task8()
{
	FILE* f = fopen("C:\\Users\\aaade\\Desktop\\Files for labs\\3.txt", "r");
	char text[1000] = { '\0' };
	fread(text, sizeof(char), 1000, f);
	fclose(f);
	int i = 0;
	int n = intcast(text, i);
	int* tmp = new int[n * n];
	int** a1 = new int* [n];
	int** a2 = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a1[i] = new int[n];
		a2[i] = new int[n];
	}
	int j = 0;
	while (j < n * n)
	{
		i++;
		tmp[j] = intcast(text, i);
		j++;
	}
	int itr = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
		{
			a1[i][j] = tmp[itr];
			a2[i][j] = tmp[itr];
			itr++;
		}
	}

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a1[i][j] == a1[n - 1 - j][n - 1 - i])
			{
				a1[i][j] = 0;
				a1[n - 1 - j][n - 1 - i] = 0;
			}
		}


	for (i = 0; i < n - 1; i++)
		for (j = 1 + i; j < n - 1; j++)
		{
			if (a2[i][j] == a2[j][i])
			{
				a2[i][j] = 0;
				a2[j][i] = 0;
			}
		}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a1[i][j] == 0 || a2[i][j] == 0) a1[i][j] = 0;
			cout << a1[i][j] << " ";
		}
		cout << endl;
	}
}






long int binom(int n, int k)
{
	if (n == k || k == 0)
		return 1;
	else
		return binom(n - 1, k - 1) + binom(n - 1, k);
}

void task9()
{
	int n, k;
	cin >> n >> k;
	cout << binom(n, k);
}