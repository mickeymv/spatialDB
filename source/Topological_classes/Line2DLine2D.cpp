
/******************************************************************************
* File: Line2DLine2D.cpp
*******************************************************************************
* Purpose: Implementation of exploration functions and evaluation functions for
*   the topological relationships between two Line2D object.This also contains
 *  clustered predicate verification functions
 *
* Description: Implementation of Exploration and Evaluation algorithms and functions
 * for Topological Predicate Verification and Determination
 *
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors:Group 4 [Michael Kemerer,Tjindra Djundi,Natasha Mandal,Aswini Ramesh,Kyuseo Park]
*
* Date: Fall Semester 2015
******************************************************************************/
#include "Line2DLine2D.h"

Line2DLine2D::Line2DLine2D(Line2D &F, Line2D &G) {

    // set obj1 and obj2
    objF=F;
    objG=G;

    // initialize vF and vG with false
    for (int i = 0; i<vF_size; i++) {
        vF[i] = false;
    }

    for (int i=0; i<vG_size; i++)
    {
        vG[i] = false;
    }

}
Line2DLine2D::~Line2DLine2D() { };


bool *Line2DLine2D::getVF() {
    return vF;
}

bool *Line2DLine2D::getVG() {
    return vG;
}

void Line2DLine2D::exploreTopoPred() {
    //TODO Object should be derived by each of the types
    PlaneSweep S(objF, objG);
    S.newSweep();
    Poi2D last_dp_f;
    Poi2D last_dp_g;
    Poi2D last_bound_in_g;
    Poi2D last_bound_in_f;

    while ((S.getStatus() != ParallelObjectTraversal::end_of_second) && (!(vF[seg_shared] && vF[interior_poi_shared] && vF[seg_unshared] &&vF[bound_on_interior]&&vF[bound_shared]&&vF[bound_disjoint]&&vG[bound_disjoint_VG]&&vG[bound_on_interior_VG]&&vG[seg_unshared_VG])))
    {
        ParallelObjectTraversal::object object_value = S.getObject();
        if (object_value == ParallelObjectTraversal::first) {

            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::first);
            Poi2D dp;
            if (h.isLeft) {
                S.addLeft(h.seg);
                dp = h.seg.p1;
            }
            else {
                S.delRight(h.seg);
                dp = h.seg.p2;
                vF[seg_unshared] = true;
            }
            if (dp != last_dp_f) {
                last_dp_f = dp;


                if (!S.lookAhead(h, objF)) {
                    last_bound_in_f = dp;
                    //poi2D comparison
                    if (last_bound_in_f == last_bound_in_g) {
                        vF[bound_shared] = true;
                    }
                    else if (last_bound_in_f == last_dp_g) {
                        vF[bound_on_interior] = true;
                    }
                    else if (!S.lookAhead(h, objG)) {
                        vF[bound_disjoint] = true;
                    }
                }

            }

            if (!(dp == last_bound_in_f))
            {
                if(dp == last_bound_in_g)
                {
                    vG[bound_on_interior]=true;
                }
                else if(dp == last_dp_g)
                {
                    vF[interior_poi_shared]= true;
                }
            }

        }
        else if(object_value == ParallelObjectTraversal::second)
        {//swapping F and G when object is second

            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::second);
            Poi2D dp;
            if (h.isLeft) {
                S.addLeft(h.seg);
                dp = h.seg.p1;
            }
            else {
                S.delRight(h.seg);
                dp = h.seg.p2;
                vF[seg_unshared] = true;
            }
            if (dp != last_dp_g) {
                last_dp_g = dp;


                if (!S.lookAhead(h, objG)) {
                    last_bound_in_g = dp;
                    //poi2D comparison
                    if (last_bound_in_f == last_bound_in_g) {
                        vF[bound_shared] = true;
                    }
                    else if (last_bound_in_g == last_dp_f) {
                        vF[bound_on_interior] = true;
                    }
                    else if (!S.lookAhead(h, objF)) {
                        vF[bound_disjoint] = true;
                    }
                }

            }

            if (!(dp == last_bound_in_g))
            {
                if(dp == last_bound_in_f)
                {
                    vG[bound_on_interior]=true;
                }
                else if(dp == last_dp_f)
                {
                    vF[interior_poi_shared]= true;
                }
            }
        }
        else
        {
            //object = both
            HalfSeg2D h = S.getHalfSegEvent(ParallelObjectTraversal::first);
            vF[seg_shared]=true;
            Poi2D dp;
            if (h.isLeft) {
                S.addLeft(h.seg);
                dp = h.seg.p1;
            }
            else {
                S.delRight(h.seg);
                dp = h.seg.p2;
                vF[seg_unshared] = true;
            }
            if(!(dp==last_dp_f))
            {
                last_dp_f = dp;

                if(!S.lookAhead(h, objF))
                {
                    last_bound_in_f = dp;
                }

            }
           if(!(dp==last_dp_g))
           {
               last_dp_g = dp;

               if(!S.lookAhead(h, objG))
               {
                   last_bound_in_g =dp;
               }
           }

           if(last_bound_in_f==last_bound_in_g)
           {
               vF[bound_shared] = true;
           }

            else
           {
               if(last_bound_in_f==last_dp_g)
               {
                   vF[bound_on_interior]=true;
               }
               if(last_bound_in_g == last_dp_f)
               {
                   vG[bound_on_interior_VG]=true;
               }
           }

        }


        //check status
        if((S.getStatus() != ParallelObjectTraversal::end_of_first))
        {
            vG[seg_unshared_VG]= true;
        }
        else if((S.getStatus() != ParallelObjectTraversal::end_of_second))
        {
            vF[seg_unshared]=true;
        }
        S.selectNext();
    }

    return;
}


void Line2DLine2D::evaluateTopoPred() {


    int IMC[3][3];


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            IMC[i][j] = 0;
        }
    }
    //populating 9IM
    if (vF[vFLine2DLine2DPredicates::seg_shared] && vF[vFLine2DLine2DPredicates::interior_poi_shared]) {
        IMC[0][0] = 1;
    }
    else if (vG[vGLine2DLine2DPredicates::bound_on_interior_VG]) {
        IMC[0][1] = 1;
    }
    else if (vF[vFLine2DLine2DPredicates::seg_unshared]) {
        IMC[0][2] = 1;
    }
    else if (vF[vFLine2DLine2DPredicates::bound_on_interior]) {
        IMC[1][0] = 1;
    }
    else if (vF[vFLine2DLine2DPredicates::bound_shared]) {
        IMC[1][1] = 1;
    }
    else if (vF[vFLine2DLine2DPredicates::bound_disjoint]) {
        IMC[1][2] = 1;
    }
    else if (vG[vGLine2DLine2DPredicates::seg_unshared_VG]) {
        IMC[2][0] = 1;
    }
    else if (vG[vGLine2DLine2DPredicates::bound_disjoint_VG]) {
        IMC[2][1] = 1;
    }

    IMC[2][2] = 1;

    //Evaluation phase

    //Disjoint
    if ((!IMC[0][0]) && (!IMC[0][1]) && (!IMC[1][0]) && (!IMC[1][1])) {
        topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_disjoint_m4;
        isPredSet = true;
    }

    //Touches/meet
    if (!(IMC[0][0])) {
        if (IMC[0][1] || IMC[1][0] || IMC[1][1]) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_meet_m25;
            isPredSet = true;
        }
    }
    //equals
    if (IMC[0][0]) {
        if ((!IMC[2][0]) && (!IMC[2][1]) && (!IMC[0][2]) && (!IMC[1][2])) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_meet_m25;
            isPredSet = true;
        }
    }
    //inside
    if (IMC[0][0]) {
        if ((!(IMC[0][2])) && (!(IMC[1][2]))) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_inside_m39;
            isPredSet = true;
        }
    }
    //coveredBy
    if ((!(IMC[0][2])) && (!(IMC[1][2]))) {


        if ((IMC[0][0]) || (IMC[0][1]) || (IMC[1][0]) || (IMC[1][1])) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_coveredby_m37;
            isPredSet = true;
        }
    }
    //contains
    if (IMC[0][0]) {
        if ((!(IMC[2][0])) && (!(IMC[2][1]))) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_contains_m43;
            isPredSet = true;
        }
    }

    //overlaps
    if ((IMC[0][0]) && (IMC[0][2]) && (IMC[2][0])) {
        topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_overlap_m44;
        isPredSet = true;
    }

    //covers
    if ((!(IMC[2][0])) && (!(IMC[2][1]))) {
        if ((IMC[0][0]) || (IMC[0][1]) || (IMC[1][0]) || (IMC[1][1])) {
            topPredNumberLine2DLine2D = TopPredNumberLine2DLine2D::ll_covers_m72;
            isPredSet = true;
        }
    }

}


TopPredNumberLine2DLine2D Line2DLine2D::getTopologicalRelationship()
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    return topPredNumberLine2DLine2D;
}

bool Line2DLine2D::isTopologicalRelationship(TopPredNumberLine2DLine2D predicate)
{
    if(!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D==predicate)
    {
        return true;
    }
    return false;
}


bool Line2DLine2D::overlap()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if( topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m44||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m45||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m47||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m48||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m50||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m51||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m53||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m54||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m55||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m56||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m57||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m58||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m59||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m60||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m61||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m62||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m64||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m65||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m67||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m68||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m70||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m71||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m71||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m73||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m74||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m75||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m76||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m77||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m78||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m79||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m80||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m81||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_overlap_m82)
    {   return true;
    }
    return false;
}

bool Line2DLine2D::meet()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m5||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m6||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m7||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m8||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m9||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m10||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m11||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m12||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m13||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m14||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m15||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m16||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m17||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m18||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m19||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m20||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m21||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m22||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m23||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m24||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m25||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m26||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m27||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m28||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m29||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m30||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m31||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D::ll_meet_m32)
    {
        return true;
    }
    return false;
}

bool Line2DLine2D::inside()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_inside_m34||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_inside_m35||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_inside_m39||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_inside_m40)
    {
        return true;
    }
    return false;
}

bool Line2DLine2D::disjoint()
{
    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_disjoint_m1||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_disjoint_m2||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_disjoint_m3||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_disjoint_m4)
    {
        return true;
    }
    return false;
}

bool Line2DLine2D::contains()
{

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_contains_m43||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_contains_m46||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_contains_m63||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_contains_m66)
    {
        return true;
    }
    return false;
}

bool Line2DLine2D::coveredBy()
{

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_coveredby_m37||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_coveredby_m38||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_coveredby_m41||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_coveredby_m42) {
        return true;
    }
    return false;
}

bool Line2DLine2D::covers()
{

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_covers_m49||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_covers_m52||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_covers_m69||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_covers_m72) {
        return true;
    }
    return false;
}

bool Line2DLine2D::equal()
{

    if (!isPredSet)
    {
        exploreTopoPred();
        evaluateTopoPred();
    }
    if(topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_equal_m33||topPredNumberLine2DLine2D ==TopPredNumberLine2DLine2D:: ll_equal_m36)
    {
                return true;
        }
    return false;
}



















