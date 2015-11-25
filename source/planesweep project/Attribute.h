//
// Created by Natasha on 11/17/2015.
//

#ifndef PLANESWEEP_PROJECT_ATTRIBUTE_H
#define PLANESWEEP_PROJECT_ATTRIBUTE_H

#include <memory>
#include <typeinfo>

#include "Topic2/Implementation/RobustGeometricPrimitives2D.h"
#include "SegmentClass.h"



class Attribute {
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
    Attribute() { };
    virtual ~Attribute() { };

    template<class T>
    Attribute &operator=(const T &t) {
        pb = std::unique_ptr<base>(new wrp<T>(t));
        return *this;
    }

    Attribute(Attribute &&) = default;

    Attribute &operator=(Attribute &&) = default;


    template<class T>
    Attribute(const T &t) : pb(new wrp<T>(t)) {
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

    bool isBool() {
        return typeID == typeid(bool).hash_code() ? true : false;
    };

    bool isSegmentClass() {
        return typeID == typeid(SegmentClass).hash_code() ? true : false;
    };

};

#endif //PLANESWEEP_PROJECT_ATTRIBUTE_H
