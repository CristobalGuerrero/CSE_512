#ifndef INORDER_H_
#define INORDER_H_

#include "Node.h"
//using namespace std;

template <class T> class Node;

template <class T>
class InorderTreeTraversal
{
public:
	typedef InorderTreeTraversal<T> iterator;

	InorderTreeTraversal() : current(0){}
	InorderTreeTraversal(Node<T>*);
	InorderTreeTraversal(const InorderTreeTraversal<T>& other)
		: current(other.current) {}

	~InorderTreeTraversal(void) {delete current;}

	T& operator *();
	void operator =(const iterator& other)
	{
		current = current.other;
	}
	bool operator ==(const iterator& other)
	{
		return current == other.current;
	}
	bool operator != (const iterator& other)
	{
		return current != other.current;
	}

	iterator& operator ++(); // preinc
	iterator operator ++(int); // postinc;

protected:
	
	friend class Node<T>;

	Node<T>* current;
};

template <class T> 
InorderTreeTraversal<T>::InorderTreeTraversal(Node<T>* root)
{
	current = root;
	while (current && current->leftChild)
		current = current->leftChild;
}

template <class T>
T& InorderTreeTraversal<T>::operator *()
{
	return current->value;
}

template <class T>
InorderTreeTraversal<T>& InorderTreeTraversal<T>::operator ++()
{
	if (current->rightChild != 0)
	{
		current = current->rightChild;
		while(current->leftChild != 0)
			current = current->leftChild;
	}
	else
	{
		Node<T>* child = current;
		current = current->parent;
		while (current && current->rightChild == child)
		{
			child = current;
			current = current->parent;
		}
	}
	return *this;
}

template <class T>
InorderTreeTraversal<T> InorderTreeTraversal<T>::operator ++(int)
{
	InorderTreeTraversal<T> clone(*this);
	operator ++();
	return clone;
}

#endif
