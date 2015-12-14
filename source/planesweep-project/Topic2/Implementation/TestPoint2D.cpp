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
    // Testing Point2D
    //The following test cases are targetting the different constructors for Point2D classes
    // Case1: default constructor
    // Case2: string constructor
    // Case3: Poi2D vector constructor
    // Case4: Copy constructor
    // Case5: Copy assignment operation
    // Case6: incorrect string for constructor
    
    cout << "\n\n------------------POINT Testing starts here ----------------------\n" <<endl;

    //Case1
    Point2D Point0;                             
    cout<<"Point0 info is: " << Point0;
    if(Point0.isEmptyPoint2D()) 
       cout<<"empty Point0 structure"<<endl; 
    else 
       cout<<"nonempty Point0 structure"<<endl;
    cout<<"Point0 number of points is " << Point0.numPoints()<<endl;
    cout<<endl;
    
    //Case2
    Point2D Point1("((1,1),(2,2),(3,3))");                             
    cout<<"Point1 info is " << Point1;
    if(Point1.isEmptyPoint2D()) 
        cout<<"empty Point1 structure"<<endl; 
    else 
        cout<<"nonempty Point1 structure"<<endl;
    cout<<"Point1 number of points is " << Point1.numPoints()<<endl;
    cout<<endl;
    
    //Case3
    vector<Poi2D> singlepoint1;
    for(int i=0;i<3;i++)
	{    //random fill of poi2D vectors
       int randomx= rand() % 10 + 1;
       int randomy= rand() % 10 + 1;
       singlepoint1.push_back(Poi2D(Number(std::to_string(randomx)),Number(std::to_string(randomy))));
    }
    Point2D Point2(singlepoint1);
    cout<<"Point2 info is " << Point2;
    if(Point2.isEmptyPoint2D()) 
       cout<<"empty Point2 structure"<<endl; 
    else 
       cout<<"nonempty Point2 structure"<<endl;
    cout<<"Point2 number of points is " << Point2.numPoints()<<endl;
    cout<<endl;
    
    
    //Case4
    Point2D testPoint1("((7,7),(3,3),(2,2))");
    Point2D Point3(testPoint1);
    cout<<"Point3 info is " << Point3;
    if(Point3.isEmptyPoint2D()) 
       cout<<"empty Point3 structure"<<endl; 
    else 
       cout<<"nonempty Point3 structure"<<endl;
    cout<<"Point3 number of points is " << Point3.numPoints()<<endl;
    cout<<endl;
    
    
    //Case5
    Point2D testPoint2("((5,6),(7,8),(9,1))");
    Point2D Point4 = testPoint2;
    cout<<"Point4 info is " << Point4;
    if(Point4.isEmptyPoint2D()) 
       cout<<"empty Point4 structure"<<endl; 
    else 
       cout<<"nonempty Point4 structure"<<endl;
    cout<<"Point4 number of points is " << Point4.numPoints()<<endl;
    cout<<endl;
    
    
    //Case6
    Point2D Pointxy("(1,1),(2,2),(3,3))");                             //empty Point2D structure
    cout<<"Pointxy info is " << Pointxy;
    if(Pointxy.isEmptyPoint2D()) 
        cout<<"empty Pointxy structure"<<endl; 
    else 
        cout<<"nonempty Pointxy structure"<<endl;
    cout<<"Pointxy number of points is " << Pointxy.numPoints()<<endl;
    cout<<endl;
    
    
    //The following test cases is targetting the different comparison operators between different point2d objects
    // Case1: == operator
    // Case2: != operator
    // Case3: < & <= operators
    // Case4: > & >= operators
    
    
    Point2D Point5("((0,0),(1,1),(2,2),(3,3),(4,4))");
    Point2D Point8("((0,0),(1,1),(2,2),(3,3),(4,4))");
    Point2D Point9("((0,0),(1,1),(2,2),(3,3),(5,5),(6,6))");
    
    //Case1
    if(Point5 == Point8) cout<<"Point2d 5&8 are equal"<<endl;  else cout<<"Point2D 5&8 are unequal"<<endl;  
    if(Point5 == Point9) cout<<"Point2D 5&9 are equal"<<endl;  else cout<<"Point2D 5&9 are unequal"<<endl; 
    
    //Case2
    if(Point5 != Point8) cout<<"Point2D 5&8 are unequal"<<endl;  else cout<<"Point2D 5&8 are equal"<<endl;  
    if(Point5 != Point9) cout<<"Point2D 5&9 are unequal"<<endl;  else cout<<"Point2D 5&9 are equal"<<endl; 
    
    //Case3
    if(Point5 < Point8)  cout<<"Point2D 5 is < Point2D 8"<<endl;  else cout<<"Point2D 5 is !< Point2D 8"<<endl;  
    if(Point5 < Point9)  cout<<"Point2D 5 is < Point2D 9"<<endl;  else cout<<"Point2D 5 is !< Point2D 9"<<endl; 
    if(Point5 <= Point8) cout<<"Point2D 5 is <= Point2D 8"<<endl;  else cout<<"Point2D 5 is !<= Point2D 8"<<endl;  
    if(Point5 <= Point9) cout<<"Point2D 5 is <= Point2D 9"<<endl;  else cout<<"Point2D 5 is !<= Point2D 9"<<endl;  
    
    //Case4
    if(Point5 > Point8)  cout<<"Point2D 5 is > Point2D 8"<<endl;  else cout<<"Point2D 5 is !> Point2D 8"<<endl;  
    if(Point5 > Point9)  cout<<"Point2D 5 is > Point2D 9"<<endl;  else cout<<"Point2D 5 is !> Point2D 9"<<endl;  
    if(Point5 >= Point8) cout<<"Point2D 5 is >= Point2D 8"<<endl;  else cout<<"Point2D 5 is !>= Point2D 8"<<endl;  
    if(Point5 >= Point9) cout<<"Point2D 5 is >= Point2D 9"<<endl;  else cout<<"Point2D 5 is !>= Point2D 9"<<endl;  
   
    
    
    // The following test cases is targetting the Point iterators for Point2D classes
    // define Point2D object with string constructor, access the internal Poi2D through iterator operators.
    // case1: defining the ConstPoiIterator object with the different constructors.
    // case2: dereferencing into poi2D objects and incrementing/decrementing operators
    // case3: iterator for loop on all poi2D objects
    // case4: comparision operators for iterators.
    
    //case1:
    Point2D Point6("((0,0),(1,1),(2,2),(3,3),(4,4))");
    Point2D::ConstPoiIterator itr,itr2,itr3;
    itr = Point6.cbegin();    							//iterator that points to the first poi2D object
    itr2 = Point6.cend();    							//iterator that points to the last poi2D object
    itr3 = itr;                                                                 //iterator with assignemnt operator
    Point2D::ConstPoiIterator itr4(itr2);  				        //copy constructor for iterator
    cout<<"Test result of cbegin: " <<itr<<endl;  		                //display iterator information
    cout<<"Test result of cend: " <<itr2<<endl;  		                //display iterator information
    cout<<"equal operator for iterator: " <<itr3<<endl;                         //display iterator information
    cout<<"equal operator for iterator: " <<itr4<<endl;                         //display iterator information
    cout<<"Test result of dereference operator *: " <<*itr2<<endl;              //display the dereferencing * operator result
    cout<<"Test result of dereference operator &: " <<&itr2<<endl;              //display the dereferencing & operator result
    
    //case2:
    Poi2D itrv1=*itr;   						        //dereference to poi2D object
    Poi2D itrv2=*itr2;   						        //dereference to poi2D object
    cout<<"Value of dereference to poi2D: "<<itrv1<<endl; 		        //display the value of itrv1 poi2D
    cout<<"Value of dereference to poi2D: "<<itrv2<<endl; 		        //display the value of itrv2 poi2d
    cout<<"Test result of prefix ++ " <<++itr<<endl;                            //display the value of itr after incrementing
    cout<<"Test result of prefix --: " <<--itr2<<endl;                          //display the value of itr2 after decrementing
    
    //case3:
    for ( Point2D::ConstPoiIterator it = Point6.cbegin(); it < Point6.ctail(); ++it )
        cout << " output " << it << endl; 

    //case4
    Point2D structN("((1,1),(2,2),(3,3))");
    Point2D::ConstPoiIterator itx,ity;
    itx = structN.cbegin();
    ity = structN.cend();
    
    if(itx == ity) cout<<"itx == ity"<<endl;    else cout<<"itx != ity"<<endl;  
    if(itx != ity) cout<<"itx != ity"<<endl;    else cout<<"itx == ity"<<endl;
    if(itx < ity) cout<<"itx < ity"<<endl;    else cout<<"itx !< ity"<<endl;  
    if(itx <= ity) cout<<"itx <= ity"<<endl;    else cout<<"itx !<= ity"<<endl; 
    if(itx > ity) cout<<"itx > ity"<<endl;    else cout<<"itx !> ity"<<endl;  
    if(itx >= ity) cout<<"itx >= ity"<<endl;    else cout<<"itx !>= ity"<<endl;  
    ++itx;
    --ity;
    if(itx == ity) cout<<"itx == ity"<<endl;    else cout<<"itx != ity"<<endl;  
    if(itx != ity) cout<<"itx != ity"<<endl;    else cout<<"itx == ity"<<endl;
    if(itx < ity) cout<<"itx < ity"<<endl;    else cout<<"itx !< ity"<<endl;  
    if(itx <= ity) cout<<"itx <= ity"<<endl;    else cout<<"itx !<= ity"<<endl; 
    if(itx > ity) cout<<"itx > ity"<<endl;    else cout<<"itx !> ity"<<endl;  
    if(itx >= ity) cout<<"itx >= ity"<<endl;    else cout<<"itx !>= ity"<<endl;    
    
    cout<<"------------------END OF POINT TESTING------------------\n";
    return 0;
}
