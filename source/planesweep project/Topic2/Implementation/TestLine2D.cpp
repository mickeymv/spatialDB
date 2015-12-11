#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "RobustGeometricPrimitives2D.h"
#include "Point2D.h"
#include "Line2D.h"
#include <regex>
#include "Line2DImpl.h"
 
using namespace std;


int main() 
{
    // Testing Line2D
    // The following test cases are targetting the different constructors for both Line2DImpl and Line2D classes
    // simple line is sequence of segments forming one block, while the complex line is sequence of segments forming blocks
    // Case1: default constructor for both classes
    // Case2: string constructor for both classes  (simple lines)
    // Case3: string constructor for both classes  (complex lines)
    // Case4: Seg2D vector constructor for both classes  (simple lines)
    // Case5: Seg2D vector constructor for both classes  (complex lines)
    // Case6: Copy constructor for both classes  (complex lines)
    // Case7: Copy assignment operation for both classes
    // Case8: test self interesecting line segments for both classes  (simple lines)
    // Case9: test self interesecting line segments for both classes  (complex lines)
    
    cout << "\n\n------------------LINE Testing starts here ----------------------\n" <<endl;
    //Case1
    Line2D emptyLine;
    cout<<"emptyLine info is " << emptyLine<<endl;
    cout<<"emptyLine number of segments is " << emptyLine.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl emptyLineImpl;
    cout<<"emptyLineImpl info is " << emptyLineImpl<<endl;
    cout<<"emptyLineImpl number of segments is " << emptyLineImpl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    //Case2
    Line2D Line1("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))");
    cout<<"Line1 info is " << Line1<<endl;
    cout<<"Line1 number of segments is " << Line1.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line1Impl("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))");
    cout<<"Line1Impl info is " << Line1Impl<<endl;
    cout<<"Line1Impl number of segments is " << Line1Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    //Case3
    Line2D Line2("(((0,0),(1,1)),((1,1),(2,2)),((3,3),(4,4)),((4,4),(5,5)))");
    cout<<"Line2 info is " << Line2<<endl;
    cout<<"Line2 number of segments is " << Line2.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line2Impl("(((0,0),(1,1)),((1,1),(2,2)),((3,3),(4,4)),((4,4),(5,5)))");
    cout<<"Line2Impl info is " << Line2Impl<<endl;
    cout<<"Line2Impl number of segments is " << Line2Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    //Case4
    //defining vector of 3 seg2Ds forming one line block
    Seg2D s11(Poi2D(Number(std::to_string(5)),Number(std::to_string(5))),Poi2D(Number(std::to_string(6)),Number(std::to_string(6))));
    Seg2D s12(Poi2D(Number(std::to_string(6)),Number(std::to_string(6))),Poi2D(Number(std::to_string(7)),Number(std::to_string(7))));
    Seg2D s13(Poi2D(Number(std::to_string(7)),Number(std::to_string(7))),Poi2D(Number(std::to_string(8)),Number(std::to_string(8))));
    
    vector<Seg2D> Seg1;
    Seg1.push_back(s11);
    Seg1.push_back(s12);
    Seg1.push_back(s13);
    
    Line2D Line3(Seg1);
    cout<<"Line3 info is " << Line3<<endl;
    cout<<"Line3 number of segments is " << Line3.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line3Impl(Seg1);
    cout<<"Line3Impl info is " << Line3Impl<<endl;
    cout<<"Line3Impl number of segments is " << Line3Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    
    //Case5
    //defining vector of 15 seg2Ds forming 4 line blocks
    Seg2D s31(Poi2D(Number(std::to_string(0)),Number(std::to_string(0))),Poi2D(Number(std::to_string(1)),Number(std::to_string(1))));
    Seg2D s32(Poi2D(Number(std::to_string(1)),Number(std::to_string(1))),Poi2D(Number(std::to_string(2)),Number(std::to_string(1))));
    Seg2D s33(Poi2D(Number(std::to_string(2)),Number(std::to_string(1))),Poi2D(Number(std::to_string(3)),Number(std::to_string(1))));
    Seg2D s34(Poi2D(Number(std::to_string(3)),Number(std::to_string(1))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s35(Poi2D(Number(std::to_string(1)),Number(std::to_string(5))),Poi2D(Number(std::to_string(3)),Number(std::to_string(3))));
    Seg2D s36(Poi2D(Number(std::to_string(4)),Number(std::to_string(3))),Poi2D(Number(std::to_string(7)),Number(std::to_string(3))));
    Seg2D s37(Poi2D(Number(std::to_string(3)),Number(std::to_string(5))),Poi2D(Number(std::to_string(5)),Number(std::to_string(7))));
    Seg2D s38(Poi2D(Number(std::to_string(5)),Number(std::to_string(7))),Poi2D(Number(std::to_string(6)),Number(std::to_string(5))));
    Seg2D s39(Poi2D(Number(std::to_string(6)),Number(std::to_string(5))),Poi2D(Number(std::to_string(8)),Number(std::to_string(7))));
    Seg2D s310(Poi2D(Number(std::to_string(8)),Number(std::to_string(7))),Poi2D(Number(std::to_string(5)),Number(std::to_string(8))));
    Seg2D s311(Poi2D(Number(std::to_string(5)),Number(std::to_string(1))),Poi2D(Number(std::to_string(6)),Number(std::to_string(1))));
    Seg2D s312(Poi2D(Number(std::to_string(6)),Number(std::to_string(1))),Poi2D(Number(std::to_string(7)),Number(std::to_string(1))));
    Seg2D s313(Poi2D(Number(std::to_string(7)),Number(std::to_string(1))),Poi2D(Number(std::to_string(8)),Number(std::to_string(1))));
    Seg2D s314(Poi2D(Number(std::to_string(8)),Number(std::to_string(1))),Poi2D(Number(std::to_string(9)),Number(std::to_string(1))));
    Seg2D s315(Poi2D(Number(std::to_string(9)),Number(std::to_string(1))),Poi2D(Number(std::to_string(10)),Number(std::to_string(1))));
    
    vector<Seg2D> Seg3;
    Seg3.push_back(s31);
    Seg3.push_back(s32);
    Seg3.push_back(s33);
    Seg3.push_back(s34);
    Seg3.push_back(s35);
    Seg3.push_back(s36);
    Seg3.push_back(s37);
    Seg3.push_back(s38);
    Seg3.push_back(s39);
    Seg3.push_back(s310);
    Seg3.push_back(s311);
    Seg3.push_back(s312);
    Seg3.push_back(s313);
    Seg3.push_back(s314);
    Seg3.push_back(s315);
    
    Line2D Line4(Seg3);
    cout<<"Line4 info is " << Line4<<endl;
    cout<<"Line4 number of segments is " << Line4.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line4Impl(Seg3);
    cout<<"Line4Impl info is " << Line4Impl<<endl;
    cout<<"Line4Impl number of segments is " << Line4Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    
    //Case6
    Line2D Line5(Line1);
    cout<<"Line5 info is " << Line1<<endl;
    cout<<"Line5 number of segments is " << Line1.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line5Impl(Line1Impl);
    cout<<"Line5Impl info is " << Line5Impl<<endl;
    cout<<"Line5Impl number of segments is " << Line5Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    
    
    //Case7
    Line2D Line6(Line1);
    cout<<"Line6 info is " << Line6<<endl;
    cout<<"Line6 number of segments is " << Line6.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line6Impl=Line1Impl;
    cout<<"Line6Impl info is " << Line6Impl<<endl;
    cout<<"Line6Impl number of segments is " << Line6Impl.getNumberOfSegments()<<endl;
    cout<<endl;
   
    
    //Case8
    Line2D Line79("(((1,2),(5,4)),((5,4),(5,6)),((5,6),(1,1)))");
    cout<<"Line79 info is " << Line79<<endl;
    cout<<"Line79 number of segments is " << Line79.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line79Impl("(((1,2),(5,4)),((5,4),(5,6)),((5,6),(1,1)))");
    cout<<"Line79Impl info is " << Line79Impl<<endl;
    cout<<"Line79Impl number of segments is " << Line79Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    
    //Case9
    Line2D Line89("(((6,2),(7,2)),((7,2),(8,2)),((1,2),(5,4)),((5,4),(5,6)),((5,6),(1,1)))");
    cout<<"Line89 info is " << Line89<<endl;
    cout<<"Line89 number of segments is " << Line89.getNumberOfSegments()<<endl;
    cout<<endl;
    
    Line2DImpl Line89Impl("(((6,2),(7,2)),((7,2),(8,2)),((1,2),(5,4)),((5,4),(5,6)),((5,6),(1,1)))");
    cout<<"Line89Impl info is " << Line89Impl<<endl;
    cout<<"Line89Impl number of segments is " << Line89Impl.getNumberOfSegments()<<endl;
    cout<<endl;
    
    
    //The following test cases is targetting the different comparison operators between different Line2D objects
    // simple line is sequence of segments forming one block, while the complex line is sequence of segments forming blocks
    // Case1: == operator
    // Case2: != operator
    // Case3: < & <= operators
    // Case4: > & >= operators
    
    
    Line2D Line7("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)),((3,3),(4,4)))");
    Line2D Line8("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)),((3,3),(4,4)))");
    Line2D Line9("(((0,0),(1,1)),((1,1),(2,2)),((3,3),(4,4)))");
    
    //Case1
    if(Line7 == Line8) cout<<"Lines 7&8 are equal"<<endl;  else cout<<"Lines 7&8 are unequal"<<endl;  
    if(Line7 == Line9) cout<<"Lines 7&9 are equal"<<endl;  else cout<<"Lines 7&9 are unequal"<<endl; 
    
    //Case2
    if(Line7 != Line8) cout<<"Lines 7&8 are unequal"<<endl;  else cout<<"Lines 7&8 are equal"<<endl;  
    if(Line7 != Line9) cout<<"Lines 7&9 are unequal"<<endl;  else cout<<"Lines 7&9 are equal"<<endl; 
    
    //Case3
    if(Line7 < Line8)  cout<<"Line 7 is < Line 8"<<endl;  else cout<<"Line 7 is !< Line 8"<<endl;  
    if(Line7 < Line9)  cout<<"Line 7 is < Line 9"<<endl;  else cout<<"Line 7 is !< Line 9"<<endl; 
    if(Line7 <= Line8) cout<<"Line 7 is <= Line 8"<<endl;  else cout<<"Line 7 is !<= Line 8"<<endl;  
    if(Line7 <= Line9) cout<<"Line 7 is <= Line 9"<<endl;  else cout<<"Line 7 is !<= Line 9"<<endl;  
    
    //Case4
    if(Line7 > Line8)  cout<<"Line 7 is > Line 8"<<endl;  else cout<<"Line 7 is !> Line 8"<<endl;  
    if(Line7 > Line9)  cout<<"Line 7 is > Line 9"<<endl;  else cout<<"Line 7 is !> Line 9"<<endl;  
    if(Line7 >= Line8) cout<<"Line 7 is >= Line 8"<<endl;  else cout<<"Line 7 is !>= Line 8"<<endl;  
    if(Line7 >= Line9) cout<<"Line 7 is >= Line 9"<<endl;  else cout<<"Line 7 is !>= Line 9"<<endl;  
   
    
    
    // The following test cases is targetting the different iterators for both Line2D and Line2DImpl classes
    // defining vector of segments forming 3 blocks
    // defining Line2DImpl object to access HalfSegments then cast to Line2D to access the block and segments iterators
    //
    // Case1: define Line2DImpl object with string constructor, access the internal halfsegments through iterators operators.
    // Case2: casting the Line2DImpl to Line2D, access the internal blocks through iterators operators
    // Case3: access the internal blocks through iterators operators
    // Case4: the comparison operators between segment iterators.
    
     
    //Case1
    Line2DImpl Line8Impl("(((0,0),(1,1)),((1,1),(2,2)),((3,3),(4,4)),((4,4),(5,5)),((6,6),(7,7)),((7,7),(8,8)))");
    
    Line2DImpl::ConstHalfSegIterator l3HSegItrF,l3HSegItrL;  //half-segment iterators 
    l3HSegItrF = Line8Impl.hBegin();                         //defining iterator points to the first half-seg
    l3HSegItrL = Line8Impl.hEnd();                           //defining iterator points to the last half-seg
    
    HalfSeg2D hsegFB = *l3HSegItrF;                          //dereferencing the iterators to HalfSeg2D object
    HalfSeg2D hsegLB = *l3HSegItrL;                          //dereferencing the iterators to HalfSeg2D object
    
    cout<<"First Half-Segment Dereferencing: "<<hsegFB<<endl;  //display the halfSegments after dereferencing
    cout<<"Last Half-Segment Dereferencing: " <<hsegLB<<endl;  //display the halfSegments after dereferencing
    
    cout<<"First HSeg: "<<l3HSegItrF<<endl;                    //display the iterator value
    cout<<"First HSeg address: " <<&l3HSegItrF<<endl;          //display the iterator memory address
    cout<<"Last HSeg:  "<<l3HSegItrL<<endl;                    //display the iterator value
    cout<<"Last HSeg address:  " <<&l3HSegItrL<<endl;          //display the iterator memory address
    cout<<"First HSeg with operator ++: " <<++l3HSegItrF<<endl;
    cout<<"Last HSeg with operator --:  " <<--l3HSegItrL<<endl;
    
    //iterator loop through the Line3Impl structure
    for ( Line2DImpl::ConstHalfSegIterator l3HSegItr = Line8Impl.hBegin(); l3HSegItr < Line8Impl.hTail(); ++l3HSegItr )
        cout << " output: " << l3HSegItr << endl; 
    
    
    //Case2
    Line2D& Line10 = Line8Impl;
    Line2D::ConstBlockIterator l3BlockItrF,l3BlockItrL;  		//Block iterators 
    l3BlockItrF = Line10.bBegin();                        		//defining iterator points to the first Block
    l3BlockItrL = Line10.bEnd();                        		//defining iterator points to the last Block
    
    Line2D lineFB = *l3BlockItrF;                          		//dereferencing the iterators to Line2D object
    Line2D lineLB = *l3BlockItrL;                          		//dereferencing the iterators to Line2D object
    cout<<"First Block Dereferencing: "<<lineFB<<endl;          //display the Line2D after dereferencing
    cout<<"Last Block Dereferencing: " <<lineLB<<endl;          //display the Line2D after dereferencing
    
    cout<<"First Block: "<<l3BlockItrF<<endl;  	                 //display the iterator value
    cout<<"First Block address: " <<&l3BlockItrF<<endl;          //display the iterator memory address
    cout<<"Last Block:  "<<l3BlockItrL<<endl;  	                 //display the iterator value
    cout<<"Last Block address:  " <<&l3BlockItrL<<endl;          //display the iterator memory address
    cout<<"First Block after ++: " <<++l3BlockItrF<<endl;
    cout<<"Last Block after --:  " <<--l3BlockItrL<<endl;
    
    //iterator loop through the Line10 structure
    for ( Line2D::ConstBlockIterator l3BlockItr = Line10.bBegin(); l3BlockItr < Line10.bTail(); ++l3BlockItr )
        cout << " output: " << l3BlockItr << endl; 
    
    
    
    
    //Case3
    Line2D::ConstSegIterator l3SegItrF,l3SegItrL;  			     //segment iterator
    l3SegItrF = Line10.sBegin();                        		 //defining iterator points to the first segment
    l3SegItrL = Line10.sEnd();                        		     //defining iterator points to the last segment
    
    Seg2D segFB = *l3SegItrF;                          		     //dereferencing the iterators to Seg2D object
    Seg2D segLB = *l3SegItrL;                        		     //dereferencing the iterators to Seg2D object
    cout<<"First Segment Dereferencing: "<<segFB<<endl;          //display the Seg2D after dereferencing
    cout<<"Last Segment Dereferencing: " <<segLB<<endl;          //display the Seg2D after dereferencing
    
    cout<<"First Segment: "<<l3SegItrF<<endl;  	                 //display the iterator value
    cout<<"First Segment: " <<&l3SegItrF<<endl;          		 //display the iterator memory address
    cout<<"Last Segment:  "<<l3SegItrL<<endl;  	                 //display the iterator value
    cout<<"Last Segment:  " <<&l3SegItrL<<endl;                  //display the iterator memory address
    cout<<"First Segment after ++: " <<++l3SegItrF<<endl;
    cout<<"Last Segment after --:  " <<--l3SegItrL<<endl;
    
    //iterator loop through the Line10 structure
    for ( Line2D::ConstSegIterator l3SegItr = Line10.sBegin(); l3SegItr < Line10.sTail(); ++l3SegItr )
        cout << " output " << l3SegItr << endl; 
    
    
    //Case4
    
    Line2D lxy("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)))");
    Line2D::ConstSegIterator ity;
    ity = lxy.sEnd();
    
    for ( Line2D::ConstSegIterator l3SegItr = lxy.sBegin(); l3SegItr < lxy.sTail(); ++l3SegItr )
	{
		if(l3SegItr == ity) cout<<"l3SegItr == ity"<<endl;    else cout<<"l3SegItr != ity"<<endl;  
        if(l3SegItr != ity) cout<<"l3SegItr != ity"<<endl;    else cout<<"l3SegItr == ity"<<endl;
        if(l3SegItr < ity)  cout<<"l3SegItr < ity"<<endl;     else cout<<"l3SegItr !< ity"<<endl;  
        if(l3SegItr <= ity) cout<<"l3SegItr <= ity"<<endl;    else cout<<"l3SegItr !<= ity"<<endl; 
        if(l3SegItr > ity)  cout<<"l3SegItr > ity"<<endl;     else cout<<"l3SegItr !> ity"<<endl;  
        if(l3SegItr >= ity) cout<<"l3SegItr >= ity"<<endl;    else cout<<"l3SegItr !>= ity"<<endl; 
	}
	
    cout<<"------------------END OF LINE TESTING------------------\n";
    return 0;
}
