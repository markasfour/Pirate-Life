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
};

#endif
