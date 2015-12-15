#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "poi2D.h"

using namespace std;

int main(){
	vector<poi2D> input;
	ifstream infile;
	infile.open("points.bin",ios::binary|ios::in);

	poi2D fileRead;

	while(infile.read((char *)&fileRead,sizeof(poi2D)))
	{
	  cout << fileRead.toString() << endl;
	}
}
