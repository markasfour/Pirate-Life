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

void SleepMs(int ms) {
	usleep(ms*1000); //convert to microseconds
}

void sail_away()
{
	if (ANIMATE)
	{
		for (int i = 0; i < 7; i++)
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
			SleepMs(500);
			clear();
		}
	}
}

void sail_back()
{
	if (ANIMATE)
	{
		for (int i = 7; i > 0; i--)
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
			SleepMs(500);
			clear();
		}
	}
}

void game_over()
{
	if (ANIMATE)
	{
		cout << "   _____" << endl;
		cout << "  / ____|" << endl;
		SleepMs(500);
		cout << " | |  __  __ _ _ __ ___   ___" << endl;
		cout << " | | |_ |/ _` | '_ ` _ \\ / _ \\" << endl;
		SleepMs(500);
		cout << " | |__| | (_| | | | | | |  __/" << endl;
		cout << "  \\_____|\\__,_|_| |_| |_|\\___|" << endl;
		cout << endl;
		SleepMs(1000);
		cout << "  ____ " << endl;
		cout << " / __ \\" << endl;
		SleepMs(500);
		cout << "| |  | |_   _____ _ __" << endl;
		cout << "| |  | \\ \\ / / _ \\ '__|" << endl;
		SleepMs(500);
		cout << "| |__| |\\ V /  __/ |" << endl;
		cout << " \\____/  \\_/ \\___|_|" << endl;
		cout << endl;
		SleepMs(2000);
	}
}

#endif
