#pragma once
#include "Exception.h"
#include <string>


using std::endl;
using std::cerr;

class InputError : public Exception
{
protected:
	int code;
public:
	InputError(int c, std::string text) : Exception(text), code(c)
	{}
	~InputError()
	{};

	int getCode();
};


void inputLetters(std::istream& in, std::string& str) throw (InputError&);
void inputLettersAndNumbers(std::istream& in, std::string& str) throw (InputError&);



template<typename T>
void inputNumber(std::istream& in, T&n, T range1, T range2)
{
	
	bool flag;
	do
	{
		try
		{
			flag = 1;
			
			in >> n;
			if (!in.good() || in.peek()!='\n')
				throw InputError(1, "Input is not a number");
			
			if (n<range1 || n>range2)
				throw InputError(5, "Input number is not in range");

		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Code:" << exception.getCode() << endl << "Description:" << exception.what() << endl;
			in.clear();
			rewind(stdin);
		}
	} while (!flag);
}


//template<typename T>
//void inputPositiveNumber(std::istream& in, T& n) throw(InputError &)
//{
//	bool flag;
//	do
//	{
//		inputNumber(in, n);
//		flag = 1;
//		try
//		{
//			if (n < 0)
//			{
//				flag = 0;
//				throw InputError(2, "Input number is not positive");
//			}
//		}
//		catch (InputError& exception)
//		{
//			cerr << "Code:" << exception.getCode() << endl << "Description:" << exception.what() << endl;
//		}
//	} while (!flag);
//}

