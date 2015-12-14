/******************************************************************************
 *File: Region2DImpl.cpp
 /******************************************************************************
 *Purpose:This file specifies implemention of class Region2DImpl defined in 
 *the Region2DImpl.h file and the several nested iterator classes that enable 
 *access to components (that is, faces, cycles, segments) of Region2DImpl 
 *objects.

 *Created on: Oct 8, 2015

 *Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain

 * Date: Fall Semester 2015
*******************************************************************************/


#include "Region2DImpl.h"
using namespace std;


  struct Region2DImpl::ConstAttributedHalfSegmentIterator::ConstAttributedHalfSegmentIteratorImplementation{
      int iteratorIndex = -1;
      Region2D::Region2DImplementation* current = NULL;     //pointer to the full structure
  }; 

  struct Region2D::ConstFaceIterator::ConstFaceIteratorImplementation{
      int iteratorIndex = -1;
      Region2D::Region2DImplementation* current = NULL;     //pointer to the full structure
  };
  
  struct Region2D::ConstCycleIterator::ConstCycleIteratorImplementation{
      int iteratorIndex = -1;
      Region2D::Region2DImplementation* current = NULL;     //pointer to the full structure
  };

  struct Region2D::Region2DImplementation
  {
      std::vector<AttrHalfSeg2D> segments;         //ordered set of all attributed half segments regarding the full Region2D structure   
      std::map<int, std::vector<AttrHalfSeg2D *>> cycles;
      std::map<int, std::map<int, std::vector<AttrHalfSeg2D *>>> faces;
  };

  //++++++++++++++++++++++++++++
  // Constructors and destructor
  //++++++++++++++++++++++++++++

  //Empty constructor. Represents the empty region object.
  Region2DImpl::Region2DImpl():Region2D()
  {
    // inherits from Region2D 
  }

  //Constructor for complex Region2D object. It takes
  //inputs as a vector of seg2D objects and creates a
  //Region2D object after checking if a valid Region2D
  //object can be created from the input.
  Region2DImpl::Region2DImpl(std::vector<Seg2D> segmentList):Region2D(segmentList)
  {
	// inherits from Region2D 
  }

    // Constructor for complex region structure. It takes as input a string name that can represent:
    //  string that textually represents the input vector of segments.
    //
    // The grammar for representing a segment vector is structured as follows:
    // Expression := '(' Segment+ ')'
    // Segment:= '(' Point ',' Point ')'
    // Point:= '(' Number ',' Number ')'
    // Number := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign := ['+' | '-']
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit:= '0' | DigitWithoutZero
    //
    // example input: "(((4,3),(6,4)),((4,3),(5,2)),((5,2),(6,4)))"
  Region2DImpl::Region2DImpl(std::string textualRegionList):Region2D(textualRegionList)
  {
	// inherits from Region2D 
  }

  //copy constructor that constructs a new Region2D object with the same 
  //properties as the inputted Region2D object.
  Region2DImpl::Region2DImpl(Region2DImpl& source):Region2D(source)
  { 
    // inherits from Region2D 
  }

  // Move constructor that moves a given Region2D object "source" to a
  // Region2D object. The Region2D object "source" gets the empty Region2D
  // object as its value.
  Region2DImpl::Region2DImpl(Region2DImpl&& source):Region2D(source)
  {  
    // inherits from Region2D   
  }

  //Destructor
  Region2DImpl::~Region2DImpl()
  {
    //inherits from Region2D
  }

  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //All functions will be inherited from Region2D.cpp when called
  //Additional functions in the extended file start here
  //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  //++++++++++++++++++++
  // Iterator functions
  //++++++++++++++++++++

  // Default constructor that creates an empty constant AttributedHalfSegment iterator.
  Region2DImpl::ConstAttributedHalfSegmentIterator::ConstAttributedHalfSegmentIterator()
  {
   handlei = new ConstAttributedHalfSegmentIteratorImplementation;
   handlei->iteratorIndex = -1;
   handlei->current = NULL;
  }

  // Copy constructor that constructs a constant AttributedHalfSegment iterator from a
  // given constant AttributedHalfSegment iterator "source".
  Region2DImpl::ConstAttributedHalfSegmentIterator::ConstAttributedHalfSegmentIterator(const ConstAttributedHalfSegmentIterator& source)
  {
   handlei = new ConstAttributedHalfSegmentIteratorImplementation;
   handlei->iteratorIndex = source.handlei->iteratorIndex;
   handlei->current = source.handlei->current;  
  }

  // Move constructor that moves a given constant AttributedHalfSegment iterator "source"
  // to a constant AttributedHalfSegment iterator. The constant AttributedHalfSegment iterator "source"
  // gets the empty constant AttributedHalfSegment iterator as its value.
  Region2DImpl::ConstAttributedHalfSegmentIterator::ConstAttributedHalfSegmentIterator(const ConstAttributedHalfSegmentIterator&& source)
  {
   handlei = new ConstAttributedHalfSegmentIteratorImplementation;
   handlei->iteratorIndex = std::move(source.handlei->iteratorIndex);
   handlei->current = std::move(source.handlei->current);
  }

  // Destructor that frees the main memory space allocated for a constant
  // AttributedHalfSegment iterator.
  Region2DImpl::ConstAttributedHalfSegmentIterator::~ConstAttributedHalfSegmentIterator()
  {
   delete handlei;
  }

  // Assignment operator that assigns another constant AttributedHalfSegment iterator
  // "rhs" to the constant AttributedHalfSegment iterator.
  Region2DImpl::ConstAttributedHalfSegmentIterator& Region2DImpl::ConstAttributedHalfSegmentIterator::operator = (const ConstAttributedHalfSegmentIterator& rhs)
  {
    handlei->iteratorIndex = rhs.handlei->iteratorIndex; 
    handlei->current = rhs.handlei->current; 
  }

  // Predicate that tests whether a constant AttributedHalfSegment iterator is empty.
  bool Region2DImpl::ConstAttributedHalfSegmentIterator::isEmpty() const
  {
   return (handlei->current == NULL);
  }

  // Increment/decrement operators '++', '--'
  Region2DImpl::ConstAttributedHalfSegmentIterator& Region2DImpl::ConstAttributedHalfSegmentIterator::operator ++ () // prefix
  {
    handlei->iteratorIndex++;
    return(*this);
  } 

  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::ConstAttributedHalfSegmentIterator::operator ++ (int postfix) // postfix
  {
    ConstAttributedHalfSegmentIterator tmp(*this);
    handlei->iteratorIndex++;
    return(tmp);
  }

  Region2DImpl::ConstAttributedHalfSegmentIterator& Region2DImpl::ConstAttributedHalfSegmentIterator::operator -- () // prefix
  {
    handlei->iteratorIndex--;
    return(*this);
  }

  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::ConstAttributedHalfSegmentIterator::operator -- (int postfix) // postfix
  {
    ConstAttributedHalfSegmentIterator tmp(*this);
    handlei->iteratorIndex--;
    return(tmp);
  }

  // Dereferencing operators that return the value at the constant AttributedHalfSegment
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a AttributedHalfSegment. The dereferenced value cannot be changed.
  const AttrHalfSeg2D& Region2DImpl::ConstAttributedHalfSegmentIterator::operator *() const
  {
   return(this->handlei->current->segments.at(this->handlei->iteratorIndex)); 
  }

  const AttrHalfSeg2D* Region2DImpl::ConstAttributedHalfSegmentIterator::operator ->() const
  {
   return(&this->handlei->current->segments.at(this->handlei->iteratorIndex));
  }

  // Comparison operators that compare a constant AttributedHalfSegment iterator position
  // with another const AttributedHalfSegment iterator position "rhs"
  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator == (const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex == rhs.handlei->iteratorIndex));
  }

  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator != (const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current != rhs.handlei->current)&&(this->handlei->iteratorIndex != rhs.handlei->iteratorIndex));
  }

  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator <(const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex < rhs.handlei->iteratorIndex));
  }

  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator <= (const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex <= rhs.handlei->iteratorIndex));
  }

  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator >(const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex > rhs.handlei->iteratorIndex));
  }

  bool Region2DImpl::ConstAttributedHalfSegmentIterator::operator >= (const ConstAttributedHalfSegmentIterator& rhs) const
  {
   return ((this->handlei->current == rhs.handlei->current)&&(this->handlei->iteratorIndex >= rhs.handlei->iteratorIndex));
  }
  

  std::ostream&operator<<(std::ostream& os, const Region2DImpl::ConstAttributedHalfSegmentIterator& output)
  {
      os << "index Value:" << output.handlei->iteratorIndex<<" ";
      os << "segments " << output.handlei->current->segments.at(output.handlei->iteratorIndex)<<" "<<endl;
	
      return os;
  }

  // Method that returns a constant AttributedHalfSegment iterator to the first AttributedHalfSegment of a
  // Region2D object.
  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::cbegin() const
  {
   ConstAttributedHalfSegmentIterator begin;
   begin.handlei->iteratorIndex = 1;
   begin.handlei->current = handle;
   return begin;
  }

  // Method that returns a constant AttributedHalfSegment iterator to the last AttributedHalfSegment of a
  // Region2D object.
  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::cend() const
  {
   ConstAttributedHalfSegmentIterator last;
   last.handlei->iteratorIndex = handle->segments.size()-2;
   last.handlei->current = handle;
   return last;
  }

  // Method that returns a constant AttributedHalfSegment iterator to the position before the
  // first AttributedHalfSegment of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant AttributedHalfSegment iterator.
  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::chead() const
  {
   ConstAttributedHalfSegmentIterator h;
   h.handlei->iteratorIndex = 0;
   h.handlei->current = handle;
   return h;
  }

  // Method that returns a constant AttributedHalfSegment iterator to the position after the
  // last AttributedHalfSegment of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant AttributedHalfSegment iterator.
  Region2DImpl::ConstAttributedHalfSegmentIterator Region2DImpl::ctail() const
  {
     ConstAttributedHalfSegmentIterator t;
     t.handlei->iteratorIndex = handle->segments.size()-1;
     t.handlei->current = handle;
     return t;
  }

