//
// Created by Djundi on 11/8/15.
//

#ifndef PLANESWEEP_PROJECT_REGION2DREGION2D_H
#define PLANESWEEP_PROJECT_REGION2DREGION2D_H

#include "Object2D.h"

#include "Region2D.h"


class Region2DRegion2D{

public:
    Region2DRegion2D(Object2D &, Object2D &);
    ~Region2DRegion2D();

    // get vector array vF
    bool *getVF();

    //Exploration function
    bool Explore();

    // enum predicates
    enum class vF_Region2DRegion2D_Predicates{
        zero_one,one_zero,one_two,two_one,zero_two,two_zero,one_one,bound_poi_shared
    };

private:
    Region2D objF, objG;
    static const int vF_size=8;

    bool vF[vF_size];
};


#endif //PLANESWEEP_PROJECT_REGION2DREGION2D_H
