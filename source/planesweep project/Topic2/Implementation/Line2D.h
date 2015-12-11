/******************************************************************************
* File: Line2D.h
*******************************************************************************
* Purpose: Interface to the class for the spatial data type Line2D
*
* Description: This file specifies interface to the class Line2D and to
*   several nested iterator classes that enable access to components (that is,
*   segments and block) of Line2D objects. The class Line2D contains
*   specifications of several constructors, a destructor, and several
*   type-specific unary methods of this spatial data type.  
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 2 (Ahmed Khaled, Revathi Kadari, Namrata Choudhury, Deepa Narain)
*
* Date: Fall Semester 2015
******************************************************************************/

#ifndef Line2D_H
#define Line2D_H

#include "RobustGeometricPrimitives2D.h"
#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;


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
    Line2D(std::string textualLineList);
    

    // Copy constructor that constructs a Line2D object from a given Line2D
    // object "source".
    Line2D(const Line2D& source);

    // Move constructor that moves a given Line2D object "source" to a
    // Line2D object. The Line2D object "source" gets the empty Line2D
    // object as its value.
    Line2D(Line2D&& source);

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
    bool operator == ( Line2D& rhs);
	
    //unequal operator that checks if the Line2D object and the inputted
    //Line2D object are different spatial regions. It is the logical opposite
    //of the == operator.
    bool operator != ( Line2D& rhs);
	
    //less than operator that compares 2 Line2D objects and checks which one is lesser 
    //by comparing their sorted half segments in lexicographic order.
    // Eg: Line1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) < Line2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since 
    // ((0,0),(1,1)) < ((5,5),(6,6))
    bool operator <  ( Line2D& rhs); 

    //less than or equal operator that compares 2 Line2D objects and checks which one is lesser 
    //or equal by comparing their sorted half segments in lexicographic order.
    // Eg: Line1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) <= Line2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns true since 
    // ((0,0),(1,1)) < ((5,5),(6,6))	
    bool operator <= ( Line2D& rhs);   

    //greater than operator that compares 2 Line2D objects and checks which one is greater 
    //by comparing their sorted half segments in lexicographic order.
    // Eg: Line1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) > Line2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since 
    // ((0,0),(1,1)) < ((5,5),(6,6))	
    bool operator >  (Line2D& rhs);  

    //greater than or equal to operator that compares 2 Line2D objects and checks which one is greater 
    //or equal by comparing their sorted half segments in lexicographic order.
    // Eg: Line1(((0,0),(1,1)),((0,0),(2,0)),((1,1),(2,0))) >= Line2(((5,5),(6,6)),((5,5),(7,5)),((6,6),(7,5))) returns false since 
    // ((0,0),(1,1)) < ((5,5),(6,6))
    bool operator >= (Line2D& rhs);    


    //++++++++++++++++++++++++++++++++
    // Unary predicates and operations
    //++++++++++++++++++++++++++++++++

    // Predicate that checks whether a Line2D object is an empty Line2D
    // object. 
    bool isEmptyLine2D() const;;

    // Method that yields the number of segments of Line2D object
    // If the Line2D object is an empty Line2D object, the value
    // 0 is returned.
    Number getNumberOfSegments();


    //++++++++++++++++
    // Output function
    //++++++++++++++++

    // Textual output of segments of a Line2D object
    friend ostream& operator << (ostream& ostr, const Line2D& rhs);



    //++++++++++++++++++++++
    //++ Block iterator ++++
    //++++++++++++++++++++++
    // Constant block iterator type that allows to navigate through the blocks of
    // a Line2D object in forward and reverse direction. A change of the
    // blocks is not possible.
    class ConstBlockIterator
    {
      friend class Line2D;

      public:
        // Default constructor that creates an empty constant block iterator.
        ConstBlockIterator();

        // Copy constructor that constructs a constant block iterator from a
        // given constant block iterator "source".
        ConstBlockIterator(const ConstBlockIterator& source);

        // Move constructor that moves a given constant block iterator "source"
        // to a constant block iterator. The constant block iterator "source"
        // gets the empty constant block iterator as its value.
        ConstBlockIterator(const ConstBlockIterator&& source);

        // Destructor that frees the main memory space allocated for a constant
        // block iterator.
        ~ConstBlockIterator();

        // Assignment operator that assigns another constant block iterator
        // "rhs" to the constant block iterator.
        ConstBlockIterator& operator = (const ConstBlockIterator& rhs);

        // Predicate that tests whether a constant block iterator is empty.
        bool isEmpty() const;

        // Increment/decrement operators '++', '--'
        ConstBlockIterator& operator ++ ();   // prefix
        ConstBlockIterator operator ++ (int); // postfix
        ConstBlockIterator& operator -- ();   // prefix
        ConstBlockIterator operator -- (int); // postfix

        // Dereferencing operators that return the value at the constant block
        // iterator position. Dereferencing is only allowed if the iterator
        // points to a block. The dereferenced value cannot be changed.
        const Line2D operator *() const;
        const Line2D operator ->() const;

        // Comparison operators that compare a constant block iterator position
        // with another const block iterator position "rhs"
        bool operator == (const ConstBlockIterator& rhs) const;
        bool operator != (const ConstBlockIterator& rhs) const;
        bool operator <  (const ConstBlockIterator& rhs) const;
        bool operator <= (const ConstBlockIterator& rhs) const;
        bool operator >  (const ConstBlockIterator& rhs) const;
        bool operator >= (const ConstBlockIterator& rhs) const;
        
        friend std::ostream&operator<<(std::ostream&, const ConstBlockIterator&);

      protected:
        // Forward struct declaration for the hidden implementation of a
        // constant block iterator that holds the different variables of the iterator
        struct ConstBlockIteratorImplementation;

        // Declaration of an opaque pointer
        ConstBlockIteratorImplementation* handlei;
    }; // class ConstBlockIterator

    // Method that returns a constant block iterator to the first block of a
    // Line2D object.
    ConstBlockIterator bBegin() const;

    // Method that returns a constant block iterator to the last block of a
    // Line2D object.
    ConstBlockIterator bEnd() const;

    // Method that returns a constant block iterator to the position before the
    // first block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    ConstBlockIterator bHead() const;

    // Method that returns a constant block iterator to the position after the
    // last block of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant block iterator.
    ConstBlockIterator bTail() const;
    
    
    
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
        const Seg2D& operator *() const;
        const Seg2D* operator ->() const;

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
        // constant segment iterator that holds the different variables of the iterator
        struct ConstSegIteratorImplementation;

        // Declaration of an opaque pointer
        ConstSegIteratorImplementation* handlei;
    }; // class ConstSegIterator

    // Method that returns a constant segment iterator to the first segment of a
    // Line2D object.
    ConstSegIterator sBegin() const;

    // Method that returns a constant segment iterator to the last segment of a
    // Line2D object.
    ConstSegIterator sEnd() const;

    // Method that returns a constant segment iterator to the position before the
    // first segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    ConstSegIterator sHead() const;

    // Method that returns a constant segment iterator to the position after the
    // last segment of a Line2D object. Note that dereferencing this iterator
    // yields the empty constant segment iterator.
    ConstSegIterator sTail() const;
    
    
  protected:
    // Forward struct declaration for the hidden implementation of class
    // "Line2D" as an abstract data type (ADT)
    struct Line2DSImpl;

    // Declaration of an opaque pointer
    Line2DSImpl *handle;
}; // class Line2D

#endif // Line2D_H
