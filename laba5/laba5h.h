#pragma once
#include "Menu.h"
#include "Menus.cpp"
#include <vector>

void Add_New_Word();
void Search_A_Word();
void Look_Through();
void Error_Track();

struct Data
{
	char english[64];
	char ukrainian[64];
	int counter;
};

struct Node
{
	Data data;
	int data_size;

	Node* left = nullptr;
	Node* right = nullptr;
	Node* root = nullptr;

} ;
void storeBSTNodes(Node* root, vector<Node*>& nodes);
Node* buildTreeUtil(vector<Node*>& nodes, int start, int end);
Node* buildTree(Node* root);
Node* newNode(Data data);

inline void Menu::Func_Def()
{
	Functional[0].f = Add_New_Word;
	Functional[1].f = Search_A_Word;
	Functional[2].f = Look_Through;
	Functional[3].f = Error_Track;
}
