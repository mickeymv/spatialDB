#include <iostream>
#include "Point2DLine2D.h"

#include "planesweep_project/Topic2/Implementation/Point2D.h"
#include "planesweep_project/Topic2/Implementation/Line2D.h"
#include "Object2D.h"

using namespace std;

int main() {

    Point2D a;
    Line2D b;
    Point2DLine2D pl(a,b);
    pl.Explore();
    pl.Evaluate();
    Point2DLine2D::TopPredNumberPoint2DLine2D result = pl.getRelation();
    cout<<result;
}