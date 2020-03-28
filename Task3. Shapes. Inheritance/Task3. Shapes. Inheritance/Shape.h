#pragma once
#include <iostream>
#include "pch.h"

/*abstract*/ class Shape abstract
{
public:
	Shape() 
	{ 
		std::cout << "Constructor shape\n"; 
	};
	/*virtual*/ ~Shape() 
	{
		std::cout << "Destructor shape\n\n"; 
	};
	
	friend std::istream& operator >> (std::istream& in, Shape& figure);
	virtual std::istream& input (std::istream& in) = 0;
	
	friend std::ostream& operator << (std::ostream& out, const Shape& figure);
	virtual std::ostream& print(std::ostream& out) const = 0;
	
	virtual double Square() = 0;

};



