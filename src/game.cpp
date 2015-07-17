#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
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
void game_play();
void sail();
void status();

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
		cout << "That be the spirit! What be yer name? :"; 
		cin >> NAME;
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
		game_play();
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
		cout << "Woul\' ye like to purchase one o\' me ships?" << endl;
		cout << endl;
		cout << "1.  Pinnace.....................$150" << endl;
		cout << "    Health: 120     Crew cap: 10    Attack level: 15" << endl;
		cout << endl;
		cout << "2.  Lugger......................$160" << endl;
		cout << "    Health: 110     Crew cap: 12    Attack level: 18" << endl;
		cout << endl;
		cout << "3.  Corvette....................$220" << endl;
		cout << "    Health: 180     Crew cap: 20    Attack level: 30" << endl;
		cout << endl;
		cout << "4.  Schooner....................$275" << endl;
		cout << "    Health: 200     Crew cap: 20    Attack level: 33" << endl;
		cout << endl;
		cout << "5.  Collier.....................$400" << endl;
		cout << "    Health: 250     Crew cap: 30    Attack level: 45" << endl;
		cout << endl;
		cout << "6.  Galleon.....................$650" << endl;
		cout << "    Health: 375     Crew cap: 75    Attack level: 65" << endl;
		cout << endl;
		cout << "7.  Barque......................$1000" << endl;
		cout << "    Health: 500     Crew cap: 100   Attack level: 90" << endl;
		cout << endl;
		cout << "8.  Clipper.....................$2,250" << endl;
		cout << "    Health: 700     Crew cap: 150   Attack level: 110" << endl;
		cout << endl;
		cout << "9.  Frigate.....................$4,500" << endl;
		cout << "    Health: 1000    Crew cap: 250   Attack level: 150" << endl;
		cout << endl;
		cout << "10. Man O\' War.................$5,000" << endl;
		cout << "    Health: 1200    Crew cap: 200   Attack level: 135" << endl;
		cout << endl;
		cout << "11. Ship of the Line............$6,000" << endl;
		cout << "    Health: 1100    Crew cap: 300   Attack level: 145" << endl;
		cout << endl;
		cout << "12. The Armada's Brig...........$15,000" << endl;
		cout << "    Health: 1500    Crew cap: 450   Attack level: 200" << endl;
		cout << endl;
		cout << "13. Royal Navy's Frigate........$20,000" << endl;
		cout << "    Health: 1500    Crew cap: 500   Attack level: 200" << endl;
		cout << endl;
		cout << "14. The Black Pearl.............$100,000" << endl;
		cout << "    Health: 2000    Crew cap: 750   Attack level: 300" << endl;
		cout << endl;
		cout << "15. The Flying Dutchman.........$500,000" << endl;
		cout << "    Health: 3000    Crew cap: 1000  Attack level: 400" << endl;
		cout << endl;
		
		cin >> input;
		while (input != "1" && input != "2" && input != "1" && input != "4" && 
			   input != "5" && input != "6" && input != "7" && input != "8" && 
			   input != "9" && input != "10" && input != "11" && input != "12" && 
			   input != "13" && input != "14" && input != "15")
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

void game_play()
{
	MENU.land();
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
		game_play();
	}
	else if (input == "2")
	{
		clear();
		build_crew();
		game_play();
	}
	else if (input == "3")
	{
		clear();
		ship_yard();
		game_play();
	}
	else if (input == "4")
	{
		clear();
		try_luck();
		game_play();
	}
	else if (input == "5")
	{
		clear();
		status();
		game_play();
	}
	else if (input == "6")
	{
		clear();
		save();
		game_play();
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
	if (NAME != "")
	{
		cout << "Till we set sail again, " << NAME << "!" << endl;
	}
	return 0;
}
