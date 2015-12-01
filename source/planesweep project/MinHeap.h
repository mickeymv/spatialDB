//
// Created by Mickey Vellukunnel on 11/25/15.
//

#ifndef PLANESWEEP_PROJECT_MINHEAP_H
#define PLANESWEEP_PROJECT_MINHEAP_H

#include "vector"
#include "Topic1/RobustGeometricPrimitives2D.h"

using namespace std;

class MinHeap
{
private:
    vector<AttrHalfSeg2D> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MinHeap(AttrHalfSeg2D* array, int length);
    MinHeap(const vector<AttrHalfSeg2D>& vector);
    MinHeap();

    void Insert(AttrHalfSeg2D newValue);
    AttrHalfSeg2D GetMin();
    void DeleteMin();
};

#endif //PLANESWEEP_PROJECT_MINHEAP_H
