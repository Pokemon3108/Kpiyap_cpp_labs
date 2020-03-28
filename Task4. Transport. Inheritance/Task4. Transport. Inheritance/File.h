#pragma once
#include "pch.h"
#include "Tree.h"

using std::ios;

class File
{
protected:
	std::string fileName;
	std::ifstream in;
	std::ofstream out;
public:
	File(const char* name)
	{
		fileName = name;
	};
	~File() {};

	bool isEOFin();
	bool isEOFout();
};

