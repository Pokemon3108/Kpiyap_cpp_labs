#pragma once
#include "TwoDShape.h"

class Triangle : public TwoDShape
{
private:
	double line;
public:
	Triangle() : line(0)
	{
		std::cout << "Constuctor triangle\n";
	};
	Triangle(double h, double a) : TwoDShape(h), line(a)
	{
		std::cout << "Constructor triangle\n";
	};
	Triangle(const Triangle& obj) : line(obj.line), TwoDShape(obj.h)
	{
		std::cout << "Constructor triangle\n";
	};

	~Triangle() 
	{ 
		std::cout << "Destructor triangle\n";
	};

	
	virtual std::istream& input(std::istream& in) override;
	virtual std::ostream& print(std::ostream& out) const override;
	
	virtual double Square() override;
};

