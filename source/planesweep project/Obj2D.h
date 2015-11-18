//
// Created by Natasha on 11/17/2015.
//

#ifndef PLANESWEEP_PROJECT_OBJ2D_H
#define PLANESWEEP_PROJECT_OBJ2D_H

#include <memory>
#include <typeinfo>

#include "Topic2/Implementation/RobustGeometricPrimitives2D.h"



class Obj2D {
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
    Obj2D() { };
    virtual ~Obj2D() { };

    template<class T>
    Obj2D &operator=(const T &t) {
        pb = std::unique_ptr<base>(new wrp<T>(t));
        return *this;
    }

    Obj2D(Obj2D &&) = default;

    Obj2D &operator=(Obj2D &&) = default;


    template<class T>
    Obj2D(const T &t) : pb(new wrp<T>(t)) {
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

    bool isPoi2D() {
        return typeID == typeid(Poi2D).hash_code() ? true : false;
    };

    bool isSeg2D() {
        return typeID == typeid(Seg2D).hash_code() ? true : false;
    };
//See if isSeg2D is enough
    bool isHalfSeg2D() {
        return typeID == typeid(HalfSeg2D).hash_code() ? true : false;
    };

    bool isAttrHalfSeg2D() {
        return typeID == typeid(AttrHalfSeg2D).hash_code() ? true : false;
    };
};

#endif //PLANESWEEP_PROJECT_OBJ2D_H
