#include "pch.h"
#include "Shape.h"

std::ostream & operator<<(std::ostream & out, const Shape& figure)
{
	return figure.print(out);
}

std::istream & operator>>(std::istream & in, Shape & figure)
{
	return figure.input(in);
}
