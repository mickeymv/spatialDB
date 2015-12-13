/******************************************************************************
* File: Region2DRegion2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between two Region2D object.This also contains
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

#include "Region2DRegion2D.h"



Region2DRegion2D::Region2DRegion2D(const Region2D &F, const Region2D &G) {
    // set obj1 and obj2
    objF = F;
    objG = G;

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for(int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

};

Region2DRegion2D::~Region2DRegion2D() { };


bool *Region2DRegion2D::getVF() {
    return vF;
}

bool *Region2DRegion2D::getVG()
{
    return vG;
}

void Region2DRegion2D::exploreTopoPred()
{
    PlaneSweep S(objF,objG);
    S.newSweep();

    Poi2D last_dp_in_F, last_dp_in_G;

    while((S.getStatus()==ParallelObjectTraversal::end_of_none)&&(!(vF[zero_one]&&vF[one_zero]&&vF[one_two]&&vF[two_one]&&vF[zero_two]&&vF[two_zero]&&vF[one_one]&&vF[bound_poi_shared]&&vG[zero_one_g]&&vG[one_zero_g]&&vG[one_two_g]&&vG[two_one_g])))
    {

        AttrHalfSeg2D h;
        if(S.getObject()==ParallelObjectTraversal::first)
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            if(h.isLeft)
            {
                last_dp_in_F = h.seg.p1;
            }
            else
            {
                last_dp_in_F = h.seg.p2;
            }
        }
        else if(S.getObject()==ParallelObjectTraversal::second)
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            if(h.isLeft)
            {
                last_dp_in_G = h.seg.p1;
            }
            else
            {
                last_dp_in_G = h.seg.p2;
            }
        }
        else // object = both
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            if(h.isLeft)
            {
                last_dp_in_F = h.seg.p1;
                last_dp_in_G = h.seg.p1;
            }
            else
            {
                last_dp_in_F = h.seg.p2;
                last_dp_in_G = h.seg.p2;
            }

        }

        if((last_dp_in_F==last_dp_in_G)||(last_dp_in_F==S.lookAhead(h,objG))||(last_dp_in_G==S.lookAhead(h,objF)))
        {
            vF[bound_poi_shared]=1;
        }

        if(!h.isLeft) // h is a right half segment
        {
            SegmentClass overlapNumber = S.getSegClass(h.seg);
            if(S.getObject()==ParallelObjectTraversal::first)
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[zero_one]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[one_zero]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[one_two]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[two_one]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[zero_two]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[two_zero]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[one_one]=1;
                }
            }
            else if(S.getObject()==ParallelObjectTraversal::second)
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vG[zero_one_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vG[one_zero_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vG[one_two_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vG[two_one_g]=1;
                }
            }
            else // object = both
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[zero_one]=1;
                    vG[zero_one_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[one_zero]=1;
                    vG[one_zero_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[one_two]=1;
                    vG[one_two_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[two_one]=1;
                    vG[two_one_g]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[zero_two]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[two_zero]=1;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[one_one]=1;
                }
            }
            S.delRight(h.seg);
        }
        else // h is a left segment
        {
            S.addLeft(h.seg);
            if(S.coincident(h.seg))
            {
                S.setObject(ParallelObjectTraversal::both); // TODO use setObject of Plane Sweep
            }
            int upperP;
            int lowerP;
            int upperS;
            int lowerS;
            if(!S.predExists(h.seg))
            {
                upperP = -1; // undefined and doesn't matter
                lowerP = 0;
            }
            else // Predecessor exists
            {
             SegmentClass pred = S.getPredSegmentClass(h.seg);
                upperP = pred.getUpperOrLeft();
                lowerP = pred.getLowerOrRight();
            }
            upperS = lowerP;
            lowerS = lowerP;

            if((S.getObject()==ParallelObjectTraversal::first)||(S.getObject()==ParallelObjectTraversal::both))
            {
                if(S.getInsideAbove(h.seg)) // TODO Should we pass object F here??
                {
                    upperS=upperS+1;
                }
                else
                {
                    upperS= upperS-1;
                }
            }

            if((S.getObject()==ParallelObjectTraversal::second)||(S.getObject()==ParallelObjectTraversal::both))
            {
                if(S.getInsideAbove(h.seg)) // TODO Should we pass object G here??
                {
                    upperS=upperS+1;
                }
                else
                {
                    upperS= upperS-1;
                }
            }
            S.setSegClass(h.seg,lowerS,upperS);

        }

        S.selectNext();
    }

    if(S.getStatus()==ParallelObjectTraversal::end_of_first)
    {
        vG[zero_one_g]=1;
        vG[one_zero_g]=1;
    }
    else if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[zero_one]=1;
        vF[one_zero]=1;
    }
}