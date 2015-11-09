#include <iostream>

#include "PlaneSweep.h"


using namespace std;

// *** begin test temp
#include "POT_Point2DPoint2D.h"
// *** end test temp

int main(int argc, char *argv[]) {

    // test

    Point2D F;
    Point2D G;
    PlaneSweep ps(F, G);


    // *** begin test temp
    // for testing, I have hardcoded in "POT_Point2DPoint2D.cpp" the value vF[poi_shared] = true
    cout << "F and G = Point2D objects \n";
    cout << " vF[poi_disjoint] = " << ps.getVF()[POT_Point2DPoint2D::poi_disjoint] << " \n";
    cout << " vF[poi_shared] = " << ps.getVF()[POT_Point2DPoint2D::poi_shared] << " \n";
    cout << "vector size = " << ps.getVFGSize() << " \n";
    // *** end test temp


    cout << " ---> test successful!! <---  \n";


    return 0;


}

