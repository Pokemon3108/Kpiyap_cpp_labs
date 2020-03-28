#include "pch.h"
#include "AirTransport.h"


std::istream & operator>>(std::istream & in, AirTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	std::cout << "Maximum height=";
	inputNumber(in, obj.maximumHeight, 1, INT_MAX);
	std::cout << "Distance=";
	inputNumber(in, obj.distance, 1, INT_MAX);
	return in;
}

std::ostream & operator<<(std::ostream & out, const AirTransport & obj)
{
	using namespace std;
	out << dynamic_cast<const Transport&>(obj);
	out << setiosflags(ios::left) << setw(16) << obj.maximumHeight << setw(18) << obj.distance;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, AirTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	in >> obj.maximumHeight;
	in.get();
	in >> obj.distance;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const AirTransport & obj)
{
	out << dynamic_cast<const Transport&>(obj);
	out << obj.maximumHeight << '|' << obj.distance << '|';
	return out;
}

//std::fstream & operator>>(std::fstream & in, AirTransport & obj)
//{
//	in >> dynamic_cast<Transport&>(obj);
//	in.write((char*)&obj.maximumHeight, sizeof(obj.maximumHeight));
//	in.write((char*)&obj.distance, sizeof(obj.distance));
//	return in;
//}
//
//std::fstream & operator<<(std::fstream & out, AirTransport & obj)
//{
//	out << dynamic_cast<Transport&>(obj);
//	out.read((char*)&obj.maximumHeight, sizeof(obj.maximumHeight));
//	out.read((char*)&obj.distance, sizeof(obj.distance));
//	return out;
//}

bool AirTransport::operator!=(AirTransport & obj)
{
	return (!(*this == obj));
}

bool AirTransport::operator==(AirTransport & obj)
{
	return ((maximumHeight == obj.maximumHeight && distance == obj.distance
		&& *(dynamic_cast<Transport*>(this)) == dynamic_cast<Transport&>(obj)));
}

AirTransport & AirTransport::operator=(AirTransport & obj)
{
	if ((*this) != obj)
	{
		*(dynamic_cast<Transport*>(this)) = dynamic_cast<Transport&>(obj);
		maximumHeight = obj.maximumHeight;
		distance = obj.distance;
	}
	return *this;
}

void AirTransport::readBF(std::ifstream & in)
{
	(dynamic_cast<Transport&>(*this)).readBF(in);
	in.read((char*)&maximumHeight, sizeof(maximumHeight));
	in.read((char*)&distance, sizeof(distance));
	
}

void AirTransport::writeBF(std::ofstream & out)
{
	(dynamic_cast<Transport&>(*this)).writeBF(out);
	out.write((char*)&maximumHeight, sizeof(maximumHeight));
	out.write((char*)&distance, sizeof(distance));

}

void AirTransport::table(std::ostream & out)
{
	using namespace std;
	Transport::table(out);
	out << setiosflags(ios::left) << setw(16) << "Maximum height" << setw(18) << "Maximum distance";
}

void AirTransport::chooseParameters()
{
	Transport::chooseParameters();
	cout << "4-Maximum height" << endl;
	cout << "5-Distance of fly" << endl;
}

std::string AirTransport::getParameter(int n)
{
	std::string parameter = Transport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 4:
			std::cout << "Maximum height=";
			inputNumber(cin, maximumHeight, 1, INT_MAX);
			return "maximumHeight";
		case 5:
			std::cout << "Distance=";
			inputNumber(cin, distance, 1, INT_MAX);
			return "distance";
		default:
			return "";
		}
	}
	else return parameter;
}

int AirTransport::getMaximumHeight() const
{
	return maximumHeight;
}

void AirTransport::setMaximumHeight(int h)
{
	maximumHeight = h;
}

int AirTransport::getDistance() const
{
	return distance;
}

void AirTransport::setDistance(int d)
{
	distance = d;
}
