# CMake file (CLion1.2)
cmake_minimum_required(VERSION 3.3)
project(Topological_classes)


#include_directories (. planesweep_project planesweep_project/Topic1 planesweep_project/Topic2/Implementation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp

        planesweep_project/MinHeap.h

        planesweep_project/AVLTree.h


        planesweep_project/Topic1/BigInteger.cpp

        planesweep_project/Topic1/BigRational.cpp
        planesweep_project/Topic1/BigRational.h

        planesweep_project/Topic1/Number.cpp
        planesweep_project/Topic1/Number.h

        planesweep_project/Topic1/RobustGeometricPrimitives2D.cpp
        planesweep_project/Topic1/RobustGeometricPrimitives2D.h

        planesweep_project/Object2D.cpp
        planesweep_project/Object2D.h

        planesweep_project/Topic2/Implementation/Line2D.h
        planesweep_project/Topic2/Implementation/Line2D.cpp
        planesweep_project/Topic2/Implementation/Line2DImpl.h
        planesweep_project/Topic2/Implementation/Line2DImpl.cpp
        planesweep_project/Topic2/Implementation/Region2D.h
        planesweep_project/Topic2/Implementation/Region2D.cpp
        planesweep_project/Topic2/Implementation/Region2DImpl.h
        planesweep_project/Topic2/Implementation/Region2DImpl.cpp

        TopPredNumberEnums.h

        planesweep_project/Topic2/Implementation/Point2D.h
        planesweep_project/Topic2/Implementation/Point2D.cpp

        planesweep_project/PlaneSweep.cpp
        planesweep_project/PlaneSweep.h

        planesweep_project/ParallelObjectTraversal.cpp
        planesweep_project/ParallelObjectTraversal.h

        TopologicalRelationships.h
        TopologicalRelationships.cpp

        planesweep_project/SegmentClass.cpp
        planesweep_project/SegmentClass.h

        planesweep_project/PlaneSweepLineStatusObject.cpp
        planesweep_project/PlaneSweepLineStatusObject.h


        Point2DPoint2D.cpp
        Point2DPoint2D.h

        Point2DRegion2D.cpp
        Point2DRegion2D.h

        Line2DLine2D.cpp
        Line2DLine2D.h

        Line2DRegion2D.cpp
        Line2DRegion2D.h

        Point2DLine2D.cpp
        Point2DLine2D.h

        Region2DRegion2D.h
        Region2DRegion2D.cpp


        TestPoint2DPoint2D.cpp
        TestPoint2DPoint2D.h

        TestPoint2DLine2D.cpp
        TestPoint2DLine2D.h
        TestRegion2DRegion2D.cpp
        TestRegion2DRegion2D.h
        TestPoint2DRegion2D.cpp
        TestPoint2DRegion2D.h
        TestLine2DLine2D.cpp
        TestLine2DLine2D.h
        TestLine2DRegion2D.cpp
        TestLine2DRegion2D.h)
add_executable(Topological_classes ${SOURCE_FILES})
