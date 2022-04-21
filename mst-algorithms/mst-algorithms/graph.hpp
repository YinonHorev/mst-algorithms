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

enum Color { white, grey, black };

struct GraphVertex {
    unsigned int vertex;
    std::vector<GraphEdge> edges;
};

class UnDirectedGraph{
    
    GraphEdge makeEdge(unsigned int vertex_u, unsigned int vertex_v, int weight);
    void DFS();
    void visit(unsigned int vertex, std::vector<Color> &colors);
    int NumberOfNodes;  // number of nodes in the graph
    int NumberOfEdges=0;
    unsigned int currentRoot;
    
    
public:
    
    std::vector<GraphVertex> head;                //adjacency list as array of pointers
    
    int GetNumberOfNodes() {return this->NumberOfNodes;};
    int GetNumberOfEdges() {return this->NumberOfEdges;};
    void MakeEmptyGraph(unsigned int NumberOfNodes);
    bool IsAdjacent(unsigned int vertex_u, unsigned int vertex_v);
    bool IsGraphConnected();
    std::vector<GraphEdge> GetAdjList(unsigned int vertex_v);
    void AddEdge(unsigned int vertex_u, unsigned int vertex_v, int weight);
    void AddEdge(GraphEdge edge);
    void RemoveEdge(unsigned int vertex_u, unsigned int vertex_v);
    

};

#endif /* graph_hpp */
