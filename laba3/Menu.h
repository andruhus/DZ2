#pragma once

class Menu
{
private:
	char name_of_file[64] = "MenuOption.bin";
	
	
	public:
	int opt_num = 0;
	struct Func {
		
		void (*f)() = nullptr;
	};
	Func* Functional = nullptr;
	//void (*Functional[])();
	
public:
	void Func_Def();
	Menu() {
		SetOptions();
		Func_Def();
	}
	
	void SetOptions();
	int Display();
	void Start();
};

