#include "pch.h"
#include <iostream>
#include "Ball.h"
#include "Cylinder.h"
#include "Triangle.h"
#include "Circle.h"

int main()
{
	int i;
	do
	{
		
			
			Shape* trianglePtrShape= new Triangle;
			
			
			std::cout << " Input triangle's line and height: ";
			std::cin >> *trianglePtrShape;
			std::cout << *trianglePtrShape;
			std::cout << " Triangle's square: " << trianglePtrShape->Square() << "\n";
		
		


		Shape* circlePtrShape = new Circle;
		std::cout << " Input circle's radius: ";
		std::cin >> *circlePtrShape;
		std::cout << *circlePtrShape;
		std::cout << " Circle's square: " << circlePtrShape->Square() << "\n";
		delete circlePtrShape;


		Shape* cylinderPtrShape = new Cylinder;
		std::cout << " Input cylinder's radius and height: ";
		std::cin >> *cylinderPtrShape;
		std::cout << *cylinderPtrShape;
		std::cout << " Cylinder's volume: " << (dynamic_cast<ThreeDShape*>(cylinderPtrShape))->Volume() << "\n";
		delete cylinderPtrShape;


		Shape* ballPtrShape = new Ball;
		std::cout << " Input ball's radius: ";
		std::cin >> *ballPtrShape;
		std::cout << *ballPtrShape;
		std::cout << " Ball's volume: " << (dynamic_cast<ThreeDShape*>(ballPtrShape))->Volume() << "\n";
		delete ballPtrShape;

		std::cout << "1-Continue" << std::endl
			<< "0-Stop" << std::endl;
		std::cin >> i;
	} while (i);
	
}