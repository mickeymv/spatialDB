/******************************************************************************
 *  File: Point2D.h	
 ******************************************************************************
 *  Purpose:  This file specifies the interface to the class Point2D and to
 *  the nested iterator class that enables access to the simple points of the
 *  Point2D objects.
 
 *  Created on: Oct 8, 2015
 
 *  Authors: Ahmed Khaled, Revathi Kadari, Deepa Narain, Namrata Choudhury
 
 *  Date: Fall Semester 2015
 *******************************************************************************/

#ifndef POINT2D_H_
#define POINT2D_H_

#include <vector>
#include "RobustGeometricPrimitives2D.h"
using namespace std;


class Point2D
{
  public:

      // +++++++++++++++++++++
      // Constructors
      // +++++++++++++++++++++
      
      // Empty constructor. Represents the empty point object.
      Point2D();

      // Constructor for complex Point2D object. It takes
      // vector of poi2D objects as input and creates a
      // Point2D object after checking if a valid Point2D
      // object can be created from the input.
      Point2D(std::vector<Poi2D> pointList);

      // Constructor for complex point structure. It takes as input a string that represents the  
      // string that textually represents the input vector of points.
      // The grammar for representing a point vector in both cases 1 and 2 are structured as follows:
      // Expression       := '(' Point (',' [WhiteSpace] Point)* ')'
      // Point            := '(' Number ',' [WhiteSpace] Number ')'
      // Number           := Sign ((DigitWithoutZero Digit* '.' Digit+) | ('0' '.' Digit+ ))
      // Sign             := ['+' | '-']
      // WhiteSpace       := ' '
      // DigitWithoutZero := '1' | '2' |'3' | '4' | '5' | '6' | '7' | '8' | '9'
      // Digit            := '0' | DigitWithoutZero
      // example for pointslist of point1, point2 and point3 here is: ((0, 0),(4, 5),(10, 10))
      Point2D(std::string textualPointList);

      // Copy constructor that constructs a new Point2D object with the same
      // properties as the inputted Point2D object. 
      Point2D(const Point2D& originalPoint);

      // Move constructor that moves the inputed Point2D object to a
      // Point2D object. The inputed Point2D object gets the empty Point2D
      // object as its value.
      Point2D(Point2D&& originalPoint);

      // Destructor, that clears the internal objects of the Point2D structure.
      virtual ~Point2D();
      
      //+++++++++++++++++++++
      // Assignment operators
      //+++++++++++++++++++++
      
      //copy assignment operator that copies the inputted object
      //to the Point2D object
      Point2D& operator = (const Point2D& originalPoint);

      // Move assignment operator that moves the inputted Point2D object to the
      // Point2D object. The inputted object gets the empty Point2D
      // object as its value.
      Point2D& operator = (Point2D&& originalPoint);

      // ++++++++++++++++++++++++++++++++++
      // Operators and Comparison operators
      // ++++++++++++++++++++++++++++++++++
      
      // Equal operator that checks if the Point2D object and the operand Point2D are the same spatial point.
      bool operator == (Point2D& operand);
      
      // unequal operator that checks if the Point2D object and the operand
      // Point2D are different spatial structures. It is the logical opposite
      // of the == operator.
      bool operator != (Point2D& operand);

      // less than comparision of lexicographic order of points
      bool operator < (Point2D& operand);
      
      // less than or equal comparision of lexicographic order of points
      bool operator <= (Point2D& operand);
        
      // greater than comparision of lexicographic order of points
      bool operator > (Point2D& operand);
      
      // greater than or equal comparision of lexicographic order of points
      bool operator >= (Point2D& operand);

      // Display function, that displayes the information of Point2D structure as follows:
      // the number of points contained in the structure, then information of each point in the point-vector structure.
      friend std::ostream&operator<<(std::ostream&, const Point2D&);
      
      //++++++++++++++++++++++++++++++++
      // Unary predicates and operations
      //++++++++++++++++++++++++++++++++
      
      // get number of single points of the structure.
      Number numPoints();
      
      // Predicate that checks whether the inputted Point2D object is an
      //empty Point2D object.
      bool isEmptyPoint2D() const;


      //+++++++++++++++++
      // Iterator classes
      //+++++++++++++++++

      // Constant poi iterator type that allows to navigate through the points of
      // a Point2D object in forward and reverse direction. A change of the
      // points is not possible.
      class ConstPoiIterator
      {
        friend class Point2D;

          public:
            // Default constructor that creates an empty constant poi iterator.
            ConstPoiIterator();

            // Copy constructor that constructs a constant poi iterator from a
            // given constant poi iterator "source".
            ConstPoiIterator(const ConstPoiIterator& source);

            // Move constructor that moves a given constant poi iterator "source"
            // to a constant poi iterator. The constant poi iterator "source"
            // gets the empty constant poi iterator as its value.
            ConstPoiIterator(ConstPoiIterator&& source);

            // Destructor that frees the main memory space allocated for a constant
            // poi iterator.
            ~ConstPoiIterator();

            // Assignment operator that assigns another constant poi iterator
            // "rhs" to the constant poi iterator.
            ConstPoiIterator& operator = (const ConstPoiIterator& rhs);

            // Predicate that tests whether a constant poi iterator is empty.
            bool isEmpty() const;
            
            // Friend member function used to print out the interator information
            friend std::ostream&operator<<(std::ostream&, const ConstPoiIterator&);
            
            // Increment/decrement operators '++', '--'
            ConstPoiIterator& operator ++ ();   // prefix
            ConstPoiIterator operator ++ (int postfix); // postfix
            ConstPoiIterator& operator -- ();   // prefix
            ConstPoiIterator operator -- (int postfix); // postfix

            // Dereferencing operators that return the value at the constant poi
            // iterator position. Dereferencing is only allowed if the iterator
            // points to a point. The dereferenced value cannot be changed.
            const Poi2D& operator *() const;
            const Poi2D* operator ->() const;

            // Comparison operators that compares a constant poi iterator position
            // with another const poi iterator position "rhs"
            bool operator == (const ConstPoiIterator& rhs) const;
            bool operator != (const ConstPoiIterator& rhs) const;
            bool operator <  (const ConstPoiIterator& rhs) const;
            bool operator <= (const ConstPoiIterator& rhs) const;
            bool operator >  (const ConstPoiIterator& rhs) const;
            bool operator >= (const ConstPoiIterator& rhs) const;

            private:
              // Forward struct declaration for the hidden implementation of a
              // constant point iterator that holds the different variables of the iterator
              struct ConstPoiIteratorImplementation;  
              ConstPoiIteratorImplementation* handle;  // Declaration of an opaque pointer
        }; // class ConstPoiIterator

        // Method that returns a constant poi iterator to the first Point of a
        // Point2D object.
        ConstPoiIterator cbegin() const;

        // Method that returns a constant poi iterator to the last Point of a
        // Point2D object.
        ConstPoiIterator cend() const;

        // Method that returns a constant poi iterator to the position before the
        // first face of a Point2D object. Note that dereferencing this iterator
        // yields the empty constant poi iterator.
        ConstPoiIterator chead() const;

        // Method that returns a constant poi iterator to the position after the
        // last face of a Point2D object. Note that dereferencing this iterator
        // yields the empty constant poi iterator.
        ConstPoiIterator ctail() const;
    
  private:
    struct point2DImplementation;    //Structure that holds all required information for building the Point2D structure
    point2DImplementation* points;   //pointer for the internal structure
};

#endif /* POINT2D_H_ */
