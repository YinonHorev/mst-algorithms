//
//  graph.hpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <vector>

// structure to store edges
struct GraphEdge {
    unsigned int startVertex, endVertex;
    int weight;
};

class DirectedGraph{
    
    GraphEdge makeEdge(unsigned int vertex_u, unsigned int vertex_v, int weight);
    int NumberOfNodes;  // number of nodes in the graph
    int NumberOfEdges=0;
    
    
public:
    
    std::vector<std::vector<GraphEdge>> head;                //adjacency list as array of pointers
    
    int GetNumberOfNodes() {return this->NumberOfNodes;};
    int GetNumberOfEdges() {return this->NumberOfEdges;};
    void MakeEmptyGraph(unsigned int NumberOfNodes);
    bool IsAdjacent(unsigned int vertex_u, unsigned int vertex_v);
    std::vector<GraphEdge> GetAdjList(unsigned int vertex_v);
    void AddEdge(unsigned int vertex_u, unsigned int vertex_v, int weight);
    void RemoveEdge(unsigned int vertex_u, unsigned int vertex_v);
    

};

#endif /* graph_hpp */
