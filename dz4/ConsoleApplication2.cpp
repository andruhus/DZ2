

#include <iostream>
#include "fily.h"
using namespace std;

void menu()
{
	char a;
	int b;
	cout << "Enter your block of tasks ";
	cin >> a;
	switch (a) {
	case 'n':  cout << "Enter your task ";
				cin >> b;
				switch (b) {
				case 1: task1(); menu(); break;
				case 2: task2(); menu(); break;
				case 3: task3(); menu(); break;
				default: break;
				} break;
	case 'b':  cout << "Enter your task ";
				cin >> b;
				switch (b) {
				case 1: task4(); menu(); break;
				case 2: task5(); menu(); break;
				case 3: task6(); menu(); break;
				case 4: task7(); menu(); break;
				default: break;
				} break;
	case 'i':  cout << "Enter your task ";
				cin >> b;
				switch (b) {
				case 1: task8(); menu(); break;
				case 2: task9(); menu(); break;
				case 3: task10(); menu(); break;
				case 4: task11(); menu(); break;
				default: break;
				}break;
	default: break;
	}
}

int main()
{
	cout << "Hello! You are in my homework." << endl;
	menu();
	cout << "Goodbye";
}


