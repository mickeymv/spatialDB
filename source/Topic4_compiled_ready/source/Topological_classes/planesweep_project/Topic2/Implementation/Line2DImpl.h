/******************************************************************************
* File: Line2DImpl.h
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

#ifndef Line2DImpl_H
#define Line2DImpl_H
#include "Line2D.h"

class Line2DImpl : public Line2D 
{
  public:
    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2DImpl object.
    Line2DImpl();

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2DImpl object in the sense that it conforms to the
    // formal definition of this data type.
    Line2DImpl(std::vector<Seg2D> segs);

    // Constructor for complex Line structure. It takes as input a string that represent the textually represents
    //        the input vector of Segments.
    //
    // The grammar for representing a Segment vector is structured as follows:
    // Expression       := '(' Segment (',' [WhiteSpace] Segment)* ')'
    // Segment          := '(' '(' Number ',' [WhiteSpace] Number ')' ',' [WhiteSpace] '(' Number ',' [WhiteSpace] Number ')' ')'
    // Number           := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
    // Sign             := ['+' | '-']
    // WhiteSpace       := ' '
    // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
    // Digit            := '0' | DigitWithoutZero
    //
    // example for segment list of seg1 and seg2 here is: (((1,2),(3,4)),((5,6),(7,8)))  
    Line2DImpl(std::string textRepresentation);

    // Copy constructor that constructs a Line2DImpl object from a given Line2DImpl
    // object "source".
    Line2DImpl(Line2DImpl& source);

    // Move constructor that moves a given Line2DImpl object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2DImpl
    // object as its value.
    Line2DImpl(Line2DImpl&& source);

    
    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant HalfSegment iterator type that allows to navigate through the halfsegments of
    // a Line2DImpl object in forward and reverse direction. A change of the
    // halfsegments is not possible.
    class ConstHalfSegIterator
    {
      friend class Line2DImpl;

      public:
        // Default constructor that creates an empty constant halfsegment iterator.
        ConstHalfSegIterator();

        // Copy constructor that constructs a constant halfsegment iterator from a
        // given constant halfsegment iterator "source".
        ConstHalfSegIterator(const ConstHalfSegIterator& source);

        // Move constructor that moves a given constant halfsegment iterator "source"
        // to a constant halfsegment iterator. The constant halfsegment iterator "source"
        // gets the empty constant halfsegment iterator as its value.
        ConstHalfSegIterator(const ConstHalfSegIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // halfsegment iterator.
        ~ConstHalfSegIterator();

        // Assignment operator that assigns another constant halfsegment iterator
        // "rhs" to the constant halfsegment iterator.
        ConstHalfSegIterator& operator = (const ConstHalfSegIterator& rhs);

        // Predicate that tests whether a constant halfsegment iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstHalfSegIterator& operator ++ ();   // prefix
        ConstHalfSegIterator operator ++ (int postfix); // postfix
        ConstHalfSegIterator& operator -- ();   // prefix
        ConstHalfSegIterator operator -- (int postfix); // postfix

        // Dereferencing operators that return the value at the constant halfsegment
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a halfsegment. The dereferenced value cannot be changed.
        const HalfSeg2D& operator *() const;
        const HalfSeg2D* operator ->() const;

        // Comparison operators that compare a constant halfsegment iterator position
        // with another const halfsegment iterator position "rhs"
        bool operator == (const ConstHalfSegIterator& rhs) const;
        bool operator != (const ConstHalfSegIterator& rhs) const;
        bool operator <  (const ConstHalfSegIterator& rhs) const;
        bool operator <= (const ConstHalfSegIterator& rhs) const;
        bool operator >  (const ConstHalfSegIterator& rhs) const;
        bool operator >= (const ConstHalfSegIterator& rhs) const;
        
        //friend member that display the internal members information of halfsegment
        friend std::ostream&operator<<(std::ostream&, const ConstHalfSegIterator&);

      protected:
        // Forward struct declaration for the hidden implementation of a
        // constant halfsegment iterator that holds the different variables of the iterator
        struct ConstHalfSegIteratorImplementation;

        // Declaration of an opaque pointer
        ConstHalfSegIteratorImplementation* handlei;
    }; // class ConstHalfSegIterator

    // Method that returns a constant halfsegment iterator to the first halfsegment of a
    // Line2D object.
    ConstHalfSegIterator hBegin() const;

    // Method that returns a constant halfsegment iterator to the last halfsegment of a
    // Line2D object.
    ConstHalfSegIterator hEnd() const;

    // Method that returns a constant halfsegment iterator to the position before the
    // first halfsegment of a Line2DImpl object. Note that dereferencing this iterator
    // yields the empty constant halfsegment iterator.
    ConstHalfSegIterator hHead() const;

    // Method that returns a constant halfsegment iterator to the position after the
    // last halfsegment of a Line2DImpl object. Note that dereferencing this iterator
    // yields the empty constant halfsegment iterator.
    ConstHalfSegIterator hTail() const;
	

}; // class Line2DImpl

#endif // Line2DImpl_H
