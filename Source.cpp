#include <iostream>
#include "Number.h"
#include "RobustGeometricPrimitives2D.h"
#include "BigRational.h"
#include "BigInteger.h"

using namespace std;

int main()
{

	Number num("5.1234");
	BigInteger a1("2");
	BigInteger a2("3");
	BigRational a("2", "3");
	BigRational b("3", "5");

	bool answer = a == b;
	cout << "Big Rational varaiable multiplication:" << a * b << endl;
	cout << "Big Rational varaiable division:" << a / b << endl;

	Poi2D p1(Number("2.0"), Number("2.0"));
	Poi2D p2(Number("5.0"), Number("5.0"));
	Poi2D p3(Number("3.0"), Number("0.0"));
	Poi2D p4(Number("4.0"), Number("4.0"));
	Poi2D p5(Number("2.0"), Number("5.0"));
	cout << "Point p1:" << p1 << endl;
	cout << "Point p2:" << p2 << endl;
	cout << "Point p3:" << p3 << endl;
	cout << "Point p4:" << p4 << endl;
	cout << "Point p5:" << p5 << endl;
	
	Seg2D s1(p1, p2);
	Seg2D s2(p3, p4);

	Seg2D s3(p3,p5);
	HalfSeg2D leftHalfS1(s1, true);
	HalfSeg2D rightHalfS1(s1, false);

	HalfSeg2D leftHalfS2(s2, true);
	HalfSeg2D rightHalfS2(s2, false);

	cout << "HalfSeg2D for s1 is " << leftHalfS1;
	cout << "--HalfSeg2D is " << rightHalfS1;
	cout << "HalfSeg2D is " << leftHalfS2;
	cout << "HalfSeg2D is " << rightHalfS2;

	// We need to figure out if the leftHalfS1 is lesser than righttHalfS2

	if (leftHalfS1 < rightHalfS2){
		cout << "yes less than";
	}
	else{
		cout << "No less than";
	}


	if (leftHalfS1 == rightHalfS2){
		cout << "yes equal to!!";
	}
	else{
		cout << "No equal to--";
	}


	if (leftHalfS1 <= rightHalfS2){
		cout << "yes less than equal to!!";
	}
	else{
		cout << "Not less that equal to--";
	}


	if (leftHalfS1 != rightHalfS2){
		cout << "yes not equal to!!";
	}
	else{
		cout << "No not equal to--";
	}

	if(Meet(s1,s3)){
		cout<<"They meet----- ";
	}else{
		cout << "They don't meet -----";
	}
	if (Intersects(s1, s2))
	{
		cout << "they intersect";
		cout << "point of intersection:" << IntersectionPoint(s1, s2);
	}
	else
	{
		cout << "dont intersect";
	}

	// if (p1 < p2)
	// {
	// 	cout << "The point" << p1 << " is less than the point " << p2 << endl;
	// }

	// if (p4 > p1)
	// {
	// 	cout << "The point" << p4 << " is greater than the point " << p2 << endl;
	// }

	// if (p2 == p3)
	// {
	// 	cout << "The point" << p2 << " is equal to the point " << p3 << endl;
	// }

	// if (p3 <= p5)
	// {
	// 	cout << "The point" << p3 << " is less than or equal to the point " << p5 << endl;
	// }
	// if (p3 >= p5)
	// {
	// 	cout << "The point" << p3 << " is greater than or equal to the point " << p5 << endl;
	// }
	// else
	// {
	// 	cout << "The point" << p3 << " is less than the point " << p5 << endl;
	// }
	
	// //Checking collinearity and meets the left end point with s1 and s2
	// if ( SegmentIsCollinearAndMeetsLeftEndpoint(s1,s2) )
	// 	cout << "yeah they're collinear and meet left endpoint."<<endl;
	// else
	// 	cout << "No either not collinear or does not meet left endpoint." << endl;
	
	// if (SegmentIsCollinearAndMeetsRightEndpoint(s1, s2))
	// 	cout << "yeah they're collinear and meet right endpoint." << endl;
	// else
	// 	cout << "No either not collinear or does not meet right endpoint." << endl;

	// if (SegmentIsCollinearAndMeetsBothEndpoint(s1, s2))
	// 	cout << "yeah they're collinear and meet both endpoints." << endl;
	// else
	// 	cout << "No either not collinear or does not meet both endpoints." << endl;

	// if (SegmentIsParallel(s1, s2))
	// 	cout << "the segments are parallel";
	// else
	// 	cout << "not parallel";
	
	getchar();
	return 0;

	
	
	/*unsigned int a = 4333234234234 * 22450000000000;
	cout << UINT_MAX<< endl << a << endl;
	return 0;*/
}
