/******************************************************************************
* File: Line2D.h
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

#ifndef Line2D_H
#define Line2D_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "RobustGeometricPrimitives2D.h"
using namespace std;

//class ConstSegIterator;


class Line2D 
{
  public:
    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    // Default constructor. It represents the empty Line2D object.
    Line2D();

    // Constructor that takes a collection (vector) of segments (Seg2D objects)
    // as input. The constructor checks whether the collection of segments
    // forms a correct Line2D object in the sense that it conforms to the
    // formal definition of this data type.
    Line2D(std::vector<Seg2D> segmentList);

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
    Line2D(std::string textualLineList);

    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2D(Line2D& source);

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2D(Line2D&& source);

    //Length: returns the concatenated length of the line
    Number Length();

    //NumberOfComponents: returns the number of blocks of line structure.
    Number numberOfComponents();

    //Computing the minimum bounding rectangle for a line object
    MBR MinBoundingRect();

    //Destructor
    virtual ~Line2D();

    
    //+++++++++++++++++++++
    // Assignment operators
    //+++++++++++++++++++++

    // Copy assignment operator that assigns a Line2D object "source" to the
    // Line2D object.
    Line2D& operator = (const Line2D& source);

    // Move assignment operator that moves a Line2D object "source" to the
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2D& operator = (Line2D&& source);

    
    //+++++++++++++++++++++
    // Comparison operators
    //+++++++++++++++++++++

    // Comparison operators ==, !=, <, <=, >, and >=. 
    //equal operator that checks if the Line2D object and input Line2D
    //object are the same spatial region.
    bool operator == (const Line2D& rhs);
	
    //unequal operator that checks if the Line2D object and the inputted
    //Line2D object are different spatial regions. It is the logical opposite
    //of the == operator.
    bool operator != (const Line2D& rhs);
	
    //less than operator that compares 2 Line2D objects and checks which one is lesser 
    //by comparing their lengths in the following way:
    //if length(x1) < length(x2) the object is less than "source" object
    //length(x1) < length(x2)
    //length(y1) < length(y2)
    //length(y1) < length(y2)
    bool operator <  (const Line2D& rhs); 

    //less than operator that compares 2 Line2D objects and checks which one is lesser 
    //or equal by comparing their lengths in the following way:
    //if length(x1) <= length(x2) the object is less than "source" object
    //length(x1) <= length(x2)
    //length(y1) <= length(y2)
    //length(y1) <= length(y2)	
    bool operator <= (const Line2D& rhs);   

    //less than operator that compares 2 Line2D objects and checks which one is greater 
    //by comparing their lengths in the following way:
    //if length(x1) > length(x2) the object is less than "source" object
    //length(x1) > length(x2)
    //length(y1) > length(y2)
    //length(y1) > length(y2)	
    bool operator >  (const Line2D& rhs);  

    //less than operator that compares 2 Line2D objects and checks which one is greater 
    //or equal by comparing their lengths in the following way:
    //if length(x1) >= length(x2) the object is less than "source" object
    //length(x1) >= length(x2)
    //length(y1) >= length(y2)
    //length(y1) >= length(y2)
    bool operator >= (const Line2D& rhs);    


    //++++++++++++++++++++++++++++++++
    // Unary predicates and operations
    //++++++++++++++++++++++++++++++++

    // Predicate that checks whether a Line2D object is an empty Line2D
    // object. 
    bool isEmptyLine2D();

    // Method that yields the number of segments of Line2D object
    // If the Line2D object is an empty Line2D object, the value
    // 0 is returned.
    Number getNumberOfSegments();


    //++++++++++++++++
    // Output function
    //++++++++++++++++

    // Textual output of segments of a Line2D object
    friend ostream& operator << (ostream& ostr, const Line2D& rhs);

    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant segment iterator type that allows to navigate through the segments of
    // a Line2D object in forward and reverse direction. A change of the
    // segments is not possible.
    class ConstSegIterator
    {
      friend class Line2D;

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
        const Line2D& operator *() const;
        const Line2D* operator ->() const;

        // Comparison operators that compare a constant segment iterator position
        // with another const segment iterator position "rhs"
        bool operator == (const ConstSegIterator& rhs) const;
        bool operator != (const ConstSegIterator& rhs) const;
        bool operator <  (const ConstSegIterator& rhs) const;
        bool operator <= (const ConstSegIterator& rhs) const;
        bool operator >  (const ConstSegIterator& rhs) const;
        bool operator >= (const ConstSegIterator& rhs) const;

      private:
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
	

  private:
    // Forward struct declaration for the hidden implementation of class
    // "Line2D" as an abstract data type (ADT)
    struct Line2DImpl;

    // Declaration of an opaque pointer
    Line2DImpl *handle;
}; // class Line2D

#endif // Line2D_H
