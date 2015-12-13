//
// Created by Sarath Francis on 12/13/15.
//

#include "SpatialOperations.h"
#include <stdio.h>
#include "planesweep project/Topic1/RobustGeometricPrimitives2D.h"
#include "planesweep project/Topic2/Implementation/Line2D.h"
#include "planesweep project/Topic2/Interfaces/Region2D.h"

int main() {

    Line2D line;

    /* We need three test cases
     *  1. a) Line-Line intersection.
     *     b) Line-Line union.
     *     c) Line-Line difference.
     *
     */

    /* 1. a) Computation of spatial intersection between two spatial Lines.
          I) No common segments.
            I.x) Both Line objects are null.
            I.y) One Line object is null.
            I.z) Both Line objects are non empty but no common segments.
          II) Some segments in common.
            II.x) Segments in common are all in the start of the two objects.
            II.y) Segments in common are all in the end of the two ob

          III)  All segments in common.

          */

    cout << "\n\n------------------LINE  SPATIAL OPERATIONS Testing starts here ----------------------\n" <<endl;



//Computation of spatial union between two spatial lines.
    line = spatialUnion(line, line);


    printf("\nSuccessfully ran Group 3's Spatial Operations Program!\n\n");

    return 0;
}