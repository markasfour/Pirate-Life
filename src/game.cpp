#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int HEALTH = 100;
int WEALTH = 0;
string SHIP = "Sloop";
int SHIP_HEALTH = 100;
string NAME;
vector <string> CREW;

//prototypes
void game_play();

void clear() 
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

bool init()
{
	cout << "Ahoy thar! Welcome to the Pirate Game! ARRGH!" << endl;
	cout << "Would ye like to play? (Y/N)";
	string input = "";
	while (input != "Y" && input != "N")
	{
		cin >> input;
	}
	if(input == "N")
	{
		return false;
	}
	else if(input == "Y")
	{
		clear();
		cout << "That be the spirit! What be yer name?"; 
		cin >> NAME;
		return true;
	}
	
}

void land_menu()
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

void tutorial_init()
{
	clear();
	cout << "It be a pleasure to set sail with ye, " << NAME << "! ARRGH!" << endl << endl;
	cout << "This be the main menu. Ye can navigate the menu by enterin\' the respective numbers." << endl << endl;
	land_menu();
	cout << endl;
	cout << "Yer objective be to gain as much wealth as possible before death be yer fate! ARRGH" << endl;
	cout << "Upgrading yer ships, growin\' yer crew, and tryin\' yer luck can help yer chances while sailin\' the seas." << endl;
	cout << "Ye will start off with the Sloop as yer vessel, a crew of size 0, a wealth of $0, and a health of 100 points." << endl;
	cout << "Best of luck to ye!" << endl;
	cout << "Enter \"START\" to begin the game: ";
	string input = "";
	while (input != "START")
	{
		cin >> input;
	}
	clear();
}

void sail() //1
{
	clear();
	game_play();
}

void build_crew() //2
{
	clear();
	game_play();
}

void ship_yard() //3
{
	string input = "";
	if (WEALTH == 0)
	{
		cout << "Ye need some wealth to come to the ship yard!" << endl;
		cout << "(Type C to Continue) : ";
		cin >> input;
		while (input != "C")
		{
			cin >> input;
		}
		clear();
		game_play();
	}
	else
	{
		//do stuff
	}
}

void try_luck() //4
{
	clear();
	game_play();
}

void status() //5
{
	clear();
	cout << "Status of " << NAME << ": " << endl << endl;
	cout << "Health: " << HEALTH << endl;
	cout << "Wealth: " << WEALTH << endl;
	cout << "Ship: " << SHIP << endl;
	cout << "Ship Health: " << SHIP_HEALTH << endl;
	cout << "Crew size: " << CREW.size() << endl;
	if (CREW.size() > 0)
	{
		cout << "Crew members: " << endl;
		for (int i = 0; i < CREW.size(); i++)
		{
			cout << "  " << CREW.at(i) << endl;
		}
	}
}

void save() //6
{
	clear();
	cout << "This feature is not yet implemented" << endl;
	cout << "(Type C to Continue) : ";
	string input = "";
	while (input != "C")
	{
		cin >> input;
	}
	clear();
	game_play();
}

void game_play()
{
	land_menu();
	string input = "";
	while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "Q")
	{
		cin >> input;
	}
	if (input == "Q")
	{
		return;
	}
	else if (input == "1")
	{
		clear();
		sail();
	}
	else if (input == "2")
	{
		clear();
		build_crew();
	}
	else if (input == "3")
	{
		clear();
		ship_yard();
	}
	else if (input == "4")
	{
		clear();
		try_luck();
	}
	else if (input == "5")
	{
		clear();
		status();
	}
	else if (input == "6")
	{
		clear();
		save();
	}
}

int main()
{
	clear();
	if (init())
	{
		tutorial_init();
		game_play();
	}
	clear();
	cout << "Till we set sail again, " << NAME << "!" << endl;
	return 0;
}
