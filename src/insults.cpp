#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

vector <string> arr1 {"Ye are ", "Yer mum be ", "Yer mummy be "};

vector <string> arr2 {"a fowl ", "a wretched ", "a scurvy-lovin' ", "a land-lovin\' "};

vector <string> arr3 {"scallywag!", "blubber!", "whale!", "buffoon!", "kraken!"};


int main()
{
	srand(time(NULL));
	cout << arr1.at(rand() % arr1.size()) << arr2.at(rand() % arr2.size()) << arr3.at(rand() % arr3.size());
	cout << endl;
	return 0;
}
