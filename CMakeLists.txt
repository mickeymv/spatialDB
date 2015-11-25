cmake_minimum_required(VERSION 3.3)
project(spatialDB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    "source/planesweep project/Topic2/Implementation/Line2D.cpp"
    "source/planesweep project/Topic2/Implementation/Line2D.h"
    "source/planesweep project/Topic2/Implementation/Number.cpp"
    "source/planesweep project/Topic2/Implementation/Number.h"
    "source/planesweep project/Topic2/Implementation/Point2D.cpp"
    "source/planesweep project/Topic2/Implementation/Point2D.h"
    "source/planesweep project/Topic2/Implementation/RobustGeometricPrimitives2D.cpp"
    "source/planesweep project/Topic2/Implementation/RobustGeometricPrimitives2D.h"
    "source/planesweep project/Attribute.cpp"
    "source/planesweep project/Attribute.h"
    "source/planesweep project/AVL.h"
    "source/planesweep project/Line2DLine2D.cpp"
    "source/planesweep project/Line2DLine2D.h"
    "source/planesweep project/Line2DRegion2D.cpp"
    "source/planesweep project/Line2DRegion2D.h"
    "source/planesweep project/main.cpp"
    "source/planesweep project/Obj2D.cpp"
    "source/planesweep project/Obj2D.h"
    "source/planesweep project/Object2D.cpp"
    "source/planesweep project/Object2D.h"
        "source/planesweep project/ObjectIterator.h"
    "source/planesweep project/ParallelObjectTraversal.cpp"
    "source/planesweep project/ParallelObjectTraversal.h"
    "source/planesweep project/PlaneSweep.cpp"
    "source/planesweep project/PlaneSweep.h"
    "source/planesweep project/Point2DLine2D.cpp"
    "source/planesweep project/Point2DLine2D.h"
    "source/planesweep project/Point2DPoint2D.cpp"
    "source/planesweep project/Point2DPoint2D.h"
    "source/planesweep project/Point2DRegion2D.cpp"
    "source/planesweep project/Point2DRegion2D.h"
    "source/planesweep project/Region2D.h"
    "source/planesweep project/Region2DRegion2D.cpp"
    "source/planesweep project/Region2DRegion2D.h" "source/planesweep project/ObjectIterator.h")

add_executable(spatialDB ${SOURCE_FILES})