#include <iostream>
#include "Vector.h"

using namespace std;

void show(vector<int> v)
{
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> myvec(10,3);

	show(myvec);

	for (int i = 1; i <= 5; i++)
		myvec.push_back(5);

	show(myvec);
	int oldsize = myvec.size();

	myvec.resize(25,0);
	
	for (int i = oldsize; i <= oldsize+3; i++)
		myvec[i] = 7;

	show(myvec);

	return 0;
}
