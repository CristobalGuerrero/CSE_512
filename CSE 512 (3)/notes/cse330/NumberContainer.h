// NumberContainer.h

#include <iostream>
#include <cassert>
using namespace std;

class NumberContainer
{
  public:

  NumberContainer()
  : size(0)
  { }

  void put(int x)
  {
    if  (size < 10)
    {
      data[size] = x;
      size++;
    }
    else
      cout << endl << "Array is full" << endl;
  }

  // get value at position i;
  int get(int i) const
  {
    assert(i >= 0 && i < size);
    return data[i];
  }

  int get_size() const
  {
    return size;
  }

  private:

  int size;   // number of elems stored in array;
  int data[10];
};
