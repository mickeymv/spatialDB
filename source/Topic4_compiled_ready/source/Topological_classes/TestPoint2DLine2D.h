//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTPOINT2DLINE2D_H
#define TOPOLOGICAL_CLASSES_TESTPOINT2DLINE2D_H

#include "TopologicalRelationships.h"
#include "vector"


class TestPoint2DLine2D {


public:
    TestPoint2DLine2D() { }

    virtual ~TestPoint2DLine2D() { }

    void start();

private:

    string topPredNumberPoint2DLine2D[TopPredNumberPoint2DLine2DEnumSize] =
            {
                    "pl_disjoint_m1", "pl_disjoint_m2", "pl_meet_m3", "pl_meet_m4", "pl_meet_m5",
                    "pl_meet_m6", "pl_inside_m7", "pl_inside_m8", "pl_overlap_m9", "pl_overlap_m10",
                    "pl_inside_m11", "pl_inside_m12", "pl_overlap_m13", "pl_overlap_m14"
            };


    void printPredicate(TopPredNumberPoint2DLine2D tpred) {

        cout << "   getTopologicalRelationship(a, b) ==> " ;
        cout << topPredNumberPoint2DLine2D[(unsigned int) tpred] << endl << endl;
    };

    string printBool(bool result) {
        return result ? "true": "false";
    }


};


#endif //TOPOLOGICAL_CLASSES_TESTPOINT2DLINE2D_H
