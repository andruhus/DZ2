#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void getline(istream &a,char* t,int &i)
{
	char d;
	a >> d;
	while (d != '\n')
	{
		t[i] = d;
		a >> d;
		i++;
	}
}

static char* enterchar(char* a, int& n, char t)
{
	n++;
	char* b = new char[n];
	for (int i = 0; i < n - 1; i++)
	{
		b[i] = a[i];
	}
	b[n - 1] = t;
	delete[] a;
	return b;
}

void dz10()
{
	ofstream r;
	r.open("lastclasswork.dat" , ios::binary);
	r <<  "Equality is about equal rights for all citizens before the law. The principle of equality between women and men underpins all European policies and is the basis for European integration. It applies in all areas. The principle of equal pay for equal work became part of the Treaty of Rome in 1957. Although inequalities still exist, the EU has made significant progress.";
	r.close();
	ifstream f;
	f.open("lastclasswork.dat", ios::binary);

	string k = "";
	while (!f.eof())
	{
		string s = "";
		getline(f, s);
		k += s;
		cout << s;
	}
	f.close();
	///////////////////////////////////////////
	cout << endl;
	char y;
	cin >> y;
	system("cls");

	int n = 0;
	for (char t : k)
	{
		if (t != ' ')
		{
			cout << t;
		}
		else
		{
			cout << endl;
			char y;
			cin >> y;
			system("cls");
			n++;
		}
	}
	/////////////////////////////////////////

	cout << endl;
	cin >> y;
	system("cls");

	cout << n + 1;
}