#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

using namespace std;

struct poi2D
{
	double x;
	double y;

	string toString(){
		ostringstream strs;
		strs << "x:" << x << " y:" << y;
		return strs.str();
	}
};

int main() {
	poi2D point;
	ofstream myfile;
	myfile.open ("points.bin", ios::out | ios::binary);
	for(int i = 0; i < 10; i++){
		point.x = rand()%100;
		point.y = rand()%100;
		cout << point.toString() << endl;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();

    return 0;
}