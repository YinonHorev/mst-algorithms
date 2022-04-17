//
//  graph.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#include "graph.hpp"

using namespace std;

DiaGraph::DiaGraph(graphEdge edges[], int n, int N)
{
    // allocate new node
    head = new adjNode*[N]();
    this->N = N;
    // initialize head pointer for all vertices
    for (int i = 0; i < N; ++i)
        head[i] = nullptr;
    // construct directed graph by adding edges to it
    for (unsigned i = 0; i < n; i++)  {
        int start_ver = edges[i].start_ver;
        int end_ver = edges[i].end_ver;
        int weight = edges[i].weight;
        // insert in the beginning
        adjNode* newNode = getAdjListNode(end_ver, weight, head[start_ver]);
         
                    // point head pointer to new node
        head[start_ver] = newNode;
         }
}

adjNode* DiaGraph::getAdjListNode(int value, int weight, adjNode* head)
{
     adjNode* newNode = new adjNode;
     newNode->val = value;
     newNode->cost = weight;
      
     newNode->next = head;   // point new node to current head
     return newNode;
}
