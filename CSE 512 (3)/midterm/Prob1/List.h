// linked list; Kerstin Voigt, October 2011
// after Timothy Budd, Data Structures in C++

//#pragma once
#ifndef LIST_H_
#define LIST_H_

#include <algorithm>
using namespace std;

// forward declaration of classes used
// by class List

template <class T> class Link;
template <class T> class ListIterator;

template <class T>
class List
{
public:

	typedef ListIterator<T> iterator;

	List();
	List(const List<T>& l);
	~List();

	bool empty() const;
	unsigned int size() const;

	T& back() const;
	T& front() const;
	void push_front(const T & x);
	void push_back(const T & x);
	void pop_front();
	void pop_back(); 

	iterator begin() const;
	iterator end() const;
	void insert(iterator pos, const T & x);
	void erase(iterator pos);

	List<T>& operator =(const List<T> & l);

protected:

	Link<T> * firstLink;
	Link<T> * lastLink;

	unsigned int mySize; // not in Timothy Budd;
};

// helper class for class List; notice the
// private interface and data members;
// notice the friend declaration that allow
// class List to access class Link's data 
// members directly;
template <class T>
class Link
{
private:
	Link(const T & x)
		: value(x), nextLink(0), prevLink(0)
	{}

	Link(const Link<T>& other)
		:value (other.value)
	{
		nextLink = other.nextLink;
		prevLink = other.prevLink;
	}

	~Link();

	T value;
	Link<T>* nextLink;
	Link<T>* prevLink;

	friend class List<T>;
	friend class ListIterator<T>;
};

// implements a "sliding window" over the
// Links of a List;
template <class T>
class ListIterator
{
public:
  typedef typename List<T>::iterator iterator;

	ListIterator() : currentLink(0)
	{}
	ListIterator(Link<T> * alink)
	{
		currentLink = alink;
	}
	ListIterator(const ListIterator<T>& other)
	{
		currentLink = other.currentLink;
	}

	T & operator*();
	ListIterator<T> & operator=(const ListIterator<T> & rhs);
	bool operator==(const iterator & rhs) const;
	bool operator!=(const iterator & rhs) const;
	// T. Budd has the ++ and -- operators backwards
	// regarding pre- and post-increment;
	ListIterator<T>& operator++(); // pre-increment; ++itr
	ListIterator<T> operator++(int); // post-increment; itr++
	ListIterator<T>& operator--(); // pre-decrement; ++itr
	ListIterator<T> operator--(int); // post-decrement; itr++

protected:
	Link<T> * currentLink; 
    // T.Budd includes pointer to List iterated over;
	// this is not necessary;

	friend class List<T>;
};


// constructors and member functions of class List<T>

template <class T>
List<T>::List()
: firstLink(0), lastLink(0), mySize(0)
{}

// copy constructor; T. Budd does not have it, but
// it is important for the compilation of our programs;
template <class T>
List<T>::List(const List<T>& other)
{
	firstLink = 0;
	lastLink = 0;
	mySize = 0;

	if (!other.empty())
	{
		iterator start = other.begin();
		iterator stop = other.end();

		firstLink = new Link<T>(*start);
		Link<T>* current = firstLink;
		++start;
		mySize++;

		while (start != stop)
		{
			T value = *start;
			Link<T>* newlink = new Link<T>(value);
			newlink->prevLink = current;
			current->nextLink = newlink;
			
			current = newlink;
			++start;
			mySize++;
			
		}
		lastLink = current;
	}
}

// destructor; absolutely necessary to avoid
// memory leaks;
template <class T>
List<T>::~List()
{
	Link<T>* first = firstLink;
	while (first != 0)
	{
		Link<T> * next = first->nextLink;

		first->nextLink = 0; // unhook Link<T> first
		first->prevLink = 0; // then delete
		delete first;
		
		first = next;
	}
}

// LAB 5
// add ::empty() and :: size()

template <class T>
bool List<T>::empty() const
{
	return firstLink == 0;
}

template <class T>
unsigned int List<T>::size() const
{
	return mySize;
}

template <class T>
T& List<T>::back() const
{
	return lastLink->value;
}

// LAB 5
// add ::front()

template <class T>
T& List<T>::front() const
{
	return firstLink->value;
}

template <class T>
void List<T>::push_front(const T & x)
{
	Link<T>* newfront = new Link<T>(x);

	if (empty())
	{
		firstLink = newfront;
		lastLink = newfront;
	}
	else
	{
		(firstLink->prevLink) = newfront;
		(newfront->nextLink) = firstLink;
		firstLink = newfront;
	}
	mySize++;
}

// Lab 5
// add :: push_back

template <class T>
void List<T>::push_back(const T & x)
{
	Link<T> * newback = new Link<T>(x);

	if (empty())
	{
		firstLink = newback;
		lastLink = newback;
	}
	else
	{
		lastLink->nextLink = newback;
		newback->prevLink = lastLink;
		lastLink = newback;
	}
	mySize++;
}

template <class T>
void List<T>::pop_front()
{
	if (firstLink == 0)
		return;

	Link<T>* save = firstLink;

	firstLink = firstLink->nextLink;

	if (firstLink != 0)
		firstLink->prevLink = 0;
	else
		lastLink = 0;
	
	save->nextLink = 0;
	delete save;

	mySize--;
}

// LAB 5:
// add pop_back

template <class T>
void List<T>::pop_back()
{
	if (firstLink == 0)
		return;

	Link<T>* save = lastLink;

	lastLink = lastLink->prevLink;
	
	if (lastLink != 0)
		lastLink->nextLink = 0;
	else
		firstLink = 0;

	save->prevLink = 0;
	delete save;

	mySize--;
}

template <class T>
ListIterator<T> List<T>::begin() const
{
	return ListIterator<T>(firstLink);
}

template <class T>
ListIterator<T> List<T>::end() const
{
	return ListIterator<T>(0);
}

// Lab 5
// fill in missing code;

template <class T>
void List<T>::insert(iterator pos, const T& x)
{
	if (pos == begin())
	{
		push_front(x);
	}
	else if (pos == end())
	{
		push_back(x);
	}
	else if (pos.currentLink == 0)
		;
	else
	{
		// the Link currently at pos;
		Link<T> * atpos = pos.currentLink;

		// create a  new Link with value x;
		Link<T> * newlink = new Link<T>(x);

		// attache newlink to its left neighbor;
		(atpos->prevLink)->nextLink = newlink;
		newlink->prevLink = atpos->prevLink;
		//attach newlink to its right neighbor;
		newlink->nextLink = atpos;
		atpos->prevLink = newlink;
	}
	mySize++;
}

// Lab5:
// fill in missing code
template <class T>
void List<T>::erase(iterator pos)
{
	if (pos == begin())
	{
		pop_front();
	}
	else if (pos == end())
	{
		pop_back();
	}
	else if (pos.currentLink == 0)
	{
		//cout << " ... nothing to erase" << endl;
		;
	}
	else
	{
		Link<T> * torem = pos.currentLink;
		// reroute nextLink and prevLink pointers
		// so that Link as pos is bridged over;

		(torem->prevLink)->nextLink = torem->nextLink;

		if (torem->nextLink != 0)
		{
			torem->nextLink->prevLink = torem->prevLink;
		}
		else
			lastLink = torem->prevLink;

		torem->nextLink = 0;
		torem->prevLink = 0;
		delete torem;

		mySize--;
	}	
}

template <class T>
List<T> & List<T>::operator=(const List<T> & other)
{
	firstLink = 0;
	lastLink = 0;

	copy(other.begin(), other.end(), begin());

	mySize = other.mySize;
	return *this;
}


// member functions of class List<T>

template <class T>
Link<T>::~Link()
{
	if (nextLink != 0)
		delete nextLink;
	if (prevLink != 0)
		delete prevLink;
}

// member functions of class ListIterator<T>

template <class T>
T& ListIterator<T>::operator*()
{
	return currentLink->value;
}

template <class T>
ListIterator<T> & ListIterator<T>::operator=(const ListIterator<T> & rhs)
{
	currentLink = rhs.currentLink;
	return *this;
}

template <class T>
//bool ListIterator<T>::operator==(const ListIterator<T> & rhs) const
bool ListIterator<T>::operator==(const iterator & rhs) const
{
	return currentLink == rhs.currentLink;
}

template <class T>
bool ListIterator<T>::operator!=(const iterator & rhs) const
{
	return currentLink != rhs.currentLink;
}

// ++itr ; returns iterator after being advanced; 
template <class T>
//ListIterator<T>&  ListIterator<T>::operator++()
ListIterator<T>&  ListIterator<T>::operator++()
{
	currentLink = currentLink->nextLink;
	return *this;
}
// itr++; returns a clone of the current iterator;
// then advances;
template <class T>
ListIterator<T> ListIterator<T>::operator++(int)
{
	ListIterator<T> clone(currentLink);
	currentLink = currentLink->nextLink;
	return clone;
}

// --itr ; returns iterator after being advanced; 
template <class T>
ListIterator<T>&  ListIterator<T>::operator--()
{
	currentLink = currentLink->prevLink;
	return *this;
}
// itr--; returns a clone of the current iterator;
// then advances;
template <class T>
ListIterator<T> ListIterator<T>::operator--(int)
{
	ListIterator<T> clone(currentLink);
	currentLink = currentLink->prevLink;
	return clone;
}

#endif









