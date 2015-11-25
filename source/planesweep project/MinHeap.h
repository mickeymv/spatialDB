//
// Created by Mickey Vellukunnel on 11/25/15.
//

#ifndef PLANESWEEP_PROJECT_MINHEAP_H
#define PLANESWEEP_PROJECT_MINHEAP_H

#include "vector"
using namespace std;

class MinHeap
{
private:
    vector<int> _vector;
    void BubbleDown(int index);
    void BubbleUp(int index);
    void Heapify();

public:
    MinHeap(int* array, int length);
    MinHeap(const vector<int>& vector);
    MinHeap();

    void Insert(int newValue);
    int GetMin();
    void DeleteMin();
};

#endif //PLANESWEEP_PROJECT_MINHEAP_H
