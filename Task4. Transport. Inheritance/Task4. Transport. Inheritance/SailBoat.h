#pragma once
#include "WaterTransport.h"

class SailBoat : public WaterTransport
{
private:
	int sailsNumber;
public:
	SailBoat() : sailsNumber(0)
	{
		//std::cout << "Constructor SailBoat" << std::endl;
	};
	SailBoat(std::string colour, int weight, std::string number, std::string type1, std::string type2, int num) :
		WaterTransport(colour, weight, number, type1, type2), sailsNumber(num)
	{
		//std::cout << "Constructor SailBoat" << std::endl;
	};
	SailBoat(const SailBoat& obj) :
		WaterTransport(obj.colour, obj.maximumWeight, obj.number, obj.typeTransfer, obj.typeWater), sailsNumber(obj.sailsNumber)
	{
		//std::cout << "Constructor SailBoat" << std::endl;
	}

	~SailBoat()
	{
		//std::cout << "Destructor SailBoat" << std::endl;
	}

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	SailBoat& operator=(SailBoat&obj);
	bool operator != (SailBoat& obj);
	bool operator == (SailBoat& obj);

	friend std::istream& operator >> (std::istream& in, SailBoat& obj);
	friend std::ostream& operator << (std::ostream& out, const SailBoat& obj);
	friend std::ifstream& operator >> (std::ifstream& in, SailBoat& obj);
	friend std::ofstream& operator << (std::ofstream& out, const SailBoat& obj);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	int getSailsNumber()const;
	void setSailsNumber(int num);
};


