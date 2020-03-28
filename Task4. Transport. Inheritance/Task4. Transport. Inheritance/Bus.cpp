#include "pch.h"
#include "Bus.h"


std::istream & operator>>(std::istream & in, Bus & obj)
{
	in >> dynamic_cast<GroundTransport&>(obj);
	std::cout << "Capacity=";
	inputNumber(in, obj.capacity,1,250);
	std::cout << "Number of seats=";
	inputNumber(in, obj.seatsNumber,1,250);
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const Bus & obj)
{
	using namespace std;
	out << dynamic_cast<const GroundTransport&>(obj);
	out << setiosflags(ios::left) << setw(11) << obj.capacity << setw(17) << obj.seatsNumber << endl;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Bus & obj)
{
	in >> dynamic_cast<GroundTransport&>(obj);
	in >> obj.seatsNumber;
	in.get();
	in >> obj.capacity;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Bus & obj)
{
	out << dynamic_cast<const GroundTransport&>(obj);
	out << obj.seatsNumber << '|' << obj.capacity << '\n';
	return out;
}

bool Bus::operator!=(Bus & obj)
{
	return !(*this == obj);
}

bool Bus::operator==(Bus & obj)
{
	return (capacity == obj.capacity && seatsNumber == obj.seatsNumber
		&& *(dynamic_cast<GroundTransport*>(this)) == dynamic_cast<GroundTransport&>(obj));
}

Bus & Bus::operator=(Bus & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<GroundTransport*>(this)) = dynamic_cast<GroundTransport&>(obj);
		seatsNumber = obj.seatsNumber;
		capacity = obj.capacity;
	}
	return *this;
}

void Bus::readBF(std::ifstream & in)
{
	(dynamic_cast<GroundTransport&>(*this)).readBF(in);
	in.read((char*)&capacity, sizeof(capacity));
	in.read((char*)&seatsNumber, sizeof(seatsNumber));
}

void Bus::writeBF(std::ofstream & out)
{
	(dynamic_cast<GroundTransport&>(*this)).writeBF(out);
	out.write((char*)&capacity, sizeof(capacity));
	out.write((char*)&seatsNumber, sizeof(seatsNumber));
}

void Bus::table(std::ostream & out)
{
	using namespace std;
	GroundTransport::table(out);
	out << setiosflags(ios::left) << setw(11) << "Capacity" << setw(17) << "Number of seats" << endl;
}

void Bus::chooseParameters()
{
	GroundTransport::chooseParameters();
	cout << "6-Capacity of passengers" << endl;
	cout << "7-Number of seats" << endl;
}

std::string Bus::getParameter(int n)
{
	std::string parameter = GroundTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Capacity=";
			inputNumber(cin, capacity, 1, 250);
			return "capacity";

		case 7:
			std::cout << "Number of seats=";
			inputNumber(cin, seatsNumber, 1, 250);
			return "seatsNumber";
		default:
			return "";
		}
	}
	else return parameter;
}

int Bus::getCapacity() const
{
	return capacity;
}

void Bus::setCapacity(int cap)
{
	capacity = cap;
}

int Bus::getSeatsNumber() const
{
	return seatsNumber;
}

void Bus::setSeatsNumber(int num)
{
	seatsNumber = num;
}
