#include <iostream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;

int main()
{
  PriorityQueue<int> myq;

  // enter several values into myq;
  
  cout << endl;
  cout << "How many values? ";
  int k;
  cin >> k;

  for (int i = 1; i <= k; i++)
    {
      int next;
      // produce a next value
      cout << "Integer: ";
      cin >> next;
      cout << endl;
      // enter it into myq;

      myq.push(next);

    }
  
  // print out the contents of myq;
  // PriortyQueue has a function for this ...
  myq.print_tree();

  myq.pop();

  cout << endl << endl;
  myq.print_tree();

  return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                  e;
}




