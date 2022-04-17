//
//  graph.hpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
// structure to store edges
struct graphEdge {
    int start_ver, end_ver, weight;
};

// stores adjacency list items
struct adjNode {
    int val, cost;
    adjNode* next;
};

class DiaGraph{
    // insert new nodes into adjacency list from given graph
    adjNode* getAdjListNode(int value, int weight, adjNode* head);
    int N;  // number of nodes in the graph
public:
    adjNode **head;                //adjacency list as array of pointers
    // Constructor
    DiaGraph(graphEdge edges[], int n, int N);
    // Destructor
    ~DiaGraph() {
    for (int i = 0; i < N; i++)
        delete[] head[i];
        delete[] head;
     }
};

#endif /* graph_hpp */
