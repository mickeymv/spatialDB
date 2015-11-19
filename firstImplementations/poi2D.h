#ifndef POI2D
#define POI2D

#include <iostream>
#include <sstream>

using namespace std;


struct poi2D
{
	double x;
	double y;

	string toString(){
		ostringstream strs;
		strs << x << "	" << y;
		return strs.str();
	}
};
#endif