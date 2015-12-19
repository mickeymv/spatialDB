/******************************************************************************
* File: Point2DRegion2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between a Point2D and a Region2D object.This also contains
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
#include "Point2DRegion2D.h"

Point2DRegion2D::Point2DRegion2D(const Point2D &F, const Region2D &G) {
    // set obj1 and obj2
    objF=F;
    objG=G;

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    // assigning the the matrix value
    for (int i=0; i< TopPredNumberPoint2DRegion2DEnumSize; i++)
        matrix[i] = imctype (std::string(matrixStr[i]));

};

Point2DRegion2D::~Point2DRegion2D() { };


bool *Point2DRegion2D::getVF() {
    return vF;
}

void Point2DRegion2D::exploreTopoPred() {
    //TODO Object should be derived by each of the types
    PlaneSweep S(objF,objG);
    S.newSweep();


    while((S.getStatus() == ParallelObjectTraversal::end_of_none) && (!(vF[poi_inside]))&&(vF[poi_on_bound])&&(vF[poi_outside]))
    {
        ParallelObjectTraversal::object object_value = S.getObject();
        if(object_value==ParallelObjectTraversal::first)
        {
            Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first);

            if(S.poiInSeg(p))
            {
                vF[poi_on_bound]= true;
            }
            else
            {

                Seg2D s= S.predOfP(p);
                Seg2D s1;
                if (s != s1)
                {
                    //check whether interior of G is above the segment
                    bool ia = S.getInsideAbove(s);

                    if(ia)
                    {
                        vF[poi_inside]= true;
                    }
                    else
                    {
                        vF[poi_outside]= true;
                    }
                }
                else
                {
                    vF[poi_outside]= true;
                }

            }
        }

        else
        {   //object not equal to first

            ParallelObjectTraversal::object object_value = S.getObject();


            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            bool ia = S.getInsideAbove(h.hseg.seg);

            if(h.hseg.isLeft) {

                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.addLeft(psso);
                S.setInsideAbove(h.hseg.seg,ia);
            }
            else
            {
                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.delRight(psso);
            }
            if(object_value==ParallelObjectTraversal::both)
            {
                vF[poi_on_bound]= true;
            }

        }
        S.selectNext();
    }
    if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[poi_outside]=true;
    }
    return;

}
void Point2DRegion2D::evaluateTopoPred() {
    // Dtj. Dec 16.
    // matrix index 2,0 2,1 and 2,2 always true
    // Since the second row of the IMC 3x3 matrix is never evaluated,
    // here we only use six array member to represent the first row and third row of the 3x3 Matrix.
    imctype IMC = imctype (std::string("000111"));


    if(vF[poi_inside])
        IMC.set(5); // setting only one bit of a time: (100000);

    if(vF[poi_on_bound])
        IMC.set(4);  // (001000);

    if(vF[poi_outside])
        IMC.set(3);  // (000100);

    // IMC.set(0), IMC.set(1), IMC.set(2)  : always true and have been set in initialization

    // compare/match the right one
    // loop exit if the top Pred number found
    for (int i = 0; i < TopPredNumberPoint2DRegion2DEnumSize && !isPredSet; i++) {

        //test
        // cout << "matrix[" << i << "] = " << matrix[i] << endl;

        // Dtj. we do bitwise comparison for faster execution:
        if (IMC == matrix[i]) {isPredSet = true; topPredNumberPoint2DRegion2D = (TopPredNumberPoint2DRegion2D) i;}
    }

    // test
    // if (!isPredSet)
    // cout << "WARNING: isPredSet = " << isPredSet << endl;




}

TopPredNumberPoint2DRegion2D  Point2DRegion2D::getTopologicalRelationship()
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberPoint2DRegion2D;
}

bool Point2DRegion2D::isTopologicalRelationship(TopPredNumberPoint2DRegion2D  predicate)
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DRegion2D==predicate)
    {
        return true;
    }
    return false;
}
bool Point2DRegion2D::overlap()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if( topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D::pr_overlap_m5||topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D::pr_overlap_m7)
    {
        return true;
    }
    return false;
}

bool Point2DRegion2D::meet()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D::pr_meet_m2||topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D::pr_meet_m3)
    {
        return true;
    }

    return false;
}

bool Point2DRegion2D::inside()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D:: pr_inside_m4||topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D:: pr_inside_m6)
    {
        return true;
    }
    return false;
}

bool Point2DRegion2D::disjoint()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberPoint2DRegion2D ==TopPredNumberPoint2DRegion2D:: pr_disjoint_m1)
    {
        return true;
    }
    return false;
}

bool Point2DRegion2D::contains()
{
    return false;
}

bool Point2DRegion2D::coveredBy()
{
    return false;
}

bool Point2DRegion2D::covers()
{
    return false;
}

bool Point2DRegion2D::equal()
{
    return false;
}
