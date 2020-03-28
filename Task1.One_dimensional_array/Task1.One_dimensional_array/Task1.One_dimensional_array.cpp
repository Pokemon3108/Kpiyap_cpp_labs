#include "pch.h"
#include "Array.h"
#include <iostream>

int main()
{
	int size1, size2, choice1;
	do
	{
		std::cout << "\n1-Enter sizes of array" << std::endl
			<< "2-Exit" << std::endl;
		std::cin >> choice1;
		if (choice1 == 2) return 0;

		Array array1,array2,newarray;
		std::cout << "Size1=";
		std::cin >> array1;
        std::cout << "Size2=";
		std::cin >> array2;
		
        newarray = array1 % array2;
		std::cout << "\nThe array after intersection" << std::endl;
		std::cout << newarray;

		newarray = array1 + array2;
		std::cout << "\nThe array after merge" << std::endl;
		std::cout << newarray;

		std::cout << "\nOperations together:" << std::endl;
		newarray = array1 % array2 + array1;
		std::cout << newarray;

	} while (true);



}
