#pragma once
#include "Tractor.h"
#include "Bus.h"
#include "Plane.h"
#include "Helicopter.h"
#include "Submarine.h"
#include "SailBoat.h"
#include "pch.h"
#include <string>

class Functor
{
private:
	std::set<std::string> setFields;

public:
	Functor() {};
	~Functor() {};

	int operator()(Transport& obj1, Transport& obj2);
	int operator()(GroundTransport& obj1, GroundTransport& obj2);
	int operator()(WaterTransport& obj1, WaterTransport& obj2);
	int operator()(AirTransport& obj1, AirTransport& obj2);

	bool operator()(Bus& obj1, Bus& obj2);
	bool operator()(Tractor& obj1, Tractor& obj2);
	bool operator()(Submarine& obj1, Submarine& obj2);
	bool operator()(SailBoat& obj1, SailBoat& obj2);
	bool operator()(Plane& obj1, Plane& obj2);
	bool operator()(Helicopter& obj1, Helicopter& obj2);

	std::set<std::string>& getSetFields();
};

