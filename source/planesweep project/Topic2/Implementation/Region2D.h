/******************************************************************************
 *  File: Region2D.h
 /******************************************************************************
 *  Purpose:  This file specifies interfaces to the class Region2D and to
*   several nested iterator classes thaty enable access to components (that is,
*   faces, cycles, segments) of Region2D objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain

 * Date: Fall Semester 2015
*******************************************************************************/

#ifndef REGION2D_H_
#define REGION2D_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "RobustGeometricPrimitives2D.h"

class Region2D 
{
  public:

    //++++++++++++++++++++++++++++
    // Constructors and destructor
    //++++++++++++++++++++++++++++

    //Empty constructor. Represents the empty region object.
    Region2D();

    //Constructor for complex Region2D object. It takes
    //inputs as a vector of seg2D objects and creates a
    //Region2D object after checking if a valid Region2D
    //object can be created from the input.
    Region2D(std::vector<Seg2D> segmentList);

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
    Region2D(std::string textualRegionList);

    //copy constructor that constructs a new Region2D object with the same 
    //properties as the inputted Region2D object.
    Region2D(Region2D& orginalRegion);

    // Move constructor that moves the inputted Region2D object to a
    // Region2D object. The inputted Region2D object gets the empty Region2D
    // object as its value.
    Region2D(Region2D&& orginalRegion);

    //Destructor
    virtual ~Region2D();


    //+++++++++++++++++++++
    // Assignment operators
    //+++++++++++++++++++++


    //copy assignment operator that copies the inputted object
    //to the Region2D object
    Region2D& operator = (Region2D& orginalRegion);

    // Move assignment operator that moves the inputted Region2D object to the
    // Region2D object. The inputted object gets the empty Region2D
    // object as its value.
    Region2D& operator = (Region2D&& orginalRegion);

    //+++++++++++++++++++++
    // Comparison operators
    //+++++++++++++++++++++

    //equal operator that checks if the Region2D object and inputted Region2D
    //object are the same spatial region.
    bool operator == (Region2D& operand);

    //unequal operator that checks if the Region2D object and the inputted
    //Region2D object are different spatial regions. It is the logical opposite
    //of the == operator.
    bool operator != (Region2D& operand);

    // less than operator that compares 2 Region2D objects through comparing their minimum bounding rectangles in the following way:
    // if (min(x1) < min(x2)) the object is less than the operand object
    // if ((min(x1) = min(x2)) and (min(y1) < min(y2))) the object is less than the operand object
    // where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
    bool operator < (Region2D& operand);

    // less or equal than operator that compares 2 Region2D objects through comparing their minimum bounding rectangles in the following way:
    // if (min(x1) <= min(x2)) the object is less than or equal the operand object
    // if ((min(x1) = min(x2)) and (min(y1) <= min(y2))) the object is less than or equal the operand object
    // where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
    bool operator <= (Region2D& operand);

    // greater than operator that compares 2 Region2D objects through comparing their minimum bounding rectangles in the following way:
    // if (min(x1) > min(x2)) the object is greater the operand object
    // if ((min(x1) = min(x2)) and (min(y1) > min(y2))) the object is greater the operand object
    // where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
    bool operator > (Region2D& operand);

    // greater or equal than operator that compares 2 Region2D objects through comparing their minimum bounding rectangles in the following way:
    // if (min(x1) >= min(x2)) the object is greater than or equal the operand object
    // if ((min(x1) = min(x2)) and (min(y1) >= min(y2))) the object is greater than or equal the operand object
    // where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
    bool operator >= (Region2D& operand);

    //++++++++++++++++++++++++++++++++
    // Unary predicates and operations
    //++++++++++++++++++++++++++++++++

    // Predicate that checks whether the inputted Region2D object is an 
    //empty Region2D object.
    bool isEmptyRegion2D();

    // Predicate that checks whether the inputted Region2D object is a simple Region2D
    // object, that is, a single-component Region2D object without holes. The
    // predicate yields false for an empty Region2D object.
    bool isSimpleRegion2D();

    // Predicate that checks whether the inputted Region2D object is a simple (that is,
    // single-component) Region2D object with at least one hole. The predicate
    // yields false for an empty Region2D object.
    bool isSimpleRegion2DWithHoles();

    // Predicate that checks whether the inputted Region2D object is a face object, that
    // is, a single-component Region2D object with or without holes. The
    // predicate yields false for an empty Region2D object.
    bool isFace();

    // Method that yields the number of faces of the inputted Region2D object. The
    // number of faces of an empty Region2D object is 0.
    Number getNumberOfFaces();

    // Method that yields the number of hole cycles of a face, which is
    // represented as a simple Region2D object with or without holes. If the
    // Region2D object is a multi-component object, that is, has more than one
    // face, the value -1 is returned. Otherwise, if the face does not contain
    // holes, the value 0 is returned. If the face is an empty Region2D object,
    // the value -2 is returned.
    Number getNumberOfHoleCycles();

    // Method that yields the number of segments of a cycle (outer cycle or
    // hole cycle), which is represented as a simple Region2D object (without
    // holes). If the Region2D object is an empty Region2D object, the value
    // -2 is returned. If the Region2D object is not simple, the value -1 is
    // returned.
    Number getNumberOfSegments();

    // Method that returns the outer cycle of a face, which is a simple
    // Region2D object with or without holes. If the Region2D is complex, that
    // is, has multiple faces, the empty Region2D object is returned. If the
    // Region2D object is simple and thus has no holes, then a copy of the
    // object is returned. Otherwise, the outer cycle is determined and
    // returned.
    Region2D getOuterCycle();

    //+++++++++++++++++
    // Iterator classes
    //+++++++++++++++++

    // Constant face iterator type that allows to navigate through the faces of
    // a Region2D object in forward and reverse direction. A change of the
    // faces is not possible.
    class ConstFaceIterator
    {
    friend class Region2D;

    public:
      // Default constructor that creates an empty constant face iterator.
      ConstFaceIterator();

      // Copy constructor that constructs a constant face iterator from a
      // given constant face iterator "source".
      ConstFaceIterator(const ConstFaceIterator& source);

      // Move constructor that moves a given constant face iterator "source"
      // to a constant face iterator. The constant face iterator "source"
      // gets the empty constant face iterator as its value.
      ConstFaceIterator(const ConstFaceIterator&& source);

      // Destructor that frees the main memory space allocated for a constant
      // face iterator.
      ~ConstFaceIterator();

      // Assignment operator that assigns another constant face iterator
      // "rhs" to the constant face iterator.
      ConstFaceIterator& operator = (const ConstFaceIterator& rhs);

      // Predicate that tests whether a constant face iterator is empty.
      bool isEmpty() const;

      // Increment/decrement operators '++', '--'
      ConstFaceIterator& operator ++ ();   // prefix
      ConstFaceIterator operator ++ (int postfix); // postfix
      ConstFaceIterator& operator -- ();   // prefix
      ConstFaceIterator operator -- (int postfix); // postfix

      // Dereferencing operators that return the value at the constant face
      // iterator position. Dereferencing is only allowed if the iterator
      // points to a face. The dereferenced value cannot be changed.
      const Region2D& operator *() const;
      const Region2D* operator ->() const;

      // Comparison operators that compare a constant face iterator position
      // with another const face iterator position "rhs"
      bool operator == (const ConstFaceIterator& rhs) const;
      bool operator != (const ConstFaceIterator& rhs) const;
      bool operator <  (const ConstFaceIterator& rhs) const;
      bool operator <= (const ConstFaceIterator& rhs) const;
      bool operator >  (const ConstFaceIterator& rhs) const;
      bool operator >= (const ConstFaceIterator& rhs) const;

    private:
      // Forward struct declaration for the hidden implementation of a
      // constant face iterator
      struct ConstFaceIteratorImplementation;

      // Declaration of an opaque pointer
      ConstFaceIteratorImplementation* handle;
    }; // class ConstFaceIterator

    // Method that returns a constant face iterator to the first face of a
    // Region2D object.
    ConstFaceIterator cFbegin() const;

    // Method that returns a constant face iterator to the last face of a
    // Region2D object.
    ConstFaceIterator cFend() const;

    // Method that returns a constant face iterator to the position before the
    // first face of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant face iterator.
    ConstFaceIterator cFhead() const;

    // Method that returns a constant face iterator to the position after the
    // last face of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant face iterator.
    ConstFaceIterator cFtail() const;


    // Constant Hole cycle iterator type that allows to navigate through the hole cycles of
    // a Region2D object in forward and reverse direction. A change of the
    // holes is not possible. 
    class ConstHoleCycleIterator
    {
    friend class Region2D;

    public:
      // Default constructor that creates an empty constant hole cycle iterator.
      ConstHoleCycleIterator();

      // Copy constructor that constructs a constant hole cycle iterator from a
      // given constant hole cycle iterator "source".
      ConstHoleCycleIterator(const ConstHoleCycleIterator& source);

      // Move constructor that moves a given constant hole cycle iterator "source"
      // to a constant hole cycle iterator. The constant hole cycle iterator "source"
      // gets the empty constant hole cycle iterator as its value.
      ConstHoleCycleIterator(const ConstHoleCycleIterator&& source);

      // Destructor that frees the main memory space allocated for a constant
      // hole cycle iterator.
      ~ConstHoleCycleIterator();

      // Assignment operator that assigns another constant hole cycle iterator
      // "rhs" to the constant face iterator.
      ConstHoleCycleIterator& operator = (const ConstHoleCycleIterator& rhs);

      // Predicate that tests whether a constant HoleCycle iterator is empty.
      bool isEmpty() const;

      // Increment/decrement operators '++', '--'
      ConstHoleCycleIterator& operator ++ ();   // prefix
      ConstHoleCycleIterator operator ++ (int postfix); // postfix
      ConstHoleCycleIterator& operator -- ();   // prefix
      ConstHoleCycleIterator operator -- (int postfix); // postfix

      // Dereferencing operators that return the value at the constant HoleCycle
      // iterator position. Dereferencing is only allowed if the iterator
      // points to a hole cycle. The dereferenced value cannot be changed.
      const Region2D& operator *() const;
      const Region2D* operator ->() const;

      // Comparison operators that compare a constant HoleCycle iterator position
      // with another const HoleCycle iterator position "rhs"
      bool operator == (const ConstHoleCycleIterator& rhs) const;
      bool operator != (const ConstHoleCycleIterator& rhs) const;
      bool operator <  (const ConstHoleCycleIterator& rhs) const;
      bool operator <= (const ConstHoleCycleIterator& rhs) const;
      bool operator >  (const ConstHoleCycleIterator& rhs) const;
      bool operator >= (const ConstHoleCycleIterator& rhs) const;

    private:
      // Forward struct declaration for the hidden implementation of a
      // constant HoleCycle iterator
      struct ConstHoleCycleIteratorImplementation;

      // Declaration of an opaque pointer
      ConstHoleCycleIteratorImplementation* handlei;
    }; // class ConstHoleCycleIterator

    // Method that returns a constant HoleCycle iterator to the first HoleCycle of a
    // Region2D object.
    ConstHoleCycleIterator cHbegin() const;

    // Method that returns a constant HoleCycle iterator to the last HoleCycle of a
    // Region2D object.
    ConstHoleCycleIterator cHend() const;

    // Method that returns a constant HoleCycle iterator to the position before the
    // first HoleCycle of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant HoleCycle iterator.
    ConstHoleCycleIterator cHhead() const;

    // Method that returns a constant HoleCycle iterator to the position after the
    // last HoleCycle of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant HoleCycle iterator.
    ConstHoleCycleIterator cHtail() const;


    // Constant segment iterator type that allows to navigate through the segments of
    // a Region2D object in forward and reverse direction. A change of the
    // segments is not possible. 
    class ConstSegmentIterator
    {
    friend class Region2D;

    public:
      // Default constructor that creates an empty constant Segment iterator.
      ConstSegmentIterator();

      // Copy constructor that constructs a constant Segment iterator from a
      // given constant Segment iterator "source".
      ConstSegmentIterator(const ConstSegmentIterator& source);

      // Move constructor that moves a given constant Segment iterator "source"
      // to a constant Segment iterator. The constant Segment iterator "source"
      // gets the empty constant Segment iterator as its value.
      ConstSegmentIterator(const ConstSegmentIterator&& source);

      // Destructor that frees the main memory space allocated for a constant
      // Segment iterator.
      ~ConstSegmentIterator();

      // Assignment operator that assigns another constant Segment iterator
      // "rhs" to the constant Segment iterator.
      ConstSegmentIterator& operator = (const ConstSegmentIterator& rhs);

      // Predicate that tests whether a constant Segment iterator is empty.
      bool isEmpty() const;

      // Increment/decrement operators '++', '--'
      ConstSegmentIterator& operator ++ ();   // prefix
      ConstSegmentIterator operator ++ (int postfix); // postfix
      ConstSegmentIterator& operator -- ();   // prefix
      ConstSegmentIterator operator -- (int postfix); // postfix

      // Dereferencing operators that return the value at the constant Segment
      // iterator position. Dereferencing is only allowed if the iterator
      // points to a Segment. The dereferenced value cannot be changed.
      const Region2D& operator *() const;
      const Region2D* operator ->() const;

      // Comparison operators that compare a constant Segment iterator position
      // with another const Segment iterator position "rhs"
      bool operator == (const ConstSegmentIterator& rhs) const;
      bool operator != (const ConstSegmentIterator& rhs) const;
      bool operator <  (const ConstSegmentIterator& rhs) const;
      bool operator <= (const ConstSegmentIterator& rhs) const;
      bool operator >  (const ConstSegmentIterator& rhs) const;
      bool operator >= (const ConstSegmentIterator& rhs) const;

    private:
      // Forward struct declaration for the hidden implementation of a
      // constant Segment iterator
      struct ConstSegmentIteratorImplementation;

      // Declaration of an opaque pointer
      ConstSegmentIteratorImplementation* handlei;
    }; // class ConstSegmentIterator

    // Method that returns a constant Segment iterator to the first Segment of a
    // Region2D object.
    ConstSegmentIterator cSbegin() const;

    // Method that returns a constant Segment iterator to the last Segment of a
    // Region2D object.
    ConstSegmentIterator cSend() const;

    // Method that returns a constant Segment iterator to the position before the
    // first Segment of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant Segment iterator.
    ConstSegmentIterator cShead() const;

    // Method that returns a constant Segment iterator to the position after the
    // last Segment of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant Segment iterator.
    ConstSegmentIterator cStail() const;



private:
    // Forward struct declaration for the hidden implementation of class
    // "Region2D" as an abstract data type (ADT)
    struct Region2DImplementation;

    // Declaration of an opaque pointer
    Region2DImplementation *handle;

};

#endif /* REGION2D_H_ */
