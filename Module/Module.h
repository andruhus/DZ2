#pragma once





// Module tasks
void task1();
void task2();
void task3();
void task4();
void task5();


// My home preparation
//	Structs
struct Data
{
	char* data;
	int data_size;
};

struct Node
{
	Data data;
	

	Node* left = nullptr;
	Node* right = nullptr;
	Node* root = nullptr;

};

class Graph
{
public:
	int vert_num;
	int** matrix;
	void Set_Graph();
	void Print_Graph();

};




