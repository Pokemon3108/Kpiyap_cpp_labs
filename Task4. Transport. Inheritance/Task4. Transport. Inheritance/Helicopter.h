#pragma once
#include "AirTransport.h"

class Helicopter : public AirTransport
{
private:
	int screwNumber;
	double* rad;
	int frequency;

public:
	Helicopter() : screwNumber(0), frequency(0), rad(nullptr)
	{
		//std::cout << "Constructor Helicopter" << std::endl;
	}
	Helicopter(std::string colour, int weight, std::string number, int h, int d, int num, int fr) :
		AirTransport(colour, weight, number, h, d), screwNumber(num), frequency(fr)
	{
		//std::cout << "Constructor Helicopter" << std::endl;
		rad = new double[screwNumber];
	}
	Helicopter(const Helicopter& obj) :
		AirTransport(obj.colour, obj.maximumWeight, obj.number, obj.maximumHeight, obj.distance),
		screwNumber(obj.screwNumber), frequency(obj.frequency)
	{
		//std::cout << "Constructor Helicopter" << std::endl;
		rad = new double[screwNumber];
		for (int i = 0; i < screwNumber; ++i)
			rad[i] = obj.rad[i];
	}

	~Helicopter()
	{
		//std::cout << "Destructor Helicopter" << std::endl;
		delete[] rad;
	}

	double& operator[](int i);
	Helicopter& operator=(Helicopter&obj);
	bool operator != (Helicopter& obj);
	bool operator == (Helicopter& obj);
	

	friend std::istream& operator>>(std::istream& in, Helicopter& obj);
	friend std::ostream& operator << (std::ostream& out, const Helicopter& obj);
	friend std::ifstream& operator>>(std::ifstream& in, Helicopter& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Helicopter& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	int getScrewNumber() const;
	void setScrewNumber(int num);

	int getFrequency() const;
	void setFrequency(int fr);

	bool isInRadiusArray(double n);

};


