#include "fily.h"
#include <iostream>
using namespace std;

/*���� ����� ������������� ����� A, B, C. �� �������������� ���-
���� A ? B ��������� ����������� ��������� ���������� ��������� ��
�������� C (��� ���������). ����� ���������� ���������, �����������
�� ��������������, � ����� ������� ��������� ����� ��������������.*/

void task2()
{
	cout << "Positive integers A, B, C are given. measure A ? B placed the maximum possible number of squares with side C(no overlays).Find the number of squares placed on the rectangle, as well as the area of ??the unoccupied part of the rectangle" << endl;
	cout << "Enter three positive integers ";
	int a, b, c;
	cin >> a >> b >> c;
	int n = a / c;
	int m = b / c;
	cout << n * m << " " << a * b - n * m * c * c << endl;
}

	
