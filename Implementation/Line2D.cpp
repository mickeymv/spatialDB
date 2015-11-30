/******************************************************************************
* File: Line2D.cpp
*******************************************************************************
* Purpose: Interface to the class for the spatial data type Line2D
*
* Description: This file specifies interface to the class Line2D and to
*   several nested iterator classes that enable access to components (that is,
*   segments) of Line2D objects. The class Line2D contains
*   specifications of several constructors, a destructor, and several
*   type-specific unary methods of this spatial data type. Binary spatial
*   operations that involve Line2D objects are specified elsewhere. 
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 2 (Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain)
*
* Date: Fall Semester 2015
******************************************************************************/

#include "Line2D.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <regex>
#include <string>
#include <iterator>

  struct Line2D::ConstSegIterator::ConstSegIteratorImplementation{
    int iteratorIndex;
    Line2D::Line2DSImpl* current;     //pointer to the full structure
  };
  struct Line2D::Line2DSImpl{
	 std::map<int, std::vector<HalfSeg2D *>> mapHseg; //map of vectors holding pointers for the blocks' halfsegments within segments 
     std::vector<HalfSeg2D> segments;                 //ordered set of all segments regarding the full Line2D structure
     Line2D::ConstSegIterator::ConstSegIteratorImplementation first;  //pointer to the segments vector
     Line2D::ConstSegIterator::ConstSegIteratorImplementation last;   //pointer to the segments vector
     Line2D::ConstSegIterator::ConstSegIteratorImplementation head;
     Line2D::ConstSegIterator::ConstSegIteratorImplementation tail;
  };

    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2D object.
    Line2D::Line2D()
    {
	    handle = new Line2DSImpl;
	    handle->segments.clear();
	    handle->mapHseg.clear();
	    handle->first.iteratorIndex = 0;
	    handle->last.iteratorIndex = 0;
        handle->head.iteratorIndex = 0;
        handle->tail.iteratorIndex = 0;
	    handle->first.current = handle;
	    handle->last.current = handle;
        handle->head.current = handle;
        handle->tail.current = handle;
    }

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2D object in the sense that it conforms to the
    // formal definition of this data type.
    Line2D::Line2D(std::vector<Seg2D> segs){
		//dividing the segments in both left and right half-segments.  for all 1<i<2n
		//for all half-segments i<>j .. the segments are either equal or disjoint or meet.
	    handle = new Line2DSImpl;
	    handle->segments.clear();
	    handle->mapHseg.clear();
	    handle->first.iteratorIndex = 1;
	    handle->first.current = handle;
	    handle->last.current = handle;
	    
	    if(segs.empty()){
			return;
		}
		
		
		vector<HalfSeg2D> halfsegments;
        HalfSeg2D* he;
		HalfSeg2D* hl;
		HalfSeg2D* hr;
		for(int i=0;i<segs.size();i++){
		     hl = new HalfSeg2D(segs.at(i),true);
	         hr = new HalfSeg2D(segs.at(i),false);
		     halfsegments.push_back(*hl);
		     halfsegments.push_back(*hr);
		     delete hl;
		     delete hr;
		}
	    
		HalfSeg2D swap;
		for (int c = 0 ; c < (halfsegments.size()-1); c++){
			for (int d = 0 ; d < (halfsegments.size()-c-1); d++){
			  if (halfsegments.at(d+1) < halfsegments.at(d)){
				swap = halfsegments.at(d);
				halfsegments.at(d) = halfsegments.at(d+1);
				halfsegments.at(d+1) = swap;
			  }
			}
		}
		
		/*
		for(int i=0;i<halfsegments.size();i++){
		     for(int j=0;j<halfsegments.size();j++){
			  if(i!=j){
				  Seg2D seg1 = halfsegments.at(i).seg;
				  Seg2D seg2 = halfsegments.at(j).seg;
				  if(Intersects(seg1,seg2)){
					cout<<"incorrect segments provided"<<endl; 
					return;
				  }
		          if(!Meet(seg1,seg2)||!Touch(seg1,seg2)||seg1 == seg2){
					cout<<"incorrect segments provided"<<endl; 
					return;
				  }
			  }
		     }
		}
		*/
		
        he = new HalfSeg2D();
        handle->segments.push_back(*he); //empty segment for chead()
	    for (int i = 0 ; i < halfsegments.size(); i++){
		    if(halfsegments.at(i).isLeft){
			      handle->segments.push_back(halfsegments.at(i));
			}
	    }
	    
        handle->segments.push_back(*he); //empty segment for ctail
	    handle->last.iteratorIndex = handle->segments.size();
	    handle->tail.iteratorIndex = handle->segments.size()+1;
		int size = handle->segments.size()-2;
		std::vector<HalfSeg2D *> currentVector;
		std::vector<HalfSeg2D *> tempVector;
		int mbc = 0;
		int index = 0;
		int flags[size];
		for (int i = 1; i<size; i++){
			flags[i] = 0;
		}
		
		for (int k = 1; k<size; k++){
		     //cout<<k;
			if (flags[k] == 0){//unflaged segment.
			    index = 0;
				currentVector.clear();
				currentVector.push_back(&handle->segments.at(k));
				flags[k]=1;
				for (int i = 0; i<size; i++){
					if (flags[i] == 0){//unflaged segment.
						for ( int j = index; j<currentVector.size(); j++){       
							if (Meet(currentVector.at(j)->seg, handle->segments.at(i).seg)){
								tempVector.push_back(&handle->segments.at(i));
								flags[i] = 1;
							}
						}
						index = currentVector.size();
						for (int c = 0; c<tempVector.size(); c++){
							currentVector.push_back(tempVector[c]);
						}
						tempVector.clear();
					}
				}//inner for loop
		      //cout<<k;
			 handle->mapHseg[mbc++] = currentVector;
			}
		}//outer for loop
    }




    // Constructor for complex Line structure. It takes as input a string that represent the textually represents
    //        the input vector of Segments.
    //
    // The grammar for representing a Segment vector is structured as follows:
    // Expression       := '(' Segment (',' [WhiteSpace] Segment)* ')'
    // Segment          := '(' '(' Number ',' [WhiteSpace] Number ')' ',' '(' Number ',' [WhiteSpace] Number ')' ')'
    // Number           := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign             := ['+' | '-']
    // WhiteSpace       := ' '
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit            := '0' | DigitWithoutZero
    //
    // example for segment list of seg1 and seg2 here is: (((1,2),(3,4)),((5,6),(7,8)))  
    Line2D::Line2D(std::string textualLineList){
		handle = new Line2DSImpl;
	    handle->segments.clear();
	    handle->mapHseg.clear();
	    handle->first.iteratorIndex = 1;
	    handle->first.current = handle;
	    handle->last.current = handle;
	    
		textualLineList.erase(std::remove(textualLineList.begin(), textualLineList.end(), ')'), textualLineList.end());
	    textualLineList.erase(std::remove(textualLineList.begin(), textualLineList.end(), '('), textualLineList.end());
	    std::istringstream ss(textualLineList);
	    vector<Seg2D> segs;
	    std::string token;
	    Number N1,N2,N3;
	    int count=0;
	    while(std::getline(ss, token, ',')){
	          if(count==0){
	            count=1;
	            N1= Number(token.c_str());
	          }
              else if(count==1){
	            count=2;
	            N2= Number(token.c_str());
	          }
              else if(count==2){
	            count=3;
	            N3= Number(token.c_str());
	          }
              else if(count==3){
	            count=0; 
	            segs.push_back(Seg2D(Poi2D(N1,N2),Poi2D(N3,Number(token.c_str()))));
	          }
	      }
		
		vector<HalfSeg2D> halfsegments;
        HalfSeg2D* he;
		HalfSeg2D* hl;
		HalfSeg2D* hr;
		for(int i=0;i<segs.size();i++){
		     hl = new HalfSeg2D(segs.at(i),true);
	         hr = new HalfSeg2D(segs.at(i),false);
		     halfsegments.push_back(*hl);
		     halfsegments.push_back(*hr);
		     delete hl;
		     delete hr;
		}
	    
		HalfSeg2D swap;
		for (int c = 0 ; c < (halfsegments.size()-1); c++){
			for (int d = 0 ; d < (halfsegments.size()-c-1); d++){
			  if (halfsegments.at(d+1) < halfsegments.at(d)){
				swap = halfsegments.at(d);
				halfsegments.at(d) = halfsegments.at(d+1);
				halfsegments.at(d+1) = swap;
			  }
			}
		}
		
		/*
		for(int i=0;i<halfsegments.size();i++){
		     for(int j=0;j<halfsegments.size();j++){
			  if(i!=j){
				  Seg2D seg1 = halfsegments.at(i).seg;
				  Seg2D seg2 = halfsegments.at(j).seg;
				  if(Intersects(seg1,seg2)){
					cout<<"incorrect segments provided"<<endl; 
					return;
				  }
		          if(!Meet(seg1,seg2)||!Touch(seg1,seg2)||seg1 == seg2){
					cout<<"incorrect segments provided"<<endl; 
					return;
				  }
			  }
		     }
		}
		*/
		
        he = new HalfSeg2D();
        handle->segments.push_back(*he); //empty segment for chead()
	    for (int i = 0 ; i < halfsegments.size(); i++){
		    if(halfsegments.at(i).isLeft){
			      handle->segments.push_back(halfsegments.at(i));
			}
	    }
        handle->segments.push_back(*he); //empty segment for ctail
        
        
		cout<<"test"<<endl;
		for(int i=0;i<handle->segments.size();i++){
			cout<<handle->segments.at(i);
		}
        
	    handle->last.iteratorIndex = handle->segments.size();
	    handle->tail.iteratorIndex = handle->segments.size()+1;
		int size = handle->segments.size()-2;
		std::vector<HalfSeg2D *> currentVector;
		std::vector<HalfSeg2D *> tempVector;
		int mbc = 0;
		int index = 0;
		int flags[size];
		for (int i = 1; i<size; i++){
			flags[i] = 0;
		}
		
		for (int k = 1; k<size; k++){
		     //cout<<k;
			if (flags[k] == 0){//unflaged segment.
			    index = 0;
				currentVector.clear();
				currentVector.push_back(&handle->segments.at(k));
				flags[k]=1;
				for (int i = 1; i<size; i++){
					if (flags[i] == 0){//unflaged segment.
						for ( int j = index; j<currentVector.size(); j++){       
							if (Meet(currentVector.at(j)->seg, handle->segments.at(i).seg)){
								tempVector.push_back(&handle->segments.at(i));
								flags[i] = 1;
							}
						}
						index = currentVector.size();
						for (int c = 0; c<tempVector.size(); c++){
							currentVector.push_back(tempVector[c]);
						}
						tempVector.clear();
					}
				}//inner for loop
		      //cout<<k;
			 handle->mapHseg[mbc++] = currentVector;
			}
		}//outer for loop
    }



    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2D::Line2D(const Line2D& source){
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
        handle->head.iteratorIndex = source.handle->head.iteratorIndex;
	    handle->tail.iteratorIndex = source.handle->tail.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
        handle->head.current = source.handle;
	    handle->tail.current = source.handle;
		std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::copy(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
    }

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2D::Line2D(Line2D&& source){
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
        handle->head.iteratorIndex = source.handle->head.iteratorIndex;
	    handle->tail.iteratorIndex = source.handle->tail.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
        handle->head.current = source.handle;
	    handle->tail.current = source.handle;
		std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::move(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
    }
    
    //Destructor
    Line2D::~Line2D(){
		delete handle;
    }

    
    //+++++++++++++++++++++
    // Assignment operators
    //+++++++++++++++++++++

    // Copy assignment operator that assigns a Line2D object "source" to the
    // Line2D object.
    Line2D& Line2D::operator = (const Line2D& source){
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
        handle->head.iteratorIndex = source.handle->head.iteratorIndex;
	    handle->tail.iteratorIndex = source.handle->tail.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
        handle->head.current = source.handle;
	    handle->tail.current = source.handle;
		std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::copy(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
    }

    // Move assignment operator that moves a Line2D object "source" to the
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2D& Line2D::operator = (Line2D&& source){
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
        handle->head.iteratorIndex = source.handle->head.iteratorIndex;
	    handle->tail.iteratorIndex = source.handle->tail.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
        handle->head.current = source.handle;
	    handle->tail.current = source.handle;
		std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::move(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
    }

    
    //+++++++++++++++++++++
    // Comparison operators
    //+++++++++++++++++++++

    // Comparison operators ==, !=, <, <=, >, and >=. 
	//equal operator that checks if the Line2D object and input Line2D
    //object are the same spatial region.
    bool Line2D::operator == (Line2D& operand){
		if(handle->segments.size() != operand.handle->segments.size())  
		  return false;
		for (unsigned i=1; i < handle->segments.size(); i++){
		  if(handle->segments.at(i) != operand.handle->segments.at(i))
			return false;
		}
		return true;
    }
	
    //unequal operator that checks if the Line2D object and the inputted
    //Line2D object are different spatial regions. It is the logical opposite
    //of the == operator.
    bool Line2D::operator != (Line2D& operand){
		if(handle->segments.size() != operand.handle->segments.size())  
		  return true;
		for (unsigned i=0; i < handle->segments.size(); i++){
		  if(handle->segments.at(i) != operand.handle->segments.at(i))
			return true;
		}
		return false;
    }
	
    //less than operator that compares 2 Line2D objects and checks which one is lesser 
    //by comparing their minimum bounding rectangles in the following way:
    //if min(x1) < min(x2) the object is less than "source" object
    //max (x1) < max (x2)
    //min(y1) < min(y2)
    //max(y1) < max(y2)
    bool Line2D::operator <  (Line2D& operand)
    {
	  if(isEmptyLine2D() || operand.isEmptyLine2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=0; i < x; i++) {
	    if (handle->segments.at(i) < operand.handle->segments.at(i))
	      return true;
	    else if (handle->segments.at(i) > operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (operand.handle->segments.size() > handle->segments.size())   
	    return true;
	  return false;
    } 

    //less than operator that compares 2 Line2D objects and checks which one is lesser 
    //or equal by comparing their minimum bounding rectangles in the following way:
    //if min(x1) <= min(x2) the object is less than "source" object
    //max (x1) <= max (x2)
    //min(y1) <= min(y2)
    //max(y1) <= max(y2)	
    bool Line2D::operator <= (Line2D& operand){	 
	  if(isEmptyLine2D() || operand.isEmptyLine2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=0; i < x; i++) {
	    if (handle->segments.at(i) == operand.handle->segments.at(i))
	      return true;
	    if (handle->segments.at(i) < operand.handle->segments.at(i))
	      return true;
	    else if (handle->segments.at(i) > operand.handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (operand.handle->segments.size() > handle->segments.size())   
	    return true;
	  return false;
    }   

    //less than operator that compares 2 Line2D objects and checks which one is greater 
    //by comparing their minimum bounding rectangles in the following way:
    //if min(x1) > min(x2) the object is less than "source" object
    //max (x1) > max (x2)
    //min(y1) > min(y2)
    //max(y1) > max(y2)	
    bool Line2D::operator >  (Line2D& operand)
    {
	  if(isEmptyLine2D() || operand.isEmptyLine2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x-1; i++) {
	    if (operand.handle->segments.at(i) > handle->segments.at(i))
	      return true;
	    else if (operand.handle->segments.at(i) < handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (operand.handle->segments.size() < handle->segments.size())   
	    return true;
	  return false;
    }  

    //less than operator that compares 2 Line2D objects and checks which one is greater 
    //or equal by comparing their minimum bounding rectangles in the following way:
    //if min(x1) >= min(x2) the object is less than "source" object
    //max (x1) >= max (x2)
    //min(y1) >= min(y2)
    //max(y1) >= max(y2)
    bool Line2D::operator >= (Line2D& operand)
    {
	  if(isEmptyLine2D() || operand.isEmptyLine2D()) 
		return false;
	  int x = (handle->segments.size() < operand.handle->segments.size()) ? handle->segments.size() : operand.handle->segments.size();
      for (unsigned i=1; i < x-1; i++) {
	    if (handle->segments.at(i) == operand.handle->segments.at(i))
	      return true;
	    if (operand.handle->segments.at(i) >= handle->segments.at(i))
	      return true;
	    else if (operand.handle->segments.at(i) < handle->segments.at(i))
	      return false;
	    else
	      continue;
	  }
	  if (operand.handle->segments.size() < handle->segments.size())   
	    return true;
	  return false;
    }    


    //++++++++++++++++++++++++++++++++
    // Unary predicates and operations
    //++++++++++++++++++++++++++++++++

    // Predicate that checks whether a Line2D object is an empty Line2D
    // object. 
    bool Line2D::isEmptyLine2D(){
		if(handle->segments.size() == 0)
	        return true;
		if(handle->segments.size() == 2)
	        return true;
		return false;
    }
    
    // Method that yields the number of segments of Line2D object
    // If the Line2D object is an empty Line2D object, the value
    // 0 is returned.
    Number Line2D::getNumberOfSegments(){
		if(handle->segments.size() == 0)
	        return Number(std::to_string(0));
		if(handle->segments.size() == 2)
	        return Number(std::to_string(0));
		return Number(std::to_string(handle->segments.size()-2));
	}
    
    
    //Computing the minimum bounding rectangle for a line object
    Rect2D Line2D::MinBoundingRect(){
    }
  
    //++++++++++++++++
    // Output function
    //++++++++++++++++

    // Textual output of segments of a Line2D object
    std::ostream& operator << (ostream& os, const Line2D& output){
	  if(output.handle->mapHseg.size() == 0 )
	        os<<"Empty Line"<<endl;
	  for (int v=0; v<output.handle->mapHseg.size(); v++){
		for(int w = 0; w<output.handle->mapHseg[v].size(); w++){
			os <<"mb["<<v<<"]["<<w<<"]: "<<*output.handle->mapHseg[v][w]<<endl;
		}
	  }
      return os;
    }
    
    
    

    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant segment iterator type that allows to navigate through the segments of
    // a Line2D object in forward and reverse direction. A change of the
    // segments is not possible.
        
     // Default constructor that creates an empty constant segment iterator.
        Line2D::ConstSegIterator::ConstSegIterator()
        {
		  handlei = new ConstSegIteratorImplementation;
		  handlei->iteratorIndex = 0;
		  handlei->current = NULL;
        }

        // Copy constructor that constructs a constant segment iterator from a
        // given constant segment iterator "source".
        Line2D::ConstSegIterator::ConstSegIterator(const ConstSegIterator& source)
        {
		  handlei = new ConstSegIteratorImplementation;
          handlei->iteratorIndex = source.handlei->iteratorIndex;
		  handlei->current = source.handlei->current;
        }

        // Move constructor that moves a given constant segment iterator "source"
        // to a constant segment iterator. The constant segment iterator "source"
        // gets the empty constant segment iterator as its value.
        Line2D::ConstSegIterator::ConstSegIterator(const ConstSegIterator&& source)
        {	
			handlei = new ConstSegIteratorImplementation;
            handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
			handlei->current = std::move(source.handlei->current);
        }

        // Destructor that frees the main memory space allocated for a constant
        // segment iterator.
        Line2D::ConstSegIterator::~ConstSegIterator()
        {
			delete handlei;
        }

        // Assignment operator that assigns another constant segment iterator
        // "rhs" to the constant segment iterator.
        Line2D::ConstSegIterator& Line2D::ConstSegIterator::operator = (const ConstSegIterator& rhs)
        {
			handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
			handlei->current = rhs.handlei->current; 
        }

        // Predicate that tests whether a constant segment iterator is empty.
        bool Line2D::ConstSegIterator::isEmpty() const
        {
			return (handlei->current == NULL);
        }

        // Increment/decrement operators '++', '--'
        Line2D::ConstSegIterator& Line2D::ConstSegIterator::operator ++ ()
        {
			 handlei->iteratorIndex++;
			 return(*this);
        }   // prefix
        Line2D::ConstSegIterator Line2D::ConstSegIterator::operator ++ (int)
        {
			ConstSegIterator tmp(*this);
    			handlei->iteratorIndex++;
    			return(tmp);
        } // postfix
        Line2D::ConstSegIterator& Line2D::ConstSegIterator::operator -- ()
        {
			 handlei->iteratorIndex--;
			 return(*this);
        }   // prefix
        Line2D::ConstSegIterator Line2D::ConstSegIterator::operator -- (int)
        {
			ConstSegIterator tmp(*this);
    		handlei->iteratorIndex--;
    		return(tmp);
        } // postfix

        // Dereferencing operators that return the value at the constant segment
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a segment. The dereferenced value cannot be changed.
        const HalfSeg2D& Line2D::ConstSegIterator::operator *() const
        {
            return(this->handlei->current->segments.at(this->handlei->iteratorIndex));   
        }
        const HalfSeg2D* Line2D::ConstSegIterator::operator ->() const
        {
            return(&this->handlei->current->segments.at(this->handlei->iteratorIndex));  
        }

        // Comparison operators that compare a constant segment iterator position
        // with another const segment iterator position "rhs"
        bool Line2D::ConstSegIterator::operator == (const ConstSegIterator& rhs) const{	
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
        }
        bool Line2D::ConstSegIterator::operator != (const ConstSegIterator& rhs) const{	
			return ((this->handlei->current != rhs.handlei->current)||(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
        }
        bool Line2D::ConstSegIterator::operator <  (const ConstSegIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
        }
        bool Line2D::ConstSegIterator::operator <= (const ConstSegIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
        }
        bool Line2D::ConstSegIterator::operator >  (const ConstSegIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }
        bool Line2D::ConstSegIterator::operator >= (const ConstSegIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }

	  std::ostream&operator<<(std::ostream& os, const Line2D::ConstSegIterator& output)
	  {
		os << "index Value:" << output.handlei->iteratorIndex<<" ";
		os << "point Value:" << output.handlei->current->segments.at(output.handlei->iteratorIndex)<<" ";
		return os;
	  }


    // Method that returns a constant segment iterator to the first segment of a
    // Line2D object.
    Line2D::ConstSegIterator Line2D::cbegin() const
    {
		ConstSegIterator begin;
		begin.handlei->iteratorIndex = 1;
		begin.handlei->current = handle;
		return begin;
    }

    // Method that returns a constant segment iterator to the last segment of a
    // Line2D object.
    Line2D::ConstSegIterator Line2D::cend() const
    {
	   ConstSegIterator last;
	   last.handlei->iteratorIndex = handle->segments.size()-2;
	   last.handlei->current = handle;
  	   return last;
    }

    // Method that returns a constant segment iterator to the position before the
    // first segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    // Currently gives default value instead of empty iterator
    Line2D::ConstSegIterator Line2D::chead() const
    {
     ConstSegIterator h;
     h.handlei->iteratorIndex = 0;
     h.handlei->current = handle;
     return h;
    }

    // Method that returns a constant segment iterator to the position after the
    // last segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    //Currently gives default values instead of empty iterator
    Line2D::ConstSegIterator Line2D::ctail() const
    {
     ConstSegIterator t;
     t.handlei->iteratorIndex = handle->segments.size()-1;
     t.handlei->current = handle;
     return t;
    }
	

