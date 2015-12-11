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
 
using namespace std;


int main() 
{
    
    // Testing Region2D
    // The following test cases are targetting the different test cases for both Region2DImpl and Region2D classes
    // Simple Region is sequence of segments forming a face(made of cycle) with hole or without hole 
    // A complex region is sequence of segments forming multiple cycles which inturn form multiple faces with or without holes
    // Case1: default empty constructor for both classes
    // Case2: Seg2D vector constructor for both classes 
    // Case3: string input constructor and invalid region testing
    // Case4: Copy and Move constructors
    // Case5: Copy and Assignment Operators
    // Case6: Comparison operators ==, != , < , <=, >, >= for both classes
    // Case7: Unary predicates and operations 
    // Case8: Face iterator test cases
    // Case9: Cycle iterator test cases
    // Case10: Attributed Half Segment iterator test cases
    // The last 3 iterator test cases include 8 test cases within each of them as below:
    // 1. Constructor, begin, end cases , 2. Assignment operator , 3. Copy & Move Constructors , 4. Increment operators
    // 5. Decrement operators , 6. Dereferencing operators , 7. Comparison operators , 8. Use case of iterator with class   


    //Constructing segments required to construct cycles and then faces   
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
   
    vector<Seg2D> Seg2, Seg3;

    vector<Seg2D> Seg4, Seg5;

    Seg2.push_back(s1);
    Seg2.push_back(s2);
    Seg2.push_back(s3);
    Seg2.push_back(s4);
    Seg2.push_back(s5);
    Seg2.push_back(s6);
 
  
    Seg3.push_back(s7);
    Seg3.push_back(s8);
    Seg3.push_back(s9);

    
    Seg4.push_back(s10);
    Seg4.push_back(s11);
    Seg4.push_back(s12);
    Seg4.push_back(s13);
    Seg4.push_back(s14);
    Seg4.push_back(s15);
    Seg4.push_back(s16);
    Seg4.push_back(s17);
    Seg4.push_back(s18);
    Seg4.push_back(s19);
    Seg4.push_back(s20);
    
    Seg5.push_back(s13);
    Seg5.push_back(s14);
    Seg5.push_back(s15);
    Seg5.push_back(s16);
    Seg5.push_back(s17);
    Seg5.push_back(s18);
    Seg5.push_back(s19);
    Seg5.push_back(s20);
    
    cout << "\n\n------------------REGION Testing starts here ----------------------\n" <<endl;
    
    //Case1
    cout<<"---------------TESTING EMPTY CONSTRUCTOR FOR Region---------------"<<endl;
    Region2D Region0;    
    cout<<"Region0 output is:  "<< Region0 <<endl;
    Region2DImpl RegionImpl0;
    cout<<"RegionImpl0 output is:   "<< RegionImpl0 << endl;

    //Case2
    cout<<"\n---------------TESTING CONSTRUCTOR FOR Region---------------"<<endl;
    Region2D Region1(Seg2);
    cout<<"Region 1 output is:"<<Region1;
    cout<<"\n---------------TESTING CONSTRUCTOR FOR Region Implementation---------------"<<endl;
    Region2DImpl RegionImpl1(Seg2);
    cout<<"Region Implementation 1 is:"<<RegionImpl1;

    //Case3
    cout<<"\n---------------TESTING CONSTRUCTOR FOR Region from text input---------------"<<endl;
    Region2D Region2("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");
    cout<<"Region2 output is:"<<Region2 <<endl;
    Region2D NotRegion2("(((3,3),(3,4)),((4,3),(4,4)),((3,3),(4,3)))");
    cout<<"NotRegion2 output is:"<<NotRegion2<<endl;
       
    //Case4
    cout<<"\n---------------COPY & MOVE CONSTRUCTORS ---------------"<<endl;
    Region2D Region3(Region2);
    cout<<"\nTest result of region copy constructor:\n "<<Region3<<endl;

    Region2D Region4(std::move(Region2));
    cout<<"\nTest result of region move constructor:\n Region 4: \n "<<Region4<<endl;
    cout<<"\nTest result of region move constructor:\n Region 2: \n "<<Region2<<endl;
   
    
    //Case5
    cout<<"\n---------------------------Testing Assignment Operators----------------------"<<endl;
    Region2D Region42, Region62;
    Region2D Region41(Seg2);
    Region2D Region61(Seg3);
    cout << "....... Testing COPY ASSIGNMENT operator .......  \n" << endl;
    Region42 = Region41 ;
    cout << "New Region 42\n" << Region42 << endl ;
    cout << "Old Region 41\n" << Region41 << endl ;

   
    cout << "....... Testing MOVE ASSIGNMENT operator .......  \n" << endl;
    Region62 = (std::move(Region61)) ;
    cout << "New Region 62\n" << Region62 << endl ;
    cout << "Old Region 61\n" << Region61 << endl ;
     
    

    //Case6
    cout<<"\n---------------------------Testing Comparison Operators----------------------"<<endl;
    
    Region2D Region5(Seg5);
    Region2DImpl Region50(Seg2);
    Region2DImpl Region51(Seg3);

    cout<<"-----*****Testing Equals(==) Operator*****-----"<<endl;
    if(Region4 == Region3) cout<<"Regions 4 and 3 are equal"<<endl;  
    else cout<<"Regions 4 and 3 are not equal"<<endl;  

    if(Region1 == Region3) cout<<"Regions 1 and 3 are equal"<<endl;  
    else cout<<"Regions 1 and 3 are not equal"<<endl;

    cout<<"-----*****Testing Not Equals(!=) Operator*****-----"<<endl;
    if(Region4 != Region3) cout<<"Regions 4 and 3 are not equal"<<endl;  
    else cout<<"Regions 4 and 3 are equal"<<endl;  

    if(Region1 != Region3) cout<<"Regions 1 and 3 are not equal"<<endl;  
    else cout<<"Regions 1 and 3 are equal"<<endl;

    
    cout<<"-----*****Testing Less Than(<) Operator*****-----"<<endl;
    if(Region50 < Region51)  cout<<" Region 50 is less than equal to Region 51 "<<endl;  
    else cout<<" Region 50 is not less than equal to Region 51 "<<endl;  
    

    cout<<"-----*****Testing Less Than Equals(<=) Operator*****------"<<endl;
    if(Region50 <= Region51)  cout<<"Region 50 is less than equal to Region 51"<<endl;  
    else cout<<"Region 50 is not less than Region 51"<<endl;  
    

    cout<<"-----*****Testing Greater Than(>) Operator*****-----"<<endl;
    if(Region50 > Region51)  cout<<" Region 50 is greater than Region 51 "<<endl;  
    else cout<<" Region 50 is not greater than Region 51"<<endl;  
    

    cout<<"-----*****Testing Greater Than Equals(>=) Operator*****-----"<<endl;
    if(Region50 >= Region51)  cout<<" Region 50 is greater than equal to Region 51"<<endl;  
    else cout<<" Region 50 is not greater than equal to Region 51 "<<endl;  
    
    


    //Case7
    cout<<"\n---------------Testing Unary predicates and operations------------"<<endl;
    
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
    
    Region2D Region6("(((4,3),(6,4)),((4,3),(6,2)),((6,2),(6,4)))");
    cout << "Testing outer cycle for complex region having multi-faces \n" <<  Region1.getOuterCycle() << endl;
    cout << "Testing outer cycle for Simple Region with holes \n " << Region5.getOuterCycle() <<endl ; 
    cout << "Testing outer cycle for Simple Region without holes \n" <<  Region6.getOuterCycle() << endl;

    
    


    cout<<"\n----------------ITERATORS TESTING-----------------------\n"<<endl;
    
    //Case8
    cout<<"\n---------------Testing Face iterator---------\n"<<endl;
    
    //Case8-1
    Region2D::ConstFaceIterator F1, F2, F3 ;
    F1 = Region1.cFbegin();
    F2 = Region1.cFend();
    cout<< "Result of cbegin of face iterator for Region 1 \n" << F1 << endl;
    cout<< "Result of cend of face iterator for Region 1 \n" << F2 << endl;
    
    //Case8-2
    F3 = F2 ;
    cout << "....... Testing assignment operator ==.......  \n" << F3 << endl ;
    
    //Case8-3
    Region2D::ConstFaceIterator F4(F3);
    cout << "....... Testing copy constructor....... \n" << F4 <<endl;
    Region2D::ConstFaceIterator F5(std::move(F2));
    cout << "....... Testing move constructor....... \n" << F5 <<endl;
    
    //Case8-4
    cout<< ".....Testing increment operators...... \n "<<endl;
    cout<< "Value before incrementing : \n" << F1 << endl;
    cout<<"Value during postfix increment: \n" <<  F1++<<endl;
    cout<<"Value after postfix increment is done: \n" <<F1<<endl;
    cout<< "Testing prefix increment \n"<< ++F1 << endl;
    cout<<"-----------------------------------"<<endl;
    
    //Case8-5
    cout<< ".....Testing decrement operators......\n "<<endl;
    cout<< "Value before decrementing : \n" << F1 << endl;
    cout<<"Value during postfix decrement: \n" <<F1--<<endl;
    cout<<"Value after postfix decrement is done: \n" <<F1<<endl;
    cout<< "Testing prefix decrement \n"<< --F1 ;
    cout<<"-----------------------------------"<<endl;
    
    //Case8-6
    cout<< ".......Testing dereferencing.........." << *F1 << endl;   
    cout<< ".......Testing dereferencing.........." << &F1 << endl;

    //Case8-7
    cout<< ".......Testing comparison operators for iterators......\n";
    cout << "F1: " << F1 << endl;
    cout << "F2: " << F2 << endl;
    cout << "F3: " << F3 << endl;
    cout << "\n Equal operator testing "<<endl;
    if( F2 == F3 )
      cout << " F2 , F3 are equal  "<<endl;   
    cout << "\n Unequal operator testing "<<endl; 
    if ( F1 != F2 ) 
      cout << " F1 , F2 are not equal  "<<endl;
    cout << "\n Less than operator testing "<<endl;
    if( F1 < F2 )
      cout << " F1 is less than F2 " << endl;
    cout << "\n Less than or equal to operator testing "<<endl;
    if( F1 <= F2 )
      cout << " F1 is less than or equal to F2 " << endl;   
    cout << "\n Greater than operator testing "<<endl;
    if( F3 > F1 )
      cout << " F3 is greater than F1 " << endl;
    cout << "\n Greater than or equal to operator testing "<<endl;
    if ( F3 >= F2 )
      cout << " F3 greater than or equal to F2 " << endl;
    
    //Case8-8
    cout<<"\n------------------ITERATING!!!!!!-----------------"<<endl;
    for ( Region2D::ConstFaceIterator F1 = Region1.cFbegin(); F1 < Region1.cFtail(); ++F1 )
        cout << " output " << F1 << endl;


    //Case9
    cout<<"\n--------------------Testing Cycle iterator--------------\n"<<endl;
    
    //Case9-1
    Region2D::ConstCycleIterator C1, C2, C3 ;
    C1 = Region1.cHbegin();
    C2 = Region1.cHend();
    cout<< "Result of cbegin of cycle iterator for Region 1 \n" << C1 << endl;
    cout<< "Result of cend of cycle iterator for Region 1 \n" << C2 << endl;
    
    //Case9-2
    C3 = C2 ;
    cout << "....... Testing assignment operator ==.......  \n" << C3 << endl ;
    
    //Case9-3
    Region2D::ConstCycleIterator C4(C3);
    cout << "....... Testing copy constructor....... \n" << C4 <<endl;
    
    Region2D::ConstCycleIterator C5(std::move(C2));
    cout << "....... Testing move constructor....... \n" << C5 <<endl;
    
    //Case9-4
    cout<< ".....Testing increment operators...... \n "<<endl;
    cout<< "Value before incrementing : \n" << C1 << endl;
    cout<<"Value during postfix increment: \n" <<  C1++<<endl;
    cout<<"Value after postfix increment is done: \n" <<C1<<endl;
    cout<< "Testing prefix increment \n"<< ++C1 << endl;
    cout<<"-----------------------------------"<<endl;
    
    //Case9-5
    cout<< ".....Testing decrement operators......\n "<<endl;
    cout<< "Value before decrementing : \n" << C1 << endl;
    cout<<"Value during postfix decrement: \n" <<C1--<<endl;
    cout<<"Value after postfix decrement is done: \n" <<C1<<endl;
    cout<< "Testing prefix decrement \n"<< --C1 ;
    cout<<"-----------------------------------"<<endl;
 
    //Case9-6
    cout<< ".......Testing dereferencing.........." << *C1 << endl;
    cout<< ".......Testing dereferencing.........." << &C1 << endl;
  
    //Case9-7
    cout<< ".......Testing comparison operators for iterators......\n";
    cout << "C1: " << C1 << endl;
    cout << "C2: " << C2 << endl;
    cout << "C3: " << C3 << endl;
    cout << "\n Equal operator testing "<<endl;
    if( C2 == C3 )
      cout << " C2 , C3 are equal  "<<endl;
    cout << "\n Unequal operator testing "<<endl; 
    if ( C1 != C2 ) 
      cout << " C1 , C2 are not equal  "<<endl;
    cout << "\n Less than operator testing "<<endl;
    if( C1 < C2 )
      cout << " C1 is less than C2 " << endl;
    if( C2 < C1 )
        cout << " C2 is less than C1 " << endl;
    cout << "\n Less than or equal to operator testing "<<endl;
    //checks less than
    if( C1 <= C2 )
      cout << " C1 is less than or equal to C2 " << endl;
    if( C2 <= C1 )
      cout << " C2 is less than or equal to C1 " << endl;
    //checks equal
    if( C2 <= C3 )
      cout << " C2 is less than or equal to C3 " << endl;
    cout << "\n Greater than operator testing "<<endl;
    if( C3 > C1 )
      cout << " C3 is greater than C1 " << endl;
    if( C1 > C3 )
        cout << " C1 is greater than C3 " << endl;
    cout << "\n Greater than or equal to operator testing "<<endl;
    //checks greater than
    if ( C3 >= C1 )
      cout << " C3 greater than or equal to C1 " << endl;
    if( C1 >= C3 )
      cout << " C1 is greater than or equal to C3 " << endl;
    //checks equal
    if( C2 >= C3 )
      cout << " C2 is less than or equal to C3 " << endl;
   
    //Case9-8
    cout<<"\n------------------ITERATING!!!!!!-----------------"<<endl;
    for ( Region2D::ConstCycleIterator C1 = Region1.cHbegin(); C1 < Region1.cHtail(); ++C1 )
        cout << " output " << C1 << endl;
  

  
    //Case10
    cout<<"--------------------Testing Attributed Half Segment iterator--------------\n"<<endl;
    
    //Case10-1
    Region2DImpl::ConstAttributedHalfSegmentIterator At1, At2, At3 ;
    At1 = RegionImpl1.cbegin();
    At2 = RegionImpl1.cend();   
    cout<< "Result of cbegin of attributed half segment iterator for Region Implementation 1 \n" << At1 << endl;
    cout<< "Result of cend of attributed half segment iterator for Region Implementation 1 \n" << At2 << endl;
    
    //Case10-2
    At3 = At2 ;
    cout << "....... Testing assignment operator ==.......  \n" << At3 << endl ;
    
    //Case10-3
    Region2DImpl::ConstAttributedHalfSegmentIterator At4(At3);
    cout << "....... Testing copy constructor....... \n" << At4 <<endl;
    Region2DImpl::ConstAttributedHalfSegmentIterator At5(std::move(At2));
    cout << "....... Testing move constructor....... \n" << At5 <<endl;
    
    //Case10-4
    cout<< ".....Testing increment operators...... \n "<<endl;
    cout<< "Value before incrementing : \n" << At1 << endl;
    cout<<"Value during postfix increment: \n" <<  At1++<<endl;
    cout<<"Value after postfix increment is done: \n" <<At1<<endl;
    cout<< "Testing prefix increment \n"<< ++At1 << endl;
    cout<<"-----------------------------------"<<endl;
    
    //Case10-5
    cout<< ".....Testing decrement operators......\n "<<endl;
    cout<< "Value before decrementing : \n" << At1 << endl;
    cout<<"Value during postfix decrement: \n" <<At1--<<endl;
    cout<<"Value after postfix decrement is done: \n" <<At1<<endl;
    cout<< "Testing prefix decrement \n"<< --At1 ;
    cout<<"-----------------------------------"<<endl;

    //Case10-6
    cout<< "\n.......Testing dereferencing.........." << *At1 << endl;
    cout<< "\n.......Testing dereferencing.........." << &At1 << endl;
  
    //Case10-7
    cout<< ".......Testing comparison operators for iterators......\n";
    cout << "At1: " << At1 << endl;
    cout << "At2: " << At2 << endl;
    cout << "At3: " << At3 << endl;
    cout << "\n Equal operator testing "<<endl;
    if( At2 == At3 )
      cout << " At2 , At3 are equal  "<<endl;
    cout << "\n Unequal operator testing "<<endl; 
    if ( At1 != At2 ) 
      cout << " At1 , At2 are not equal  "<<endl;
    cout << "\n Less than operator testing "<<endl;
    if( At1 < At2 )
      cout << " At1 is less than At2 " << endl;
    if( At2 < At1 )
        cout << " At2 is less than At1 " << endl;
    cout << "\n Less than or equal to operator testing "<<endl;
    //checks less than
    if( At1 <= At2 )
      cout << " At1 is less than or equal to At2 " << endl;
    if( At2 <= At1 )
      cout << " At2 is less than or equal to At1 " << endl;
    //checks equal
    if( At2 <= At3 )
      cout << " At2 is less than or equal to At3 " << endl;
    cout << "\n Greater than operator testing "<<endl;
    if( At3 > At1 )
      cout << " At3 is greater than At1 " << endl;
    if( At1 > At3 )
        cout << " At1 is greater than At3 " << endl;
    cout << "\n Greater than or equal to operator testing "<<endl;
    //checks greater than
    if ( At3 >= At1 )
      cout << " At3 greater than or equal to At1 " << endl;
    if( At1 >= At3 )
      cout << " At1 is greater than or equal to At3 " << endl;
    //checks equal
    if( At2 >= At3 )
      cout << " At2 is less than or equal to At3 " << endl;

    //Case10-8
    cout<<"\n------------------ITERATING!!!!!!-----------------"<<endl;
    for ( Region2DImpl::ConstAttributedHalfSegmentIterator At1 = RegionImpl1.cbegin(); At1 < RegionImpl1.ctail(); ++At1 )
        cout << " output " << At1 << endl;
    cout<<"------------------END OF REGION TESTING------------------\n";

    return 0;
}

