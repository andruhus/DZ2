#include "fily.h"
#include <iostream>
#include <math.h>
using namespace std;

/*���� ���������� ���� ��������� ����� ��������� ����� x1, y1,
x2, y2 (����� �����, ������� � ��������� 1�8). ��������� ���������� ��-
����������: ����� �� ���� ��� ����� ������� � ������ ���� �� ������.*/

void task7()
{
	cout << "The coordinates of two different checkerboard fields x1, y1,x2, y2(integers in the range 1�8).Check the truth you tales : �A horse can move from one field to another in one move�" << endl;
	cout << "Enter two chess positions ";
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	bool q = ((abs(x2 - x1) == 1 & abs(y2 - y1) == 2) || (abs(x2 - x1) == 2 & abs(y2 - y1) == 1));
	cout << q << endl;
}