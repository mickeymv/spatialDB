/******************************************************************************
 *  File: Region2D.h
 /******************************************************************************
 *  Purpose:  This file specifies interfaces to the class Region2D and to
 *  all the nested iterator classes that enable access to components (that is,
 *  faces and cycles) of Region2D objects.
 *  Created on: Oct 8, 2015
 *  Authors: Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain
 *  Date: Fall Semester 2015
*******************************************************************************/

#ifndef REGION2D_H_
#define REGION2D_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#include "../../Topic1/RobustGeometricPrimitives2D.h"
#include "../../Object2D.h"


class Region2D : public Object2D
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
    Region2D(std::string textualRegionList);

    //copy constructor that constructs a new Region2D object with the same
    //properties as the inputted Region2D object.
    Region2D(Region2D& source);

    // Move constructor that moves the inputted Region2D object to a
    // Region2D object. The inputted Region2D object gets the empty Region2D
    // object as its value.
    Region2D(Region2D&& source);

    //Destructor
    virtual ~Region2D();


    //+++++++++++++++++++++
    // Assignment operators
    //+++++++++++++++++++++


    //copy assignment operator that copies the inputted object
    //to the Region2D object
    Region2D& operator = (const Region2D& source);

    // Move assignment operator that moves the inputted Region2D object to the
    // Region2D object. The inputted object gets the empty Region2D
    // object as its value.
    Region2D& operator = (Region2D&& source);

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

    // less than operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic order.
    // Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) < Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since
    // ((0,0),(1,1)) < ((5,5),(6,6))
    bool operator < (Region2D& operand);

    // less than or equal operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic
    //order. Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) <= Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since
    // ((0,0),(1,1)) <= ((5,5),(6,6))
    bool operator <= (Region2D& operand);

    // greater than operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic order.
    // Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) > Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since
    // ((0,0),(1,1)) < ((5,5),(6,6)).
    bool operator > (Region2D& operand);

    // greater than or equal operator that compares 2 Region2D objects through comparing their sorted attributed half segments in lexicographic
    //order. Eg: Region1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) >= Region2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since
    // ((0,0),(1,1)) <= ((5,5),(6,6))
    bool operator >= (Region2D& operand);

    //++++++++++++++++++++++++++++++++
    // Unary predicates and operations
    //++++++++++++++++++++++++++++++++

    // Predicate that checks whether the inputted Region2D object is an
    //empty Region2D object.
    bool isEmptyRegion2D() const;

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

    //++++++++++++++++
    // Output function
    //++++++++++++++++

    // Textual output of segments of a Region2D object
    friend std::ostream& operator << (std::ostream& ostr, const Region2D& rhs);

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
        const Region2D operator *() const;
        const Region2D operator ->() const;

        // Comparison operators that compare a constant face iterator position
        // with another const face iterator position "rhs"
        bool operator == (const ConstFaceIterator& rhs) const;
        bool operator != (const ConstFaceIterator& rhs) const;
        bool operator <  (const ConstFaceIterator& rhs) const;
        bool operator <= (const ConstFaceIterator& rhs) const;
        bool operator >  (const ConstFaceIterator& rhs) const;
        bool operator >= (const ConstFaceIterator& rhs) const;

        friend std::ostream&operator<<(std::ostream& os, const ConstFaceIterator& output);

    protected:
        // Forward struct declaration for the hidden implementation of a
        // constant face iterator
        struct ConstFaceIteratorImplementation;

        // Declaration of an opaque pointer
        ConstFaceIteratorImplementation* handlei;
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


    // Constant cycle iterator type that allows to navigate through the cycles of
    // a Region2D object in forward and reverse direction. A change of the
    // holes is not possible.
    class ConstCycleIterator
    {
        friend class Region2D;

    public:
        // Default constructor that creates an empty constant cycle iterator.
        ConstCycleIterator();

        // Copy constructor that constructs a constant cycle iterator from a
        // given constant cycle iterator "source".
        ConstCycleIterator(const ConstCycleIterator& source);

        // Move constructor that moves a given constant cycle iterator "source"
        // to a constant cycle iterator. The constant cycle iterator "source"
        // gets the empty constant cycle iterator as its value.
        ConstCycleIterator(const ConstCycleIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // cycle iterator.
        ~ConstCycleIterator();

        // Assignment operator that assigns another constant cycle iterator
        // "rhs" to the constant face iterator.
        ConstCycleIterator& operator = (const ConstCycleIterator& rhs);

        // Predicate that tests whether a constant Cycle iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstCycleIterator& operator ++ ();   // prefix
        ConstCycleIterator operator ++ (int postfix); // postfix
        ConstCycleIterator& operator -- ();   // prefix
        ConstCycleIterator operator -- (int postfix); // postfix

        // Dereferencing operators that return the value at the constant Cycle
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a cycle. The dereferenced value cannot be changed.
        const Region2D operator *() const;
        const Region2D operator ->() const;

        // Comparison operators that compare a constant Cycle iterator position
        // with another const Cycle iterator position "rhs"
        bool operator == (const ConstCycleIterator& rhs) const;
        bool operator != (const ConstCycleIterator& rhs) const;
        bool operator <  (const ConstCycleIterator& rhs) const;
        bool operator <= (const ConstCycleIterator& rhs) const;
        bool operator >  (const ConstCycleIterator& rhs) const;
        bool operator >= (const ConstCycleIterator& rhs) const;

        friend std::ostream&operator<<(std::ostream& os, const ConstCycleIterator& output);

    protected:
        // Forward struct declaration for the hidden implementation of a
        // constant Cycle iterator
        struct ConstCycleIteratorImplementation;

        // Declaration of an opaque pointer
        ConstCycleIteratorImplementation* handlei;
    }; // class ConstCycleIterator

    // Method that returns a constant Cycle iterator to the first Cycle of a
    // Region2D object.
    ConstCycleIterator cHbegin() const;

    // Method that returns a constant Cycle iterator to the last Cycle of a
    // Region2D object.
    ConstCycleIterator cHend() const;

    // Method that returns a constant Cycle iterator to the position before the
    // first Cycle of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant Cycle iterator.
    ConstCycleIterator cHhead() const;

    // Method that returns a constant Cycle iterator to the position after the
    // last Cycle of a Region2D object. Note that dereferencing this iterator
    // yields the empty constant Cycle iterator.
    ConstCycleIterator cHtail() const;

protected:
    // Forward struct declaration for the hidden implementation of class
    // "Region2D" as an abstract data type (ADT)
    struct Region2DImplementation;

    // Declaration of an opaque pointer
    Region2DImplementation *handle;

};

#endif /* REGION2D_H_ */