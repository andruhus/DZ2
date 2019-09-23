#include <iostream>
#include "fily.h"
using namespace std;

void task8()
{
	cout << "Three numbers are given. Find the smallest of them." << endl;
	cout << "Enter three integers";
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) a = b;
	if (a > c) a = c;
	cout << a << endl;

}