#pragma once
#include "TwoDShape.h"


class Circle : public TwoDShape
{
public:
	Circle()
	{
		std::cout << "Constructor circle\n";
	};
	Circle(double radius) : TwoDShape(radius)
	{
		std::cout << "Constructor circle\n";
	};
	Circle(const Circle& obj) : TwoDShape(obj.h)
	{
		std::cout << "Constructor circle\n";
	};

	~Circle() 
	{
		std::cout << "Destructor circle\n";
	};
	
	
	virtual std::istream& input(std::istream& in) override;
	virtual std::ostream& print(std::ostream& out)const override;
	
	virtual double Square() override;
};

