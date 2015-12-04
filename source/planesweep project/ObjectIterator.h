//
// Created by Mickey on 11/12/2015.
//

#ifndef PLANESWEEP_PROJECT_OBJECTITERATOR_H
#define PLANESWEEP_PROJECT_OBJECTITERATOR_H

/**This is a pure virtual class/ abstract base class/Interface class which will have no objects of its own.
* It's upto the derived classes; Poi, Line and RegionIterators to have definitions for
* the methods in this class.
*/
#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"
#include "Object2D.h"

class ObjectIterator {

public:

    // Predicate that tests whether a constant iterator is empty.
    bool isEmpty() const;
    //TODO: this function is defined with different names in Line and point and region. Need to handle for that.


    // Dereferencing operators that return the value at the constant object
    // iterator position. Dereferencing is only allowed if the iterator
    // points to a point. The dereferenced value cannot be changed.
//    virtual const Object2D & operator *() const =0;
//    virtual const Object2D * operator ->() const =0;


    // Increment/decrement operators '++', '--'
    virtual ObjectIterator &operator++() = 0;   // prefix
    //virtual ObjectIterator operator++(int postfix) = 0; // postfix //TODO: errors out in the Derived classes. Need to figure out why.
    virtual ObjectIterator &operator--() = 0;   // prefix
    //virtual ObjectIterator operator--(int postfix) = 0; // postfix //TODO: errors out in the Derived classes. Need to figure out why.


    // Comparison operators that compares a constant poi iterator position
    // with another const poi iterator position "rhs"
    virtual bool operator==(const ObjectIterator &rhs) const = 0;

    virtual bool operator!=(const ObjectIterator &rhs) const = 0;

    virtual bool operator<(const ObjectIterator &rhs) const = 0;

    virtual bool operator<=(const ObjectIterator &rhs) const = 0;

    virtual bool operator>(const ObjectIterator &rhs) const = 0;

    virtual bool operator>=(const ObjectIterator &rhs) const = 0;

    // Method that returns a constant  iterator to the first element of an
    //  object.
    ObjectIterator cbegin() const;

    // Method that returns a constant  iterator to the last element of an object.
    ObjectIterator cend() const;

    // Method that returns a constant iterator to the position before the
    // first face of an object. Note that dereferencing this iterator
    // yields the empty constant iterator.
    ObjectIterator chead() const;

    // Method that returns a constant iterator to the position after the
    // last face of an object. Note that dereferencing this iterator
    // yields the empty constant iterator.
    ObjectIterator ctail() const;

};

#endif //PLANESWEEP_PROJECT_OBJECTITERATOR_H
