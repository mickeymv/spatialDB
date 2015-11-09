/******************************************************************************
 *  File: Point2D.cpp
******************************************************************************
*  Purpose:  This file implements the interfaces to the class Point2D and to
*   several nested iterator classes that enable access to components (that is,
*   faces, cycles, segments) of Point2D objects.

 *  Created on: Oct 8, 2015

 *  Authors: Ahmed Khaled, Revathi Kadari, Deepa Narain, Namrata Choudhury

 * Date: Fall Semester 2015
*******************************************************************************/


#include "Point2D.h"

struct ConstPoiIteratorImplementation {
    int iteratorIndex;
    Poi2D current;       //must be null point
};
struct point2DImplementation {
    std::vector<Poi2D> vecPoints;
    ConstPoiIteratorImplementation *first;
    ConstPoiIteratorImplementation *last;
};


// Empty constructor. Represents the empty point object.
Point2D::Point2D() {
    points = new point2DImplementation;
    points->first = new ConstPoiIteratorImplementation;
    points->last = new ConstPoiIteratorImplementation;
    points->vecPoints.clear();
    points->first->iteratorIndex = 0;
    points->last->iteratorIndex = 0;

}

// Constructor for complex Point2D object. It takes
// inputs as a vector of poi2D objects and creates a
// Poi2D object after checking if a valid Point2D
// object can be created from the input.
Point2D::Point2D(std::vector<Poi2D> pointList) {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::copy(pointList.begin(), pointList.end(), std::back_inserter(points->vecPoints));
    points->first = new ConstPoiIteratorImplementation;
    points->last = new ConstPoiIteratorImplementation;
    points->first->iteratorIndex = 0;
    points->last->iteratorIndex = points->vecPoints.size() - 1;
    points->first->current = points->vecPoints.at(0);
    points->last->current = points->vecPoints.at(points->vecPoints.size() - 1);

}

// Constructor for complex point structure. It takes as input a string name that can represent either :
// 1) file name which contains the vector of points from which to construct the Point2D object
// 2) string the textually represents the input vector of points.
//
// The grammar for representing a point vector in both cases 1 and 2 are structured as follows:
// Expression := (PointsList)
// PointsList := Point | Point,
// Point := (Number,Number)
//
// example for pointslist of point1, point2 and point3 here is: ((x1, y1),(x2, y2),(x3, y3))
Point2D::Point2D(std::string textualPointList) {
    points = new point2DImplementation;

    if (std::regex_match(textualPointList, std::regex("[a-z]+\\.txt|doc"))) {
        //read from file the representation is to be defined to parse lines and points inside the file
    }

    else if (std::regex_match(textualPointList,
                              std::regex(" (\\(\\([0-9]+,[0-9]+\\)\\))+ ")))//means the string is point representation
    {
        points->vecPoints.clear();
        textualPointList.erase(std::remove(textualPointList.begin(), textualPointList.end(), ')'),
                               textualPointList.end());
        textualPointList.erase(std::remove(textualPointList.begin(), textualPointList.end(), '('),
                               textualPointList.end());
        std::istringstream ss(textualPointList);

        std::string token;
        Number N1;
        int count = 0;

        while (std::getline(ss, token, ',')) {
            if (count == 0) {
                count = 1;
                N1 = Number(atof(token.c_str()));
            }
            else if (count == 1) {
                count = 0;
                points->vecPoints.push_back(Poi2D(N1, Number(atof(token.c_str()))));
            }
        }
        if (count == 1) {
            points->vecPoints.clear();
            return;
        } //not complete set of points
    }
    else {
        //throw error for invalid output
    }
}

// Copy constructor that constructs a new Point2D object with the same
// properties as the inputted Point2D object.
Point2D::Point2D(const Point2D &orginalPoint) {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::copy(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),
              std::back_inserter(points->vecPoints));
}

// Move constructor that moves the inputed Point2D object to a
// Point2D object. The inputed Point2D object gets the empty Point2D
// object as its value.
Point2D::Point2D(Point2D &&orginalPoint) {
    //move components
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::move(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),
              std::back_inserter(points->vecPoints));
}

// Destructor, that clears the internal objects of the Point2D structure.
//virtual Point2D::~Point2D(){}
Point2D::~Point2D() {
    delete points;
}



//+++++++++++++++++++++
// Assignment operators
//+++++++++++++++++++++


//copy assignment operator that copies the inputted object
//to the Point2D object

Point2D &Point2D::operator=(Point2D &orginalPoint) {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::copy(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),
              std::back_inserter(points->vecPoints));
}

// Move assignment operator that moves the inputted Point2D object to the
// Point2D object. The inputted object gets the empty Point2D
// object as its value.
Point2D &Point2D::operator=(Point2D &&orginalPoint) {
    points = new point2DImplementation;
    points->vecPoints.clear();
    std::move(orginalPoint.points->vecPoints.begin(), orginalPoint.points->vecPoints.end(),
              std::back_inserter(points->vecPoints));
}

// +++++++++++++++++++++
// operators and Comparison operators
// +++++++++++++++++++++

// Equal operator that checks if the Point2D object and the operand Point2D are the same spatial point.
bool Point2D::operator==(Point2D &operand) {
    if (points->vecPoints.size() != operand.points->vecPoints.size())
        return false;
    int x = 0;
    for (unsigned i = 0; i < points->vecPoints.size(); i++) {
        x = 0;
        for (unsigned j = 0; j < operand.points->vecPoints.size(); j++) {
            if (points->vecPoints.at(i) == operand.points->vecPoints.at(j)) {
                x = 1;
                break;
            }
        }
        if (x == 0)
            return false;
    }
    return true;
}

// unequal operator that checks if the Point2D object and the operand
// Point2D are different spatial structures. It is the logical opposite
// of the == operator.
bool Point2D::operator!=(Point2D &operand) {
    if (points->vecPoints.size() != operand.points->vecPoints.size())
        return true;
    int x = 0;
    for (unsigned i = 0; i < points->vecPoints.size(); i++) {
        x = 0;
        for (unsigned j = 0; j < operand.points->vecPoints.size(); j++) {
            if (points->vecPoints.at(i) == operand.points->vecPoints.at(j)) {
                x = 1;
                break;
            }
        }
        if (x == 0)
            return true;
    }
    return false;
}

// less than operator that compares 2 Point2D objects through comparing their minimum bounding rectangles in the following way:
// if (min(x1) < min(x2)) the object is less than the operand object
// if ((min(x1) = min(x2)) and (min(y1) < min(y2))) the object is less than the operand object
// where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
bool Point2D::operator<(Point2D &operand) {
    if (isEmptyPoint2D() || operand.isEmptyPoint2D())
        return false;
    Poi2D poi1 = points->vecPoints.at(0);
    Poi2D poi2 = operand.points->vecPoints.at(0);
    int x = (points->vecPoints.size() > operand.points->vecPoints.size()) ? points->vecPoints.size()
                                                                          : operand.points->vecPoints.size();
    for (unsigned i = 1; i < x; i++) {
        if (i < points->vecPoints.size()) {
            if (points->vecPoints.at(i) < poi1) {
                poi1 = points->vecPoints.at(i);
            }
        }
        if (i < operand.points->vecPoints.size()) {
            if (operand.points->vecPoints.at(i) < poi2) {
                poi2 = operand.points->vecPoints.at(i);
            }
        }
    }
    if (poi1 < poi2) return true;
    return false;
}

// less or equal than operator that compares 2 Point2D objects through comparing their minimum bounding rectangles in the following way:
// if (min(x1) <= min(x2)) the object is less than or equal the operand object
// if ((min(x1) = min(x2)) and (min(y1) <= min(y2))) the object is less than or equal the operand object
// where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
bool Point2D::operator<=(Point2D &operand) {
    if (isEmptyPoint2D() || operand.isEmptyPoint2D())
        return false;
    Poi2D poi1 = points->vecPoints.at(0);
    Poi2D poi2 = operand.points->vecPoints.at(0);
    int x = (points->vecPoints.size() > operand.points->vecPoints.size()) ? points->vecPoints.size()
                                                                          : operand.points->vecPoints.size();
    for (unsigned i = 1; i < x; i++) {
        if (i < points->vecPoints.size()) {
            if (points->vecPoints.at(i) < poi1) {
                poi1 = points->vecPoints.at(i);
            }
        }
        if (i < operand.points->vecPoints.size()) {
            if (operand.points->vecPoints.at(i) < poi2) {
                poi2 = operand.points->vecPoints.at(i);
            }
        }
    }
    if (poi1 <= poi2) {
        return true;
    }
    return false;
}

// greater than operator that compares 2 Point2D objects through comparing their minimum bounding rectangles in the following way:
// if (min(x1) > min(x2)) the object is greater the operand object
// if ((min(x1) = min(x2)) and (min(y1) > min(y2))) the object is greater the operand object
// where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
bool Point2D::operator>(Point2D &operand) {
    if (isEmptyPoint2D() || operand.isEmptyPoint2D())
        return false;
    Poi2D poi1 = points->vecPoints.at(0);
    Poi2D poi2 = operand.points->vecPoints.at(0);
    int x = (points->vecPoints.size() > operand.points->vecPoints.size()) ? points->vecPoints.size()
                                                                          : operand.points->vecPoints.size();
    for (unsigned i = 1; i < x; i++) {
        if (i < points->vecPoints.size()) {
            if (points->vecPoints.at(i) < poi1) {
                poi1 = points->vecPoints.at(i);
            }
        }
        if (i < operand.points->vecPoints.size()) {
            if (operand.points->vecPoints.at(i) < poi2) {
                poi2 = operand.points->vecPoints.at(i);
            }
        }
    }
    if (poi1 > poi2) {
        return true;
    }
    return false;
}

// greater or equal than operator that compares 2 Point2D objects through comparing their minimum bounding rectangles in the following way:
// if (min(x1) >= min(x2)) the object is greater than or equal the operand object
// if ((min(x1) = min(x2)) and (min(y1) >= min(y2))) the object is greater than or equal the operand object
// where min(x) and min(y) are the points with the minimum x,y values within the structure respectively.
bool Point2D::operator>=(Point2D &operand) {
    if (isEmptyPoint2D() || operand.isEmptyPoint2D())
        return false;
    Poi2D poi1 = points->vecPoints.at(0);
    Poi2D poi2 = operand.points->vecPoints.at(0);
    int x = (points->vecPoints.size() > operand.points->vecPoints.size()) ? points->vecPoints.size()
                                                                          : operand.points->vecPoints.size();
    for (unsigned i = 1; i < x; i++) {
        if (i < points->vecPoints.size()) {
            if (points->vecPoints.at(i) < poi1) {
                poi1 = points->vecPoints.at(i);
            }
        }
        if (i < operand.points->vecPoints.size()) {
            if (operand.points->vecPoints.at(i) < poi2) {
                poi2 = operand.points->vecPoints.at(i);
            }
        }
    }
    if (poi1 >= poi2) {
        return true;
    }
    return false;
}

// Display function, that displayes the information of Point2D structure as follows:
// the number of points contained in the structure, then information of each point in the point-vector structure.

std::ostream &operator<<(std::ostream &os, const Point2D &output) {
    os << "number of points" << output.points->vecPoints.size() << " ";
    os << endl;
    for (unsigned i = 0; i < output.points->vecPoints.size(); i++)
        os << "point " << i << ":" << output.points->vecPoints[i] << " ";
    os << endl;
    return os;
}

//++++++++++++++++++++++++++++++++
// Unary predicates and operations
//++++++++++++++++++++++++++++++++

// get number of single points of the structure.
Number Point2D::numPoints() {
    return Number(points->vecPoints.size());
}

// Predicate that checks whether the inputted Point2D object is an
// empty Point2D object.
bool Point2D::isEmptyPoint2D() {
    return points->vecPoints.empty();
}


// +++++++++++++++++++
// Iterator functions
// +++++++++++++++++++
// Default constructor that creates an empty constant poi iterator.
Point2D::ConstPoiIterator::ConstPoiIterator() {
    handle = new ConstPoiIteratorImplementation;
    handle->iteratorIndex = 0;
}

// Copy constructor that constructs a constant poi iterator from a
// given constant poi iterator "source".
Point2D::ConstPoiIterator::ConstPoiIterator(const ConstPoiIterator &source) {
    handle->iteratorIndex = source.handle->iteratorIndex;
}

// Move constructor that moves a given constant poi iterator "source"
// to a constant poi iterator. The constant poi iterator "source"
// gets the empty constant poi iterator as its value.
Point2D::ConstPoiIterator::ConstPoiIterator(ConstPoiIterator &&source) {
    handle->iteratorIndex = std::move(source.handle->iteratorIndex);
}

// Destructor that frees the main memory space allocated for a constant
// poi iterator.
Point2D::ConstPoiIterator::~ConstPoiIterator() {
    delete handle;
}

// Assignment operator that assigns another constant poi iterator
// "rhs" to the constant poi iterator.
Point2D::ConstPoiIterator &Point2D::ConstPoiIterator::operator=(const ConstPoiIterator &rhs) {
    handle->iteratorIndex = rhs.handle->iteratorIndex;
    handle->current = rhs.handle->current;
}

// Predicate that tests whether a constant poi iterator is empty.
bool Point2D::ConstPoiIterator::isEmpty() const {
}

// Increment/decrement operators '++', '--'
Point2D::ConstPoiIterator &Point2D::ConstPoiIterator::operator++() {
    //  handle = handle->next;
    // return this;

}

// prefix
Point2D::ConstPoiIterator Point2D::ConstPoiIterator::operator++(int postfix) {
    return (*this);
    this->handle->iteratorIndex++;

}

// postfix
Point2D::ConstPoiIterator &Point2D::ConstPoiIterator::operator--() {

    this->handle->iteratorIndex++;
    return (*this);

}

// prefix
Point2D::ConstPoiIterator Point2D::ConstPoiIterator::operator--(int postfix) {
    return (*this);
    this->handle->iteratorIndex++;

}// postfix

// Dereferencing operators that return the value at the constant poi
// iterator position. Dereferencing is only allowed if the iterator
// points to a point. The dereferenced value cannot be changed.
const Poi2D &Point2D::ConstPoiIterator::operator*() const {

}

const Poi2D *Point2D::ConstPoiIterator::operator->() const {

}

// Comparison operators that compares a constant poi iterator position
// with another const poi iterator position "rhs"
bool Point2D::ConstPoiIterator::operator==(const ConstPoiIterator &rhs) const {

}

bool Point2D::ConstPoiIterator::operator!=(const ConstPoiIterator &rhs) const {

}

bool Point2D::ConstPoiIterator::operator<(const ConstPoiIterator &rhs) const {
}

bool Point2D::ConstPoiIterator::operator<=(const ConstPoiIterator &rhs) const {

}

bool Point2D::ConstPoiIterator::operator>(const ConstPoiIterator &rhs) const {

}

bool Point2D::ConstPoiIterator::operator>=(const ConstPoiIterator &rhs) const {

}


// Method that returns a constant poi iterator to the first point of a
// Point2D object.
Point2D::ConstPoiIterator Point2D::cbegin() const {
    ConstPoiIterator begin;
    begin.handle = points->first;
    return begin;
}

// Method that returns a constant poi iterator to the last point of a
// Point2D object.
Point2D::ConstPoiIterator Point2D::cend() const {
    ConstPoiIterator last;
    last.handle = points->last;
    return last;
}

std::ostream &operator<<(std::ostream &os, const Point2D::ConstPoiIterator &output) {
    os << "index Value:" << output.handle->iteratorIndex << " ";
    os << "point Value:" << output.handle->current << " ";
    return os;
}

// Method that returns a constant poi iterator to the position before the
// first face of a Point2D object. Note that dereferencing this iterator
// yields the empty constant poi iterator.
Point2D::ConstPoiIterator Point2D::chead() const {

}

// Method that returns a constant poi iterator to the position after the
// last face of a Point2D object. Note that dereferencing this iterator
// yields the empty constant poi iterator.
Point2D::ConstPoiIterator Point2D::ctail() const {

}


