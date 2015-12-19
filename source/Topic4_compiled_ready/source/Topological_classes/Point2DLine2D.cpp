/******************************************************************************
* File: Point2DLine2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between a Point2D and a Line2D object.This also contains
 *  clustered predicate verification functions
 *
* Description: Implementation of Exploration and Evaluation algorithms and functions
 * for Topological Predicate Verification and Determination
 *
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors:Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/
#include "Point2DLine2D.h"


Point2DLine2D::Point2DLine2D(const Point2D &F, const Line2D &G) {
    // set obj1 and obj2
    objF=F;
    objG=G;

    // initialize vF and vG with false
    for (int i = 0; i < vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    // assigning the the matrix value
    for (int i=0; i< TopPredNumberPoint2DLine2DEnumSize; i++)
        matrix[i] = imctype (std::string(matrixStr[i]));

};

Point2DLine2D::~Point2DLine2D() {
};


bool *Point2DLine2D::getVF() {
    return vF;
}

bool *Point2DLine2D::getVG() {
    return vG;
}

void Point2DLine2D::exploreTopoPred() {
    PlaneSweep S(objF,objG);
    S.newSweep();
    Poi2D last_dp;

    //int count=0;
    while((S.getStatus()!=ParallelObjectTraversal::end_of_second)&&(S.getStatus()==ParallelObjectTraversal::end_of_none)&&(!(vF[poi_disjoint]&&vF[poi_on_interior]&&vF[poi_on_bound]&&vG[bound_poi_disjoint])))
    {
        ParallelObjectTraversal::object object_value = S.getObject();
        if(object_value==ParallelObjectTraversal::first)
        {
            Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first);
            if(S.poiInSeg(p))//poi_inSeg
            {
                vF[poi_on_interior]= true;
            }
            else
            {
                vF[poi_disjoint]=true;
            }
        }
        else if(object_value==ParallelObjectTraversal::second)
        {
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if(h.isLeft)
            {
                PlaneSweepLineStatusObject * psso = new PlaneSweepLineStatusObject(h.seg);
                S.addLeft(*psso);
                dp=h.seg.p1;
            }
            else
            {
                PlaneSweepLineStatusObject * psso = new PlaneSweepLineStatusObject(h.seg);
                S.delRight(*psso);
                dp=h.seg.p2;
            }
            if(dp!=last_dp)
            {
                last_dp=dp;
            }
            if(!S.lookAhead(h,ParallelObjectTraversal::second))
            {
                vG[bound_poi_disjoint]= true;
            }
        }
        else if(object_value==ParallelObjectTraversal::both)
        {
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if(h.isLeft)
            {
                PlaneSweepLineStatusObject * psso = new PlaneSweepLineStatusObject(h.seg);
                S.addLeft(*psso);
                dp=h.seg.p1;
            }
            else
            {
                PlaneSweepLineStatusObject * psso = new PlaneSweepLineStatusObject(h.seg);
                S.delRight(*psso);
                dp=h.seg.p2;
            }
            last_dp=dp;
            if(S.lookAhead(h,ParallelObjectTraversal::second))
            {
                vF[poi_on_interior]=true;
            }
            else
            {
                vF[poi_on_bound]=true;
            }
        }
        S.selectNext();
    }
    if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[poi_disjoint]=true;
    }
    return;
}

void Point2DLine2D::evaluateTopoPred()
{
    // Dtj. Dec 16.
    // matrix index 2,0 and 2,2 always true
    // Since the second row of the IMC 3x3 matrix is never evaluated,
    // here we only use six array member to represent the first row and third row of the 3x3 Matrix.
    imctype IMC = imctype (std::string("000101"));

    // populating the ICM with the value of vF and vG
    if(vF[poi_on_interior])
        IMC.set(5); // setting only one bit of a time: (100000);

    if(vF[poi_on_bound])
        IMC.set(4);  // (001000);

    if(vF[poi_disjoint])
        IMC.set(3);  // (000100);

    // IMC.set(2) : has been set in initialization

    if(vG[bound_poi_disjoint])
        IMC.set(1); // (000010);


    // compare/match the right one
    // loop exit if the top Pred number found
    for (int i = 0; i < TopPredNumberPoint2DLine2DEnumSize && !isPredSet; i++) {

        //test
        // cout << "matrix[" << i << "] = " << matrix[i] << endl;

        // Dtj. we do bitwise comparison for faster execution:
        if (IMC == matrix[i]) {isPredSet = true; topPredNumberPoint2DLine2D = (TopPredNumberPoint2DLine2D) i;}
    }

    // test
    // if (!isPredSet)
    // cout << "WARNING: isPredSet = " << isPredSet << endl;

}

TopPredNumberPoint2DLine2D Point2DLine2D::getTopologicalRelationship()
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DLine2D;
}

bool Point2DLine2D::isTopologicalRelationship(TopPredNumberPoint2DLine2D predicate)
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DLine2D==predicate)
    {
        return true;
    }
    return false;
}

bool Point2DLine2D::overlap()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if( topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_overlap_m9||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_overlap_m10||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_overlap_m13||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_overlap_m14)
    {
        return true;
    }
    return false;
}

bool Point2DLine2D::meet()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_meet_m3||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_meet_m4||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_meet_m5||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D::pl_meet_m6)
    {
        return true;
    }
    return false;
}

bool Point2DLine2D::inside()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_inside_m7||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_inside_m8||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_inside_m11||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_inside_m12)
    {
        return true;
    }
    return false;
}

bool Point2DLine2D::disjoint()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_disjoint_m1||topPredNumberPoint2DLine2D ==TopPredNumberPoint2DLine2D:: pl_disjoint_m2)
    {
        return true;
    }
    return false;
}

bool Point2DLine2D::contains()
{
    return false;
}

bool Point2DLine2D::coveredBy()
{
    return false;
}

bool Point2DLine2D::covers()
{
    return false;
}

bool Point2DLine2D::equal()
{
    return false;
}
