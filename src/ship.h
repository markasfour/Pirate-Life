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
	};
	~vessel() {};//destructor
	vessel(string n, int mh, int mc, int mv) //constructor for ships in yard
	{
		name = n;
		max_health = mh;
		max_capacity = mc;
		max_value = mv;
	};
	void change(string n, int mh, int mc, int mv) //alter boat attributes
	{
		name = n;
		max_health = mh;
		max_capacity = mc;
		max_value = mv;
	};
};

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
