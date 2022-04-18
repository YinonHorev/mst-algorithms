#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>
#include <string>
using namespace std;

struct MstVertex {
    int weight;
    unsigned int VertexIndex;
};

struct HeapNode {
    MstVertex vertex;
    int indexInHeap;
};


class MinHeap {
    HeapNode** arr;
    int heapMaxSize;
    int heapSize;

private:
    int getLeft(int index) { return (2 * index + 1); }
    int getRight(int index) { return (2 * index + 2); }
    int getParent(int index) { return (index - 1) / 2; }
    void fixHeapDown(int nodeIndex);
    void fixHeapUp(int nodeIndex);

public:
    MinHeap(int size) {
        heapMaxSize = size;
        heapSize = 0;
        arr = new HeapNode*[heapMaxSize];
    }
    ~MinHeap() {
        delete []arr;
    }
//
//    HeapNode* Min() {
//        return arr[0];
//    }
    
    int getHeapSize() {return heapSize;}
    
//    void Insert(HeapNode* node);
    HeapNode* DeleteMin();
    void DecreaseKey(int index, int weight);
    bool isEmpty() { return heapSize == 0; }
    void swap(HeapNode*& a, HeapNode*& b)
    {
        HeapNode* temp = a;
        int tempIndex = a->indexInHeap;
        a->indexInHeap = b->indexInHeap;
        b->indexInHeap = tempIndex;
        a = b;
        b = temp;
    }
};


#endif /* MinHeap_hpp */
