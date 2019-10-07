#include <math.h>
#include <iostream>
#include <math.h>
#include "dz6h.h"
using namespace std;

int* vved(int& n)
{
	cout << "Enter Number: ";

	cin >> n;
	cout << "Enter the array of size " << n << ": ";
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	return mas;
}

void print(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void task_arr_part1_1()
{
	cout << "Given integers N (> 2), A and B. Form and print an integer N array of size N, the first element of which is A, the second is B, and each subsequent element is equal to the sum of all previous ones" << endl;
	cout << "Enter N, a, b: ";
	int  a, b;
	int n;
	cin >> n >> a >> b;
	int* mas = new int[n];
	mas[0] = a;
	mas[1] = b;
	int s = a + b;
	for (int i = 2; i < n; i++)
	{
		mas[i] = s;
		s += mas[i];
	}
	print(mas, n);
}

void task_arr_part1_2()
{
	cout << "An integer array of size N is given. First, output all contents even numbers in the given array in the increasing order of their indices, and then all the odd numbers in descending order of their indexes" << endl;
	int n = 0;
	cin >> n;
	int* mas = vved(n);
	for (int i = 0; i < n; i++)
		if (mas[i] % 2 == 0)
			cout << mas[i] << " ";
	cout << endl;
	for (int i = n - 1; i >= 0; i--)
		if (mas[i] % 2 == 1)
			cout << mas[i] << " ";
	cout << endl;

}

void task_arr_part1_3()
{
	cout << "Given an array A of size N and an integer K (1 ≤ K ≤ N). Output Element You are an array with serial numbers that are multiples of K : AK, A2 · K, A3 · K, .... Do not use conditional statement." << endl;
	int n = 0, k;
	int* mas = vved(n);
	cout << "Enter K: ";
	cin >> k;
	while (k >= n)
	{
		cout << "Wrong K" << endl;
		cin >> k;
	}
	for (int i = k - 1; i < n; i += k)
		cout << mas[i] << " ";
	cout << endl;
}

void task_arr_part1_4()
{
	cout << "An array A of size N is given. Output its elements in the following order: A1, AN, A2, AN – 1, A3, AN – 2, ...." << endl;
	int n = 0;
	int* mas = vved(n);
	for (int i = 0; i < n / 2; i++)
		cout << mas[i] << " " << mas[n - 1 - i] << " ";
	if (n % 2 == 1) cout << mas[n / 2];
	cout << endl;

}

void task_arr_part2_1()
{
	cout << "An array of size N is given. Find the number of its first local minimum (local minimum is an element that is smaller than any of its neighbors)." << endl;
	int n = 0;
	int* mas = vved(n);
	for (int i = 0; i < n; i++)
		if (mas[i] < mas[i - 1] && mas[i] < mas[i + 1])
		{
			cout << i << endl;
			return;
		}
	cout << "there is no local minimum" << endl;
}

void task_arr_part2_2()
{
	cout << "An array of size N is given. Find the number of plots on which it elements monotonously increase." << endl;
	int n = 0;
	int* mas = vved(n);
	int soll = 0;
	bool ind = false;
	for (int i = 1; i < n; i++)
	{
		bool con = mas[i - 1] < mas[i] && mas[i] < mas[i + 1];
		if (con && !ind)
		{
			ind = true;
			soll++;
		}
		if (!con) ind = false;
	}
	cout << soll << endl;
}

void task_arr_part2_3()
{
	cout << "Given an integer array of size N. Find the number of different elements in this array." << endl;
	int n = 0;
	int* mas = vved(n);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		int um = 1;
		for (int j = 0; j < i; j++)
			if (mas[j] == mas[i])
				um = 0;
		num += um;
	}
	cout << num << endl;

}

void task_arr_part2_4()
{
	cout << "Given an integer array A of size N, which is a permutation (the definition of the permutation is given in the Array49 task).Find the amount of versions in this permutation, that is, such pairs of elements AIand AJ, in which the largest number is to the left of the smaller one : AI > AJ for I < J." << endl;
	int n = 0;
	int* mas = vved(n);
	int inver = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (mas[i] > mas[j]) inver++;
	cout << inver << endl;
}

void task_arr_part3_1()
{
	cout << "Given an integer array A of size N. Rewrite to a new integer numerical array B all even numbers from the original array(in the same row) and print the size of the resulting array B and its contents." << endl;
	int n = 0;
	int* mas = vved(n);
	int t = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] % 2 == 0) t++;
	if (t == 0)
	{
		cout << t << endl;
		cout << "No even number" << endl;
		return;
	}
	int* mas1 = new int[t];
	int index = 0;
	for (int i = 0; i < n; i++)
		if (mas[i] % 2 == 0)
		{
			mas1[index] = mas[i];
			index++;
		}
	cout << t << endl;
	print(mas1, t);
}

void task_arr_part3_2()
{
	cout << "Given an integer array A of size N. Rewrite to a new integer numerical array B of the same size at first all elements of the original array with even numbers, and then with odd numbers : A2, A4, A6, ..., A1, A3, A5, ...." << endl;
	int n = 0;
	int* a = vved(n);
	int* b = new int[n];
	for (int i = 1; i < n; i += 2)
	{
		b[(i - 1) / 2] = a[i];
	}
	for (int i = 0; i < n; i += 2)
	{
		b[i / 2 + n / 2] = a[i];
	}
	print(b, n);
}

void task_arr_part3_3()
{
	cout << "An array A of size N is given. Form a new array B of the same size. measure according to the following rule : the element BK is equal to the arithmetic sum elements of array A with numbers from K to N." << endl;
	int n = 0;
	int* a = vved(n);
	int* b = new int[n];
	int quant = 1;
	int sum = a[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		b[i] = sum / quant;
		sum += a[i - 1];
		quant++;
	}
	b[0] = sum / quant;
	print(b, n);

}

void task_arr_part3_4()
{
	cout << "Given three integer arrays A, B and C of size NA, NB, NC, respectively Actually, the elements of which are ordered in descending order.Combine these arrays so that the resulting integer array is D(of size NA + NB + NC) remained ordered in descending order." << endl;
	int na = 0;
	int nb = 0;
	int nc = 0;
	int* a = vved(na);
	int* b = vved(nb);
	int* c = vved(nc);
	int* d = new int[na + nb + nc];
	for (int i = 0; i < na + nb + nc; i++)
	{
		if (i < na) d[i] = a[i];
		else if (i < nb + na && i >= na) d[i] = b[i - na];
		else d[i] = c[i - na - nb];
	}
	for (int i = 0; i < na + nb + nc - 1; i++)
		for (int j = i + 1; j < na + nb + nc; j++)
			if (d[i] < d[j])
			{
				int r = d[i];
				d[i] = d[j];
				d[j] = r;
			}
	print(d, na + nb + nc);
}

void task_arr_part4_1()
{
	cout << "Given an integer array of size N. Increase all odd numbers, contained in the array, at the original value of the last odd number If there are no odd numbers in the array, then leave the array without changes." << endl;
	int n = 0;
	int* a = vved(n);
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 1) a[i]++;
	print(a, n);

}

void task_arr_part4_2()
{
	cout << "An array of size N is given. Reset the array elements located between its minimumand maximum elements(not including mini minimum and maximum elements)." << endl;
	int n = 0;
	int* a = vved(n);
	int max = a[0];
	int min = a[1];
	if (max < min)
	{
		int y = min;
		min = max;
		max = y;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max) max = a[i];
		if (a[i] < min) min = a[i];
	}
	bool ew = false;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == max || a[i] == min)
			ew = 1 - ew;
		if (ew && a[i] != max && a[i] != min) a[i] = 0;
	}
	print(a, n);
}

void task_arr_part4_3()
{
	cout << "An integer array of size N is given. Remove all elecops that occur exactly two times, and print the size of the resulting array its contents." << endl;
	int n = 0;
	int* a = vved(n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] == a[j]) a[j] = 0;
	print(a, n);
}

void task_arr_part4_4()
{
	cout << "An array of size N is given. After each negative element, insert an element with a zero value." << endl;
	int n = 0;
	int* a = vved(n);
	int k = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0) k++;
	int zsuv = 0;
	int* b = new int[n + k];
	for (int i = 0; i < n; i++)
	{
		b[i + zsuv] = a[i];
		if (a[i] < 0)
		{
			b[i + zsuv + 1] = 0;
			zsuv++;
		}
	}
	print(b, n + k);
}

void task_arr_part5_1()
{
	cout << "Given an integer array of size N. Insert after each series item with zero value." << endl;
	int n = 0;
	int* a = vved(n);
	for (int i = 0; i < n - 1; i++)
	{
		cout << a[i] << " ";
		if (a[i] != a[i + 1]) cout << 0 << " ";
	}
	cout << 0 << endl;
}

void task_arr_part5_2()
{
	cout << "Given an integer array of size N. Convert the array, increase-having made his first series of the greatest length by one element." << endl;
	int n = 0;
	int* a = vved(n);
	int maxd = 1;
	int mytd = 1;
	int poch = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1]) mytd++;
		else
		{
			if (mytd > maxd)
			{
				maxd = mytd;
				poch = i - maxd + 1;
			}
			mytd = 1;
			
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		if(i == poch)
			cout << a[i] << " ";
	}
	cout << endl;
}

void task_arr_part5_3()
{
	cout << "Given a set A of N points (points are given by their coordinates x, y).Among all the points of this set lying in the second quarter, we find This is the point farthest from the origin.If there are no such points, then print the point with zero coordinates." << endl;
	int n = 0;
	int* a = vved(n);
	float vids = 0;
	float maxvids = 0;
	int x = 0;
	int y = 0;
	for (int i = 0; i < n; i += 2)
	{
		if (a[i] < 0 && a[i+1] > 0)
			vids = sqrt(a[i] * a[i] + a[i + 1] * a[i + 1]);
		if (vids > maxvids)
		{
			x = a[i];
			y = a[i + 1];
			maxvids = vids;
		}
	}
	cout << x << "," << y << endl;
}

void task_arr_part5_4()
{
	cout << "Given a set A of N points with integer coordinates x, y. The order on the coordinate plane is defined as follows : (x1, y1) < (x2, y2) if either x1 < x2 or x1 = x2 and y1 < y2. Arrange the points of this set in ascending order according to specified order." << endl;
	int n = 0;
	int* a = vved(n);
	for (int i = 0; i < n; i += 2)
		for (int j = i + 2; j < n; j += 2)
		{
			bool t = a[i] == a[j] && a[i + 1] > a[j + 1];
			if (a[i] > a[j] || t)
			{
				int q = a[i];
				int w = a[i+1];
				a[i] = a[j];
				a[i+1] = a[j+1];
				a[j] = q;
				a[j + 1] = w;
			}
		}
	print(a, n);
}