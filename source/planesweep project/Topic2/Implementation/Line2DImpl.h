/******************************************************************************
* File: Line2DImpl.h
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

#ifndef Line2DImpl_H
#define Line2DImpl_H
#include "Line2D.h"

class Line2DImpl : protected Line2D
{
public:
    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2D object.
    Line2DImpl();

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2D object in the sense that it conforms to the
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

    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2DImpl(Line2DImpl& source);

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2DImpl(Line2DImpl&& source);

    //Destructor
    virtual ~Line2DImpl();



    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant segment iterator type that allows to navigate through the segments of
    // a Line2D object in forward and reverse direction. A change of the
    // segments is not possible.
    class ConstSegIterator : public ObjectIterator
    {
        friend class Line2DImpl;

    public:
        // Default constructor that creates an empty constant segment iterator.
        ConstSegIterator();

        // Copy constructor that constructs a constant segment iterator from a
        // given constant segment iterator "source".
        ConstSegIterator(const ConstSegIterator& source);

        // Move constructor that moves a given constant segment iterator "source"
        // to a constant segment iterator. The constant segment iterator "source"
        // gets the empty constant segment iterator as its value.
        ConstSegIterator(const ConstSegIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // segment iterator.
        ~ConstSegIterator();

        // Assignment operator that assigns another constant segment iterator
        // "rhs" to the constant segment iterator.
        ConstSegIterator& operator = (const ConstSegIterator& rhs);

        // Predicate that tests whether a constant segment iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstSegIterator& operator ++ ();   // prefix
        ConstSegIterator operator ++ (int postfix); // postfix
        ConstSegIterator& operator -- ();   // prefix
        ConstSegIterator operator -- (int postfix); // postfix

        // Dereferencing operators that return the value at the constant segment
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a segment. The dereferenced value cannot be changed.
        const HalfSeg2D& operator *() const;
        const HalfSeg2D* operator ->() const;

        // Comparison operators that compare a constant segment iterator position
        // with another const segment iterator position "rhs"
        bool operator == (const ConstSegIterator& rhs) const;
        bool operator != (const ConstSegIterator& rhs) const;
        bool operator <  (const ConstSegIterator& rhs) const;
        bool operator <= (const ConstSegIterator& rhs) const;
        bool operator >  (const ConstSegIterator& rhs) const;
        bool operator >= (const ConstSegIterator& rhs) const;

        friend std::ostream&operator<<(std::ostream&, const ConstSegIterator&);

    protected:
        // Forward struct declaration for the hidden implementation of a
        // constant segment iterator
        struct ConstSegIteratorImplementation;

        // Declaration of an opaque pointer
        ConstSegIteratorImplementation* handlei;
    }; // class ConstSegIterator

    // Method that returns a constant segment iterator to the first segment of a
    // Line2D object.
    ConstSegIterator cbegin() const;

    // Method that returns a constant segment iterator to the last segment of a
    // Line2D object.
    ConstSegIterator cend() const;

    // Method that returns a constant segment iterator to the position before the
    // first segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    ConstSegIterator chead() const;

    // Method that returns a constant segment iterator to the position after the
    // last segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    ConstSegIterator ctail() const;


}; // class Line2DImpl

#endif // Line2DImpl_H