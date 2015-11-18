cmake_minimum_required(VERSION 3.3)
project(planesweep_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Topic2/Implementation/Line2D.cpp
    Topic2/Implementation/Line2D.h
    Topic2/Implementation/Number.cpp
    Topic2/Implementation/Number.h
    Topic2/Implementation/Point2D.cpp
    Topic2/Implementation/Point2D.h
    Topic2/Implementation/RobustGeometricPrimitives2D.cpp
    Topic2/Implementation/RobustGeometricPrimitives2D.h
    Attribute.cpp
    Attribute.h
    AVL.h
    Line2DLine2D.cpp
    Line2DLine2D.h
    Line2DRegion2D.cpp
    Line2DRegion2D.h
    main.cpp
    Obj2D.cpp
    Obj2D.h
    Object2D.cpp
    Object2D.h
    ObjectIterator.h
    ParallelObjectTraversal.cpp
    ParallelObjectTraversal.h
    PlaneSweep.cpp
    PlaneSweep.h
    Point2DLine2D.cpp
    Point2DLine2D.h
    Point2DPoint2D.cpp
    Point2DPoint2D.h
    Point2DRegion2D.cpp
    Point2DRegion2D.h
    Region2D.h
    Region2DRegion2D.cpp
    Region2DRegion2D.h)

add_executable(planesweep_project ${SOURCE_FILES})