#include "pch.h"
#include "Helicopter.h"


double & Helicopter::operator[](int i)
{
	return this->rad[i];
}

Helicopter& Helicopter::operator=(Helicopter&obj)
{
	
	*(dynamic_cast<AirTransport*>(this)) = dynamic_cast<AirTransport&>(obj);
	frequency = obj.frequency;
	screwNumber = obj.screwNumber;
	delete this->rad;
	rad = new double[obj.screwNumber];
	for (int i = 0; i < obj.screwNumber; ++i)
		rad[i] = obj.rad[i];
	
	return *this;
}

bool Helicopter::operator!=(Helicopter & obj)
{
	return (!(*this == obj));
}

bool Helicopter::operator==(Helicopter & obj)
{
	
	for (int i = 0; i < screwNumber; ++i)
	{
		if (obj.rad[i] != rad[i])
			return false;
	}
	if (frequency == obj.frequency && screwNumber == obj.screwNumber
		&& *(dynamic_cast<AirTransport*>(this)) == dynamic_cast<AirTransport&>(obj))  return true;
	return true;
}

void Helicopter::readBF(std::ifstream & in)
{
	(dynamic_cast<AirTransport&>(*this)).readBF(in);
	in.read((char*)&frequency, sizeof(frequency));
	in.read((char*)&screwNumber, sizeof(screwNumber));
	rad = new double[screwNumber];
	for (int i = 0; i < screwNumber; ++i)
	{
		in.read((char*)&rad[i], sizeof(rad[i]));
	}
}

void Helicopter::writeBF(std::ofstream & out)
{
	(dynamic_cast<AirTransport&>(*this)).writeBF(out);
	out.write((char*)&frequency, sizeof(frequency));
	out.write((char*)&screwNumber, sizeof(screwNumber));
	for (int i = 0; i < screwNumber; ++i)
	{
		out.write((char*)&rad[i], sizeof(rad[i]));
	}
}

void Helicopter::table(std::ostream & out)
{
	using namespace std;
	AirTransport::table(out);
	out << setiosflags(ios::left) << setw(18) << "Rotational speed" << setw(19) << "Number of screws" << setw(20) << "Radiuses of screw" << endl;
}

void Helicopter::chooseParameters()
{
	AirTransport::chooseParameters();
	cout << "6-Number of screws" << endl;
	cout << "7-Radius of screw" << endl;
	cout << "8-Frequency" << endl;
}

std::string Helicopter::getParameter(int n)
{
	std::string parameter = AirTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Number of screws=";
			inputNumber(cin, screwNumber, 1, 100);
			return "screwNumber";
		case 7:
			std::cout << "Radius of screw:";
			rad = new double[1];
			inputNumber(cin, rad[0], 0.1, 100.0);
			return "rad";
		case 8:
			std::cout << "Frequency=";
			inputNumber(cin, frequency, 1, INT_MAX);
			return "frequency";
		default:
			return "";
		}
	}
	else return parameter;
}

int Helicopter::getScrewNumber() const
{
	return screwNumber;
}

void Helicopter::setScrewNumber(int num)
{
	screwNumber = num;
}

int Helicopter::getFrequency() const
{
	return frequency;
}

void Helicopter::setFrequency(int fr)
{
	frequency = fr;
}

bool Helicopter::isInRadiusArray(double n)
{
	for (int i = 0; i < screwNumber; ++i)
		if (rad[i] == n) return true;
	return false;
}


std::istream & operator>>(std::istream & in, Helicopter & obj)
{
	in>>dynamic_cast<AirTransport&>(obj);
	std::cout << "Frequency=";
	inputNumber(in, obj.frequency,1,INT_MAX);
	std::cout << "Number of screws=";
	inputNumber(in, obj.screwNumber,1,100);
	obj.rad = new double[obj.screwNumber];
	for (int i = 0; i < obj.screwNumber; ++i)
	{
		std::cout << "Radius of [" << i << "] screw:";
		inputNumber(in, obj[i], 0.1, 100.0);
	}
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const Helicopter & obj)
{
	using namespace std;
	out << dynamic_cast<const AirTransport&>(obj);
	out << setiosflags(ios::left) << setw(18) << obj.frequency << setw(19) << obj.screwNumber;
	for (int i = 0; i < obj.screwNumber; ++i)
	{
		out << obj.rad[i];
		if (i != obj.screwNumber - 1) putchar(',');
	}
	putchar('\n');
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Helicopter & obj)
{
	in >> dynamic_cast<AirTransport&>(obj);
	in >> obj.frequency;
	in.get();
	in >> obj.screwNumber;
	in.get();
	obj.rad = new double[obj.screwNumber];
	for (int i = 0; i < obj.screwNumber; ++i)
	{
		in>>obj.rad[i];
		in.get();
	}
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Helicopter & obj)
{
	out << dynamic_cast<const AirTransport&>(obj);
	out << obj.frequency << '|' << obj.screwNumber << '|';
	for (int i = 0; i < obj.screwNumber; ++i)
	{
		out<< obj.rad[i];
		if (i != obj.screwNumber - 1) out << ',';
	}
	out << '\n';
	return out;
}

