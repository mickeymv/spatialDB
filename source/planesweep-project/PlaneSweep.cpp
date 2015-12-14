//
// Created by Djundi on 11/3/15.
//

//test edit


#include "PlaneSweep.h"

PlaneSweep::PlaneSweep(const Object2D &objF, const Object2D &objG) {
    pot = new ParallelObjectTraversal(objF, objG);
    this->objF = objF;
    this->objG = objG;
}

PlaneSweep::~PlaneSweep() {
    delete pot;
}

void PlaneSweep::setSegClass(Seg2D seg, int lOrR, int uOrL) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject> *node =
            sweepLineStatus->FindKey(psso);
    node->key.setSegmentClass(lOrR, uOrL);
}

void PlaneSweep::setInsideAbove(Seg2D seg, bool ia) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject> *node =
            sweepLineStatus->FindKey(psso);
    node->key.setInsideAbove(ia);
}

SegmentClass PlaneSweep::getSegClass(Seg2D seg) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject> *node =
            sweepLineStatus->FindKey(psso);
    SegmentClass sc = node->key.getSegmentClass();
    return sc;
}

bool PlaneSweep::getInsideAbove(Seg2D seg) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject> *node =
            sweepLineStatus->FindKey(psso);
    bool ia = node->key.getInsideAbove();
    return ia;
}

//TODO try to store halfsegments in Minheap
int PlaneSweep::findLeast() {
    //AttrHalfSeg2D objS, objD1, objD2, objD;
    getPot()->setNextMin();

    Poi2D *objSP = nullptr;
    objSP = getPot()->getNextPoi2DMin();

    HalfSeg2D *objHS = nullptr;
    objHS = getPot()->getNextHalfSeg2DMin();

    AttrHalfSeg2D *objAHS = nullptr;
    objAHS = getPot()->getNextAttrHalfSeg2DMin();

    if (objSP != nullptr) {
        if (getPot()->getObjF().isPoint2D() && (*(getPot()->getMinPoi2DF()) == *objSP)) {
            if (getPot()->getObjG().isPoint2D()) {
                return 1;
            }
            else if (getPot()->getObjG().isLine2D()) {
                if (dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
                HalfSeg2D objD2 = dynamicEPSObjG.GetMin().hseg;

                if (*objSP < objD2)
                    return 1;
                return 2;
            }
            else if (getPot()->getObjG().isRegion2D()) {
                if (dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
                AttrHalfSeg2D objD2 = dynamicEPSObjG.GetMin();
                if (*objSP < objD2)
                    return 1;
                return 2;
            }
        }
        else if (getPot()->getObjG().isPoint2D() && (*(getPot()->getMinPoi2DG()) == *objSP)) {
            return 1;
        }
    }
    else if (objHS != nullptr) {

        if (getPot()->getObjF().isLine2D() && (*(getPot()->getMinHalfSeg2DF()) == *objHS)) {
            HalfSeg2D objD1;
            if (!dynamicEPSObjF.isEmpty()) {
                objD1 = dynamicEPSObjF.GetMin().hseg;
            }
            if (getPot()->getObjG().isLine2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    HalfSeg2D objD2 = dynamicEPSObjG.GetMin().hseg;
                    if (objD1 < objD2) {
                        HalfSeg2D objD = objD1;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        HalfSeg2D objD = objD2;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }


            }
            else if (getPot()->getObjG().isRegion2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    AttrHalfSeg2D objD2 = dynamicEPSObjG.GetMin();
                    if (objD1 < objD2) {
                        HalfSeg2D objD = objD1;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        AttrHalfSeg2D objD = objD2;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
            }
        }
        else if (getPot()->getObjG().isLine2D() && (*(getPot()->getMinHalfSeg2DG()) == *objHS)) {
            HalfSeg2D objD1;
            if (!dynamicEPSObjG.isEmpty()) {
                objD1 = dynamicEPSObjG.GetMin().hseg;
            }
            if (getPot()->getObjF().isLine2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    HalfSeg2D objD2 = dynamicEPSObjF.GetMin().hseg;
                    if (objD1 < objD2) {
                        HalfSeg2D objD = objD1;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        HalfSeg2D objD = objD2;
                        if (*objHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }


            }
            else if (getPot()->getObjF().isPoint2D()) {
                if (dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
                else {
                    if (*objHS < objD1)
                        return 1;
                    return 2;
                }
            }

        }
    }
    else if (objAHS != nullptr) {
        if (getPot()->getObjF().isRegion2D() && (*(getPot()->getMinAttrHalfSeg2DF()) == *objAHS)) {
            AttrHalfSeg2D objD1;
            if (!dynamicEPSObjF.isEmpty()) {
                objD1 = dynamicEPSObjF.GetMin();
            }
            if (getPot()->getObjF().isRegion2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    AttrHalfSeg2D objD2 = dynamicEPSObjF.GetMin();
                    if (objD1 < objD2) {
                        AttrHalfSeg2D objD = objD1;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        AttrHalfSeg2D objD = objD2;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
            }
        }
        else if (getPot()->getObjG().isRegion2D() && (*(getPot()->getMinAttrHalfSeg2DG()) == *objAHS)) {
            AttrHalfSeg2D objD1;
            if (!dynamicEPSObjG.isEmpty()) {
                objD1 = dynamicEPSObjG.GetMin();
            }
            if (getPot()->getObjF().isLine2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    HalfSeg2D objD2 = dynamicEPSObjF.GetMin().hseg;
                    if (objD1 < objD2) {
                        AttrHalfSeg2D objD = objD1;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        HalfSeg2D objD = objD2;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }


            }
            else if (getPot()->getObjF().isRegion2D()) {
                if ((!dynamicEPSObjF.isEmpty()) && (!dynamicEPSObjG.isEmpty())) {
                    AttrHalfSeg2D objD2 = dynamicEPSObjF.GetMin();
                    if (objD1 < objD2) {
                        AttrHalfSeg2D objD = objD1;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                    else {
                        AttrHalfSeg2D objD = objD2;
                        if (*objAHS < objD)
                            return 1;
                        return 2;
                    }
                }
                else if (dynamicEPSObjF.isEmpty() && dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
            }
            else if (getPot()->getObjF().isPoint2D()) {
                if (dynamicEPSObjG.isEmpty()) {
                    return 1;
                }
                else {
                    if (*objAHS < objD1)
                        return 1;
                    return 2;
                }
            }

        }
    }

//        objD1 = dynamicEPSObjF.GetMin();
//        objD2 = dynamicEPSObjG.GetMin();
//        objD = (objD1 < objD2) ? (objD1) : (objD2);
//
//        if (objS < objD)
//            return 1;
//        return 2;

}

void PlaneSweep::selectNext() {
    if (findLeast() == 1) {
        getPot()->selectNext();
    }
    else {
        HalfSeg2D objD1H, objD2H;
        AttrHalfSeg2D objD, objD1AH, objD2AH;

        if (objF.isLine2D()) {
            if (!dynamicEPSObjF.isEmpty()) { objD1H = dynamicEPSObjF.GetMin().hseg; }
            if (objG.isLine2D()) {
                if (!dynamicEPSObjG.isEmpty()) {
                    objD2H = dynamicEPSObjG.GetMin().hseg;
                    if (objD1H < objD2H) {
                        dynamicEPSObjF.DeleteMin();
                    } else {
                        dynamicEPSObjG.DeleteMin();
                    }
                }
                return;
            }
            else if (objG.isRegion2D()) {
                if (!dynamicEPSObjG.isEmpty()) {
                    objD2AH = dynamicEPSObjG.GetMin();
                    if (objD1H < objD2AH) {
                        dynamicEPSObjF.DeleteMin();
                    } else {
                        dynamicEPSObjG.DeleteMin();
                    }
                }
                return;
            }
        }
        else if (objF.isRegion2D()) {
            if (!dynamicEPSObjF.isEmpty()) {
                objD1AH = dynamicEPSObjF.GetMin();
            }
            if (objG.isLine2D()) {
                if (!dynamicEPSObjG.isEmpty()) {
                    objD2H = dynamicEPSObjG.GetMin().hseg;
                    if (objD1AH < objD2H) {
                        dynamicEPSObjF.DeleteMin();
                    } else {
                        dynamicEPSObjG.DeleteMin();
                    }
                }
                return;
            }
            else if (objG.isRegion2D()) {
                if (!dynamicEPSObjG.isEmpty()) {
                    objD2AH = dynamicEPSObjG.GetMin();
                    if (objD1AH < objD2AH) {
                        dynamicEPSObjF.DeleteMin();
                    } else {
                        dynamicEPSObjG.DeleteMin();
                    }
                }
                return;
            }
        }
    }

}

ParallelObjectTraversal::object  PlaneSweep::getObject() {
    // temporary, to be replaced
    return getPot()->getObject();

}

ParallelObjectTraversal::status  PlaneSweep::getStatus() {
    // temporary, to be replaced
    return getPot()->getStatus();
}

void PlaneSweep::updateSegmentClassWhileAddingSegment(PlaneSweepLineStatusObject &sweepLineStatusObject) {
    /*
     * We assume that the segment is already added to the sweepLineStatus.
     * (In the addLeft function)
     */
    /*
     * Only add segments from sweepLineStatus which have the segmentClass
     * as (1/2), (2/1), (0/2), (2/0).
     *
     * How to assign overLap numbers.
     *  1. If it has no successor  then assign 0 to upper and if there is no predecessor
     *       then assign 0 to lower.
     *  2. If the predecessor is another region object and the successor is the same region object, 1/2.
     *      If the successor is different region object and the predecessor is same region object, 2/1.
     *  3. If the segment is from both the objects, then assign 2 or 0 based on whether the predecessor or
     *      successor is present or not.
     *
     *      In some cases, the lower value of the current is the upper value of predecessor/upper value of predecessor+1.
     *
     *      Same objects case:
     *          a) current and predecessor are the same object.
     *              a1) In the case where the predecessor's upper is 1/2, and ia is 1,
     *          and the current's ia is 0, then current's lower is 1/2.
     *              Cases not possible:
     *                  I) pred's upper is 0 and ia is 1.
     *              a2) In the case where the predecessor's upper is 0/1, and ia is 0,
     *          and the current's ia is 1, then current's lower is 0/1.
     *              Cases not possible:
     *                  I) pred's upper is 2 and ia is 0.
     *                  II) pred's ia=1 and curr's ia=1.
     *                  III) pred's ia=0 and curr's ia=0.
     *
     *          b) current and successor are the same object.
     *              b1) In the case where the successor's lower is 0/1, and ia is 1,
     *          and the current's ia is 0, then current's upper is 0/1.
     *              b2) In the case where the successor's lower is 1/2, and ia is 0,
     *          and the current's ia is 1, then current's upper is 1/2.
     *              b3) In the case where the successor's lower is 0/1, and ia is 1,
     *          and the current's ia is 1, then current's upper is 1/2.
     *
     *
     *     Different objects case:
     *          c) current and predecessor are different objects.
     *              c1) In the case where the predecessor's upper is 2, and ia is 1,
     *          and the current's ia is 0, then current's lower is 2.
     *              CASES which do not occur:
     *                  I) pred's upper is 0 and ia is 1.
     *                  II) pred's upper is 1, ia=1, current's ia=0
     *
     *              c2) In the case where the predecessor's upper is 1, and ia is 1,
     *          and the current's ia is 1, then current's lower is 1.
     *              CASES which do not occur:
     *                  I) pred's upper is 0 and ia is 1.
     *                  II) pred's upper is 2, ia=1, current's ia is 1.
     *
     *              c3) Pred's ia=0, curr's ia=1. if pred's upper is 0
     *                  then curr's lower is 0.
     *                  CASES which do NOT occur:
     *                       I)pred's ia=0, curr's ia=0, pred's upper=1.
     *                       II) pred's ia=0, pred's upper=2.
     *                       III) pred's ia=0, curr's ia=0.
     *
     *          d) current and successor are different objects
     *              d1) succ's ia=0, curr's ia=0.
     *                  succ's lower is 2, then curr's upper is 1 AND change succ's lower to 1.
     *
     *                  CASES which do not occur:
     *                      I) succ's ia=0, lower is 0.
     *                      II) succ's ia=0, lower is 1.
     *
     *              d2) succ's ia=0, curr's ia=1.
     *                  succ's lower 1, then curr's upper is 2 AND change succ's lower to 2.
     *
     *                  CASES which do not occur:
     *                      I) succ's ia=0, lower is 0.
     *                      II) succ's ia=0, curr's ia=1, succ's lower=2.
     *
     *              d3) succ's ia=1, curr's ia=0.
     *                  succ's lower 1, then curr's upper is 0 AND change succ's lower to 0.
     *
     *                  CASES which do not occur:
     *                      I) succ's ia=1, succ's lower=0.
     *                      II) uscc's ia=1, succ's lower=2.
     *
     *              d4) succ's ia=1, curr's ia=1.
     *                  succ's lower is 0, then set curr's upper is 1, AND change succ's lower to 1.
     *
     *                  CASES which do not occur:
     *                      I) ucc's ia=1, curr's ia=1, succ's lower=1/2.
     *
     */

    AVLnode<PlaneSweepLineStatusObject> *predecessorNode = sweepLineStatus->getPred(sweepLineStatusObject);
    AVLnode<PlaneSweepLineStatusObject> *successorNode = sweepLineStatus->getSucc(sweepLineStatusObject);

    AVLnode<PlaneSweepLineStatusObject> *currentNode = sweepLineStatus->FindKey(sweepLineStatusObject);

    bool isPredecessorSameObjectAsCurrent;
    bool isSuccessorSameObjectAsCurrent;

    SegmentClass predecessorSegmentClass = predecessorNode->key.getSegmentClass();
    SegmentClass successorSegmentClass = successorNode->key.getSegmentClass();
    bool iaPred, iaSucc, iaCurr = sweepLineStatusObject.getInsideAbove();

    if (predecessorNode && successorNode) {

    } else if (predecessorNode != NULL) {
        iaPred = predecessorNode->key.getInsideAbove();
        if (currentNode->key.getObject() == predecessorNode->key.getObject()) {
            isPredecessorSameObjectAsCurrent = true;
            if(iaPred == true && iaCurr == false) {
                // dummy val 0 for uol
                int lorCurr = predecessorNode->key.getSegmentClass().getUpperOrLeft();
                if (lorCurr == 1 || lorCurr == 2) {
                    //sweepLineStatusObject.setSegmentClass(lorCurr, 0);
                    currentNode->key.getSegmentClass().setLowerOrRight(lorCurr);
                }
            } else if (iaPred == false && iaCurr ==true) {
                // dummy val 0 for uol
                int lorCurr = predecessorNode->key.getSegmentClass().getUpperOrLeft();
                if (lorCurr==0 || lorCurr==1) {
                    //sweepLineStatusObject.setSegmentClass(lorCurr, 0);
                    currentNode->key.getSegmentClass().setLowerOrRight(lorCurr);
                }
            }
            /*
             * Cases not possible:
             * I) pred's upper is 2 and ia is 0.
             * II) pred's ia=1 and curr's ia=1.
             * III) pred's ia=0 and curr's ia=0.
             * IV) pred's upper is 0 and ia is 1.
             */
        } else {
            isPredecessorSameObjectAsCurrent = false;
            if(iaPred ==true && iaCurr ==false) { //c1
                int lorCurr = predecessorNode->key.getSegmentClass().getUpperOrLeft();
                if(lorCurr ==2) {
                    //dummy val 1 for uol
                    //sweepLineStatusObject.setSegmentClass(lorCurr, 1);
                    currentNode->key.getSegmentClass().setLowerOrRight(lorCurr);
                }
                /*
                 * CASES which do not occur:
                 * I) pred's upper is 0 and ia is 1.
                 * II) pred's upper is 1, ia=1, current's ia=0
                 */
            } else if (iaPred == true && iaCurr ==true) { //c2
                int lorCurr = predecessorNode->key.getSegmentClass().getUpperOrLeft();
                if(lorCurr == 1) {
                    //dummy val 2 for uol
                    //sweepLineStatusObject.setSegmentClass(lorCurr, 2);
                    currentNode->key.getSegmentClass().setLowerOrRight(lorCurr);
                }
                /*
                 * CASES which do not occur:
                 * I) pred's upper is 0 and ia is 1.
                 * II) pred's upper is 2, ia=1, current's ia is 1.
                 */
            } else if (iaPred == false && iaCurr == true) { //c3
                int lorCurr = predecessorNode->key.getSegmentClass().getUpperOrLeft();
                if (lorCurr ==0) {
                    //dummy val 1 for uol
                    //sweepLineStatusObject.setSegmentClass(lorCurr, 1);
                    currentNode->key.getSegmentClass().setLowerOrRight(lorCurr);
                }

                /*
                 * CASES which do NOT occur:
                 * I)pred's ia=0, curr's ia=0, pred's upper=1.
                 * II) pred's ia=0, pred's upper=2.
                 * III) pred's ia=0, curr's ia=0. counter arguement : WHY NOT?
                 */
            }
        }
    } else {
        currentNode->key.getSegmentClass().setLowerOrRight(0); //Case1
    }
    if (successorNode != NULL) {
        iaSucc = successorNode->key.getInsideAbove();
        if (currentNode->key.getObject() == successorNode->key.getObject()) {
            isSuccessorSameObjectAsCurrent = true;
            if(iaSucc == true && iaCurr == false) {
                //dummy val 0 for lor
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr==0 || uolCurr==1) {
                    //sweepLineStatusObject.setSegmentClass(0,uol);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }
            } else if (iaSucc == false && iaCurr == true) {
                //dummy val 0 for lor
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr==1 || uolCurr==2) {
                    //sweepLineStatusObject.setSegmentClass(0,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }
            }
        } else {
            isSuccessorSameObjectAsCurrent = false;
            if(iaSucc == false && iaCurr == false) { //case d1 ??
                //dummy val 2 for lor
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr ==1) {
                    //sweepLineStatusObject.setSegmentClass(2,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                } else if (uolCurr ==2) {
                    uolCurr--;
                    successorNode->key.getSegmentClass().setLowerOrRight(uolCurr);
                    //sweepLineStatusObject.setSegmentClass(2,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }

            } else if (iaSucc == false && iaCurr == true) { //d2
                // dummy val 1 for lor
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr == 1) {
                    uolCurr++;
                    successorNode->key.getSegmentClass().setLowerOrRight(uolCurr);
                    //sweepLineStatusObject.setSegmentClass(1,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }
            }  else if (iaSucc == true && iaCurr == false) { //d3
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr ==1) {
                    uolCurr--;
                    successorNode->key.getSegmentClass().setLowerOrRight(uolCurr);
                    //sweepLineStatusObject.setSegmentClass(1,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }
            } else if (iaSucc == true && iaCurr == true) { //d4
                int uolCurr = successorNode->key.getSegmentClass().getLowerOrRight();
                if (uolCurr ==0) {
                    //dummy val 0 for lor
                    uolCurr++;
                    successorNode->key.getSegmentClass().setLowerOrRight(uolCurr);
                    //sweepLineStatusObject.setSegmentClass(0,uolCurr);
                    currentNode->key.getSegmentClass().setUpperOrLeft(uolCurr);
                }
            }
        }
    } else {
        currentNode->key.getSegmentClass().setUpperOrLeft(0); //Case1
    }
}


void PlaneSweep::addLeft(PlaneSweepLineStatusObject &planeSweepLineStatusObject) {
    sweepLineStatus->insert(planeSweepLineStatusObject);

    /*
     * Add the updateSegmentClass code here.
     * it should update the segmentClass for the added segment
     * as well as it's predecessor and successor.
     */

    updateSegmentClassWhileAddingSegment(planeSweepLineStatusObject);

    Seg2D pred = getPredecessor(planeSweepLineStatusObject).getSegment2D();
    Seg2D succ = getSuccessor(planeSweepLineStatusObject).getSegment2D();

    Seg2D seg2D = planeSweepLineStatusObject.getSegment2D();

    if (((objF.isLine2D() && objG.isLine2D()) || (objF.isLine2D() && objG.isRegion2D()) ||
         (objF.isRegion2D() && objG.isRegion2D())) && isRelation(seg2D, pred)) {
        splitLines(seg2D, pred);
    }
    else if (((objF.isLine2D() && objG.isLine2D()) || (objF.isLine2D() && objG.isRegion2D()) ||
              (objF.isRegion2D() && objG.isRegion2D())) && isRelation(seg2D, succ)) {
        splitLines(seg2D, succ);
    }
}

void PlaneSweep::delRight(PlaneSweepLineStatusObject &planeSweepLineStatusObject) {

    Seg2D pred = getPredecessor(planeSweepLineStatusObject).getSegment2D();
    Seg2D succ = getSuccessor(planeSweepLineStatusObject).getSegment2D();

    Seg2D seg2D = planeSweepLineStatusObject.getSegment2D();
    sweepLineStatus->deleteKey(seg2D);
    if (((objF.isLine2D() && objG.isLine2D()) || (objF.isLine2D() && objG.isRegion2D()) ||
         (objF.isRegion2D() && objG.isRegion2D())) && isRelation(pred, succ)) {
        splitLines(pred, succ);
    }

    /*
 * Add the updateSegmentClass code here.
 * it should update the segmentClass for the deleted segment's
 *  predecessor and successor.
 */
}

//TODO change type of getElements() from AVLtree
bool PlaneSweep::coincident(Seg2D &givenSeg) {
    int itr = 0;
    int const treeSize = sweepLineStatus->sizeOfAVL();

    PlaneSweepLineStatusObject **segArray = (PlaneSweepLineStatusObject **) malloc(treeSize);
    sweepLineStatus->getElements(segArray);

    for (itr = 0; itr < treeSize; itr++) {
        Seg2D seg2D = segArray[itr]->getSegment2D();
        if (Intersects(seg2D, givenSeg))
            return true;
    }
    return false;

}

Seg2D PlaneSweep::predOfP(Poi2D &p) {
    int itr = 0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    PlaneSweepLineStatusObject **segArray = (PlaneSweepLineStatusObject **) malloc(treeSize);
    sweepLineStatus->getElements(segArray);

    for (itr = 0; itr < treeSize; itr++) {

        PlaneSweepLineStatusObject planeSweepLineStatusObject = *segArray[itr];
        Seg2D seg2D = segArray[itr]->getSegment2D();

        PlaneSweepLineStatusObject planeSweepLineStatusObject1 = sweepLineStatus->getPred(
                planeSweepLineStatusObject)->key;
        Seg2D seg2D1 = planeSweepLineStatusObject1.getSegment2D();

        Poi2D Ipoint = IntersectionPoint(seg2D, seg2D1);
        if (Ipoint.y < p.y)
            return seg2D;
    }

}

bool PlaneSweep::predExists(Seg2D &seg2D) {
    PlaneSweepLineStatusObject sweepLineStatusObject(seg2D);
    AVLnode<PlaneSweepLineStatusObject> *nodeInSweepLineStatus = sweepLineStatus->FindKey(sweepLineStatusObject);
    if (nodeInSweepLineStatus != NULL && nodeInSweepLineStatus->left != NULL) {
        return true;
    }
    return false;
}

SegmentClass PlaneSweep::getPredSegmentClass(Seg2D seg2D) {
    AVLnode<PlaneSweepLineStatusObject> *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getSegmentClass();
}

bool PlaneSweep::getPredInsideAbove(Seg2D seg2D) {
    AVLnode<PlaneSweepLineStatusObject> *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getInsideAbove();
}


bool PlaneSweep::isRelation(Seg2D &firstSegment, Seg2D &secondSegment) {
    if ((Intersects(firstSegment, secondSegment)) || (Touch(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) ||
        (SegmentLiesOnSegment(firstSegment, secondSegment) &&
         SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
         SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentLiesOnSegment(firstSegment, secondSegment) &&
         SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
         SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) ||
        (SegmentLiesOnSegment(secondSegment, firstSegment) &&
         SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
         SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment))) {
        return true;
    }
    return false;
}

/*TODO Need to see how ConstSegIterator can be used for pot->isInObjF(Seg2D) and pot->isInObjG(seg2D) and ConstHalsegInterator, ConstAttrHalfsegIterator for getNextObjIterator
 * TODO see how Attributed half segments can be generated from segments
 * TODO see what to insert for ia since attributed halfsegment iterators can consider ia for comparison
 * VERY IMPORTANT
 * */
void PlaneSweep::splitLines(Seg2D &firstSegment, Seg2D &secondSegment) {
    if (Intersects(firstSegment, secondSegment)) {
        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {
            Poi2D mp = IntersectionPoint(firstSegment, secondSegment);
            Seg2D S11(firstSegment.p1, mp);
            Seg2D S21(secondSegment.p1, mp);
            Seg2D S12(mp, firstSegment.p2);
            Seg2D S22(mp, secondSegment.p2);

            updateSweepLineStatus(firstSegment, S11);
            updateSweepLineStatus(secondSegment, S21);

            HalfSeg2D *halfSeg11Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;
            HalfSeg2D *halfSeg21Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;

            AttrHalfSeg2D *attrHalfSeg11FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;
            AttrHalfSeg2D *attrHalfSeg21FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;

            AttrHalfSeg2D *attrHalfSeg11GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;
            AttrHalfSeg2D *attrHalfSeg21GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg11Right = new HalfSeg2D(S11, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
                halfSeg21Right = new HalfSeg2D(S21, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }

            }


            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                }

            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                }

            }
        }

    }
    else if (Touch(firstSegment, secondSegment)) {
        Poi2D tp = TouchingPoint(firstSegment, secondSegment);
        Seg2D S11(firstSegment.p1, tp);
        Seg2D S21(secondSegment.p1, tp);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {
            if (PointLiesOnRightEndPointOfSegment(tp, secondSegment)) {
                Seg2D S12(tp, firstSegment.p2);

                HalfSeg2D *halfSeg11Right;
                HalfSeg2D *halfSeg12Left;
                HalfSeg2D *halfSeg12Right;
                HalfSeg2D *halfSeg21Right;

                AttrHalfSeg2D *attrHalfSeg11FRight;
                AttrHalfSeg2D *attrHalfSeg12FLeft;
                AttrHalfSeg2D *attrHalfSeg12FRight;
                AttrHalfSeg2D *attrHalfSeg21FRight;

                AttrHalfSeg2D *attrHalfSeg11GRight;
                AttrHalfSeg2D *attrHalfSeg12GLeft;
                AttrHalfSeg2D *attrHalfSeg12GRight;
                AttrHalfSeg2D *attrHalfSeg21GRight;

                if (objF.isLine2D() || objG.isLine2D()) {
                    halfSeg11Right = new HalfSeg2D(S11, false);
                    halfSeg12Left = new HalfSeg2D(S12, true);
                    halfSeg12Right = new HalfSeg2D(S12, false);
                    halfSeg21Right = new HalfSeg2D(S21, false);
                }
                if (objF.isRegion2D() || objG.isRegion2D()) {
                    if (objF.isRegion2D()) {
                        AttrHalfSeg2D temp = getPot()->currentFASeg();
                        attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                        attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                        attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                        attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    }
                    if (objG.isRegion2D()) {
                        AttrHalfSeg2D temp = getPot()->currentGASeg();
                        attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                        attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                        attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                        attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    }
                }


                if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {

                    if (objF.isLine2D() && objG.isLine2D()) {
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    }
                    else if (objF.isLine2D() && objG.isRegion2D()) {
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                        dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    }
                    else if (objF.isRegion2D() && objG.isRegion2D()) {
                        dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                        dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                        dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    }

                }
                else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {

                    if (objG.isLine2D() && objG.isLine2D()) {
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    }
                    else if (objG.isRegion2D() && objF.isLine2D()) {
                        dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                        dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    }
                    else if (objG.isRegion2D() && objF.isRegion2D()) {
                        dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                        dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                        dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    }
                }

            }
            else if (PointLiesOnRightEndPointOfSegment(tp, firstSegment)) {
                Seg2D S22(tp, secondSegment.p2);
                HalfSeg2D *halfSeg11Right;
                HalfSeg2D *halfSeg21Right;
                HalfSeg2D *halfSeg22Left;
                HalfSeg2D *halfSeg22Right;
                AttrHalfSeg2D *attrHalfSeg11FRight;
                AttrHalfSeg2D *attrHalfSeg21FRight;
                AttrHalfSeg2D *attrHalfSeg22FLeft;
                AttrHalfSeg2D *attrHalfSeg22FRight;
                AttrHalfSeg2D *attrHalfSeg11GRight;
                AttrHalfSeg2D *attrHalfSeg21GRight;
                AttrHalfSeg2D *attrHalfSeg22GLeft;
                AttrHalfSeg2D *attrHalfSeg22GRight;
                if (objF.isLine2D() && objG.isLine2D()) {
                    halfSeg11Right = new HalfSeg2D(S11, false);
                    halfSeg21Right = new HalfSeg2D(S21, false);
                    halfSeg22Left = new HalfSeg2D(S22, true);
                    halfSeg22Right = new HalfSeg2D(S22, false);
                }
                if (objF.isRegion2D() || objG.isRegion2D()) {
                    if (objF.isRegion2D()) {
                        AttrHalfSeg2D temp = getPot()->currentFASeg();
                        attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                        attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                        attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                        attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    }
                    if (objG.isRegion2D()) {
                        AttrHalfSeg2D temp = getPot()->currentGASeg();
                        attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                        attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                        attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                        attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    }
                }

                if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                    if (objF.isLine2D() && objG.isLine2D()) {
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    }
                    else if (objF.isLine2D() && objG.isRegion2D()) {
                        dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                        dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    }
                    else if (objF.isRegion2D() && objG.isRegion2D()) {
                        dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                        dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                        dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    }

                }
                else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                    if (objG.isLine2D() && objF.isLine2D()) {
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                        dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    }
                    else if (objG.isRegion2D() && objF.isLine2D()) {
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                        dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                        dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    }
                    else if (objG.isRegion2D() && objG.isRegion2D()) {
                        dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                        dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                        dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                        dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    }

                }
            }
        }
    }
    else if (SegmentIsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S11);
        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg11Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;
            AttrHalfSeg2D *attrHalfSeg11FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;
            AttrHalfSeg2D *attrHalfSeg11GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg11Right = new HalfSeg2D(S11, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
            }

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg)); // Is it required?? Should it be S21??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight); // Is it required?? Should it be S21??
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight); // Is it required?? Should it be S21??
                }

            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg)); // Is it required?? Should it be S21??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg)); // Is it required?? Should it be S21??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight); // Is it required?? Should it be S21??
                }

            }

        }
    }
    else if (SegmentIsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(secondSegment, S21);
        updateSweepLineStatus(firstSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg21Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;
            AttrHalfSeg2D *attrHalfSeg21FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;
            AttrHalfSeg2D *attrHalfSeg21GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg21Right = new HalfSeg2D(S21, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
            }

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {
                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg)); // Is it required?? Should it be S11??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight); // Is it required?? Should it be S11??
                }
            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg)); // Is it required?? Should it be S11??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg)); // Is it required?? Should it be S11??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight); // Is it required?? Should it be S11??
                }
            }

        }
    }
    else if (SegmentLiesOnSegment(firstSegment, secondSegment) &&
             SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
             SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);
        Seg2D S13(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg11Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;
            HalfSeg2D *halfSeg13Left;
            HalfSeg2D *halfSeg13Right;

            AttrHalfSeg2D *attrHalfSeg11FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;
            AttrHalfSeg2D *attrHalfSeg13FLeft;
            AttrHalfSeg2D *attrHalfSeg13FRight;

            AttrHalfSeg2D *attrHalfSeg11GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;
            AttrHalfSeg2D *attrHalfSeg13GLeft;
            AttrHalfSeg2D *attrHalfSeg13GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg11Right = new HalfSeg2D(S11, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
                halfSeg13Left = new HalfSeg2D(S13, true);
                halfSeg13Right = new HalfSeg2D(S13, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg13FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S13);
                    attrHalfSeg13FRight = new AttrHalfSeg2D(temp.insideAbove, false, S13);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg13GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S13);
                    attrHalfSeg13GRight = new AttrHalfSeg2D(temp.insideAbove, false, S13);
                }
            }


            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg13Left->isLeft, halfSeg13Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg13Right->isLeft, halfSeg13Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg13Left->isLeft, halfSeg13Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg13Right->isLeft, halfSeg13Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S22??
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg13FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg13FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S22??
                }
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {

                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg13Left->isLeft, halfSeg13Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg13Right->isLeft, halfSeg13Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg13GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg13GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg13GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg13GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight); // Is it required?? Should it be S22??
                }
            }

        }
    }
    else if (SegmentLiesOnSegment(secondSegment, firstSegment) &&
             SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
             SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);
        Seg2D S23(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg21Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;
            HalfSeg2D *halfSeg23Left;
            HalfSeg2D *halfSeg23Right;

            AttrHalfSeg2D *attrHalfSeg21FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;
            AttrHalfSeg2D *attrHalfSeg23FLeft;
            AttrHalfSeg2D *attrHalfSeg23FRight;

            AttrHalfSeg2D *attrHalfSeg21GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;
            AttrHalfSeg2D *attrHalfSeg23GLeft;
            AttrHalfSeg2D *attrHalfSeg23GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg21Right = new HalfSeg2D(S21, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
                halfSeg23Left = new HalfSeg2D(S23, true);
                halfSeg23Right = new HalfSeg2D(S23, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    attrHalfSeg23FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S23);
                    attrHalfSeg23FRight = new AttrHalfSeg2D(temp.insideAbove, false, S23);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    attrHalfSeg23GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S23);
                    attrHalfSeg23GRight = new AttrHalfSeg2D(temp.insideAbove, false, S23);
                }
            }

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg23Left->isLeft, halfSeg23Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg23Right->isLeft, halfSeg23Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg23Left->isLeft, halfSeg23Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg23Right->isLeft, halfSeg23Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S12??
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg23FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg23FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S12??
                }

            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg23Left->isLeft, halfSeg23Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg23Right->isLeft, halfSeg23Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg23GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg23GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg23GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg23GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight); // Is it required?? Should it be S12??
                }
            }

        }
    }
    else if (SegmentIsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg11Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;

            AttrHalfSeg2D *attrHalfSeg11FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;

            AttrHalfSeg2D *attrHalfSeg11GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg11Right = new HalfSeg2D(S11, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
            }

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S22??
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S22??
                }

            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S22??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft); // Is it required?? Should it be S22??
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight); // Is it required?? Should it be S22??
                }
            }

        }

    }
    else if (SegmentIsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg21Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;

            AttrHalfSeg2D *attrHalfSeg21FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;

            AttrHalfSeg2D *attrHalfSeg21GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg21Right = new HalfSeg2D(S21, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
            }
            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
            }

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {

                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S12??
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {

                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S12??
                }

            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {

                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S12??
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft); // Is it required?? Should it be S12??
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight); // Is it required?? Should it be S12??
                }

            }

        }
    }
    else if (SegmentLiesOnSegment(firstSegment, secondSegment) &&
             SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
             SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg11Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;

            AttrHalfSeg2D *attrHalfSeg11FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;

            AttrHalfSeg2D *attrHalfSeg11GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg11Right = new HalfSeg2D(S11, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
            }

            if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg11FRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg11GRight = new AttrHalfSeg2D(temp.insideAbove, false, S11);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                }
            }

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg11FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                }

            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg11Right->isLeft, halfSeg11Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg11GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                }

            }

        }


    }
    else if (SegmentLiesOnSegment(secondSegment, firstSegment) &&
             SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
             SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            HalfSeg2D *halfSeg21Right;
            HalfSeg2D *halfSeg22Left;
            HalfSeg2D *halfSeg22Right;
            HalfSeg2D *halfSeg12Left;
            HalfSeg2D *halfSeg12Right;

            AttrHalfSeg2D *attrHalfSeg21FRight;
            AttrHalfSeg2D *attrHalfSeg22FLeft;
            AttrHalfSeg2D *attrHalfSeg22FRight;
            AttrHalfSeg2D *attrHalfSeg12FLeft;
            AttrHalfSeg2D *attrHalfSeg12FRight;

            AttrHalfSeg2D *attrHalfSeg21GRight;
            AttrHalfSeg2D *attrHalfSeg22GLeft;
            AttrHalfSeg2D *attrHalfSeg22GRight;
            AttrHalfSeg2D *attrHalfSeg12GLeft;
            AttrHalfSeg2D *attrHalfSeg12GRight;

            if (objF.isLine2D() || objG.isLine2D()) {
                halfSeg21Right = new HalfSeg2D(S21, false);
                halfSeg22Left = new HalfSeg2D(S22, true);
                halfSeg22Right = new HalfSeg2D(S22, false);
                halfSeg12Left = new HalfSeg2D(S12, true);
                halfSeg12Right = new HalfSeg2D(S12, false);
            }
            else if (objF.isRegion2D() || objG.isRegion2D()) {
                if (objF.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentFASeg();
                    attrHalfSeg21FRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22FRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    attrHalfSeg12FLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12FRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
                if (objG.isRegion2D()) {
                    AttrHalfSeg2D temp = getPot()->currentGASeg();
                    attrHalfSeg21GRight = new AttrHalfSeg2D(temp.insideAbove, false, S21);
                    attrHalfSeg22GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S22);
                    attrHalfSeg22GRight = new AttrHalfSeg2D(temp.insideAbove, false, S22);
                    attrHalfSeg12GLeft = new AttrHalfSeg2D(temp.insideAbove, true, S12);
                    attrHalfSeg12GRight = new AttrHalfSeg2D(temp.insideAbove, false, S12);
                }
            }

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {

                if (objF.isLine2D() && objG.isLine2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                }
                else if (objF.isLine2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                }
                else if (objF.isRegion2D() && objG.isRegion2D()) {
                    dynamicEPSObjF.Insert(*attrHalfSeg21FRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight); // Is it required?? Should it be S21??
                    dynamicEPSObjG.Insert(*attrHalfSeg12GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg12GRight);
                }

            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {

                if (objG.isLine2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg21Right->isLeft, halfSeg21Right->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg));
                    dynamicEPSObjG.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                }
                else if (objG.isRegion2D() && objF.isLine2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Left->isLeft, halfSeg22Left->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg22Right->isLeft, halfSeg22Right->seg)); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Left->isLeft, halfSeg12Left->seg));
                    dynamicEPSObjF.Insert(AttrHalfSeg2D(false, halfSeg12Right->isLeft, halfSeg12Right->seg));
                }
                else if (objG.isRegion2D() && objF.isRegion2D()) {
                    dynamicEPSObjG.Insert(*attrHalfSeg21GRight);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GLeft);
                    dynamicEPSObjG.Insert(*attrHalfSeg22GRight);
                    dynamicEPSObjF.Insert(*attrHalfSeg22FLeft); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(*attrHalfSeg22FRight); // Is it required?? Should it be S21??
                    dynamicEPSObjF.Insert(*attrHalfSeg12FLeft);
                    dynamicEPSObjF.Insert(*attrHalfSeg12FRight);
                }

            }

        }


    }

}


Poi2D PlaneSweep::getPoiEvent(ParallelObjectTraversal::object objectValue) {
    Poi2D poi2D, poi2DStatic, poi2DDynamic;
    AttrHalfSeg2D attrHalfSegDynamic;
    HalfSeg2D halfSeg2D;
//Get static point
    Point2D::ConstPoiIterator *pos = getPot()->getPoiObjIterator(objectValue);
    poi2DStatic = *(*pos);


    poi2D = poi2DStatic;
    return poi2D;
}

HalfSeg2D PlaneSweep::getHalfSegEvent(ParallelObjectTraversal::object objectValue) {
    HalfSeg2D halfSeg2D, halfSeg2DStatic, halfSeg2DDynamic;
//Get static HalfSeg2D
    Line2DImpl::ConstHalfSegIterator *pos = getPot()->getHalfSegIterator(objectValue);
    halfSeg2DStatic = *(*pos);


    //Get Dynamic halfSeg
    if (objectValue == ParallelObjectTraversal::first) {
        if (!dynamicEPSObjF.isEmpty()) {
            halfSeg2DDynamic = dynamicEPSObjF.GetMin().hseg;
        }

    } else if (objectValue == ParallelObjectTraversal::second) {
        if (!dynamicEPSObjG.isEmpty()) {
            halfSeg2DDynamic = dynamicEPSObjG.GetMin().hseg;
        }
    }

    if (objectValue == ParallelObjectTraversal::first && dynamicEPSObjF.isEmpty()) {
        halfSeg2D = halfSeg2DStatic;
        return halfSeg2D;
    }
    if (objectValue == ParallelObjectTraversal::second && dynamicEPSObjG.isEmpty()) {
        halfSeg2D = halfSeg2DStatic;
        return halfSeg2D;
    }

    halfSeg2D = (halfSeg2DDynamic <= halfSeg2DStatic) ? halfSeg2DDynamic : halfSeg2DStatic;
    return halfSeg2D;
}


AttrHalfSeg2D PlaneSweep::getAttrHalfSegEvent(ParallelObjectTraversal::object objectValue) {
    AttrHalfSeg2D attrHalfSeg2D, attrHalfSeg2DStatic, attrHalfSeg2DDynamic;
//Get static HalfSeg2D
    Region2DImpl::ConstAttributedHalfSegmentIterator *pos = getPot()->getAttrHalfSegIterator(objectValue);
    attrHalfSeg2DStatic = *(*pos); //TODO: Group2 need to correct the return type from RegionImpl to AttrHalfSeg2D


    //Get Dynamic point
    if (objectValue == ParallelObjectTraversal::first) {
        if (!dynamicEPSObjF.isEmpty()) {
            attrHalfSeg2DDynamic = dynamicEPSObjF.GetMin();
        }

    } else if (objectValue == ParallelObjectTraversal::second) {
        if (!dynamicEPSObjG.isEmpty()) {
            attrHalfSeg2DDynamic = dynamicEPSObjG.GetMin();
        }

    }

    if (objectValue == ParallelObjectTraversal::first && dynamicEPSObjF.isEmpty()) {
        attrHalfSeg2D = attrHalfSeg2DStatic;
        return attrHalfSeg2D;
    }

    if (objectValue == ParallelObjectTraversal::second && dynamicEPSObjG.isEmpty()) {
        attrHalfSeg2D = attrHalfSeg2DStatic;
        return attrHalfSeg2D;
    }

    attrHalfSeg2D = (attrHalfSeg2DDynamic <= attrHalfSeg2DStatic) ? attrHalfSeg2DDynamic : attrHalfSeg2DStatic;
    return attrHalfSeg2D;
}

/* TODO Need to update attrHalfSeg implementation after group 2 changes it
 * TODO Need to update code to get next object after a given object in an AVL tree to get dynSucc
 */

bool PlaneSweep::lookAhead(HalfSeg2D &halfseg2D, Line2D &line2D) {
    Seg2D &seg2D = halfseg2D.seg;
    if (pot->isObjectF(line2D)) {
        //Static
        ParallelObjectTraversal::object objf = ParallelObjectTraversal::first;
        Line2DImpl::ConstHalfSegIterator *val = getPot()->getNextObjIterator(halfseg2D, objf);
        HalfSeg2D *halfsegStaticSucc = nullptr;
        if (val != nullptr) {
            halfsegStaticSucc = new HalfSeg2D();
            *halfsegStaticSucc = *(*val);
        }
        else {
            halfsegStaticSucc = nullptr;
        } // TODO the 'else' block is redundant code

        //Dynamic
//        dynamicEPSObjF.DeleteMin();
//        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjF.GetMin();
//        AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
//        dynamicEPSObjF.Insert(attrhalfsegReinsert);
//        HalfSeg2D halfsegDynSucc = attrhalfsegDynSucc.halfsegment; //change later

        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjF.GetNext(attrhalfsegReinsert);
        HalfSeg2D *halfsegDynSucc = nullptr;
        if (!dynamicEPSObjF.isEmpty()) {
            halfsegDynSucc = new HalfSeg2D(); //change later
            *halfsegDynSucc = dynamicEPSObjF.GetNext(AttrHalfSeg2D(false, halfseg2D.isLeft, halfseg2D.seg)).hseg;
        }
        //*halfsegDynSucc = attrhalfsegDynSucc.hseg;

        if (halfsegStaticSucc == nullptr && halfsegDynSucc == nullptr) {
            return false;
        }

        if ((halfsegStaticSucc != nullptr && halfsegDynSucc == nullptr) || (*halfsegStaticSucc < *halfsegDynSucc)) {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = (*halfsegStaticSucc).isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = halfseg2D.seg.p1;
            }
            else {
                dpGiven = halfseg2D.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*halfsegStaticSucc).seg.p1;
            }
            else {
                dpSucc = (*halfsegStaticSucc).seg.p2;
            }

            if (dpGiven == dpSucc) {
                return true;
            }
            else {
                return false;
            }
        }
        else if ((halfsegStaticSucc == nullptr && halfsegDynSucc != nullptr) ||
                 (*halfsegDynSucc > *halfsegStaticSucc)) {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = (*halfsegDynSucc).isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = halfseg2D.seg.p1;
            }
            else {
                dpGiven = halfseg2D.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*halfsegDynSucc).seg.p1;
            }
            else {
                dpSucc = (*halfsegDynSucc).seg.p2;
            }
            if (dpGiven == dpSucc) {
                return true;
            }
            else {
                return false;
            }
        }


    }
    else if (pot->isObjectG(line2D)) {
        //Static
        ParallelObjectTraversal::object objg = ParallelObjectTraversal::second;
        Line2DImpl::ConstHalfSegIterator *val = getPot()->getNextObjIterator(halfseg2D, objg);
        HalfSeg2D *halfsegStaticSucc = nullptr;
        if (val != nullptr) {
            halfsegStaticSucc = new HalfSeg2D();
            *halfsegStaticSucc = *(*val);
        }
        else {
            halfsegStaticSucc = nullptr;
        }

        //Dynamic
//        dynamicEPSObjG.DeleteMin();
//        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjG.GetMin();
//        AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
//        dynamicEPSObjG.Insert(attrhalfsegReinsert);
//        HalfSeg2D halfsegDynSucc = attrhalfsegDynSucc.halfsegment; //change later

        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjG.GetNext(attrhalfsegReinsert);
        HalfSeg2D *halfsegDynSucc = nullptr; //change later
        if (!dynamicEPSObjG.isEmpty()) {
            halfsegDynSucc = new HalfSeg2D();
            *halfsegDynSucc = dynamicEPSObjG.GetNext(AttrHalfSeg2D(false, halfseg2D.isLeft, halfseg2D.seg)).hseg;
        }
        //*halfsegDynSucc = attrhalfsegDynSucc.hseg;

        if (halfsegStaticSucc == nullptr && halfsegDynSucc == nullptr) {
            return false;
        }

        if ((halfsegStaticSucc != nullptr && halfsegDynSucc == nullptr) || (*halfsegStaticSucc <= (*halfsegDynSucc))) {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = (*halfsegStaticSucc).isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = halfseg2D.seg.p1;
            }
            else {
                dpGiven = halfseg2D.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*halfsegStaticSucc).seg.p1;
            }
            else {
                dpSucc = (*halfsegStaticSucc).seg.p2;
            }

            if (dpGiven == dpSucc) {
                return true;
            }
            else {
                return false;
            }
        }
        else if ((halfsegStaticSucc == nullptr && halfsegDynSucc != nullptr) ||
                 (*halfsegDynSucc > *halfsegStaticSucc)) {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = (*halfsegDynSucc).isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = halfseg2D.seg.p1;
            }
            else {
                dpGiven = halfseg2D.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*halfsegDynSucc).seg.p1;
            }
            else {
                dpSucc = (*halfsegDynSucc).seg.p2;
            }

            if (dpGiven == dpSucc) {
                return true;
            }
            else {
                return false;
            }
        }

    }
}

/* TODO Need to update attrHalfSeg implementation after group 2 changes it
 * TODO Need to update code to get next object after a given object in an AVL tree to get dynSucc
 */

bool PlaneSweep::lookAhead(AttrHalfSeg2D &attrhalfseg2D, Region2D &region2D) {
    Seg2D &seg2D = attrhalfseg2D.hseg.seg;
    if (pot->isObjectF(region2D)) {
        //Static
        ParallelObjectTraversal::object objf = ParallelObjectTraversal::first;
        Region2DImpl::ConstAttributedHalfSegmentIterator *val = getPot()->getNextObjIterator(attrhalfseg2D, objf);
        AttrHalfSeg2D *attrhalfsegStaticSucc = nullptr;
        if (val != nullptr) {
            attrhalfsegStaticSucc = new AttrHalfSeg2D();
            *attrhalfsegStaticSucc = *(*val);

        }
        else {
            attrhalfsegStaticSucc = nullptr;
        }

        //Dynamic
//        dynamicEPSObjF.DeleteMin();
//        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjF.GetMin();
//        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
//        dynamicEPSObjF.Insert(attrhalfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = attrhalfsegDynSucc.halfsegment //change later
        AttrHalfSeg2D *attrhalfsegDynSucc = nullptr;
        if (!dynamicEPSObjF.isEmpty()) {
            attrhalfsegDynSucc = new AttrHalfSeg2D();
            *attrhalfsegDynSucc = dynamicEPSObjF.GetNext(attrhalfseg2D);
        }

        if (attrhalfsegStaticSucc == nullptr && attrhalfsegDynSucc == nullptr) {
            return false;
        }

        if ((attrhalfsegStaticSucc != nullptr && attrhalfsegDynSucc == nullptr) ||
            (*attrhalfsegStaticSucc <= *attrhalfsegDynSucc)) {
            bool isDirGiven = attrhalfseg2D.hseg.isLeft;
            bool isDirSucc = (*attrhalfsegStaticSucc).hseg.isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.hseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.hseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*attrhalfsegStaticSucc).hseg.seg.p1;
            }
            else {
                dpSucc = (*attrhalfsegStaticSucc).hseg.seg.p2;
            }

            if (dpGiven == (dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }
        else if ((attrhalfsegStaticSucc == nullptr && attrhalfsegDynSucc != nullptr) ||
                 (*attrhalfsegDynSucc > *attrhalfsegStaticSucc)) {
            bool isDirGiven = attrhalfseg2D.hseg.isLeft;
            bool isDirSucc = (*attrhalfsegDynSucc).hseg.isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.hseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.hseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*attrhalfsegDynSucc).hseg.seg.p1;
            }
            else {
                dpSucc = (*attrhalfsegDynSucc).hseg.seg.p2;
            }
            if (dpGiven == (dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }


    }
    else if (pot->isObjectG(region2D)) {
        //Static
        ParallelObjectTraversal::object objg = ParallelObjectTraversal::second;
        Region2DImpl::ConstAttributedHalfSegmentIterator *val = getPot()->getNextObjIterator(attrhalfseg2D, objg);
        AttrHalfSeg2D *attrhalfsegStaticSucc = nullptr;
        if (val != nullptr) {
            attrhalfsegStaticSucc = new AttrHalfSeg2D();
            *attrhalfsegStaticSucc = *(*val);
        }
        else {
            attrhalfsegStaticSucc = nullptr;
        }

        //Dynamic
//        dynamicEPSObjG.DeleteMin();
//        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjG.GetMin();
//        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
//        dynamicEPSObjG.Insert(attrhalfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = attrhalfsegDynSucc.halfsegment //change later
        AttrHalfSeg2D *attrhalfsegDynSucc = nullptr;
        if (!dynamicEPSObjG.isEmpty()) {
            attrhalfsegDynSucc = new AttrHalfSeg2D();
            *attrhalfsegDynSucc = dynamicEPSObjG.GetNext(attrhalfseg2D);
        }

        if (attrhalfsegStaticSucc == nullptr && attrhalfsegDynSucc == nullptr) {
            return false;
        }

        if ((attrhalfsegStaticSucc != nullptr && attrhalfsegDynSucc == nullptr) ||
            (*attrhalfsegStaticSucc <= *attrhalfsegDynSucc)) {
            bool isDirGiven = attrhalfseg2D.hseg.isLeft;
            bool isDirSucc = (*attrhalfsegStaticSucc).hseg.isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.hseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.hseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*attrhalfsegStaticSucc).hseg.seg.p1;
            }
            else {
                dpSucc = (*attrhalfsegStaticSucc).hseg.seg.p2;
            }

            if (dpGiven == (dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }
        else if ((attrhalfsegStaticSucc == nullptr && attrhalfsegDynSucc != nullptr) ||
                 (*attrhalfsegDynSucc > *attrhalfsegStaticSucc)) {
            bool isDirGiven = attrhalfseg2D.hseg.isLeft;
            bool isDirSucc = (*attrhalfsegDynSucc).hseg.isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.hseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.hseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = (*attrhalfsegDynSucc).hseg.seg.p1;
            }
            else {
                dpSucc = (*attrhalfsegDynSucc).hseg.seg.p2;
            }

            if (dpGiven == (dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }

    }
}

void PlaneSweep::updateSweepLineStatus(Seg2D &segmentToBeReplaced, Seg2D &segmentToReplaceWith) {
//    sweepLineStatus->deleteKey(segmentToBeReplaced);
//    PlaneSweepLineStatusObject obj(segmentToReplaceWith);
//    sweepLineStatus->insert(obj);// should it be key??

    /*
     * Updating the previous code (commented above) with
     * the recursive version so that newly split lines could also be split
     * if required.
     */
    PlaneSweepLineStatusObject sweepLineStatusObjectToBeReplaced(segmentToBeReplaced);
    delRight(sweepLineStatusObjectToBeReplaced);
    PlaneSweepLineStatusObject sweepLineStatusObjectToReplaceWith(segmentToReplaceWith);
    addLeft(sweepLineStatusObjectToReplaceWith);
}

bool PlaneSweep::poiOnSeg(Poi2D &poi2D) {
    int itr = 0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    //AVLnode<PlaneSweepLineStatusObject> *segArray[treeSize] = {};
    PlaneSweepLineStatusObject **segArray;
    sweepLineStatus->getElements(segArray);

    for (itr = 0; itr < treeSize; itr++) {

        Seg2D seg2D = segArray[itr]->getSegment2D();
        if (PointLiesOnSegment(poi2D, seg2D)) {
            return true;
        }
    }
    return false;
}

PlaneSweepLineStatusObject PlaneSweep::getPredecessor(PlaneSweepLineStatusObject &s) {
    PlaneSweepLineStatusObject planeSweepLineStatusObject;
    AVLnode<PlaneSweepLineStatusObject> *predecessor = sweepLineStatus->getPred(s);
    if (predecessor != NULL) {
        return predecessor->key;
    }
    else {
        return planeSweepLineStatusObject;
    }
}

PlaneSweepLineStatusObject PlaneSweep::getSuccessor(PlaneSweepLineStatusObject &s) {
    PlaneSweepLineStatusObject planeSweepLineStatusObject;
    AVLnode<PlaneSweepLineStatusObject> *successor = sweepLineStatus->getSucc(s);
    if (successor != NULL) {
        return successor->key;
    }
    else {
        return planeSweepLineStatusObject;
    }
}

void PlaneSweep::newSweep() {
    sweepLineStatus = new AVLTree<PlaneSweepLineStatusObject>();//Not sure if it is passed like this
}
