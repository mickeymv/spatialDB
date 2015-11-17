#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

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

//comparator function
bool compareX(poi2D poi1, poi2D poi2){
	return poi1.x < poi2.x;
}

//comparator function
bool compareY(poi2D poi1, poi2D poi2){
	return poi1.y < poi2.y;
}

//returns an iterator of a vector poi2D at the greatest X location
vector<poi2D>::iterator getXMost(vector<poi2D> vec){
	vector<poi2D>::iterator it = vec.begin();
	vector<poi2D>::iterator ans = vec.begin();
	for (it; it != vec.end(); ++it) {
	    if(it->x > ans->x)
	    	ans = it;
	}
	return ans;
}

vector<poi2D> combineHulls(vector<poi2D> vec1, vector<poi2D> vec2){
	//find rightmost point of left and leftmost point of right
	vector<poi2D>::iterator it = getXMost(vec1);

}

//sees if the slope has increased between 2 points
bool slopeIncreased(poi2D p1, poi2D p2, poi2D p3){
	//if p1 to p3 has greater slope return true
	return (p2.y - p1.y)*(p2.x - p1.x) < (p3.y - p1.y)*(p3.x - p1.x);
}

//recursive divide and Conquer function
vector<poi2D> divideAndConquer(vector<poi2D> vec){
	int size = vec.size();
	if(size < 4)
		return vec;
	sort(vec.begin(), vec.end(), compareX);
	vector<poi2D> part1(vec.begin(), vec.begin() + size/2), part2(vec.begin() + size/2, vec.end());
	part1 = divideAndConquer(part1);
	part2 = divideAndConquer(part2);
	return combineHulls(part1, part2);
}

//prints vector of poi2D's
void printVec(vector<poi2D> vec){
	for (vector<poi2D>::iterator it = vec.begin(); it != vec.end(); ++it) {
	    cout << it->toString() << endl;
	}
}

int main(){
	vector<poi2D> input;
	ifstream infile;
	infile.open("points.bin",ios::binary|ios::in);

	poi2D fileRead;

	cout << "reading in binary file" << endl;
	cout << endl;

	while(infile.read((char *)&fileRead,sizeof(poi2D)))
	{
	  input.push_back(fileRead);
	  cout << fileRead.toString() << endl;
	}

	cout << endl;
	cout << "splitting points" << endl;
	int size = input.size();
	sort(input.begin(), input.end(), compareX);
	vector<poi2D> part1(input.begin(), input.begin() + size/2), part2(input.begin() + size/2, input.end());
	printVec(part1);
	cout << endl;
	printVec(part2);

	divideAndConquer(input);
}