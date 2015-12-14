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
            if(h.hseg.isLeft)
            {
                last_dp_in_F = h.hseg.seg.p1;
            }
            else
            {
                last_dp_in_F = h.hseg.seg.p2;
            }
        }
        else if(S.getObject()==ParallelObjectTraversal::second)
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            if(h.hseg.isLeft)
            {
                last_dp_in_G = h.hseg.seg.p1;
            }
            else
            {
                last_dp_in_G = h.hseg.seg.p2;
            }
        }
        else // object = both
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            if(h.hseg.isLeft)
            {
                last_dp_in_F = h.hseg.seg.p1;
                last_dp_in_G = h.hseg.seg.p1;
            }
            else
            {
                last_dp_in_F = h.hseg.seg.p2;
                last_dp_in_G = h.hseg.seg.p2;
            }

        }

        if((last_dp_in_F==last_dp_in_G)||(last_dp_in_F==S.lookAhead(h,objG))||(last_dp_in_G==S.lookAhead(h,objF)))
        {
            vF[bound_poi_shared]=true;
        }

        if(!h.hseg.isLeft) // h is a right half segment
        {
            SegmentClass overlapNumber = S.getSegClass(h.hseg.seg);
            if(S.getObject()==ParallelObjectTraversal::first)
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[zero_one]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[one_zero]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[one_two]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[two_one]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[zero_two]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[two_zero]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[one_one]=true;
                }
            }
            else if(S.getObject()==ParallelObjectTraversal::second)
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vG[zero_one_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vG[one_zero_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vG[one_two_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vG[two_one_g]=true;
                }
            }
            else // object = both
            {
                if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[zero_one]=true;
                    vG[zero_one_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[one_zero]=true;
                    vG[one_zero_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[one_two]=true;
                    vG[one_two_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[two_one]=true;
                    vG[two_one_g]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==0)&&(overlapNumber.getLowerOrRight()==2))
                {
                    vF[zero_two]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==2)&&(overlapNumber.getLowerOrRight()==0))
                {
                    vF[two_zero]=true;
                }
                else if((overlapNumber.getUpperOrLeft()==1)&&(overlapNumber.getLowerOrRight()==1))
                {
                    vF[one_one]=true;
                }
            }
            S.delRight(h.hseg.seg);
        }
        else // h is a left segment
        {
            S.addLeft(h.hseg.seg);
            if(S.coincident(h.hseg.seg))
            {
                S.setObject(ParallelObjectTraversal::both);
            }
            int upperP;
            int lowerP;
            int upperS;
            int lowerS;
            if(!S.predExists(h.hseg.seg))
            {
                upperP = -1; // undefined and doesn't matter
                lowerP = 0;
            }
            else // Predecessor exists
            {
             SegmentClass pred = S.getPredSegmentClass(h.hseg.seg);
                upperP = pred.getUpperOrLeft();
                lowerP = pred.getLowerOrRight();
            }
            upperS = lowerP;
            lowerS = lowerP;

            if((S.getObject()==ParallelObjectTraversal::first)||(S.getObject()==ParallelObjectTraversal::both))
            {

                if(h.insideAbove) // TODO Should we pass object F here??
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
                if(h.insideAbove) // TODO Should we pass object G here??
                {
                    upperS=upperS+1;
                }
                else
                {
                    upperS= upperS-1;
                }
            }
            S.setSegClass(h.hseg.seg,lowerS,upperS);

        }

        S.selectNext();
    }

    if(S.getStatus()==ParallelObjectTraversal::end_of_first)
    {
        vG[zero_one_g]=true;
        vG[one_zero_g]=true;
    }
    else if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[zero_one]=true;
        vF[one_zero]=true;
    }
}

void Region2DRegion2D::evaluateTopoPred()
{
    int IMC[3][3];


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            IMC[i][j] = 0;
        }
    }

    if(vF[zero_one]||vF[one_zero])
    {
        IMC[1][2]=1;
    }
    if(vG[zero_one_g]||vG[one_zero_g])
    {
        IMC[2][1]=1;
    }
    if(vF[one_two]||vF[two_one])
    {
        IMC[1][0]=1;
    }
    if(vG[one_two_g]||vG[two_one_g])
    {
        IMC[0][1]=1;
    }
    if(vF[zero_two]||vF[two_zero])
    {
        IMC[1][1]=1;
        IMC[0][0]=1;
    }
    if(vF[one_one])
    {
        IMC[1][1]=1;
        IMC[0][2]=1;
        IMC[2][0]=1;
    }

}