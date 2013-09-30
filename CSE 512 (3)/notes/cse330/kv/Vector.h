#pragma once

//#include <iostream>
#include <cassert>

using namespace std;

template <class T> 
class vector
{
public:

   typedef T * iterator;
   typedef T value_type;

  // constructors:

  vector() 
	  : buffer(0), mySize(0), myCapacity(0)
  {}

  vector(unsigned int size)
	  : buffer(0)
  {	 
      reserve(size);
  }

  vector(unsigned int size, T initial)
	  : buffer(0)
    {
      resize(size, initial);
    }
  
  vector(vector& v)
	  : buffer(0)
    {
      reserve(v.myCapacity);
      vcopy(v.begin(), v.end(), begin());
      mySize = v.mySize;
    }

  // destructor:
	
  ~vector() { delete [] buffer; }  

  // member functions:

  T& back() const { return buffer[mySize - 1]; }	

  T& front() const { return buffer[0];}

  iterator begin() { return buffer;}

  int capacity() { return myCapacity;}

  bool empty() { return mySize == 0;}

  iterator end() { return begin() + mySize;}

  void pop_back() {mySize--;}

  void push_back(T);  

  void reserve(unsigned int); 

  void resize(unsigned int, T);

  int  size() { return mySize;}

  T& operator [ ](unsigned int index)
    {
      return buffer[index];
    }

  /*  ... do these later ...
  void insert(iterator, T);
  void swap(vector<T>&);   
  void erase(iterator);
  void erase(iterator, iterator);
  */

 protected:

  unsigned int mySize;
  unsigned int myCapacity;

  T * buffer;

};




// MEMBER FUNCTIONS


// reserves space of size newCap if necessary; copies current
// values back into newly allocated space;

template<class T>
void vector<T>::reserve(unsigned int newCap)
// this is a comment
{
	 if (buffer == 0) {
		 mySize = 0;
		myCapacity = 0;
	 }

	if (newCap <= myCapacity) 
		 return;

	T * newBuffer = new T[newCap];
	assert(newBuffer);
	
	vcopy(buffer, buffer + mySize, newBuffer);

	myCapacity = newCap;

	delete [] buffer;

	buffer = newBuffer;
}

// resizes the array and pads all positions with a default value;

template <class T>
void vector<T>::resize(unsigned int newSize, T pad_value)
{
  reserve(newSize);
  vfill(buffer, buffer + newSize, pad_value);
  mySize = newSize;
}
	
// adds a value to the end and increases capacity by 5 if the space
// is tight;

template <class T>
void vector<T>::push_back(T value)
{
 if (mySize >= myCapacity)
     reserve(myCapacity + 5);
 
  buffer[mySize++] = value; 	
}

/*

template <class T>
void vector<T>::show()
{
  if (empty())
    {
      cout << " EMPTY" << endl;
      return;
    }

  T* curr = buffer;

  while (curr != buffer + mySize)
    {
      //cout << endl << *curr;
      cout << *curr << " ";
      curr++;
    }
  cout << endl;
}
*/

// the following 4 member functions are subject project 1:

// inserts new element x into position referenced by iterator itr;
// refuses to insert at 100% capacity;
/*
template <class T>
void vector<T>::insert(iterator itr, T x)
{
  assert(mySize < myCapacity);
  assert(itr >= begin());
  assert(itr < end());

  iterator ptr = end();

  while (ptr > itr)
    {
      *ptr = *(ptr - 1);
      ptr--;
    }
  *itr = x;
  mySize++;
}

template <class T>
void vector<T>::erase(iterator itr)
{
  assert(itr >= begin() && itr < end());

  if (itr == 0)
    return;
  if (itr == end() - 1)
    {
      pop_back();
      return;
    }
  
  while(itr < end())
    {
      *itr = *(itr  + 1);
      itr++;
    }
  mySize--;
}

template <class T>
void vector<T>::erase(iterator start, iterator stop)
{
  assert(stop >= start && 
	 start >= begin() && start < end() &&
	 stop >= begin() && stop < end());

  int newSize = mySize - (stop - start);

  if (stop == start)
    {
      erase(start);
      return;
    }

  //iterator rest = stop + 1;
  iterator rest = stop;
  while (rest < end())
    {
      *start = *rest;
      start++;
      rest++;
    }

  mySize = newSize;
}

template <class T>
void vector<T>::swap(vector<T>& vec)
{
  T temp;
  int size1 = mySize;
  int size2 = vec.mySize;

  if (myCapacity > vec.myCapacity)
    vec.reserve(myCapacity);
  else if (myCapacity < vec.myCapacity)
    reserve(vec.myCapacity);

  iterator itr1 = begin();
  iterator itr2 = vec.begin();
  
  while (itr1 < end() && itr2 < vec.end())
    {
      temp = *itr1;
      *itr1 = *itr2;
      *itr2 = temp;

      itr1++;
      itr2++;
    }

  if (itr1 >= end() && itr2 >= vec.end())
    return;
  else if (itr1 >= end()) // vec is larger ... copy rest to "this"
    copy(itr2, vec.end(), itr1);
  else
    copy(itr1, end(), itr2); // "this" is larger ... copy rest to vec

  mySize = size2;
  vec.mySize = size1;
}
*/

// GENERIC ALGORITHMS vfill and vcopy (should really just  be fill and copy);

template <class ItrType, class T>
void vfill(ItrType current, ItrType stop, T value)
{
 while (current != stop) {
      *current = value;
      current++;
      }
}


template <class SourceItrType, class DestItrType>
int vcopy(SourceItrType current, 
          SourceItrType stop,
          DestItrType dest)
{
  int count = 0;
  while(current != stop)
    {
      *dest++ = *current++;
      count++;
    }
  return count;
}
