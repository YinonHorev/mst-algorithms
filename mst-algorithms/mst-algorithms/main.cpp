#include <iostream>
#include "graph.hpp"
#include "Kruskal.hpp"
#include "Prim.hpp"
#include "ConfigurationParser.hpp"
#include "Logger.hpp"


static void IsGraphConnected(UnDirectedGraph &G) {
    if (not (G.IsGraphConnected()))
    {
        Logger::getInstance() << "No MST" << "\n";
        exit(0);
    }
}

static void RunKruskal(const UnDirectedGraph &G) {
    Kruskal kr = Kruskal(G);
    kr.RunKruskal();
}

static UnDirectedGraph BuildGraph(const ConfigurationParser &config) {
    UnDirectedGraph G;
    G.MakeEmptyGraph(config.numberOfNodesInGraph);
    for(GraphEdge edge : config.edges) G.AddEdge(edge);
    return G;
}

int main(int argc, const char * argv[]) {
    Logger::SetPathToLogFile(argv[2]);
        
    ConfigurationParser config;
    config.ParseInputFromUser(argc, argv);
    
    UnDirectedGraph G = BuildGraph(config);
    IsGraphConnected(G);
    PrimMST(G);
    RunKruskal(G);
    
    G.RemoveEdge(config.edgeToDelete.startVertex, config.edgeToDelete.endVertex);
    IsGraphConnected(G);
    RunKruskal(G);
    
    return 0;
}

