#include "pch.h"

#include "InputError.h"

using std::cout;
using std::cin;
using std::endl;


int main()
{
	int range1, range2;
	int a;
	double b;
	std::string name;

	cout << "Input name" << endl;
	inputLetters(cin, name);

	cout << "Input range\n";
	cin >> range1 >> range2;

	cout << "Input integer number"<<endl;
	inputNumber(cin,a, range1, range2);
	
	

	
	//cout << "Input positive number"<<endl;
	//inputPositiveNumber(cin,b);

	cout << "Input number of car"<<endl;
	inputLettersAndNumbers(cin, name);

	
	
}

