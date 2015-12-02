//
// Created by Djundi on 10/10/15.
//

#include "TopologicalRelationships.h"



//Topological Relationship between a point2D object and a point2D object


TopPredNumberPoint2DPoint2D exploreTopologicalRelationship(const Point2D& lhs, const Point2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DPoint2D predicate;
    predicate = TopPredNumberPoint2DPoint2D::pp_disjoint_m1;
    //::pp_disjointCluster_m1;

    //Implementation

    return predicate;

}

bool isTopologicalRelationship(const Point2D& lhs, const Point2D& rhs, TopPredNumberPoint2DPoint2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a point2D object and a line2D object */

typedef enum {
    poi_disjoint,poi_on_interior,poi_on_bound
}vFPoint2DLine2DPredicates;

typedef enum {
    bound_poi_disjoint
}vGPoint2DLine2DPredicates;

void Explore(const Point2D &lhs, const Line2D &rhs, bool *vF, bool *vG);

void Evaluate(const Point2D& lhs, const Line2D& rhs, bool* vF, bool* vG, TopPredNumberPoint2DLine2D* predicate);

TopPredNumberPoint2DLine2D exploreTopologicalRelationship(const Point2D& lhs, const Line2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicate;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicate);

    return *predicate;

}

bool isTopologicalRelationship(const Point2D& lhs, const Line2D& rhs, TopPredNumberPoint2DLine2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate= false;

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicateTest;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicateTest);

    if(*predicateTest==predicate)
    {
        isPredicate=true;
    }
    return isPredicate;

}

/* Topological Relationship between a point2D object and a region2D object */

TopPredNumberPoint2DRegion2D exploreTopologicalRelationship(const Point2D& lhs, const Region2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DRegion2D predicate;

    //Implementation

    return predicate;

}

bool isTopologicalRelationship(const Point2D& lhs, const Region2D& rhs, TopPredNumberPoint2DRegion2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a line2D object and a line2D object */

TopPredNumberLine2DLine2D exploreTopologicalRelationship(const Line2D& lhs, const Line2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberLine2DLine2D predicate;

    //Implementation

    return predicate;


}

bool isTopologicalRelationship(const Line2D& lhs, const Line2D& rhs, TopPredNumberLine2DLine2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a line2D object and a region2D object */

TopPredNumberLine2DRegion2D exploreTopologicalRelationship(const Line2D& lhs, const Region2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberLine2DRegion2D predicate;

    //Implementation

    return predicate;

}

bool isTopologicalRelationship(const Line2D& lhs, const Region2D& rhs, TopPredNumberLine2DRegion2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/* Topological Relationship between a region2D object and a region2D object */

TopPredNumberRegion2DRegion2D exploreTopologicalRelationship(const Region2D& lhs, const Region2D& rhs){

    //Define predicate as an integer/matrix number
    TopPredNumberRegion2DRegion2D predicate;

    //Implementation

    return predicate;


}

bool isTopologicalRelationship(const Region2D& lhs, const Region2D& rhs, TopPredNumberRegion2DRegion2D predicate){

    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Point2D object
bool overlap(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Point2D& lhs, const Point2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Line2D object
bool overlap(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicate;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicate);

    if( *predicate ==TopPredNumberPoint2DLine2D:: pl_overlap_m9||*predicate ==TopPredNumberPoint2DLine2D:: pl_overlap_m10||*predicate ==TopPredNumberPoint2DLine2D:: pl_overlap_m13||*predicate ==TopPredNumberPoint2DLine2D:: pl_overlap_m14)
    {
        isPredicate = true;
    }

    return isPredicate;

}

bool disjoint(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicate;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicate);

    if(*predicate == TopPredNumberPoint2DLine2D:: pl_disjoint_m1||*predicate == TopPredNumberPoint2DLine2D:: pl_disjoint_m2)
    {
        isPredicate = true;
    }

    return isPredicate;

}

bool touch(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicate;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicate);

    if(*predicate ==TopPredNumberPoint2DLine2D:: pl_meet_m3||*predicate ==TopPredNumberPoint2DLine2D:: pl_meet_m4||*predicate ==TopPredNumberPoint2DLine2D:: pl_meet_m5||*predicate ==TopPredNumberPoint2DLine2D:: pl_meet_m6)
    {
        isPredicate = true;
    }

    return isPredicate;

}

bool equal(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Point2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate = false;

    //Define predicate as an integer/matrix number
    TopPredNumberPoint2DLine2D* predicate;

    static const int vF_size=3;
    static const int vG_size=1;
    bool vF[vF_size];
    bool vG[vG_size];

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

    Explore(lhs, rhs, vF, vG);
    Evaluate(lhs, rhs, vF, vG, predicate);

    if(*predicate == TopPredNumberPoint2DLine2D:: pl_inside_m7||*predicate == TopPredNumberPoint2DLine2D:: pl_inside_m8||*predicate == TopPredNumberPoint2DLine2D:: pl_inside_m11||*predicate == TopPredNumberPoint2DLine2D:: pl_inside_m12)
    {
        isPredicate = true;
    }

    return isPredicate;

}

//Cluster predicates for a Point2D object and a Region2D object
bool overlap(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Point2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Line2D object and a Line2D object
bool overlap(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Line2D& lhs, const Line2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Line2D object and a Region2D object
bool overlap(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Line2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

//Cluster predicates for a Region2D object and a Region2D object
bool overlap(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool disjoint(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool touch(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool equal(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool contains(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool covers(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool coveredBy(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

bool inside(const Region2D& lhs, const Region2D& rhs)
{
    //Define a boolean variable which defines whether the given predicate is a topological relationship between the two spatial objects
    bool isPredicate;

    //Implementation

    return isPredicate;

}

/*Point2DLine2D*/

void Explore(const Point2D &lhs, const Line2D &rhs, bool vF[], bool vG[])
{
//TODO Object should be derived by each of the types
    PlaneSweep S(lhs,rhs);
    S.newSweep();
    Poi2D last_dp;

    while((S.getStatus()!=ParallelObjectTraversal::end_of_second)&&(S.getStatus()!=ParallelObjectTraversal::end_of_both)&&(!(vF[poi_disjoint]&&vF[poi_on_interior]&&vF[poi_on_bound]&&vG[bound_poi_disjoint])))
    {
        ParallelObjectTraversal::object object_value = S.getObject();
        if(object_value==ParallelObjectTraversal::first)
        {
            Poi2D p = S.getPoiEvent(ParallelObjectTraversal::first);
            if(S.poiInSeg(p))
            {
                vF[vFPoint2DLine2DPredicates::poi_on_interior]= true;
            }
            else
            {
                vF[vFPoint2DLine2DPredicates::poi_disjoint]=true;
            }
        }
        else if(object_value==ParallelObjectTraversal::second)
        {
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if(h.isLeft)
            {
                S.addLeft(h.seg);
                dp=h.seg.p1;
            }
            else
            {
                S.delRight(h.seg);
                dp=h.seg.p2;
            }
            if(dp!=last_dp)
            {
                last_dp=dp;
            }
            if(!S.lookAhead(h,rhs))
            {
                vG[vGPoint2DLine2DPredicates::bound_poi_disjoint]= true;
            }
        }
        else if(object_value==ParallelObjectTraversal::both)
        {
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if(h.isLeft)
            {
                S.addLeft(h.seg);
                dp=h.seg.p1;
            }
            else
            {
                S.delRight(h.seg);
                dp=h.seg.p2;
            }
            last_dp=dp;
            if(S.lookAhead(h,rhs))
            {
                vF[vFPoint2DLine2DPredicates::poi_on_interior]=true;
            }
            else
            {
                vF[vFPoint2DLine2DPredicates::poi_on_bound]=true;
            }
        }
        S.selectNext();
    }
    if(S.getStatus()==ParallelObjectTraversal::end_of_second)
    {
        vF[vFPoint2DLine2DPredicates::poi_disjoint]=true;
    }
    return; // return true if no error, else false
}

void Evaluate(const Point2D& lhs, const Line2D& rhs, bool* vF, bool* vG, TopPredNumberPoint2DLine2D* predicate)
{
    int IMC[3][3];

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            IMC[i][j]=0;
        }
    }

    if(vF[vFPoint2DLine2DPredicates::poi_on_interior])
    {
        IMC[0][0]=1;
    }
    if(vF[vFPoint2DLine2DPredicates::poi_on_bound])
    {
        IMC[0][1]=1;
    }
    if(vF[vFPoint2DLine2DPredicates::poi_disjoint])
    {
        IMC[0][2]=1;
    }
    IMC[2][0]=1;
    if(vG[vGPoint2DLine2DPredicates::bound_poi_disjoint])
    {
        IMC[2][1]=1;
    }
    IMC[2][2]=1;

    if(IMC[0][0])
    {
        if(IMC[0][1])
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_overlap_m14;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_overlap_m13;
                }
            }
            else
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_inside_m12;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_inside_m11;
                }

            }

        }
        else
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_overlap_m10;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_overlap_m9;
                }
            }
            else
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_inside_m8;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_inside_m7;
                }

            }

        }

    }
    else
    {
        if(IMC[0][1])
        {
            if(IMC[0][2])
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_meet_m6;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_meet_m5;
                }

            }
            else
            {
                if(IMC[2][1])
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_meet_m4;

                }
                else
                {
                    *predicate = TopPredNumberPoint2DLine2D:: pl_meet_m3;
                }

            }
        }
        else
        {
            if(IMC[2][1])
            {
                *predicate = TopPredNumberPoint2DLine2D:: pl_disjoint_m2;

            }
            else
            {
                *predicate = TopPredNumberPoint2DLine2D:: pl_disjoint_m1;
            }
        }
    }
    return;
}


