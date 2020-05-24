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

bool operator == (Data v1, Data v2)
{
	
	for (int i = 0; i < v1.data_size; i++)
		if (v1.data[i] != v2.data[i])
			return false;
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
				cout << "enter the first vertix: ";
				cin >> v1;
			} while (v1 > vert_num);
			do
			{
				cout << "enter the second vertix: ";
				cin >> v2;
			} while (v2 > vert_num);

			matrix[v1 - 1][v2 - 1] = 1;

		}
	} while (Continue);



}

// Gets nullptr Node tree
Node* Set_Tree(Node* tree)
{
	tree = new Node;

	cout << "Write something: ";
	char input[64];
	bool want_l,want_r = false;


	cin >> input;

	for (int i = 0; i < 64; i++)
	{
		tree->data.data[i] = input[i];
	}

	cout << "Do you want a left branch: ";
	cin >> want_l;
	if (want_l)
	{
		cout << endl;
		cout << "Diving to the left..." << endl;
		tree->left = Set_Tree(tree->left);
		tree->left->root = tree;
		cout << "Returnng from the left" << endl;
		cout << endl;
	}



	cout << "Do you want a right branch: ";
	cin >> want_r;
	if (want_r)
	{
		cout << endl;
		cout << "Diving to the right..." << endl;
		tree->right = Set_Tree(tree->right);
		tree->right->root = tree;
		cout << "Returnng from the right" << endl;
		cout << endl;
	}

	return tree;
}

void Node::Display()
{
	if (!this)
	{
		system("cls");
		cout << "Set the tree at first" << endl;
		system("pause");
		return;

	}
	Node* temp = this;
	int ch;
	do {

		temp->Print_Data();
		ch = _getch();
		char c = (char)ch;
		if (temp)
		{
			if (c == 'w')
				temp = temp->root;
			if (c == 'a')
				temp = temp->left;
			if (c == 'd')
				temp = temp->right;
		}

	} while (ch != 13 && temp);
}


void Node::Print_Data()
{
	cout << "The data:  ";
	for (int i = 0; i < this->data.data_size && this->data.data[i]>0; i++)
	{
		cout << this->data.data[i];
	}

	cout << endl;
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