//
//  ConfigurationParser.hpp
//  mst-algorithms
//
//  Created by Yinon Horev on 20/04/2022.
//

#ifndef ConfigurationParser_hpp
#define ConfigurationParser_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include "graph.hpp"

class ConfigurationParser
{
    GraphEdge parseEdge(std::ifstream &fileInput)
    { //TODO: Add validation
        unsigned int startVertex, endVertex;
        int weight;
        fileInput >> startVertex;
        fileInput >> endVertex;
        fileInput >> weight;
        return GraphEdge{.startVertex = startVertex,
                .endVertex = endVertex,
            .weight = weight};
    }
    
    GraphEdge parseEdgeToDelete(std::ifstream &fileInput) {
        unsigned int startVertex, endVertex;
        fileInput >> startVertex;
        fileInput >> endVertex;
        return GraphEdge{.startVertex = startVertex,
                .endVertex = endVertex};
    }
    
    public:
    int numberOfNodesInGraph;
    int numberOfEdgesInGraph;
    std::vector<GraphEdge> edges;
    GraphEdge edgeToDelete;
    
    void DigestFile(const char* filePath)
    {
        std::string line;
        std::ifstream fileInput;
        fileInput.open(filePath);
        
        if (!fileInput.is_open()) {
            std::cout << "File err";
            exit(1);
        }
        
        fileInput >> numberOfNodesInGraph;
        fileInput >> numberOfEdgesInGraph;
        
        for (int i = 0; i < numberOfEdgesInGraph; i++) {
            edges.push_back(parseEdge(fileInput));
        }
        
        edgeToDelete = parseEdgeToDelete(fileInput);
    }
        
};


#endif /* ConfigurationParser_hpp */
