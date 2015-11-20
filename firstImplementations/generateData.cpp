#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#include "poi2D.h"

using namespace std;


//generates data in perfect circle
void generateInCircle(int number, double radius){
	poi2D point;
	ofstream myfile;
	myfile.open ("points.bin", ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX);
		point.x = cos(angle) * radius;
		point.y = sin(angle) * radius;
		cout << point.toString() << endl;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates data where points are all close to the shapes border
void generateCloseToCricle(int number, double radius){
	poi2D point;
	ofstream myfile;
	myfile.open ("points.bin", ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX)*44/7;
		point.x = cos(angle) * radius;
		point.y = sin(angle) * radius;
		point.x += (sqrt((double)rand() / RAND_MAX)-1) * radius/2;
		point.y += (sqrt((double)rand() / RAND_MAX)-1) * radius/2;
		cout << point.toString() << endl;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates random set of data in a square
void generateRandom(int number, double max){
	poi2D point;
	ofstream myfile;
	myfile.open ("points.bin", ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		point.x = ((double)rand() / RAND_MAX)*max;
		point.y = ((double)rand() / RAND_MAX)*max;
		cout << point.toString() << endl;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

int main(int argc, char* argv[]) {
	srand ( time(0) );	//seed rand using time
	generateCloseToCricle(120, 100.0); //
    return 0;
}