#pragma once





// Module tasks
void task1();
void task2();
void task3();
void task4();



// My home preparation
//	Structs
struct Data
{
	
	int data_size =64;
	char* data = new char[data_size];
};

class Node
{
public:
	Data data;
	

	Node* left = nullptr;
	Node* right = nullptr;
	Node* root = nullptr;

	void Print_Data();
	void Display();
	
};

Node* Set_Tree(Node* tree);

class Graph
{
public:
	int vert_num;
	int** matrix;
	void Set_Graph();
	void Print_Graph();

};
bool operator == (Data v1, Data v2);




