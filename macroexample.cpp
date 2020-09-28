// macroexample.cpp
//
// by Michael G. Workman
//
// This C++ program is freely distributable 
// under terms of MIT open source license
// https://opensource.org/licenses/MIT

#ifndef PI

#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

#define PI	3.14159265358979

#define AREA(r)	(PI*(r)*(r))

#define CIRCUMFERENCE(r) (PI*(2)*(r))

#define PRINTLINES(count) \
	for (int i=1;i <= count;i++) { \
		cout << "Line " << i << endl; \
	}

#endif

// function to check if number input is an actual number
bool isNumber(char* input)
{
	// get the length of the char array string
	int len = *(&input +1) - input;

	// loop through the char array checking each index is a digit
	for (int i=0;i < len;i++)
	{
		if (isdigit(input[i]) == false)
		{
			return false;
		}
	}

	return true; 
}

int main(int argc, char** argv)
{
	// check to make sure argument format is correct
	bool errorPresent = false;

	// check that there is at least 3 arguments
	if (argc < 3)
	{
		errorPresent = true;
	}

	// check that the second argument is a valid number, remember with arrays the first index is 0
	if ((!errorPresent) && (!isNumber(argv[1])))
	{
		errorPresent =  true;
	}

	// check that the third argument is a valid unit of measurement
	if ((!errorPresent) && (strcmp(argv[2],"inches") != 0)
		&& (strcmp(argv[2],"centimeters") != 0)
		&& (strcmp(argv[2],"yards") != 0)
		&& (strcmp(argv[2],"meters") != 0))
	{
		errorPresent = true;
	}

	// output the proper format if there is an error
	// return an error code
	if (errorPresent)
	{
		cout << endl << "Format:" << endl;
		cout << "./example [number length of radius] [unit of measurement]" 
			<< endl;
		cout << "Valid Units of Measurement: inches centimeters yards meters" 
			<< endl << endl;	

		// return a non-zero number for an error
		return 1;
	}

	// unit of measurement
	char* units = argv[2];

	// radius of the circle
	double radius = atoi(argv[1]);

	// get the area of the circle
	double area = AREA(radius);

	// get the circumference of the circle
	double circumference = CIRCUMFERENCE(radius);

	// constant PI
	cout << "PI: " << PI << endl;

	// area of a circle
	cout << "AREA CIRCLE radius=" << radius << " " << units 
		<< ", " << area << " square " << units << endl;

	// circumference of a circle
	cout << "CIRCUMFERENCE CIRCLE radius=" << radius << " " 
		<< units << ", " << circumference << " " << units << endl;
	
	// convert units
	if (strcmp(units,"yards") == 0)
	{
		cout << "AREA in inches squared: " 
			<< area*36*36 << endl;

		cout << "CIRCUMFERENCE in inches: " 
			<< circumference*36 << endl;

	}
	else if (strcmp(units, "meters") == 0)
	{
		cout << "AREA in centimeters squared: " 
			<< area*100*100 << endl;

		cout << "CIRCUMFERENCE in centimeters: " 
			<< circumference*100 << endl;
	}

	// print out number of lines
	double numberLines = atoi(argv[1]);
	cout << "Print Out " << numberLines << " Lines" << endl;
	PRINTLINES(numberLines);

	// when we get to this point it means there were no errors, 
	// so we return 0 for no errors
	return 0;

}
