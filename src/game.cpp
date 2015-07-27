#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "ship.h"
#include "people.h"
using namespace std;

//global variables
//Main character
int HEALTH = 100;
int WEALTH = 0;
string NAME;

//Main character's ship
ship MY_SHIP;

//Main character's crew
vector <person> CREW;

//MENU
menu MENU;

//prototypes
bool game_play();
void sail();
void status();
void interact();
void edit_crew();

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
		//initialize game
		cout << "Populating ship yard...";
		populate_ships();
		cout << "Done" << endl;
		cout << "Populating male first names...";
		populate_male_first();
		cout << "Done" << endl;
		cout << "Populating female first names...";
		populate_female_first();
		cout << "Done" << endl;
		cout << "Populating last names...";
		populate_last();
		cout << "Done" << endl;
		
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
	cout << "Ye will start off with the " << MY_SHIP.get_name() << " as yer vessel, a crew of size 0, a wealth of $0, and a health of 100 points." << endl;
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
	string input = "";

	clear();
	cout << "Ye are at a crowded dock" << endl;
	cout << endl;
	MENU.dock();
	cin >> input;
	while (input != "1" && input != "2" && input != "3" && input != "4")
	{
		cin >> input;
	}
	if (input == "1")
	{
		clear();
		interact();
	}
	else if (input == "2")
	{
		cout << "Ye threatened the crowd..." << endl;
		//TODO make random chance for people to join
		
		if (CREW.size() >= MY_SHIP.get_max_capacity())
		{
			cout << "Yer vessel is already full!" << endl;
			cout << "Ye need a bigger ship to expand yer crew!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();
		}
		else
		{
			int crowd = (rand() % (MY_SHIP.get_max_capacity() - MY_SHIP.get_capacity()) % 5) + 1;
			for (int i = 0; i < crowd; i++)
			{
				person a;
				CREW.push_back(a);
				MY_SHIP.add_to_capacity();
				cout << a.get_name() << " is intimidated by ye." << endl;
				cout << a.get_name() << " has joined yer crew! ARRGH!" << endl;
			}
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();
		}
	}
	else if (input == "3")
	{
		clear();
		edit_crew();	
	}
	else if (input == "4")
	{
		clear();	
	}
}

void interact()
{
	string input = "";
	person a;
	string g;
	if (a.get_gender() == "Male")
	{
		g = "lad";
	}
	else
	{
		g = "lass";
	}
	cout << "Ye be talking to a "<< g<< " named " << a.get_name() << " who be a " << a.get_type() << "." << endl;
	MENU.interact();
	cin >> input;
	while (input != "1" && input != "2" && input != "3" && input != "4")
	{
		cin >> input;
	}
	if (input == "1")
	{
		//TODO make random chance to join
		if (CREW.size() < MY_SHIP.get_max_capacity())
		{
			CREW.push_back(a);
			MY_SHIP.add_to_capacity();
			cout << a.get_name() << " has joined yer crew! ARRGH!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();
		}
		else
		{
			cout << "Yer vessel is already full!" << endl;
			cout << "Ye need a bigger ship to expand yer crew!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();

		}
	}
	else if (input == "2")
	{
		//TODO make random chance to join
		cout << "Ye insulted " << a.get_name() << "..." << endl;
		if (CREW.size() < MY_SHIP.get_max_capacity())
		{
			CREW.push_back(a);
			MY_SHIP.add_to_capacity();
			cout << a.get_name() << " has joined yer crew! ARRGH!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();
		}
		else
		{
			cout << "Yer vessel is already full!" << endl;
			cout << "Ye need a bigger ship to expand yer crew!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			build_crew();

		}
	}
	else if (input == "3")
	{
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
			build_crew();
		}
		else
		{
			cout << "How much would ye like to offer? ";
			int num = 0;
			cin >> num;
			if (num > WEALTH || num <= 0)
			{
				do {
					cout << "Ye can\'t offer that much!" << endl;
					cout << "How much would ye like to offer? " << endl;
				} while (num > WEALTH && num <= 0);
			}
			WEALTH = WEALTH - num;
			//TODO make random chance to join
			if (CREW.size() < MY_SHIP.get_max_capacity())
			{
				CREW.push_back(a);
				MY_SHIP.add_to_capacity();
				cout << a.get_name() << " has joined yer crew! ARRGH!" << endl;
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				build_crew();
			}
			else
			{
				cout << "Yer vessel is already full!" << endl;
				cout << "Ye need a bigger ship to expand yer crew!" << endl;
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				build_crew();
			}
		}
	}
	else if (input == "4")
	{
		clear();
		build_crew();
	}
}

bool find_crew_member(string n)
{
	for (int i = 0; i < CREW.size(); i++)
	{
		if (n == CREW.at(i).get_name())
		{
			return true;
		}
	}
	return false;
}

int get_crew_member_index(string n)
{
	for (int i = 0; i < CREW.size(); i++)
	{
		if (n == CREW.at(i).get_name())
		{
			return i;
		}
	}
	return -1;
}

person get_crew_member(string n)
{
	for (int i = 0; i < CREW.size(); i++)
	{
		if (n == CREW.at(i).get_name())
		{
			return CREW.at(i);
		}
	}
}

void edit_crew()
{
	MENU.edit_crew();
	string input = "";
	while (input != "1" && input != "2" && input != "3" && input != "4")
	{
		cin >> input;
	}
	if (input == "1")
	{
		cout << "Crew: " << endl;
		cout << CREW.at(0).get_name();
		for (int i = 1; i < CREW.size(); i++)
		{
			cout << ", " << CREW.at(i).get_name();
		}
		cout << "Type C to Continue: ";
		input = "";
		cin >> input;
		while (input != "C")
		{
			cin >> input;
		}
		clear();
		edit_crew();
	}
	else if (input == "2")
	{
		cout << "Enter a crew member\'s name to retrieve their stats (Type R to return): ";
		string n = "";
		cin >> n;
		while (n != "R" && find_crew_member(n))
		{
			cout << "That ain\'t be a person in yer crew." << endl;
			cin >> n;
		}
		if (n == "R")
		{
			clear();
			edit_crew();
		}
		else
		{
			get_crew_member(n).get_details();
			cout << "Type C to Continue: ";
			input = "";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
			edit_crew();
		}
	}
	else if (input == "3")
	{
		cout << "Enter a crew member\'s name to remove (Type R to return): ";
		string n = "";
		cin >> n;
		while (n != "R" && find_crew_member(n))
		{
			cout << "That ain\'t be a person in yer crew." << endl;
			cin >> n;
		}
		if (n == "R")
		{
			clear();
			edit_crew();
		}
		else
		{
			CREW.erase(CREW.begin() + get_crew_member_index(n));
			MY_SHIP.sub_from_capacity();
			cout << n << " has been thrown overboard! ARRGH!" << endl;
			cout << "Type C to Continue: ";
			input = "";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
			edit_crew();
		}
	}
	else if (input == "4")
	{
		clear();
		build_crew();
	}
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
		cout << "Ye need some wealth to come to the tavern!" << endl;
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
	MY_SHIP.get_details();
	cout << endl;
	cout << "Crew size: " << CREW.size() << endl;
	if (CREW.size() > 0)
	{
		cout << "Crew members: " << endl;
		cout << endl;
		for (int i = 0; i < CREW.size(); i++)
		{
			CREW.at(i).get_details();
			cout << endl;
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
