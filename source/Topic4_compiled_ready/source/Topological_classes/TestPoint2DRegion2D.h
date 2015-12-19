//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTPOINT2DREGION2D_H
#define TOPOLOGICAL_CLASSES_TESTPOINT2DREGION2D_H


#include "TopologicalRelationships.h"
#include "vector"



class TestPoint2DRegion2D {


public:
    TestPoint2DRegion2D() { }

    virtual ~TestPoint2DRegion2D() { }

    void start();

private:

    string topPredNumberPoint2DRegion2D[7] =
            {
                    "pr_disjoint_m1", "pr_meet_m2", "pr_meet_m3", "pr_inside_m4", "pr_overlap_m5",
                    "pr_inside_m6", "pr_overlap_m7"
            };


    void printPoint2DRegion2DPredicate(TopPredNumberPoint2DRegion2D tpred) {
        cout << topPredNumberPoint2DRegion2D[(unsigned int) tpred] << " <===";
    };

};


#endif //TOPOLOGICAL_CLASSES_TESTPOINT2DREGION2D_H
