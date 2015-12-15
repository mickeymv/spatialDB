#ifndef POI2D
#define POI2D

#include <iostream>
#include <sstream>
#include "Number.h"

using namespace std;


struct poi2D
{
	Number x;
	Number y;

	string toString(){
		ostringstream strs;
		strs << x << "	" << y;
		return strs.str();
	}
};
#endif