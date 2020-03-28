#include "pch.h"
#include "Tractor.h"


std::istream & operator>>(std::istream & in, Tractor & obj)
{
	in >> dynamic_cast<GroundTransport&>(obj);
	std::cout << "Tranction class=";
	inputNumber(in, obj.tractionClass, 0.1, 75.0);
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const Tractor & obj)
{
	using namespace std;
	out << dynamic_cast<const GroundTransport&>(obj);
	out << setiosflags(ios::left) << setw(16) << obj.tractionClass << endl;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Tractor & obj)
{
	in >> dynamic_cast<GroundTransport&>(obj);
	in >> obj.tractionClass;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Tractor & obj)
{
	out << dynamic_cast<const GroundTransport&>(obj);
	out << obj.tractionClass << '\n';
	return out;
}

bool Tractor::operator!=(Tractor & obj)
{
	return (!(*this == obj));
}

bool Tractor::operator==(Tractor & obj)
{
	return (tractionClass == obj.tractionClass
		&& *(dynamic_cast<GroundTransport*>(this)) == dynamic_cast<GroundTransport&>(obj));
}

Tractor & Tractor::operator=(Tractor & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<GroundTransport*>(this)) = dynamic_cast<GroundTransport&>(obj);
		tractionClass = obj.tractionClass;
	}
	return *this;
}

void Tractor::readBF(std::ifstream & in)
{
	(dynamic_cast<GroundTransport&>(*this)).readBF(in);
	in.read((char*)&tractionClass, sizeof(tractionClass));

}

void Tractor::writeBF(std::ofstream & out)
{
	(dynamic_cast<GroundTransport&>(*this)).writeBF(out);
	out.write((char*)&tractionClass, sizeof(tractionClass));
}

void Tractor::table(std::ostream & out)
{
	using namespace std;
	GroundTransport::table(out);
	out << setiosflags(ios::left) << setw(16) << "Tractor's class" << endl;
}

void Tractor::chooseParameters()
{
	GroundTransport::chooseParameters();
	cout << "6-Traction class" << endl;
}

std::string Tractor::getParameter(int n)
{
	std::string parameter = GroundTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Tranction class=";
			inputNumber(cin, tractionClass, 0.1, 75.0);
			return "tractionClass";
		default:
			return "";
		}
	}
	else return parameter;
}

double Tractor::getTractionClass() const
{
	return tractionClass;
}

void Tractor::setTractionClass(int classTr)
{
	tractionClass = classTr;
}
