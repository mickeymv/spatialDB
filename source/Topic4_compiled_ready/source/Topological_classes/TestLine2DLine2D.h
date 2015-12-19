//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTLINE2DLINE2D_H
#define TOPOLOGICAL_CLASSES_TESTLINE2DLINE2D_H

#include "TopologicalRelationships.h"
#include "vector"

class TestLine2DLine2D {

public:
    virtual ~TestLine2DLine2D() { }

    TestLine2DLine2D() { }

    void start();

private:

    string topPredNumberLine2DLine2D[TopPredNumberLine2DLine2DEnumSize] =
            {
                    "ll_disjoint_m1", "ll_disjoint_m2", "ll_disjoint_m3", "ll_disjoint_m4",
                    "ll_meet_m5", "ll_meet_m6", "ll_meet_m7", "ll_meet_m8", "ll_meet_m9",
                    "ll_meet_m10", "ll_meet_m11", "ll_meet_m12", "ll_meet_m13", "ll_meet_m14",
                    "ll_meet_m15", "ll_meet_m16", "ll_meet_m17", "ll_meet_m18", "ll_meet_m19",
                    "ll_meet_m20", "ll_meet_m21", "ll_meet_m22", "ll_meet_m23", "ll_meet_m24",
                    "ll_meet_m25", "ll_meet_m26", "ll_meet_m27", "ll_meet_m28", "ll_meet_m29",
                    "ll_meet_m30","ll_meet_m31", "ll_meet_m32", "ll_equal_m33", "ll_inside_m34",
                    "ll_inside_m35", "ll_equal_m36","ll_coveredby_m37", "ll_coveredby_m38",
                    "ll_inside_m39", "ll_inside_m40", "ll_coveredby_m41", "ll_coveredby_m42",
                    "ll_contains_m43", "ll_overlap_m44", "ll_overlap_m45", "ll_contains_m46",
                    "ll_overlap_m47", "ll_overlap_m48", "ll_covers_m49", "ll_overlap_m50",
                    "ll_overlap_m51", "ll_covers_m52", "ll_overlap_m53", "ll_overlap_m54",
                    "ll_overlap_m55", "ll_overlap_m56", "ll_overlap_m57", "ll_overlap_m58",
                    "ll_overlap_m59", "ll_overlap_m60", "ll_overlap_m61", "ll_overlap_m62",
                    "ll_contains_m63", "ll_overlap_m64", "ll_overlap_m65", "ll_contains_m66",
                    "ll_overlap_m67", "ll_overlap_m68", "ll_covers_m69", "ll_overlap_m70",
                    "ll_overlap_m71", "ll_covers_m72", "ll_overlap_m73", "ll_overlap_m74",
                    "ll_overlap_m75", "ll_overlap_m76", "ll_overlap_m77", "ll_overlap_m78",
                    "ll_overlap_m79", "ll_overlap_m80", "ll_overlap_m81", "ll_overlap_m82"

            };

    void printLine2DLine2DPredicate(TopPredNumberLine2DLine2D tpred) {

        cout << topPredNumberLine2DLine2D[(unsigned int) tpred] << " <===";

    };
};


#endif //TOPOLOGICAL_CLASSES_TESTLINE2DLINE2D_H
