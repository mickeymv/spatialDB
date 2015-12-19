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

Line2DRegion2D::Line2DRegion2D(const Line2D &F, const Region2D &G) {
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

    // assigning the the matrix value to bitset
    for (int i = 0; i < TopPredNumberLine2DRegion2DEnumSize; i++)
        matrix[i] = imctype(std::string(matrixStr[i]));

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
                PlaneSweepLineStatusObject psso(h.seg);
                S.addLeft(psso);
                dp = h.seg.p1;
            }
            else {
                if (S.predExists(h.seg)) {
                    // (mp/np):=get_pred_attr(S,s);
                    // if np = 1 then vF[seg_inside] = true
                    // else vF[seg_outside] = true
                    SegmentClass overlapNumber = S.getPredSegmentClass(h.seg);
                    if(overlapNumber.getLowerOrRight()==1)
                    {
                        vF[seg_inside]=true;
                    }
                    else {
                        vF[seg_outside] = true;
                    }
                }
                else {
                    vF[seg_outside] = true;
                }
                PlaneSweepLineStatusObject psso(h.seg);
                S.delRight(psso);
            }
            if (dp != last_dp_in_F) {
                last_dp_in_F = dp;
                if (!S.lookAhead(h, ParallelObjectTraversal::first)) {
                    last_bound_in_F = dp;
                    if (last_bound_in_F == last_dp_in_G || S.lookAhead(h, ParallelObjectTraversal::second)) {
                        vF[bound_shared] = true;
                    }
                    else {
                        if (S.predExists(h.seg)) {
                            //(mp/np):=get_pred_attr(S,s);
                            // if np = 1 then vF[bound_inside] = true
                            // else vF[bound_outside] = true
                            SegmentClass overlapNumber = S.getPredSegmentClass(h.seg);
                            if(overlapNumber.getLowerOrRight()==1)
                            {
                                vF[bound_inside]=true;
                            }
                            else
                            {
                                //TODO - find out about bound_outside
                                //vF[bound_outside]=true;
                            }
                        }
                        else {
                            //vF[bound_outside] = true;
                        }

                    }

                }
            } // line 39
            if ((dp != last_bound_in_F && dp == last_dp_in_G) || S.lookAhead(h, ParallelObjectTraversal::second)) {
                vF[poi_shared] = true;
            }
        }
        else if (object_value == ParallelObjectTraversal::second) // line 44
        {
            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            bool ia = h.insideAbove;

            Poi2D dp;
            if (h.hseg.isLeft) {
                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.addLeft(psso);
                S.setInsideAbove(h.hseg.seg,ia);
                dp = h.hseg.seg.p1;
            }
            else {
                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.delRight(psso);
                vG[seg_unshared] = true;
            }
            if (dp != last_dp_in_G) {
                last_dp_in_G = dp;
            }
        } // line 49
        else {
            vF[seg_shared] = true;
            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if (h.hseg.isLeft) {
                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.addLeft(psso);
                dp = h.hseg.seg.p1;
            }
            else {
                PlaneSweepLineStatusObject psso(h.hseg.seg);
                S.delRight(psso);
            } // line 53
            if (dp != last_dp_in_F) {
                last_dp_in_F = dp;
                if (S.lookAhead(h.hseg, ParallelObjectTraversal::first))  // line 55
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

    // Dtj. Dec 16.
    // matrix index 2,0 and 2,2 always true
    imctype IMC = imctype(std::string("000000101"));  // matrix 2,0 and 2:2 always true

    if(vF[seg_inside])
        IMC.set(8) = 1; // (100000000)

    if(vF[seg_shared] || vF[poi_shared])
        IMC.set(7) = 1; // (100000000)

    if(vF[seg_outside])
        IMC.set(6) = 1; // (010000000)

    if(vF[bound_inside])
        IMC.set(5) = 1; // (001000000)

    if(vF[bound_shared])
        IMC.set(4) = 1; // (000100000

    if(vF[bound_disjoint])
        IMC.set(3) = 1; // (000001000)

    if(vG[seg_unshared]) {
        IMC.set(1) = 1; // (000000010)

        // compare/match the right one
        // loop exit if the top Pred number found
        for (int i = 0; i < TopPredNumberLine2DRegion2DEnumSize && !isPredSet; i++) {

            //test
            // cout << "matrix[" << i << "] = " << matrix[i] << endl;

            // Dtj. we do bitwise comparison for faster execution:
            if (IMC == matrix[i]) {isPredSet = true; topPredNumberLine2DRegion2D = (TopPredNumberLine2DRegion2D) i;}
        }

        // test
        // if (!isPredSet)
        // cout << "WARNING: isPredSet = " << isPredSet << endl;

    }

}

bool Line2DRegion2D::isTopologicalRelationship(TopPredNumberLine2DRegion2D predicate) {
    if(!isPredSet)
    {
        exploreTopoPred();
//        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D==predicate)
    {
        return true;
    }
    return false;
}

TopPredNumberLine2DRegion2D Line2DRegion2D::getTopologicalRelationship() {
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberLine2DRegion2D;

}

bool Line2DRegion2D::overlap() {

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m18 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m19 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m43 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m42 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m41|| topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m40 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m39 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m38 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m37 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m36 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m35 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m34 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m33 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m32 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m25 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m24 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m23 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m22 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m21 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_overlap_m20) {
        return true;
    }

    return false;
}

bool Line2DRegion2D::disjoint() {

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_disjoint_m1 || topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_disjoint_m2) {
        return true;
    }

    return false;
}

bool Line2DRegion2D::meet() {

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m3||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m4||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m5||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m6||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m7||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m8||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m9||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m10||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m11||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m12||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_meet_m13) {
        return true;
    }
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
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_coveredby_m15||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_coveredby_m17||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_coveredby_m28||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_coveredby_m31) {
        return true;
    }
    return false;
}

bool Line2DRegion2D::inside() {
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m14||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m16||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m26||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m27||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m29||topPredNumberLine2DRegion2D == TopPredNumberLine2DRegion2D::lr_inside_m30) {
        return true;
    }
    return false;
}