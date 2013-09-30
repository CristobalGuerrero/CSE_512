#include <iostream>
#include "NumberContainer.h"
using namespace  std;


int main()
{
  NumberContainer mynums;

  int next;
  cin >> next;
  while (next != -1)
  {
    mynums.put(next);	
    cin >> next;
  }

  cout << endl << endl;
  for (int i = 0; i < mynums.get_size(); i++)
     cout << mynums.get(i) << " ";
  cout << endl << endl;

  return 0;
}

  
