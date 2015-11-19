#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <ctime>

#include "poi2D.h"

using namespace std;



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

void generateRandom(int number, double max){
	poi2D point;
	ofstream myfile;
	myfile.open ("points.bin", ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		point.x = ((double)rand() / RAND_MAX)*max;
		point.y = ((double)rand() / RAND_MAX)*max;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

int main() {
	srand ( time(0) );
	generateRandom(1000000, 100.0);
    return 0;
}