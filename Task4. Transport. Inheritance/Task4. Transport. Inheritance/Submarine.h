#pragma once
#include "WaterTransport.h"

class Submarine : public WaterTransport
{
private:
	double depth;
public:
	Submarine() : depth(0)
	{
		//std::cout << "Constructor Submarine" << std::endl;
	};
	Submarine(std::string colour, int weight, std::string number, std::string type1, std::string type2, int d) :
		WaterTransport(colour, weight, number, type1, type2), depth(d)
	{
		//std::cout << "Constructor Submarine" << std::endl;
	};
	Submarine(const Submarine& obj) :
		WaterTransport(obj.colour, obj.maximumWeight, obj.number, obj.typeTransfer, obj.typeWater), depth(obj.depth)
	{
		//std::cout << "Constructor Submarine" << std::endl;
	};

	~Submarine()
	{
		//std::cout << "Destructor Submarine" << std::endl;
	};

	Submarine& operator=(Submarine&obj);
	bool operator != (Submarine& obj);
	bool operator == (Submarine& obj);

	friend std::istream& operator >> (std::istream& in, Submarine& obj);
	friend std::ostream& operator << (std::ostream& out, const Submarine& obj);
	friend std::ifstream& operator >> (std::ifstream& in, Submarine& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Submarine& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	double getDepth()const;
	void setDepth(int d);
};


