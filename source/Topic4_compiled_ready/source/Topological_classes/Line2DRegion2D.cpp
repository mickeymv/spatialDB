/******************************************************************************
* File: Line2DRegion2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between a Line2D and a Region2D object.This also contains
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

#include "Line2DRegion2D.h"

Line2DRegion2D::Line2DRegion2D(const Line2D &F,const Region2D &G) {
    // set obj1 and obj2
    objF = F;
    objG = G;

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

};

Line2DRegion2D::~Line2DRegion2D() { };


bool *Line2DRegion2D::getVF() {
    return vF;
}

bool *Line2DRegion2D::getVG() {
    return vG;
}

void Line2DRegion2D::exploreTopoPred() {
    PlaneSweep S(objF,objG);
    S.newSweep();
    Poi2D last_dp_in_F, last_dp_in_G, last_bound_in_F;

    while((S.getStatus()!=ParallelObjectTraversal::end_of_second)&&(S.getStatus()!=ParallelObjectTraversal::end_of_both)
          &&(!(vF[seg_inside]&&vF[seg_shared]&&vF[seg_outside]&&vF[poi_shared]&&vF[bound_inside]&&vF[bound_shared]&&vG[bound_disjoint]&&vG[seg_unshared]))) {
        ParallelObjectTraversal::object object_value = S.getObject();
        if (object_value == ParallelObjectTraversal::first) {
            //Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first); // 하프세그먼트 옴
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::first);
            Poi2D dp;
            if (h.isLeft) {
                S.addLeft(h.seg);
                dp = h.seg.p1;
            }
            else {
                if (S.predExists(h.seg)) {
                    // (mp/np):=get_pred_attr(S,s);
                    // if np = 1 then vF[seg_inside] = true
                    // else vF[seg_outside] = true
                }
                else {
                    vF[seg_outside] = true;
                }
                S.delRight(h.seg);
            }
            if (dp != last_dp_in_F) {
                last_dp_in_F = dp;
                if (!S.lookAhead(h, objF)) {
                    last_bound_in_F = dp;
                    if (last_bound_in_F == last_dp_in_G || S.lookAhead(h, objG)) {
                        vF[bound_shared] = true;
                    }
                    else {
                        if (S.predExists(h.seg)) {
                            //(mp/np):=get_pred_attr(S,s);
                            // if np = 1 then vF[bound_inside] = true
                            // else vF[bound_outside] = true
                        }
                        else { // if np = 1
                            vF[bound_inside] = true;
                        }

                    }

                }
            } // line 39
            if (dp != last_bound_in_F && dp == last_dp_in_G || S.lookAhead(h.seg, objG)) {
                vF[poi_shared] = true;
            }
        }
        else if (object_value == ParallelObjectTraversal::second) // line 44
        {
            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if (h.hseg.isLeft) {
                S.addLeft(h.hseg.seg);
                dp = h.hseg.seg.p1;
            }
            else {
                S.delRight(h.hseg.seg);
                vG[seg_unshared] = true;
            }
            if (dp != last_dp_in_G) {
                last_dp_in_G = dp;
            }
        } // line 49
        else {
            vF[seg_shared] = true;
            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second); // I saw this in the paper (Natasha)
            Poi2D dp;
            if (h.hseg.isLeft) {
                S.addLeft(h.hseg.seg);
                dp = h.hseg.seg.p1;
            }
            else {
                S.delRight(h.hseg.seg);
            } // line 53
            if (dp != last_dp_in_F) {
                last_dp_in_F = dp;
                if (S.lookAhead(h.hseg.seg, objF))  // line 55
                {
                    vF[bound_shared] = true;
                }
                else {
                    vF[poi_shared] = true;
                }
            }
            if (dp != last_dp_in_G) {
                last_dp_in_G = dp;
            }
        }
        if (S.getStatus() == ParallelObjectTraversal::end_of_second) {
            vF[seg_outside] = true;
        }
        S.selectNext();
    }
    if(S.getStatus() == ParallelObjectTraversal::end_of_first) {
        vG[seg_unshared] = true;
    }

    return; // return true if no error, else false
}

void Line2DRegion2D::evaluateTopoPred() {

}

bool Line2DRegion2D::isTopologicalRelationship(TopPredNumberLine2DRegion2D predicate) {
    return false;
}

TopPredNumberLine2DRegion2D Line2DRegion2D::getTopologicalRelationship() {
    return TopPredNumberLine2DRegion2D:: lr_overlap_m34;
}

bool Line2DRegion2D::overlap() {
    return false;
}

bool Line2DRegion2D::disjoint() {
    return false;
}

bool Line2DRegion2D::meet() {
    return false;
}

bool Line2DRegion2D::equal() {
    return false;
}

bool Line2DRegion2D::contains() {
    return false;
}

bool Line2DRegion2D::covers() {
    return false;
}

bool Line2DRegion2D::coveredBy() {
    return false;
}

bool Line2DRegion2D::inside() {
    return false;
}
