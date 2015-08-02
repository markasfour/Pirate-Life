#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <iostream>
#include <unistd.h>
using namespace std;

//TURN ANIMATIONS ON/OFF
bool ANIMATE = true;

//clear screen
void clear() 
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    cout << "\x1B[2J\x1B[H";
}

void sail_away()
{
	if (ANIMATE)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "                   ~;"<<endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "                  ,/|\\," << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "                ,/' |\\ \\," << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "              ,/'   | |  \\ " << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "            ,/'     | |  | " << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "          ,/'       |/   | " << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "        ,/__________|----'  ," << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "     ____......-----''-----/" << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "     \\  o   o          o  /" << endl;
			cout << "~~^~~^~^~^~^~^~~^~~^^~^~^~~^~^~~^~^~^~" << endl;
			cout << "~^~^~^^~^~~~~^~^~~~^~^~^~~~~^~^~^~^~~~" << endl;
			sleep(1);
			clear();
		}
	}
}

void sail_back()
{
	if (ANIMATE)
	{
		for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "                 ;~"<<endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "               ./|\\." << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "             ./ /| '\\." << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "            /  | |   '\\." << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "           |   | |     '\\." << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "           |    \\|       '\\. " << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "        .   '----|_________\\." << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "         \\------''----.....___" << endl;
			for (int j = 0; j < i; j++) {cout << " ";}
			cout << "          \\  o        o   o  /" << endl;
			cout << "~~^~~^~^~^~^~^~~^~~^^~^~^~~^~^~~^~^~^~" << endl;
			cout << "~^~^~^^~^~~~~^~^~~~^~^~^~~~~^~^~^~^~~~" << endl;
			sleep(1);
			clear();
		}
	}
}

#endif
