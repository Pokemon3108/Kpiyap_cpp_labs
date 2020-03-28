#include "pch.h"
#include "Circle.h"

std::istream & Circle::input(std::istream & in)
{
	in >> h;
	return in;
}

std::ostream & Circle::print(std::ostream & out) const
{
	out <<" Radius of circle is: "<< h << std::endl;
	return out;
}

double Circle::Square()
{
	return M_PI * pow(h, 2);
}


