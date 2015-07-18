#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>

struct vessel
{
	string name;
	int max_health;
	int max_capacity;
	int max_value;
	vessel() //default constructor
	{
		name = "Sloop";
		max_health = 100;
		max_capacity = 10;
		max_value = 100;	
	}
	vessel(string n, int mh, int mc, int mv) //constructor for ships in yard
	{
		name = n;
		max_health = mh;
		max_capacity = mc;
		max_value = mv;
	}
	void change(string n, int mh, int mc, int mv) //alter boat attributes
	{
		name = n;
		max_health = mh;
		max_capacity = mc;
		max_value = mv;
	}
};

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

class ship
{
	private:
		vessel current;
		int health;
		int capacity;
		
	public:
		ship() {}; //constructor
		~ship() {}; //destructor

		string get_current_ship() {return current.name;}; //return name of current ship
		int get_max_health() {return current.max_health;}; //return max health of current ship
		int get_health() {return health;}; //return current health of current ship
		int get_max_capacity() {return current.max_capacity;}; //return max capacity of current ship
		int get_capacity() {return capacity;}; //return current capacity of current ship
		int get_max_value() {return current.max_value;}; //return max value of current ship
		int get_value() {return ((get_health() / get_max_health()) * get_max_value());}; //return calculated value of current ship

		void details(); //print out all current ship details
		void buy(vessel name); //procedure to convert current ship to new ship

};

void ship::details()
{
	cout << get_current_ship();
	cout << "Health: " << get_health() << "/" << get_max_health() << endl;
	cout << "Capacity: " << get_capacity() << "/" << get_max_capacity() << endl;
	cout << "Value: " << get_value() << "/" << get_max_value() << endl;
}

void ship::buy(vessel purchased)
{
	current.name = purchased.name;
	current.max_health = purchased.max_health;
	health = current.max_health;
	current.max_capacity = purchased.max_capacity;
	capacity = purchased.max_capacity;
	current.max_value = purchased.max_value;
}
#endif