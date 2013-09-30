#include <iostream>
#include "Vector.h"
#include <cassert>

using namespace std;

// print out chars in Vector separated by enclosed by '-';
void show(const Vector<char>& v)
{
	
	cout << endl << "-";
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "-";
	cout << endl;
}


// bracelet:  $$-o-$$-o-$$-o-$$
//            X-oo-X-oo-X-oo-X
//            #*#-oo-#*#-oo-#*#-oo-#*#
// erase a bead, replace a bead, repeat a bead; do same with each occurrence

bool is_bead(char x)
{
	return (x == '!' || x == '@' || x == '#' || x == '$' || x == '%' ||
		    x == '&' || x == '*' || x == '+' || x == 'o');
}

int main()
{
	Vector<char> bracelet;
    char bead;

	cout << endl;
	cout << "Type the beads of your starter bracelet, finish q to quit";
	cout << endl;
	cin >> bead;
	while (is_bead(bead))
	{
		bracelet.push_back(bead);
		cin >> bead;
	}

	cout << endl << endl;
	cout << "This is your starter bracelet:" << endl;
	show(bracelet);

	bool done = false;
	int select; 
	int no_mods = 0;

	while (!done && !bracelet.empty())
	{
		cout << endl;
		if (no_mods == 0)
			cout << "What would you like to do with your bracelet?" << endl << endl;
		else
			cout << "What else would you like to do?" << endl << endl;

		cout << "[1] Keep as is -- it's way cool" << endl;
		cout << "[2] Take out a type of bead -- it's ruins the look" << endl;
		cout << "[3] Replace a type of bead -- just playing around" << endl;
		cout << "[4] Double up a type of bead -- it needs more punch" << endl << endl;
		cout << "Choose 1-4: ";
		cin >> select;
		cout << endl;

		if (select == 1)
		{
			cout << endl << "Well, here it is ... totally YOU! ";
			show(bracelet);
			done = true;
		}
		else if (select == 2)
		{
			char bead;
			cout << "Type bead to take out: ";
			cin >> bead;

			assert(is_bead(bead));

			for (int i = 0; i < bracelet.size(); i++)
			{
				if (bracelet[i] == bead)
				{
					bracelet.erase(i);
					i--; // explain!
				}
			}

			cout << endl;
			cout << "This is what it looks like now ... " << endl;
			show(bracelet);
		}
		else if (select == 3)
		{
			char bead1, bead2;
			cout << "Type old bead followed by new bead: ";
			cin >> bead1 >> bead2;

			assert(is_bead(bead1) && is_bead(bead2));

			for (int i = 0; i < bracelet.size(); i++)
			{
				if (bracelet[i] == bead1)
					bracelet[i] = bead2;
			}

			cout << endl;
			cout << "This is what it looks like now ... " << endl;
			show(bracelet);
		}
		else if (select == 4)
		{
			char bead;
			cout << "Type bead to double: ";
			cin >> bead;

			assert(is_bead(bead));

			for (int i = 0; i < bracelet.size(); i++)
			{
				if (bracelet[i] == bead)
				{
					bracelet.insert(i, bead);
					show(bracelet);
					i = i + 2; // explain!
				}
			}

			cout << endl;
			cout << "This is what it looks like now ... " << endl;
			show(bracelet);
		}
		else
		{
			cout << endl;
			cout << "You need to choose from options 1-4";
		}
		
		if (no_mods == 0)
			no_mods++;
	}
	return 0;
}

