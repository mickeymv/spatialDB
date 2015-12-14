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
                            SegmentClass overlapNumber = S.getPredSegmentClass(h.seg);
                            if(overlapNumber.getLowerOrRight()==1)
                            {
                                vF[bound_inside]=true;
                            }
                            else
                            {
                             vF[bound_outside]=true;
                            }
                        }
                        else {
                            vF[bound_outside] = true;
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
            bool ia = h.insideAbove;

            Poi2D dp;
            if (h.hseg.isLeft) {
                S.addLeft(h.hseg.seg);
                S.setInsideAbove(h.hseg.seg,ia);
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
            AttrHalfSeg2D h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
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
                if (S.lookAhead(h.hseg, objF))  // line 55
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
    int IMC[3][3];

    for(int i=0; i<3; i++) {
        for (int j = 0; j < 3; j++) {
            IMC[i][j] = 0;
        }
    }

    if(vF[seg_inside]) {
        IMC[0][0] = 1;
    }
    if(vF[seg_shared] || vF[poi_shared]) {
        IMC[0][1] = 1;
    }
    if(vF[seg_outside]) {
        IMC[0][2] = 1;
    }
    if(vF[bound_inside]) {
        IMC[1][0] = 1;
    }
    if(vF[bound_shared]) {
        IMC[1][1] = 1;
    }
    if(vF[bound_disjoint]) {
        IMC[1][2] = 1;
    }
    IMC[2][1] = 1;
    if(vG[seg_unshared]) {
        IMC[2][1] = 1;
    }
    IMC[2][2] = 1;


    if(IMC[1][0]) {
        if(IMC[0][1]) {
            if(IMC[0][2]) {
                if(IMC[1][1]) {
                    if(IMC[0][2]) {
                        // 43
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m43;
                        isPredSet=true;
                    }
                    else {
                        // 42
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m42;
                        isPredSet=true;
                    }
                }
                else {
                    if(IMC[0][2]) {
                        if(IMC[2][1]) {
                            // 41
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m41;
                            isPredSet=true;
                        }
                        else {
                            // 40
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m40;
                            isPredSet=true;
                        }
                    }
                    else {
                        if(IMC[2][1]) {
                            // 39
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m39;
                            isPredSet=true;
                        }
                        else {
                            // 38
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m38;
                            isPredSet=true;
                        }
                    }
                }
            }
            else {
                if(IMC[1][1]) {
                    // 31
                    topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_coveredby_m31;
                    isPredSet=true;
                }
                else {
                    if(IMC[2][1]) {
                        // 30
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m30;
                        isPredSet=true;
                    }
                    else {
                        // 29
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m29;
                        isPredSet=true;
                    }
                }
            }
        }
        else {
            if(IMC[0][2]) {
                if(IMC[1][1]) {
                    if(IMC[0][2]) {
                        // 25
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m25;
                        isPredSet=true;
                    }
                    else {
                        //24
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m24;
                        isPredSet=true;
                    }
                }
                else {
                    if(IMC[0][2]) {
                        // 23
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m23;
                        isPredSet=true;
                    }
                    else {
                        // 22
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m22;
                        isPredSet=true;
                    }
                }
            }
            else {
                if(IMC[1][1]) {
                    // 17
                    topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_coveredby_m17;
                    isPredSet=true;
                }
                else {
                    // 16
                    topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m16;
                    isPredSet=true;
                }
            }
        }
    }
    else {
        if(IMC[0][0]) {
            if(IMC[0][1]) {
                if(IMC[0][2]) {
                    if(IMC[1][1]) {
                        if(IMC[0][2]) {
                            // 37
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m37;
                            isPredSet=true;
                        }
                        else {
                            // 36
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m36;
                            isPredSet=true;
                        }
                    }
                    else {
                        if(IMC[0][2]) {
                            if(IMC[2][1]) {
                                // 35
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m35;
                                isPredSet=true;
                            }
                            else {
                                //34
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m34;
                                isPredSet=true;
                            }
                        }
                        else {
                            if(IMC[2][1]) {
                                // 33
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m33;
                                isPredSet=true;
                            }
                            else {
                                // 32
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m32;
                                isPredSet=true;
                            }
                        }
                    }
                }
                else {
                    if(IMC[1][1]) {
                        // 28
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_coveredby_m28;
                        isPredSet=true;
                    }
                    else {
                        if(IMC[2][1]) {
                            // 27
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m27;
                            isPredSet=true;
                        }
                        else {
                            // 26
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m26;
                            isPredSet=true;
                        }
                    }
                }
            }
            else {
                if(IMC[0][2]) {
                    if(IMC[1][1]) {
                        if(IMC[0][2]) {
                            // 21
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m21;
                            isPredSet=true;
                        }
                        else {
                            // 20
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m20;
                            isPredSet=true;
                        }
                    }
                    else {
                        if(IMC[0][2]) {
                            // 19
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m19;
                            isPredSet=true;
                        }
                        else {
                            // 18
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_overlap_m18;
                            isPredSet=true;
                        }
                    }
                }
                else {
                    if(IMC[1][1]) {
                        // 15
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_coveredby_m15;
                        isPredSet=true;
                    }
                    else {
                        // 14
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_inside_m14;
                        isPredSet=true;
                    }
                }

            }
        }
        else {
            if(IMC[1][1]) {
                if(IMC[0][1]) {
                    if(IMC[0][2]) {
                        if(IMC[0][2]) {
                            // 13
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m13;
                            isPredSet=true;
                        }
                        else {
                            //12
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m12;
                            isPredSet=true;
                        }
                    }
                    else {
                        // 7
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m7;
                        isPredSet=true;
                    }
                }
                else {
                    if(IMC[0][2]) {
                        // 4
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m4;
                        isPredSet=true;
                    }
                    else {
                        //3
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m3;
                        isPredSet=true;
                    }
                }
            }
            else {
                if(IMC[0][2]) {
                    if(IMC[0][1]) {
                        if(IMC[2][1]) {
                            // 11
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m11;
                            isPredSet=true;
                        }
                        else {
                            // 10
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m10;
                            isPredSet=true;
                        }
                    }
                    else {
                        // 2
                        topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_disjoint_m2;
                        isPredSet=true;
                    }
                }
                else {
                    if(IMC[0][2]) {
                        if(IMC[0][1]) {
                            if(IMC[2][1]) {
                                // 9
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m9;
                                isPredSet=true;
                            }
                            else {
                                // 8
                                topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m8;
                                isPredSet=true;
                            }
                        }
                        else {
                            // 1
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_disjoint_m1;
                            isPredSet=true;
                        }
                    }
                    else {
                        if(IMC[2][1]) {
                            // 6
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m6;
                            isPredSet=true;
                        }
                        else {
                            // 5
                            topPredNumberLine2DRegion2D = TopPredNumberLine2DRegion2D::lr_meet_m5;
                            isPredSet=true;
                        }
                    }
                }
            }
        }
    }


}

bool Line2DRegion2D::isTopologicalRelationship(TopPredNumberLine2DRegion2D predicate) {
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
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
