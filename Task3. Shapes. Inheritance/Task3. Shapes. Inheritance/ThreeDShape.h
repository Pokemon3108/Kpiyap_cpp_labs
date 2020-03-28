#pragma once
#include "Shape.h"


class ThreeDShape abstract : public Shape
{
protected:
	double h;
public:
	ThreeDShape() : h(0)
	{
		std::cout<<"Constructor 3DShape\n";
	};

	ThreeDShape(double height) : h(height)
	{
		std::cout << "Constructor 3DShape\n";
	};
	ThreeDShape(const ThreeDShape& obj) : h(obj.h)
	{
		std::cout << "Constructor 3DShape\n";
	};

	virtual ~ThreeDShape()
	{
		std::cout << "Destructor 3DShape\n";
	};

	virtual std::istream& input(std::istream& in) override = 0;
	virtual std::ostream& print(std::ostream& out) const override = 0;

	virtual double Volume() = 0;
	virtual double Square() = 0;
};

