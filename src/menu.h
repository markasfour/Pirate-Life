#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class menu
{
	private:
	public:
		menu() {}; //default constructor
		~menu() {}; //destructor
		
		void land();
		void sea();
		void prebattle();
		void battle();
};

//main menu
void menu::land()
{
	cout << "                      MENU                " << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Navigate the Seas          |" << endl;
	cout << "    |   2.    Build a Crew               |" << endl;
	cout << "    |   3.    Find a Ship                |" << endl;
	cout << "    |   4.    Try Yer Luck               |" << endl;
	cout << "    |   5.    Check Yer Satus            |" << endl;
	cout << "    |   6.    Save                       |" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |         Q to quit the game         |" << endl;
	cout << "    --------------------------------------" << endl;

}

//sea menu
void menu::sea()
{
	cout << "                    Navigate" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Continue Sailing           |" << endl;
	cout << "    |   2.    Check Status               |" << endl;
	cout << "    |   3.    Return to Land             |" << endl;
	cout << "    --------------------------------------" << endl;
}

//prebattle menu
void menu::prebattle()
{
	cout << "                    Action" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    View Enemy Stats           |" << endl;
	cout << "    |   2.    Check Yer Status           |" << endl;
	cout << "    |   3.    Attack                     |" << endl;
	cout << "    |   4.    Flee                       |" << endl;
	cout << "    --------------------------------------" << endl;
}

//battle menu
void menu::battle()
{
	cout << "                    Battle" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Fire the Cannons           |" << endl;
	cout << "    |   2.    Board Their Ship           |" << endl;
	cout << "    |   3.    View Enemy Stats           |" << endl;
	cout << "    |   4.    Check Yer Status           |" << endl;
	cout << "    |   5.    Flee                       |" << endl;
	cout << "    --------------------------------------" << endl;
}

#endif
