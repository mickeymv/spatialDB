//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTREGION2DREGION2D_H
#define TOPOLOGICAL_CLASSES_TESTREGION2DREGION2D_H


#include "TopologicalRelationships.h"
#include "vector"


class TestRegion2DRegion2D {

public:
    TestRegion2DRegion2D(){};

    virtual ~TestRegion2DRegion2D(){};

    void start();

private:

    string topPredNumberRegion2DRegion2D[TopPredNumberRegion2DRegion2DEnumSize] =
            {
                    "rr_disjoint_m1", "rr_meet_m2", "rr_meet_m3", "rr_meet_m4", "rr_equal_m5",
                    "rr_coveredby_m6", "rr_inside_m7", "rr_coveredby_m8", "rr_coveredby_m9",
                    "rr_overlap_m10", "rr_covers_m11", "rr_overlap_m12", "rr_overlap_m13",
                    "rr_overlap_m14", "rr_overlap_m15", "rr_overlap_m16", "rr_overlap_m17",
                    "rr_overlap_m18", "rr_contains_m19", "rr_overlap_m20", "rr_covers_m21",
                    "rr_overlap_m22", "rr_overlap_m23", "rr_covers_m24", "rr_overlap_m25",
                    "rr_overlap_m26", "rr_overlap_m27", "rr_overlap_m28", "rr_overlap_m29",
                    "rr_overlap_m30", "rr_overlap_m31", "rr_overlap_m32", "rr_overlap_m33"
            };



    inline void printRegion2DRegion2DPredicate(TopPredNumberRegion2DRegion2D tpred) {
        cout << topPredNumberRegion2DRegion2D[(unsigned int) tpred] << " <===";
    };
};


#endif //TOPOLOGICAL_CLASSES_TESTREGION2DREGION2D_H

