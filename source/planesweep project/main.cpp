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
    PlaneSweep ps(F, G); //selectFirst() is Called only once to initialize the plane sweep variables object 
	// and status within the constructor.

	/** Give an example below of how we can use the PlaneSweep and ParallelObjectTraversal
	*	object and methods to implement Spatial Operations or Topological Predicates.	
	*/

	
	
	while (ps.getObject != none) {
	 	//do some work related to spatial/topological operations
	 	//use the 'object' or 'status' variables or the other functions
	 	// such as getEvent, lookAhead() from the ps object
	 	ps.selectNext();
	}
	
	/** Example above.
	*/
	

    // *** begin test temp
    // for testing, I have hardcoded in "POT_Point2DPoint2D.cpp" the value vF[poi_shared] = true
    cout << "F and G = Point2D objects \n";
    
    //The below vF should be removed from the common PlaneSweep and ParallelObjectTraversal work.
    cout << " vF[poi_disjoint] = " << ps.getVF()[POT_Point2DPoint2D::poi_disjoint] << " \n";
    cout << " vF[poi_shared] = " << ps.getVF()[POT_Point2DPoint2D::poi_shared] << " \n";
    cout << "vector size = " << ps.getVFGSize() << " \n";
    //The above vF should be removed from the common PlaneSweep and ParallelObjectTraversal work.
    
    // *** end test temp


    cout << " ---> test successful!! <---  \n";


    return 0;


}

