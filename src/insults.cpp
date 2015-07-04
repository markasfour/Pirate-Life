#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

vector <string> arr1 {"Ye be a ", "Yer mum be a ", "Yer mummy be a ", 
					  "Yer crew be a ", "Yer ship be a ", "Yer lassy be a ", 
					  "Yer lad be a "};

vector <string> arr2 {"fowl ", "wretched ", "scurvy-lovin' ", "land-lovin\' ", 
					  "good fer nothin\' ", "lily-livered ", "yellow bellied ", 
					  "barnacle bottomed ", "barnacle lovin\' ", 
					  "mermaid marryin\' ", "thievin\' "};

vector <string> arr3 {"scallywag!", "blubber!", "whale!", "buffoon!", "kraken!", 
					  "rascal!", "blaggard!", "milk maid!", "landlubber!", 
					  "sorry sea dog!", "salty swab!", "blowfish!", "swine!"};

int main()
{
	srand(time(NULL));
	cout << arr1.at(rand() % arr1.size()) << arr2.at(rand() % arr2.size()) << arr3.at(rand() % arr3.size());
	cout << endl;
	return 0;
}
