#include "pch.h"
#include "File.h"


bool File::isEOFin()
{
	return in.eof();
}


bool File::isEOFout()
{
	return out.eof();
}