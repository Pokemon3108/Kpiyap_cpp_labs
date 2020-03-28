#pragma once
#include "pch.h"
#include <string>
#include "InputError.h"

using std::cout;
using std::endl;
using std::cin;


class Transport abstract
{
protected:
	std::string colour;
	int maximumWeight;
	std::string number;
public:
	Transport() : maximumWeight(0)
	{
		//std::cout << "Constructor Transport" << std::endl;
	};
	Transport(std::string cl, int weight, std::string num) : colour(cl), maximumWeight(weight), number(num)
	{
		//std::cout << "Constructor Transport" << std::endl;
	};
	Transport(const Transport& obj) : colour(obj.colour), maximumWeight(obj.maximumWeight)
	{
		//std::cout << "Constructor Transport" << std::endl;
	};

	virtual ~Transport()
	{
		//std::cout << "Destructor Transport" << std::endl;
	};

	friend std::istream& operator >> (std::istream& in, Transport& obj);
	friend std::ostream& operator << (std::ostream& out, const Transport& obj);
	friend std::ifstream& operator >> (std::ifstream& in, Transport& obj);
	friend std::ofstream& operator << (std::ofstream& out, const Transport& obj);
	//friend std::fstream& operator >> (std::fstream& in, Transport& obj);
	//friend std::fstream& operator << (std::fstream& out, Transport& obj);

	void readBF(std::ifstream& in);
	void writeBF(std::ofstream& out);

	bool operator !=(Transport& obj);
	bool operator ==(Transport& obj);
	Transport& operator = (Transport&obj);
	bool operator >(Transport& obj);
	bool operator <(Transport& obj);

	virtual void table(std::ostream&out);
	virtual void chooseParameters();
	virtual std::string getParameter(int n);

	void setColour(std::string cl);
	std::string getColour() const;

	void setNumber(std::string num);
	std::string getNumber() const;

	void setMaximumWeight(int weight);
	int getMaximumWeight() const;

};


