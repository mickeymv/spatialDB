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

void PlaneSweep::setSegClass(Seg2D seg, int lOrR, int uOrL){
	PlaneSweepLineStatusObject *psso = 
					new PlaneSweepLineStatusObject(seg);
	AVLNode<PlaneSweepLineStatusObject> *node = 
								sweepLineStatus->FindKey(psso);
	node->setSegmentClass(lOrR, uOrL);
	node = NULL;
	psso = NULL;
}

void PlaneSweep::setInsideAbove(Seg2D seg, bool ia){
	PlaneSweepLineStatusObject *psso = 
					new PlaneSweepLineStatusObject(seg);
	AVLNode<PlaneSweepLineStatusObject> *node = 
								sweepLineStatus->FindKey(psso);
	node->setInsideAbove(ia);
	node = NULL;
	psso = NULL;
}

SegmentClass PlaneSweep::getSegClass(Seg2D seg){
	PlaneSweepLineStatusObject *psso = 
					new PlaneSweepLineStatusObject(seg);
	AVLNode<PlaneSweepLineStatusObject> *node = 
								sweepLineStatus->FindKey(psso);
	SegmentClass sc = node->getSegmentClass();
	node = NULL;
	psso = NULL;
	return sc;
}

bool PlaneSweep::getInsideAbove(Seg2D seg){
	PlaneSweepLineStatusObject *psso = 
					new PlaneSweepLineStatusObject(seg);
	AVLNode<PlaneSweepLineStatusObject> *node = 
								sweepLineStatus->FindKey(psso);
	bool ia = node->getInsideAbove();
	node = NULL;
	psso = NULL;
	return ia;
}

int PlaneSweep::findLeast() {
    objS = getPot->getNextMin();
    objD1 = dynamicEPSObjF->GetMin();
    objD2 = dynamicEPSObjG->GetMin();
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
		
		objD1 = dynamicEPSObjF->GetMin();
		objD2 = dynamicEPSObjG->GetMin();
		if (objD1 < objD2) {
			dynamicEPSObjF->DeleteMin();
		} else {
			dynamicEPSObjG->DeleteMin();
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
    if (calculateRelation(seg2D)) {
        /* This means there is an overlap/colleanearity
            with the added segment and segments already in
            sweepLineStatus. If so, calculateRelation()
            would automatically add the segment to the
            sweepLineStatus after doing the necessary splits.
         */
         return;
    } else {
        sweepLineStatus->insert(seg2D);
    }
}

void PlaneSweep::delRight(Seg2D &seg2D) {
        sweepLineStatus->deleteKey(seg2D);
}
bool PlaneSweep::coincident(Seg2D &givenSeg)
{
    int itr=0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    seg2D* segArray[] = sweepLineStatus->getElements();

    for(itr=o;itr<treeSize;itr++){

        if(Intersects(segArray(itr), givenSeg))
        return true;
    }
    return false;

}

Seg2D& PlaneSweep::predOfP(Poi2D &p){
    int itr=0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    seg2D* segArray[] = sweepLineStatus->getElements();
    for(itr=o;itr<treeSize;itr++) {
        poi2D *Ipoint = IntersectionPoint(segArray(itr),sweepLineStatus->getPred());
        if(Ipoint.y<p.y)
            return segArray(itr);
    }

}

bool PlaneSweep::predExists(Seg2D &seg2D) {
    PlaneSweepLineStatusObject sweepLineStatusObject(seg2D);
    AVLnode *nodeInSweepLineStatus = sweepLineStatus->FindKey(sweepLineStatusObject);
    if (nodeInSweepLineStatus != NULL && nodeInSweepLineStatus->left != NULL) {
        return true;
    }
    return false;
}

SegmentClass PlaneSweep::getPredSegmentClass(Seg2D seg2D) {
    AVLnode *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getSegmentClass();
}

bool getPredInsideAbove(Seg2D) {
    AVLnode *pred = sweepLineStatus->getPred(seg2D);
    PlaneSweepLineStatusObject predObject = pred->key;
    return predObject.getInsideAbove();
}

bool PlaneSweep::calculateRelation(Seg2D &seg2D) {
//change the name of the variable from seg2D
    Seg2D &pred = getPredecessor(seg2D);
    Seg2D &succ = getSuccessor(seg2D);

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
        (IsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) ||
        (LiesOn(firstSegment, secondSegment) && IsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
         IsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) ||
        (IsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) ||
        (LiesOn(firstSegment, secondSegment) && IsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
         IsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (IsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) ||
        (LiesOn(secondSegment, firstSegment) && IsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
         IsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) ||
        (IsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) ||
        (IsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment))) {
        return true;
    }
    return false;
}

void PlaneSweep::splitLines(Seg2D &firstSegment, Seg2D &secondSegment) {
    if (Intersects(firstSegment, secondSegment)) {
        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {
            Poi2D mp = IntersectionPoint(firstSegment, secondSegment);
            Seg2D S11(firstSegment.p1, mp);
            Seg2D S21(secondSegment.p1, mp);
            Seg2D S12(mp, firstSegment.p2);
            Seg2D S22(mp, secondSegment.p2);

            updateSweepLineStatus(firstSegment, S11);
            updateSweepLineStatus(secondSegment, S21);

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());

            if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
            }
            else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
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

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {
            if (LiesOnRightEndPointOfSegment(tp, secondSegment)) {
                Seg2D S12(tp, firstSegment.p2);
                AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
                AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
                AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());
                AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());

                if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                    dynamicEPSObjF.Insert(attrHalfSeg11Right);
                    dynamicEPSObjF.Insert(attrHalfSeg12Left);
                    dynamicEPSObjF.Insert(attrHalfSeg12Right);
                    dynamicEPSObjG.Insert(attrHalfSeg21Right);
                }
                else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
                    dynamicEPSObjG.Insert(attrHalfSeg11Right);
                    dynamicEPSObjG.Insert(attrHalfSeg12Left);
                    dynamicEPSObjG.Insert(attrHalfSeg12Right);
                    dynamicEPSObjF.Insert(attrHalfSeg21Right);
                }

            }
            else if (LiesOnRightEndPointOfSegment(tp, firstSegment)) {
                Seg2D S22(tp, secondSegment.p2);
                AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
                AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
                AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
                AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());

                if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                    dynamicEPSObjG.Insert(attrHalfSeg21Right);
                    dynamicEPSObjG.Insert(attrHalfSeg22Left);
                    dynamicEPSObjG.Insert(attrHalfSeg22Right);
                    dynamicEPSObjF.Insert(attrHalfSeg11Right);
                }
                else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
                    dynamicEPSObjF.Insert(attrHalfSeg21Right);
                    dynamicEPSObjF.Insert(attrHalfSeg22Left);
                    dynamicEPSObjF.Insert(attrHalfSeg22Right);
                    dynamicEPSObjG.Insert(attrHalfSeg11Right);
                }
            }
        }
    }
    else if (IsCollinearAndMeetsLeftEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S11);
        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());

            if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg11Right); // Is it required?? Should it be S21??
            }
            else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg11Right); // Is it required?? Should it be S21??
            }

        }
    }
    else if (IsCollinearAndMeetsLeftEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(secondSegment, S21);
        updateSweepLineStatus(firstSegment, S21);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());

            if (isInObjF(secondSegment) && isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg21Right); // Is it required?? Should it be S11??
            }
            else if (isInObjG(secondSegment) && isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg21Right); // Is it required?? Should it be S11??
            }

        }
    }
    else if (LiesOn(firstSegment, secondSegment) && IsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
             IsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);
        Seg2D S13(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg13Left = new AttrHalfSeg2D(S13.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg13Right = new AttrHalfSeg2D(S13.ComputeRightHalfSegment());

            if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg13Left);
                dynamicEPSObjF.Insert(attrHalfSeg13Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }
            else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
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
    else if (LiesOn(secondSegment, firstSegment) && IsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
             IsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);
        Seg2D S23(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg23Left = new AttrHalfSeg2D(S23.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg23Right = new AttrHalfSeg2D(S23.ComputeRightHalfSegment());

            if (isInObjF(secondSegment) && isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg23Left);
                dynamicEPSObjF.Insert(attrHalfSeg23Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
            }
            else if (isInObjG(secondSegment) && isInObjF(firstSegment)) {
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
    else if (IsCollinearAndMeetsRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());

            if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }
            else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg11Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left); // Is it required?? Should it be S22??
                dynamicEPSObjF.Insert(attrHalfSeg12Right); // Is it required?? Should it be S22??
            }

        }

    }
    else if (IsCollinearAndMeetsRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());

            if (isInObjF(secondSegment) && isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
            }
            else if (isInObjG(secondSegment) && isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left); // Is it required?? Should it be S12??
                dynamicEPSObjF.Insert(attrHalfSeg22Right); // Is it required?? Should it be S12??
            }

        }
    }
    else if (LiesOn(firstSegment, secondSegment) && IsCollinearAndCrossesLeftEndpoint(secondSegment, firstSegment) &&
             IsCollinearAndCrossesRightEndpoint(firstSegment, secondSegment)) {
        Seg2D S11(firstSegment.p1, secondSegment.p1);
        Seg2D S12(secondSegment.p1, firstSegment.p2);
        Seg2D S22(firstSegment.p2, secondSegment.p2);

        updateSweepLineStatus(firstSegment, S11);
        updateSweepLineStatus(secondSegment, S12);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg11Right = new AttrHalfSeg2D(S11.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());

            if (isInObjF(firstSegment) && isInObjG(secondSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg11Right);
                dynamicEPSObjF.Insert(attrHalfSeg12Left);
                dynamicEPSObjF.Insert(attrHalfSeg12Right);
                dynamicEPSObjG.Insert(attrHalfSeg12Left); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg12Right); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
            }
            else if (isInObjG(firstSegment) && isInObjF(secondSegment)) {
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
    else if (LiesOn(secondSegment, firstSegment) && IsCollinearAndCrossesLeftEndpoint(firstSegment, secondSegment) &&
             IsCollinearAndCrossesRightEndpoint(secondSegment, firstSegment)) {
        Seg2D S21(secondSegment.p1, firstSegment.p1);
        Seg2D S22(firstSegment.p1, secondSegment.p2);
        Seg2D S12(secondSegment.p2, firstSegment.p2);

        updateSweepLineStatus(firstSegment, S22);
        updateSweepLineStatus(secondSegment, S21);

        if ((isInObjF(firstSegment) && isInObjG(secondSegment)) ||
            (isInObjG(firstSegment) && isInObjF(secondSegment))) {

            AttrHalfSeg2D attrHalfSeg21Right = new AttrHalfSeg2D(S21.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Left = new AttrHalfSeg2D(S22.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg22Right = new AttrHalfSeg2D(S22.ComputeRightHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Left = new AttrHalfSeg2D(S12.ComputeLeftHalfSegment());
            AttrHalfSeg2D attrHalfSeg12Right = new AttrHalfSeg2D(S12.ComputeRightHalfSegment());

            if (isInObjF(secondSegment) && isInObjG(firstSegment)) {
                dynamicEPSObjF.Insert(attrHalfSeg21Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left);
                dynamicEPSObjF.Insert(attrHalfSeg22Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg22Right); // Is it required?? Should it be S21??
                dynamicEPSObjG.Insert(attrHalfSeg12Left);
                dynamicEPSObjG.Insert(attrHalfSeg12Right);
            }
            else if (isInObjG(secondSegment) && isInObjF(firstSegment)) {
                dynamicEPSObjG.Insert(attrHalfSeg21Right);
                dynamicEPSObjG.Insert(attrHalfSeg22Left);
                dynamicEPSObjG.Insert(attrHalfSeg22Right);
                dynamicEPSObjF.Insert(attrHalfSeg22Left); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg22Right); // Is it required?? Should it be S21??
                dynamicEPSObjF.Insert(attrHalfSeg11Left);
                dynamicEPSObjF.Insert(attrHalfSeg11Left);
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
    poi2DStatic = val->operator*();


    //Get Dynamic point
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSegDynamic = dynamicEPSObjF.GetMin();
        halfSeg2D = attrHalfSegDynamic.HalfSeg2D(); //TODO: update with HalfSeg getter of AttrHalfSeg
        bool isLeft = halfSeg2D.isLeft;
        if (isLeft) {
            poi2DDynamic = halfSeg2D.seg.p1;
        } else {
            poi2DDynamic = halfSeg2D.seg.p2;
        }


    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSegDynamic = dynamicEPSObjG.GetMin();
        halfSeg2D = attrHalfSegDynamic.HalfSeg2D();
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
    halfSeg2DStatic = val->operator*();


    //Get Dynamic halfSeg
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSegDynamic = dynamicEPSObjF.GetMin();
        halfSeg2DDynamic = attrHalfSegDynamic.HalfSeg2D(); //TODO: update with HalfSeg getter of AttrHalfSeg




    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSegDynamic = dynamicEPSObjG.GetMin();
        halfSeg2DDynamic = attrHalfSegDynamic.HalfSeg2D();


    }

    halfSeg2D = (halfSeg2DDynamic <= halfSeg2DStatic) ? halfSeg2DDynamic : halfSeg2DStatic;
    return halfSeg2D;
}


AttrHalfSeg2D PlaneSweep::getAttrHalfSegEvent(ParallelObjectTraversal::object objectValue) {
    AttrHalfSeg2D attrHalfSeg2D, attrHalfSeg2DStatic, attrHalfSeg2DDynamic;
//Get static HalfSeg2D
    ObjectIterator *pos = getPot()->getObjIterator(objectValue);
    Line2D::ConstSegIterator *val = dynamic_cast<Line2D::ConstSegIterator *>(pos);
    attrHalfSeg2DStatic = val->operator*();  //TODO: ASk to Group2 for attrhalfseg2d iterator


    //Get Dynamic point
    if (objectValue == ParallelObjectTraversal::first) {

        attrHalfSeg2DDynamic = dynamicEPSObjF.GetMin();


    } else if (objectValue == ParallelObjectTraversal::second) {
        attrHalfSeg2DDynamic = dynamicEPSObjG.GetMin();

    }

    attrHalfSeg2D = (attrHalfSeg2DDynamic <= attrHalfSeg2DStatic) ? attrHalfSeg2DDynamic : attrHalfSeg2DStatic;
    return attrHalfSeg2D;
}


bool PlaneSweep::poiInSeg(Poi2D & poi2D) {
    int itr=0;
    int treeSize = sweepLineStatus->sizeOfAVL();

    seg2D* segArray[] = sweepLineStatus->getElements();

    for(itr=o;itr<treeSize;itr++){

        if(PointLiesOnSegment(poi2D, segArray(itr)))
            return true;
    }
    return false;
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