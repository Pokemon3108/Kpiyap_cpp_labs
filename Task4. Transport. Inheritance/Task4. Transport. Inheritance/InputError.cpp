#include "pch.h"
#include "InputError.h"
#include <string>

using std::endl;
using std::cerr;


void inputLetters(std::istream& in, std::string & str) throw(InputError &)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			std::getline(in, str);
			for (size_t i = 0; i < str.length(); ++i)
			{
				if (!isalpha(str[i]) && str[i] != ' ')
				{
					throw InputError(3, "There are not only letters in string");
				}
			}
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Code:" << exception.getCode() << endl << "Description:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}





int InputError::getCode()
{
	return code;
}


void inputLettersAndNumbers(std::istream& in, std::string & str) throw(InputError &)
{
	bool flag;
	do
	{
		try
		{
			flag = 1;
			rewind(stdin);
			std::getline(in, str);
			for (size_t i = 0; i < str.length(); ++i)
			{
				
				if ((!isalpha(str[i]) && (str[i] < '0' || str[i]>'9')) && str[i] != ' ')
				{
					
					throw InputError(4, "There are not only letters and numbers in string");
				}
			}
		}
		catch (InputError& exception)
		{
			flag = 0;
			cerr << "Code:" << exception.getCode() << endl << "Description:" << exception.what() << endl;
			str.clear();
		}
	} while (!flag);
}