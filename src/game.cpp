#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

//global variables
int HEALTH = 100;
int WEALTH = 0;
string SHIP = "Sloop";
int SHIP_HEALTH = 100;
string NAME;
vector <string> CREW;

//prototypes
void game_play();

//clear screen
void clear() 
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

//used first time playing game
bool init()
{
	cout << "Ahoy thar! Welcome to the Pirate Game! ARRGH!" << endl;
	cout << "Would ye like to play? (Y/N) ";
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
		cout << "That be the spirit! What be yer name? "; 
		cin >> NAME;
		return true;
	}
	
}

//main menu
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

//sea menu
void sea_menu()
{
	cout << "                    Navigate" << endl;
	cout << "    --------------------------------------" << endl;
	cout << "    |   1.    Continue sailing           |" << endl;
	cout << "    |   2.    Return to Land             |" << endl;
	cout << "    --------------------------------------" << endl;
}

//used first time playing game
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
	int next = 0;
	int injury = 0;
	int treasure = 0;

	sea_menu();
	cout << "What woul\' ye like to do, capt\'n " << NAME << "? " << endl;
	string input = "";
	while (input != "1" && input != "2")
	{
		cin >> input;
	}
	if (input == "1")
	{
		next = rand() % 100;
		if (next < 20)
		{
			cout << "It be smooth sailin\'." << endl;
			sail();
		}
		else if (next < 30)
		{
			cout << "Ye got battered up by some stormy weather! ARRGH!" << endl;
			injury = rand() % 3 + 1; //from 1 to 3
			cout << "Health -" << injury;
			HEALTH -= injury;
			sail();
		}
		else if (next < 45)
		{
			if (CREW.size() > 0)
			{
				if (next % 3 == 0)
				{
					cout << "Yer crew came down wit\' scurvy! ARRGH!" << endl;
					injury = rand() % 5 + 5; //from 5 to 10
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
				else if (next % 3 == 1)
				{
					cout << "Yer crew started a fight on board yer ship! Them scalleywags!" << endl;
					injury = rand() % 2 + 5; //from 2 to 7
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
				else
				{
					cout << "Yer crew didn\'t get any shut eye!" << endl;
					injury = 1;
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
			}
			else
			{
				if (next % 3 == 0)
				{
					cout << "Ye came down wit\' scurvy! ARRGH!" << endl;
					injury = rand() % 5 + 5; //from 5 to 10
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
				else if (next % 3 == 1)
				{
					cout << "Ye got sea sick from some rough tides!" << endl;
					injury = rand() % 2 + 5; //from 2 to 7
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
				else
				{
					cout << "Yer couldn\'t get any shut eye!" << endl;
					injury = 1;
					cout << "Health -" << injury;
					HEALTH -= injury;
				}
			}
			sail();
		}
		else if (next < 60)
		{
			cout << "Ye came across some floatin\' treasure!" << endl;
			if (next % 2 == 0)
			{
				treasure = rand() % 10 + 1 + 5; //from 5 to 15
			}
			else 
			{
				treasure = rand() % 5 + 1; //from 1 to 5
			}
			cout << "Wealth +" << treasure << endl;
			WEALTH += treasure;
			sail();
		}
		else if (next < 80)
		{
			cout << "Thar be a small ship up ahead. Would ye like to attack? (Y/N) " << endl;
			sail();
		}
		else
		{
			cout << "A military ship is just under the horizon. Would ye like to attack it? (Y/N) " << endl;
			sail();
		}
	}
	else if (input == "2")
	{
		clear();
		game_play();
	}
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
		cout << "Try settin\' sail first." << endl;
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
	string input = "";
	if (WEALTH == 0)
	{
		cout << "Ye need some wealth to come to the ship yard!" << endl;
		cout << "Try settin\' sail first." << endl;
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

void status() //5
{
	clear();
	cout << "Status of " << NAME << ": " << endl;
	cout << endl;
	cout << "Health: " << HEALTH << endl;
	cout << "Wealth: " << WEALTH << endl;
	cout << endl;
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
	cout << endl;
	cout << "(Type C to Continue) : ";
	string input = "";
	while (input != "C")
	{
		cin >> input;
	}
	clear();
	game_play();
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
	srand(time(NULL));

	if (init())
	{
		tutorial_init();
		game_play();
	}
	clear();
	cout << "Till we set sail again, " << NAME << "!" << endl;
	return 0;
}