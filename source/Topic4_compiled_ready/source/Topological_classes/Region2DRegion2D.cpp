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
    for (int i = 0; i < vF_size; i++) {
        vF[i] = false;
    }

    for (int i = 0; i < vG_size; i++) {
        vG[i] = false;
    }

    // assigning the the matrix value to bitset
    for (int i = 0; i < matrixSize; i++)
        matrix[i] = imctype(std::string(matrixStr[i]));
};

Region2DRegion2D::~Region2DRegion2D() { };


bool *Region2DRegion2D::getVF() {
    return vF;
}

bool *Region2DRegion2D::getVG() {
    return vG;
}

void Region2DRegion2D::exploreTopoPred() {
    PlaneSweep S(objF, objG);
    S.newSweep();
    Poi2D last_dp_in_F, last_dp_in_G;

    while ((S.getStatus() == ParallelObjectTraversal::end_of_none) &&
           (!(vF[zero_one] && vF[one_zero] && vF[one_two] && vF[two_one] && vF[zero_two] && vF[two_zero] &&
              vF[one_one] && vF[bound_poi_shared] && vG[zero_one_g] && vG[one_zero_g] && vG[one_two_g] &&
              vG[two_one_g]))) {
        AttrHalfSeg2D h;
        if (S.getObject() == ParallelObjectTraversal::first) {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            if (h.hseg.isLeft) {
                last_dp_in_F = h.hseg.seg.p1;
            }
            else {
                last_dp_in_F = h.hseg.seg.p2;
            }
        }
        else if (S.getObject() == ParallelObjectTraversal::second) {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::second);
            if (h.hseg.isLeft) {
                last_dp_in_G = h.hseg.seg.p1;
            }
            else {
                last_dp_in_G = h.hseg.seg.p2;
            }
        }
        else // object = both
        {
            h = S.getAttrHalfSegEvent(ParallelObjectTraversal::first);
            if (h.hseg.isLeft) {
                last_dp_in_F = h.hseg.seg.p1;
                last_dp_in_G = h.hseg.seg.p1;
            }
            else {
                last_dp_in_F = h.hseg.seg.p2;
                last_dp_in_G = h.hseg.seg.p2;
            }

        }

        // Doesn't handle the case when the Poi2D(0,0) is used
        if ((last_dp_in_F == last_dp_in_G) || ((S.lookAheadPoi(h, ParallelObjectTraversal::second) != nullptr) &&
                                               (last_dp_in_F ==
                                                *(S.lookAheadPoi(h, ParallelObjectTraversal::second))) &&
                                               (last_dp_in_F != Poi2D(Number("0"), Number("0")))) ||
            ((S.lookAheadPoi(h, ParallelObjectTraversal::first) != nullptr) &&
             (last_dp_in_G == *(S.lookAheadPoi(h, ParallelObjectTraversal::first))) &&
             (last_dp_in_G != Poi2D(Number("0"), Number("0"))))) {
            vF[bound_poi_shared] = true;
        }


        if (!h.hseg.isLeft) // h is a right half segment
        {
            SegmentClass overlapNumber = S.getSegClass(h.hseg.seg);

            if (S.getObject() == ParallelObjectTraversal::first) {
                if ((overlapNumber.getUpperOrLeft() == 0) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[zero_one] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 0)) {
                    vF[one_zero] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 2)) {
                    vF[one_two] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 2) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[two_one] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 0) && (overlapNumber.getLowerOrRight() == 2)) {
                    vF[zero_two] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 2) && (overlapNumber.getLowerOrRight() == 0)) {
                    vF[two_zero] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[one_one] = true;
                }
            }
            else if (S.getObject() == ParallelObjectTraversal::second) {
                if ((overlapNumber.getUpperOrLeft() == 0) && (overlapNumber.getLowerOrRight() == 1)) {
                    vG[zero_one_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 0)) {
                    vG[one_zero_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 2)) {
                    vG[one_two_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 2) && (overlapNumber.getLowerOrRight() == 1)) {
                    vG[two_one_g] = true;
                }
            }
            else // object = both
            {
                if ((overlapNumber.getUpperOrLeft() == 0) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[zero_one] = true;
                    vG[zero_one_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 0)) {
                    vF[one_zero] = true;
                    vG[one_zero_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 2)) {
                    vF[one_two] = true;
                    vG[one_two_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 2) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[two_one] = true;
                    vG[two_one_g] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 0) && (overlapNumber.getLowerOrRight() == 2)) {
                    vF[zero_two] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 2) && (overlapNumber.getLowerOrRight() == 0)) {
                    vF[two_zero] = true;
                }
                else if ((overlapNumber.getUpperOrLeft() == 1) && (overlapNumber.getLowerOrRight() == 1)) {
                    vF[one_one] = true;
                }
            }
            PlaneSweepLineStatusObject psso(h.hseg.seg);
            S.delRight(psso);
        }
        else // h is a left segment
        {
            PlaneSweepLineStatusObject psso(h.hseg.seg);
            S.addLeft(psso);
            if (S.coincident(h.hseg.seg)) {
                S.setObject(ParallelObjectTraversal::both);
            }
            int upperP;
            int lowerP;
            int upperS;
            int lowerS;
            if (!S.predExists(h.hseg.seg)) {
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

            if ((S.getObject() == ParallelObjectTraversal::first) || (S.getObject() == ParallelObjectTraversal::both)) {

                if (h.insideAbove) // TODO Should we pass object F here??
                {
                    upperS = upperS + 1;
                }
                else {
                    upperS = upperS - 1;
                }
            }

            if ((S.getObject() == ParallelObjectTraversal::second) ||
                (S.getObject() == ParallelObjectTraversal::both)) {
                if (h.insideAbove) // TODO Should we pass object G here??
                {
                    upperS = upperS + 1;
                }
                else {
                    upperS = upperS - 1;
                }
            }
            S.setSegClass(h.hseg.seg, lowerS, upperS);
        }

        S.selectNext();
    }

    if (S.getStatus() == ParallelObjectTraversal::end_of_first) {
        vG[zero_one_g] = true;
        vG[one_zero_g] = true;
    }
    else if (S.getStatus() == ParallelObjectTraversal::end_of_second) {
        vF[zero_one] = true;
        vF[one_zero] = true;
    }
}

void Region2DRegion2D::evaluateTopoPred() {


    // Dtj. Dec 16.
    // IMC matrix comparison
    imctype IMC = imctype(std::string("000000001"));  // matrix 2:2 always true


    // populating the ICM with the value of vF and vG
    if (vF[zero_one] || vF[two_zero] || vF[one_two] || vF[two_one] || vG[one_two_g] || vG[two_one_g])
        IMC.set(7) = 1; // (100000000)

    if (vG[one_two_g] || vG[two_one_g])
        IMC.set(6) = 1; // (010000000)

    if (vF[zero_one] || vF[one_zero] || vF[one_one] || vG[one_two_g] || vG[two_one_g])
        IMC.set(5) = 1; // (001000000)

    if (vF[one_two] || vF[two_one])
        IMC.set(4) = 1; // (000100000)

    if (vF[zero_two] || vF[two_zero] || vF[one_one] || vF[bound_poi_shared])
        IMC.set(3) = 1; // (000010000)

    if (vF[zero_one] || vF[one_zero])
        IMC.set(2) = 1; // (000001000)

    if (vF[one_two] || vF[two_one] || vF[one_one] || vG[zero_one_g] || vG[one_zero_g])
        IMC.set(1) = 1; // (000000100)

    if (vG[zero_one_g] || vG[one_zero_g])
        IMC.set(0) = 1; // (000000010)

    // compare/match the right one
    // loop exit if the top Pred number found
    for (int i = 0; i < matrixSize && !isPredSet; i++) {

        //test
        // cout << "matrix[" << i << "] = " << matrix[i] << endl;

        // Dtj. we do bitwise comparison for faster execution:
        if (IMC == matrix[i]) {
            isPredSet = true;
            topPredNumberRegion2DRegion2D = (TopPredNumberRegion2DRegion2D) i;
        }
    }

}

TopPredNumberRegion2DRegion2D Region2DRegion2D::getTopologicalRelationship() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberRegion2DRegion2D;
}


bool Region2DRegion2D::isTopologicalRelationship(TopPredNumberRegion2DRegion2D predicate) {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == predicate) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::disjoint() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_disjoint_m1) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::meet() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_meet_m2 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_meet_m3 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_meet_m4) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::equal() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_equal_m5) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::coveredBy() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_coveredby_m6 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_coveredby_m8 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_coveredby_m9) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::inside() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_inside_m7) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::covers() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_covers_m11 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_covers_m21 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_covers_m24) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::overlap() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m10 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m12 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m13 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m14 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m15 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m16 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m17 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m18 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m20 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m22 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m23 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m25 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m26 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m27 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m28 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m29 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m30 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m31 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m32 ||
        topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_overlap_m33) {
        return true;
    }
    return false;
}

bool Region2DRegion2D::contains() {
    if (!isPredSet) {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if (topPredNumberRegion2DRegion2D == TopPredNumberRegion2DRegion2D::rr_contains_m19) {
        return true;
    }
    return false;
}