#include "pch.h"
#include "Cylinder.h"

std::istream & Cylinder::input(std::istream & in)
{
	in >> h >> radius;
	return in;
}

std::ostream & Cylinder::print(std::ostream & out) const
{
	out << " Height of cylinder is: " << h << std::endl
		<< " Radius of cylinder is: " << radius << std::endl;
	return out;
}

double Cylinder::Square()
{
	return M_PI * pow(radius, 2);
}

double Cylinder::Volume()
{
	return h * this->Square();
}
