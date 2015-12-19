//
// Created by Djundi on 12/18/15.
//

#ifndef TOPOLOGICAL_CLASSES_TESTPOINT2DPOINT2D_H
#define TOPOLOGICAL_CLASSES_TESTPOINT2DPOINT2D_H


#include "TopologicalRelationships.h"
#include "vector"

class TestPoint2DPoint2D {


public:
    TestPoint2DPoint2D(){};

    virtual ~TestPoint2DPoint2D(){};

    void start();

private:

    string topPredNumberPoint2DPoint2D[TopPredNumberPoint2DPoint2DEnumSize] =
    {
            "pp_disjoint_m1", "pp_equal_m2", "pp_inside_m3", "pp_contains_m4", "pp_overlap_m5"
    };

    void printPoint2DPoint2DPredicate(TopPredNumberPoint2DPoint2D tpred) {

        cout << "   getTopologicalRelationship(a, b) ==> " ;
        cout << topPredNumberPoint2DPoint2D[(unsigned int) tpred] << endl << endl;
    };

    string printResult(bool result) {
        return result ? "true": "false";
    }


};


#endif //TOPOLOGICAL_CLASSES_TESTPOINT2DPOINT2D_H
