//
// Aswini Ramesh
//

#ifndef PLANESWEEP_PROJECT_LINE2DLINE2D_H
#define PLANESWEEP_PROJECT_LINE2DLINE2D_H



#include "planesweep_project/Object2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "planesweep_project/PlaneSweep.h"

#include "TopPredNumberEnums.h"



class Line2DLine2D{

public:
    Line2DLine2D(Line2D &F, Line2D &G);
    ~Line2DLine2D();

    //Function to check whether the given spatial predicate holds true
    bool isTopologicalRelationship(TopPredNumberLine2DLine2D predicate);

    //Function to check return  spatial predicate
    TopPredNumberLine2DLine2D getTopologicalRelationship();

    //8 basic spatial predicates based on 9IM
    bool overlap();
    bool disjoint();
    bool meet();
    bool equal();
    bool contains();
    bool covers();
    bool coveredBy();
    bool inside();

private:

    typedef enum {
        seg_shared,interior_poi_shared,seg_unshared,bound_on_interior,bound_shared,bound_disjoint
    }vFLine2DLine2DPredicates;

    typedef enum {
        seg_unshared_VG,bound_on_interior_VG,bound_disjoint_VG
    }vGLine2DLine2DPredicates;

    Line2D objF;
    Line2D objG;
    static const int vF_size=6;
    static const int vG_size=3;

    TopPredNumberLine2DLine2D topPredNumberLine2DLine2D;
    bool isPredSet=false;

    bool vF[vF_size];
    bool vG[vG_size];

    // get vector array vF
    bool *getVF();

    // get vector array vG
    bool *getVG();


    //Exploration function
    void exploreTopoPred();

    //Evaluation function
    void evaluateTopoPred();



};


#endif //PLANESWEEP_PROJECT_LINE2DLINE2D_H
