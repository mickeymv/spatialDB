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

#ifndef PLANESWEEP_PROJECT_OBJECT2D_H
#define PLANESWEEP_PROJECT_OBJECT2D_H

#include <memory>
#include <typeinfo>


// This is a pure virtual class/ abstract base class/Interface class which will have no objects of its own.
// It's upto the derived classes; Poi, Line and Region2D to have definitions for
// the methods in this class.
//

class Object2D {

public:

    Object2D() { };

    ~Object2D() { };

    bool operator==(const Object2D &operand) const;

    virtual bool isPoint2D() const;

    virtual bool isLine2D() const;

    virtual bool isRegion2D() const;

};


#endif //PLANESWEEP_PROJECT_OBJECT2D_H
