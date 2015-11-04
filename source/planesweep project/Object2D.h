//
// Created by Djundi on 11/3/15.
//

#ifndef SPATIAL_PREDICATES_OBJECT2D_H
#define SPATIAL_PREDICATES_OBJECT2D_H

#include <memory>
#include <typeinfo>

#include "Point2D.h"
#include "Line2D.h"
#include "Region2D.h"


// *** begin test temp
#include "Test2D.h"
// *** end test temp


// since we do not have any base (super) class for the spatial objects, we use this template
// class Object2D is the base template class for the F and G objects

class Object2D {
// *** begin template declaration ***
    template<class T>
    class wrp;

    size_t typeID; // this holds the actual typeID of the instance

    class base {
    public:
        virtual ~base() { }

        template<class T>
        T *has_value() {
            auto *ptr = dynamic_cast<wrp<T> *>(this);
            return ptr ? &ptr->m : nullptr;
        };
    };

    template<class T>
    class wrp : public base {
    public:
        wrp() : m() { };

        wrp(const T &t) : m(t) { };
        T m;
    };

    std::unique_ptr<base> pb;

public:
    Object2D() { };
    virtual ~Object2D() { };

    template<class T>
    Object2D &operator=(const T &t) {
        pb = std::unique_ptr<base>(new wrp<T>(t));
        return *this;
    }

    Object2D(Object2D &&) = default;

    Object2D &operator=(Object2D &&) = default;


    template<class T>
    Object2D(const T &t) : pb(new wrp<T>(t)) {
        typeID = typeid(t).hash_code();
    }

    template<class T>
    T *get() const { //ret nullptr if not a T*
        return bool(pb) ? pb->has_value<T>() : nullptr;
    }

    template<class T>
    bool set(T &t) {
        T *pt = get<T>();
        if (pt) t = *pt;
        return bool(pt);
    }


    // *** begin test temp
    bool isTest2D() {
        return (typeID == typeid(Test2D).hash_code()) ? true : false;
    };
    // *** end test temp

    bool isPoint2D() {
        return (typeID == typeid(Point2D).hash_code()) ? true : false;
    };

    bool isLine2D() {
        return (typeID == typeid(Line2D).hash_code()) ? true : false;
    };

    bool isRegion2D() {
        return (typeID == typeid(Region2D).hash_code()) ? true : false;
    };

};


#endif //SPATIAL_PREDICATES_OBJECT2D_H
