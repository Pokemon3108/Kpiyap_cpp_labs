#pragma once
#include "ThreeDShape.h"


class Cylinder : public ThreeDShape
{
private:
	double radius;
public:
	Cylinder() : radius(0)
	{
		std::cout << "Constructor cylinder\n";
	};
	Cylinder(double rad, double h) : ThreeDShape(h), radius(rad)
	{
		std::cout << "Constructor cylinder\n";
	};
	Cylinder(const Cylinder& obj) : radius(obj.radius), ThreeDShape(obj.h)
	{
		std::cout << "Constructor cylinder\n";
	};

	~Cylinder() 
	{
		std::cout << "Destructor cylinder\n";
	};

	virtual std::istream& input(std::istream& in) override;
	virtual std::ostream& print(std::ostream& out) const override;

	virtual double Square() override;
	virtual double Volume() override;
};

