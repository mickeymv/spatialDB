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

class ObjectIterator {

public:

    // Default constructor that creates an empty constant Object iterator.
    virtual ObjectIterator()=0;

    // Copy constructor that constructs a constant Object iterator from a
    // given constant Object iterator "source".
    virtual ObjectIterator(const ObjectIterator& source)=0;

    // Move constructor that moves a given constant Object iterator "source"
    // to a constant Object iterator. The constant poi iterator "source"
    // gets the empty constant poi iterator as its value.
    virtual ObjectIterator(const ObjectIterator&& source)=0;

    // Destructor that frees the main memory space allocated for a constant
    // poi iterator.
    virtual ~ObjectIterator()=0;

    // Assignment operator that assigns another constant poi iterator
    // "rhs" to the constant poi iterator.
    virtual ObjectIterator& operator = (const ObjectIterator& rhs) =0;


    // Predicate that tests whether a constant iterator is empty.
    virtual bool isEmpty() const = 0;

    // Dereferencing operators that return the value at the constant object
    // iterator position. Dereferencing is only allowed if the iterator
    // points to a point. The dereferenced value cannot be changed.
    virtual const Object2D& operator *() const =0;
    virtual const Object2D* operator ->() const =0;


    // Increment/decrement operators '++', '--'
    virtual ObjectIterator &operator++() = 0;   // prefix
    virtual ObjectIterator operator++(int postfix) = 0; // postfix
    virtual ObjectIterator &operator--() = 0;   // prefix
    virtual ObjectIterator operator--(int postfix) = 0; // postfix

    // Comparison operators that compares a constant poi iterator position
    // with another const poi iterator position "rhs"
    virtual bool operator==(const ObjectIterator &rhs) const = 0;

    virtual bool operator!=(const ObjectIterator &rhs) const = 0;

    virtual bool operator<(const ObjectIterator &rhs) const = 0;

    virtual bool operator<=(const ObjectIterator &rhs) const = 0;

    virtual bool operator>(const ObjectIterator &rhs) const = 0;

    virtual bool operator>=(const ObjectIterator &rhs) const = 0;

};

#endif //PLANESWEEP_PROJECT_OBJECTITERATOR_H
