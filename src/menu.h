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
		void dock();
		void interact();
		void edit_crew();
		void ship_yard();
		int repair(int y, int y2, int y3);
};

//main menu
void menu::land()
{
	cout << "                      MENU                " << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Navigate the Seas          |" << endl;
	cout << "    |   2.    Build a Crew               |" << endl;
	cout << "    |   3.    Ship Yard                  |" << endl;
	cout << "    |   4.    Local Tavern               |" << endl;
	cout << "    |   5.    Check Yer Status           |" << endl;
	cout << "    |   6.    Save                       |" << endl;
	cout << "    |   7.    Load                       |" << endl;
	cout << "    |   8.    Settings                   |" << endl;
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
	cout << "    |   2.    Board Enemy Ship           |" << endl;
	cout << "    |   3.    View Enemy Stats           |" << endl;
	cout << "    |   4.    Check Yer Status           |" << endl;
	cout << "    |   5.    Flee                       |" << endl;
	cout << "    --------------------------------------" << endl;
}

//dock menu
void menu::dock()
{
	cout << "                     Dock" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Interact with Individuals  |" << endl;
	cout << "    |   2.    Threaten the Crowd         |" << endl;
	cout << "    |   3.    Edit Crew                  |" << endl;
	cout << "    |   4.    Return                     |" << endl;
	cout << "    --------------------------------------" << endl;
}

//interact menu
void menu::interact()
{
	cout << "                   Interact" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Ask to Join Yer Crew       |" << endl;
	cout << "    |   2.    Insult                     |" << endl;
	cout << "    |   3.    Bribe                      |" << endl;
	cout << "    |   4.    Return                     |" << endl;
	cout << "    --------------------------------------" << endl;

}

//edit crew menu
void menu::edit_crew()
{
	cout << "                   Edit Crew" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    List Crew                  |" << endl;
	cout << "    |   2.    Get Stats                  |" << endl;
	cout << "    |   3.    Remove                     |" << endl;
	cout << "    |   4.    Return                     |" << endl;
	cout << "    --------------------------------------" << endl;
}

//ship yard main menu
void menu::ship_yard()
{
	cout << "                   Ship Yard" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    View Ships Available       |" << endl;
	cout << "    |   2.    Repair Ship                |" << endl;
	cout << "    |   3.    Sell Ship                  |" << endl;
	cout << "    |   4.    Return                     |" << endl;
	cout << "    --------------------------------------" << endl;
}

//repair ship menu
int menu::repair(int y, int y2, int y3)
{
	//conditional statements intentionally not tabbed 
	int i = 2;
	cout << "                 Ship Repair" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "        1.    +1  health: $" << y << endl;
	if (y2 != 0)
	{
	cout << "        2.    +10 health: $" << y2 << endl;
	cout << "        3.    full health: $" <<  y3 << endl;
	i+=2;
	}
	else if (y2 == 0 && y3 != 0)
	{
	cout << "        2.    full health: $" << y3 << endl;
	i++;
	}
	cout << "        " << i << ".    Return" << endl;
	cout << "    --------------------------------------" << endl;
	return i;
}
#endif
