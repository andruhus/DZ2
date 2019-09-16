// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fily.h"
using namespace std;

void menu()
{
	int a;
	cout << "Enter your task ";
	cin >> a;
	switch (a) {
	case 1: task1(); cout << "If you want exit press 0." << endl; menu(); break;
	case 2: task2(); cout << "If you want exit press 0." << endl; menu(); break;
	case 3: task3(); cout << "If you want exit press 0." << endl; menu(); break;
	case 4: task4(); cout << "If you want exit press 0." << endl; menu(); break;
	case 5: task5(); cout << "If you want exit press 0." << endl; menu(); break;
	case 6: task6(); cout << "If you want exit press 0." << endl; menu(); break;
	case 7: task7(); cout << "If you want exit press 0." << endl; menu(); break;
	default: break;
	}
}

int main()
{
	cout << "Hello! You are in my homework." << endl;
	menu();
	cout << "Goodbye";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
