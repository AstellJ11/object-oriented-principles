#include "Square.h"
#include "Shape.h"
#include "Point.h"
#include "Movable.h"
using namespace std;

Square::Square(int x, int y, int edge) : edge(edge)
{
	calculateArea(edge);
	calculatePerimeter(edge);
	calculatePoints(x, y, edge);

};

void Square::calculateArea(int edge)
{
	if (edge > 0)
	{
		area = edge * edge;
	}

	else
	{
		cout << "A positive value is required for edge, please try again." << endl;
	}
};

void Square::calculatePerimeter(int edge)
{
	perimeter = edge * 4;

};

void Square::calculatePoints(int x, int y, int edge)
{
	Shape allPoints;

	Point leftTop(x, y);
	allPoints.addCoord(leftTop);

	Point rightTop(x + edge, y);
	allPoints.addCoord(rightTop);

	Point rightBottom(x + edge, y + edge);
	allPoints.addCoord(rightBottom);

	Point leftBottom(x, y + edge);
	allPoints.addCoord(leftBottom);

	cout << "Points[(" << allPoints.getCoord(0).getX() << "," << allPoints.getCoord(0).getY() << ")(";
	cout << allPoints.getCoord(1).getX() << "," << allPoints.getCoord(1).getY() << ")(";
	cout << allPoints.getCoord(2).getX() << "," << allPoints.getCoord(2).getY() << ")(";
	cout << allPoints.getCoord(3).getX() << "," << allPoints.getCoord(3).getY() << ")]" << endl;

};

void Square::scale(float scaleX, float scaleY)
{
	if (scaleX > 0 && scaleY > 0) {
		edge = edge * scaleX;

		calculateArea(edge);
		calculatePerimeter(edge);
		calculatePoints(leftTop.x, leftTop.y, edge);
	}

	else {
		cout << "A positive value is required for scale, please try again." << endl;
	}
};

void Square::move(int x, int y)
{
	calculatePoints(x, y, edge);

};

void Square::toString()
{
	while (edge > 0)
	{
		cout << "Square[e=" << edge << "]\n";
		cout << "Area=" << area << " Perimeter=" << perimeter << endl;

		break;
	}

};
