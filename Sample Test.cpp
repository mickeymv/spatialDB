#include<iostream>
#include "BigRational.h"
#include "BigInteger.h"
#include "PoiR2D.h"
using namespace std;

void main()
{
	BigRational bigRational(6.323230);
	BigRational bigRational1(6.1);
	BigInteger bigInteger(3);
	BigInteger bigInteger1(4);

	cout << "BigRationals: " << bigRational << " and " << bigRational1 << endl;
	cout << "addition: " << bigRational + bigRational1 << endl;
	cout << "subtraction: " << bigRational - bigRational1 << endl;
	cout << "multiplication: " << bigRational * bigRational1 << endl;
	cout << "division: " << bigRational / bigRational1 << endl;

	cout << "\nBigIntegers: " << bigInteger << " and " << bigInteger1 << endl;
	cout << "addition: " << bigInteger + bigInteger1 << endl;
	cout << "subtraction: " << bigInteger - bigInteger1 << endl;
	cout << "multiplication: " << bigInteger * bigInteger1 << endl;
	cout << "division: " << bigInteger / bigInteger1 << endl;
	cout << "modulus: " << bigInteger % bigInteger1 << endl;

	cout << "\naddition: " << bigInteger / bigRational << endl;

	cout << "\naddition: " << bigRational / bigInteger << endl;

	if (bigInteger > bigRational1)
	{
		cout << "true"<<endl;
	}
	else
	{
		cout << "false"<<endl;
	}

	if (bigRational >= bigInteger)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << "LCM: " << LCM(bigInteger, bigInteger1) << endl;
	cout << "HCF: " << HCF(bigInteger, bigInteger1) << endl;


	PoiR2D p1(bigRational, bigRational1);
	cout << p1 << endl;


	return;
}