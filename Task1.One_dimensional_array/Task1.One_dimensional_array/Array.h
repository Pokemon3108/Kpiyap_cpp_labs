#pragma once
#include "pch.h"

class Array {
private:
	int* array;
	int size;

public:
	Array() : size(0), array(nullptr)
	{ }

	Array(int n) : size(n)
	{
		array = new int[size];
	}

	Array(const Array& obj) : size(obj.size)
	{
		
		array = new int[size];
		for (int i = 0; i < size; ++i)
			array[i] = obj.array[i];
	}

	~Array()
	{
		delete[] array;
	}

	void randomInput();
	void goThroughArray(Array& newarray);

	int& operator[](int n);
	Array operator+ (Array array2);
	Array operator% (Array array2);
	Array& operator= (Array obj);

	friend std::ostream& operator <<(std::ostream&s, Array&obj);
	friend std::istream& operator >>(std::istream&s, Array&obj);
};

