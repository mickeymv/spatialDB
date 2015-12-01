/******************************************************************************
* File: Line2DImpl.cpp
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

#include "Line2DImpl.h"
    
    struct Line2D::ConstSegIterator::ConstSegIteratorImplementation{
      int iteratorIndex;
      Line2D::Line2DSImpl* current;     //pointer to the full structure
    };
    struct Line2D::Line2DSImpl{
	  std::map<int, std::vector<HalfSeg2D *>> mapHseg; //map of vectors holding pointers for the blocks' halfsegments within segments 
      std::vector<HalfSeg2D> segments;                 //ordered set of all segments regarding the full Line2D structure
      Line2D::ConstSegIterator::ConstSegIteratorImplementation first;  //pointer to the segments vector
      Line2D::ConstSegIterator::ConstSegIteratorImplementation last;   //pointer to the segments vector
    };
    struct Line2DImpl::ConstBlockIterator::ConstBlockIteratorImplementation{
      int iteratorIndex;
      Line2D::Line2DSImpl* current=NULL;     //pointer to the full structure
    };

    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2D object.
    Line2DImpl::Line2DImpl():Line2D(){}

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2D object in the sense that it conforms to the
    // formal definition of this data type.
    Line2DImpl::Line2DImpl(std::vector<Seg2D> segmentList):Line2D(segmentList){}


    // Constructor for complex region structure. It takes as input a string name that can represent either :
    // 1) file name which contains the vector of segments from which to construct the region object 
    // 2) string the textually represents the input vector of segments.
    //
    // The grammar for representing a segment vector in both cases 1 and 2 are structured as follows:
    // Expression := '(' Segment+ ')'
    // Segment:= '(' Point ',' Point ')'
    // Point:= '(' Number ',' Number ')'
    // Number := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign := ['+' | '-']
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit:= '0' | DigitWithoutZero
    //
    // example for segment list of seg1 and seg2 here is: (((1,2),(3,4)),((5,6),(7,8)))
    Line2DImpl::Line2DImpl(std::string textRepresentation):Line2D(textRepresentation){}

    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2DImpl::Line2DImpl(Line2DImpl& source){
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
		std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::copy(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
	}

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2DImpl::Line2DImpl(Line2DImpl&& source){
	    handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->first.iteratorIndex = source.handle->first.iteratorIndex;
	    handle->last.iteratorIndex = source.handle->last.iteratorIndex;
	    handle->first.current = source.handle;
	    handle->last.current = source.handle;
		std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::move(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
	}
    
    //Destructor
    Line2DImpl::~Line2DImpl(){
		//delete Line2D::handle;
    }
   	
    //++++++++++++++++++++++
    //++ Block iterator ++++
    //++++++++++++++++++++++
    // Constant block iterator type that allows to navigate through the blocks of
    // a Line2D object in forward and reverse direction. A change of the
    // blocks is not possible.
        
        // Default constructor that creates an empty constant block iterator.
        Line2DImpl::ConstBlockIterator::ConstBlockIterator(){
		  handlei = new ConstBlockIteratorImplementation;
		  handlei->iteratorIndex = 0;
		  handlei->current = NULL;
        }

        // Copy constructor that constructs a constant block iterator from a
        // given constant block iterator "source".
        Line2DImpl::ConstBlockIterator::ConstBlockIterator(const ConstBlockIterator& source){
		  handlei->iteratorIndex = source.handlei->iteratorIndex;
		  handlei->current = source.handlei->current;
        }

        // Move constructor that moves a given constant block iterator "source"
        // to a constant block iterator. The constant block iterator "source"
        // gets the empty constant block iterator as its value.
        Line2DImpl::ConstBlockIterator::ConstBlockIterator(const ConstBlockIterator&& source){
			handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
			handlei->current = std::move(source.handlei->current);
        }

        // Destructor that frees the main memory space allocated for a constant
        // block iterator.
        Line2DImpl::ConstBlockIterator::~ConstBlockIterator(){
			delete handlei;
        }

        // Assignment operator that assigns another constant block iterator
        // "rhs" to the constant block iterator.
        Line2DImpl::ConstBlockIterator& Line2DImpl::ConstBlockIterator::operator = (const ConstBlockIterator& rhs){
			handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
			handlei->current = rhs.handlei->current; 
        }

        // Predicate that tests whether a constant block iterator is empty.
        bool Line2DImpl::ConstBlockIterator::isEmpty() const{
			return (handlei->current == NULL);
        }

        // Increment/decrement operators '++', '--'
        Line2DImpl::ConstBlockIterator& Line2DImpl::ConstBlockIterator::operator ++ ()
        {
			 handlei->iteratorIndex++;
			 return(*this);
        }   // prefix
        Line2DImpl::ConstBlockIterator& Line2DImpl::ConstBlockIterator::operator ++ (int prefix)
        {
			 handlei->iteratorIndex++;
			 return(*this);
        } // postfix
        Line2DImpl::ConstBlockIterator& Line2DImpl::ConstBlockIterator::operator -- ()
        {
			 handlei->iteratorIndex--;
			 return(*this);
        }   // prefix
        Line2DImpl::ConstBlockIterator& Line2DImpl::ConstBlockIterator::operator -- (int prefix)
        {
			 handlei->iteratorIndex--;
			 return(*this);
        } // postfix

        // Dereferencing operators that return the value at the constant block
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a block. The dereferenced value cannot be changed.
        const vector<HalfSeg2D*>& Line2DImpl::ConstBlockIterator::operator *() const
        {
			//return(this.handlei->current->mapHseg[this.handlei->iteratorIndex]);
        }
        const vector<HalfSeg2D*>* Line2DImpl::ConstBlockIterator::operator ->() const
        {
			//return(&this.handlei->current->mapHseg[this.handlei->iteratorIndex]);  
        }

        // Comparison operators that compare a constant block iterator position
        // with another const block iterator position "rhs"
        bool Line2DImpl::ConstBlockIterator::operator == (const ConstBlockIterator& rhs) const{	
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstBlockIterator::operator != (const ConstBlockIterator& rhs) const{
			return ((this->handlei->current != rhs.handlei->current)||(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstBlockIterator::operator <  (const ConstBlockIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstBlockIterator::operator <= (const ConstBlockIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstBlockIterator::operator >  (const ConstBlockIterator& rhs) const{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstBlockIterator::operator >= (const ConstBlockIterator& rhs) const{
		   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }

	  std::ostream&operator<<(std::ostream& os, const Line2DImpl::ConstBlockIterator& output){
		os << "index Value:" << output.handlei->iteratorIndex<<" ";
		os << "size of vector:" << output.handlei->current->mapHseg.find(output.handlei->iteratorIndex)->second.size()<<" ";
		os << "size of vector:" << &output.handlei->current->mapHseg[output.handlei->iteratorIndex].at(0)<<" ";
		os << "size of vector:" << *output.handlei->current->mapHseg[output.handlei->iteratorIndex].at(0)<<" ";
		return os;
	  }

	  
    // Method that returns a constant block iterator to the first block of a
    // Line2D object.
    Line2DImpl::ConstBlockIterator Line2DImpl::cbegin() const
    {
		ConstBlockIterator begin;
		begin.handlei->iteratorIndex = 0;
		begin.handlei->current = handle;
		return begin;
    }

    // Method that returns a constant block iterator to the last block of a
    // Line2D object.
    Line2DImpl::ConstBlockIterator Line2DImpl::cend() const
    {
	   ConstBlockIterator last;
	   last.handlei->iteratorIndex = handle->mapHseg.size()-1;
	   last.handlei->current = handle;
  	   return last;
    }

    // Method that returns a constant block iterator to the position before the
    // first block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    Line2DImpl::ConstBlockIterator Line2DImpl::chead() const
    {
    }

    // Method that returns a constant block iterator to the position after the
    // last block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    Line2DImpl::ConstBlockIterator Line2DImpl::ctail() const
    {
    }


