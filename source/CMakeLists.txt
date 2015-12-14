cmake_minimum_required(VERSION 3.3)
project(source)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    planesweep-project/Topic1/BigInteger.cpp
    planesweep-project/Topic1/BigInteger.h
    planesweep-project/Topic1/BigRational.cpp
    planesweep-project/Topic1/BigRational.h
    planesweep-project/Topic1/Number.cpp
    planesweep-project/Topic1/Number.h
    planesweep-project/Topic1/RobustGeometricPrimitives2D.cpp
    planesweep-project/Topic1/RobustGeometricPrimitives2D.h
    planesweep-project/Topic2/Implementation/Line2D.cpp
    planesweep-project/Topic2/Implementation/Line2D.h
    planesweep-project/Topic2/Implementation/Line2DImpl.cpp
    planesweep-project/Topic2/Implementation/Line2DImpl.h
    planesweep-project/Topic2/Implementation/Point2D.cpp
    planesweep-project/Topic2/Implementation/Point2D.h
    planesweep-project/Topic2/Implementation/Region2D.cpp
    planesweep-project/Topic2/Implementation/Region2D.h
    planesweep-project/Topic2/Implementation/Region2DImpl.cpp
    planesweep-project/Topic2/Implementation/Region2DImpl.h
    planesweep-project/Topic2/Implementation/TestLine2D.cpp
    planesweep-project/Topic2/Implementation/TestPoint2D.cpp
    planesweep-project/Topic2/Implementation/TestRegion2D.cpp
    planesweep-project/AVLTree.h
    planesweep-project/main.cpp
    planesweep-project/MinHeap.h
    planesweep-project/Object2D.cpp
    planesweep-project/Object2D.h
    planesweep-project/ParallelObjectTraversal.cpp
    planesweep-project/ParallelObjectTraversal.h
    planesweep-project/PlaneSweep.cpp
    planesweep-project/PlaneSweep.h
    planesweep-project/PlaneSweepLineStatusObject.cpp
    planesweep-project/PlaneSweepLineStatusObject.h
    planesweep-project/SegmentClass.cpp
    planesweep-project/SegmentClass.h
    LineSpatialOperationsTestClass.cpp
    PointSpatialOperationsTestClass.cpp
    RegionSpatialOperationsTestClass.cpp
    SpatialOperations.cpp
    SpatialOperations.h)

add_executable(source ${SOURCE_FILES})