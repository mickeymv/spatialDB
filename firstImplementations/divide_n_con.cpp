#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>

#include "poi2D.h"

using namespace std;

//comparator function
bool compareX(const poi2D &poi1, const poi2D &poi2){
	return poi1.x < poi2.x;
}

//sees if the slope has increases from p2 to p3 when connected to p1
bool slopeIncreased(const poi2D &p1, const poi2D &p2, const poi2D &p3){
	//if p1 to p3 has greater slope return true
	return (((p3.y - p1.y)/(p3.x - p1.x)) > ((p2.y - p1.y)/(p2.x - p1.x)));
}

//used to order hulls of 3 points
vector<poi2D> orderHullClockwise(vector<poi2D> &hull){
	if(hull.size() == 3){
		//orders the points by x and then determines the correct order of the last 2 points
		sort(hull.begin(), hull.end(), compareX);
		if(slopeIncreased(hull[0], hull[1], hull[2])){
			poi2D temp;
			temp = hull[1];
			hull[1] = hull[2];
			hull[2] = temp;
		}
		return hull;
	} else {
		//combiningHulls is used to make hulls larger than 3 or 4
		cout << "	error ordering hull that has more than 4 points" << endl;
	}
}

//prints vector of poi2D's
void printVec(const vector<poi2D> & vec){
	for (vector<poi2D>::iterator it = vec.begin(); it != vec.end(); ++it) {
	    cout << it->toString() << endl;
	}
}

//combining a left and right hull by determining the bottom and top tangents (eliminating unneccesary points)
vector<poi2D> combineHulls(vector<poi2D> &part1, vector<poi2D> &part2){
	//find rightmost point of left and leftmost point of right
	vector<poi2D>::iterator left = max_element(part1.begin(), part1.end(), compareX);
	vector<poi2D>::iterator right = min_element(part2.begin(), part2.end(), compareX);
	vector<poi2D>::iterator tangentTopLeft = left, tangentTopRight = right, tangentBottomLeft = left, tangentBottomRight = right;
	vector<poi2D>::iterator temp;

	//finds the top tangent
	while(true){
		while(true){
			temp = tangentTopLeft;
			//moves iterator backward looping if neccesary
			if(tangentTopLeft == part1.begin()) {tangentTopLeft = part1.end()-1;} else {tangentTopLeft--;}
			if(slopeIncreased(*tangentTopRight, *temp, *tangentTopLeft)){
				tangentTopLeft = temp;
				break;
			} else {
			}
			if(tangentTopLeft == left)
				break;
		}
		bool changed = false;
		while(true){
			temp = tangentTopRight;
			//moves iterator forward looping if neccesary
			if(tangentTopRight == part2.end()-1) {tangentTopRight = part2.begin();} else {tangentTopRight++;}
			if(!slopeIncreased(*tangentTopLeft, *temp, *tangentTopRight)){
				tangentTopRight = temp;
				break;
			} else {
				changed = true;
			}
			if(tangentTopRight == right)	break;
		}
		if(!changed)
			break;
	}

	//finds the bottom tangent
	while(true){
		//moves iterator backward looping if neccesary
		while(true){
			temp = tangentBottomLeft;
			//moves iterator backward looping if neccesary
			if(tangentBottomLeft == part1.end()-1) {tangentBottomLeft = part1.begin();} else {tangentBottomLeft++;}
			if(!slopeIncreased(*tangentBottomRight, *temp, *tangentBottomLeft)){
				tangentBottomLeft = temp;
				break;
			} else {
			}
			if(tangentBottomLeft == left) break;
		}
		bool changed = false;
		//moves iterator forward looping if neccesary
		while(true){
			temp = tangentBottomRight;
			//moves iterator forward looping if neccesary
			if(tangentBottomRight == part2.begin()) {tangentBottomRight = part2.end()-1;} else {tangentBottomRight--;}
			if(slopeIncreased(*tangentBottomLeft, *temp, *tangentBottomRight)){
				tangentBottomRight = temp;
				break;
			} else {
				changed = true;
			}
			if(tangentBottomRight == right) break;
		}
		if(!changed)
			break;
	}

	//combining the left and right keeping clockwise ordering
	vector<poi2D> finalHull;
	if(tangentBottomLeft > tangentTopLeft){
		finalHull.insert(finalHull.end(), tangentBottomLeft, part1.end());
		finalHull.insert(finalHull.end(), part1.begin(), tangentTopLeft+1);
	} else {
		finalHull.insert(finalHull.end(), tangentBottomLeft, tangentTopLeft+1);
	}
	if(tangentTopRight > tangentBottomRight){
		finalHull.insert(finalHull.end(), tangentTopRight, part2.end());
		finalHull.insert(finalHull.end(), part2.begin(), tangentBottomRight+1);
	} else {
		finalHull.insert(finalHull.end(), tangentTopRight, tangentBottomRight+1);
	}
	return finalHull;

}



//recursive divide and Conquer function
vector<poi2D> divideAndConquer(vector<poi2D> &vec){
	int size = vec.size();
	if(size < 3){ //base case of 2 points
		return vec;
	} else if(size < 4) { //base case of 3 points
		return(orderHullClockwise(vec));
	}
	sort(vec.begin(), vec.end(), compareX);
	vector<poi2D> part1(vec.begin(), vec.begin() + size/2), part2(vec.begin() + size/2, vec.end()); //splitting into left and right parts
	part1 = divideAndConquer(part1); //computing the left hull
	part2 = divideAndConquer(part2); //computing the right hull
	return combineHulls(part1, part2); //combining the hulls
}

int main(){
	vector<poi2D> input;
	ifstream infile;
	infile.open("points.bin",ios::binary|ios::in);

	poi2D fileRead;

	while(infile.read((char *)&fileRead,sizeof(poi2D)))
	{
	  input.push_back(fileRead);
	}

	infile.close();
	

	printVec(divideAndConquer(input));
}
