//
// Created by Natasha on 11/15/2015.
//

#ifndef PLANESWEEP_PROJECT_OBJECTITERATOR_H
#define PLANESWEEP_PROJECT_OBJECTITERATOR_H

/**This is a pure virtual class/ abstract base class/Interface class which will have no objects of its own.
* It's upto the derived classes; Poi, Line and RegionIterators to have definitions for
* the methods in this class.
*/

class ObjectIterator {

public:

    // Predicate that tests whether a constant iterator is empty.
    virtual bool isEmpty() const = 0;


    // Increment/decrement operators '++', '--'
    virtual ObjectIterator &operator++() = 0;   // prefix
    virtual ObjectIterator operator++(int postfix) = 0; // postfix
    virtual ObjectIterator &operator--() = 0;   // prefix
    virtual ObjectIterator operator--(int postfix) = 0; // postfix

    // Comparison operators that compares a constant poi iterator position
    // with another const poi iterator position "rhs"
    virtual bool operator==(const ConstPoiIterator &rhs) const = 0;

    virtual bool operator!=(const ConstPoiIterator &rhs) const = 0;

    virtual bool operator<(const ConstPoiIterator &rhs) const = 0;

    virtual bool operator<=(const ConstPoiIterator &rhs) const = 0;

    virtual bool operator>(const ConstPoiIterator &rhs) const = 0;

    virtual bool operator>=(const ConstPoiIterator &rhs) const = 0;

};

#endif //PLANESWEEP_PROJECT_OBJECTITERATOR_H
