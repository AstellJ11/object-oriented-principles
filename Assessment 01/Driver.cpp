/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment edited by James Astell 
Fall 2019

Orignal written by Ayse Kucukyilmaz

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // This one will hold your shapes
	vector <string> parameters; // This one will hold parameters for the commands
	vector <string> tokens;	// This one will hold tokens

	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";	// Asking the user for input

		parameters.clear();	// Clearing the paramters at the start of each loop to allow new input each time

		getline(cin, userCommand);	// Getting the users input

		char* cstr = new char[userCommand.length() + 1];	// A new character string is created here from the users input

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());	// strcpy_s is a function that copies characters from a string to a destination char array including null charcters

		char delim[] = " ";	// Declaring what the break character is in order to split the input up
		char* next_token = NULL;

		char* token = strtok_s(cstr, delim, &next_token);	// strtok_s is a function that finds the next token in the string after the defined delim

		while (token != NULL)	// Loops until the input has all been passed through
		{
			parameters.push_back(token);
			token = strtok_s(NULL, delim, &next_token);	// Parameters for the strtok_s function
			
		}

		if (parameters.empty())		// Exception handling to stop the user from entering nothing
		{
			cout << "No input entered, please try again" << endl;
			continue;
		}

		string command = parameters[0];		// Usercommand is now stored seperatly in the parameters

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the the parameters vector contains ascii values

			string string_x = parameters[1];	// Assigning each of the seperated parameters into strings
			string string_y = parameters[2];
			string string_h = parameters[3];
			string string_w = parameters[4];

			int x = stoi(string_x);		// stoi is a function that converts form string to int
			int y = stoi(string_y);		// This is done for every input
			int h = stoi(string_h);
			int w = stoi(string_w);

			Rectangle* r = new Rectangle(x, y, h, w);	// A new rectanlge object is created and passes the parameters to the rectangle class
			shapes.push_back(r);		// Adds the newly created shape to the end of the shapes vector
			r->toString();		/* instead of this, you may implement operator overloadig and
									//use cout << r which will give you additional points */
		}

			else if (command.compare("addS") == 0) {

				string string_x = parameters[1];
				string string_y = parameters[2];
				string string_e = parameters[3];

				int x = stoi(string_x);
				int y = stoi(string_y);
				int e = stoi(string_e);

				Square* s = new Square(x, y, e);
				shapes.push_back(s);
				s->toString();

			}

			else if (command.compare("addC") == 0) {		 // Changed to 'else if' instead of 'if'

				string string_x = parameters[1];
				string string_y = parameters[2];
				string string_r = parameters[3];

				int x = stoi(string_x);
				int y = stoi(string_y);
				int r = stoi(string_r);

				Circle* c = new Circle(x, y, r);
				shapes.push_back(c);
				c->toString();
				
			}

			else if (command.compare("scale") == 0) {
				// scale object at index... the scaling needs to be isotropic in case of circle and square 
				// you may want to check if the index exists or not!
				
				// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
				// As a result all your derived classes have scale functions... 
				// You may need to use type casting wisely to use polymorphic functionality!

				string string_shapeNo = parameters[1];	// index should point and select a certain shape
				string string_x = parameters[2];
				string string_y = parameters[3];

				int shapeNo = stoi(string_shapeNo);
				int scaleX = stoi(string_x);
				int scaleY = stoi(string_y);

				Movable* s = nullptr;		// Creates an empty nulltpr to allow dynamic_cast
				s = dynamic_cast<Movable*>(shapes[shapeNo - 1]);	// Converts the new pointer and calls the class. ShapeNo-1 as the first shape starts with 0
				s->scale(scaleX, scaleY);	// Calls the scale function in the relevant class

				shapes[shapeNo - 1]->toString();	// Runs the new values through toString 	                                                                                                               
			}



			else if (command.compare("move") == 0) {
				// move object at index 

				string string_shapeNo = parameters[1];
				string string_x = parameters[2];
				string string_y = parameters[3];

				int shapeNo = stoi(string_shapeNo);
				int moveX = stoi(string_x);
				int moveY = stoi(string_y);

				// Study the following code. A Shape object is not Movable, but all derived classes are...
				// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
				Movable* m = nullptr;
				m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
				m->move(moveX, moveY);

				// note that here you should see the corresponding toString output for the derived classes...
				// if toString is not a virtual function, you may see the base class functionality :(
				shapes[shapeNo - 1]->toString();

			}

			else if (command.compare("display") == 0) {
			for (Shape* ptr : shapes) // Loop to display all shapes created and stored in the vector
			{

				Shape& shape = *ptr; // Dereferences the ptr variable 
				shape.toString();	// Calling the toString function for all of the stored shapes to display them
				cout << endl;	// Line break to make seeing the seperate shapes easier

			}

			}

			else
			{
			cout << "'" << userCommand << "'" << " is not a valid input, please try again." << endl;	// Exception handling if the user doesn't enter a valid input

			}

			cout << endl << endl;
	}

	cout << "Press any key to continue...";		// Exit route for the user
	getchar();

	return 0;
}
