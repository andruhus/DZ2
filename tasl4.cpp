#include "fily.h"
#include <iostream>
using namespace std;

/*Даны три целых числа: A, B, C. Проверить истинность высказыва-
ния: «Хотя бы одно из чисел A, B, C положительное».*/

void task4()
{
	cout << "Three integers are given: A, B, C. Verify the truth of statement: “At least one of the numbers A, B, C is positive.”" << endl;
	cout << "Enter three integers ";
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a > 0) || (b > 0) || (c > 0)) << endl;
	
}