#include "Shape.h"
#include "Rectangle.h"
#include "Point.h"
#include "Movable.h"
#include <iostream>
#include <set>
#include <string>
#include <iosfwd>
using namespace std;

Rectangle::Rectangle(int x, int y, int height, int width) : height(height), width(width)
{
	calculateArea(height, width);
	calculatePerimeter(height, width);
	calculatePoints(x, y, height, width);

};

void Rectangle::calculateArea(int height, int width)
{
	if (height > 0 && width > 0) 
	{		// Exception handling to make sure a positive value of height and width exists
		area = height * width;		// Calculating the area
	}

	else 
	{
		cout << "A positive value is required for height and/or width, please try again." << endl;
	}

};

void Rectangle::calculatePerimeter(int height, int width)
{
	perimeter = (height + width) * 2;	// Calculating the perimeter

};

void Rectangle::calculatePoints(int x, int y, int height, int width)
{
	Shape allPoints;

	Point leftTop(x, y);
	allPoints.addCoord(leftTop);

	Point rightTop(x + width, y);
	allPoints.addCoord(rightTop);

	Point rightBottom(x + width, y + height);
	allPoints.addCoord(rightBottom);

	Point leftBottom(x, y + height);
	allPoints.addCoord(leftBottom);

	cout << "Points[(" << allPoints.getCoord(0).getX() << "," << allPoints.getCoord(0).getY() << ")(";
	cout << allPoints.getCoord(1).getX() << "," << allPoints.getCoord(1).getY() << ")(";
	cout << allPoints.getCoord(2).getX() << "," << allPoints.getCoord(2).getY() << ")(";
	cout << allPoints.getCoord(3).getX() << "," << allPoints.getCoord(3).getY() << ")]" << endl;

};

void Rectangle::scale(float scaleX, float scaleY)
{
	if (scaleX > 0 && scaleY > 0) {
		height = height * scaleX;
		width = width * scaleY;

		calculateArea(height, width);
		calculatePerimeter(height, width);
		calculatePoints(leftTop.x, leftTop.y, height, width);
	}

	else {
		cout << "A positive value is required for scale, please try again." << endl;
	}

};

void Rectangle::move(int x, int y)
{
	calculatePoints(x, y, height, width);	// Calls back to calculatePoints with the new x, y coordinates

};

void Rectangle::toString()
{
	while (height > 0 && width > 0)
	{
		cout << "Rectangle[h=" << height << ",w=" << width << "]\n";
		cout << "Area=" << area << " Perimeter=" << perimeter << endl;

		break;
	}

};


