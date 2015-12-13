cmake_minimum_required(VERSION 3.3)
project(planesweep_project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Topic1/BigInteger.cpp
    Topic1/BigInteger.h
    Topic1/BigRational.cpp
    Topic1/BigRational.h
    Topic1/Number.cpp
    Topic1/Number.h
    Topic1/RobustGeometricPrimitives2D.cpp
    Topic1/RobustGeometricPrimitives2D.h
    Topic2/Implementation/BigInteger.cpp
    Topic2/Implementation/BigInteger.h
    Topic2/Implementation/BigRational.cpp
    Topic2/Implementation/BigRational.h
    Topic2/Implementation/Line2D.cpp
    Topic2/Implementation/Line2D.h
    Topic2/Implementation/Line2DImpl.cpp
    Topic2/Implementation/Line2DImpl.h
    Topic2/Implementation/Number.cpp
    Topic2/Implementation/Number.h
    Topic2/Implementation/Point2D.cpp
    Topic2/Implementation/Point2D.h
    Topic2/Implementation/Region2D.cpp
    Topic2/Implementation/Region2D.h
    Topic2/Implementation/Region2DImpl.cpp
    Topic2/Implementation/Region2DImpl.h
    Topic2/Implementation/RobustGeometricPrimitives2D.cpp
    Topic2/Implementation/RobustGeometricPrimitives2D.h
    Topic2/Implementation/TestLine2D.cpp
    Topic2/Implementation/TestPoint2D.cpp
    Topic2/Implementation/TestRegion2D.cpp
    Topic2/Interfaces/Line2D.h
    Topic2/Interfaces/Number.h
    Topic2/Interfaces/Point2D.h
    Topic2/Interfaces/Region2D.h
    Topic2/Interfaces/Region2DImpl.h
    Topic2/Interfaces/RobustGeometricPrimitives2D.cpp
    Topic2/Interfaces/RobustGeometricPrimitives2D.h
    AVLTree.cpp
    AVLTree.h
    main.cpp
    MinHeap.cpp
    MinHeap.h
    Object2D.cpp
    Object2D.h
    ParallelObjectTraversal.cpp
    ParallelObjectTraversal.h
    PlaneSweep.cpp
    PlaneSweep.h
    PlaneSweepLineStatusObject.cpp
    PlaneSweepLineStatusObject.h
    SegmentClass.cpp
    SegmentClass.h)

add_executable(planesweep_project ${SOURCE_FILES})