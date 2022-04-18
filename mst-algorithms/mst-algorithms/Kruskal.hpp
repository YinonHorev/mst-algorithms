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
using namespace std;


class Kruskal {
    
    DirectedGraph graph;
    
    
    
public:
    Kruskal(DirectedGraph graph) {
        this->graph = graph;
        
    }
    
    
    int RunKruskal(){
        int u ,v ,minimal_weight=0;
        int n = this->graph.GetNumberOfNodes();
        int m = this->graph.GetNumberOfEdges();
        GraphEdge* edgeList = this->getEdgeList(this->graph,n,m);
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
        free(edgeList);
        return minimal_weight;
    }
    
    
    
private:
    void swapGraphEdge(GraphEdge *a, GraphEdge *b);
    int partition (GraphEdge * arr, int low, int high);
    void quickSort(GraphEdge * arr, int low, int high);
    GraphEdge* getEdgeList(DirectedGraph graph , int NumOfNodes, int NumOfEdges)
    {
        GraphEdge* edgeList = (GraphEdge*)malloc(NumOfEdges * sizeof(GraphEdge));
        int counter = 0;
        for (int i=0; i < NumOfNodes; i++) {
            for (GraphEdge edge: graph.GetAdjList(i)) {
                edgeList[counter++] = edge;
                
                }
            }
    ;
        return edgeList;
    }
    

    
};
    
    
   

#endif /* Kruskal_hpp */
