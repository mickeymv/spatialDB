//
// Created by Djundi on 11/3/15.
//



#include "ParallelObjectTraversal.h"

// *** begin test temp
using namespace std;
#include <iostream>
#include "Test2D.h"
// *** end test temp

ParallelObjectTraversal::ParallelObjectTraversal(Object2D &F, Object2D &G) {

    POT_Point2DPoint2D *pp;
    POT_Point2DLine2D *pl;
    POT_Point2DRegion2D *pr;
    POT_Line2DLine2D *ll;
    POT_Line2DRegion2D *lr;
    POT_Region2DRegion2D *rr;


    // *** begin test temp
    POT_Test2DPoint2D *tp;
    if (F.isTest2D() && G.isPoint2D()) {
        tp = new POT_Test2DPoint2D(F, G);
        cout << tp->getFoo(3) << " Foo OK!!   \n";
    }
    // *** end test temp

    if (F.isPoint2D()) {
        if (G.isPoint2D()) {
            pp = new POT_Point2DPoint2D(F, G);
        } else if (G.isLine2D()) {
            pl = new POT_Point2DLine2D(F, G);
        } else if (G.isRegion2D()) {
            pr = new POT_Point2DRegion2D(F, G);
        }
    } else
    if (F.isLine2D()) {
        if (G.isPoint2D()) {
            pl = new POT_Point2DLine2D(G, F);
        } else if (G.isLine2D()) {
            ll = new POT_Line2DLine2D(F, G);
        } else if (G.isRegion2D()) {
            lr = new POT_Line2DRegion2D(F, G);
        }
    } else
    if (F.isRegion2D()) {
        if (G.isPoint2D()) {
            pr = new POT_Point2DRegion2D(G, F);
        } else if (G.isLine2D()) {
            lr = new POT_Line2DRegion2D(G, F);
        } else if (G.isRegion2D()) {
            rr = new POT_Region2DRegion2D(F, G);
        }
    }


}
