/* *****************************************************************************
*  File: Object2D.cpp
* ******************************************************************************
*
*  Purpose: Object2D serves as abstract base class for Point2D, Line2D and Region2D classes.
*
*  Description: This abstract base class is needed for the above mentioned classes to work
*  properly in PlaneSweep and ParallelObjectTraverse. In this case, first Point2D,  Line2D and Region2D
*  need to inherit Object2D. This is done just by adding ": public Object2D' at the end of its class
*  declaration (may not be covered in Topic 2 implementation).
*
*
*  Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
*  Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*           Group 4 (Aswini Ramesh, Djundi Tjindra, Kyuseo Park, Michael Kemerer, Natasha Mandal)
*
* Date: Fall Semester 2015
*
* *****************************************************************************/


#include "Object2D.h"
#include "Topic2/Implementation/Region2D.h"
#include "Topic2/Implementation/Point2D.h"
#include "Topic2/Implementation/Line2D.h"


// Equal operator that checks if the Object2D object and the operand Object2D are the same
bool Object2D::operator==(const Object2D &operand) const {
    return this == &operand ? true : false;
}

// The methods below are used to verify those in objF or objG passed params,
// used in PlaneSweep and ParallelObjectTraverse.

bool Object2D::isPoint2D() const {
    return dynamic_cast<const Point2D *>(this) != nullptr;
}

bool Object2D::isLine2D() const {
    return dynamic_cast<const Line2D *>(this) != nullptr;
}

bool Object2D::isRegion2D() const {
    return dynamic_cast<const Region2D *>(this) != nullptr;

}
