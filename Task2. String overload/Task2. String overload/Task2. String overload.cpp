#include "pch.h"
#include "String.h"


int main()
{
	const char* const_string = "Hello world";
	int flag;
	do
	{
        int start, end;

		std::cout << "Enter 1st string" << std::endl;
		String str1, str2, str3;
		std::cin >> str1;
		std::cout << "Enter 2nd string" << std::endl;
		std::cin >> str2;

		std::cout << std::endl << "Operator == and !=" << std::endl;
		if (str1 == str2) std::cout << "Strings are equal" << std::endl << std::endl;
		else if (str1 != str2)std::cout << "Strings are not equal" << std::endl << std::endl;

		std::cout << "Operators > <" << std::endl;
		if (str1 > str2) std::cout << "String1 has a bigger ASCII-position" << std::endl << std::endl;
		else if (str1 < str2) std::cout << "String2 has a bigger ASCII-position" << std::endl << std::endl;

		std::cout << "Operators + and =" << std::endl;
		str3 = str1 +str2;
		std::cout << str3 << std::endl << std::endl;

		std::cout << "Operator +=" << std::endl;
		str3 += str1;
		std::cout << str3 << std::endl << std::endl;

		std::cout << "Operator ++ (str2=str1++)" << std::endl;
		std::cout << "Before: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl;
		str2 = str1++;
		std::cout << "After: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl << std::endl;


		std::cout << "Operator -- (str2 = str1--)" << std::endl;
		std::cout << "Before: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl;
		str2 = str1--;
		std::cout << "After: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl << std::endl;


		std::cout << "Operator ++ (str2 = ++str1)" << std::endl;
		std::cout << "Before: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl;
		str2 = ++str1;
		std::cout << "After: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl << std::endl;


		std::cout << "Operator -- (str2 = --str1;)" << std::endl;
		std::cout << "Before: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl;
		str2 = --str1;
		std::cout << "After: \n 1st string: " << str1 << std::endl
			<< " 2nd string: " << str2 << std::endl << std::endl;


		std::cout << "Operator ()" << std::endl;
		std::cout << "Choose 2 positions from this string: " << str1 << std::endl;
		std::cin >> start >> end;
		str3 = str1(start, end);
		std::cout << str3 << std::endl << std::endl;


		std::cout << "Operator + with const char*" << std::endl;
		str3 = const_string + str1;
		std::cout << "const+string: " << str3 << std::endl;
		str3 = str1 + const_string;
		std::cout << "string+const: " << str3 << std::endl;


		std::cout << std::endl << "Operator ==  and != with const char*" << std::endl;
		if (str1 == const_string) std::cout << "Strings are equal" << std::endl << std::endl;
		else if (str1 != const_string) std::cout << "Strings are not equal" << std::endl << std::endl;

		std::cout << "Operators > < with const char* (compare const and string1)" << std::endl
			<< "str1=" << str1 << std::endl;
		if (str1 > const_string)
			std::cout << "String1 has a bigger ASCII-position than const string" << std::endl << std::endl;
		else if (str1 < const_string)
			std::cout << "const string has a bigger ASCII-position than String1" << std::endl << std::endl;

		std::cout << "Operator = with const*char" << std::endl;
		str1 = const_string;
		std::cout << "str1=" << str1 << std::endl << std::endl;


		std::cout << "Operator += with const*char" << std::endl;
		str2 += const_string;
		std::cout << "str2=" << str2<<std::endl<<std::endl;

		

		std::cout << "Continue?" << std::endl
			<< "Yes-1" << std::endl
			<< "No-0" << std::endl;
		std::cin >> flag;

	} while (flag);

}

