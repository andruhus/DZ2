#pragma once
#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;
inline void Menu::SetOptions()
{
	bool Answer;
	cout << "Do you want to change the menu?" << endl;
	cout << "Your answer: ";
	cin >> Answer;
	if (Answer)
	{
		ofstream file;
		file.open(name_of_file, ios_base::binary);
		char temp_option[64];


		cout << "How many options do you have: ";
		cin >> opt_num;

		file.write((char*)& opt_num, sizeof(int));

		for (int i = opt_num; i > 0; i--)
		{
			cout << opt_num - i + 1 << " Option:" << endl;
			if(i == opt_num)
				cin.ignore();
			cin.getline(temp_option, 64);
			file.write(temp_option, 64);
		}

		


		file.close();
	}
	else
	{
		ifstream file;
		file.open(name_of_file, ios_base::binary);
		file.read((char*)& opt_num, sizeof(int));
	}
	Functional = new Func[opt_num];
}

inline int Menu::Display()
{

	int key = 0;
	int code;
	
	char temp_option[64];
	do {
		ifstream file;
		file.open(name_of_file, ios_base::binary);
		file.read((char*)& opt_num, sizeof(int));
		system("cls");
		key = (key + opt_num + 1) % (opt_num + 1);
		for (int i = 0; i < opt_num; i++)
		{
			file.read(temp_option, 64);

			if (key == i) cout << "-> " << temp_option << endl;
			else  cout << "   " << temp_option << endl;
		}
		if (key == opt_num) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;
		file.close();

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	
	return key;
}

inline void Menu::Start()
{

	int key = Display();
	bool NonExit = true;
	for (int i = 0; i < opt_num; i++)
	{
		if (key == i)
			Functional[i].f();
	}
	if (key == opt_num)
		NonExit = false;
	if (NonExit)
		Start();
	
}