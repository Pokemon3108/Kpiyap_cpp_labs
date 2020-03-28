#pragma once
#include "Transport.h"

class AirTransport abstract : public Transport
{
protected:
	int maximumHeight;
	int distance;
public:
	AirTransport() : maximumHeight(0), distance(0)
	{
		//std::cout << "Constructor AirTransport" << std::endl;
	};
	AirTransport(std::string colour, int weight, std::string number, int h, int d) :
		Transport(colour, weight, number), maximumHeight(h), distance(d)
	{
		//std::cout << "Constructor AirTransport" << std::endl;
	};
	AirTransport(const AirTransport& obj) :
		Transport(obj.colour, obj.maximumWeight, obj.number), maximumHeight(obj.maximumHeight), distance(obj.distance)
	{
		//std::cout << "Constructor AirTransport" << std::endl;
	};

	virtual ~AirTransport()
	{
		//std::cout << "Destructor AirTransport" << std::endl;
	};

	bool operator !=(AirTransport& obj);
	bool operator ==(AirTransport& obj);
	AirTransport& operator = (AirTransport&obj);

	friend std::istream& operator>> (std::istream& in, AirTransport& obj);
	friend std::ostream& operator << (std::ostream& out, const AirTransport& obj);
	friend std::ifstream& operator>> (std::ifstream& in, AirTransport& obj);
	friend std::ofstream& operator << (std::ofstream& out, const AirTransport& obj);
	//friend std::fstream& operator >> (std::fstream& in, AirTransport& obj);
	//friend std::fstream& operator << (std::fstream& out, AirTransport& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	int getMaximumHeight()const;
	void setMaximumHeight(int h);

	int getDistance() const;
	void setDistance(int d);

};

