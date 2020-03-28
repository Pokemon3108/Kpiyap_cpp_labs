#pragma once
#include "GroundTransport.h"

class Bus : public GroundTransport
{
private:
	int capacity;
	int seatsNumber;
public:
	Bus() : capacity(0), seatsNumber(0)
	{
		//std::cout << "Constructor Bus" << std::endl;
	}
	Bus(std::string colour, int weight, std::string number, int p, int wheel, int cap, int num) :
		GroundTransport(colour, weight, number, p, wheel), capacity(cap), seatsNumber(num)
	{
		//std::cout << "Constructor Bus" << std::endl;
	}
	Bus(const Bus& obj) :
		GroundTransport(obj.colour, obj.maximumWeight, obj.number, obj.power, obj.wheelNumber),
		capacity(obj.capacity), seatsNumber(obj.seatsNumber)
	{
		//std::cout << "Constructor Bus" << std::endl;
	}

	~Bus()
	{
		//std::cout << "Destructor Bus" << std::endl;
	}

	bool operator !=(Bus& obj);
	bool operator ==(Bus& obj);
	Bus& operator = (Bus&obj);
	

	friend std::istream& operator >> (std::istream& in, Bus& obj);
	friend std::ostream& operator << (std::ostream& out, const Bus& obj);
	friend std::ifstream& operator >> (std::ifstream& in, Bus& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Bus& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream&out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	int getCapacity() const;
	void setCapacity(int cap);

	int getSeatsNumber() const;
	void setSeatsNumber(int num);

};

