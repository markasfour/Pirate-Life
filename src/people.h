#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
using namespace std;

struct person
{
	string name;
	string gender;
	string type;

	person() {}; //default constructor
	~person() {}; //destructor
	person(const person & p) //copy constructor
	{
		name = p.name;
		gender = p.gender;
		type = p.type;
	}
	void get_details() //print all of person's details
	{
		cout << name << endl;
		cout << gender << endl;
		cout << type << endl;
	}
};

#endif
