#include "fily.h"

#include <iostream>
using namespace std;

/*Даны числа x, y. Проверить истинность высказывания: «Точка с ко-
ординатами (x, y) лежит во второй координатной четверти».*/

void task5()
{
	cout << "The numbers x, y are given.Check the truth of the statement : “The point with the ordinates(x, y) lie in the second coordinate quarter.”" << endl;
	cout << "Enter two cordinates ";
	int a, b;
	cin >> a >> b;
	cout << (a <= 0 & b <= 0) << endl;
	
}