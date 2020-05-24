#include "Module.h"
#include <iostream>

using namespace std;

// Example tree


bool Is_bool(char* a, int size)
{
	
		if (a[0] == '0' || a[0] == '1')
			return true;
	
	return false;
}




void Switch(Node* tree)
{
	if (!tree)
		return;
	Node* temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;
	if (tree->left)
		Switch(tree->left);
	if (tree->right)
		Switch(tree->right);

}

const int num_of_oper = 3;
char al_operators[num_of_oper] = {  '&','|','-' };

void Get_Data_Array(Node* a,Data* b, int& ind)
{
	
	for (int i = 0; i < 3; i++)
		if (a->data.data[0] == al_operators[i])
		{
			if (a->left)
				Get_Data_Array(a->left, b, ind);
			if (a->right)
				Get_Data_Array(a->right, b, ind);
			return;
		}
	if (Is_bool(a->data.data, a->data.data_size))
	{
		if (a->left)
			Get_Data_Array(a->left, b, ind);
		if (a->right)
			Get_Data_Array(a->right, b, ind);
		return;
	}
	for (int i = 0; i < ind; i++)
		if (b[i] == a->data)

		{
			if (a->left)
				Get_Data_Array(a->left, b, ind);
			if (a->right)
				Get_Data_Array(a->right, b, ind);
			return;
		}
	b[ind] = a->data;
	ind++;
	if (a->left)
		Get_Data_Array(a->left, b, ind);
	if (a->right)
		Get_Data_Array(a->right, b, ind);
}

bool Calc_res(Node* a, int& k)
{
	bool number;
	if (a->data.data[0] == '&')
		return Calc_res(a->left,k) && Calc_res(a->right,k);
	if (a->data.data[0] == '-')
		return 1 - Calc_res(a->right,k);
	if (a->data.data[0] == '|')
		return Calc_res(a->left,k) || Calc_res(a->right,k);
	
	if (Is_bool(a->data.data, a->data.data_size))
	{

			number = (int)a->data.data[0] - 48;
			
		
		return number;
	}
	number = k % 2;
	k = k / 2;
	return number;
}

Node* get_tree(char* str, int size, Node* root = nullptr)
{
	// declareation
	Node* novel_root = new Node;
	char* left_str;
	char* right_str;
	char* sub_str;

	// str analysis
	if (size == 0)
		return nullptr;

	if (str[0] == '(')
	{
		bool Has_Bracket = true;
		for (int i = 0; i < size - 1 ; i++)
		{
			if (str[i] == ')' && str[i+1] >0)
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

				novel_root->data.data_size = 1;
				novel_root->data.data = new char[1];
				novel_root->data.data[0] = al_operators[i];

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

	novel_root->data.data_size = size;
	novel_root->data.data = str;


	novel_root->left = nullptr;
	novel_root->right = nullptr;
	novel_root->root = root;

	return novel_root;
}


void getHeight(Node* root, int& h) {
	if (!root)
		return;
	h++;
	int leftH = h;
	int rightH = h;
	if (root->right != nullptr) {
		getHeight(root->right, rightH);
	}
	if (root->left != nullptr) {
		getHeight(root->left, leftH);
	}

	if (leftH > rightH) {
		h = leftH;
	}
	else {
		h = rightH;
	}
}

Node** getNodesOnThisLevel(Node** nodes, int& nodesSize, Node* iterationNode, int& iterationLevel, int level) {
	
	if (iterationLevel < level && iterationNode->left)
	{
		iterationLevel++;
		nodes = getNodesOnThisLevel(nodes, nodesSize, iterationNode->left, iterationLevel, level);
	}
	if(iterationLevel == level)
	{
		
		Node** nodes2 = new Node * [nodesSize + 1];
		for (int i = 0; i < nodesSize + 1; i++)
			nodes2[i] = new Node;
		for (int i = 0; i < nodesSize; i++) {
			nodes2[i] = nodes[i];
		}
		nodes2[nodesSize] = iterationNode;
		nodes = nodes2;
		nodesSize++;
		
		iterationLevel--;
		return nodes;
	}
	if (iterationLevel < level && iterationNode->right)
	{
		iterationLevel++;
		nodes = getNodesOnThisLevel(nodes, nodesSize, iterationNode->right, iterationLevel, level);
	}
} 

void Main_for_2(Node* root) {
	int h = 0;
	getHeight(root, h);
	cout << "The height is: " << h << endl;
	int numberOfHDiv2 = 0;
	Node** H_div_2_nodes = new Node * [numberOfHDiv2];
	
	int iterationLevel = 1;
	H_div_2_nodes = getNodesOnThisLevel(H_div_2_nodes, numberOfHDiv2, root, iterationLevel, h / 2);
	for (int i = 0; i < numberOfHDiv2; i++) {
		if (H_div_2_nodes[i]->left != nullptr && H_div_2_nodes[i]->right != nullptr) {
			int leftH = 0;
			int rightH = 0;
			getHeight(H_div_2_nodes[i]->left, leftH);
			getHeight(H_div_2_nodes[i]->right, rightH);
			if (leftH == rightH) {
				if (H_div_2_nodes[i] == H_div_2_nodes[i]->root->right) {
					H_div_2_nodes[i]->root->right = nullptr;
				}
				if (H_div_2_nodes[i] == H_div_2_nodes[i]->root->left) {
					H_div_2_nodes[i]->root->left = nullptr;
				}
			}
		}
	}
	int k = 0;
	getHeight(root, k);
	cout << "The height is: " << k << endl;
}

bool dfs(int key, int* was, Graph ab) {
	int n = ab.vert_num;
	int** a = ab.matrix;

	was[key] = 1;

	for (int i = 0; i < n; i++) {

		if (a[key][i]) {

			if (was[i] == 0) { if (dfs(i, was, ab)) return true; }

			else if (was[i] == 1) { return true; }
		}
	}

	was[key] = 2;

	return false;
}


void task1()
{
	Node* extree = nullptr;
	extree = Set_Tree(extree);
	Switch(extree);
	extree->Display();
}
void task2()
{
	Node* extree = nullptr;
	extree = Set_Tree(extree);
	
	Main_for_2(extree);
	extree->Display();
}
void task3()
{
	Node* extree = nullptr;
	char input[64];
	cout << "Enter your expression: ";
	cin.getline(input, 64);
	int y = 0;
	for (int i = 0; i < 64; i++)
	{
		if (input[i] < 0)
		{
			y = i;
			break;
		}
	}
	char* a = new char[y];
	for (int i = 0; i < y; i++)
	{
		a[i] = input[i];
	}
	extree = get_tree(a, y);
	extree->Display();

	Data* variable_array = new Data[64];
	int number_of_var = 0;
	Get_Data_Array(extree, variable_array, number_of_var);
	bool* res_array = new bool[(int)pow(2,number_of_var)];
	
	cout << endl;
	for (int i = 0; i < pow(2, number_of_var); i++)
	{
		cout << "(";
		int temp = i;
		int k = i;
		for (int j = 0; j < number_of_var; j++)
		{
			cout << temp % 2;
			temp = temp / 2;
			cout << ",";
		}
		cout << ")  -> ";
		bool res = Calc_res(extree, k);
		cout << res;
		
		res_array[i] = res;
		cout << endl;

	}

	cout << "Shortened expression: ";
	if (number_of_var == 0)
	{
		int y = 0;
		cout << Calc_res(extree, y);
	}
	for (int i = 0; i < pow(2, number_of_var); i++)
	{
		if (res_array[i])
		{
			int temp = i;
			for (int j = 0; j < number_of_var; j++)
			{
				if (temp % 2 == 0)
				{
					cout << "-";
					for (int m = 0; m < variable_array[j].data_size && variable_array[j].data[m] > 0; m++)
					{
						cout << variable_array[j].data[m];
					}
				}
				if (temp % 2 == 1)
				{
					for (int m = 0; m < variable_array[j].data_size && variable_array[j].data[m] > 0; m++)
					{
						cout << variable_array[j].data[m];
					}
				}
				temp = temp / 2;
				if (j < number_of_var - 1)
					cout << "&";
			}
			cout << "|";
		}
	}


}
void task4()
{
	Graph a;
	a.Set_Graph();


	int* was = new int[a.vert_num];
	for (int i = 0; i < a.vert_num; i++) {

		was[i] = 0;

	}
	for (int i = 0; i < a.vert_num; i++) {

		if (!was[i] && dfs(i, was, a)) { cout << "It is acyclic\n"; return; }
	}

	cout << "It isnt acyclic\n";
	return;
}
