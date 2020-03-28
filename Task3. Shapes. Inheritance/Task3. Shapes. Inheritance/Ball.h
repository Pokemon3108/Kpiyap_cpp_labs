#pragma once
#include "ThreeDShape.h"

class Ball : public ThreeDShape
{
public:
	Ball()
	{
		std::cout << "Constructor ball\n";
	};
	Ball(double radius) : ThreeDShape(radius)
	{
		std::cout << "Constructor ball\n";
	};
	Ball(const Ball& obj) : ThreeDShape(obj.h)
	{
		std::cout << "Constructor ball\n";
	};

	~Ball()
	{
		std::cout << "Destructor ball\n";
	};

	virtual std::istream& input(std::istream& in) override;
	virtual std::ostream& print(std::ostream& out)const override;

	virtual double Square() override;
	virtual double Volume() override;

};

