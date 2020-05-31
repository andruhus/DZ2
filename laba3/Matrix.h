#pragma once
#include "Menu.h"
#include "Menus.cpp"

void One_Matrix();
void Add_2_Matrixes();
void Multiply_2_Matrixes();


template <typename T>
struct Node
{
	T data;
	Node<T>* previous = nullptr;
	Node<T>* following = nullptr;
};

class Larger_List
{
public:
	Node<int>* head = nullptr;
	Node<int>* tail = nullptr;
	
	void push_back(int f);
	Larger_List() {

		for (int i = 0; i < 100; i++)
		{
			this->push_back(0);
		}
	}
	void push_front(int f);
	void remove(int f);
};

class Matrix
{
public:
	Node<Larger_List>* head = nullptr;
	Node<Larger_List>* tail = nullptr;
	void push_back(Larger_List f);
	Matrix() {
		for (int i = 0; i < 100; i++)
		{
			Larger_List s;
			this->push_back(s);
		}
		
	}
	void Set_Matrix();
	void Write_2_types_in_file();
};



inline void Menu::Func_Def()
{
	Functional[0].f = One_Matrix;
	Functional[1].f = Add_2_Matrixes;
	Functional[2].f = Multiply_2_Matrixes;
}

