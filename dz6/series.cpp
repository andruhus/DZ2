#include <math.h>
#include <iostream>
#include <vector>
#include "dz6h.h"
using namespace std;

int rish1(int k)
{
	int i = 0;
	bool q = true;
	int y = -1;
	cout << "Enter a new number with a new line " << endl;
	while (y != 0) {
		cin >> y;
		if (q)
		{
			if (y > k) q = false;
			else i++;
		}
	}
	return i;
}

void task1()
{
	cout << "Given an integer K and a set of nonzero integers; sign of his of completion - number 0. Print the number of the first number in the set greater than K. If there are no such numbers, then print 0." << endl;
	cout << "Enter K: ";
	int k;
	cin >> k;
	cout << "The index is " << rish1(k) + 1 << endl;
}

void rish2(int n)
{
	int y, w;
	cout << "Enter an integer with a new line" << endl;
	vector<int> a(n, 0);
	cin >> y;
	a[0] = y;
	for (int i = 1; i < n; i++)
	{
		cin >> w;
		if (y != w) a[i] = w;
		y = w;
	}
	for (int i = 0; i < n; i++)
		if (a[i] != 0) cout << a[i] << " ";
	cout << endl;
}

void task2()
{
	cout << "Given an integer N and a set of N integers ordered by ascending.This set may contain the same elements.You - keep in the same order all the different elements of this set." << endl;
	cout << "Enter N: ";
	int n;
	cin >> n;
	rish2(n);
}

void rish3(int n, int k)
{
	vector<long long int> a(n, 0);
	cout << "Enter your set of numbers ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] = pow(a[i], k);
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}

void task3()
{
	cout << "Given integers K, N and a set of N real numbers: A1, A2, ..., An. Print K - e degrees of numbers from a given set" << endl;
	cout << "Enter your N and K: ";
	int n, k;
	cin >> n >> k;
	rish3(n, k);

}

int rish4(int k)
{
	int t = 0;
	for (int i = 0; i < k; i++)
	{
		bool q = true;
		int y, z;
		y = -1;
		cin >> z;
		while (z != 0 && q)
		{
			if (z < y) q = false;
			y = z;
			cin >> z;
		}
		if (q) t++;

	}
	return t;
}

void task4()
{
	cout << "Given an integer K, as well as K sets of non-zero integers. Each set contains at least two elements, a sign of its completion is the number 0. Find the number of sets whose elements are ascending" << endl;
	cout << "Enter your K: ";
	int k;
	cin >> k;
	cout << rish4(k) << endl;
}

void rish5(int a, int& b)
{
	b = a * a * a;
}

void task5()
{
	cout << "Describe the PowerA3 (A, B) procedure that computes the third power of a number A and returning it in variable B(A - input, B - output pair - meter; both parameters are real).Using this procedurery find the third degree of five given numbers" << endl;
	cout << "Enter your a: ";
	int a, b;
	cin >> a;
	b = 0;
	rish5(a, b);
	cout << b << endl;
}

void rish6(int &a, int &b)
{
	if (a > b) { int y = a; a = b; b = y; }
}

void task6()
{
	cout << "Describe the Minmax(X, Y) procedure that writes to the variable X the minimum of the values ​​of X and Y, and in the variable Y, the maximum of of these values(X and Y are real parameters that are one - temporarily in and out).Using four calls of this procedures, find the minimumand maximum of the given numbers A, B, C, D." << endl;
	cout << "Enter A B C D: ";
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	rish6(a, b);
	rish6(c, d);
	rish6(a, c);
	rish6(b, d);
	cout << a << " " << d << endl;

}

float rish7(float a, float h)
{
	float b = sqrt(pow(a / 2, 2) + pow(h, 2));
	return (float)2 * b + a;
}

void task7()
{
	cout << "Describe the function TriangleP(a, h) that finds the perimeter of an isosceles triangle at its base a and height h drawn to the base (a and h are real).Use this function to find perimeters three triangles for which the bases and heights are given.For finding - side of the triangle b use the Pythagorean theorem" << endl;
	cout << "Enter your a,h: ";
	float a, h;
	cin >> a >> h;
	cout << rish7(a, h) << endl;

}

long long int rish8(int n)
{
	long long int y = 1;
	if (n % 2 == 0)
		for (int i = 2; i < n + 1; i += 2)
			y *= i;
	else
		for (int i = 3; i < n + 1; i += 2)
			y *= i;
	return y;
}

void task8()
{
	cout << "Describe the function Fact2 (N) of a real type that computes double (N > 0 is a parameter of an integer type; the real return value is used to avoid integer overflow when large values ​​of N).Use this function to find double factorials five given integers" << endl;
	cout << "Enter an integer ";
	int n;
	cin >> n;
	cout << rish8(n) << endl;

}