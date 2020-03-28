#pragma once
#include "Transport.h"

class GroundTransport abstract : public Transport
{
protected:
	int power;
	int wheelNumber;

public:
	GroundTransport() : power(0), wheelNumber(0)
	{
		//std::cout << "Constructor GroundTransport" << std::endl;
	};
	GroundTransport(std::string colour, int weight, std::string number, int p, int wheel) :
		Transport(colour, weight, number), power(p), wheelNumber(wheel)
	{
		//std::cout << "Constructor GroundTransport" << std::endl;
	};
	GroundTransport(const GroundTransport& obj) :
		Transport(obj.colour, obj.maximumWeight, obj.number), power(obj.power), wheelNumber(obj.wheelNumber)
	{
		//std::cout << "Constructor GroundTransport" << std::endl;
	};

	virtual ~GroundTransport()
	{
		//std::cout << "Destructor GroundTransport" << std::endl;
	};

	bool operator !=(GroundTransport& obj);
	bool operator ==(GroundTransport& obj);
	GroundTransport& operator = (GroundTransport&obj);

	friend std::istream& operator >> (std::istream& in, GroundTransport& obj);
	friend std::ostream& operator << (std::ostream& out, const GroundTransport& obj);
	friend std::ifstream& operator >> (std::ifstream& in, GroundTransport& obj);
	friend std::ofstream& operator << (std::ofstream& out, const GroundTransport& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream&out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	int getPower()const;
	void setPower(int p);

	int getWheelNumber()const;
	void setWheelNumber(int num);
};


