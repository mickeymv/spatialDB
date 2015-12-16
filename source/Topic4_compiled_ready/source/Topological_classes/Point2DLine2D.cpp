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

    //cout<<"Inside explore\n";
    PlaneSweep S(objF,objG);
    //cout<<"After object creation\n";
    S.newSweep();
    //cout<<"After new Sweep\n";
    Poi2D last_dp;

    //int count=0;
    while((S.getStatus()!=ParallelObjectTraversal::end_of_second)&&(S.getStatus()==ParallelObjectTraversal::end_of_none)&&(!(vF[poi_disjoint]&&vF[poi_on_interior]&&vF[poi_on_bound]&&vG[bound_poi_disjoint])))
    {
        //cout<<endl;
        //cout<<"In while loop"<<count++<<endl;
        ParallelObjectTraversal::object object_value = S.getObject();
        if(object_value==ParallelObjectTraversal::first)
        {
            //cout<<"In object_value in first\n";
            Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first);
            //cout<<p<<endl;
            //cout<<"After getPoiEvent\n";
            if(S.poiInSeg(p))//poi_inSeg
            {
                vF[poi_on_interior]= true;
               // cout<<"vF[poi_on_interior] set in poiInSeg\n";
            }
            else
            {
                vF[poi_disjoint]=true;
                //cout<<"After poiOnSeg\n";
               // cout<<"vF[poi_disjoint] set in poiInSeg\n";
            }
        }
        else if(object_value==ParallelObjectTraversal::second)
        {
           // cout<<"In object_value in second\n";
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            //cout<<"After getHalfSegEvent\n";
            Poi2D dp;
            if(h.isLeft)
            {
                PlaneSweepLineStatusObject psso(h.seg);
                S.addLeft(psso);
                //cout<<"After addLeft\n";
                dp=h.seg.p1;
            }
            else
            {
                PlaneSweepLineStatusObject psso(h.seg);
                S.delRight(psso);
                //cout<<"After delRight\n";
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
            //cout<<"In object_value in both\n";
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            //cout<<"After getHalfSegEvent\n";
            Poi2D dp;
            if(h.isLeft)
            {
                PlaneSweepLineStatusObject psso(h.seg);
                S.addLeft(psso);
                //cout<<"After addLeft\n";
                dp=h.seg.p1;
            }
            else
            {
                PlaneSweepLineStatusObject psso(h.seg);
                S.delRight(psso);
                //cout<<"After delRight\n";
                dp=h.seg.p2;
            }
            last_dp=dp;
            if(S.lookAhead(h,ParallelObjectTraversal::second))
            {
                vF[poi_on_interior]=true;
                //cout<<"After lookAhead\n";
                //cout<<"vF[poi_on_interior] set in lookAhead\n";
            }
            else
            {
                vF[poi_on_bound]=true;
                //cout<<"After lookAhead\n";
            }
        }
        S.selectNext();
        //cout<<endl;
        //cout<<"After selectNext\n";
    }
    if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[poi_disjoint]=true;
        //cout<<"End of second\n";
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
