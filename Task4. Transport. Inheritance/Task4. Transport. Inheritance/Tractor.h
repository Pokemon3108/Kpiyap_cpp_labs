#pragma once
#include "GroundTransport.h"

class Tractor : public GroundTransport
{
private:
	double tractionClass;
public:
	Tractor() : tractionClass(0)
	{
		//std::cout << "Constructor Tractor" << std::endl;
	}
	Tractor(std::string colour, int weight, std::string number, int p, int wheel, double n) :
		GroundTransport(colour, weight, number, p, wheel), tractionClass(n)
	{
		//std::cout << "Constructor Tractor" << std::endl;
	}
	Tractor(const Tractor& obj) :
		GroundTransport(obj.colour, obj.maximumWeight, obj.number, obj.power, obj.wheelNumber), tractionClass(obj.tractionClass)
	{
		//std::cout << "Constructor Tractor" << std::endl;
	}

	~Tractor()
	{
		//std::cout << "Destructor Tractor" << std::endl;
	}

	bool operator !=(Tractor& obj);
	bool operator ==(Tractor& obj);
	Tractor& operator = (Tractor&obj);

	friend std::istream& operator >> (std::istream& in, Tractor& obj);
	friend std::ostream& operator << (std::ostream& out, const Tractor& obj);
	friend std::ifstream& operator >> (std::ifstream& in, Tractor& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Tractor& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream&out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	double getTractionClass() const;
	void setTractionClass(int classTr);
};


