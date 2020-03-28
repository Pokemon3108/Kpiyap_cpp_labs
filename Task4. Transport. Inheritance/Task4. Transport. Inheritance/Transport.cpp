#include "pch.h"
#include "Transport.h"
#include <string>


std::istream & operator>>(std::istream & in, Transport & obj)
{
	
	std::cout << "Maximum weight=";
	inputNumber(in, obj.maximumWeight, 1, INT_MAX);
	rewind(stdin);
	std::cout << "Colour:";
	inputLetters(in,obj.colour);
	rewind(stdin);
	std::cout << "Number of license=";
	inputLettersAndNumbers(in,obj.number);
	return in;
}

std::ostream & operator<<(std::ostream & out, const Transport & obj)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << obj.colour << setw(15) << obj.maximumWeight << setw(17) << obj.number;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Transport & obj)
{
	std::getline(in,obj.colour, '|');
	in >> obj.maximumWeight;
	in.get();
	std::getline(in, obj.number, '|');
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Transport & obj)
{
	out << obj.colour << '|' << obj.maximumWeight << '|' << obj.number<<'|';
	return out;
}

//std::fstream & operator>>(std::fstream & in, Transport & obj)
//{
//	int len;
//	len = obj.colour.length() + 1;
//	in.write((char*)&len, sizeof(len));
//	in.write(obj.colour.c_str(), len);
//
//	in.write((char*)&obj.maximumWeight, sizeof(obj.maximumWeight));
//
//	len = obj.number.length() + 1;
//	in.write((char*)&len, sizeof(len));
//	in.write(obj.number.c_str(), len);
//
//	return in;
//}
//
//std::fstream & operator<<(std::fstream & out, Transport & obj)
//{
//	int len;
//	out.read((char*)&len, sizeof(len));
//	char* str = new char[len];
//	out.read(str, len);
//	obj.colour = str;
//	delete str;
//
//	out.read((char*)&obj.maximumWeight, sizeof(obj.maximumWeight));
//
//	out.read((char*)&len, sizeof(len));
//	str = new char[len];
//	out.read(str, len);
//	obj.number = str;
//	delete str;
//
//	return out;
//}

void Transport::readBF(std::ifstream & in)
{
	int len;
	in.read((char*)&len, sizeof(len));
	char* str = new char[len];
	in.read(str, len);
	colour = str;
	delete str;

	in.read((char*)&maximumWeight, sizeof(maximumWeight));

	in.read((char*)&len, sizeof(len));
	str = new char[len];
	in.read(str, len);
	number = str;
	delete str;

}

void Transport::writeBF(std::ofstream & out)
{
	int len;
	len = colour.length() + 1;
	out.write((char*)&len, sizeof(len));
	out.write(colour.c_str(), len);
	
	out.write((char*)&maximumWeight, sizeof(maximumWeight));
	
	len = number.length() + 1;
	out.write((char*)&len, sizeof(len));
	out.write(number.c_str(), len);
	
	
}

bool Transport::operator!=(Transport & obj)
{
	return (!(*this == obj));
}

bool Transport::operator==(Transport & obj)
{
	return (colour == obj.colour && maximumWeight == obj.maximumWeight && number == obj.number);
}

Transport & Transport::operator=(Transport & obj)
{
	if (*this != obj)
	{
		colour = obj.colour;
		maximumWeight = obj.maximumWeight;
		number = obj.number;
	}
	return *this;
}

bool Transport::operator>(Transport & obj)
{
	return (number > obj.number);
}

bool Transport::operator<(Transport & obj)
{
	return (number < obj.number);
}

void Transport::table(std::ostream & out)
{
	using namespace std;
	out << setiosflags(ios::left) << setw(15) << "Colour" << setw(15) << "Maximum weight" << setw(17) << "License number";
}

std::string Transport::getParameter(int n)
{
	switch (n)
	{
	case 1:
		std::cout << "Colour:";
		inputLetters(cin, colour);
		return "colour";
	case 2:
		std::cout << "Maximum weight=";
		inputNumber(cin, maximumWeight, 1, INT_MAX);
		return "maximumWeight";
	case 3:
		std::cout << "Number of license=";
		inputLetters(cin, number);
		return "number";
	default:
		return "";
	}
}

void Transport::setColour(std::string cl)
{
	colour = cl;

}

std::string Transport::getColour() const
{
	return colour;
}

void Transport::setNumber(std::string num)
{
	number = num;
}

std::string Transport::getNumber() const
{
	return number;
}

void Transport::setMaximumWeight(int weight)
{
	maximumWeight = weight;
}

int Transport::getMaximumWeight() const
{
	return maximumWeight;
}

void Transport::chooseParameters()
{
	cout << "Choose parameters for search:" << endl;
	cout << "1-Colour" << endl;
	cout << "2-Maximum weight" << endl;
	cout << "3-License number" << endl;

}


