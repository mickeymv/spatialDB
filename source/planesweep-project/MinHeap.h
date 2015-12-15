/******************************************************************************
* File: MinHeap.h
*******************************************************************************
* Purpose: Interface to the class MinHeap
*
* Description: The MinHeap class creates a min-heap, a tree data structure.
* This data structure is used to store data in the dynamic event point schedule.
*
* Class: Spatial and Moving Objects Databases (CIS 4930/CIS 6930)
*
* Authors: Group 3 (Amritesh Randhi, Arvindh Mani, Mickey Vellukunnel, Sarath Francis)
*
* Date: Fall Semester 2015
******************************************************************************/

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
    T GetNext(T x);
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


template<class T>
MinHeap<T>::MinHeap(int MinHeapSize)
{// Min heap constructor.
    MaxSize = MinHeapSize;
    heap = new T[MaxSize+1];
    CurrentSize = 0;
}

template<class T>
MinHeap<T>& MinHeap<T>::Insert(const T& x)
{
    T temp = x;
// Insert x into the min heap.
    if (CurrentSize == MaxSize)
        return *this; // TODO - find out what to do

    // find place for x
    // i starts at new leaf and moves up tree
    int i = ++CurrentSize;
    while (i != 0 && temp < heap[i/2]) {
        // cannot put x in heap[i]
        heap[i] = heap[i/2]; // move element down
        i /= 2; // move to parent
    }
    heap[i] = x;

    return *this;
}

template<class T>
MinHeap<T>& MinHeap<T>::DeleteMin()
{// Set x to min element and delete
    // min element from heap.
    // check if heap is empty
    if (CurrentSize == 0)
        return *this; // TODO - find out what to do

    //x = heap[0]; // min element

    // restructure heap
    T y = heap[CurrentSize--]; // last element

    // find place for y starting at root
    int i = 1,  // current node of heap
            ci = 2; // child of i
    while (ci <= CurrentSize) {// find place to put y
        // heap[ci] should be smaller child of i
        if (ci < CurrentSize &&
            heap[ci] > heap[ci+1]) ci++;

        // can we put y in heap[i]?
        if (y <= heap[ci]) break;  // yes

        // no
        heap[i] = heap[ci]; // move child up
        i = ci;  // move down a level
        ci *= 2;
    }
    heap[i] = y;

    return *this;
}

template<class T>
void MinHeap<T>::Initialize(T a[], int size, int ArraySize)
{// Initialize min heap to array a.
    delete [] heap;
    heap = a;
    CurrentSize = size;
    MaxSize = ArraySize;

    // make into a min heap
    for (int i = CurrentSize/2; i >= 0; i--) {
        T y = heap[i]; // root of subtree

        // find place to put y
        int c = 2*i; // parent of c is target
        // location for y
        while (c <= CurrentSize) {
            // make c point to smaller sibling
            if (c < CurrentSize &&
                heap[c] > heap[c+1]) c++;

            // can we put y in heap[c/2]?
            if (y <= heap[c]) break;  // yes

            // no
            heap[c/2] = heap[c]; // move heap[c] up
            c *= 2;              // move c down a level
        }
        heap[c/2] = y;
    }
}

template<class T>
void MinHeap<T>::Output() const
{
    cout << "The " << CurrentSize
    << " elements are"<< endl;
    for (int i = 0; i <= CurrentSize; i++)
        cout << heap[i] << ' ';
    cout << endl;
}

template<class T>
T MinHeap<T>::GetMin() {
    AttrHalfSeg2D attrHalfSeg2D;
    if (CurrentSize == 0)
        return attrHalfSeg2D;
    return heap[0];//

}

template<class T>
bool MinHeap<T>::isEmpty()
{
    if(CurrentSize==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
T MinHeap<T>::GetNext(T x)
{
    T *result = nullptr;
    for (int i = 0; i <= CurrentSize; i++)
    {
        if((heap[i]>x)&&(result== nullptr))
        {
            result = &heap[i];
        }
        else if((heap[i]>x)&&(result!= nullptr))
        {
            if(&heap[i]<result)
            {
                result = &heap[i];
            }
        }
    }
    return *result;
}

#endif //PLANESWEEP_PROJECT_MINHEAP_H
