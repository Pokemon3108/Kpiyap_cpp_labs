#include "pch.h"
#include "SailBoat.h"


std::istream & operator>>(std::istream & in, SailBoat & obj)
{
	in >> dynamic_cast<WaterTransport&>(obj);
	std::cout << "Number of sails=";
	inputNumber(in, obj.sailsNumber,1,200);
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const SailBoat & obj)
{
	using namespace std;
	out << dynamic_cast<const WaterTransport&>(obj);
	out << setiosflags(ios::left) << setw(17) << obj.sailsNumber << endl;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, SailBoat & obj)
{
	in >> dynamic_cast<WaterTransport&>(obj);
	in >> obj.sailsNumber;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const SailBoat & obj)
{
	out << dynamic_cast<const WaterTransport&>(obj);
	out << obj.sailsNumber << '\n';
	return out;
}

void SailBoat::readBF(std::ifstream & in)
{
	(dynamic_cast<WaterTransport&>(*this)).readBF(in);
	in.read((char*)&sailsNumber, sizeof(sailsNumber));
}

void SailBoat::writeBF(std::ofstream & out)
{
	(dynamic_cast<WaterTransport&>(*this)).writeBF(out);
	out.write((char*)&sailsNumber, sizeof(sailsNumber));
}

SailBoat & SailBoat::operator=(SailBoat & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<WaterTransport*>(this)) = dynamic_cast<WaterTransport&>(obj);
		sailsNumber = obj.sailsNumber;
	}
	return *this;
}

bool SailBoat::operator!=(SailBoat & obj)
{
	return !(*this == obj);
}

bool SailBoat::operator==(SailBoat & obj)
{
	return (sailsNumber == obj.sailsNumber && *(dynamic_cast<WaterTransport*>(this)) == dynamic_cast<WaterTransport&>(obj));
}

void SailBoat::table(std::ostream & out)
{
	using namespace std;
	WaterTransport::table(out);
	out << setiosflags(ios::left) << setw(17) << "Number of sails" << endl;
}

void SailBoat::chooseParameters()
{
	WaterTransport::chooseParameters();
	cout << "6-Number of sails" << endl;
}

std::string SailBoat::getParameter(int n)
{
	std::string parameter = WaterTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Number of sails=";
			inputNumber(cin, sailsNumber, 1, 200);
			return "sailsNumber";
		default:
			return "";
		}
	}
	else return parameter;
}

int SailBoat::getSailsNumber() const
{
	return sailsNumber;
}

void SailBoat::setSailsNumber(int num)
{
	sailsNumber = num;
}

