#include <iostream>
#include "Number.h"
#include "RobustGeometricPrimitives2D.h"

using namespace std;

int main()
{

	Number a("5.1234");
	Number b("3.1234");
	//cin >> a;
	cout << "--number--"<< endl << a <<endl;
	Poi2D p(a, b);
	cout << "--point--" << endl << p << endl;
	Seg2D seg(Poi2D(Number("3"), Number("4")), p);
	cout << "--segment--" << endl << seg << endl;
	HalfSeg2D halfseg(p, true);
	cout << "--half segment--" << endl << halfseg << endl;
	cout << LiesAboveOrOnSegment(p, seg)<<endl;
	return 0;
}