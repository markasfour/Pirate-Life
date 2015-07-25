#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
using namespace std;

//Vector of names
vector <string> male_first;
vector <string> female_first;
vector <string> last;

void populate_male_first()
{
	//names taken from http://names.mongabay.com/male_names.htm
	string names[] = {"James", "John", "Robert", "Michael", 
					  "William", "David", "Richard", "Charles",
					  "Joseph", "Thomas", "Christopher" "Daniel",
					  "Paul", "Mark", "Donald", "George", "Kenneth",
					  "Steven", "Edward", "Brian", "Ronald",
					  "Anthony", "Kevin", "Jason", "Matthew",
					  "Gary", "Timothy", "Jose", "Larry", "Jeffrey",
					  "Frank", "Scott", "Eric", "Andrew", "Raymond",
					  "Gregory", "Joshua", "Jerry", "Dennis",
					  "Walter", "Peter", "Patrick", "Harold",
					  "Douglas", "Henry", "Carl", "Arthur", "Ryan",
					  "Roger", "Joe", "Juan", "Jack", "Albert",
					  "Justin", "Terry", "Gerald", "Keith", 
					  "Samuel", "Willie", "Ralph", "Lawrence",
					  "Nicholas", "Roy", "Benjamin", "Bruce", 
					  "Brandon", "Adam", "Harry", "Fred", "Wayne",
					  "Billy", "Louis", "Jeremy", "Aaron", "Randy",
					  "Howard", "Eugene","Carlos", "Russell",
					  "Bobby", "Victor", "Martin", "Todd", "Ernest",
					  "Phillip", "Jesse", "Craig", "Alan", "Shawn",
					  "Clarence", "Sean", "Earl", "Jimmy",
					  "Antonio", "Danny", "Bryan", "Tony", "Mike",
					  "Leonard", "Dale"};
	int size = 100;
	for (int i = 0; i < size; i++)
	{
		male_first.push_back(names[i]);
	}
}

void populate_female_first()
{
	//names taken from http://names.mongabay.com/female_names.htm
	string names[] = {"Mary", "Patricia", "Linda", "Barbara",
					  "Elizabeth", "Jennifer", "Maria", "Susan",
					  "Margaret", "Dorthy", "Lisa", "Nancy", 
					  "Karen", "Betty", "Helen", "Sandra", "Donna",
					  "Carol", "Ruth", "Sharon", "Michelle",
					  "Laura", "Sarah", "Kimberly", "Deborah", 
					  "Jessica", "Shirley", "Cynthia", "Angela", 
					  "Melissa", "Brenda", "Amy", "Anna", "Rebecca",
					  "Virginia", "Kathleen", "Pamela", "Martha", 
					  "Debra", "Amanda", "Stephanie", "Carolyn",
					  "Christine", "Marie", "Janet", "Catherine", 
					  "Frances", "Ann", "Joyce", "Diane", "Alice",
					  "Julie", "Heather", "Teresa", "Doris", 
					  "Gloria", "Evelyn", "Jean", "Cheryl", 
					  "Mildred", "Katherine", "Joan", "Ashely", 
					  "Judith", "Rose", "Janice", "Kelly", "Nicole",
					  "Judy", "Christina", "Kathy", "Theresa", 
					  "Beverly", "Denise", "Tammy", "Irene", "Jane",
					  "Lori", "Rachel", "Marilyn", "Andrea", 
					  "Kathryn", "Louise", "Sara", "Anne", 
					  "Jacqueline", "Wanda", "Bonnie", "Julia",
					  "Ruby", "Lois", "Tina", "Phyllis", "Norma",
					  "Paula", "Diana", "Annie", "Lillian", "Emily",
					  "Robin"};
	int size = 100;
	for (int i = 0; i < size; i++)
	{
		female_first.push_back(names[i]);
	}
}

void populate_last()
{
	//names taken from http://names.mongabay.com/data/1000.html
	string names[] = {"Smith", "Johnson", "Williams", "Brown", 
					 "Jones", "Miller", "Davis", "Garcia", 
					 "Rodriguez", "Wilson", "Martinez", "Anderson",
					 "Taylor", "Thomas", "Hernandez", "Moore", 
					 "Martin", "Jackson", "Thompson", "White", 
					 "Lopez", "Lee", "Gonzalez", "Harris", "Clark",
					 "Lewis", "Robinson", "Walker", "Perez", "Hall",
					 "Young", "Allen", "Sanchez", "Wright", 
					 "Wright", "King", "Scott", "Green", "Baker", 
					 "Adams", "Nelson", "Hill", "Ramirez", 
					 "Campbell", "Mitchell", "Roberts", "Carter",
					 "Phillips", "Evans", "Turner", "Torres", 
					 "Parker", "Collins", "Edwards", "Stewart", 
					 "Flores", "Morris", "Nguyen", "Murphy", 
					 "Rivera", "Cook", "Rogers", "Morgan", 
					 "Peterson", "Cooper", "Reed", "Bailey", "Bell",
					 "Gomez", "Kelly", "Howard", "Ward", "Cox",
					 "Diaz", "Richardson", "Wood", "Watson", 
					 "Brooks", "Bennett", "Gray", "James", "Reyes",
					 "Cruz", "Hughes", "Price", "Myers", "Long", 
					 "Foster", "Sanders", "Ross", "Morales", 
					 "Powell", "Sullivan", "Russell", "Ortiz",
					 "Jenkins", "Gutierrez", "Perry", "Butler", 
					 "Barnes", "Fisher"};
	int size = 100;
	for (int i = 0; i < size; i++)
	{
		last.push_back(names[i]);
	}
}

struct person
{
	private:
		int charisma;
		int intelligence;
		int moral;
		int strength;
		string name;
		string gender;
		string type;
		vector <string> types = {"Soldier", "Sailor", "Seeker", "Babe"};

	public:
	person() //default constructor
	{
		int x = rand() % 2;
		if (x)
		{
			gender = "Male";
			name = male_first.at(rand() % male_first.size()) + " " +
				   last.at(rand() % last.size());
			type = types.at(rand() % (types.size() - 1));
		}
		else
		{
			gender = "Female";
			name = female_first.at(rand() % female_first.size()) +
				   " " + last.at(rand() % last.size());
			type = types.at(rand() % (types.size() - 1) + 1);
		}
		if (type == "Soldier")
		{
			charisma = 1;
			intelligence = rand() % 5 + 1; //1 to 5
			moral = rand() % 5 + 1; //1 to 5
			strength = 5;
		}
		else if (type == "Sailor")
		{
			charisma = rand() % 5 + 1; //1 to 5
			intelligence = 5;
			moral = rand() % 5 + 1; //1 to 5
			strength = rand() % 5 + 1; //1 to 5
		}
		else if (type == "Seeker")
		{
			charisma = rand() % 5 + 1; //1 to 5
			intelligence = rand() % 2 + 4; //4 to 5
			moral = 5;
			strength = rand() % 5 + 1; //1 to 5
		}
		else if (type == "Babe")
		{
			charisma = 5;
			intelligence = rand() % 5 + 1; //1 to 5
			moral = rand() % 5 + 1; //1 to 5
			strength = 1;
		}
	}
	person(string g) //constructor with gender param
	{
		if (g == "Male")
		{
			gender = "Male";
			name = male_first.at(rand() % male_first.size()) + " " +
				   last.at(rand() % last.size());
			type = types.at(rand() % (types.size() - 1));
		}
		else
		{
			gender = "Female";
			name = female_first.at(rand() % female_first.size()) +
				   " " + last.at(rand() % last.size());
			type = types.at(rand() % (types.size() - 1) + 1);
		}
		if (g == "Female")
		{
			charisma = 1;
			intelligence = rand() % 5 + 1; //1 to 5
			moral = rand() % 5 + 1; //1 to 5
			strength = 5;
		}
		else if (type == "Sailor")
		{
			charisma = rand() % 5 + 1; //1 to 5
			intelligence = 5;
			moral = rand() % 5 + 1; //1 to 5
			strength = rand() % 5 + 1; //1 to 5
		}
		else if (type == "Seeker")
		{
			charisma = rand() % 5 + 1; //1 to 5
			intelligence = rand() % 2 + 4; //4 to 5
			moral = 5;
			strength = rand() % 5 + 1; //1 to 5
		}
		else if (type == "Babe")
		{
			charisma = 5;
			intelligence = rand() % 5 + 1; //1 to 5
			moral = rand() % 5 + 1; //1 to 5
			strength = 1;
		}
	}
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
	string get_name(person p) {return p.name;}
	string get_gender(person p) {return p.gender;}
	string get_type(person p) {return p.type;}
};

#endif