//
//  main.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 13/04/2022.
//

#include <iostream>
#include "graph.hpp"


static void PrintGraph(DirectedGraph &g) {
    std::cout<<"Graph adjacency list "<< std::endl <<"(start_vertex, end_vertex, weight):"<< std::endl;
    for (int i = 0; i < 6; i++)
    {
        // display adjacent vertices of vertex i
        for (GraphEdge edge: g.GetAdjList(i))
        {
            std::cout << "(" << i << ", " << edge.startVertex
            << ", " << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // graph edges array.
    DirectedGraph g{};
    GraphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    g.MakeEmptyGraph(6);
    for (GraphEdge edge: edges)
    {
        g.AddEdge(edge.startVertex, edge.endVertex, edge.weight);
    }
    
    PrintGraph(g);
    
    g.RemoveEdge(0, 1);
    
    PrintGraph(g);
    return 0;
}
