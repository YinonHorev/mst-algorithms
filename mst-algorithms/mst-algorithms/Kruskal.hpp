//
//  Kruskal.hpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#ifndef Kruskal_hpp
#define Kruskal_hpp

#include <stdio.h>
#include "graph.hpp"
#include "UnionFind.hpp"
#include <vector>
using namespace std;


class Kruskal {
    
    UnDirectedGraph graph;
    
    
    
public:
    Kruskal(UnDirectedGraph graph) {
        this->graph = graph;
        
    }
    int RunKruskal();
    
    
    
private:
    void swapGraphEdge(GraphEdge *a, GraphEdge *b);
    int partition (vector<GraphEdge> &arr, int low, int high);
    void quickSort(vector<GraphEdge> &arr, int low, int high);
};
    
    
   

#endif /* Kruskal_hpp */
