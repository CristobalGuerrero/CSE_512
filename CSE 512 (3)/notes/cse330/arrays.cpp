#include <iostream>
using namespace std;

int main()
{
  int nums[10];
  int i = 0;
  int next = 0;

  while (next != -1)
  {
    cin >> next;
    nums[i] =next;
    i++;
   }
   
   cout << endl << endl;
   for (int j = 0; j < i; j++)
      cout << nums[j] << " ";
    
    cout << endl << endl;
    return 0;
   }
