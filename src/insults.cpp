#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

vector <string> arr1 {"Ye be ", "Yer mum be ", "Yer mummy be ", "Yer crew be ", "Yer ship be ", "Yer lassy be ", "Yer lad be "};

vector <string> arr2 {"a fowl ", "a wretched ", "a scurvy-lovin' ", "a land-lovin\' ", "a good fer nothin\' ", "a lily-livered ", "a yellow bellied ", "a barnacle bottomed ", "a barnacle lovin\' ", "a mermaid marryin\' ", "a thievin\' "};

vector <string> arr3 {"scallywag!", "blubber!", "whale!", "buffoon!", "kraken!", "rascal!", "blaggard!", "milk maid!", "landlubber!", "sorry sea dog!", "salty swab!", "blowfish!", "swine!"};


int main()
{
	srand(time(NULL));
	cout << arr1.at(rand() % arr1.size()) << arr2.at(rand() % arr2.size()) << arr3.at(rand() % arr3.size());
	cout << endl;
	return 0;
}
