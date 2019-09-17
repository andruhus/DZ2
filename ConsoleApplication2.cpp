

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
	case 8: task8(); cout << "If you want exit press 0." << endl; menu(); break;
	case 9: task9(); cout << "If you want exit press 0." << endl; menu(); break;
	case 10: task10(); cout << "If you want exit press 0." << endl; menu(); break;
	case 11: task11(); cout << "If you want exit press 0." << endl; menu(); break;
	default: break;
	}
}

int main()
{
	cout << "Hello! You are in my homework." << endl;
	menu();
	cout << "Goodbye";
}


