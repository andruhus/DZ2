#pragma once
#include "Menu.h"
#include "Menus.cpp"

void Set_Graph();
void Get_Polynom();
void Sort();
class Pol
{
public:
	int* arr = new int[64];
	int max_deg = 0;
	Pol()
	{
		for (int i = 0; i < 64; i++)
			arr[i] = 0;
	}
	void Print();
	int Substitution(int x);
};
class Graph
{
private:
	void Write();
public:
	int number_of_vertix;
	Graph();
	bool** matrix;
	bool Is_Empty();
	Graph Extract_Edge(int i,int j);
	Graph Edge_Contraction(int i,int j);
	void Set_Graph();
	void Get_File();
	int* degr_val = new int[number_of_vertix];
	void Set_Degree();


};

inline void Menu::Func_Def()
{
	Functional[0].f = Set_Graph;
	Functional[1].f = Get_Polynom;
	Functional[2].f = Sort;
}

Pol Answ_Get(Graph a);
Pol operator -(Pol a1, Pol a2);