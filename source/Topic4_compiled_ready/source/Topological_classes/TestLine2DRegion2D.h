//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTLINE2DREGION2D_H
#define TOPOLOGICAL_CLASSES_TESTLINE2DREGION2D_H

#include "TopologicalRelationships.h"
#include "vector"

class TestLine2DRegion2D {


public:
    virtual ~TestLine2DRegion2D() { }

    TestLine2DRegion2D() { }

    void start();

private:


    string topPredNumberLine2DRegion2D[TopPredNumberLine2DRegion2DEnumSize] =
            {
                    "lr_disjoint_m1", "lr_disjoint_m2", "lr_meet_m3", "lr_meet_m4", "lr_meet_m5",
                    "lr_meet_m6", "lr_meet_m7", "lr_meet_m8", "lr_meet_m9", "lr_meet_m10", "lr_meet_m11",
                    "lr_meet_m12", "lr_meet_m13", "lr_inside_m14", "lr_coveredby_m15", "lr_inside_m16",
                    "lr_coveredby_m17", "lr_overlap_m18", "lr_overlap_m19", "lr_overlap_m20",
                    "lr_overlap_m21", "lr_overlap_m22", "lr_overlap_m23", "lr_overlap_m24",
                    "lr_overlap_m25", "lr_inside_m26", "lr_inside_m27", "lr_coveredby_m28",
                    "lr_inside_m29", "lr_inside_m30", "lr_coveredby_m31", "lr_overlap_m32",
                    "lr_overlap_m33", "lr_overlap_m34", "lr_overlap_m35", "lr_overlap_m36",
                    "lr_overlap_m37", "lr_overlap_m38", "lr_overlap_m39", "lr_overlap_m40",
                    "lr_overlap_m41", "lr_overlap_m42", "lr_overlap_m43"
            };


    void printLine2DRegion2DPredicate(TopPredNumberLine2DRegion2D tpred) {
        cout << topPredNumberLine2DRegion2D[(unsigned int) tpred] << " <===";
    };

};


#endif //TOPOLOGICAL_CLASSES_TESTLINE2DREGION2D_H
