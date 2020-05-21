#include "Module.h"
#include <iostream>
using namespace std;

// Example tree
Node* extree;
void Get_Example(Node* extree)
{
	extree = new Node;
	extree->data.data = new char[2];
	extree->data.data_size = 2;

	extree->left = new Node;
	extree->left->data.data = new char[2];
	extree->left->data.data_size = 2;

	extree->right = new Node;
	extree->right->data.data = new char[2];
	extree->right->data.data_size = 2;

	extree->left->left = new Node;
	extree->right->right = new Node;


}





void Switch(Node* tree)
{
	Node* temp = tree->left;
	tree->left = tree->right;
	tree->right = temp;
	if(tree->left)
	Switch(tree->left);
	if(tree->right)
	Switch(tree->right);

}

const int num_of_oper = 3;
char al_operators[num_of_oper] = { '-', '&','|' };

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

void getNodesOnThisLevel(Node** nodes, int& nodesSize, Node* iterationNode, int& iterationLevel, int level) {
	iterationLevel++;
	if (iterationLevel < level) {
		if (iterationNode->right != nullptr) {
			getNodesOnThisLevel(nodes, nodesSize, iterationNode->right, iterationLevel, level);
		}
		if (iterationNode->left != nullptr) {
			getNodesOnThisLevel(nodes, nodesSize, iterationNode->left, iterationLevel, level);
		}
	}
	else {
		Node** nodes2 = new Node * [nodesSize + 1];
		for (int i = 0; i < nodesSize; ++i) {
			nodes2[i] = nodes[i];
		}
		nodes2[nodesSize + 1] = iterationNode;
		**nodes = **nodes2;
		nodesSize++;
	}
}

void Main_for_2(Node* root) {
	int h = 0;
	getHeight(root, h);
	
	int numberOfHDiv2 = 0;
	Node** H_div_2_nodes = new Node*[numberOfHDiv2];
	int iterationLevel;
	getNodesOnThisLevel(H_div_2_nodes, numberOfHDiv2, root, iterationLevel, h / 2);
	for (int i = 0; i < numberOfHDiv2; ++i) {
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
}

bool dfs(int key, int* was, Graph ab) {
	int n = ab.vert_num;
	 int** a = ab.matrix;
	
	was[key] = 1;
	
	for (int i = 0; i < n; i++) {
		
		if (a[key][i]) {
			
			if (was[i] == 0) { if (dfs(i,was,ab)) return true; }
			
			else if (was[i] == 1) { return true; }
		}
	}
	
	was[key] = 2;
	
	return false;
}


void task1()
{
	Get_Example(extree);
	Switch(extree);
}
void task2()
{
	Get_Example(extree);
	Main_for_2(extree);
}
void task3()
{
	Node* tree = nullptr;
	char* a = new char[64];
	a[0] = 'a';
	a[1] = '&';
	a[2] = 'b';
	tree = get_tree(a, 64);
}
void task4()
{
	Graph a;
	a.Set_Graph();
	
	
	int *was = new int[a.vert_num];
	for (int i = 0; i < a.vert_num; i++) {
		
		was[i] = 0;
		
	}
	for (int i = 0; i < a.vert_num; i++) {
		
		if (!was[i] && dfs(i,was,a)) { cout << "It is acyclic\n"; return ; }
	}
	
	cout << "It isnt acyclic\n";
	return ;
}
void task5()
{

}