#pragma once
#include "Transport.h"

class WaterTransport abstract : public Transport
{
protected:
	std::string typeTransfer;
	std::string typeWater;

public:

	WaterTransport()
	{
		//std::cout << "Constructor waterTransport" << std::endl;
	}
	WaterTransport(std::string colour, int weight, std::string number, std::string type1, std::string type2) :
		Transport(colour, weight, number), typeTransfer(type1), typeWater(type2)
	{
		//std::cout << "Constructor waterTransport" << std::endl;
	}
	WaterTransport(const WaterTransport& obj) :
		Transport(obj.colour, obj.maximumWeight, obj.number), typeTransfer(obj.typeTransfer), typeWater(obj.typeWater)
	{
		//std::cout << "Constructor waterTransport" << std::endl;
	}

	virtual ~WaterTransport()
	{
		//std::cout << "Destructor waterTransport" << std::endl;
	}

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	bool operator !=(WaterTransport& obj);
	bool operator ==(WaterTransport& obj);
	WaterTransport& operator = (WaterTransport&obj);

	friend std::istream& operator >> (std::istream& in, WaterTransport& obj);
	friend std::ostream& operator << (std::ostream& out, const WaterTransport& obj);
	friend std::ifstream& operator >> (std::ifstream& in, WaterTransport& obj);
	friend std::ofstream& operator << (std::ofstream& out, const WaterTransport& obj);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	void setTypeTransfer(std::string transfer);
	std::string getTypeTransfer() const;

	void setTypeWater(std::string water);
	std::string getTypeWater() const;
};


