#include "pch.h"
#include "Ball.h"
#define _USE_MATH_DEFINES
#include <cmath>

std::istream & Ball::input(std::istream & in)
{
	in >> h;
	return in;
}

std::ostream & Ball::print(std::ostream & out) const
{
	out << " Radius of ball is " << h<<std::endl;
	return out;
}

double Ball::Square()
{
	return 1;
}

double Ball::Volume()
{
	return 4 * M_PI*pow(h, 3) / 3;
}
