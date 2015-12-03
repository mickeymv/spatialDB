#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "RobustGeometricPrimitives2D.h"
#include "Point2D.h"
#include "Line2D.h"
#include <regex>
 
using namespace std;


int main() 
{
	
    // running the code:
    // g++ -std=c++0x TestPoint2D.cpp Point2D.cpp Number.cpp RobustGeometricPrimitives2D.cpp BigInteger.cpp Line2DImpl.cpp BigRational.cpp Line2D.cpp
    // ./a.out
    
    /*

    Seg2D s1(Poi2D(Number(std::to_string(0)),Number(std::to_string(0))),Poi2D(Number(std::to_string(1)),Number(std::to_string(1))));
    Seg2D s2(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(2)),Number(std::to_string(2))));
    Seg2D s3(Poi2D(Number(std::to_string(2)),Number(std::to_string(2))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s4(Poi2D(Number(std::to_string(5)),Number(std::to_string(5))),Poi2D(Number(std::to_string(6)),Number(std::to_string(6))));
    Seg2D s5(Poi2D(Number(std::to_string(6)),Number(std::to_string(6))),Poi2D(Number(std::to_string(7)),Number(std::to_string(7))));
    Seg2D s6(Poi2D(Number(std::to_string(7)),Number(std::to_string(7))),Poi2D(Number(std::to_string(8)),Number(std::to_string(8))));
    
    Seg2D s7(Poi2D(Number(std::to_string(10)),Number(std::to_string(10))),Poi2D(Number(std::to_string(11)),Number(std::to_string(11))));
    Seg2D s8(Poi2D(Number(std::to_string(11)),Number(std::to_string(11))),Poi2D(Number(std::to_string(12)),Number(std::to_string(12))));
    
    vector<Seg2D> Seg1;
    Seg1.push_back(s6);
    Seg1.push_back(s1);
    Seg1.push_back(s2);
    Seg1.push_back(s5);
    Seg1.push_back(s8);
    Seg1.push_back(s7);
    Seg1.push_back(s3);
    Seg1.push_back(s4);
    
    
    Line2D line1(Seg1);
    Line2D::ConstSegIterator itr;
    Line2D::ConstSegIterator itr2;
    Line2D::ConstSegIterator itr3;
    itr = line1.cbegin();
    itr2 = line1.cend();
    if(itr.isEmpty()){cout<<"1 is empty"<<endl;}else{cout<<"1 is not empty"<<endl;}
    if(itr3.isEmpty()){cout<<"3 is empty"<<endl;}else{cout<<"3 is not empty"<<endl;}
    
    
    cout<<"Test result of cbegin: " <<itr<<endl;
    cout<<"Test result of cend: " <<itr2<<endl;
    cout<<"Test result of dereference operator *: " <<*itr2<<endl;
    cout<<"Test result of dereference operator &: " <<&itr2<<endl;
    cout<<"Test result of cbegin: " <<itr++<<endl;
    cout<<"Test result of cbegin: " <<itr--<<endl;
    
    
    
    
    
    
    
    
    
    
    
    Poi2D p1(Number(std::to_string(1)),Number(std::to_string(1)));
    Seg2D s1(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(2)),Number(std::to_string(2))));
    Seg2D s2(Poi2D(Number(std::to_string(2)),Number(std::to_string(2))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s3(Poi2D(Number(std::to_string(3)),Number(std::to_string(3))),Poi2D(Number(std::to_string(4)),Number(std::to_string(4))));
    Seg2D s4(Poi2D(Number(std::to_string(0)),Number(std::to_string(0))),Poi2D(Number(std::to_string(1)),Number(std::to_string(1))));
    
    //HalfSeg2D hs1(s1,false);
    //cout<<hs1<<endl;
    
    vector<HalfSeg2D> halfsegments;
    HalfSeg2D* hs;
    hs = new HalfSeg2D(s1,false);
    halfsegments.push_back(*hs);
    delete hs;
    hs = new HalfSeg2D(s1,true);
    halfsegments.push_back(*hs);
    delete hs;
    
	//halfsegments.push_back(HalfSeg2D(s1,false));
	
	
    //cout<<halfsegments.at(0)<<endl;
    //cout<<halfsegments.at(1)<<endl;
    
    
    vector<Seg2D> Seg1;
    Seg1.push_back(s1);
    Seg1.push_back(s2);
    Seg1.push_back(s3);
    Seg1.push_back(s4);
    
    Line2D line1(Seg1);
    cout<<line1;
    
    Line2D::ConstSegIterator itr;
    Line2D::ConstSegIterator itr2;
    Line2D::ConstSegIterator itr3;
    itr = line1.cbegin();
    itr2 = line1.cend();
    if(itr.isEmpty()){cout<<"1 is empty"<<endl;}else{cout<<"1 is not empty"<<endl;}
    if(itr3.isEmpty()){cout<<"3 is empty"<<endl;}else{cout<<"3 is not empty"<<endl;}
    
    
    cout<<"Test result of cbegin: " <<itr<<endl;
    cout<<"Test result of cend: " <<itr2<<endl;
    cout<<"Test result of dereference operator *: " <<*itr2<<endl;
    cout<<"Test result of dereference operator &: " <<&itr2<<endl;
    cout<<"Test result of cbegin: " <<itr++<<endl;
    cout<<"Test result of cbegin: " <<itr--<<endl;
    */
    
    vector<Poi2D> singlepoint1, singlepoint2;
    int randomx,randomy;
    for(int i=0;i<3;i++)
    {
       randomx= rand() % 10 + 1;
       randomy= rand() % 10 + 1;
       singlepoint1.push_back(Poi2D(Number(std::to_string(randomx)),Number(std::to_string(randomy))));
       singlepoint2.push_back(Poi2D(Number(std::to_string(i+1)), Number(std::to_string(i+1))));
    }
    
    cout<<"display vector initialized Point2D: "<<endl;
    Point2D struct1(singlepoint1);           //testing vector of points input
    Point2D struct2(singlepoint2);
    cout<<struct1;
    cout<<struct2;

    Point2D struct3("((1,1),(2,2),(3,3))");  //testing list of points input
    cout<<struct3;
                                             //testing operators
    if(struct3 == struct2)                 
	cout<<"Testing == result true\n";
    else
        cout<<"Testing == result false\n";

    if(struct1 != struct3)
	cout<<"Testing != result true\n";
    else
        cout<<"Testing != result false\n";


    Point2D::ConstPoiIterator itr;
    Point2D::ConstPoiIterator itr1;
    Point2D::ConstPoiIterator itr2;
    Point2D::ConstPoiIterator itr3;
    itr = struct2.chead();
    itr1 = struct2.cbegin();
    itr2 = struct2.cend();
    itr3 = struct2.ctail();
    
    if(itr.isEmpty()){cout<<"1 is empty"<<endl;}else{cout<<"1 is not empty"<<endl;}
    if(itr3.isEmpty()){cout<<"3 is empty"<<endl;}else{cout<<"3 is not empty"<<endl;}
    
    
    cout<<"Test result of chead: " <<itr<<endl;
    cout<<"Test result of cbegin: " <<itr1<<endl;
    cout<<"Test result of cend: " <<itr2<<endl;
    cout<<"Test result of ctail:  "<<itr3<<endl;
    cout<<"Test result of prefix ++ " <<++itr1<<endl;
    cout<<"Test result of postfix ++ temp: " <<itr1++<<endl;
    cout<<"Test result of object after postfix ++ :" << itr1 <<endl;
    cout<<"Test result of prefix --: " <<--itr1<<endl;
    cout<<"Test result of postfix --: " <<itr1--<<endl;
    cout<<"Test result of after postfix --" <<itr1 <<endl;
    itr2--;
    cout<<"Test result of dereference operator *: " <<*itr2<<endl;
    cout<<"Test result of dereference operator &: " <<&itr2<<endl;
    
    //cout << "itr1"<<itr1<<", itr2" << itr2 ; 
    if (itr1 == itr1)
	cout<<"Testing iterator == result true\n";
    if (itr1 != itr2)
        cout<<"Testing iterator != result true\n";
    
     if (itr1 < itr2)
         cout<< "Testing iterator < result true \n";
     else if ( itr1 > itr2 )
         cout<< "Testing iterator > result true \n";
     
    //Test case to show limiting ++, -- on points objects
    Point2D::ConstPoiIterator StrItr1,StrItr2,StrItr3,StrItr4;
    StrItr1 = struct3.chead();
    StrItr2 = struct3.cbegin(); 
    StrItr3 = struct3.cend();
    StrItr4 = struct3.ctail();
    
    cout << "***********Testing new functionality*********"<< endl;
    cout<< StrItr1 << endl << StrItr2 << endl << StrItr3 << endl<< StrItr4 <<endl;    
    
    for ( Point2D::ConstPoiIterator it = struct3.cbegin(); it < struct3.ctail(); ++it )
        cout << " output " << it << endl;        

    return 0;
}
