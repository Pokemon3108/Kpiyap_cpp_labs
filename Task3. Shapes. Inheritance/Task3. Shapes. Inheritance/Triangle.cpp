#include "pch.h"
#include "Triangle.h"

std::istream & Triangle::input(std::istream & in)
{
	in >> h >> line;
	return in;
}

std::ostream & Triangle::print(std::ostream & out) const
{
	out << " Height of triangle is: "<<h<<std::endl
		<< " The length of triangle's line: " << line<<std::endl;
	return out;
}

double Triangle::Square()
{
	return h * line / 2;
}

