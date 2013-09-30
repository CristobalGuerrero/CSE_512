// Implementation of set data structure after Timothy Budd,
// Data Structures in C++; modified by Kerstin Voigt so that
// each element can only occur once in the set; *no* multisets;
// this is more in the spirit of mathematical sets, and it 
// the implementation is somewhat simpler;

#ifndef SET_H_
#define SET_H_

#include "Node.h"
#include "InorderTreeTraversal.h" // for iterators
//#include "PreorderTreeTraversal.h"
//#include "PostorderTreeTraversal.h"
//using namespace std;


template <class T>
class Set
{
public:

	typedef InorderTreeTraversal<T> iterator;
	//typedef PreorderTreeTraversal<T> iterator;
	//typedef PostorderTreeTraversal<T> iterator;

	Set(void) : root(0), mySize(0) {}
	~Set(void) {delete root;}

	Set(const Set<T>&); // make deep copy;


	void insert(T&);
	void erase (T& x)
	{
		root = remove(root, x);
		mySize--;
	}

	// KV-modified to return 0 or 1;
	unsigned int count(T& x) const 
	{
		if (root == 0)
			return 0;
		else
			return root->count(x);
	}

	unsigned int size() const
	{
		/*
		if (root == 0)
			return 0;
		return root->size();
		*/
		return mySize;
	}

	bool empty() const {return root == 0;}

	bool include(T& x, int& comps) const
	{
		int subcomps = 0;
		if (root == 0)
			return false;
		bool result = root->include(x, subcomps);
		comps = subcomps;
		return result;
	}

	iterator begin() {return InorderTreeTraversal<T>(root);}
	iterator end(){return InorderTreeTraversal<T>(0);}

	void print() const; 

protected:
	Node<T>* remove(Node<T>*, T&);

	Node<T>* root;
	unsigned int mySize;
};



template <class T>
Set<T>::Set(const Set<T>& other)
: mySize(other.mySize)
{
	Node<T>* newroot = new Node<T>(*(other.root));
	root = newroot;
}

template <class T>
void Set<T>::insert(T& x)
{
	if (this->count(x) >= 1)
		return;

	Node<T>* newnode = new Node<T>(x); //0,0,0);

	if (root == 0)
		root = newnode;
	else
		root->insert(newnode);
	mySize++;
}

template <class T>
Node<T>* Set<T>::remove(Node<T>* current, T& x)
{
	if (current != 0)
	{
		
		if (x < current->value)
		{
			//cout << "Set::remove left(1) ..." << endl;
			// remove from left subtree;
			current->leftChild = remove(current->leftChild, x);
			return current;
		}
		else if (x > current->value)
		{
			//cout << "Set::remove right (2) ..." << endl;
			// remove from right subtree
			current->rightChild = remove(current->rightChild, x);
			return current;
		}
		else
		{
			//cout << "Set::remove here(3) ..." << endl;
			// case: current->value == x; remove here;
			// merge left and right subtrees and connect 
			// with parent of current;
			Node<T>* par = current->parent;
			Node<T>* result = current->merge(current->leftChild,
											 current->rightChild);
			//cout << "Set::remove, merged left and right" << endl;
			if (result != 0)
			{
				result->parent = par;
				//cout << "Set::remove, set parent" << endl;
			}
			//delete current;
			//result->parent = par;
			//cout << "Set::remove, returning result" << endl;

			// disconnect current and delete;
			current->parent = 0;
			current->leftChild = 0;
			current->rightChild = 0;
			delete current;
			return result;
		}
	}
	return current;
}

template <class T>
void Set<T>::print() const
{
	if (root == 0)
		return;
	root->print();
}


#endif








