// Vector.h

#ifndef VECTOR_H
#define VECTOR_H
#include <cstdlib>
#include <cctype>
#include <iostream>
using namespace std;

template <class T>
class Vector
  {
	public:
	  //typedef T * iterator;
	  //my_size=size should be replaced by resize(size)
	  Vector() { buffer = 0; my_size = 0;}
	  //my_size=size should be replaced by resize(size)
	  Vector(unsigned int size) { buffer = 0; my_size = size; my_capacity = 0;} 
	  //Vector(unsigned int size, const T & initial);
	  //Vector(const Vector<T> & v); // copy constructor
	  ~Vector() { delete [] buffer; }
	
	  unsigned int capacity() const { return my_capacity; } // capacity of vector (in elements)
	  unsigned int size() const { return my_size; } // the number of elements in the vector
	  bool empty() const { return (my_size==0); }
	  
	  //iterator begin() { return buffer; }// return iterator pointing to first elem
	  //iterator end() { return begin()+my_size; } // iterator pointing to one past last elem
	  T & front() { return buffer[0]; } // reference to the first element
	  T & back() { return buffer[my_size-1]; } // reference to the last element
	  void push_back(const T & value); // add a new element
	  void pop_back() { my_size--; } // remove the last element
	  
	  void insert(unsigned int i, T x);
	  
	  //void reserve(unsigned int capacity); // adjust capacity
	  //void resize(unsigned int size); // adjust size reserve(newSize);
	  
	  T & operator[](unsigned int index){ return buffer[index]; } 
	  // return reference to numbered element
	  //Vector<T> & operator=(const Vector<T> &);
	
	private:
	  unsigned int my_size;
	  unsigned int my_capacity;
	  T * buffer;
  };

template <class T>
void Vector<T>::push_back(const T & value){
 if (my_size < my_capacity){
	cout << "... plain push_back ..." << endl;
	buffer[my_size] = value;
	my_size++;
 }
 else{
	cout << "... push_back with resize ..." << endl;
	T* newbuf = new T [my_capacity + 5];
	copy(buffer, buffer+my_size, newbuf);
	delete [] buffer;
	buffer = newbuf;
	buffer[my_size] = value;
	my_size++;
	my_capacity += 5;
 }
}



//one of the default constructors
//template <class T> 
//Vector<T>::Vector(unsigned int size, const T & initial){
//	buffer = 0;
//	resize(size);
//	fill (begin(), end(), initial);
//}

//copy constructor
//template <class T> 
//Vector<T>::Vector(const Vector<T> & v){
//	buffer = 0;
//	resize(v.length());
//	copy(v.begin(), v.end(), begin());
//}

//this function reserves memory from the heap for the program
//template <class T> 
//void Vector<T>::reserve(unsigned int capacity){ 
//	if(buffer==0){
//	  my_size=0;
//	  my_capacity=0;
//	}
//	if(capacity<=my_capacity){
//	  return;
//	T * newBuffer = new T[capacity];
//	assert(newBuffer);
//	}
//	copy(buffer, buffer + my_size, newBuffer);
//	
//	my_capacity = capacity;
//	
//	delete [] buffer;
//	buffer = newBuffer;
//}
	
	
  
#endif
