#include "fily.h"
#include <iostream>
using namespace std;

/*���� ����� ����� a, b, c. ��������� ���������� ������������:
����������� ����������� �� ��������� a, b, c�.*/

void task6()
{
	cout << "The integers a, b, c are given. Check the truth of the statement: �There is a triangle with sides a, b, c�" << endl;
	cout << "Enter three integers ";
	int a, b, c;
	cin >> a >> b >> c;
	cout << ((a + b > c) & (b + c > a) & (a + c > b)) << endl;
}