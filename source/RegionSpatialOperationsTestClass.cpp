//
// Created by Sarath Francis on 12/13/15.
//
//
// Created by Sarath Francis on 12/13/15.
//

#include "SpatialOperations.h"
#include <stdio.h>
#include "planesweep project/Topic1/RobustGeometricPrimitives2D.h"
#include "planesweep project/Topic2/Implementation/Line2D.h"
#include "planesweep project/Topic2/Interfaces/Region2D.h"

int main() {


    Region2D region;

    /* We need three test cases
     *  1. a) Region-Region intersection.
     *     b) Region-Region union.
     *     c) Region-Region difference.
     *
     */

    /* 1. a) Computation of spatial intersection between two spatial Regions.
          I) No common Interiors.
            I.x) Both Region objects are null.
            I.y) One Regions object is null.
            I.z) Both Region objects are non empty but no common interiors.
          II) Some Interiors in common.
            II.x) Interiors in common are all in the start of the two objects.
            II.y) Interiors in common are all in the end of the two objects

          III)  All Interiors in common.

          */

    cout << "\n\n------------------REGION SPATIAL OPERATIONS Testing starts here ----------------------\n" <<endl;





//Computation of spatial difference between two spatial regions.
    region = spatialDifference(region, region);

    printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");

    return 0;
}