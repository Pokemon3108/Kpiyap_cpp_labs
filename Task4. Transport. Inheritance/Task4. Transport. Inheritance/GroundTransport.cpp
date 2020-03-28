#include "pch.h"
#include "GroundTransport.h"

std::istream & operator>>(std::istream & in, GroundTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	std::cout << "Power=";
	inputNumber(in, obj.power,1, INT_MAX);
	std::cout << "Number of wheels=";
	inputNumber(in, obj.wheelNumber,1, INT_MAX);
	return in;
}

std::ostream & operator<<(std::ostream & out, const GroundTransport & obj)
{
	using namespace std;
	out << dynamic_cast<const Transport&>(obj);
	out << setiosflags(ios::left) << setw(8) << obj.power << setw(17) << obj.wheelNumber;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, GroundTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	in >> obj.power;
	in.get();
	in >> obj.wheelNumber;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const GroundTransport & obj)
{
	out << dynamic_cast<const Transport&>(obj);
	out << obj.power << '|' << obj.wheelNumber << '|';
	return out;
}

bool GroundTransport::operator!=(GroundTransport & obj)
{
	return (!(*this == obj));
}

bool GroundTransport::operator==(GroundTransport & obj)
{
	return ((power == obj.power && wheelNumber == obj.wheelNumber
		&& *(dynamic_cast<Transport*>(this)) == dynamic_cast<Transport&>(obj)));
}

GroundTransport & GroundTransport::operator=(GroundTransport & obj)
{
	if ((*this) != obj)
	{
		*(dynamic_cast<Transport*>(this)) = dynamic_cast<Transport&>(obj);
		wheelNumber = obj.wheelNumber;
		power = obj.power;
	}
	return *this;
}

void GroundTransport::readBF(std::ifstream & in)
{
	(dynamic_cast<Transport&>(*this)).readBF(in);
	in.read((char*)&power, sizeof(power));
	in.read((char*)&wheelNumber, sizeof(wheelNumber));

}

void GroundTransport::writeBF(std::ofstream & out)
{
	(dynamic_cast<Transport&>(*this)).writeBF(out);
	out.write((char*)&power, sizeof(power));
	out.write((char*)&wheelNumber, sizeof(wheelNumber));
}

void GroundTransport::table(std::ostream & out)
{
	using namespace std;
	Transport::table(out);
	out << setiosflags(ios::left) << setw(8) << "Power" << setw(17) << "Wheel's number";
}

void GroundTransport::chooseParameters()
{
	Transport::chooseParameters();
	cout << "4-Power" << endl;
	cout << "5-Number of wheels" << endl;
}

std::string GroundTransport::getParameter(int n)
{
	std::string parameter = Transport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 4:
			std::cout << "Power=";
			inputNumber(cin, power, 1, INT_MAX);
			return "power";
		case 5:
			std::cout << "Number of wheels=";
			inputNumber(cin, wheelNumber, 1, INT_MAX);
			return "wheelNumber";
		default:
			return "";
		}
	}
	else return parameter;
}

int GroundTransport::getPower() const
{
	return power;
}

void GroundTransport::setPower(int p)
{
	power = p;
}

int GroundTransport::getWheelNumber() const
{
	return wheelNumber;
}

void GroundTransport::setWheelNumber(int num)
{
	wheelNumber = num;
}

