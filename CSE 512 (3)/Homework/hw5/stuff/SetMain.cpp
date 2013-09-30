#include "Set.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// generates a random number between 1 and K;
int random_1toK(int k)
{
	int rno = 1 + rand() % k;
	return rno;
}

int main()
{
	Set<int> myset;
	int how_many;

	cout << endl << "Enter a seed integer: ";
	int seed;
	cin >> seed;
	srand(seed);
	cout << endl << endl;
	cout << endl << "How many elements in your set? ";
	cin >> how_many;
	cout << endl << endl;
	assert(how_many >= 0);

	for (int i = 1; i <= how_many; i++)
	{
		int next = random_1toK(3 * how_many);
		myset.insert(next);
	}

	//myset.print();

	// user iterators to print;
	Set<int>::iterator itr = myset.begin();
	Set<int>::iterator stop = myset.end();

	while (itr != stop)
	{
		cout << *itr << " ";
		++itr;
	}
	cout << endl << endl;

	/*
	int sum_of_comps = 0;
	for (int i = 1; i <= how_many; i++)
	{
		int mycomps = 0;
		int nextfind = random_1toK(3 * how_many);
		cout << "trying to find " << nextfind << endl;
		myset.include(nextfind, mycomps);

		sum_of_comps += mycomps;
	}

	cout << how_many << "inclusion tests took " 
		 << sum_of_comps/(double)how_many << " comparisons on the average" 
		 << endl << endl;
	*/

	return 0;
}






/*
int main()
{
	Set<int> myset;

	int next;
	for (int i = 1; i <= 10; i++)
	{
		cout << endl;
		cout << "Integer: "; 
		cin >> next;
		myset.insert(next);
	}

	cout << endl << endl;
	cout << "Values read into set";
	cout << endl << endl;
	myset.print();
	cout << endl << endl;

	cout << "Enter a value to find: ";
	cin >>  next;
	cout << endl;

	if (myset.include(next))
		cout << "Value found :-)";
	else
		cout << "Value not found :-(";
	cout << endl << endl;
	
	cout << "Enter three values to remove ...";
	for (int i = 1; i <= 3; i++)
	{
		cout << endl;
		cout << "Remove: ";
		cin >> next;
		myset.erase(next);
		myset.print();
	}
	cout << endl << endl;
	cout << "Here are the values again:" << endl;

	InorderTreeTraversal<int> itr = myset.begin();
	InorderTreeTraversal<int> stop = myset.end();

	for (; itr != stop; ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl << endl;

	Set<int> myset2;
	
	for (int i = 1; i <= 5; i++)
	{
		cout << endl;
		cout << "Integer: "; 
		cin >> next;
		myset2.insert(next);
	}
	cout << endl << endl;

	Set<int> myset3;

	for (int i = 1; i <= myset.size() + myset2.size(); i++)
	{
		cout << endl;
		cout << "Integer: "; 
		cin >> next;
		myset3.insert(next);
	}

	Set<int>::iterator dest = myset3.begin();
	myset.begin();
	myset.end();
	myset2.begin();
	myset2.end();

	cout << "before set_union" << endl;

	set_union(myset.begin(), myset.end(), myset2.begin(), myset2.end(), dest);

	myset3.print();

	return 0;
}
*/


