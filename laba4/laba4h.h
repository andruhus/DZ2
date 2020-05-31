#pragma once
#include "Menu.h"
#include "Menus.cpp"

void Set_Tree();
void Calculate();
void Display_Tree();



struct Node
{
	char* data;
	int data_size;

	Node* left = nullptr;
	Node* right = nullptr;
	Node* root = nullptr;

};

class Bntr_Tr
{
public:
	Node* root = nullptr;
	char** variables;
	

};



inline void Menu::Func_Def()
{
	Functional[0].f = Set_Tree;
	Functional[1].f = Calculate;
	Functional[2].f = Display_Tree;
}
