Cristobal Guerrero,Starship/Leingod,Starship,05.10.2011 11:17,file:///C:/Users/Leingod/AppData/Roaming/OpenOffice.org/3;                                                                                                                                                                                                                                                                                                                                                                                                        	T& back() const;
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
void List<T>::push_front(c