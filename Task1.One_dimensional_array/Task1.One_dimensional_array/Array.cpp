#include "pch.h"
#include "Array.h"
#include <time.h>


void Array::randomInput()
{

	srand(time(NULL));

	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 20;
		std::cout << std::setw(5) << array[i];
	}

}

void Array::goThroughArray(Array& newarray)
{
	int i, j;
	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < newarray.size; ++j)
			if (newarray[j] == array[i]) break;

		if (j == newarray.size) newarray[newarray.size++] = array[i];
	}
}

std::ostream & operator<<(std::ostream & s, Array & obj)
{
	
	for (int i = 0; i < obj.size; ++i)
		s << std::setw(4) << obj[i];
	return s;
}

std::istream & operator>>(std::istream & s, Array & obj)
{
	int size;
	s >> size;
	obj.size = size;
	obj.array = new int[size];
	
	for (int i = 0; i < size; ++i)
		s >> obj[i];
	
	return s;

}

int & Array::operator[](int n)
{
	return array[n];
}

Array Array::operator+(Array array2)
{
	int newsize = array2.size + size;
	Array temp(newsize);
	temp.size = 0;
	this->goThroughArray(temp);
	array2.goThroughArray(temp);
	return temp;
}

Array Array::operator% (Array array2)
{
	int lengthOfArray1 = size, lengthOfArray2 = array2.size, newsize = 0;
	int n = (lengthOfArray1 > lengthOfArray2) ? lengthOfArray1 : lengthOfArray2;
	Array temp(n);
	for (int i = 0; i < lengthOfArray1; ++i)
	{
		int j = 0, k = 0;
		while (array[i] != array2[j] && j < lengthOfArray2) ++j;
		while (temp[k] != array[i] && k < newsize) ++k;
		if (j != lengthOfArray2 && k == newsize) temp[newsize++] = array[i];
	}
	temp.size = newsize;
	return temp;
}

Array& Array::operator=(Array obj)
{
	delete[]array;
	size = obj.size;
	array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = obj[i];
	return *this;
}

