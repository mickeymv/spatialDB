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
	
	//runing the code:
	//  g++ -std=c++0x SpatialDataType.cpp Point2D.cpp Number.cpp RobustGeometricPrimitives2D.cpp Line2D.cpp
    //  ./a.out
    
    
    vector<Poi2D> singlepoint;
    int randomx,randomy;
    for(int i=0;i<3;i++){
       randomx= rand() % 10 + 1;
       randomy= rand() % 10 + 1;
       singlepoint.push_back(Poi2D(Number(randomx),Number(randomy)));
    }
    
    cout<<"display vector initialized Point2D: "<<endl;
    Point2D struct2(singlepoint);
    cout<<struct2<<endl;
    
    Point2D::ConstPoiIterator itr;
    itr = struct2.cbegin();
    cout<<itr<<endl;
    
    Point2D::ConstPoiIterator itr2;
    itr2 = struct2.cend();
    cout<<itr2<<endl;
    
    
    
    
    
    
    /*
     * vector<Seg2D> segVec;
    int randomx,randomy,randomx2,randomy2;
    for(int i=0;i<3;i++){
       randomx= rand() % 10 + 1;
       randomy= rand() % 10 + 1;
       randomx2= rand() % 10 + 1;
       randomy2= rand() % 10 + 1;
       segVec.push_back(Seg2D(Poi2D(randomx,randomy),Poi2D(randomx2,randomy2)));
    }
    
    for(int j=0;j<segVec.size();j++){
       cout<<segVec.at(j);
    }
    * */
    
    
	
	/*
    cout<<"display empty Point2D: "<<endl;
    Point2D struct1;
    cout<<struct1<<endl; //empty Point2D structure
    
    //testing point2D class functions and iterators.
    vector<Poi2D> singlepoint;
    int randomx,randomy;
    for(int i=0;i<3;i++){
       randomx= rand() % 10 + 1;
       randomy= rand() % 10 + 1;
       singlepoint.push_back(Poi2D(Number(randomx),Number(randomy)));
    }
    
    cout<<"display vector initialized Point2D: "<<endl;
    Point2D struct2(singlepoint); //Point2D structure with 3 points
    cout<<struct2<<endl;

    string strPoints = "((3,4),(5,6),(7,8))";
    cout<<"display string initialized Point2D: "<<endl;
    Point2D struct3(strPoints); //Point2D structure with 3 points
    cout<<struct3<<endl;
    
    cout<<struct3.numPoints()<<endl;
  
    if(struct3.isEmptyPoint2D()) 
       cout<<"struct 3 is empty"<<endl;
    if(struct1.isEmptyPoint2D()) 
       cout<<"struct 1 is empty"<<endl;
    
    cout<<"test copy constructor: "<<endl;
    Point2D struct4(struct2);
    cout<<struct4<<endl;
    
    cout<<"test assignment operator: "<<endl;
    Point2D struct5 = struct3;
    cout<<struct5<<endl;
    
    //cout<<"test move constructor: "<<endl;
    //Point2D struct4(struct2);
    //cout<<struct4<<endl;
    
    cout<<"move assignment operator: "<<endl;
    Point2D struct7 = std::move(struct5);
    cout<<"struct 5"<<endl;
    cout<<struct5<<endl;
    cout<<"struct 7"<<endl;
    cout<<struct7<<endl;
    
    
    cout<<"test Operators !! "<<endl;
    string strPoints1 = "((3,4),(5,6),(7,8))";
    string strPoints2 = "((3,4),(5,6))";
    string strPoints3 = "((3,4),(5,6),(7,8))";
    
    Point2D structx(strPoints1);
    Point2D structy(strPoints2);
    Point2D structz(strPoints1);
    if(structx == structy){cout<<"struct x and y are equal ! "<<endl;}
    else{cout<<"struct x and y are notequal ! "<<endl;}
    
    if(structx == structz){cout<<"struct x and z are equal ! "<<endl;}
    else{cout<<"struct x and z are notequal ! "<<endl;}
    
    
    string strPoints4 = "((1,2),(5,7))";
    string strPoints5 = "((4,3),(3,6),(7,8))";
    
    Point2D structm(strPoints4);
    Point2D structn(strPoints5);
    if(structm < structn){cout<<"struct m < n ! "<<endl;}
    else{cout<<"struct m not < n  ! "<<endl;}
    if(structm > structn){cout<<"struct m > n ! "<<endl;}
    else{cout<<"struct m not > n  ! "<<endl;}
    
    */
	return 0;
}
