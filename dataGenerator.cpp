#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string.h>


#include "poi2D.h"
#include "Number.h"
#include "ConvexHull.h"


using namespace std;

//prints vector of poi2D's
void saveVec(vector<poi2D>& vec, char* filename){
	ofstream myfile;
	myfile.open(filename);
	for (vector<poi2D>::iterator it = vec.begin(); it != vec.end(); ++it) {
	    myfile << it->toString() + "\n";
	}
	myfile.close();
}

//generates data in perfect circle
vector<poi2D> generateOnCircle(int number, double radius){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX);
		x = cos(angle) * radius;
		y = sin(angle) * radius;
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

vector<poi2D> generateInCircle(int number, double radius){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX);
		x = cos(angle) * ((double)rand() / RAND_MAX) * radius;
		y = sin(angle) * ((double)rand() / RAND_MAX) * radius;
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

//generates data where points are all close to the shapes border
vector<poi2D> generateCloseToCricle(int number, double radius){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		double angle = ((double)rand() / RAND_MAX)*44/7;
		x = cos(angle) * radius;
		y = sin(angle) * radius;
		x += (sqrt((double)rand() / RAND_MAX)-0.5) * radius/2;
		y += (sqrt((double)rand() / RAND_MAX)-0.5) * radius/2;
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

//generates random set of data in a square
vector<poi2D> generateInSquare(int number, double max){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		x = ((double)rand() / RAND_MAX)*max;
		y = ((double)rand() / RAND_MAX)*max;
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

//generates random set of data in a square
vector<poi2D> generateOnSquare(int number, double max){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		if(rand() % 2){	//generates points along the top and bottom of the square
			if(rand() % 2){
				x = ((double)rand() / RAND_MAX)*max;
				y = max;
			} else {
				x = ((double)rand() / RAND_MAX)*max;
				y = 0.0;
			}
		} else {	//generates points along the sides of the square
			if(rand() % 2){
				x = max;
				y = ((double)rand() / RAND_MAX)*max;
			} else {
				x = 0.0;
				y = ((double)rand() / RAND_MAX)*max;
			}
		}
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

//generates random set of data in a square
vector<poi2D> generateCloseToSquare(int number, double max){
	poi2D point;
	vector<poi2D> points;
	double x, y;
	for(int i = 0; i < number; i++){
		if(rand() % 2){	//generates points along the top and bottom of the square
			if(rand() % 2){
				x = ((double)rand() / RAND_MAX)*max;
				y = max;
			} else {
				x = ((double)rand() / RAND_MAX)*max;
				y = 0.0;
			}
		} else {	//generates points along the sides of the square
			if(rand() % 2){
				x = max;
				y = ((double)rand() / RAND_MAX)*max;
			} else {
				x = 0.0;
				y = ((double)rand() / RAND_MAX)*max;
			}
		}
		//adding spread to the points away from the square edges
		x += (sqrt((double)rand() / RAND_MAX)-0.5) * max/2;
		y += (sqrt((double)rand() / RAND_MAX)-0.5) * max/2;
		point.x = Number(to_string(x));
		point.y = Number(to_string(y));
		points.push_back(point);
	}
	return points;
}

/*
gen [int n] [double r] <s> <o>
	n=number of points
	r=range points
	s=(optional: designates shape points go inside: s=square, c=circle)
	o=(optional: designates points as: e=exactly on shape edge, c=close to shape edge)
*/

int main(int argc, char* argv[]) {
	srand ( time(0) );	//seed rand using time
	if(argc < 4)
		cout << "not enough arguments" << endl;
	vector<poi2D> input;
	if(argc == 4){
		input = generateInSquare(atoi(argv[2]), atof(argv[3]));
	} else if (argc == 5){	//in case o is not provided points generated inside the shape
		if(string(argv[4]) == "-s")
			input = generateInSquare(atoi(argv[2]), atof(argv[3]));
		if(string(argv[4]) == "-c")
			input = generateInCircle(atoi(argv[2]), atof(argv[3]));
	}
	else if (argc == 6){	//in case o is provided points are generated either on the shape's edge or close to the shape's edge
		if(string(argv[5]) == "-c"){
			if(string(argv[4]) == "-s")
				input = generateCloseToSquare(atoi(argv[2]), atof(argv[3]));
			if(string(argv[4]) == "-c")
				input = generateCloseToCricle(atoi(argv[2]), atof(argv[3]));
		} else if(string(argv[5]) == "-e"){
			if(string(argv[4]) == "-s")
				input = generateOnSquare(atoi(argv[2]), atof(argv[3]));
			if(string(argv[4]) == "-c")
				input = generateOnCircle(atoi(argv[2]), atof(argv[3]));
		}
	}
	vector<poi2D> result;
	clock_t begin = clock(); //start clock

	if(string(argv[1]) == "divideconquer"){
		cout << "you choose computeDivideConquer" << endl;
		result = computeDivideConquer(input);
	}
	else if(string(argv[1]) == "jarvis"){
		cout << "you choose computeJarvis" << endl;
		result = computeJarvis(input);
	}
	else if(string(argv[1]) == "graham"){
		cout << "you choose computeGraham" << endl;
		result = computeGraham(input);
	}
	// else if(string(argv[1]) == "quick"){
	// 	cout << "you choose computeQuick" << endl;
	// 	result = computeQuick(input);
	// }
	else if(string(argv[1]) == "newalgo"){
		cout << "you choose computeNewAlgo" << endl;
		result = computeNewAlgo(input);
	}
	else
		cout << "algorithm not found" << endl;

	clock_t end = clock(); //end clock

	double elapsed_secs = double(end - begin);
	cout << "time elapsed: " << elapsed_secs / (CLOCKS_PER_SEC / 1000) << "ms"  << endl;
	// cout << elapsed_secs / (CLOCKS_PER_SEC / 1000) << endl;

	saveVec(input, (char*)"test_in");
	saveVec(result, (char*)"test_out");
    return 0;
}