#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>
#include <vector>
#include "graph.hpp"

struct Vertex {
    unsigned int VertexIndex;
    std::vector<GraphEdge> edges;
};

struct HeapNode {
    int key;
    Vertex vertex;
    unsigned int indexInHeap;
};


class MinHeap {
    std::vector<unsigned int> vertexsIndexesInHeap;
    std::vector<HeapNode> heapArray;
    int getLeft(int index) { return (2 * index + 1); }
    int getRight(int index) { return (2 * index + 2); }
    int getParent(int index) { return (index - 1) / 2; }
    void fixHeapDown(int nodeIndex);
    void fixHeapUp(int nodeIndex);

public:
    HeapNode DeleteMin();
    
    void DecreaseKey(int index, int weight);
    
    void Build(UnDirectedGraph G, unsigned int initial_vertex = 0);
    
    bool isEmpty() { return heapArray.size() == 0; }
    
    void swap(HeapNode& a, HeapNode& b)
    {
        HeapNode temp = a;
        unsigned int t = vertexsIndexesInHeap[a.vertex.VertexIndex];
        vertexsIndexesInHeap[a.vertex.VertexIndex] = vertexsIndexesInHeap[b.vertex.VertexIndex];
        vertexsIndexesInHeap[b.vertex.VertexIndex] = t;
//        int tempIndex = a.indexInHeap;
//        a.indexInHeap = b.indexInHeap;
//        b.indexInHeap = tempIndex;
        a = b;
        b = temp;
    }
};


#endif /* MinHeap_hpp */
