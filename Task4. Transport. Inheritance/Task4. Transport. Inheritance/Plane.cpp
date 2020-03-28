#include "pch.h"
#include "Plane.h"

std::istream & operator>>(std::istream & in, Plane & obj)
{
	in>> dynamic_cast<AirTransport&>(obj);
	std::cout << "Speed=";
	inputNumber(in, obj.speed, 100.0, 11230.0);
	std::cout << "Length of wings=";
	inputNumber(in,obj.wingLength, 0.1, 100.0);
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const Plane & obj)
{
	using namespace std;
	out << dynamic_cast<const AirTransport&>(obj);
	out << setw(15) << obj.speed << setw(17) << obj.wingLength << endl;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Plane & obj)
{
	in >> dynamic_cast<AirTransport&>(obj);
	in >> obj.speed;
	in.get();
	in >> obj.wingLength;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Plane & obj)
{
	out << dynamic_cast<const AirTransport&>(obj);
	out << obj.speed << '|' << obj.wingLength<<'\n';
	return out;
}

//std::fstream & operator>>(std::fstream & in, Plane & obj)
//{
//	in >> dynamic_cast<AirTransport&>(obj);
//	in.write((char*)&obj.speed, sizeof(obj.speed));
//	in.write((char*)&obj.wingLength, sizeof(obj.wingLength));
//	in.seekg(in.tellg(), std::ios::beg);
//	return in;
//}
//
//std::fstream & operator<<(std::fstream & out, Plane & obj)
//{
//	out << dynamic_cast<const AirTransport&>(obj);
//	out.read((char*)&obj.speed, sizeof(obj.speed));
//	out.read((char*)&obj.wingLength, sizeof(obj.wingLength));
//	return out;
//}

Plane & Plane::operator=(Plane & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<AirTransport*>(this)) = dynamic_cast<AirTransport&>(obj);
		speed = obj.speed;
		wingLength = obj.wingLength;
	}
	return *this;
}

bool Plane::operator!=(Plane & obj)
{
	return !(*this == obj);
}

bool Plane::operator==(Plane & obj)
{
	return (*(dynamic_cast<AirTransport*>(this)) == dynamic_cast<AirTransport&>(obj)
		&& obj.wingLength == wingLength && obj.speed == speed);
}

void Plane::readBF(std::ifstream & in)
{
	(dynamic_cast<AirTransport&>(*this)).readBF(in);
	in.read((char*)&speed, sizeof(speed));
	in.read((char*)&wingLength, sizeof(wingLength));
	
}

void Plane::writeBF(std::ofstream & out)
{
	(dynamic_cast<AirTransport&>(*this)).writeBF(out);
	out.write((char*)&speed, sizeof(speed));
	out.write((char*)&wingLength, sizeof(wingLength));
	
}

void Plane::table(std::ostream & out)
{
	using namespace std;
	AirTransport::table(out);
	out << setw(15) << "Maximum speed" << setw(17) << "Length of wings" << endl;
}

void Plane::chooseParameters()
{
	AirTransport::chooseParameters();
	cout << "6-Maximum speed" << endl;
	cout << "7-Length of wings" << endl;
}

std::string Plane::getParameter(int n)
{
	std::string parameter = AirTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Speed=";
			inputNumber(cin, speed, 100.0, 11230.0);
			return "speed";

		case 7:
			std::cout << "Length of wings=";
			inputNumber(cin, wingLength, 0.1, 100.0);
			return "wingLength";
		default:
			return "";
		}
	}
	else return parameter;
}

double Plane::getSpeed() const
{
	return speed;
}

void Plane::setSpeed(int s)
{
	speed = s;
}

double Plane::getWingLength() const
{
	return wingLength;
}

void Plane::setWingLength(int len)
{
	wingLength = len;
}
