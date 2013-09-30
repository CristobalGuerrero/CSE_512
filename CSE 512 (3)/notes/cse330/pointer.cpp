// pointer.cpp

#include <iostream>
using namespace std;

int main()
{
  int x;
  int* p;

  cout << "Integer: ";
  cin >> x;

  p = &x;

 cout << endl << endl;
 cout << "x: " << x << endl;
 cout << "pointed to by p: " << *p << endl;
 cout << endl << endl;

 return 0;
}
