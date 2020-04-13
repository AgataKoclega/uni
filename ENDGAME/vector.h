#pragma once
#include <iostream>
#include "bluebodies.h"

using namespace std;

//my own implementation of vector
template <class T>
class myvector
{
private:
	//available number of stored items
	int possible_size_of_stored_items;
	//used size of array
	int used_sarray;
	T *arr;
public:
	myvector()
	{
		//at the beginning  the array has size 10
		possible_size_of_stored_items = 10;
		arr = new T[possible_size_of_stored_items];
		used_sarray = 0;
	}

	~myvector()
	{
		delete[] arr;
	}

	T operator[](int i)
	{
		//return the i'th value in the array
		if (i >= 0 && i < possible_size_of_stored_items)
			return arr[i];
		else
		{
			//if the error will occured
			cout << "vector out of bounds\n";
			return T();
		}
	}

	void push(T &element)	//This adds a new element to a vector
	{
		//if we still have some available place in our array
		if (used_sarray < possible_size_of_stored_items)
		{
			//then just use it
			arr[used_sarray] = element;
			used_sarray++;
		}
		//if not
		else
		{
			//Now we are creating a  bigger array
			T *arr2 = new T[possible_size_of_stored_items * 2];
			//We have to copy all content from previous array to a new one
			for (int i = 0; i < possible_size_of_stored_items; i++)
				arr2[i] = arr[i];
			//then destroy an old array
			delete[] arr;
			//hold pointer to a new array
			arr = arr2;
			//only then add new item
			arr[used_sarray] = element;
			used_sarray++;
		}
	}
	// and now return the number of stored items
	int size()
	{
		return used_sarray;
	}
};