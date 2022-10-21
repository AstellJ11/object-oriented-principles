#pragma once
#include <iostream>

class Point
{
public:

	int x, y;

	Point()		// Default constructor
	{
		x = 0; y = 0;
	}
	Point(int x, int y) : x(x), y(y) 
	{
		// Nothing
	}


	int getX() 	  // Getters to return the values of x when needed
	{ 
		return x; 
	}
	int getY() 
	{ 
		return y;
	} 	
};
