/******************************************************************************
 *  File: Region2D.cpp
 /******************************************************************************
 *  Purpose:  This file implements interfaces to the class Region2D defined 
 *  in the Region2D.h file and the several nested iterator classes that enable 
 *  access to components (that is, faces, cycles, segments) of Region2D objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain

 * Date: Fall Semester 2015
*******************************************************************************/

#include "Region2D.h"

  struct Region2DImplementation{
     std::vector<Seg2D> segments;
  };
  //++++++++++++++++++++++++++++
  // Constructors and destructor
  //++++++++++++++++++++++++++++

  //Empty constructor. Represents the empty region object.
  Region2D::Region2D(){}

  //Constructor for complex Region2D object. It takes
  //inputs as a vector of seg2D objects and creates a
  //Region2D object after checking if a valid Region2D
  //object can be created from the input.
  Region2D::Region2D(std::vector<Seg2D> segmentList){ }

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

  Region2D::Region2D(std::string textualRegionList){  }

  //copy constructor that constructs a new Region2D object with the same 
  //properties as the inputted Region2D object.
  Region2D::Region2D(Region2D& orginalRegion) {  }

   // Move constructor that moves a given Region2D object "source" to a
   // Region2D object. The Region2D object "source" gets the empty Region2D
   // object as its value.
  Region2D::Region2D(Region2D&& orginalRegion){}

  //Destructor
  Region2D::~Region2D(){}

  //+++++++++++++++++++++
  // Assignment operators
  //+++++++++++++++++++++

  //copy assignment operator that copies the inputted object
  //to the Region2D object
  Region2D& Region2D::operator = (Region2D& orginalRegion){}

  // Move assignment operator that moves the inputted Region2D object to the
  // Region2D object. The inputted object gets the empty Region2D
  // object as its value.
  Region2D& Region2D::operator = (Region2D&& orginalRegion){}

  //+++++++++++++++++++++
  // Comparison operators
  //+++++++++++++++++++++

  //equal operator that checks if the Region2D object and inputted Region2D
  //object are the same spatial region.
  bool Region2D::operator == (Region2D& operand)
  {}

  //unequal operator that checks if the Region2D object and the inputted
  //Region2D object are different spatial regions. It is the logical opposite
  //of the == operator.
  bool Region2D::operator != (Region2D& operand)
  {}

  //less than operator that compares 2 Region2D objects and checks which one is lesser 
  //by comparing their minimum bounding rectangles in the following way:
  //if min(x1) < min(x2) the object is less than "source" object
  //else if max (x1) < max (x2) the object is less than "source" object
  //else if min(y1) < min(y2) the object is less than "source" object
  //else if max(y1) < max(y2) the object is less than "source" object
  bool Region2D::operator < (Region2D& operand)
  {}
    
  //less than or equal operator that compares 2 Region2D objects and checks which one is lesser 
  //or equal by comparing their minimum bounding rectangles in the following way:
  //if min(x1) <= min(x2) the object is less than or equal to "source" object
  //else if max (x1) <= max (x2) the object is less than or equal to "source" object
  //min(y1) <= min(y2) the object is less than or equal to "source" object
  //max(y1) <= max(y2) the object is less than or equal to "source" object
  bool Region2D::operator <= (Region2D& operand)
  {}
    
  //greater than operator that compares 2 Region2D objects and checks which one is greater 
  //by comparing their minimum bounding rectangles in the following way:
  //if min(x1) > min(x2) the object is greater than "source" object
  //else if max (x1) > max (x2)  the object is greater than "source" object
  //else if min(y1) > min(y2) the object is greater than "source" object
  //else if max(y1) > max(y2)  the object is greater than "source" object
  bool Region2D::operator > (Region2D& operand)
  {}
    
  //greater than or equal operator that compares 2 Region2D objects and checks which one is greater 
  //or equal by comparing their minimum bounding rectangles in the following way:
  //if min(x1) >= min(x2)  the object is greater than or equal to "source" object
  //else if max (x1) >= max (x2) the object is greater than or equal to "source" object
  //else if min(y1) >= min(y2) the object is greater than or equal to "source" object
  //else if max(y1) >= max(y2) the object is greater than or equal to "source" object
  bool Region2D::operator >= (Region2D& operand)
  {}

  //++++++++++++++++++++++++++++++++
  // Unary predicates and operations
  //++++++++++++++++++++++++++++++++

  // Predicate that checks whether the inputted Region2D object is an 
  //empty Region2D object.
  bool Region2D::isEmptyRegion2D()
  {
  }

  // Predicate that checks whether the inputted Region2D object is a simple Region2D
  // object, that is, a single-component Region2D object without holes. The
  // predicate yields false for an empty Region2D object.
  bool Region2D::isSimpleRegion2D()
  {
  }

  // Predicate that checks whether the inputted Region2D object is a simple (that is,
  // single-component) Region2D object with at least one hole. The predicate
  // yields false for an empty Region2D object.
  bool Region2D::isSimpleRegion2DWithHoles()
  {
  }

  // Predicate that checks whether the inputted Region2D object is a face object, that
  // is, a single-component Region2D object with or without holes. The
  // predicate yields false for an empty Region2D object.
  bool Region2D::isFace()
  {
  }

  // Method that yields the number of faces of the inputted Region2D object. The
  // number of faces of an empty Region2D object is 0.
  Number Region2D::getNumberOfFaces()
  {
  }

  // Method that yields the number of hole cycles of a face, which is
  // represented as a simple Region2D object with or without holes. If the
  // Region2D object is a multi-component object, that is, has more than one
  // face, the value -1 is returned. Otherwise, if the face does not contain
  // holes, the value 0 is returned. If the face is an empty Region2D object,
  // the value -2 is returned.
  Number Region2D::getNumberOfHoleCycles()
  {
  }

  // Method that yields the number of segments of a cycle (outer cycle or
  // hole cycle), which is represented as a simple Region2D object (without
  // holes). If the Region2D object is an empty Region2D object, the value
  // -2 is returned. If the Region2D object is not simple, the value -1 is
  // returned.
  Number Region2D::getNumberOfSegments()
  {
  }

  // Method that returns the outer cycle of a face, which is a simple
  // Region2D object with or without holes. If the Region2D is complex, that
  // is, has multiple faces, the empty Region2D object is returned. If the
  // Region2D object is simple and thus has no holes, then a copy of the
  // object is returned. Otherwise, the outer cycle is determined and
  // returned.
  Region2D Region2D::getOuterCycle()
  {
  }

  //++++++++++++++++++++
  // Iterator functions
  //++++++++++++++++++++

  // Default constructor that creates an empty constant face iterator.
  Region2D::ConstFaceIterator::ConstFaceIterator()
  {
  }

  // Copy constructor that constructs a constant face iterator from a
  // given constant face iterator "source".
  Region2D::ConstFaceIterator::ConstFaceIterator(const ConstFaceIterator& source)
  {
  }

  // Move constructor that moves a given constant face iterator "source"
  // to a constant face iterator. The constant face iterator "source"
  // gets the empty constant face iterator as its value.
  Region2D::ConstFaceIterator::ConstFaceIterator(const ConstFaceIterator&& source)
  {
  }

  // Destructor that frees the main memory space allocated for a constant
  // face iterator.
  Region2D::ConstFaceIterator::~ConstFaceIterator()
  {
  }

  // Assignment operator that assigns another constant face iterator
  // "rhs" to the constant face iterator.
  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator = (const ConstFaceIterator& rhs)
  {
  }

  // Predicate that tests whether a constant face iterator is empty.
  bool Region2D::ConstFaceIterator::isEmpty() const
  {
  }

  // Increment/decrement operators '++', '--'
  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator ++ () //prefix
  {
  }

  Region2D::ConstFaceIterator Region2D::ConstFaceIterator::operator ++ (int postfix) //postfix
  {
  }
  Region2D::ConstFaceIterator& Region2D::ConstFaceIterator::operator -- ()   // prefix
  {
  }

  Region2D::ConstFaceIterator Region2D::ConstFaceIterator::operator -- (int postfix) // postfix
  {
  }

  // Dereferencing operators that return the value at the constant face
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a face. The dereferenced value cannot be changed.
  const Region2D& Region2D::ConstFaceIterator::operator *() const
  {
  }

  const Region2D* Region2D::ConstFaceIterator::operator ->() const
  {
  }

  // Comparison operators that compare a constant face iterator position
  // with another const face iterator position "rhs"
  bool Region2D::ConstFaceIterator::operator == (const ConstFaceIterator& rhs) const
  {
  }

  bool Region2D::ConstFaceIterator::operator != (const ConstFaceIterator& rhs) const
  {
  }

  bool Region2D::ConstFaceIterator::operator <  (const ConstFaceIterator& rhs) const
  {
  }

  bool Region2D::ConstFaceIterator::operator <= (const ConstFaceIterator& rhs) const
  {
  }

  bool Region2D::ConstFaceIterator::operator >  (const ConstFaceIterator& rhs) const
  {
  }

  bool Region2D::ConstFaceIterator::operator >= (const ConstFaceIterator& rhs) const
  {
  }

  // Method that returns a constant face iterator to the first face of a
  // Region2D object.
  Region2D::ConstFaceIterator Region2D::cFbegin() const
  {
  }

  // Method that returns a constant face iterator to the last face of a
  // Region2D object.
  Region2D::ConstFaceIterator Region2D::cFend() const
  {
  }

  // Method that returns a constant face iterator to the position before the
  // first face of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant face iterator.
  Region2D::ConstFaceIterator Region2D::cFhead() const  
  {
  }

  // Method that returns a constant face iterator to the position after the
  // last face of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant face iterator.
  Region2D::ConstFaceIterator Region2D::cFtail() const
  {
  }


  // Default constructor that creates an empty constant hole cycle iterator.
  Region2D::ConstHoleCycleIterator::ConstHoleCycleIterator()
  {
  }

  // Copy constructor that constructs a constant hole cycle iterator from a
  // given constant hole cycle iterator "source".
  Region2D::ConstHoleCycleIterator::ConstHoleCycleIterator(const ConstHoleCycleIterator& source)
  {
  }

  // Move constructor that moves a given constant hole cycle iterator "source"
  // to a constant hole cycle iterator. The constant hole cycle iterator "source"
  // gets the empty constant hole cycle iterator as its value.
  Region2D::ConstHoleCycleIterator::ConstHoleCycleIterator(const ConstHoleCycleIterator&& source)
  {
  }

  // Destructor that frees the main memory space allocated for a constant
  // hole cycle iterator.
  Region2D::ConstHoleCycleIterator::~ConstHoleCycleIterator()
  {
  }

  // Assignment operator that assigns another constant hole cycle iterator
  // "rhs" to the constant face iterator.
  Region2D::ConstHoleCycleIterator& Region2D::ConstHoleCycleIterator::operator = (const ConstHoleCycleIterator& rhs)
  {
  }

  // Predicate that tests whether a constant HoleCycle iterator is empty.
  bool Region2D::ConstHoleCycleIterator::isEmpty() const
  {
  }

  // Increment/decrement operators '++', '--'
  Region2D::ConstHoleCycleIterator& Region2D::ConstHoleCycleIterator::operator ++ ()  // prefix
  {
  }

  Region2D::ConstHoleCycleIterator Region2D::ConstHoleCycleIterator::operator ++ (int postfix) // postfix
  {
  }

  Region2D::ConstHoleCycleIterator& Region2D::ConstHoleCycleIterator::operator -- ()   // prefix
  {
  }

  Region2D::ConstHoleCycleIterator Region2D::ConstHoleCycleIterator::operator -- (int postfix) // postfix
  {
  }

  // Dereferencing operators that return the value at the constant HoleCycle
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a hole cycle. The dereferenced value cannot be changed.
  const Region2D& Region2D::ConstHoleCycleIterator::operator *() const
  {
  }
  

  const Region2D* Region2D::ConstHoleCycleIterator::operator ->() const
  {
  }

  // Comparison operators that compare a constant HoleCycle iterator position
  // with another const HoleCycle iterator position "rhs"
  bool Region2D::ConstHoleCycleIterator::operator == (const ConstHoleCycleIterator& rhs) const
  {
  }

  bool Region2D::ConstHoleCycleIterator::operator != (const ConstHoleCycleIterator& rhs) const
  {
  }

  bool Region2D::ConstHoleCycleIterator::operator <  (const ConstHoleCycleIterator& rhs) const
  {
  }

  bool Region2D::ConstHoleCycleIterator::operator <= (const ConstHoleCycleIterator& rhs) const
  {
  }

  bool Region2D::ConstHoleCycleIterator::operator >  (const ConstHoleCycleIterator& rhs) const
  {
  }

  bool Region2D::ConstHoleCycleIterator::operator >= (const ConstHoleCycleIterator& rhs) const
  {
  }


  // Method that returns a constant HoleCycle iterator to the first HoleCycle of a
  // Region2D object.
  Region2D::ConstHoleCycleIterator Region2D::cHbegin() const
  {
  }

  // Method that returns a constant HoleCycle iterator to the last HoleCycle of a
  // Region2D object.
  Region2D::ConstHoleCycleIterator Region2D::cHend() const
  {
  }

  // Method that returns a constant HoleCycle iterator to the position before the
  // first HoleCycle of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant HoleCycle iterator.
  Region2D::ConstHoleCycleIterator Region2D::cHhead() const
  {
  }

  // Method that returns a constant HoleCycle iterator to the position after the
  // last HoleCycle of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant HoleCycle iterator.
  Region2D::ConstHoleCycleIterator Region2D::cHtail() const
  {
  }




  // Default constructor that creates an empty constant Segment iterator.
  Region2D::ConstSegmentIterator::ConstSegmentIterator()
  {
  }

  // Copy constructor that constructs a constant Segment iterator from a
  // given constant Segment iterator "source".
  Region2D::ConstSegmentIterator::ConstSegmentIterator(const ConstSegmentIterator& source)
  {
  }

  // Move constructor that moves a given constant Segment iterator "source"
  // to a constant Segment iterator. The constant Segment iterator "source"
  // gets the empty constant Segment iterator as its value.
  Region2D::ConstSegmentIterator::ConstSegmentIterator(const ConstSegmentIterator&& source)
  {
  }

  // Destructor that frees the main memory space allocated for a constant
  // Segment iterator.
  Region2D::ConstSegmentIterator::~ConstSegmentIterator()
  {
  }

  // Assignment operator that assigns another constant Segment iterator
  // "rhs" to the constant Segment iterator.
  Region2D::ConstSegmentIterator& Region2D::ConstSegmentIterator::operator = (const ConstSegmentIterator& rhs)
  {
  }

  // Predicate that tests whether a constant Segment iterator is empty.
  bool Region2D::ConstSegmentIterator::isEmpty() const
  {
  }

  // Increment/decrement operators '++', '--'
  Region2D::ConstSegmentIterator& Region2D::ConstSegmentIterator::operator ++ ()   // prefix
  {
  }

  Region2D::ConstSegmentIterator Region2D::ConstSegmentIterator::operator ++ (int postfix) // postfix
  {
  }

  Region2D::ConstSegmentIterator& Region2D::ConstSegmentIterator::operator -- ()   // prefix
  {
  }

  Region2D::ConstSegmentIterator Region2D::ConstSegmentIterator::operator -- (int postfix) // postfix
  {
  }

  // Dereferencing operators that return the value at the constant Segment
  // iterator position. Dereferencing is only allowed if the iterator
  // points to a Segment. The dereferenced value cannot be changed.
  const Region2D& Region2D::ConstSegmentIterator::operator *() const
  {
  }

  const Region2D* Region2D::ConstSegmentIterator::operator ->() const
  {
  }

  // Comparison operators that compare a constant Segment iterator position
  // with another const Segment iterator position "rhs"
  bool Region2D::ConstSegmentIterator::operator == (const ConstSegmentIterator& rhs) const
  {
  }

  bool Region2D::ConstSegmentIterator::operator != (const ConstSegmentIterator& rhs) const
  {
  }

  bool Region2D::ConstSegmentIterator::operator <  (const ConstSegmentIterator& rhs) const
  {
  }

  bool Region2D::ConstSegmentIterator::operator <= (const ConstSegmentIterator& rhs) const
  {
  }

  bool Region2D::ConstSegmentIterator::operator >  (const ConstSegmentIterator& rhs) const
  {
  }

  bool Region2D::ConstSegmentIterator::operator >= (const ConstSegmentIterator& rhs) const
  {
  }


  // Method that returns a constant Segment iterator to the first Segment of a
  // Region2D object.
  Region2D::ConstSegmentIterator Region2D::cSbegin() const
  {
  }

  // Method that returns a constant Segment iterator to the last Segment of a
  // Region2D object.
  Region2D::ConstSegmentIterator Region2D::cSend() const
  {
  }

  // Method that returns a constant Segment iterator to the position before the
  // first Segment of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant Segment iterator.
  Region2D::ConstSegmentIterator Region2D::cShead() const
  {
  }

  // Method that returns a constant Segment iterator to the position after the
  // last Segment of a Region2D object. Note that dereferencing this iterator
  // yields the empty constant Segment iterator.
  Region2D::ConstSegmentIterator Region2D::cStail() const
  {
  }
