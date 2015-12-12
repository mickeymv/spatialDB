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
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

};

Point2DLine2D::~Point2DLine2D() { };


bool *Point2DLine2D::getVF() {
    return vF;
}

bool *Point2DLine2D::getVG() {
    return vG;
}

void Point2DLine2D::exploreTopoPred() {

    //TODO Object should be derived by each of the types
    PlaneSweep S(objF,objG);
    S.newSweep();
    Poi2D last_dp;

    while((S.getStatus()!=ParallelObjectTraversal::end_of_second)&&(S.getStatus()!=ParallelObjectTraversal::end_of_both)&&(!(vF[poi_disjoint]&&vF[poi_on_interior]&&vF[poi_on_bound]&&vG[bound_poi_disjoint])))
    {
        ParallelObjectTraversal::object object_value = S.getObject();
        if(object_value==ParallelObjectTraversal::first)
        {
            Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first);
            if(S.poiInSeg(p))
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
                S.addLeft(h.seg);
                dp=h.seg.p1;
            }
            else
            {
                S.delRight(h.seg);
                dp=h.seg.p2;
            }
            if(dp!=last_dp)
            {
                last_dp=dp;
            }
            if(!S.lookAhead(h,objG))
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
                S.addLeft(h.seg);
                dp=h.seg.p1;
            }
            else
            {
                S.delRight(h.seg);
                dp=h.seg.p2;
            }
            last_dp=dp;
            if(S.lookAhead(h,objG))
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
    return; // return true if no error, else false
}

void Point2DLine2D::evaluateTopoPred()
{
    int IMC[3][3];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            IMC[i][j]=0;
        }
    }

    if(vF[poi_on_interior])
    {
        IMC[0][0]=1;
    }
    if(vF[poi_on_bound])
    {
        IMC[0][1]=1;
    }
    if(vF[poi_disjoint])
    {
        IMC[0][2]=1;
    }
    IMC[2][0]=1;
    if(vG[bound_poi_disjoint])
    {
        IMC[2][1]=1;
    }
    IMC[2][2]=1;

    if(IMC[0][0])
    {
        if(IMC[0][1])
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D:: pl_overlap_m14;
                    isPredSet=true;

                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D:: pl_overlap_m13;
                    isPredSet=true;
                }
            }
            else
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D:: pl_inside_m12;
                    isPredSet=true;

                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_inside_m11;
                    isPredSet=true;
                }

            }

        }
        else
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_overlap_m10;
                    isPredSet=true;
                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_overlap_m9;
                    isPredSet=true;
                }
            }
            else
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_inside_m8;
                    isPredSet=true;

                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_inside_m7;
                    isPredSet=true;
                }

            }

        }

    }
    else
    {
        if(IMC[0][1])
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_meet_m6;
                    isPredSet=true;

                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_meet_m5;
                    isPredSet=true;
                }

            }
            else
            {
                if(IMC[2][1])
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_meet_m4;
                    isPredSet=true;

                }
                else
                {
                    topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_meet_m3;
                    isPredSet=true;
                }

            }
        }
        else
        {
            if(IMC[2][1])
            {
                topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_disjoint_m2;
                isPredSet=true;

            }
            else
            {
                topPredNumberPoint2DLine2D = TopPredNumberPoint2DLine2D::pl_disjoint_m1;
                isPredSet=true;
            }
        }
    }
    return;
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