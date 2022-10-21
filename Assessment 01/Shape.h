#pragma once
#include "Point.h"
#include "Shape.h"
#include <set>
#include <vector>
using namespace std;

class Shape
{
public:
	float area;		// Declaring variables for use
	bool isCircular;
	Point leftTop;
	float perimeter;
	vector<Point>points;	

	void addCoord(Point &coord)		// Adding the user inputted coordinates to the Point class which contains x and y
	{ 
		points.push_back(coord);		// Using push_back to add them the the vector
	}

	Point getCoord(int index) 		 // Allows the vector coordinates to be returned and displayed
	{ 
		return points[index]; 
	}


	virtual void calculateArea() {};	// All declared and overriden in base classes
	virtual void calculatePerimeter() {};
	virtual void calculatePoints() {};
	virtual void toString() {};

};

