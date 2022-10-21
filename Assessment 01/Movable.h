#pragma once
#include "Shape.h"

class Movable
{

public:
	int newX, newY;			// New values to be used in the move and scale functions
	float scaleX, scaleY;		   

	virtual void move(int x, int y) {};
	virtual void scale(float scaleX, float scaleY) {};			// Virtual void's being declared in moveable.h

};

