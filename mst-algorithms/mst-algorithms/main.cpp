//
//  main.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 13/04/2022.
//

#include <iostream>
#include "graph.hpp"
#include "UnionFind.hpp"
#include "Kruskal.hpp"
#include "MinHeap.hpp"

using namespace std;




int testUnionFind(){
    int n = 7;
    UnionFind test(n);
    for (int i=0; i <= n; i++) {
          test.MakeSet(i);
      }
      
    test.Union(0, 1);
    test.PrintNode(0);
    test.PrintNode(1);
    test.Union(1, 2);
    test.PrintNode(0);
    test.PrintNode(1);
    test.PrintNode(2);
    test.Union(2, 3);
    test.PrintForest();
    cout << test.Find(3) << endl;
    test.PrintForest();
    return 0;

}


void testKruskal(){
    int size = 7;
    UnDirectedGraph g{};
    GraphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {1,2,16},{1,3,13},{2,3,10},
        {2,4,12},{4,3,9},{3,5,14},
        {5,4,7},{5,6,4},{4,6,20},
    };
    g.MakeEmptyGraph(size);
    for (GraphEdge edge: edges)
    {
        g.AddEdge(edge.startVertex, edge.endVertex, edge.weight);
    }
    
    Kruskal k = Kruskal(g);
    int minWeight = k.RunKruskal();
    cout << minWeight << endl;
    
    
}


static void PrintGraph(UnDirectedGraph &g) {
    std::cout<<"Graph adjacency list "<< std::endl <<"(start_vertex, end_vertex, weight):"<< std::endl;
    for (int i = 0; i < 6; i++)
    {
        // display adjacent vertices of vertex i
        for (GraphEdge edge: g.GetAdjList(i))
        {
            std::cout << "(" << edge.startVertex << ", " << edge.endVertex
            << ", " << edge.weight << ") ";
        }
        std::cout << std::endl;
    }
}

static void TestGraphFunctions() {
    UnDirectedGraph g{};
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
}

static void TestHeapFunctions() {
    UnDirectedGraph g{};
    GraphEdge edges[] = {
        // (x, y, w) -> edge from x to y with weight w
        {0,1,2},{0,2,4},{1,4,3},{2,3,2},{3,1,4},{4,3,3}
    };
    g.MakeEmptyGraph(6);
    for (GraphEdge edge: edges)
    {
        g.AddEdge(edge.startVertex, edge.endVertex, edge.weight);
    }
    
    MinHeap h{};
    h.Build(g, 3);
    while (!h.isEmpty()) {
        std::cout << h.DeleteMin().vertex.weight << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    // graph edges array.
//    TestGraphFunctions();
//    testKruskal(); // fails tests currently
    TestHeapFunctions();
    return 0;
}

