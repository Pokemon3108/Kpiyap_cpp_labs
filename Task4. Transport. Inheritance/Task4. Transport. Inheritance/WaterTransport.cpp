#include "pch.h"
#include "WaterTransport.h"


std::istream & operator>>(std::istream & in, WaterTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	rewind(stdin);
	std::cout << "Type of transfer: ";
	inputLetters(in, obj.typeTransfer);
	std::cout << "Type of water: ";
	inputLetters(in, obj.typeWater);
	return in;
}

std::ostream & operator<<(std::ostream & out, const WaterTransport & obj)
{
	using namespace std;
	out << dynamic_cast<const Transport&>(obj);
	out << setiosflags(ios::left) << setw(17) << obj.typeTransfer << setw(14) << obj.typeWater;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, WaterTransport & obj)
{
	in >> dynamic_cast<Transport&>(obj);
	std::getline(in, obj.typeTransfer, '|');
	std::getline(in, obj.typeWater, '|');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const WaterTransport & obj)
{
	out << dynamic_cast<const Transport&>(obj);
	out << obj.typeTransfer << '|' << obj.typeWater << '|';
	return out;
}


void WaterTransport::readBF(std::ifstream & in)
{
	(dynamic_cast<Transport&>(*this)).readBF(in);

	int len;
	in.read((char*)&len, sizeof(len));
	char* str = new char[len];
	in.read(str, len);
	typeTransfer = str;
	delete str;

	in.read((char*)&len, sizeof(len));
	str = new char[len];
	in.read(str, len);
	typeWater = str;
	delete str;
}

void WaterTransport::writeBF(std::ofstream & out)
{
	(dynamic_cast<Transport&>(*this)).writeBF(out);

	int len;
	len = typeTransfer.length() + 1;
	out.write((char*)&len, sizeof(len));
	out.write(typeTransfer.c_str(), len);

	len = typeWater.length() + 1;
	out.write((char*)&len, sizeof(len));
	out.write(typeWater.c_str(), len);
}

bool WaterTransport::operator!=(WaterTransport & obj)
{
	return (!(*this == obj));
}

bool WaterTransport::operator==(WaterTransport & obj)
{
	return ((typeTransfer == obj.typeTransfer && typeWater == obj.typeWater
		&& *(dynamic_cast<Transport*>(this)) == dynamic_cast<Transport&>(obj)));
}

WaterTransport & WaterTransport::operator=(WaterTransport & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<Transport*>(this)) = dynamic_cast<Transport&>(obj);
		typeTransfer = obj.typeTransfer;
		typeWater = obj.typeWater;
	}
	return *this;
}

void WaterTransport::table(std::ostream & out)
{
	using namespace std;
	Transport::table(out);
	out << setiosflags(ios::left) << setw(17) << "Type of transfer" << setw(14) << "Type of water";
}

void WaterTransport::chooseParameters()
{
	Transport::chooseParameters();
	cout << "4-Type of transfer" << endl;
	cout << "5-Type of water" << endl;
}

std::string WaterTransport::getParameter(int n)
{
	std::string parameter = Transport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 4:
			std::cout << "Type of transfer: ";
			inputLetters(cin, typeTransfer);
			return "typeTransfer";

		case 5:
			std::cout << "Type of water: ";
			inputLetters(cin, typeWater);
			return "typeWater";
			
		default:
			return "";
		}
	}
	else return parameter;
}

std::string WaterTransport::getTypeTransfer() const
{
	return typeTransfer;
}

void WaterTransport::setTypeWater(std::string water)
{
	typeWater = water;
}

std::string WaterTransport::getTypeWater() const
{
	return typeWater;
}

void WaterTransport::setTypeTransfer(std::string transfer)
{
	typeTransfer = transfer;
}
