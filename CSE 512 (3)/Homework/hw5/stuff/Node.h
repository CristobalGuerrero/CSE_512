#ifndef NODE_H_
#define NODE_H_

#include <iostream>

using namespace std;

template <class T> class Set;
template <class T> class InorderTreeTraversal;
//template <class T> class PreorderTreeTraversal;
//template <class T> class PostorderTreeTraversal;

template <class T>
class Node
{
public:
	
	Node(void) : parent(0), leftChild(0), rightChild(0) {}
	Node(T& x) : value(x), parent(0), leftChild(0), rightChild(0) {}
	Node(T& x, Node<T>* par, Node<T>* lch, Node<T>* rch)
		: value(x), parent(par), leftChild(lch), rightChild(rch) {}
	Node(const Node<T>&);

	~Node(void){}
	
	unsigned int count(T&) const; // KV-modified to return 0 or 1;
	unsigned int size() const;
	void insert(Node<T>*);
	Node<T>* merge(Node<T>*, Node<T>*);

	bool include(T&, int&);

	void print() const;

protected:

	friend class Set<T>;
	friend class InorderTreeTraversal<T>;
	//friend class PreorderTreeTraversal<T>;
	//friend class PostorderTreeTraversal<T>;

	T value;
	Node<T>* parent;
	Node<T>* leftChild;
	Node<T>* rightChild;
};


template <class T>
Node<T>::Node(const Node<T>& other)
: value(other.value)
{
	if (other.parent != 0)
	{
		Node<T>* newpar = new Node<T>(*(other.parent));
		parent = newpar;
	}
	if (other.leftChild != 0)
	{
		Node<T>* newleft = new Node<T>(*(other.leftChild));
		leftChild = newleft;
	}
	if (other.rightChild != 0)
	{
		Node<T>* newright = new Node<T>(*(other.rightChild));
		rightChild = newright;
	}
}

template <class T>
unsigned int Node<T>::size() const
{
	int count = 1; // count this node;

	if (leftChild != 0)
		count += leftChild->size();
	if (rightChild != 0)
		count += rightChild->size();
	
	return count;
}

// modified to return only 1 (as soon as x is found),
// or 0 when x is not in set;
template <class T>
unsigned int Node<T>::count(T& x) const
{
	//cout << "Node::count(1) ..." << endl;

	if (value == x)
		return 1;
	
	//cout << "Node::count (2) ..." << endl;

	if (leftChild == 0 && rightChild == 0)
		return 0;

	//cout << "Node::count (3) ..." << endl;
	if (leftChild == 0)
		return rightChild->count(x);
	if (rightChild == 0)
		return leftChild->count(x);
	return 0;
}

template <class T>
void Node<T>::insert(Node<T>* newnode)
{
	//cout << "Node::insert ..." << endl;
	if (newnode->value < value)
	{
		if (leftChild != 0)
			leftChild->insert(newnode);
		else
		{
			//newnode->parent = this;
			leftChild = newnode;
			leftChild->parent = this;
		}
	}
	else if (newnode->value > value)
	{
		if (rightChild != 0)
			rightChild->insert(newnode);
		else
		{
			//newnode->parent = this;
			rightChild = newnode;
			rightChild->parent = this;
		}
	}
	// will not insert newnode with value == value;
	return;
}

template <class T>
Node<T>* Node<T>::merge(Node<T>* left, Node<T>* right)
{
	if (left == 0)
		return right;
	if (right == 0)
		return left;

	Node<T>* child = merge(left, right->leftChild);
	
	child->parent = right;
	right->leftChild = child;
	return right; 
}

template <class T>
bool Node<T>::include(T& x, int& comps)
{
	comps = 1;
	if (value == x)
	{
		cout << "found it" << endl;
		return true; // with comps = 1;
	}
	
	if (leftChild == 0 && rightChild == 0)
	{
		cout << "not in set" << endl;
		return false; // with comps = 1;
	}

	if (x < value)
	{
		cout << "looking left ..." << endl;
		if (leftChild != 0)
		{
			int leftcomps = 0;
			bool result = leftChild->include(x,leftcomps);
			comps += leftcomps;
			return result;
		}
		else
		{
			cout << "not in set" << endl;
			return false; // with comps = 1, see above;
		}
	}

	if (x > value)
	{
		cout << "looking right ..." << endl;
		if (rightChild != 0)
		{
			int rightcomps = 0;
			bool result = rightChild->include(x,rightcomps);
			comps +=rightcomps;
			return result;
		}
		else
		{
			cout << "not in set" << endl;
			return false; // with comps = 1, see above;
		}
	}
}


template <class T>
void Node<T>::print() const
{
	if (leftChild == 0 && rightChild == 0)
	{
		cout << value << " ";
		return;
	}

	if (leftChild != 0)
		leftChild->print();
	cout << value << " ";
	if (rightChild != 0)
		rightChild->print();
}

#endif
