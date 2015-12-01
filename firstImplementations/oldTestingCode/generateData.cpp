#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstdlib>

#include "poi2D.h"

using namespace std;

//generates data in perfect circle
void generateOnCircle(int number, double radius, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX);
		point.x = cos(angle) * radius;
		point.y = sin(angle) * radius;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

void generateInCircle(int number, double radius, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX);
		point.x = cos(angle) * ((double)rand() / RAND_MAX) * radius;
		point.y = sin(angle) * ((double)rand() / RAND_MAX) * radius;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates data where points are all close to the shapes border
void generateCloseToCricle(int number, double radius, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX)*44/7;
		point.x = cos(angle) * radius;
		point.y = sin(angle) * radius;
		point.x += (sqrt((double)rand() / RAND_MAX)-0.5) * radius/2;
		point.y += (sqrt((double)rand() / RAND_MAX)-0.5) * radius/2;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates random set of data in a square
void generateInSquare(int number, double max, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		point.x = ((double)rand() / RAND_MAX)*max;
		point.y = ((double)rand() / RAND_MAX)*max;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates random set of data in a square
void generateOnSquare(int number, double max, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		if(rand() % 2){	//generates points along the top and bottom of the square
			if(rand() % 2){
				point.x = ((double)rand() / RAND_MAX)*max;
				point.y = max;
			} else {
				point.x = ((double)rand() / RAND_MAX)*max;
				point.y = 0.0;
			}
		} else {	//generates points along the sides of the square
			if(rand() % 2){
				point.x = max;
				point.y = ((double)rand() / RAND_MAX)*max;
			} else {
				point.x = 0.0;
				point.y = ((double)rand() / RAND_MAX)*max;
			}
		}
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

//generates random set of data in a square
void generateCloseToSquare(int number, double max, char* filename){
	poi2D point;
	ofstream myfile;
	myfile.open(filename, ios::out | ios::binary);
	for(int i = 0; i < number; i++){
		if(rand() % 2){	//generates points along the top and bottom of the square
			if(rand() % 2){
				point.x = ((double)rand() / RAND_MAX)*max;
				point.y = max;
			} else {
				point.x = ((double)rand() / RAND_MAX)*max;
				point.y = 0.0;
			}
		} else {	//generates points along the sides of the square
			if(rand() % 2){
				point.x = max;
				point.y = ((double)rand() / RAND_MAX)*max;
			} else {
				point.x = 0.0;
				point.y = ((double)rand() / RAND_MAX)*max;
			}
		}
		//adding spread to the points away from the square edges
		point.x += (sqrt((double)rand() / RAND_MAX)-0.5) * max/2;
		point.y += (sqrt((double)rand() / RAND_MAX)-0.5) * max/2;
		myfile.write((char*)&point, sizeof(poi2D));
	}
	myfile.close();
}

/*
gen [filename] [int n] [double r] <s> <o>
	filename= file for saving the points
	n=number of points
	r=range points
	s=(optional: designates shape points go inside: s=square, c=circle)
	o=(optional: designates points as: e=exactly on shape edge, c=close to shape edge)
*/

int main(int argc, char* argv[]) {
	srand ( time(0) );	//seed rand using time
	if(argc == 4)
		generateInSquare(atoi(argv[2]), atof(argv[3]), argv[1]);
	else if (argc == 5){	//in case o is not provided points generated inside the shape
		if(string(argv[4]) == "-s")
			generateInSquare(atoi(argv[2]), atof(argv[3]), argv[1]);
		if(string(argv[4]) == "-c")
			generateInCircle(atoi(argv[2]), atof(argv[3]), argv[1]);
	}
	else if (argc == 6){	//in case o is provided points are generated either on the shape's edge or close to the shape's edge
		if(string(argv[5]) == "-c"){
			if(string(argv[4]) == "-s")
				generateCloseToSquare(atoi(argv[2]), atof(argv[3]), argv[1]);
			if(string(argv[4]) == "-c")
				generateCloseToCricle(atoi(argv[2]), atof(argv[3]), argv[1]);
		} else if(string(argv[5]) == "-e"){
			if(string(argv[4]) == "-s")
				generateOnSquare(atoi(argv[2]), atof(argv[3]), argv[1]);
			if(string(argv[4]) == "-c")
				generateOnCircle(atoi(argv[2]), atof(argv[3]), argv[1]);
		}
	}
    return 0;
}