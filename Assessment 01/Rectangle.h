#pragma once
#include "Shape.h"
#include "Point.h"
#include "Movable.h"


class Rectangle : public Shape, public Movable
{	
public:
	int height;		
	int width;

	Shape allPoints;	// If this is here and not in rectangle.cpp move doesn't work!
	Point* points;


	Rectangle()		// Default constructor
	{
		int x = 0;
		int y = 0;
		int height = 0;
		int width = 0;
	}

	Rectangle(int x, int y, int height, int width);		// Declaring the parameters for the rectangle class

	void calculateArea(int height, int width);		// Creating the functions along with there parameters
	void calculatePerimeter(int height, int width);
	void calculatePoints(int x, int y, int height, int width);
	void move(int x, int y);
	void scale(float scaleX, float scaleY);
	void toString();

};