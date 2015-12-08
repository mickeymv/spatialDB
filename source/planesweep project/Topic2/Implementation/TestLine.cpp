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
	// running the code:
    // g++ -std=c++0x TestLine.cpp Point2D.cpp Number.cpp RobustGeometricPrimitives2D.cpp BigInteger.cpp BigRational.cpp Line2D.cpp Line2DImpl.cpp
    // ./a.out
    
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
    
    
    Line2D el3;  //default constructor for empty line structure
    cout<<"Line 3 info is " << el3<<endl;
    cout<<"Line 3 number of segments is " << el3.getNumberOfSegments()<<endl;
    if(el3.isEmptyLine2D()) cout<<"Empty Line structure"<<endl;
    else                   cout<<"Not Empty Line structure"<<endl;
    
    Line2DImpl el3imp(Seg3);
    Line2DImpl::ConstHalfSegIterator l3HSegItrF,l3HSegItrL;  //block iterator on the line l3, of the previous step
    l3HSegItrF = el3imp.hBegin();
    l3HSegItrL = el3imp.hEnd();
    HalfSeg2D hsegFB = *l3HSegItrF;
    HalfSeg2D hsegLB = *l3HSegItrL;
    
    cout<<"First Half-Segment Dereferencing: "<<hsegFB<<endl;
    cout<<"Last Half-Segment Dereferencing: " <<hsegLB<<endl;
    
    
    
    cout<<"First HSeg: "<<l3HSegItrF<<endl;
    cout<<"First HSeg: " <<&l3HSegItrF<<endl;
    cout<<"First HSeg after ++: " <<l3HSegItrF++<<endl;
    cout<<"Last HSeg:  "<<l3HSegItrL<<endl;
    cout<<"Last HSeg:  " <<&l3HSegItrL<<endl;
    cout<<"Last HSeg after --:  " <<l3HSegItrL--<<endl;
    
    
    for ( Line2DImpl::ConstHalfSegIterator l3HSegItr = el3imp.hBegin(); l3HSegItr < el3imp.hTail(); ++l3HSegItr )
        cout << " output " << l3HSegItr << endl; 
    
    Line2D& l3 = el3imp;
    cout<<"Line 2 info is " << l3<<endl;
    cout<<"Line 3 number of segments is " << l3.getNumberOfSegments()<<endl;
    if(l3.isEmptyLine2D()) cout<<"Empty Line structure"<<endl;
    else                   cout<<"Not Empty Line structure"<<endl;
    
    Line2D::ConstBlockIterator l3BlockItrF,l3BlockItrL;  //block iterator on the line l3, of the previous step
    l3BlockItrF = l3.bBegin();
    l3BlockItrL = l3.bEnd();
    Line2D lineFB = *l3BlockItrF;
    Line2D lineLB = *l3BlockItrL;
    
    cout<<"First Block Dereferencing: "<<lineFB<<endl;
    cout<<"Last Block Dereferencing: " <<lineLB<<endl;
    
    
    cout<<"First Block: "<<l3BlockItrF<<endl;
    cout<<"First Block: " <<&l3BlockItrF<<endl;
    cout<<"First Block after ++: " <<l3BlockItrF++<<endl;
    cout<<"Last Block:  "<<l3BlockItrL<<endl;
    cout<<"Last Block:  " <<&l3BlockItrL<<endl;
    cout<<"Last Block after --:  " <<l3BlockItrL--<<endl;
    
    
    for ( Line2D::ConstBlockIterator l3BlockItr = l3.bBegin(); l3BlockItr < l3.bTail(); ++l3BlockItr )
        cout << " output " << l3BlockItr << endl; 
    
    Line2D::ConstSegIterator l3SegItrF,l3SegItrL;  //block iterator on the line l3, of the previous step
    l3SegItrF = l3.sBegin();
    l3SegItrL = l3.sEnd();
    Seg2D segFB = *l3SegItrF;
    Seg2D segLB = *l3SegItrL;
    
    cout<<"First Segment Dereferencing: "<<segFB<<endl;
    cout<<"Last Segment Dereferencing: " <<segLB<<endl;
    
    cout<<"First Segment: "<<l3SegItrF<<endl;
    cout<<"First Segment: " <<&l3SegItrF<<endl;
    cout<<"First Segment after ++: " <<l3SegItrF++<<endl;
    cout<<"Last Segment:  "<<l3SegItrL<<endl;
    cout<<"Last Segment:  " <<&l3SegItrL<<endl;
    cout<<"Last Segment after --:  " <<l3SegItrL--<<endl;
    
    
    for ( Line2D::ConstSegIterator l3SegItr = l3.sBegin(); l3SegItr < l3.sTail(); ++l3SegItr )
        cout << " output " << l3SegItr << endl; 
    
    cout<<"==================================================================="<<endl;
    cout<<"==================================================================="<<endl;
    cout<<"==================================================================="<<endl;
    
    
    Line2D l4("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)),((3,3),(4,4)))");
    Line2D l5("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)),((3,3),(4,4)))");
    Line2D l6("(((0,0),(1,1)),((1,1),(2,2)),((2,2),(3,3)),((4,4),(5,5)))");
    
    if(l4 == l5) cout<<"equal line 4 & 5"<<endl;  else cout<<"not equal line 4 & 5"<<endl;  
    if(l4 == l6) cout<<"equal line 4 & 6"<<endl;  else cout<<"not equal line 4 & 6"<<endl; 
    
    if(l4 < l5)  cout<<"line 4 < 5"<<endl;  else cout<<"line 4 !< 5"<<endl;  
    if(l4 < l6)  cout<<"line 4 < 6"<<endl;  else cout<<"line 4 !< 6"<<endl; 
    if(l4 <= l5) cout<<"line 4 <= 5"<<endl;  else cout<<"line 4 !<= 5"<<endl;  
    if(l4 <= l6) cout<<"line 4 <= 6"<<endl;  else cout<<"line 4 !<= 6"<<endl;  
    
    if(l4 > l5)  cout<<"line 4 > 5"<<endl;  else cout<<"line 4 !> 5"<<endl;  
    if(l4 > l6)  cout<<"line 4 > 6"<<endl;  else cout<<"line 4 !> 6"<<endl;  
    if(l4 >= l5) cout<<"line 4 >= 5"<<endl;  else cout<<"line 4 !>= 5"<<endl;  
    if(l4 >= l6) cout<<"line 4 >= 6"<<endl;  else cout<<"line 4 !>= 6"<<endl;  
    
    
    
    
    
    
    
    
    
    return 0;
}
