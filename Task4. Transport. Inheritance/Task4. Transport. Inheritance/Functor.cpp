#include "pch.h"
#include "Functor.h"

bool Functor::operator()(Helicopter& obj1, Helicopter& obj2)
{
	int i = (*this)(dynamic_cast<AirTransport&>(obj1), dynamic_cast<AirTransport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "screwNumber" && obj1.getScrewNumber() == obj2.getScrewNumber()) ++i;
		if (str == "frequency" && obj1.getFrequency() == obj2.getFrequency()) ++i;
		if (str == "rad" && obj1.isInRadiusArray(obj1[0])) ++i;
		
	}
	return (i == setFields.size());
}

std::set<std::string>& Functor::getSetFields()
{
	return setFields;
}

int Functor::operator()(Transport & obj1, Transport & obj2)
{
	int i = 0;

	for (std::string str : setFields)
	{
		if (str == "colour" && obj1.getColour() == obj2.getColour()) ++i;
		if (str == "maximumWeight" && obj1.getMaximumWeight() == obj2.getMaximumWeight()) ++i;
		if (str == "number" && obj1.getNumber() == obj2.getNumber()) ++i;
	}
	return i;
}

int Functor::operator()(GroundTransport & obj1, GroundTransport & obj2)
{
	int i = (*this)(dynamic_cast<Transport&>(obj1), dynamic_cast<Transport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "power" && obj1.getPower() == obj2.getPower()) ++i;
		if (str == "wheelNumber" && obj1.getWheelNumber() == obj2.getWheelNumber()) ++i;
	}
	return i;
}

int Functor::operator()(WaterTransport & obj1, WaterTransport & obj2)
{
	int i = (*this)(dynamic_cast<Transport&>(obj1), dynamic_cast<Transport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "typeTransfer" && obj1.getTypeTransfer() == obj2.getTypeTransfer()) ++i;
		if (str == "typeWater" && obj1.getTypeWater() == obj2.getTypeWater()) ++i;
	}
	return i;
}

int Functor::operator()(AirTransport & obj1, AirTransport & obj2)
{
	int i = (*this)(dynamic_cast<Transport&>(obj1), dynamic_cast<Transport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "maximumHeight" && obj1.getMaximumHeight() == obj2.getMaximumHeight()) ++i;
		if (str == "distance" && obj1.getDistance() == obj2.getDistance()) ++i;
	}
	return i;
}

bool Functor::operator()(Bus & obj1, Bus & obj2)
{
	int i= (*this)(dynamic_cast<GroundTransport&>(obj1), dynamic_cast<GroundTransport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "capacity" && obj1.getCapacity() == obj2.getCapacity()) ++i;
		if (str == "seatsNumber" && obj1.getSeatsNumber() == obj2.getSeatsNumber()) ++i;
	}
	return (i == setFields.size());
}

bool Functor::operator()(Tractor & obj1, Tractor & obj2)
{
	int i = (*this)(dynamic_cast<GroundTransport&>(obj1), dynamic_cast<GroundTransport&>(obj2));

	for (auto str : setFields)
	{
		if (str == "tractionClass" && obj1.getTractionClass() == obj2.getTractionClass()) ++i;
	}

	return (i == setFields.size());
}

bool Functor::operator()(Submarine & obj1, Submarine & obj2)
{
	int i = (*this)(dynamic_cast<WaterTransport&>(obj1), dynamic_cast<WaterTransport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "depth" && obj1.getDepth() == obj2.getDepth()) ++i;
	}

	return (i == setFields.size());
}

bool Functor::operator()(SailBoat & obj1, SailBoat & obj2)
{
	int i = (*this)(dynamic_cast<WaterTransport&>(obj1), dynamic_cast<WaterTransport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "sailsNumber" && obj1.getSailsNumber() == obj2.getSailsNumber()) ++i;
	}

	return (i == setFields.size());
}

bool Functor::operator()(Plane & obj1, Plane & obj2)
{
	int i = (*this)(dynamic_cast<AirTransport&>(obj1), dynamic_cast<AirTransport&>(obj2));
	
	for (auto str : setFields)
	{
		if (str == "speed" && obj1.getSpeed() == obj2.getSpeed()) ++i;
		if (str == "wingLength" && obj1.getWingLength() == obj2.getWingLength()) ++i;
	}

	return (i == setFields.size());
}

