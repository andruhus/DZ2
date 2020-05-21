#include "Module.h"
#include <iostream>
#include <conio.h>
using namespace std;

bool operator > (Data v1, Data v2)
{
	return true;
}

bool operator < (Data v1, Data v2)
{
	return true;
}

void Graph::Set_Graph()
{
	cout << "Enter the number of vertices: ";
	cin >> vert_num;

	matrix = new int* [vert_num];
	for (int i = 0; i < vert_num; i++)
	{
		matrix[0] = new int[vert_num];
	}

	cout << endl << "Now enter the edges:" << endl;
	cout << "EXAMPLE 1 -> 2 (index of vertix can vary from 1 to n - number of vertices)" << endl;
	
	int v1, v2;
	bool Continue = true;
	do
	{
		cout << "Press 1 to continue, 0 to stop" << endl;
		cin >> Continue;
		if (Continue)
		{
			do
			{
			cin >> v1;
			} while (v1 < vert_num + 1);
			do
			{
			cin >> v2;
			} while (v2 < vert_num + 1);

			matrix[v1 - 1][v2 - 1] = 1;
			
		}
	} while (Continue);

	
	
}

Node* nwnode(Data v, Node* pl, Node* pr, Node* kor) {
	Node* p = new Node;
	p->data = v;
	p->left = pl;
	p->right = pr;
	p->root = kor;
	return p;
}
Node* insert(Node* p, Data v, Node* kor) {
	if (!p)
		return nwnode(v, NULL, NULL, kor);
	if (p->data > v)
		p->left = insert(p->left, v, p);

	else if (p->data < v)
		p->right = insert(p->right, v, p);
	else
		p->right = insert(p->right, v, p);
	return p;
}