#ifndef SELFORGANIZINGLIST_H_
#define SELFORGANIZINGLIST_H_

#include <iostream>
#include "List.h"
using namespace std;
template <class T>
class SelfOrganizingList : public List<T>
{
  public:

	typedef typename List<T>::iterator iterator;

	bool alt_include(T&, int&);
	void print() const;
};

template <class T>
bool SelfOrganizingList<T>::alt_include(T& value, int & comps)
{
	iterator itr = this->begin();
	iterator stop = this->end();

	comps = 0;
	while(itr != stop)
	{
		comps++;
		if(*itr == value)
		 {
		   this->insert(itr, value);
		   this->erase(itr);
		   //this->push_front(value);
		   return true;
		 }
		else
		  ++itr;
	}
      return false;
}

template <class T>
void SelfOrganizingList<T>::print() const
{
	iterator itr = this->begin();
	iterator stop = this->end();

	for(; itr != stop; ++itr)
	    cout << *itr << " ";
	cout << endl;
}

#endif
