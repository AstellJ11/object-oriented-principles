#pragma once
#include "Shape.h"
#include "Movable.h"
#include <ostream>


class Square : public Shape, public Movable
{
public:

	int edge;

	Square()		// Default constructor
	{
		int x = 0;
		int y = 0;
		int height = 0;
		int width = 0;
	}

	Square(int x, int y, int edge);

	void calculateArea(int edge);
	void calculatePerimeter(int edge);
	void calculatePoints(int x, int y, int edge);
	void move(int x, int y);
	void scale(float scaleX, float scaleY);
	void toString();

};