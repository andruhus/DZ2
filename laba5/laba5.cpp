#pragma once
#pragma warning (disable : 4996)
#include "laba5h.h"
#include "windows.h"
#include <fstream>
#include <ctime>
#include <chrono>

// Constants
bool Console_Problem_Avoider = true;
char errorfile[64] = "Error.bin";
char Errors[3][64] = { "Invalid english word","Invalid ukrainian word","Non-a-number has been entered" };
int Ukr_Char_Codes[33] = { -32, -31, -30, -29, -76, -28, -27, -70, -26, -25, -24, -77, -65, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -4, -2, -1, };
/* It prints the time


auto err = chrono::system_clock::now();
time_t er = chrono::system_clock::to_time_t(err);
cout << ctime(&er);
cout << endl << sizeof(err) << endl << sizeof(er);


*/

bool operator > (Data d1, Data d2)
{
	return d1.counter > d2.counter;
}
bool operator < (Data d1, Data d2)
{
	return d1.counter < d2.counter;
}
bool operator ==  (Data d1, Data d2)
{
	bool ukr = true;
	bool eng = true;
	for (int i = 0; i < 64; i++)
	{
		if (d1.ukrainian[i] != d2.ukrainian[i])
			ukr = false;
		if (d1.english[i] != d2.english[i])
			eng = false;
	}
	return ukr || eng;
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




Node* tree = nullptr;


void Record_Error(int errornum)
{
	ofstream file;
	file.open(errorfile, ios::binary | ios::app);
	file.write(Errors[errornum], 64);
	auto err_time = chrono::system_clock::now();
	time_t er = chrono::system_clock::to_time_t(err_time);
	file.write((char*)&er, sizeof(time_t));
	file.close();
}

// Set of checking functions
bool Is_Eng_Char(char c)
{
	return (int)c >= 97 && (int)c <= 122;
}

bool Is_Valid_Eng(char word[64])
{
	for (int ind = 0; word[ind] != 0; ind++)
	{
		if (!Is_Eng_Char(word[ind]))
		{
			Record_Error(0);
			cout << "Not an English word" << endl;
			return false;
		}
	}
	return true;
}

bool Is_Ukr_Char(char c)
{
	int code = (int)c;
	for (int i = 0; i < 33; i++)
		if (code == Ukr_Char_Codes[i])
			return true;
	return false;
}

bool Is_Valid_Ukr(char word[64])
{
	for (int ind = 0; word[ind] != 0; ind++)
	{
		if (!Is_Ukr_Char(word[ind]))
		{
			Record_Error(1);
			cout << "Not an Ukrainian word" << endl;
			return false;
		}
	}
	return true;
}

bool Is_Number(char der[64], int& num)
{
	for (int i = 0; der[i] > 0; i++)
	{
		if (der[i] <= 47 || der[i] >= 58)
		{
			cout << "Please enter a number";
			Record_Error(2);
			return false;
		}
		else
		{
			num *= 10;
			num += der[i] - 48;

		}
	}
	return true;
}


// Executing functions
void Data_Display(Data a)
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "English: ";
	for (int i = 0; a.english[i] > 0; i++)
	{
		cout << a.english[i];
	}
	cout << endl;
	cout << "Українська: ";
	for (int i = 0; a.ukrainian[i] < 0; i++)
	{
		cout << a.ukrainian[i];
	}
	cout << endl;
	cout << "Popularity: " << a.counter << endl;
}

void Search_In_Tree(Node* tree, Data* result)
{
	if (*result == tree->data)
	{
		Data_Display(tree->data);
		tree->data.counter++;
		system("pause");
		return;
	}
	else
	{
		if (tree->left)
		{
			Search_In_Tree(tree->left,result);
		}
		if (tree->right)
		{
			Search_In_Tree(tree->right,result);
		}
	}

}

void Set_Word(Data& a)
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	cout << "Enter the English word: ";
	if (Console_Problem_Avoider)
	{
		cin.ignore(1, '\n');
		Console_Problem_Avoider = false;
	}
	do {

		cin.getline(a.english, 64);
	} while (!Is_Valid_Eng(a.english));


	cout << "Enter the Ukrainian word: ";
	do {
		cin.getline(a.ukrainian, 64);
	} while (!Is_Valid_Ukr(a.ukrainian));



	cout << "How much times has the word been turned to: ";
	char fer[64];
	int num = 0;
	do
	{
		cin.getline(fer, 64);

	} while (!Is_Number(fer,num));
	a.counter = num;

}

void Enter_Searching_Word(Data& a)
{
	system("cls");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char search[64];
	if (Console_Problem_Avoider)
	{
		cin.ignore(1, '\n');
		Console_Problem_Avoider = false;
	}
	bool valid = false;
	do
	{
		cout << "Enter your word: ";
		cin.getline(search, 64);
		if (Is_Ukr_Char(search[0]))
		{
			valid = Is_Valid_Ukr(search);
			if (valid)
				for (int i = 0; i < 64; i++)
					a.ukrainian[i] = search[i];
		}
		else if (Is_Eng_Char(search[0]))
		{
			valid = Is_Valid_Eng(search);
			if (valid)
				for (int i = 0; i < 64; i++)
					a.english[i] = search[i];
		}
		else
		{
			valid = false;
			cout << "It is not a word" << endl;
		}
	} while (!valid);

}




// main functions
void Add_New_Word()
{
	Data value;
	Set_Word(value);
	tree = insert(tree, value, NULL);
	tree = buildTree(tree);
	cout << "The word has been successfully added" << endl;
}
void Search_A_Word()
{
	if (!tree)
	{
		system("cls");
		cout << "Set the tree at first" << endl;
		system("pause");
		return;
	}
	Data a;
	Enter_Searching_Word(a);
	Search_In_Tree(tree, &a);
}
void Look_Through()
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

		Data_Display(temp->data);
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
void Error_Track()
{
	ifstream file;
	file.open(errorfile, ios::binary);
	char temp[64];
	time_t tempo;

	while (!file.eof())
	{
		file.read(temp, 64);
		file.read((char*)&tempo, sizeof(time_t));
		cout << "The error is ";
		for (int i = 0; temp[i] > 0; i++)
			cout << temp[i];
		cout << "." << endl;
		cout << "It was made on ";
		cout << ctime(&tempo) << endl << endl;
	}
	system("pause");
	file.close();
}