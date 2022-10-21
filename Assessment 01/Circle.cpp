#include "Circle.h"
#include "Shape.h"
#include "Point.h"
#include "Movable.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
using namespace std;

Circle::Circle(int x, int y, int radius) : radius(radius)
{
	calculateArea(radius);
	calculatePerimeter(radius);
	calculatePoints(x, y, radius);

};

void Circle::calculateArea(int radius)
{
	if (radius > 0)
	{
		area = M_PI * (pow(radius, 2));
		area = round(area * 10) / 10;
	}

	else
	{
		cout << "A positive value is required for radius, please try again." << endl;
	}

};

void Circle::calculatePerimeter(int radius)
{
	perimeter = 2 * M_PI * radius;
	perimeter = round(perimeter * 10) / 10;

};

void Circle::calculatePoints(int x, int y, int radius)
{
	Shape allPoints;

	Point leftTop(x, y);
	allPoints.addCoord(leftTop);
	Point rightBottom(x + (2*radius), y + (2*radius));
	allPoints.addCoord(rightBottom);

	cout << "Points[(" << allPoints.getCoord(0).getX() << "," << allPoints.getCoord(0).getY() << ")(";
	cout << allPoints.getCoord(1).getX() << "," << allPoints.getCoord(1).getY() << ")]" << endl;

};

void Circle::scale(float x, float y)
{
	if (radius > 0)
	{
		radius = radius * x;
		radius = radius * y;

		/*Point leftTop = points.*/

		calculateArea(radius);
		calculatePerimeter(radius);
		calculatePoints(leftTop.x, leftTop.y, radius);
	}

	else
	{
		cout << "A positive value is required for scale, please try again." << endl;
	}

};

void Circle::move(int x, int y)
{
	calculatePoints(x, y, radius);

};

void Circle::toString()
{
	while (radius > 0)
	{
		cout << "Circle[r=" << radius << "]\n";
		cout << "Area=" << area << " Perimeter=" << perimeter << endl;

		break;
	}

};
