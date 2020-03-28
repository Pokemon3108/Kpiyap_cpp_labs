#pragma once
#include "Shape.h"

class TwoDShape abstract: public Shape
{
protected:
	double h;
public:
	TwoDShape() : h(0)
	{
		std::cout << "Constructor  2DShape\n";
	};
	TwoDShape(double height) : h(height)
	{
		std::cout << "Constructor  2DShape\n";
	};
	TwoDShape(const TwoDShape& obj) : h(obj.h)
	{
		std::cout << "Constructor  2DShape\n";
	};

	
	/*virtual*/ ~TwoDShape()
	{
		std::cout << "Destructor 2d\n";
	}

	virtual std::istream& input(std::istream& in) override = 0;
	virtual std::ostream& print(std::ostream& out) const override = 0;

	virtual double Square() = 0;
};

