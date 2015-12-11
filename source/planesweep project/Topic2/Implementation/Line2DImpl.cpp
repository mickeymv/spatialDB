/******************************************************************************
* File: Line2DImpl.cpp
*******************************************************************************
* Purpose: Interface to the class for the spatial data type Line2DImpl
*
* Description: This file specifies interface to the class Line2DImpl and to
*   nested iterator class that enable access to internal components (that is,
*   Half-Segments) of Line2DImpl objects. The class Line2DImpl contains
*   specifications of several constructors, a destructor, and several
*   type-specific unary methods of this spatial data type. 
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 2 (Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain)
*
* Date: Fall Semester 2015
******************************************************************************/

#include "Line2DImpl.h"
    

    // Forward struct declaration for the hidden implementation of a
    // constant halfsegment iterator that holds the different variables of the iterator
    struct Line2DImpl::ConstHalfSegIterator::ConstHalfSegIteratorImplementation
	{
      int iteratorIndex = -1;                  //integer index for the pointer
      Line2D::Line2DSImpl* current=NULL;     //pointer to the full structure
    };

    // Forward struct declaration for the hidden implementation of a
    // constant segment iterator that holds the different variables of the iterator
    struct Line2D::ConstSegIterator::ConstSegIteratorImplementation
	{
      int iteratorIndex = -1;                  //integer index for the pointer
      Line2D::Line2DSImpl* current=NULL;     //pointer to the full structure
    };
    
    // Forward struct declaration for the hidden implementation of a
    // constant block iterator that holds the different variables of the iterator
    struct Line2D::ConstBlockIterator::ConstBlockIteratorImplementation
	{
      int iteratorIndex = -1;                  //integer index for the pointer
      Line2D::Line2DSImpl* current = NULL;     //pointer to the full structure
    };
    
    // Forward struct declaration for the hidden implementation of a
    // Line2D that holds the different variables of the line2D structure
    struct Line2D::Line2DSImpl
	{
	  std::map<int, std::vector<HalfSeg2D *>> mapHseg; //map of vectors holding pointers for the blocks' halfsegments within segments 
      std::vector<HalfSeg2D> segments;                 //ordered set of all HalfSegments regarding the full Line2D structure
      Line2D::ConstBlockIterator::ConstBlockIteratorImplementation firstBlock;  //pointer to the segments vector
      Line2D::ConstBlockIterator::ConstBlockIteratorImplementation lastBlock;   //pointer to the segments vector
    };

    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2DImpl object.
    Line2DImpl::Line2DImpl():Line2D()
	{
	}

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2DImpl object in the sense that it conforms to the
    // formal definition of this data type.
    Line2DImpl::Line2DImpl(std::vector<Seg2D> segmentList):Line2D(segmentList)
	{
	}


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
    Line2DImpl::Line2DImpl(std::string textRepresentation):Line2D(textRepresentation)
	{
	}

    // Copy constructor that constructs a Line2DImpl object from a given Line2DImpl
    // object "source".
    Line2DImpl::Line2DImpl(Line2DImpl& source)
	{
		handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->firstBlock.iteratorIndex = source.handle->firstBlock.iteratorIndex;
	    handle->lastBlock.iteratorIndex = source.handle->lastBlock.iteratorIndex;
	    handle->firstBlock.current = source.handle;
	    handle->lastBlock.current = source.handle;
		std::copy(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::copy(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
	}

    // Move constructor that moves a given Line2DImpl object "source" to a
    // Line2DImpl object. The Line2DImpl object "source" gets the empty Line2DImpl
    // object as its value.
    Line2DImpl::Line2DImpl(Line2DImpl&& source)
	{
	    handle = new Line2DSImpl;
		handle->segments.clear();
		handle->mapHseg.clear();
	    handle->firstBlock.iteratorIndex = source.handle->firstBlock.iteratorIndex;
	    handle->lastBlock.iteratorIndex = source.handle->lastBlock.iteratorIndex;
	    handle->firstBlock.current = source.handle;
	    handle->lastBlock.current = source.handle;
		std::move(source.handle->segments.begin(), source.handle->segments.end(),std::back_inserter(handle->segments));
		std::move(source.handle->mapHseg.begin(), source.handle->mapHseg.end(), std::inserter(handle->mapHseg,handle->mapHseg.end()) );
	}
    
    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant segment iterator type that allows to navigate through the segments of
    // a Line2D object in forward and reverse direction. A change of the
    // segments is not possible.
        
     // Default constructor that creates an empty constant halfsegment iterator.
        Line2DImpl::ConstHalfSegIterator::ConstHalfSegIterator()
        {
		  handlei = new ConstHalfSegIteratorImplementation;
		  handlei->iteratorIndex = -1;
		  handlei->current = NULL;
        }

        // Copy constructor that constructs a constant halfsegment iterator from a
        // given constant halfsegment iterator "source".
        Line2DImpl::ConstHalfSegIterator::ConstHalfSegIterator(const ConstHalfSegIterator& source)
        {
		  handlei = new ConstHalfSegIteratorImplementation;
          handlei->iteratorIndex = source.handlei->iteratorIndex;
		  handlei->current = source.handlei->current;
        }

        // Move constructor that moves a given constant halfsegment iterator "source"
        // to a constant halfsegment iterator. The constant halfsegment iterator "source"
        // gets the empty constant halfsegment iterator as its value.
        Line2DImpl::ConstHalfSegIterator::ConstHalfSegIterator(const ConstHalfSegIterator&& source)
        {	
			handlei = new ConstHalfSegIteratorImplementation;
            handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
			handlei->current = std::move(source.handlei->current);
        }

        // Destructor that frees the main memory space allocated for a constant
        // halfsegment iterator.
        Line2DImpl::ConstHalfSegIterator::~ConstHalfSegIterator()
        {
			delete handlei;
        }

        // Assignment operator that assigns another constant halfsegment iterator
        // "rhs" to the constant halfsegment iterator.
        Line2DImpl::ConstHalfSegIterator& Line2DImpl::ConstHalfSegIterator::operator = (const ConstHalfSegIterator& rhs)
        {
			handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
			handlei->current = rhs.handlei->current; 
        }

        // Predicate that tests whether a constant halfsegment iterator is empty.
        bool Line2DImpl::ConstHalfSegIterator::isEmpty() const
        {
			return (handlei->current == NULL);
        }

        // Increment/decrement operators '++', '--'
        Line2DImpl::ConstHalfSegIterator& Line2DImpl::ConstHalfSegIterator::operator ++ ()
        {
			handlei->iteratorIndex++;
		    return(*this);
        }   // prefix
        Line2DImpl::ConstHalfSegIterator Line2DImpl::ConstHalfSegIterator::operator ++ (int)
        {
			ConstHalfSegIterator tmp(*this);
    		handlei->iteratorIndex++;
    		return(tmp);
        } // postfix
        Line2DImpl::ConstHalfSegIterator& Line2DImpl::ConstHalfSegIterator::operator -- ()
        {
			handlei->iteratorIndex--;
			return(*this);
        }   // prefix
        Line2DImpl::ConstHalfSegIterator Line2DImpl::ConstHalfSegIterator::operator -- (int)
        {
			ConstHalfSegIterator tmp(*this);
    		handlei->iteratorIndex--;
    		return(tmp);
        } // postfix

        // Dereferencing operators that return the value at the constant halfsegment
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a halfsegment. The dereferenced value cannot be changed.
        const HalfSeg2D& Line2DImpl::ConstHalfSegIterator::operator *() const
        {
            return(this->handlei->current->segments.at(this->handlei->iteratorIndex));   
        }
        const HalfSeg2D* Line2DImpl::ConstHalfSegIterator::operator ->() const
        {
            return(&this->handlei->current->segments.at(this->handlei->iteratorIndex));  
        }

        // Comparison operators that compare a constant halfsegment iterator position
        // with another const halfsegment iterator position "rhs"
        bool Line2DImpl::ConstHalfSegIterator::operator == (const ConstHalfSegIterator& rhs) const
		{	
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstHalfSegIterator::operator != (const ConstHalfSegIterator& rhs) const
		{	
			return ((this->handlei->current != rhs.handlei->current)||(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstHalfSegIterator::operator <  (const ConstHalfSegIterator& rhs) const
		{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstHalfSegIterator::operator <= (const ConstHalfSegIterator& rhs) const
		{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstHalfSegIterator::operator >  (const ConstHalfSegIterator& rhs) const
		{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }
        bool Line2DImpl::ConstHalfSegIterator::operator >= (const ConstHalfSegIterator& rhs) const
		{
			return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
        }

	  std::ostream&operator<<(std::ostream& os, const Line2DImpl::ConstHalfSegIterator& output)
	  {
		os << "index Value:" << output.handlei->iteratorIndex<<" ";
		os << "point Value:" << output.handlei->current->segments.at(output.handlei->iteratorIndex)<<" ";
		return os;
	  }


    // Method that returns a constant halfsegment iterator to the first halfsegment of a
    // Line2DImpl object.
    Line2DImpl::ConstHalfSegIterator Line2DImpl::hBegin() const
    {
		ConstHalfSegIterator begin;
		begin.handlei->iteratorIndex = 1;
		begin.handlei->current = handle;
		return begin;
    }

    // Method that returns a constant halfsegment iterator to the last halfsegment of a
    // Line2DImpl object.
    Line2DImpl::ConstHalfSegIterator Line2DImpl::hEnd() const
    {
	   ConstHalfSegIterator last;
       if(handle->segments.size() >= 2)
         last.handlei->iteratorIndex = handle->segments.size()-2;
       else 
         last.handlei->iteratorIndex = 0;
	   last.handlei->current = handle;
  	   return last;
    }

    // Method that returns a constant halfsegment iterator to the position before the
    // first halfsegment of a Line2DImpl object. Note that dereferencing this iterator
    // yields the empty constant halfsegment iterator.
    // Currently gives default value instead of empty iterator
    Line2DImpl::ConstHalfSegIterator Line2DImpl::hHead() const
    {
		 ConstHalfSegIterator h;
		 h.handlei->iteratorIndex = 0;
		 h.handlei->current = handle;
		 return h;
    }

    // Method that returns a constant halfsegment iterator to the position after the
    // last halfsegment of a Line2DImpl object. Note that dereferencing this iterator
    // yields the empty constant halfsegment iterator.
    //Currently gives default values instead of empty iterator
    Line2DImpl::ConstHalfSegIterator Line2DImpl::hTail() const
    {
		 ConstHalfSegIterator t;
		 if(handle->segments.size() >= 1)
			t.handlei->iteratorIndex = handle->segments.size()-1;
		 else 
			t.handlei->iteratorIndex = 0;
		 t.handlei->current = handle;
		 return t;
    }
