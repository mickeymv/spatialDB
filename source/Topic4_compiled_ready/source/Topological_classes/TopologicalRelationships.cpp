/******************************************************************************
* File: TopologicalRelationships.cpp
*******************************************************************************
* Purpose: Interface to exploration functions and validation predicates for
*   the topological relationships between two complex objects of the spatial
*   data types Point2D, Line2D, and Region2D
* Description: Topological relationships characterize the relative topological
*   position between two spatial objects.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/

#include "TopologicalRelationships.h"
#include "Point2DPoint2D.h"
#include "Point2DLine2D.h"
#include "Point2DRegion2D.h"
#include "Region2DRegion2D.h"


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


// TODO DTj: temporary excluded
/* Topological Relationship between a point2D object and a line2D object */

TopPredNumberPoint2DLine2D getTopologicalRelationship(const Point2D &lhs, const Line2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D predicate;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    predicate = pl->getTopologicalRelationship();
    delete pl;
    return predicate;

}

bool isTopologicalRelationship(const Point2D &lhs, const Line2D &rhs, TopPredNumberPoint2DLine2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    //Define predicate as an integer/matrix number
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->isTopologicalRelationship(predicate);
    delete pl;
    return isPredicate;

}

/* Topological Relationship between a point2D object and a region2D object */

//TopPredNumberPoint2DRegion2D getTopologicalRelationship(const Point2D &lhs, const Region2D &rhs) {
//
//    //Define predicate as an integer/matrix number
//    TopPredNumberPoint2DRegion2D predicate;
//    //Define predicate as an integer/matrix number
//
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    predicate = pr->getTopologicalRelationship();
//    delete pr;
//    return predicate;
//    //Implementation
//
//    return predicate;
//
//}
//
//bool isTopologicalRelationship(const Point2D &lhs, const Region2D &rhs, TopPredNumberPoint2DRegion2D predicate) {
//
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//
//    //Define predicate as an integer/matrix number
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->isTopologicalRelationship(predicate);
//    delete pr;
//
//    return isPredicate;
//
//}
//
///* Topological Relationship between a line2D object and a line2D object */
//
//TopPredNumberLine2DLine2D getTopologicalRelationship(const Line2D &lhs, const Line2D &rhs) {
//
//    //Define predicate as an integer/matrix number
//    TopPredNumberLine2DLine2D predicate;
//    //Define predicate as an integer/matrix number
//
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    predicate = ll->getTopologicalRelationship();
//    delete ll;
//    return predicate;
//
//
//}
//
//bool isTopologicalRelationship(const Line2D &lhs, const Line2D &rhs, TopPredNumberLine2DLine2D predicate) {
//
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//
//    //Define predicate as an integer/matrix number
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->isTopologicalRelationship(predicate);
//    delete ll;
//
//    return isPredicate;
//
//}
//
///* Topological Relationship between a line2D object and a region2D object */
//
//TopPredNumberLine2DRegion2D getTopologicalRelationship(const Line2D &lhs, const Region2D &rhs) {
//
//    //Define predicate as an integer/matrix number
//    TopPredNumberLine2DRegion2D predicate;
//
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    predicate = lr->getTopologicalRelationship();
//    delete lr;
//
//    return predicate;
//
//}
//
//bool isTopologicalRelationship(const Line2D &lhs, const Region2D &rhs, TopPredNumberLine2DRegion2D predicate) {
//
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate;
//
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->isTopologicalRelationship(predicate);
//    delete lr;
//
//    return isPredicate;
//
//}
//
///* Topological Relationship between a region2D object and a region2D object */

TopPredNumberRegion2DRegion2D getTopologicalRelationship(const Region2D &lhs, const Region2D &rhs) {

    //Define predicate as an integer/matrix number
    TopPredNumberRegion2DRegion2D predicate;

    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    predicate = rr->getTopologicalRelationship();
    delete rr;

    return predicate;


}

bool isTopologicalRelationship(const Region2D &lhs, const Region2D &rhs, TopPredNumberRegion2DRegion2D predicate) {

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->isTopologicalRelationship(predicate);
    delete rr;

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Point2D object
bool overlap(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->overlap();
    delete pp;
    return isPredicate;
}

bool disjoint(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->disjoint();
    delete pp;
    return isPredicate;
}

bool touch(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->touch();
    delete pp;
    return isPredicate;
}

bool equal(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->equal();
    delete pp;
    return isPredicate;
}

bool contains(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->contains();
    delete pp;
    return isPredicate;
}

bool covers(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->covers();
    delete pp;
    return isPredicate;
}

bool coveredBy(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->coveredBy();
    delete pp;
    return isPredicate;
}

bool inside(const Point2D &lhs, const Point2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;
    Point2DPoint2D *pp = new Point2DPoint2D(lhs, rhs);
    isPredicate = pp->inside();
    delete pp;
    return isPredicate;
}

////Cluster predicates for a Point2D object and a Line2D object
bool overlap(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->overlap();
    delete pl;
    return isPredicate;

}

bool disjoint(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->disjoint();
    delete pl;
    return isPredicate;

}

bool touch(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->meet();
    delete pl;
    return isPredicate;

}

bool equal(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->equal();
    delete pl;
    return isPredicate;

}

bool contains(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->contains();
    delete pl;
    return isPredicate;

}

bool covers(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->covers();
    delete pl;
    return isPredicate;

}

bool coveredBy(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->coveredBy();
    delete pl;
    return isPredicate;

}

bool inside(const Point2D &lhs, const Line2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Point2DLine2D *pl = new Point2DLine2D(lhs, rhs);
    isPredicate = pl->inside();
    delete pl;
    return isPredicate;

}

////Cluster predicates for a Point2D object and a Region2D object
//bool overlap(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->overlap();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool disjoint(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->disjoint();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool touch(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->meet();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool equal(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->equal();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool contains(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->contains();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool covers(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->covers();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool coveredBy(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->coveredBy();
//    delete pr;
//    return isPredicate;
//
//}
//
//bool inside(const Point2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Point2DRegion2D *pr = new Point2DRegion2D(lhs, rhs);
//    isPredicate = pr->inside();
//    delete pr;
//    return isPredicate;
//
//}
//
////Cluster predicates for a Line2D object and a Line2D object
//bool overlap(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->overlap();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool disjoint(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->disjoint();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool touch(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2Dlhs, rhs);
//    isPredicate = ll->meet();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool equal(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->equal();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool contains(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2Dlhs, rhs);
//    isPredicate = ll->contains();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool covers(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->covers();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool coveredBy(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->coveredBy();
//    delete ll;
//    return isPredicate;
//
//}
//
//bool inside(const Line2D &lhs, const Line2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DLine2D *ll = new Line2DLine2D(lhs, rhs);
//    isPredicate = ll->inside();
//    delete ll;
//    return isPredicate;
//
//}
//
////Cluster predicates for a Line2D object and a Region2D object
//bool overlap(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2Dlhs, rhs);
//    isPredicate = lr->overlap();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool disjoint(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->disjoint();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool touch(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2Dlhs, rhs);
//    isPredicate = lr->meet();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool equal(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->equal();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool contains(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2Dlhs, rhs);
//    isPredicate = lr->contains();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool covers(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->covers();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool coveredBy(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->coveredBy();
//    delete lr;
//    return isPredicate;
//
//}
//
//bool inside(const Line2D &lhs, const Region2D &rhs) {
//    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
//    bool isPredicate = false;
//    Line2DRegion2D *lr = new Line2DRegion2D(lhs, rhs);
//    isPredicate = lr->inside();
//    delete lr;
//    return isPredicate;
//
//}
//
////Cluster predicates for a Region2D object and a Region2D object
bool overlap(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->overlap();
    delete rr;
    return isPredicate;

}

bool disjoint(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->disjoint();
    delete rr;
    return isPredicate;

}

bool touch(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->meet();
    delete rr;
    return isPredicate;

}

bool equal(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->equal();
    delete rr;
    return isPredicate;

}

bool contains(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->contains();
    delete rr;
    return isPredicate;

}

bool covers(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->covers();
    delete rr;
    return isPredicate;

}

bool coveredBy(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->coveredBy();
    delete rr;
    return isPredicate;

}

bool inside(const Region2D &lhs, const Region2D &rhs) {
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;
    Region2DRegion2D *rr = new Region2DRegion2D(lhs, rhs);
    isPredicate = rr->inside();
    delete rr;
    return isPredicate;

}



