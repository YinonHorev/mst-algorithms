#include "MinHeap.hpp"
#include <iostream>
using namespace std;

void MinHeap::fixHeapDown(int nodeIndex) {

    int min = nodeIndex;
    int left = getLeft(nodeIndex);
    int right = getRight(nodeIndex);

    if (left < heapSize && arr[left]->vertex.weight < arr[min]->vertex.weight)
        min = left;
    if (right < heapSize && arr[right]->vertex.weight < arr[min]->vertex.weight)
        min = right;
    if (min != nodeIndex) {
        swap(arr[nodeIndex], arr[min]);
        fixHeapDown(min);
    }
}

void  MinHeap::fixHeapUp(int nodeIndex) {
    if (nodeIndex && arr[getParent(nodeIndex)]->vertex.weight > arr[nodeIndex]->vertex.weight)
    {
        swap(arr[nodeIndex], arr[getParent(nodeIndex)]);
        fixHeapUp(getParent(nodeIndex));
            
    }
}

//void MinHeap::Insert(HeapNode* node) {
//
//    if (heapSize == heapMaxSize)
//    {
//        cout << "error - could not Insert key" << endl;
//        exit(1);
//    }
//
//    int i = heapSize;
//    arr[i] = node;
//    arr[i]->indexInHeap = i;
//    fixHeapUp(i);
//    heapSize++;
//}

HeapNode* MinHeap::DeleteMin() {
    HeapNode* min = arr[0];
    
    heapSize--;
    swap(arr[0], arr[heapSize]);
    arr[heapSize] = nullptr;
    fixHeapDown(0);
    return min;

}


void MinHeap::DecreaseKey(int index, int weight) {
//    if (heapSize == index) {
//        delete arr[heapSize];
//        arr[heapSize] = nullptr;
//        return;
//    }
    arr[index]->vertex.weight = weight;
    fixHeapUp(index);
}
