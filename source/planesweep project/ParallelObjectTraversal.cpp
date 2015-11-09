//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

// *** begin test temp
using namespace std;
#include <iostream>
// *** end test temp




ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    // 11/04/2015 DT
    // note that for the symmetrical object combination, only one instance is created, but the passing of the object is swapped accordingly
    if (F.isPoint2D()) {
        if (G.isPoint2D()) {
            ExplorePoint2DPoint2D(F, G);

        } else if (G.isLine2D()) {
            ExplorePoint2DLine2D(F, G);

        } else if (G.isRegion2D()) {
            ExplorePoint2DRegion2D(F, G);
        }
    } else
    if (F.isLine2D()) {
        if (G.isPoint2D()) {
            // swap parameters because it is symmetrical
            ExplorePoint2DLine2D(G, F);

        } else if (G.isLine2D()) {
            ExploreLine2DLine2D(F, G);

        } else if (G.isRegion2D()) {
            ExploreLine2DRegion2D(F, G);
        }
    } else
    if (F.isRegion2D()) {
        if (G.isPoint2D()) {
            // swap parameters because it is symmetrical
            ExplorePoint2DRegion2D(G, F);

        } else if (G.isLine2D()) {
            // swap parameters because it is symmetrical
            ExploreLine2DRegion2D(G, F);

        } else if (G.isRegion2D()) {

            rr = new POT_Region2DRegion2D(F, G);
            vF = rr->getVF();
            vG = rr->getVG();
            sizeofvFG = rr->getVFGSize();

        }
    }


}

ParallelObjectTraversal::~ParallelObjectTraversal() {
    if (pp) delete pp;
    if (pl) delete pl;
    if (pr) delete pr;
    if (ll) delete ll;
    if (lr) delete lr;
    if (rr) delete rr;

}


const bool *ParallelObjectTraversal::getVF() {
    return vF;
}

// get vector array vG
const bool *ParallelObjectTraversal::getVG() {
    return vG;
}

// returns the size of vector F (or vector G, they both have the same size)
const size_t ParallelObjectTraversal::getVFGSize() {
    return sizeofvFG;
}


bool ParallelObjectTraversal::ExplorePoint2DPoint2D(Object2D &F, Object2D &G) {
    // create new instance
    pp = new POT_Point2DPoint2D(F, G);

    // set vF and vG
    vF = pp->getVF();
    vG = pp->getVG();

    // set size of vF (and vG)
    sizeofvFG = pp->getVFGSize();

    // "do while" ... implement "ExplorePoint2DPoint2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExplorePoint2DLine2D(Object2D &F, Object2D &G) {
    // create new instance
    pp = new POT_Point2DPoint2D(F, G);

    // set vF and vG
    vF = pp->getVF();
    vG = pp->getVG();

    // set size of vF (and vG)
    sizeofvFG = pp->getVFGSize();

    // "do while" ... implement "ExplorePoint2DPoint2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExplorePoint2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    pr = new POT_Point2DRegion2D(F, G);

    // set vF and vG
    vF = pr->getVF();
    vG = pr->getVG();

    // set size of vF (and vG)
    sizeofvFG = pr->getVFGSize();

    // "do while" ... implement "ExplorePoint2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreLine2DLine2D(Object2D &F, Object2D &G) {
    // create new instance
    ll = new POT_Line2DLine2D(F, G);

    // set vF and vG
    vF = ll->getVF();
    vG = ll->getVG();

    // set size of vF (and vG)
    sizeofvFG = ll->getVFGSize();

    // "do while" ... implement "ExploreLine2DLine2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreLine2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    lr = new POT_Line2DRegion2D(F, G);

    // set vF and vG
    vF = lr->getVF();
    vG = lr->getVG();

    // set size of vF (and vG)
    sizeofvFG = lr->getVFGSize();

    // "do while" ... implement "ExploreLine2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}

bool ParallelObjectTraversal::ExploreRegion2DRegion2D(Object2D &F, Object2D &G) {
    // create new instance
    rr = new POT_Region2DRegion2D(F, G);

    // set vF and vG
    vF = rr->getVF();
    vG = rr->getVG();

    // set size of vF (and vG)
    sizeofvFG = rr->getVFGSize();

    // "do while" ... implement "ExploreRegion2DRegion2D" algorithm below as described in the paper



    return true; // return true if no error, else false

}