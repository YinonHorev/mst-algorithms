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
    
    
    int RunKruskal(){
        int u ,v ,minimal_weight=0;
        int n = this->graph.GetNumberOfNodes();
        int m = this->graph.GetNumberOfEdges();
        vector<GraphEdge> edgeList = graph.GetEdgesList();
        UnionFind UF = UnionFind(n);
        quickSort(edgeList, 0, m-1);
    
        for (int i = 0 ; i < n ; i++) {
            UF.MakeSet(i);
        }
                
        for (int i = 0 ; i < m ; i++ ) {
            u = UF.Find(edgeList[i].startVertex);
            v = UF.Find(edgeList[i].endVertex);
            if (u != v) {
                minimal_weight += edgeList[i].weight;
                UF.Union(u, v);
            }
        }
        cout << "minimal: " << minimal_weight << endl;
        return minimal_weight;
    }
    
    
    
private:
    void swapGraphEdge(GraphEdge *a, GraphEdge *b);
    int partition (vector<GraphEdge> &arr, int low, int high);
    void quickSort(vector<GraphEdge> &arr, int low, int high);
};
    
    
   

#endif /* Kruskal_hpp */
