//
// Created by Djundi on 12/2/15.
//

#ifndef POINT2DPONT2D_POINT2DPOINT2D_H
#define POINT2DPONT2D_POINT2DPOINT2D_H

//#include "Object2D.h"
#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "TopologicalRelationships.h"


class Point2DPoint2D {
public:
    Point2DPoint2D(const Point2D &F, const Point2D &G);
    ~Point2DPoint2D();

    bool isTopologicalRelationship(TopPredNumberPoint2DPoint2D predicate);
    TopPredNumberPoint2DPoint2D getTopologicalRelationship();


private:

    // predicates enum
    enum class vF_Point2DPoint2D_Predicates {
        poi_shared, poi_disjoint
    };

    enum class vG_Point2DPoint2D_Predicates {
        poi_disjoint
    };



    Point2D objF, objG;
    static const int vF_size = 2;
    static const int vG_size = 1;

    bool vF[vF_size];
    bool vG[vG_size];

    /* getter functions */

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();


    // setter functions
    void setObjF(const Point2D &objF);
    void setObjG(const Point2D &objG);


    // Exploration function
    static void exploreTopoPred();

    // Evaluation functions
    static bool evaluateVerificationTopoPred();
    static TopPredNumberPoint2DPoint2D evaluateDeterminationTopoPred();


    // Since I don't know yet what the 9IMC, MT and MCDT nethods should return,
    // I am putting them as a TODO for now.

    // TODO: declare 9IMC method here:
    // ...

    // TODO: declare Matrix Thinning method here:
    // ...

    // TODO: declare MCDT method here:
    // ...

};


#endif //POINT2DPONT2D_POINT2DPOINT2D_H

