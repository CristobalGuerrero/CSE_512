#pragma once
#include <iostream>
#include <cassert>

using namespace std;

class FlexContainer
{
public:
	FlexContainer(void)
		:size(0), capacity(5)
	{
		numbers = new int[5];
	}

	FlexContainer(int cap)
		: size(0), capacity(cap)
	{
		numbers = new int[cap];
	}


	~FlexContainer(void)
	{
		delete [] numbers;
	}

	void put(int x)
	{
		if (size < capacity)
		{
			numbers[size] = x;
			size++;
		}
	}
	int get(int i) const
	{
		assert(i >= 0 && i < size);
		return numbers[i];
	}

	int get_size() const
	{
		return size;
	}

	int get_capacity() const
	{
		return capacity;
	}

	void print() const
	{
		cout << endl;
		if (size == 0)
			cout << "FlexContainer is empty!" << endl;
		else
		{
			for (int i = 0; i < size; i++)
				cout << numbers[i] << " ";
			cout << endl;
		}
	}

private:

	int size;
	int capacity;
	int* numbers;
};


