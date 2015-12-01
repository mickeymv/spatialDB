//
// Created by Djundi on 11/3/15.
//

//test edit


#include "PlaneSweep.h"
#include "ObjectIterator.h"

PlaneSweep::PlaneSweep(Object2D objF, Object2D objG) {
    pot = new ParallelObjectTraversal(objF, objG);
}

PlaneSweep::~PlaneSweep() {
    delete pot;
}

void PlaneSweep::setSegClass(Seg2D seg, int lOrR, int uOrL) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject &> *node =
            sweepLineStatus->FindKey(psso);
    node->key.setSegmentClass(lOrR, uOrL);
    node = NULL;
    delete psso;
}

void PlaneSweep::setInsideAbove(Seg2D seg, bool ia) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject &> *node =
            sweepLineStatus->FindKey(psso);
    node->key.setInsideAbove(ia);
    node = NULL;
    delete psso;
}

SegmentClass PlaneSweep::getSegClass(Seg2D seg) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject &> *node =
            sweepLineStatus->FindKey(psso);
    SegmentClass sc = node->key.getSegmentClass();
    node = NULL;
    delete psso;
    return sc;
}

bool PlaneSweep::getInsideAbove(Seg2D seg) {
    PlaneSweepLineStatusObject psso(seg);
    AVLnode<PlaneSweepLineStatusObject&> *node =
            sweepLineStatus->FindKey(psso);
    bool ia = node->key.getInsideAbove();
    node = NULL;
    delete psso;
    return ia;
}

int PlaneSweep::findLeast() {
    AttrHalfSeg2D objS, objD1, objD2, objD;
    objS = getPot()->getNextMin();
    objD1 = dynamicEPSObjF.GetMin();
    objD2 = dynamicEPSObjG.GetMin();
    objD = (objD1 < objD2) ? (objD1) : (objD2);

    if (objS < objD)
        return 1;
    return 2;

}

void PlaneSweep::selectNext() {
    if (findLeast() == 1) {
        getPot()->selectNext();
    }
    else {
        AttrHalfSeg2D objD, objD1, objD2;

        objD1 = dynamicEPSObjF.GetMin();
        objD2 = dynamicEPSObjG.GetMin();
        if (objD1 < objD2) {
            dynamicEPSObjF.DeleteMin();
        } else {
            dynamicEPSObjG.DeleteMin();
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

void PlaneSweep::addLeft(Seg2D &seg2D) {
    sweepLineStatus->insert(seg2D);

    Seg2D pred = getPredecessor(seg2D);
    Seg2D succ = getSuccessor(seg2D);

    if (isRelation(seg2D, pred)) {
        splitLines(seg2D, pred);
    }
    else if (isRelation(seg2D, succ)) {
        splitLines(seg2D, succ);
    }
}

void PlaneSweep::delRight(Seg2D &seg2D) {
    Seg2D pred = getPredecessor(seg2D);
    Seg2D succ = getSuccessor(seg2D);
    sweepLineStatus->deleteKey(seg2D);
    if (isRelation(pred, succ)) {
        splitLines(pred, succ);
    }
}
//TODO change type of getElements() from AVLtree
bool PlaneSweep::coincident(Seg2D &givenSeg) {
    int itr = 0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    PlaneSweepLineStatusObject *segArray[] = sweepLineStatus->getElements();

    for (itr = 0; itr < treeSize; itr++) {

        if (Intersects(segArray(itr), givenSeg))
            return true;
    }
    return false;

}

Seg2D PlaneSweep::predOfP(Poi2D &p) {
    int itr = 0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    PlaneSweepLineStatusObject *segArray[] = sweepLineStatus->getElements();
    for (itr = 0; itr < treeSize; itr++) {
        Poi2D *Ipoint = IntersectionPoint(segArray(itr), sweepLineStatus->getPred());
        if (Ipoint.y < p.y)
            return segArray(itr);
    }

}

bool PlaneSweep::predExists(Seg2D &seg2D) {
    PlaneSweepLineStatusObject sweepLineStatusObject(seg2D);
    AVLnode<PlaneSweepLineStatusObject &> *nodeInSweepLineStatus = sweepLineStatus->FindKey(sweepLineStatusObject);
    if (nodeInSweepLineStatus != NULL && nodeInSweepLineStatus->left != NULL) {
        return true;
    }
    return false;
}

SegmentClass PlaneSweep::getPredSegmentClass(Seg2D seg2D) {
    AVLnode<PlaneSweepLineStatusObject &> *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getSegmentClass();
}

bool PlaneSweep::getPredInsideAbove(Seg2D seg2D) {
    AVLnode<PlaneSweepLineStatusObject &> *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getInsideAbove();
}

bool PlaneSweep::calculateRelation(Seg2D &seg2D) {
//change the name of the variable from seg2D
    Seg2D pred = getPredecessor(seg2D);
    Seg2D succ = getSuccessor(seg2D);

    if (isRelation(seg2D, pred)) {
        splitLines(seg2D, pred);
        return true;
    }
    else if (isRelation(seg2D, succ)) {
        splitLines(seg2D, succ);
        return true;
    }

    return false;

}

bool PlaneSweep::isRelation(Seg2D &firstSegment, Seg2D &secondSegment) {
    if ((Intersects(firstSegment, secondSegment)) || (Touch(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) ||
        (SegmentLiesOnSegment(firstSegment, secondSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
        SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentLiesOnSegment(firstSegment, secondSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
        SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) ||
        (SegmentLiesOnSegment(secondSegment, firstSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
        SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) ||
        (SegmentIsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment))) {
        return true;
    }
    return false;
}
/*TODO Need to see how ConstSegIterator can be used for pot->isInObjF(Seg2D) and pot->isInObjG(seg2D) and ConstHalsegInterator, ConstAttrHalfsegIterator for getNextObjIterator
 * TODO see how Attributed half segments can be generated
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

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);
            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
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
                AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
                AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
                AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);
                AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);

                if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                    dynamicEPSObjF.Insert(attrHalfSeg11Right);
                    dynamicEPSObjF.Insert(attrHalfSeg12Left);
                    dynamicEPSObjF.Insert(attrHalfSeg12Right);
                    dynamicEPSObjG.Insert(attrHalfSeg21Right);
                }
                else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                    dynamicEPSObjG.Insert(attrHalfSeg11Right);
                    dynamicEPSObjG.Insert(attrHalfSeg12Left);
                    dynamicEPSObjG.Insert(attrHalfSeg12Right);
                    dynamicEPSObjF.Insert(attrHalfSeg21Right);
                }

            }
            else if (PointLiesOnRightEndPointOfSegment(tp, firstSegment)) {
                Seg2D S22(tp, secondSegment.p2);
                AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
                AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
                AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
                AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);

                if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                    dynamicEPSObjG.Insert(attrHalfSeg21Right);
                    dynamicEPSObjG.Insert(attrHalfSeg22Left);
                    dynamicEPSObjG.Insert(attrHalfSeg22Right);
                    dynamicEPSObjF.Insert(attrHalfSeg11Right);
                }
                else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                    dynamicEPSObjF.Insert(attrHalfSeg21Right);
                    dynamicEPSObjF.Insert(attrHalfSeg22Left);
                    dynamicEPSObjF.Insert(attrHalfSeg22Right);
                    dynamicEPSObjG.Insert(attrHalfSeg11Right);
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

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg11Right); // Is it required?? Should it be S21??
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg11Right); // Is it required?? Should it be S21??
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

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg21Right); // Is it required?? Should it be S11??
            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg21Right); // Is it required?? Should it be S11??
            }

        }
    }
    else if (SegmentLiesOnSegment(firstSegment, secondSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
            SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);
        Seg2D S13(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);
            AttrHalfSeg2D attrHalfSeg13Left = new AttrHalfSeg2D(S13.p1);
            AttrHalfSeg2D attrHalfSeg13Right = new AttrHalfSeg2D(S13.p2);

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg13Left);
                dynamicEPSObjF.Insert(attrHalfSeg13Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg13Left);
                dynamicEPSObjG.Insert(attrHalfSeg13Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjF.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }

        }
    }
    else if (SegmentLiesOnSegment(secondSegment, firstSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
            SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);
        Seg2D S23(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);
            AttrHalfSeg2D attrHalfSeg23Left = new AttrHalfSeg2D(S23.p1);
            AttrHalfSeg2D attrHalfSeg23Right = new AttrHalfSeg2D(S23.p2);

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg23Left);
                dynamicEPSObjF.Insert(attrHalfSeg23Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??


            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg23Left);
                dynamicEPSObjG.Insert(attrHalfSeg23Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjF.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
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

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjF.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
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

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjF.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
            }

        }
    }
    else if (SegmentLiesOnSegment(firstSegment, secondSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
            SegmentIsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);

            if (pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
            }
            else if (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg12Right); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
            }

        }


    }
    else if (SegmentLiesOnSegment(secondSegment, firstSegment) && SegmentIsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
            SegmentIsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((pot->isInObjF(firstSegment) && pot->isInObjG(secondSegment)) ||
            (pot->isInObjG(firstSegment) && pot->isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.p2);
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.p1);
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.p2);
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.p1);
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.p2);

            if (pot->isInObjF(secondSegment) && pot->isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
            }
            else if (pot->isInObjG(secondSegment) && pot->isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg22Right); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
            }

        }


    }

}


Poi2D PlaneSweep::getPoiEvent(ParallelObjectTraversal::object objectValue) {
    Poi2D poi2D, poi2DStatic, poi2DDynamic;
    AttrHalfSeg2D attrHalfSegDynamic;
    HalfSeg2D halfSeg2D;
//Get static point
    ObjectIterator *pos = getPot()->getObjIterator(objectValue);
    Point2D::ConstPoiIterator *val = dynamic_cast<Point2D::ConstPoiIterator *>(pos);
    poi2DStatic = *(*val);


    //Get Dynamic point
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSegDynamic = dynamicEPSObjF.GetMin();
        halfSeg2D = attrHalfSegDynamic.hseg;
        bool isLeft = halfSeg2D.isLeft;
        if (isLeft) {
            poi2DDynamic = halfSeg2D.seg.p1;
        } else {
            poi2DDynamic = halfSeg2D.seg.p2;
        }


    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSegDynamic = dynamicEPSObjG.GetMin();
        halfSeg2D = attrHalfSegDynamic.hseg;
        bool isLeft = halfSeg2D.isLeft;
        if (isLeft) {
            poi2DDynamic = halfSeg2D.seg.p1;
        } else {
            poi2DDynamic = halfSeg2D.seg.p2;
        }
    }

    poi2D = (poi2DDynamic <= poi2DStatic) ? poi2DDynamic : poi2DStatic;
    return poi2D;
}

HalfSeg2D PlaneSweep::getHalfSegEvent(ParallelObjectTraversal::object objectValue) {
    HalfSeg2D halfSeg2D, halfSeg2DStatic, halfSeg2DDynamic;
    AttrHalfSeg2D attrHalfSegDynamic;
//Get static HalfSeg2D
    ObjectIterator *pos = getPot()->getObjIterator(objectValue);
    Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(pos);
    halfSeg2DStatic = *(*val);


    //Get Dynamic halfSeg
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSegDynamic = dynamicEPSObjF.GetMin();
        halfSeg2DDynamic = attrHalfSegDynamic.hseg; //TODO: update with HalfSeg getter of AttrHalfSeg




    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSegDynamic = dynamicEPSObjG.GetMin();
        halfSeg2DDynamic = attrHalfSegDynamic.hseg;


    }

    halfSeg2D = (halfSeg2DDynamic <= halfSeg2DStatic) ? halfSeg2DDynamic : halfSeg2DStatic;
    return halfSeg2D;
}


AttrHalfSeg2D PlaneSweep::getAttrHalfSegEvent(ParallelObjectTraversal::object objectValue) {
    AttrHalfSeg2D attrHalfSeg2D, attrHalfSeg2DStatic, attrHalfSeg2DDynamic;
//Get static HalfSeg2D
    ObjectIterator *pos = getPot()->getObjIterator(objectValue);
    Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(pos);
    attrHalfSeg2DStatic = *(*val);  //TODO: ASk to Group2 for attrhalfseg2d iterator


    //Get Dynamic point
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSeg2DDynamic = dynamicEPSObjF.GetMin();


    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSeg2DDynamic = dynamicEPSObjG.GetMin();

    }

    attrHalfSeg2D = (attrHalfSeg2DDynamic <= attrHalfSeg2DStatic) ? attrHalfSeg2DDynamic : attrHalfSeg2DStatic;
    return attrHalfSeg2D;
}

/* TODO Need to update attrHalfSeg implementation after group 1 changes it
 * TODO Need to update code to get next object after a given object in an AVL tree to get dynSucc
 */

bool PlaneSweep::lookAhead(HalfSeg2D & halfseg2D, Line2D & line2D)
{
    Seg2D & seg2D = halfseg2D.seg;
    if(pot->isObjectF(line2D))
    {
        //Static
        ParallelObjectTraversal::object objf = ParallelObjectTraversal::first;
        ObjectIterator *obji = pot->getNextObjIterator(halfseg2D,objf);
        Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(obji);
        HalfSeg2D halfsegStaticSucc;
        if(obji!= nullptr) {
            halfsegStaticSucc = *(*val);
        }
        else
        {
            halfsegStaticSucc = nullptr;
        }

        //Dynamic
        dynamicEPSObjF.DeleteMin();
        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjF.GetMin();
        AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        dynamicEPSObjF.Insert(attrhalfsegReinsert);
        HalfSeg2D halfsegDynSucc = attrhalfsegDynSucc.halfsegment; //change later

        if(halfsegStaticSucc== nullptr&&halfsegDynSucc== nullptr)
        {
            return false;
        }

        if((halfsegStaticSucc!= nullptr&&halfsegDynSucc== nullptr)||(halfsegStaticSucc<halfsegDynSucc ))
        {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = halfsegStaticSucc.isLeft;
            Poi2D dpGiven, dpSucc;

            if(isDirGiven)
            {
                dpGiven = halfseg2D.seg.p1;
            }
            else
            {
                dpGiven = halfseg2D.seg.p2;
            }
            if(isDirSucc)
            {
                dpSucc = halfsegStaticSucc.seg.p1;
            }
            else
            {
                dpSucc = halfsegStaticSucc.seg.p2;
            }

            if(dpGiven==(dpSucc))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((halfsegStaticSucc== nullptr&&halfsegDynSucc!= nullptr)||(halfsegDynSucc>halfsegStaticSucc))
        {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = halfsegDynSucc.isLeft;
            Poi2D dpGiven, dpSucc;

            if(isDirGiven)
            {
                dpGiven = halfseg2D.seg.p1;
            }
            else
            {
                dpGiven = halfseg2D.seg.p2;
            }
            if(isDirSucc)
            {
                dpSucc = halfsegDynSucc.seg.p1;
            }
            else
            {
                dpSucc = halfsegDynSucc.seg.p2;
            }
            if(dpGiven==(dpSucc))
            {
                return true;
            }
            else
            {
                return false;
            }
        }


    }
    else if(pot->isObjectG(line2D))
    {
        //Static
        ParallelObjectTraversal::object objg = ParallelObjectTraversal::second;
        ObjectIterator *obji = pot->getNextObjIterator(halfseg2D,objg);
        Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(obji);
        HalfSeg2D halfsegStaticSucc;
        if(obji!= nullptr) {
            halfsegStaticSucc = *(*val);
        }
        else
        {
            halfsegStaticSucc = nullptr;
        }

        //Dynamic
        dynamicEPSObjG.DeleteMin();
        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjG.GetMin();
        AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        dynamicEPSObjG.Insert(attrhalfsegReinsert);
        HalfSeg2D halfsegDynSucc = attrhalfsegDynSucc.halfsegment; //change later

        if(halfsegStaticSucc== nullptr&&halfsegDynSucc== nullptr)
        {
            return false;
        }

        if((halfsegStaticSucc!= nullptr&&halfsegDynSucc== nullptr)||(halfsegStaticSucc<=( halfsegDynSucc )))
        {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = halfsegStaticSucc.isLeft;
            Poi2D dpGiven, dpSucc;

            if(isDirGiven)
            {
                dpGiven = halfseg2D.seg.p1;
            }
            else
            {
                dpGiven = halfseg2D.seg.p2;
            }
            if(isDirSucc)
            {
                dpSucc = halfsegStaticSucc.seg.p1;
            }
            else
            {
                dpSucc = halfsegStaticSucc.seg.p2;
            }

            if(dpGiven==(dpSucc))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if((halfsegStaticSucc== nullptr&&halfsegDynSucc!= nullptr)||(halfsegDynSucc>(halfsegStaticSucc)))
        {
            bool isDirGiven = halfseg2D.isLeft;
            bool isDirSucc = halfsegDynSucc.isLeft;
            Poi2D dpGiven, dpSucc;

            if(isDirGiven)
            {
                dpGiven = halfseg2D.seg.p1;
            }
            else
            {
                dpGiven = halfseg2D.seg.p2;
            }
            if(isDirSucc)
            {
                dpSucc = halfsegDynSucc.seg.p1;
            }
            else
            {
                dpSucc = halfsegDynSucc.seg.p2;
            }

            if(dpGiven==(dpSucc))
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
}

/* TODO Need to update attrHalfSeg implementation after group 1 changes it
 * TODO Need to update code to get next object after a given object in an AVL tree to get dynSucc
 */

bool PlaneSweep::lookAhead(AttrHalfSeg2D & attrhalfseg2D, Region2D & region2D) {
    Seg2D &seg2D = attrhalfseg2D.halfseg.seg;//Implement when updated
    if(pot->isObjectF(region2D))
    {
        //Static
        ParallelObjectTraversal::object objf = ParallelObjectTraversal::first;
        ObjectIterator *obji = pot->getNextObjIterator(attrhalfseg2D,objf);
        Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(obji);
        AttrHalfSeg2D attrhalfsegStaticSucc;
        if(obji!= nullptr) {
            attrhalfsegStaticSucc = *(*val);

        }
        else
        {
            attrhalfsegStaticSucc = nullptr;
        }

        //Dynamic
        dynamicEPSObjF.DeleteMin();
        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjF.GetMin();
        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        dynamicEPSObjF.Insert(attrhalfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = attrhalfsegDynSucc.halfsegment //change later

        if(attrhalfsegStaticSucc== nullptr&&attrhalfsegDynSucc== nullptr)
        {
            return false;
        }

        if ((attrhalfsegStaticSucc!= nullptr&&attrhalfsegDynSucc== nullptr)||(attrhalfsegStaticSucc<=(attrhalfsegDynSucc))) {
            bool isDirGiven = attrhalfseg2D.halfseg.isLeft;//Implement when updated
            bool isDirSucc = attrhalfsegStaticSucc.halfseg.isLeft;//Implement when updated
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.halfseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.halfseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = attrhalfsegStaticSucc.halfseg.seg.p1;
            }
            else {
                dpSucc = attrhalfsegStaticSucc.halfseg.seg.p2;
            }

            if (dpGiven==(dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }
        else if((attrhalfsegStaticSucc== nullptr&&attrhalfsegDynSucc!= nullptr)||(attrhalfsegDynSucc>(attrhalfsegStaticSucc)))
        {
            bool isDirGiven = attrhalfseg2D.halfseg.isLeft;//Implement when updated
            bool isDirSucc = attrhalfsegDynSucc.halfseg.isLeft;//Implement when updated
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.halfseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.halfseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = attrhalfsegDynSucc.halfseg.seg.p1;
            }
            else {
                dpSucc = attrhalfsegDynSucc.halfseg.seg.p2;
            }
            if (dpGiven==(dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }


    }
    else if(pot->isObjectG(region2D))
    {
        //Static
        ParallelObjectTraversal::object objg = ParallelObjectTraversal::second;
        ObjectIterator *obji = pot->getNextObjIterator(attrhalfseg2D,objg);
        Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(obji);
        AttrHalfSeg2D attrhalfsegStaticSucc;
        if(obji!= nullptr) {
            attrhalfsegStaticSucc = *(*val);
        }
        else
        {
            attrhalfsegStaticSucc = nullptr;
        }

        //Dynamic
        dynamicEPSObjG.DeleteMin();
        AttrHalfSeg2D attrhalfsegDynSucc = dynamicEPSObjG.GetMin();
        //AttrHalfSeg2D attrhalfsegReinsert(halfseg2D);
        dynamicEPSObjG.Insert(attrhalfseg2D);
        //AttrHalfSeg2D attrhalfsegDynSucc = attrhalfsegDynSucc.halfsegment //change later

        if(attrhalfsegStaticSucc== nullptr&&attrhalfsegDynSucc== nullptr)
        {
            return false;
        }

        if ((attrhalfsegStaticSucc!= nullptr&&attrhalfsegDynSucc== nullptr)||(attrhalfsegStaticSucc<=(attrhalfsegDynSucc))) {
            bool isDirGiven = attrhalfseg2D.halfseg.isLeft;//Implement when updated
            bool isDirSucc = attrhalfsegStaticSucc.halfseg.isLeft;//Implement when updated
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.halfseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.halfseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = attrhalfsegStaticSucc.halfseg.seg.p1;
            }
            else {
                dpSucc = attrhalfsegStaticSucc.halfseg.seg.p2;
            }

            if (dpGiven==(dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }
        else if((attrhalfsegStaticSucc== nullptr&&attrhalfsegDynSucc!= nullptr)||(attrhalfsegDynSucc>(attrhalfsegStaticSucc)))
        {
            bool isDirGiven = attrhalfseg2D.halfseg.isLeft;
            bool isDirSucc = attrhalfsegDynSucc.halfseg.isLeft;
            Poi2D dpGiven, dpSucc;

            if (isDirGiven) {
                dpGiven = attrhalfseg2D.halfseg.seg.p1;
            }
            else {
                dpGiven = attrhalfseg2D.halfseg.seg.p2;
            }
            if (isDirSucc) {
                dpSucc = attrhalfsegDynSucc.halfseg.seg.p1;
            }
            else {
                dpSucc = attrhalfsegDynSucc.halfseg.seg.p2;
            }

            if (dpGiven==(dpSucc)) {
                return true;
            }
            else {
                return false;
            }
        }

    }
}

void PlaneSweep::updateSweepLineStatus(Seg2D &segmentToBeReplaced, Seg2D &segmentToReplaceWith)
{
    sweepLineStatus->deleteKey(segmentToBeReplaced);
    PlaneSweepLineStatusObject obj(segmentToReplaceWith);
    sweepLineStatus->insert(obj);// should it be key??
}

bool PlaneSweep::poiOnSeg(Poi2D &poi2D) {
    int itr = 0;
    int treeSize = sweepLineStatus->sizeOfAVL();

//    AVLnode<PlaneSweepLineStatusObject &> temp = sweepLineStatus->getElements();

    AVLnode<PlaneSweepLineStatusObject &> *segArray[treeSize] = {};
//    segArray = sweepLineStatus->getElements();
    sweepLineStatus->getElements(segArray);

    for (itr = 0; itr < treeSize; itr++) {

        if (PointLiesOnSegment(poi2D, segArray[itr]->key.getSegment2D()))
            return true;
    }
    return false;
}

Seg2D PlaneSweep::getPredecessor(Seg2D& s) {
    return sweepLineStatus->getPred(s)->key.getSegment2D();
}
Seg2D PlaneSweep::getSuccessor(Seg2D& s){
    return sweepLineStatus->getSucc(s)->key.getSegment2D();
}

void PlaneSweep::newSweep() {
    sweepLineStatus = new AVLTree<PlaneSweepLineStatusObject &>();//Not sure if it is passed like this
}


/*
*/


/*
 *  Change the following functions based on our discussion on Saturday
 *  11/21/15.
 */


/*


void PlaneSweep::add_left(Seg2D& seg2D)
{
    sweepLineStatus->Insert(seg2D.p1.y,seg2D);
}

void PlaneSweep::del_right(Seg2D& seg2D)
{
    //sweepLineStatus->deleteKey(Seg2D.p2.y,Seg2D);
    sweepLineStatus->Remove(seg2D.p1.y);
}

 */