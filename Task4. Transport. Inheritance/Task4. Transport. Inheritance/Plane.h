#pragma once
#include "AirTransport.h"

class Plane : public AirTransport
{
private:
	double speed;
	double wingLength;
public:
	Plane() : speed(0), wingLength(0)
	{
		//std::cout << "Constructor plane" << std::endl;
	};
	Plane(std::string colour, int weight, std::string number, int h, int d, double s, double len) :
		AirTransport(colour, weight, number, h, d), speed(s), wingLength(len)
	{
		//std::cout << "Constructor plane" << std::endl;
	};
	Plane(const Plane& obj) :
		AirTransport(obj.colour, obj.maximumWeight, obj.number, obj.maximumHeight, obj.distance),
		speed(obj.speed), wingLength(obj.wingLength)
	{
		//std::cout << "Constructor plane" << std::endl;
	};

	~Plane()
	{
		//std::cout << "Destructor plane" << std::endl;
	};

	Plane& operator=(Plane&obj);
	bool operator != (Plane& obj);
	bool operator == (Plane& obj);

	friend std::istream& operator >> (std::istream& in, Plane& obj);
	friend std::ostream& operator << (std::ostream& out, const Plane& obj);
	friend std::ifstream& operator >> (std::ifstream& in, Plane& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Plane& obj);
	//friend std::fstream& operator >> (std::fstream& in, Plane& obj);
	//friend std::fstream& operator << (std::fstream& out, Plane& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	virtual void table(std::ostream& out) override;
	virtual void chooseParameters() override;
	virtual std::string getParameter(int n) override;

	double getSpeed()const;
	void setSpeed(int s);

	double getWingLength() const;
	void setWingLength(int len);
};

