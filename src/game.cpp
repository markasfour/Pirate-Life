#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "ship.h"
using namespace std;

//global variables
int HEALTH = 100;
int WEALTH = 0;
string SHIP = "Sloop";
int SHIP_HEALTH = 100;
string NAME;
vector <string> CREW;

//MENU
menu MENU;

//prototypes
bool game_play();
void sail();
void status();

//clear screen
void clear() 
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

vector <vessel> ships;
void populate_ships()
{
	vessel boat;
	ships.push_back(boat);
	boat.change("Pinnace", 120, 10, 150);
	ships.push_back(boat);
	boat.change("Lugger", 110, 12, 160);
	ships.push_back(boat);
	boat.change("Corvette", 180, 20, 220);
	ships.push_back(boat);
	boat.change("Schooner", 200, 20, 275);
	ships.push_back(boat);
	boat.change("Collier", 250, 30, 400);
	ships.push_back(boat);
	boat.change("Galleon", 375, 75, 650);
	ships.push_back(boat);
	boat.change("Barque", 500, 100, 1000);
	ships.push_back(boat);
	boat.change("Clipper", 700, 150, 2250);
	ships.push_back(boat);
	boat.change("Frigate", 1000, 250, 4500);
	ships.push_back(boat);
	boat.change("Man O\' War", 1200, 200, 5000);
	ships.push_back(boat);
	boat.change("Ship of the Line", 1100, 300, 6000);
	ships.push_back(boat);
	boat.change("The Armada\'s Brig", 1500, 450, 15000);
	ships.push_back(boat);
	boat.change("Royal Navy's Frigate", 1500, 450, 20000);
	ships.push_back(boat);
	boat.change("The Black Pearl", 2000, 750, 100000);
	ships.push_back(boat);
	boat.change("The Flying Dutchman", 3000, 1000, 500000);
	ships.push_back(boat);
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
		cout << "That be the spirit! What be yer name? :"; 
		cin >> NAME;
		//initialize game
		populate_ships();
		return true;
	}
	
}

//used first time playing game
void tutorial_init()
{
	clear();
	cout << "It be a pleasure to set sail with ye, " << NAME << "! ARRGH!" << endl << endl;
	cout << "This be the main menu. Ye can navigate the menu by enterin\' the respective numbers." << endl << endl;
	MENU.land();
	cout << endl;
	cout << "Yer objective be to gain as much wealth as possible before death be yer fate! ARRGH" << endl;
	cout << "Upgrading yer ships, growin\' yer crew, and tryin\' yer luck can help yer chances while sailin\' the seas." << endl;
	cout << endl;
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
	
	cout << "Ye be sailin\' the Seven Seas! ARRGH!" << endl;
	MENU.sea();
	cout << "What woul\' ye like to do, capt\'n " << NAME << "? " << endl;
	string input = "";
	while (input != "1" && input != "2" && input != "3")
	{
		cin >> input;
	}
	
	if (input == "1")
	{
		next = rand() % 100;
		if (next < 20)
		{
			clear();
			cout << "It be smooth sailin\'." << endl;
			sail();
		}
		else if (next < 30)
		{
			clear();
			cout << "Ye got battered up by some stormy weather! ARRGH!" << endl;
			injury = rand() % 3 + 1; //from 1 to 3
			cout << "Health -" << injury;
			HEALTH -= injury;
			sail();
		}
		else if (next < 45)
		{
			clear();
			if (CREW.size() > 1)
			{
				if (next % 3 == 0)
				{
					cout << "Yer crew came down wit\' scurvy! ARRGH!" << endl;
					injury = rand() % 5 + 5; //from 5 to 10
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
				else if (next % 3 == 1)
				{
					cout << "Yer crew started a fight on board yer ship! Them scalleywags!" << endl;
					injury = rand() % 2 + 5; //from 2 to 7
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
				else
				{
					cout << "Yer crew didn\'t get any shut eye!" << endl;
					injury = 1;
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
			}
			else
			{
				clear();
				if (next % 3 == 0)
				{
					cout << "Ye came down wit\' scurvy! ARRGH!" << endl;
					injury = rand() % 5 + 5; //from 5 to 10
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
				else if (next % 3 == 1)
				{
					cout << "Ye got sea sick from some rough tides!" << endl;
					injury = rand() % 2 + 5; //from 2 to 7
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
				else
				{
					cout << "Yer couldn\'t get any shut eye!" << endl;
					injury = 1;
					cout << "Health -" << injury << endl;
					HEALTH -= injury;
				}
			}
			sail();
		}
		else if (next < 60)
		{
			clear();
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
			clear();
			cout << "Thar be a small ship up ahead. Would ye like to attack? (Y/N) " << endl;
			input = "";
			cin >> input;
			while (input != "Y" && input != "N")
			{
				cin >> input;
			}
			if (input == "Y")
			{
				//battle
			}
			else if (input == "N")
			{
				cout << "Ye let the humble wee vessel be..." << endl;
			}
			sail();
		}
		else
		{
			clear();
			MENU.prebattle();
			cout << "A military ship is just under the horizon. Would ye like to do?" << endl;
			input = "";
			cin >> input;
			while (input != "1" && input != "2" && input != "3" && input != "4")
			{
				cin >> input;
			}
			if (input == "1")
			{
				//battle
			}
			else if (input == "2")
			{
				clear();
				status();
			}
			else if (input == "3")
			{

			}
			else if (input == "4")
			{
				if (next % 3 != 0)
				{
					cout << "Ye sailed passed their ship unharmed." << endl;
				}
				else
				{
					cout << "The ship blocked yer path! ARRGH! To battle!" << endl;
					//battle
				}
			}
			sail();
		}
	}
	else if (input == "2")
	{
		clear();
		status();
		sail();
	}
	else if (input == "3")
	{
		clear();
	}
}

void build_crew() //2
{
	clear();
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
	}
	else
	{
		cout << "Ahoy thar! Welcome to the ship yard!" << endl;
		cout << endl;
		//print out ships
		for (int i = 0; i < ships.size(); i++)
		{
			cout << i + 1 << ". " << ships.at(i).name << endl;
		}
		cout << endl;
		cout << "Which vessel woul\' ye like to buy?";
		int num = 0;
		cin >> num;
		while(num < 1 && num > 16)
		{
			cin >> num;
		}

		clear();
		cout << ships.at(num - 1).name << endl;
		cout << "Max Health: " << ships.at(num - 1).max_health << endl;
		cout << "Max Capacity: " << ships.at(num - 1).max_capacity << endl;
		cout << "Price: " << ships.at(num - 1).max_value << endl;
		cout << endl;
		cout << "Type C to Continue: ";
		input = "";
		cin >> input;
		while (input != "C")
		{
			cin >> input;
		}
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
}

bool game_play()
{
	MENU.land();
	string input = "";
	while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" && input != "6" && input != "Q")
	{
		cin >> input;
	}
	if (input == "Q")
	{
		return false;
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
		while (game_play());
	}
	clear();
	if (NAME != "")
	{
		cout << "Till we set sail again, " << NAME << "!" << endl;
	}
	return 0;
}
