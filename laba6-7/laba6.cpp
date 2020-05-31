#include "laba6.h"
#include <math.h>
#pragma warning (disable : 4996)
using namespace std;
char file[64] = "Graph.bin";

Pol operator +(Pol a1, Pol a2)
{
	Pol res;
	if (a1.max_deg > a2.max_deg)
		res.max_deg = a1.max_deg;
	else
		res.max_deg = a2.max_deg;

	for (int i = 0; i <= res.max_deg; i++)
	{
		res.arr[i] = a1.arr[i] + a2.arr[i];
	}
	return res;
}
Pol operator -(Pol a1, Pol a2)
{
	Pol res;
	if (a1.max_deg > a2.max_deg)
		res.max_deg = a1.max_deg;
	else
		res.max_deg = a2.max_deg;

	for (int i = 0; i <= res.max_deg; i++)
	{
		res.arr[i] = a1.arr[i] - a2.arr[i];
	}
	return res;
}
void Pol::Print()
{
	cout << "The cronomial polynom is: ";
	for (int i = max_deg; i >= 0; i--)
	{
		cout << arr[i] << "*x^" << i;
		if (i != 0)
			cout << " + ";
	}
	cout << endl;
}
int Pol::Substitution(int x)
{
	int res = 0;
	for (int i = 0; i <= max_deg; i++)
	{
		res += (int)(pow(x, i) * arr[i]);
	}
	return res;
}
Graph::Graph()
{

}
void Graph::Write()
{
	FILE* f;
	f = fopen(file, "wb");
	fwrite(&number_of_vertix, sizeof(int), 1, f);
	for (int i = 0; i < number_of_vertix; i++)
	{
		for (int j = 0; j < number_of_vertix; j++)
			fwrite(&matrix[i][j], sizeof(bool), 1, f);

	}
	fclose(f);
}
void Graph::Set_Graph()
{
	cout << "How many vertices do you have: ";
	cin >> number_of_vertix;
	cout << "Now enter the matrix" << endl;
	matrix = new bool* [number_of_vertix];
	for (int i = 0; i < number_of_vertix; i++)
	{
		matrix[i] = new bool[number_of_vertix];
		for (int j = 0; j < number_of_vertix; j++)
			matrix[i][j] = 0;
	}



	for (int i = 0; i < number_of_vertix; i++)
	{
		for (int j = 0; j < number_of_vertix; j++)
		{

			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < number_of_vertix; i++)
		matrix[i][i] = 0;
	Write();
}
void Graph::Get_File()
{
	FILE* f;
	f = fopen(file, "rb");
	fread(&number_of_vertix, sizeof(int), 1, f);
	matrix = new bool* [number_of_vertix];
	for (int i = 0; i < number_of_vertix; i++)
	{
		matrix[i] = new bool[number_of_vertix];
	}


	for (int i = 0; i < number_of_vertix; i++)
		for (int j = 0; j < number_of_vertix; j++)
			fread(&matrix[i][j], sizeof(bool), 1, f);
	fclose(f);
}

bool Graph::Is_Empty()
{
	for (int i = 0; i < number_of_vertix; i++)
	{
		for (int j = 0; j < number_of_vertix; j++)
			if (matrix[i][j] != 0)
				return false;

	}
	return true;
}

Graph Graph::Extract_Edge(int i, int j)
{
	Graph a;
	a.number_of_vertix = number_of_vertix;
	a.matrix = new bool* [a.number_of_vertix];
	for (int i = 0; i < a.number_of_vertix; i++)
		a.matrix[i] = new bool[a.number_of_vertix];
	for (int k = 0; k < number_of_vertix; k++)
	{
		for (int m = 0; m < number_of_vertix; m++)
		{
			a.matrix[k][m] = matrix[k][m];
		}

	}
	a.matrix[i][j] = 0;
	a.matrix[j][i] = 0;
	return a;
}

void Colomn_Contracton(bool* a, int size, int min, int max, bool* res)
{
	for (int i = 0; i < size; i++)
	{
		if (i < max)
			res[i] = a[i];
		else if (i == max)
			res[min] = res[min] || a[i];
		else
			res[i - 1] = a[i];
	}
}
Graph Graph::Edge_Contraction(int i, int j)
{
	Graph a;
	a.number_of_vertix = number_of_vertix - 1;
	a.matrix = new bool* [a.number_of_vertix];
	for (int i = 0; i < a.number_of_vertix; i++)
		a.matrix[i] = new bool[a.number_of_vertix];
	int min, max;
	if (i > j)
	{
		max = i; min = j;
	}
	else
	{
		min = i; max = j;
	}

	for (int k = 0; k < number_of_vertix; k++)
	{
		if (k == max)
		{
			for (int m = 0; m < number_of_vertix; m++)
			{
				if (m == max)
					a.matrix[min][min] = a.matrix[min][min] && matrix[k][m];
				else if (m > max)
					a.matrix[min][m - 1] =a.matrix[min][m-1] || matrix[k][m];
				else
					a.matrix[min][m] = a.matrix[min][m] ||  matrix[k][m];


			}
		}
		else if (k > max)
		{
			for (int m = 0; m < number_of_vertix; m++)
			{
				if (m == max)
					a.matrix[k - 1][min] = a.matrix[k - 1][min] && matrix[k][m];
				else if (m > max)
					a.matrix[k - 1][m - 1] = matrix[k][m];
				else
					a.matrix[k - 1][m] = matrix[k][m];


			}
		}
		else
		{
			for (int m = 0; m < number_of_vertix; m++)
			{
				if (m == max)
					a.matrix[k][min] = a.matrix[k][min] && matrix[k][max];
				else if (m > max)
					a.matrix[k][m - 1] = matrix[k][m];
				else
					a.matrix[k][m] = matrix[k][m];


			}
		}
	}

	return a;
}


Pol Answ_Get(Graph a)
{

	if (a.Is_Empty())
	{
		Pol b;
		b.max_deg = a.number_of_vertix;
		b.arr[b.max_deg] = 1;
		return b;
	}
	for (int i = 0; i < a.number_of_vertix; i++)
		for (int j = 0; j < a.number_of_vertix; j++)
			if (a.matrix[i][j] == 1 || a.matrix[j][i] == 1)
				return Answ_Get(a.Extract_Edge(i, j)) - Answ_Get(a.Edge_Contraction(i, j));


}



void Set_Graph()
{
	Graph a;
	a.Set_Graph();
	cout << "The graph is successfully added" << endl;
}
void Get_Polynom()
{
	system("cls");
	Graph a;
	a.Get_File();
	Pol b = Answ_Get(a);
	b.Print();

	cout << "The chronomial number is ";
	for (int k = 1; k <= a.number_of_vertix; k++)
	{
		if (b.Substitution(k) > 0)
		{
			cout << k << endl;
			system("pause");
			return;
		}
	}




}