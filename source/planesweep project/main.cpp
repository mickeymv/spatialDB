#include <iostream>

#include "PlaneSweep.h"


using namespace std;

// *** begin test temp
#include "Test2D.h"
// *** end test temp

int main(int argc, char* argv[])
{

    // test

    Test2D F;
    Point2D G;
    PlaneSweep ps(F,G);


      cout << " ---> test successful!! <---  \n";

    return 0;


}

