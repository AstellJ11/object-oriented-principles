#pragma once
#include "Shape.h"
#include "Movable.h"


class Circle : public Shape, public Movable
{
public:
	int radius;

	Circle()		// Default constructor
	{
		int x = 0;
		int y = 0;
		int height = 0;
		int width = 0;
	}

	Circle(int x, int y, int radius);

	void calculateArea(int radius);
	void calculatePerimeter(int radius);
	void calculatePoints(int x, int y, int radius);
	void move(int x, int y);
	void scale(float x, float y);
	void toString();

};
