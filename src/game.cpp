#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "menu.h"
#include "ship.h"
#include "people.h"
#include "animations.h"
using namespace std;

//global variables
//Main character
int HEALTH = 100;
int WEALTH = 0;
string NAME;
bool GHOST = false;
bool OWN_SHIP = true;

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
	cout << "Upgrading yer ships, growin\' yer crew, and visitin\' the tavern can help yer chances while sailin\' the seas." << endl;
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

void end_game()
{
	if (!GHOST)
	{
		GHOST = true;
		game_over();
		cout << NAME << ", yer fate has been sealed. Ye have died. ARRGH!" << endl;
		cout << "Would ye like to continue playing as a ghost? (Y/N)" << endl;
		string input = "";
		cin >> input;
		while (input != "Y" && input != "N")
		{
			cin >> input;
		}
		if (input == "N")
		{
			exit(0);
		}
		else if (input == "Y")
		{
			NAME += " (Ghost)";
		}
	}
}

int get_crew_attack()
{
	int attack = 0;
	if (CREW.size() > 0)
	{
		for (int i = 0; i < CREW.size(); i++)
		{
			attack += CREW.at(i).get_strength();
			attack += CREW.at(i).get_moral();	
		}
	}
	attack += 10; //your own attack
	return attack;
}

double get_crew_accuracy()
{
	double accuracy = 0;
	if (CREW.size() > 0)
	{
		for (int i = 0; i < CREW.size(); i++)
		{
			accuracy += CREW.at(i).get_intelligence();
			accuracy += CREW.at(i).get_moral();	
		}
		double x = 0;
		x += 10 * CREW.size();
		accuracy = accuracy / x;
	}
	else
	{
		accuracy += 1; //your own accuracy
	}
	return accuracy;
}

double get_crew_luck()
{
	double luck = 0;
	if (CREW.size() > 0)
	{
		for (int i = 0; i < CREW.size(); i++)
		{
			luck += CREW.at(i).get_intelligence();
			luck += CREW.at(i).get_charisma();	
		}
		double x = 0;
		x += 10 * CREW.size();
		luck = luck / x;
	}
	else
	{
		luck += 1; //your own accuracy
	}
	return luck;
}

void enemy_attack(ship ENEMY)
{
	int damage = 0;
	int attack = ENEMY.get_capacity() * 10;
	for (int i = 0; i < ENEMY.get_capacity(); i++)
	{
		attack -= 4 * (rand() % 3);
	}
	damage = attack + (rand() % (attack / 5));
	if (rand() % 10 < 8) //80% of the time
	{
		damage -= attack / 3;
	}
	cout << endl;
	cout << "The enemy fired their cannons!" << endl;
	cout << "The enemy did " << attack << " damage to yer ship! ARRGH!" << endl;
	MY_SHIP.damage_ship(attack);
	if (MY_SHIP.get_health() <= 0)
	{
		cout << "The enemy has sunk yer ship!" << endl;
		end_game();
	}
	if (attack >= 10 && CREW.size() > 0)
	{
		int collateral = 0;
		collateral = rand() % (attack / 10);
		if (collateral > CREW.size())
		{
			collateral = CREW.size();
		}
		if (collateral != 0 && rand() % 5 < 2)
		{
			cout << collateral << " of yer crew have been taken out collaterally! ARRGH!" << endl;
			for (int i = 0; i < collateral; i++)
			{
				MY_SHIP.sub_from_capacity();
				CREW.erase(CREW.begin() + (rand() % CREW.size()));
			}
		}
	}
	if (rand() % 10 < 3) //20% of the time
	{
		int injury = 0;
		injury = rand() % 20 + 1; //from 1 to 20
		HEALTH -= injury;
		cout << "Ye have been wounded by the blast!" << endl;
		cout << "Health -" << injury << endl;
		if (HEALTH <= 0)
		{
			end_game();
		}
	}
}

void victory(int x, ship ENEMY, bool commercial)
{
	int money = 0;
	if (x == 1) //ship sunk
	{
		money = (rand() % ENEMY.get_max_value()) / 4;
		if (commercial)
		{
			money = money * 2;
		}
		cout << "Ye were able to salvage some booty from the wreckage." << endl;
		cout << "Wealth +" << money;
		WEALTH += money;
	}
	else if (x == 2) //enemy crew eliminated but did not board ship
	{
		money = (rand() % ENEMY.get_max_value()) / 2; 
		if (commercial)
		{
			money = money * 2;
		}
		cout << "Ye were able to salvage some booty from aboard their ship." << endl;
		cout << "Wealth +" << money;
		WEALTH += money;
		cout << endl;
		cout << "Would ye like to claim the enemy ship as yer own? (Y/N)" << endl;
		string input = "";
		cin >> input;
		while (input != "Y" && input != "N")
		{
			cin >> input;
		}
		if (input == "Y")
		{
			MY_SHIP.claim(ENEMY);
			if (CREW.size() > MY_SHIP.get_max_capacity())
			{
				int i = 0;
				while (CREW.size() > MY_SHIP.get_max_capacity())
				{
					CREW.erase(CREW.begin() + CREW.size() - 1);
					i++;
				}
				cout << i << " of yer crew were abandoned." << endl;
			}
			cout << "Ye have claimed the " << MY_SHIP.get_name() << endl;
		}
	}
	else if (x == 3) //enemy crew eliminated by boarding the ship
	{
		money = (rand() % ENEMY.get_max_value()); 
		if (commercial)
		{
			money = money * 2;
		}
		cout << "Ye were able to salvage the treasures aboard their ship." << endl;
		cout << "Wealth +" << money;
		WEALTH += money;
		cout << endl;
		cout << "Would ye like to claim the enemy ship as yer own? (Y/N)" << endl;
		string input = "";
		cin >> input;
		while (input != "Y" && input != "N")
		{
			cin >> input;
		}
		if (input == "Y")
		{
			MY_SHIP.claim(ENEMY);
			if (CREW.size() > MY_SHIP.get_max_capacity())
			{
				int i = 0;
				while (CREW.size() > MY_SHIP.get_max_capacity())
				{
					CREW.erase(CREW.begin() + CREW.size() - 1);
					i++;
				}
				cout << i << " of yer crew were abandoned." << endl;
			}
			cout << "Ye have claimed the " << MY_SHIP.get_name() << endl;
		}
	}
	cout << endl;
}

void battle(ship ENEMY, bool commercial)
{
	while (true)
	{
		string input = "";
		MENU.battle();
		cin >> input;
		while (input != "1" && input != "2" && input != "3" && input != "4" && input != "5")
		{
			cin >> input;
		}
		if (input == "1")
		{
			double damage = 0;
			if ((rand() % static_cast<int>(get_crew_accuracy() * 10)) != 0)
			{
				if ((rand() % static_cast<int>(get_crew_luck() * 10)) < 2)
				{
					damage = get_crew_attack() * (1 + ((rand() % static_cast<int>(get_crew_luck() * 10)) / 10.0));
				}
				else if ((rand() % static_cast<int>(get_crew_luck() * 10)) < 4)
				{
					damage = get_crew_attack() * (1 - ((rand() % static_cast<int>(get_crew_luck() * 10)) / 10.0));
				}
				else
				{
					damage = get_crew_attack(); 
				}
			}
			if (damage != 0)
			{
				cout << "Yer cannons did " << damage << " damage to the enemy!" << endl;
				if (damage >= 10 && ENEMY.get_capacity() > 0)
				{
					int collateral = 0;
					collateral = rand() % (static_cast<int>(damage) / 10);
					if (collateral > ENEMY.get_capacity())
					{
						collateral = ENEMY.get_capacity();
					}
					if (collateral != 0 && rand() % 5 < 2)
					{
						cout << collateral << " enemies have been taken out collaterally! ARRGH!" << endl;
						for (int i = 0; i < collateral; i++)
						{
							ENEMY.sub_from_capacity();
						}
					}
				}
			}
			else
			{
				cout << "Yer cannons missed the ship! ARRGH!" << endl;
			}
			ENEMY.damage_ship(damage);
			if (ENEMY.get_health() <= 0 || ENEMY.get_capacity() <= 0)
			{
				int v = 0;
				if (ENEMY.get_health() <= 0)
				{
					cout << "Ye have sunk the enemy ship!" << endl;
					v = 1;
				}
				else if(ENEMY.get_capacity() <= 0)
				{
					cout << "Ye have eliminated the enemy crew!" << endl;
					v = 2;
				}
				cout << "Ye have won the battle! ARRGH!" << endl;
				cout << endl;
				victory(v, ENEMY, commercial);
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				break;
			}
			enemy_attack(ENEMY);	
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
			continue;
		}
		else if (input == "2")
		{
			if (CREW.size() < 1)
			{
				cout << "Ye don\'t have any crew members to send over!" << endl;
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				continue;
			}
			else
			{
				cout << "How many crew member will ye send to fight?" << endl;
				cout << "Ye have " << CREW.size() << " people in yer crew." << endl;
				int n = 0;
				int friendly = 0;
				int foe = 0;

				cin >> n;
				while (n > CREW.size() && n < 1)
				{
					cout << "Ye can\'t send that many people!" << endl;
					cin >> n;
				}
				cout << endl;
				while (n > 0 && ENEMY.get_capacity() > 0)
				{
					if (rand() % 2 == 0)
					{
						CREW.erase(CREW.begin() + (rand() % CREW.size()));
						MY_SHIP.sub_from_capacity();
						friendly++;
						n--;
					}
					else
					{
						ENEMY.sub_from_capacity();
						foe++;
					}
				}
				if (n == 0)
				{
					cout << "The enemy slaughtered yer crew! ARRGH!" << endl;
					cout << friendly << " friendlies killed." << endl;
					cout << foe << " enemies killed." << endl;
					input = "";
					cout << "Type C to continue: ";
					cin >> input;
					while (input != "C")
					{
						cin >> input;
					}
					clear();
					continue;	
				}
				else if (ENEMY.get_capacity() == 0)
				{
					cout << "Yer crew has claimed victory over the enemy! ARRGH!" << endl;
					cout << friendly << " friendlies killed." << endl;
					cout << foe << " enemies killed." << endl;
					cout << endl;
					victory(3, ENEMY, commercial);
					input = "";
					cout << "Type C to continue: ";
					cin >> input;
					while (input != "C")
					{
						cin >> input;
					}
					clear();
					break;	
				}
			}
			enemy_attack(ENEMY);
		}
		else if (input == "3")
		{
			ENEMY.get_details();
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
			continue;
		}
		else if (input == "4")
		{
			clear();
			status();
			clear();
			continue;
		}
		else if (input == "5")
		{
			if (rand() % 3 != 0)
			{
				cout << "Ye got away safely." << endl;
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				break;
			}
			else
			{
				cout << "Their ship blocked yer path! ARRGH!" << endl;
				enemy_attack(ENEMY);
				input = "";
				cout << "Type C to continue: ";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				continue;
			}		
		}
	}
}

void prebattle(int i, ship ENEMY)
{
	bool commercial;
	string input = "";
	MENU.prebattle();

	if (i == 1)
	{
		cout << "A commercial ship is just under the horizon. What would ye like to do?" << endl;
		commercial = true;
	}
	else if (i == 2)
	{
		cout << "A military ship is just under the horizon. What would ye like to do?" << endl;
		commercial = false;
	}
	cin >> input;
	while (input != "1" && input != "2" && input != "3" && input != "4")
	{
		cin >> input;
	}
	if (input == "1")
	{
		ENEMY.get_details();
		cout << endl;
		cout << "Type C to continue: ";
		cin >> input;
		while (input != "C")
		{
			cin >> input;
		}
		clear();
		prebattle(i, ENEMY);
	}
	else if (input == "2")
	{
		clear();
		status();
		clear();
		prebattle(i, ENEMY);
	}
	else if (input == "3")
	{
		clear();
		battle(ENEMY, commercial);
	}
	else if (input == "4")
	{
		if (rand() % 3 != 0)
		{
			cout << "Ye sailed passed their ship unharmed." << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
		}
		else
		{
			cout << "The ship blocked yer path! ARRGH! To battle!" << endl;
			input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
			battle(ENEMY, commercial);
		}
	}
}

void sail() //1
{
	string input = "";
	if (!OWN_SHIP)
	{
		cout << "Ye need a ship to sail the seas!" << endl;
		input = "";
			cout << "Type C to continue: ";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
		clear();
	}
	else if (OWN_SHIP)
	{
		int next = 0;
		int injury = 0;
		int treasure = 0;
		
		cout << "Ye be sailin\' the Seven Seas! ARRGH!" << endl;
		MENU.sea();
		cout << "What woul\' ye like to do, capt\'n " << NAME << "? " << endl;
		while (input != "1" && input != "2" && input != "3")
		{
			cin >> input;
		}
		
		if (input == "1")
		{
			clear();
			sail_away();
			clear();
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
				cout << "Health -" << injury << endl;
				HEALTH -= injury;
				if (HEALTH <= 0)
				{
					end_game();
				}
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
						if (HEALTH <= 0)
						{
							end_game();
						}
					}
					else if (next % 3 == 1)
					{
						cout << "Yer crew started a fight on board yer ship! Them scalleywags!" << endl;
						injury = rand() % 2 + 5; //from 2 to 7
						cout << "Health -" << injury << endl;
						HEALTH -= injury;
						if (HEALTH <= 0)
						{
							end_game();
						}
					}
					else
					{
						cout << "Yer crew didn\'t get any shut eye!" << endl;
						injury = 1;
						cout << "Health -" << injury << endl;
						HEALTH -= injury;
						if (HEALTH <= 0)
						{
							end_game();
						}
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
						if (HEALTH <= 0)
						{
							end_game();
						}
					}
					else if (next % 3 == 1)
					{
						cout << "Ye got sea sick from some rough tides!" << endl;
						injury = rand() % 2 + 5; //from 2 to 7
						cout << "Health -" << injury << endl;
						HEALTH -= injury;
						if (HEALTH <= 0)
						{
							end_game();
						}
					}
					else
					{
						cout << "Yer couldn\'t get any shut eye!" << endl;
						injury = 1;
						cout << "Health -" << injury << endl;
						HEALTH -= injury;
						if (HEALTH <= 0)
						{
							end_game();
						}
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
				ship ENEMY((rand() % (return_ship_index(MY_SHIP.get_name()) + 3)) % ships.size());
				ENEMY.set_capacity((rand() % ENEMY.get_max_capacity()) + 1);
				prebattle(1, ENEMY);	
				sail();
			}
			else
			{
				clear();
				ship ENEMY((rand() % (return_ship_index(MY_SHIP.get_name()) + 3)) % ships.size());
				ENEMY.set_capacity((rand() % ENEMY.get_max_capacity()) + 1);
				prebattle(2, ENEMY);	
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
			sail_back();
			clear();
		}
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
		if (!OWN_SHIP)
		{
			cout << "Ye need a ship to recruit new crew members!" << endl;
			cout << "Type C to Continue: ";
			input = "";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
		}
		else if (OWN_SHIP)
		{
			interact();
		}
	}
	else if (input == "2")
	{
		if (!OWN_SHIP)
		{
			cout << "Ye need a ship to recruit new crew members!" << endl;
			cout << "Type C to Continue: ";
			input = "";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear();
		}
		else if (OWN_SHIP)
		{
			cout << "Ye threatened the crowd." << endl;
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
					a.give_stats();
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
	}
	else if (input == "3")
	{
		clear();
		if (!OWN_SHIP || CREW.size() == 0)
		{
			cout << "Ye don\'t have any crew members!" << endl;
			cout << "Type C to Continue: ";
			input = "";
			cin >> input;
			while (input != "C")
			{
				cin >> input;
			}
			clear(); 
		}
		else
		{
			edit_crew();	
		}
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
	a.give_stats();
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
		cout << "Ye insulted " << a.get_name() << "." << endl;
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
			//TODO make random chance to join
			WEALTH = WEALTH - num;
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
		int x = 1;
		cout << "Crew: " << endl;
		cout << CREW.at(0).get_name();
		for (int i = 1; i < CREW.size(); i++)
		{
			cout << ", ";
			if (x % 3 == 0)
			{
				cout << endl;
			}
			cout << CREW.at(i).get_name();
			x++;
		}
		cout << endl;
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
		string m = "";
		cin >> n >> m;
		n += " " + m;
		while (n != "R" && !(find_crew_member(n)))
		{
			cout << "That ain\'t be a person in yer crew." << endl;
			cin.clear();
			cin >> n >> m;
			n += " " + m;
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
		string m = "";
		cin >> n >> m;
		n += " " + m;
		while (n != "R" && !(find_crew_member(n)))
		{
			cout << "That ain\'t be a person in yer crew." << endl;
			cin.clear();
			cin >> n >> m;
			n += " " + m;
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
		MENU.ship_yard();
		cout << endl;
		input = "";
		cin >> input;
		while (input != "1" && input != "2" && input != "3" && input != "4")
		{
			cin >> input;
		}
		//print out ships
		if (input == "1")
		{
			clear();
			for (int i = 0; i < ships.size(); i++)
			{
				cout << i + 1 << ". " << ships.at(i).name << endl;
			}
			cout << endl;
			cout << "Which vessel woul\' ye like to buy? (Enter 0 to leave)";
			int num = 0;
			cin >> num;
			while(num < 0 && num > 16)
			{
				cin >> num;
			}
			if (num == 0)
			{
				clear();
			}
			else
			{
				clear();
				cout << ships.at(num - 1).name << endl;
				cout << "Max Health: " << ships.at(num - 1).max_health << endl;
				cout << "Max Capacity: " << ships.at(num - 1).max_capacity << endl;
				cout << "Price: " << ships.at(num - 1).max_value << endl;
				cout << endl;
				if (ships.at(num - 1).max_value > WEALTH)
				{
					cout << "Ye cannot afford this ship." << endl;
					cout << "Type C to Continue: ";
					input = "";
					cin >> input;
					while (input != "C")
					{
						cin >> input;
					}
					clear();
					ship_yard();
				}
				else
				{
					cout << "Be ye sure ye would like to buy this ship? (Y/N)" << endl;
					input = "";
					cin >> input;
					while (input != "Y" && input != "N")
					{
						cin >> input;
					}
					if (input == "Y")
					{
						WEALTH -= ships.at(num - 1).max_value;
						MY_SHIP.buy(ships.at(num - 1));
						OWN_SHIP = true;
						cout << "ARRGH! Ye have bought the " << MY_SHIP.get_name() << endl;
						cout << endl;
						cout << "Type C to Continue: ";
						input = "";
						cin >> input;
						while (input != "C")
						{
							cin >> input;
						}
						clear();
						ship_yard();
					}
					else if (input == "N")
					{
						clear();
						ship_yard();
					}
				}
			}
		}
		else if (input == "2")
		{
			if (!OWN_SHIP)
			{
				clear();
				cout << "Ye don\'t own a ship to repair a ship!" << endl;
				cout << "Type C to Continue: ";
				input = "";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				ship_yard();
			}
			else if (OWN_SHIP)
			{
				//TODO
			}
		}
		else if (input == "3")
		{
			clear();
			if (!OWN_SHIP)
			{
				cout << "Ye need to own a ship to sell a ship!" << endl;
				cout << "Type C to Continue: ";
				input = "";
				cin >> input;
				while (input != "C")
				{
					cin >> input;
				}
				clear();
				ship_yard();
			}
			else if (OWN_SHIP)
			{
				cout << "Sellin\' yer " << MY_SHIP.get_name() << " will give ye +" << MY_SHIP.get_value() << " Wealth." << endl;
				cout << "Warning: If ye sell yer ship, ye will lose yer crew." << endl;
				cout << "Be ye sure ye wana sell the " << MY_SHIP.get_name() << "? (Y/N) " << endl;
				input = "";
				cin >> input;
				while (input != "Y" && input != "N")
				{
					cin >> input;
				}
				if (input == "Y")
				{
					WEALTH += MY_SHIP.get_value();
					int y = CREW.size();
					for (int i = 0; i < y; i++)
					{
						CREW.erase(CREW.begin());
						MY_SHIP.sub_from_capacity();
					}
					OWN_SHIP = false;
					cout << "Ye have sold yer ship!" << endl;
					cout << "Wealth +" << MY_SHIP.get_value() << endl;
					cout << "Type C to Continue: ";
					input = "";
					cin >> input;
					while (input != "C")
					{
						cin >> input;
					}
					clear();
					ship_yard();
				}
				else if (input == "N")
				{
					clear();
					ship_yard();
				}
			}
		}
		else if (input == "4")
		{
			clear();
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
		cout << "The tavern is under construction..." << endl;
		cout << "(Type C to Continue) : ";
		cin >> input;
		while (input != "C")
		{
			cin >> input;
		}
		clear();
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
	if (OWN_SHIP)
	{
		MY_SHIP.get_details();
	}
	else if (!OWN_SHIP)
	{
		cout << "Not a ship owner" << endl;
	}
	cout << endl;
	cout << "Crew size: " << CREW.size() << endl;
	if (CREW.size() != 0)
	{
		int soldier = 0;
		int sailor = 0;
		int seeker = 0;
		int swindler = 0;
		for (int i = 0; i < CREW.size(); i++)
		{
			if (CREW.at(i).get_type() == "Soldier")
			{
				soldier++;
			}
			else if (CREW.at(i).get_type() == "Sailor")
			{
				sailor++;
			}
			else if (CREW.at(i).get_type() == "Seeker")
			{
				seeker++;
			}
			else if (CREW.at(i).get_type() == "Swindler")
			{
				swindler ++;
			}
		}
		cout << sailor << " Sailors, " << soldier << " Soldiers, " << seeker << " Seekers, " << swindler << " Swinlders" << endl;
		cout << "Crew attack: " << static_cast<int>(get_crew_attack()) << endl;
		cout << "Crew accuracy: " << get_crew_accuracy() * 100 << "%" << endl;
		cout << "Crew Luck: " << get_crew_luck() * 100 << "%" << endl;
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
		if (OWN_SHIP)
		{
			sail_away();
		}
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
