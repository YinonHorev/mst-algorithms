//
//  Prim.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#include <iostream>
#include "Prim.hpp"
#include "graph.hpp"
#include "MinHeap.hpp"
#include <vector>

void PrimMST(UnDirectedGraph graph)
{
    unsigned int v0 = 0;
    int numberOfVertexesInGraph = (int)graph.head.size(); // Get the number of vertices in graph
    std::vector<int> parents, keys; // Array to store constructed MST
    std::vector<bool> inMstTree;
    inMstTree.resize(numberOfVertexesInGraph);
    parents.resize(numberOfVertexesInGraph);
    keys.resize(numberOfVertexesInGraph); // Key values used to pick minimum weight edge in cut
    for(int &key : keys) key = INT32_MAX;
    keys[v0] = 0;
 
    // Initialize min heap with all vertices. Key value of
    // all vertices (except 0th vertex) is initially infinite
    MinHeap heap{};
    // Make key value of 0th vertex as 0 so that it
    // is extracted first
    heap.Build(graph, v0);
    
 
    // In the following loop, min heap contains all nodes
    // not yet added to MST.
    while (!heap.isEmpty()) {
        // Extract the vertex with minimum key value
        HeapNode u = heap.DeleteMin();
        
        int vertexUIndex = u.vertex.VertexIndex; // Store the extracted vertex number
        inMstTree[vertexUIndex] = true;
 
        // Traverse through all adjacent vertices of u (the extracted
        // vertex) and update their key values
        for (GraphEdge e : u.vertex.edges) {
            unsigned int v = e.endVertex;
            int weight = e.weight;
            // If v is not yet included in MST and weight of u-v is
            // less than key value of v, then update key value and
            // parent of v
            if (not inMstTree[v] and weight < keys[v]) {
                keys[v] = weight;
                parents[v] = u.vertex.VertexIndex;
                heap.DecreaseKey(v, weight); // TODO: Decrese key should get endVertex index
            }
        }

 
       
            
        }
    int sum = 0;
    for(int key: keys) sum += key;
    std::cout << "Prim " << sum;
}
 
    // print edges of MST
    
