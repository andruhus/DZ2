#include "fily.h"

#include <iostream>
using namespace std;

/*���� ����� x, y. ��������� ���������� ������������: ������ � ��-
���������� (x, y) ����� �� ������ ������������ ��������.*/

void task5()
{
	cout << "The numbers x, y are given.Check the truth of the statement : �The point with the ordinates(x, y) lie in the second coordinate quarter.�" << endl;
	cout << "Enter two cordinates ";
	int a, b;
	cin >> a >> b;
	cout << (a <= 0 & b <= 0) << endl;
	
}