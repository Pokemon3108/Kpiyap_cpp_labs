#include "pch.h"
#include "Submarine.h"

std::istream & operator>>(std::istream & in, Submarine & obj)
{
	in >> dynamic_cast<WaterTransport&>(obj);
	std::cout << "Depth=";
	inputNumber(in, obj.depth, 0.01, 11000.0);
	puts("\n");
	return in;
}

std::ostream & operator<<(std::ostream & out, const Submarine & obj)
{
	using namespace std;
	out << dynamic_cast<const WaterTransport&>(obj);
	out << setiosflags(ios::left) << setw(15) << obj.depth << endl;
	return out;
}

std::ifstream & operator>>(std::ifstream & in, Submarine & obj)
{
	in >> dynamic_cast<WaterTransport&>(obj);
	in >> obj.depth;
	in.get();
	return in;
}

std::ofstream & operator<<(std::ofstream & out, const Submarine & obj)
{
	out << dynamic_cast<const WaterTransport&>(obj);
	out << obj.depth << '\n';
	return out;
}

Submarine & Submarine::operator=(Submarine & obj)
{
	if (*(this) != obj)
	{
		*(dynamic_cast<WaterTransport*>(this)) = dynamic_cast<WaterTransport&>(obj);
		depth = obj.depth;
	}
	return *this;
}

bool Submarine::operator!=(Submarine & obj)
{
	return !(*this == obj);
}

bool Submarine::operator==(Submarine & obj)
{
	return (depth == obj.depth && *(dynamic_cast<WaterTransport*>(this)) == dynamic_cast<WaterTransport&>(obj));
}

void Submarine::readBF(std::ifstream & in)
{
	(dynamic_cast<WaterTransport&>(*this)).readBF(in);
	in.read((char*)&depth, sizeof(depth));
}

void Submarine::writeBF(std::ofstream & out)
{
	(dynamic_cast<WaterTransport&>(*this)).writeBF(out);
	out.write((char*)&depth, sizeof(depth));
}

void Submarine::table(std::ostream & out)
{
	using namespace std;
	WaterTransport::table(out);
	out << setiosflags(ios::left) << setw(15) << "Maximum depth" << endl;
}

void Submarine::chooseParameters()
{
	WaterTransport::chooseParameters();
	cout << "6-Maximum depth" << endl;
}

std::string Submarine::getParameter(int n)
{
	std::string parameter = WaterTransport::getParameter(n);
	if (parameter == "")
	{
		switch (n)
		{
		case 6:
			std::cout << "Depth=";
			inputNumber(cin, depth, 0.01, 11000.0);
			return "depth";
		default:
			return "";
		}
	}
	else return parameter;
}

double Submarine::getDepth() const
{
	return depth;
}

void Submarine::setDepth(int d)
{
	depth = d;
}


