#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;



class Scaner
{
private:
	char name[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
public:
	void input()
	{
		cout << "Enter name: ";
		for (int i = 0; i < 25; i++)
			cin >> name[i];
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter the size: ";
		cin >> x_size;
		cin >> y_size;
		cout << "Enter optr: ";
		cin >> optr;
		cout << "Enter how grey it is: ";
		cin >> grey;
		system("cls");
	}

	void writing(ofstream &a)
	{
		a.write(name, 25);
		a << " ";
		a << price;
		a << " ";
		a << x_size;
		a << " ";
		a << y_size;
		a << " ";
		a << optr;
		a << " ";
		a << grey;
		a << "\n";

	}
};

void dz9()
{
	short int n;
	cin >> n;

	ofstream qa;
	qa.open("C:\\Users\\aaade\\Desktop\\Files for labs\\dz9.txt", ios::binary);

	qa << n;

	for (int i = 0; i < n; i++)
	{
		Scaner r;
		r.input();
		r.writing(qa);
	}

	qa.close();

	
}



