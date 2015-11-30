/******************************************************************************
 *  File: Region2DExtension.h
 /******************************************************************************
 *  Purpose:  This file specifies interfaces to the class Region2DImpl and to
*   several nested iterator classes thaty enable access to components (that is,
*   faces, cycles, segments) of Region2DImpl objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain

 * Date: Fall Semester 2015
*******************************************************************************/

#ifndef REGION2DE_H_
#define REGION2DE_H_

#include "Region2D.h"

class Region2DImpl: public Region2D        //inherits Region2D  
{
  public:
	//++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

	//Empty constructor. Represents the empty region object.
	Region2DImpl();

	//Constructor for complex Region2D object. It takes
	//inputs as a vector of seg2D objects and creates a
	//Region2D object after checking if a valid Region2D
	//object can be created from the input.
	Region2DImpl(std::vector<Seg2D> segmentList);

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
    // example for pointslist of point1, point2 and point3 here is: ((x1, y1),(x2, y2),(x3, y3))
	Region2DImpl(std::string textualRegionList);

    //copy constructor that constructs a new Region2D object with the same 
    //properties as the inputted Region2D object.
	Region2DImpl(Region2DImpl& orginalRegion);

	// Move constructor that moves a given Region2D object "source" to a
    // Region2D object. The Region2D object "source" gets the empty Region2D
    // object as its value.
	Region2DImpl(Region2DImpl&& orginalRegion);

	//Destructor
	virtual ~Region2DImpl();



    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		//All functions will be inherited from Region2D.cpp when called
        //Additional functions in the extended file start here
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	
	//+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant attributed half segment iterator type that allows to navigate through the attributed half segments of
    // a Region2D object in forward and reverse direction. A change of the
    // attributed half segment is not possible. 
    class ConstAttributedHalfSegmentIterator
    {
      friend class Region2DImpl;

      public:
        // Default constructor that creates an empty constant AttributedHalfSegment iterator.
        ConstAttributedHalfSegmentIterator();

        // Copy constructor that constructs a constant AttributedHalfSegment iterator from a
        // given constant AttributedHalfSegment iterator "source".
        ConstAttributedHalfSegmentIterator(const ConstAttributedHalfSegmentIterator& source);

        // Move constructor that moves a given constant AttributedHalfSegment iterator "source"
        // to a constant AttributedHalfSegment iterator. The constant AttributedHalfSegment iterator "source"
        // gets the empty constant AttributedHalfSegment iterator as its value.
        ConstAttributedHalfSegmentIterator(const ConstAttributedHalfSegmentIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // AttributedHalfSegment iterator.
        ~ConstAttributedHalfSegmentIterator();

        // Assignment operator that assigns another constant AttributedHalfSegment iterator
        // "rhs" to the constant AttributedHalfSegment iterator.
        ConstAttributedHalfSegmentIterator& operator = (const ConstAttributedHalfSegmentIterator& rhs);

        // Predicate that tests whether a constant AttributedHalfSegment iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstAttributedHalfSegmentIterator& operator ++ ();   // prefix
        ConstAttributedHalfSegmentIterator operator ++ (int postfix); // postfix
        ConstAttributedHalfSegmentIterator& operator -- ();   // prefix
        ConstAttributedHalfSegmentIterator operator -- (int postfix); // postfix

        // Dereferencing operators that return the value at the constant AttributedHalfSegment
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a AttributedHalfSegment. The dereferenced value cannot be changed.
        const Region2DImpl& operator *() const;
        const Region2DImpl* operator ->() const;

        // Comparison operators that compare a constant AttributedHalfSegment iterator position
        // with another const AttributedHalfSegment iterator position "rhs"
        bool operator == (const ConstAttributedHalfSegmentIterator& rhs) const;
        bool operator != (const ConstAttributedHalfSegmentIterator& rhs) const;
        bool operator <  (const ConstAttributedHalfSegmentIterator& rhs) const;
        bool operator <= (const ConstAttributedHalfSegmentIterator& rhs) const;
        bool operator >  (const ConstAttributedHalfSegmentIterator& rhs) const;
        bool operator >= (const ConstAttributedHalfSegmentIterator& rhs) const;

      private:
        // Forward struct declaration for the hidden implementation of a
        // constant AttributedHalfSegment iterator
        struct ConstAttributedHalfSegmentIteratorImplementation;

        // Declaration of an opaque pointer
        ConstAttributedHalfSegmentIteratorImplementation* handle;
    }; // class ConstAttributedHalfSegmentIterator

    // Method that returns a constant AttributedHalfSegment iterator to the first AttributedHalfSegment of a
    // Region2D object.
    ConstAttributedHalfSegmentIterator cbegin() const;

    // Method that returns a constant AttributedHalfSegment iterator to the last AttributedHalfSegment of a
    // Region2D object.
    ConstAttributedHalfSegmentIterator cend() const;

    // Method that returns a constant AttributedHalfSegment iterator to the position before the
    // first AttributedHalfSegment of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant AttributedHalfSegment iterator.
    ConstAttributedHalfSegmentIterator chead() const;

    // Method that returns a constant AttributedHalfSegment iterator to the position after the
    // last AttributedHalfSegment of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant AttributedHalfSegment iterator.
    ConstAttributedHalfSegmentIterator ctail() const;


};

#endif /* REGION2DE_H_ */
