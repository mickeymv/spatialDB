#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "RobustGeometricPrimitives2D.h"
#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"
#include "Region2DImpl.h"
#include <regex>
 
using namespace std;


int main() 
{
    
    // running the code:
    // g++ -std=c++0x TestRegion2D.cpp Point2D.cpp Number.cpp RobustGeometricPrimitives2D.cpp BigInteger.cpp BigRational.cpp Line2D.cpp Region2D.cpp
    // ./a.out
    
    //Testing Region2D
    
   /* Seg2D s1(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(1)),Number(std::to_string(6))));
    Seg2D s2(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s3(Poi2D(Number(std::to_string(1)),Number(std::to_string(6))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s4(Poi2D(Number(std::to_string(3)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(5))));
    Seg2D s5(Poi2D(Number(std::to_string(4)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(6))));
    Seg2D s6(Poi2D(Number(std::to_string(3)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(6))));
    Seg2D s7(Poi2D(Number(std::to_string(4)),Number(std::to_string(3))),Poi2D(Number(std::to_string(6)),Number(std::to_string(4))));
    Seg2D s8(Poi2D(Number(std::to_string(4)),Number(std::to_string(3))),Poi2D(Number(std::to_string(5)),Number(std::to_string(2))));
    Seg2D s9(Poi2D(Number(std::to_string(5)),Number(std::to_string(2))),Poi2D(Number(std::to_string(6)),Number(std::to_string(4))));
    Seg2D s10(Poi2D(Number(std::to_string(1.5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(3))));
    Seg2D s11(Poi2D(Number(std::to_string(2)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(4))));
    Seg2D s12(Poi2D(Number(std::to_string(1.5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(4))));*/



    Seg2D s1(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(1)),Number(std::to_string(6))));
    Seg2D s2(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s3(Poi2D(Number(std::to_string(1)),Number(std::to_string(6))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s4(Poi2D(Number(std::to_string(3)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(5))));
    Seg2D s5(Poi2D(Number(std::to_string(4)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(6))));
    Seg2D s6(Poi2D(Number(std::to_string(3)),Number(std::to_string(5))),Poi2D(Number(std::to_string(4)),Number(std::to_string(6))));
    Seg2D s7(Poi2D(Number(std::to_string(4)),Number(std::to_string(3))),Poi2D(Number(std::to_string(6)),Number(std::to_string(4))));
    Seg2D s8(Poi2D(Number(std::to_string(4)),Number(std::to_string(3))),Poi2D(Number(std::to_string(5)),Number(std::to_string(2))));
    Seg2D s9(Poi2D(Number(std::to_string(5)),Number(std::to_string(2))),Poi2D(Number(std::to_string(6)),Number(std::to_string(4))));
    Seg2D s10(Poi2D(Number(std::to_string(1.5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(3))));
    Seg2D s11(Poi2D(Number(std::to_string(2)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(4))));
    Seg2D s12(Poi2D(Number(std::to_string(1.5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(2)),Number(std::to_string(4))));

    Seg2D s13(Poi2D(Number(std::to_string(4)),Number(std::to_string(4))),Poi2D(Number(std::to_string(4)),Number(std::to_string(1))));
    Seg2D s14(Poi2D(Number(std::to_string(4)),Number(std::to_string(1))),Poi2D(Number(std::to_string(7)),Number(std::to_string(1))));
    Seg2D s15(Poi2D(Number(std::to_string(7)),Number(std::to_string(1))),Poi2D(Number(std::to_string(7)),Number(std::to_string(4))));
    Seg2D s16(Poi2D(Number(std::to_string(4)),Number(std::to_string(4))),Poi2D(Number(std::to_string(7)),Number(std::to_string(4))));

    Seg2D s17(Poi2D(Number(std::to_string(5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(5)),Number(std::to_string(2))));
    Seg2D s18(Poi2D(Number(std::to_string(5)),Number(std::to_string(2))),Poi2D(Number(std::to_string(6)),Number(std::to_string(2))));
    Seg2D s19(Poi2D(Number(std::to_string(6)),Number(std::to_string(2))),Poi2D(Number(std::to_string(6)),Number(std::to_string(3))));
    Seg2D s20(Poi2D(Number(std::to_string(5)),Number(std::to_string(3))),Poi2D(Number(std::to_string(6)),Number(std::to_string(3))));


    
    
    vector<Seg2D> Seg2;

    Seg2.push_back(s1);
    Seg2.push_back(s2);
    Seg2.push_back(s3);
    Seg2.push_back(s4);
    Seg2.push_back(s5);
    Seg2.push_back(s6);
    //Seg2.push_back(s7);
    //Seg2.push_back(s8);
    //Seg2.push_back(s9);
    Seg2.push_back(s10);
    Seg2.push_back(s11);
    Seg2.push_back(s12);
    Seg2.push_back(s13);
    Seg2.push_back(s14);
    Seg2.push_back(s15);
    Seg2.push_back(s16);
    Seg2.push_back(s17);
    Seg2.push_back(s18);
    Seg2.push_back(s19);
    Seg2.push_back(s20);

    //Region2D Region1(Seg2);
    
    //cout<<"Region 1 is:"<<Region1;

    vector<Seg2D> Seg3;
  
    Seg3.push_back(s7);
    Seg3.push_back(s8);
    Seg3.push_back(s9);

    //Region2D Region2("(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))");
    Region2D Region2(Seg3);
    cout<<"Region 2 is:"<<Region2;
    /*
    Region2D Region3(Region2);
    cout<<"\nTest result of region copy constructor:\n "<<Region3<<endl;
    
    cout<<"---Testing Unary predicates and operations"<<endl;
    
    if(Region1.isEmptyRegion2D()) 
       cout << "Region is empty " << endl;
    else 
       cout << "Region is not empty " << endl;
    
    if(Region1.isSimpleRegion2D()) 
       cout << "Simple Region " << endl;
    else 
       cout << "Not simple region  " << endl;

    if(Region1.isSimpleRegion2DWithHoles()) 
       cout << "Region is Simple Region with Holes " << endl;
    else 
       cout << "Region is not Simple Region with Holes " << endl;

    if(Region1.isFace()) 
       cout << "Region is just a face " << endl;
    else 
       cout << "Region is either empty or multiface " << endl;

    cout << " Number of faces , hole cycles, segments for Region1 are : "<< Region1.getNumberOfFaces() << " " << Region1.getNumberOfHoleCycles() << " " <<  Region1.getNumberOfSegments() << endl;
    
    cout << " Number of faces , hole cycles(excl outer cycle), segments for Region2 are : "<< Region2.getNumberOfFaces() << " " << Region2.getNumberOfHoleCycles() << " " <<  Region2.getNumberOfSegments() << endl;
    
    cout << "Testing outer cycle \n" <<  Region2.getOuterCycle() << endl; 

    cout<<"--------ITERATORS TESTING---------------"<<endl;
    cout<<"---------------Region 2D ---------------"<<endl;
    Region2D::ConstFaceIterator F1;
    F1 = Region1.cFbegin();
    cout<<"itr Value: F1" <<F1<<endl;
    cout<<"Value during postfix increment: F1" <<F1++<<endl;
    cout<<"Value after postfix increment is done: F1" <<F1<<endl;
    cout<<"-----------------------------------"<<endl;
    
    Region2D::ConstFaceIterator F2;
    F2 = Region2.cFbegin();
    cout<<"itr Value: F2" <<F2<<endl;
    cout<<"itr Value after prefix increment: F2" <<++F2<<endl;
    cout<<"itr Value: F2" <<F2<<endl;
    cout<<"-----------------------------------"<<endl;

    Region2D::ConstCycleIterator C1;
    C1 = Region1.cHbegin();
    cout<<"itr Value: C1" <<C1<<endl;
    cout<<"itr Value: C1 checking decrement" <<--C1<<endl;
    cout<<"itr Value: C1" <<C1++<<endl;
    cout<<"itr Value: C1" <<C1<<endl;
    cout<<"itr Value: C1 dereferencing cycle" <<*C1<<endl;
    cout<<"-----------------------------------"<<endl;
    
    Region2D::ConstCycleIterator C2;
    C2 = Region2.cHbegin();
    cout<<"itr Value: C2" <<C2<<endl;
    cout<<"itr Value: C2" <<--C2<<endl;
    cout<<"itr Value: C2" <<++C2<<endl;
    cout<<"itr Value: C2" <<C2<<endl;
    
    cout<<"---------------Region 2D Implementation---------------"<<endl;
    Region2DImpl regionx(Seg2);
    Region2DImpl::ConstAttributedHalfSegmentIterator itrx;
    itrx = regionx.cbegin();
    cout<<"itr Value: " <<itrx<<endl;
    cout<<"itr Value: " <<++itrx<<endl;
    cout<<"itr Value: " <<itrx++<<endl;
    cout<<"itr Value: " <<itrx<<endl;
    cout<<"-----------------------------------"<<endl;
    Region2DImpl regiony(regionx);
    Region2DImpl::ConstAttributedHalfSegmentIterator itr2x;
    itr2x = regiony.cbegin();
    cout<<"itr Value: " <<itr2x<<endl;
    cout<<"itr Value: " <<++itr2x<<endl;
    cout<<"-----------------------------------"<<endl;
    Region2DImpl regionz = regiony;
    Region2DImpl::ConstAttributedHalfSegmentIterator itr2y;
    itr2y = regionz.cbegin();
    cout<<"itr Value: " <<itr2y<<endl;
    cout<<"itr Value: " <<itr2y++<<endl;
    cout<<"itr Value: " <<itr2y<<endl;
    cout<<"-----------------------------------"<<endl;    
    */
    return 0;
}

