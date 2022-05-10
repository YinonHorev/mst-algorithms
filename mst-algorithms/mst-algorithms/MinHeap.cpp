#include "MinHeap.hpp"
#include <iostream>
#include<algorithm>

void MinHeap::fixHeapDown(int nodeIndex) {

    int min = nodeIndex;
    int left = getLeft(nodeIndex);
    int right = getRight(nodeIndex);

    if (left < heapArray.size() && heapArray[left].key < heapArray[min].key && heapArray[right].key > heapArray[left].key)
        min = left;
    
    if (right < heapArray.size() && heapArray[right].key < heapArray[min].key)
        min = right;
    
    if (min != nodeIndex) {
        swap(heapArray[nodeIndex], heapArray[min]);
        fixHeapDown(min);
    }
}

void  MinHeap::fixHeapUp(int nodeIndex) {
    if (nodeIndex && heapArray[getParent(nodeIndex)].key > heapArray[nodeIndex].key)
    {
        swap(heapArray[nodeIndex], heapArray[getParent(nodeIndex)]);
        fixHeapUp(getParent(nodeIndex));
    }
}

void MinHeap::Build(UnDirectedGraph G, unsigned int initial_vertex)
{
    unsigned int i = 0;
    for(GraphVertex &v: G.head)
    {
        vertexsIndexesInHeap.push_back(i);
        
        heapArray.push_back(HeapNode{
            .key = INT32_MAX,
            .vertex{.VertexIndex = v.vertex, .edges = v.edges},
            .indexInHeap = static_cast<unsigned int>(heapArray.size())
            
        });
        i++;
    }
    
    heapArray[initial_vertex].key = 0;
    
//    std::for_each(G.head.begin(), G.head.end(),
//                  [this](GraphVertex &v){ arr.push_back(HeapNode{.vertex{.VertexIndex = v.vertex}, .indexInHeap = static_cast<int>(arr.size() - 1)}); });
    std::for_each(heapArray.rbegin() + (heapArray.size()/2) + 1 , heapArray.rend() , [this](HeapNode &node){fixHeapDown(node.indexInHeap);});
}

HeapNode MinHeap::DeleteMin()
{
    HeapNode min = heapArray.front();
    swap(heapArray.front(), heapArray.back());
    heapArray.pop_back();
    fixHeapDown(0);
    return min;

}


void MinHeap::DecreaseKey(int vertex, int weight) {
    heapArray[vertexsIndexesInHeap[vertex]].key = weight;
    fixHeapUp(vertexsIndexesInHeap[vertex]); // assuming key only decreses;
}
