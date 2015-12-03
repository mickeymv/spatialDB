//
// Created by Djundi on 10/10/15.
//

#include "TopologicalRelationships.h"
#include "Point2DPoint2D.h"


//Topological Relationship between a point2D object and a point2D object
TopPredNumberPoint2DPoint2D getTopologicalRelationship(const Point2D &lhs, const Point2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DPoint2D predicate;

    //Implementation
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);

    predicate = pp->getTopologicalRelationship();

    delete pp;

    return predicate;
}

bool isTopologicalRelationship(const Point2D &lhs, const Point2D &rhs, TopPredNumberPoint2DPoint2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);

    isPredicate = pp->isTopologicalRelationship(predicate);

    delete pp;


    return isPredicate;

}

/* Topological Relationship between a point2D object and a line2D object */

TopPredNumberPoint2DLine2D getTopologicalRelationship(const Point2D &lhs, const Line2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D predicate;
    Point2DLine2D *pl = new pl(lhs, rhs);
    predicate = pl->getTopologicalRelationship();
    delete pl;
    return predicate;

}

bool isTopologicalRelationship(const Point2D &lhs, const Line2D &rhs, TopPredNumberPoint2DLine2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    //Define predicate as an integer/matrix number
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->isTopologicalRelationship(predicate);
    delete pl;
    return isPredicate;

}

/* Topological Relationship between a point2D object and a region2D object */

TopPredNumberPoint2DRegion2D getTopologicalRelationship(const Point2D &lhs, const Region2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DRegion2D predicate;

    //Implementation

    return predicate;

}

bool isTopologicalRelationship(const Point2D &lhs, const Region2D &rhs, TopPredNumberPoint2DRegion2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a line2D object and a line2D object */

TopPredNumberLine2DLine2D getTopologicalRelationship(const Line2D &lhs, const Line2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberLine2DLine2D predicate;

    //Implementation

    return predicate;


}

bool isTopologicalRelationship(const Line2D &lhs, const Line2D &rhs, TopPredNumberLine2DLine2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a line2D object and a region2D object */

TopPredNumberLine2DRegion2D getTopologicalRelationship(const Line2D &lhs, const Region2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberLine2DRegion2D predicate;

    //Implementation

    return predicate;

}

bool isTopologicalRelationship(const Line2D &lhs, const Region2D &rhs, TopPredNumberLine2DRegion2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a region2D object and a region2D object */

TopPredNumberRegion2DRegion2D getTopologicalRelationship(const Region2D &lhs, const Region2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberRegion2DRegion2D predicate;

    //Implementation

    return predicate;


}

bool isTopologicalRelationship(const Region2D &lhs, const Region2D &rhs, TopPredNumberRegion2DRegion2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Point2D object
bool overlap(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Line2D object
bool overlap(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->overlap();
    delete pl;
    return isPredicate;

}

bool disjoint(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->disjoint();
    delete pl;
    return isPredicate;

}

bool touch(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->meet();
    delete pl;
    return isPredicate;

}

bool equal(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->equal();
    delete pl;
    return isPredicate;

}

bool contains(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->contains();
    delete pl;
    return isPredicate;

}

bool covers(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->covers();
    delete pl;
    return isPredicate;

}

bool coveredBy(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->coveredBy();
    delete pl;
    return isPredicate;

}

bool inside(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new pl(lhs, rhs);
    isPredicate = pl->inside();
    delete pl;
    return isPredicate;

}

//Cluster predicates for a Point2D object and a Region2D object
bool overlap(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Point2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Line2D object and a Line2D object
bool overlap(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Line2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Line2D object and a Region2D object
bool overlap(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Line2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Region2D object and a Region2D object
bool overlap(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}



