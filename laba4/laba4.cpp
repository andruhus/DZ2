#include <iostream>
#include <conio.h>
#include "laba4h.h"
using namespace std;

const int num_of_oper = 5;
char al_operators[num_of_oper] = { '+','-','*','/','^' };

bool Is_digit(char* a, int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] < 48 || a[i] > 57)
			return false;
	return true;
}

Node* tree = nullptr;
Node* get_tree(char* str, int size, Node* root = nullptr)
{
	// declareation
	Node* novel_root = new Node;
	char* left_str;
	char* right_str;
	char* sub_str;

	// str analysis
	if (str[0] == al_operators[1])
	{
		sub_str = new char[size + 1];
		sub_str[0] = '0';
		for (int i = 0; i < size; i++)
			sub_str[i + 1] = str[i];
		return get_tree(sub_str, size + 1, root);
	}

	if (str[0] == '(')
	{
		bool Has_Bracket = true;
		for (int i = 0; i < size - 1; i++)
		{
			if (str[i] == ')')
				Has_Bracket = false;

		}
		if (Has_Bracket)
		{
			sub_str = new char[size - 2];

			for (int i = 1; i < size - 1; i++)
				sub_str[i - 1] = str[i];
			return get_tree(sub_str, size - 2, root);
		}
	}

	// execution
	for (int i = 0; i < num_of_oper; i++)
	{
		for (int j = size - 1; j >= 0; j--)
		{
			if (str[j] == al_operators[i])
			{
				left_str = new char[j];
				right_str = new char[size - j - 1];
				for (int k = 0; k < size; k++)
				{
					if (k < j)
						left_str[k] = str[k];

					if (k > j)
						right_str[k - j - 1] = str[k];
				}

				novel_root->data_size = 1;
				novel_root->data = new char[1];
				novel_root->data[0] = al_operators[i];

				novel_root->left = get_tree(left_str, j, novel_root);
				novel_root->right = get_tree(right_str, size - j - 1, novel_root);
				novel_root->root = root;

				return novel_root;
			}

			if (str[j] == ')')
			{
				while (str[j] != '(')
					j--;
			}
		}
	}

	novel_root->data_size = size;
	novel_root->data = str;


	novel_root->left = nullptr;
	novel_root->right = nullptr;
	novel_root->root = root;

	return novel_root;
}

void Node_Display(Node* a)
{
	system("cls");
	if (!a)
	{
		cout << "Null" << endl;
		system("pause");
		return;
	}

	for (int i = 0; i < a->data_size; i++)
		cout << a->data[i];

	cout << endl << endl;
	cout << "If you want to take left - press a" << endl;
	cout << "If you want to take right - press d" << endl;
	cout << "If you want to take root - press w" << endl;
}

int Calc_res(Node* a)
{
	int number = 0;
	if (a->data[0] == '+')
		return Calc_res(a->left) + Calc_res(a->right);
	if (a->data[0] == '-')
		return Calc_res(a->left) - Calc_res(a->right);
	if (a->data[0] == '*')
		return Calc_res(a->left) * Calc_res(a->right);
	if (a->data[0] == '/')
		return Calc_res(a->left) / Calc_res(a->right);
	if (a->data[0] == '^')
		return pow(Calc_res(a->left) , Calc_res(a->right));
	if (Is_digit(a->data, a->data_size))
	{
		
		for (int i = a->data_size - 1; i >= 0; i--)
		{
			int wer = (int)a->data[i] - 48;
			number += wer * pow(10, a->data_size - i - 1);
		}
		return number;
	}
	for (int i = 0; i < a->data_size; i++)
		cout << a->data[i];
	cout << " = ";
	cin >> number;
	return number;

}



void Set_Tree()
{
	char expression[64];
	cout << "Enter your expression" << endl;
	cin.getline(expression, 64);
	if (!expression[0])
		cin.getline(expression, 64);
	char* expression2;
	int size;
	for (int i = 0; i < 64; i++)
		if (expression[i] == '\0')
		{
			size = i;

		}
	expression2 = new char[size];
	for (int j = 0; j < size; j++)
		expression2[j] = expression[j];
	tree = get_tree(expression2, size);

}


void Calculate()
{
	Node* temp = tree;
	int result = Calc_res(temp);
	cout << "The result is " << result << endl;
	system("pause");
}


void Display_Tree()
{
	if (!tree)
	{
		system("cls");
		cout << "Set the tree at first" << endl;
		system("pause");
		return;

	}
	Node* temp = tree;
	int ch;
	do {

		Node_Display(temp);
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