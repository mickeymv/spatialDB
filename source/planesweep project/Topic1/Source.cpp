#include <iostream>
#include "Number.h"
#include "RobustGeometricPrimitives2D.h"
#include "BigRational.h"
#include "BigInteger.h"

using namespace std;

int main()
{
	/* Numbers */
	/* sample code to run functions on bigintegers */
	BigInteger a("-422223423531234");
	BigInteger b("2111");
	BigInteger c("122313124");
	BigInteger d("122313124");

	BigInteger e("5655770");
	BigInteger f("1131154");
	cout << "a = " << a<<endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;

	//mathematical operations
	cout << "a + b = " << a + b << endl;
	cout << "a - b = " << a - b << endl;
	cout << "a * b = " << a*b << endl;
	cout << "a / b = " << a / b << endl;
	cout << "a % b = " << a % b << endl;

	//Power function
	cout << "a ^ 2 = " << Pow(a, 2) << endl;
	
	//GCD
	cout << "GCD of a and b = " << GCD(a, b) << endl;

	//LCM
	cout << "LCM of e and f = " << LCM(e, f) << endl;

	//Absolute function
	cout << "Absolute value of a = " << Abs(a) << endl;

	//Logical Operations
	if (a < b) {
		cout << "a is lesser than b" << endl;
	}
	else
		cout << "a is greater than b" << endl;

	if (b > a) {
		cout << "b is greater than a" << endl;
	}
	else
		cout << "a is greater than b" << endl;

	if (c == d) {
		cout << "c is equal to d" << endl;
	}
	else
		cout << "c is not equal to d" << endl;

	if (a != b) {
		cout << "a is not equal to b" << endl;
	}
	else
		cout << "a is equal to b" << endl;



	//BigRational
	BigRational x("233242", "957505");
	BigRational y("432", "918");
	BigRational r("675", "123");
	BigRational s("675", "123");

	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "r = " << r << endl;
	cout << "s = " << s << endl;

	//mathematical operations
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * y = " << x * y << endl;
	cout << "x / y = " << x / y << endl;

	//logical operations
	if (x < y) {
		cout << "x is lesser than y" << endl;
	}
	else
		cout << "x is greater than y" << endl;

	if (x > y) {
		cout << "x is greater than y" << endl;
	}
	else
		cout << "y is greater than x" << endl;

	if (r == s) {
		cout << "r is equal to s" << endl;
	}
	else
		cout << "r is not equal to s" << endl;

	if (x != y) {
		cout << "x is not equal to y" << endl;
	}
	else
		cout << "x is equal to y" << endl;

	
	//Number
	Number n1("27328733242342342.324242432312412414");
	Number n2("436875634568075464.474223242353454364645");
	Number n3("7487235544657569032.636332");
	Number n4("7487235544657569032.636332");

	cout << "n1 = " << n1 << endl;
	cout << "n2 = " << n2 << endl;

	//mathematical operations
	cout << "n1 + n2 = " << n1 + n2 << endl;
	cout << "n1 - n2 = " << n1 - n2 << endl;
	cout << "n1 * n2 = " << n1 * n2 << endl;
	cout << "n1 / n2 = " << n1 / n2 << endl;

	//logical operations
	if (n1 < n2) {
		cout << "n1 is lesser than n2" << endl;
	}
	else{
		cout << "n1 is greater than n2" << endl;
	}	

	if (x >= y) {
		cout << "n1 is greater  or equal to n2" << endl;
	}
	else{
		cout << "n2 is greater than n1" << endl;
	}	

	if (n3 == n4) {
		cout << "n3 is equal to n4" << endl;
	}
	else{
		cout << "n3 is not equal to n4" << endl;
	}	

	if (n1 != n2) {
		cout << "n1 is not equal to n2" << endl;
	}
	else{
		cout << "n1 is equal to n2" << endl;
	}	

	//-----------------------------------------------------//



	/* Points used to construct segments used for Segment Relationships Tests*/
	 Poi2D p1(Number("1.0"), Number("1.0"));
	 Poi2D p2(Number("100.0"), Number("100.0"));
	 Poi2D p3(Number("50.0"), Number("50.0"));
	 Poi2D p4(Number("60.0"),Number("60.0"));
	 Poi2D p5(Number("60.0"), Number("80.0"));
	 Poi2D p6(Number("70.0"), Number("90.0"));
	 Poi2D p7(Number("20"), Number("20.0"));
	 Poi2D p8(Number("30.0"), Number("30.0"));
	 Poi2D p9(Number("70.0"), Number("70.0"));
	 Poi2D p10(Number("80.0"), Number("80.0"));
	 Poi2D p11(Number("50.0"), Number("60.0"));
	 Poi2D p12(Number("60.0"), Number("70.0"));
	 Poi2D p13(Number("50.0"), Number("50.0"));
	 Poi2D p14(Number("60.0"), Number("60.0"));
	 Poi2D p15(Number("50.0"), Number("60.0"));
	 Poi2D p16(Number("60.0"), Number("50.0"));
	 Poi2D p17(Number("60.0"), Number("60.0"));
	 Poi2D p18(Number("70.0"), Number("70.0"));

	 /* Points Used in Point Relation Tests*/
	 Poi2D pi1(Number("50.0"), Number("50.0"));
	 Poi2D pi2(Number("50.0"), Number("51.0"));
	 Poi2D pi3(Number("49.0"), Number("48.0"));
	 Poi2D pi4(Number("1.0"), Number("1.0"));
	 Poi2D pi5(Number("100.0"), Number("100.0"));
	 Poi2D pi6(Number("0.5"), Number("0.5"));
	 Poi2D pi7(Number("101.0"), Number("101.0"));
	 
	 cout << "\nList of Points used to create Segments";
	 cout << "\n---------------------------------------------------------------------------------------------------";
	 cout << "\n\tPoint p1:" << p1 << endl;
	 cout << "\n\tPoint p2:" << p2 << endl;
	 cout << "\n\tPoint p3:" << p3 << endl;
	 cout << "\n\tPoint p4:" << p4 << endl;
	 cout << "\n\tPoint p5:" << p5 << endl;
	 cout << "\n\tPoint p6:" << p6 << endl;
	 cout << "\n\tPoint p7:" << p7 << endl;
	 cout << "\n\tPoint p8:" << p8 << endl;
	 cout << "\n\tPoint p9:" << p9<< endl;
	 cout << "\n\tPoint p10:" << p10 << endl;
	 cout << "\n\tPoint p11:" << p11 << endl;
	 cout << "\n\tPoint p12:" << p12 << endl;
	 cout << "\n\tPoint p13:" << p13 << endl;
	 cout << "\n\tPoint p14:" << p14 << endl;
	 cout << "\n\tPoint p15:" << p15 << endl;
	 cout << "\n\tPoint p16:" << p16 << endl;
	 cout << "\n\tPoint p17:" << p17 << endl;
	 cout << "\n\tPoint p18:" << p18 << endl;

	 Seg2D s1(p1, p2);
	 Seg2D s2(p3, p4);
	 Seg2D s3(p5, p6);
	 Seg2D s4(p7, p8);
	 Seg2D s5(p9, p10);
	 Seg2D s6(p11, p12);
	 Seg2D s7(p13, p14);
	 Seg2D s8(p15, p16);
	 Seg2D s9(p17, p18);

	 cout << "\nList of Segments";
	 cout << "\n ----------------------------------------------------------------------------------------------------";
	 cout << "\nSegment 1:" << s1;
	 cout << "\nSegment 2:" << s2;
	 cout << "\nSegment 3:" << s3;
	 cout << "\nSegment 4:" << s4;
	 cout << "\nSegment 5:" << s5;
	 cout << "\nSegment 6:" << s6;
	 cout << "\nSegment 7:" << s7;
	 cout << "\nSegment 8:" << s8;
	 cout << "\nSegment 9:" << s9<<"\n";

	 cout << "\nRelationship Tests between Points and Segments";
	 cout << "\n ---------------------------------------------------------------------------------------------------";
	 cout<<"\nPoint"<<pi1<<"Lies On Segment"<<s1<<"Test:"<<PointLiesOnSegment(pi1,s1);
	 cout <<"\nPoint"<<pi1<<"Lies On Segment And Not Endpoints"<<s1<<"Test:" << PointLiesOnSegmentAndNotEndpoints(pi1,s1);
	 cout <<"\nPoint"<<pi2<<"Lies Above Segment Test:"<<PointLiesAboveSegment(pi2,s1);
	 cout<<"\nPoint"<<pi3<<"Lies Below Segment"<<s1<<"Test:"<<PointLiesBelowSegment(pi3,s1);
	 cout<<"\nPoint"<<pi3<<"Lies Above Or On Segment"<<s1<<"Test:"<<PointLiesAboveOrOnSegment(pi3,s1);
	 cout<<"\nPoint"<<pi1<<"Lies Below Or On Segment"<<s1<<"Test:"<<PointLiesBelowOrOnSegment(pi1,s1);
	 cout << "\nPoint"<<pi4<<"Lies On Left Endpoint of Segment"<<s1<<"Test:" << PointLiesOnLeftEndPointOfSegment(pi4, s1);
	 cout << "\nPoint" << pi5 << "Lies On Right Endpoint of Segment" << s1 << "Test:" << PointLiesOnRightEndPointOfSegment(pi5, s1);
	 cout <<"\nPoint"<<pi6<<"is collinear to Segment"<<s1<<"Test:"<<PointIsCollinearToSegment(pi6,s1);
	 cout <<"\nPoint"<<pi6<<"is collinear and lies to the left of Segment"<<s1<<"Test:" << PointLiesLeftOFSegmentAndIsCollinear(pi6,s1);
	 cout <<"\nPoint"<<pi7<<"Lies Below Or On Segment"<<s1<<"Test:"<<PointLiesRightOfSegmentAndIsCollinear(pi7,s1);

	 cout << "\nRelationship Tests between pairs of Segments";
	 cout << "\n---------------------------------------------------------------------------------------------------";
	 
	 cout << "\nSegment: "<<s1<<"Lies On Segment"<<s2<<"Test:"<<SegmentLiesOnSegment(s1, s2);
	 cout << "\nSegment: "<<s3<<"Lies Above Segment"<<s2<<"Test:"<<SegmentLiesAboveSegment(s3, s2);
 	 cout << "\nSegment: "<<s3<<"Lies Below Segment:"<<s2<<SegmentLiesBelowSegment(s3, s2);
	 cout << "\nSegment: "<<s4<<"Lies Left OF Segment"<<s2<<"Test:"<<SegmentLiesLeftOFSegment(s4, s2);
	 cout << "\nSegment: "<<s4<<"Lies Right Of Segment:"<<SegmentLiesRightOfSegment(s4, s2);
	 cout << "\nSegment: "<<s4<<"Is Collinear to"<<s2<<"Test:"<<SegmentIsCollinear(s4,s2);
	 cout << "\nSegment: "<<s4<<"Lies Left OF Segment"<<s2<<"And Is Collinear Test:"<<SegmentLiesLeftOFSegmentAndIsCollinear(s4,s2);
	 cout << "\nSegment: "<<s5<<"Lies Right Of Segment"<<s2<<"And Is Collinear Test:"<<SegmentLiesRightOfSegmentAndIsCollinear(s5,s2);
	 cout << "\nSegment: "<<s2<<"Is Parallel to Segment"<<s6<<"Test:"<<SegmentIsParallel(s2,s6);
	 cout << "\nSegment: "<<s2<<"Is Parallel And Above"<<s6<<"Test:"<<SegmentIsParallelAndAbove(s2,s6);
	 cout << "\nSegment: "<< s2<<"Is Parallel And Below"<<s6<<"Test:"<< SegmentIsParallelAndBelow(s2,s6);
	 cout << "\nSegment: "<<s7<<"Intersects Segment"<<s8<<"Test:"<<Intersects(s7,s8);
	 cout << "\nSegment: "<<s1<<"Is Lesser Than Segment"<<s2<<"Test:" << SegmentIsLesserThanSegment(s1,s2);
	 cout << "\nSegment: " << s7 << "Intersects Segment" << s8 << " Point of Intersection Is:"<<IntersectionPoint(s7,s8);
	 cout << "\nSegment: " << s9 << "Meets Segment" << s2 << "Test:" << Meet(s9, s2);
	 cout << "\nSegment: " << s9 << "Meets Segment" << s2 <<"at Point:" << MeetingPoint(s9, s2);
	 cout<<"\nMidpoint of the Segment: "<<s2<<"is:"<<MidPoint(s2);


	//-----------------------------------------------------//

	/* 

	function for point or segment in polygon test
	attached is an image for testing the polygon.

	*/
	
	cout << "\nRelationship Tests between Polygons , points and segment";
	 cout << "\n---------------------------------------------------------------------------------------------------";
	vector<Poi2D> points2 = { Poi2D(Number("2.0"), Number("10.0")),Poi2D(Number("4.0"), Number("12.0")), Poi2D(Number("4.0"), Number("14.0")),Poi2D(Number("8.0"), Number("14.0")),Poi2D(Number("8.0"), Number("1.0")),Poi2D(Number("1.0"), Number("1.0")),Poi2D(Number("1.0"), Number("3.0")),Poi2D(Number("6.0"), Number("3.0")) ,Poi2D(Number("6.0"), Number("4.0")),Poi2D(Number("2.0"), Number("4.0")),Poi2D(Number("2.0"), Number("6.0")),Poi2D(Number("6.0"), Number("8.0"))};
	SimplePolygon2D testpolygon(points2);
	Poi2D pi11 = Poi2D(Number("2.0"), Number("2.0"));
	cout <<"polygon inside or not test----"<< simplePointInsideSimplePolygon(pi11, testpolygon)<<"----"<<endl;
	

	//SimplePolygon2D testpolygon(points2);
	Poi2D pi12 = Poi2D(Number("2.0"), Number("1.0"));
	cout <<"simplePointOnBoundaryOfSimplePoly----"<< simplePointOnBoundaryOfSimplePoly(pi12, testpolygon)<<"----"<<endl;

	Poi2D pi13 = Poi2D(Number("6.0"), Number("5.0"));
	Poi2D pi14 = Poi2D(Number("6.0"), Number("7.0"));
	Seg2D si1(pi13,pi14);
	cout <<"segInsideSimplePolygon----"<< segInsideSimplePolygon(si1, testpolygon)<<"----"<<endl;


	Poi2D pi15 = Poi2D(Number("2.0"), Number("5.0"));
	Poi2D pi16 = Poi2D(Number("2.0"), Number("6.0"));
	Seg2D si2(pi15,pi16);
	cout <<"segOnBoundaryOfSimplePolygon----"<< segOnBoundaryOfSimplePolygon(si2, testpolygon)<<"----"<<endl;
	getchar();
	return 0;

}
