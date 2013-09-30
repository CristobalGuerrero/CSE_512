// VectorMain.cpp
#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
Vector<int> v1(5);
int next;
for (int i = 0; i < 5; i++)
{

cout << "Integer: ";
cin >> next;
v1.push_back(next);
cout << endl;
}
cout << endl << "v1: ";
for (int i = 0; i < v1.size(); i++)
{
cout << v1[i] << " ";
}
cout << endl;
if (v1.size() >= v1.capacity())
cout << "The vector is full" << endl;
else
cout << "The vector has capacity left" << endl;
for (int i = 1; i <= 3; i++)
{
cout << endl << "Integer: ";
cin >> next;
v1.push_back(next);
}
cout << endl;
cout << "Vector with additional elements:" << endl;
cout << endl << "v1: ";
for (int i = 0; i < v1.size(); i++)
{
cout << v1[i] << " ";
}
cout << endl;
return 0;
}

