#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

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
void printVec(vector<poi2D> & vec){
	for (vector<poi2D>::iterator it = vec.begin(); it != vec.end(); ++it) {
	    cout << it->toString() << endl;
	}
}

//combinines left and right hull using bottom and top tangents to form a bridge between the hulls
vector<poi2D> combineHulls(vector<poi2D> &part1, vector<poi2D> &part2){
	vector<poi2D>::iterator left_point = max_element(part1.begin(), part1.end(), compareX); //rightmost point in left hull
	vector<poi2D>::iterator right_point = min_element(part2.begin(), part2.end(), compareX); //leftmost point in right hull
	vector<poi2D>::iterator upper_left_point = left_point, upper_right_point = right_point, lower_left_point = left_point, lower_right_point = right_point;
	vector<poi2D>::iterator previous_point; //holds the previous point during CW/CCW iteration

	bool upper_changed = false;
	do // walk up the left and right points (CW & CCW) until tangent is reached
	{
		while(true){
			previous_point = upper_left_point;
			if(upper_left_point == part1.begin()) {upper_left_point = part1.end()-1;} else {upper_left_point--;} //moves iterator backward looping if neccesary
			if(slopeIncreased(*upper_right_point, *previous_point, *upper_left_point)) //break if tangent is no longer decreasing in slope
			{
				upper_left_point = previous_point;
				break;
			}
			if(upper_left_point == left_point) break;
		}
		upper_changed = false;
		while(true){
			previous_point = upper_right_point;
			if(upper_right_point == part2.end()-1) {upper_right_point = part2.begin();} else {upper_right_point++;} //moves iterator forward looping if neccesary
			if(!slopeIncreased(*upper_left_point, *previous_point, *upper_right_point)) //break if tangent is no longer increasing in slope
			{
				upper_right_point = previous_point;
				break;
			} else upper_changed = true;
			if(upper_right_point == right_point){
				upper_changed = false;
				break;
			}
		}
	} while(upper_changed);

	bool lower_changed;
	do // walk down the left and right points (CCW & CW) until tangent is reached
	{
		while(true){
			previous_point = lower_left_point;
			if(lower_left_point == part1.end()-1) {lower_left_point = part1.begin();} else {lower_left_point++;} //moves iterator backward looping if neccesary
			if(!slopeIncreased(*lower_right_point, *previous_point, *lower_left_point)) //break if tangent is no longer decreasing in slope
			{
				lower_left_point = previous_point;
				break;
			}
			if(lower_left_point == left_point) break;
		}
		lower_changed = false;
		while(true){
			previous_point = lower_right_point;
			if(lower_right_point == part2.begin()) {lower_right_point = part2.end()-1;} else {lower_right_point--;} //moves iterator forward looping if neccesary
			if(slopeIncreased(*lower_left_point, *previous_point, *lower_right_point))  //break if tangent is no longer decreasing in slope
			{
				lower_right_point = previous_point;
				break;
			}
			else lower_changed = true;
			if(lower_right_point == right_point){
				lower_changed = false;
				break;
			}
		}
	} while(lower_changed);

	//combining the left and right keeping clockwise ordering
	vector<poi2D> finalHull;
	if(lower_left_point > upper_left_point){
		finalHull.insert(finalHull.end(), lower_left_point, part1.end());
		finalHull.insert(finalHull.end(), part1.begin(), upper_left_point+1);
	} else {
		finalHull.insert(finalHull.end(), lower_left_point, upper_left_point+1);
	}
	if(upper_right_point > lower_right_point){
		finalHull.insert(finalHull.end(), upper_right_point, part2.end());
		finalHull.insert(finalHull.end(), part2.begin(), lower_right_point+1);
	} else {
		finalHull.insert(finalHull.end(), upper_right_point, lower_right_point+1);
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
	// poi2D fileRead;
	// fileRead.y = 3.0;
	// for (int i = 0; i < 15; ++i)
	// {
	// 	fileRead.x = i;
	// 	fileRead.y = i;
	// 	input.push_back(fileRead);
	// }
	
	clock_t begin = clock();

	input = divideAndConquer(input);

	printVec(input);

	clock_t end = clock();
	double elapsed_secs = double(end - begin);
	cout << elapsed_secs << endl;
}
