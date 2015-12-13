//
// Created by Mickey Vellukunnel on 11/25/15.
//

#ifndef PLANESWEEP_PROJECT_MINHEAP_H
#define PLANESWEEP_PROJECT_MINHEAP_H

#include "vector"
#include "Topic1/RobustGeometricPrimitives2D.h"

using namespace std;

template<class T>
class MinHeap {
public:
    MinHeap(int MinHeapSize = 10);
    ~MinHeap() {delete [] heap;}
    int Size() const {return CurrentSize;}
    T GetMin();
    MinHeap<T> GetNext(T x);
    MinHeap<T>& Insert(const T& x);
    MinHeap<T>& DeleteMin();
    void Initialize(T a[], int size, int ArraySize);
    void Deactivate() {heap = 0;}
    void Output() const;
    bool isEmpty();
private:
    int CurrentSize, MaxSize;
    T *heap; // element array
};

#endif //PLANESWEEP_PROJECT_MINHEAP_H
