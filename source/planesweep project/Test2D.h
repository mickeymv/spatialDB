//
// Created by Djundi on 11/3/15.
//

// This is a test class object, to be deleted later.

#ifndef SPATIAL_PREDICATES_TEST2D_H
#define SPATIAL_PREDICATES_TEST2D_H

// *** begin test temp
class Test2D {

public:
    Test2D() { }
    virtual ~Test2D() { }

    const int &getFoo(unsigned int index) const {
        return (int&) foo[index];
    }

private:
    // random value assignment for testing
    int foo [5] = { 16, 2, 77, 40, 12071 };
};
// *** end test temp

#endif //SPATIAL_PREDICATES_TEST2D_H
