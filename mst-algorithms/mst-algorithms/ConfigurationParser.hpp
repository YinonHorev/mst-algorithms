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
#include <sstream>
#include <stdio.h>
#include <vector>
#include <string>
#include "graph.hpp"

using namespace std;

class ConfigurationParser
{
    
    GraphEdge parseEdge(std::ifstream &fileInput)
    {
        unsigned int startVertex, endVertex;
        int weight;
        string line;
        int numOfValidInputs;
        getline(fileInput,line);
        numOfValidInputs = sscanf(line.c_str(), "%d %d %d", &startVertex, &endVertex, &weight);
        if (numOfValidInputs != 3){
            std::cout << "Parse err - bad vertex format\n";
            exit(1);
        }
        return GraphEdge{.startVertex = startVertex,
                    .endVertex = endVertex,
                .weight = weight};
    }
    
    

    
    GraphEdge parseEdgeToDelete(std::ifstream &fileInput) {
        unsigned int startVertex, endVertex;
        int weight;
        fileInput >> startVertex;
        fileInput >> endVertex;
        if (fileInput >> weight) {
            std::cout << "Parse err - bad number of vertex";
            exit(1);
            
        }
            
        return GraphEdge{.startVertex = startVertex,
                .endVertex = endVertex};
    }
    
   
    
    void readIntFromFile(std::ifstream &fileInput,int & intToRead){
        string line ;
        getline(fileInput,line);
        int numOfValidInputs = sscanf(line.c_str(), "%d", &intToRead);
        if (numOfValidInputs != 1)
            {
                std::cout << "Parse err - wrong value";
                exit(1);
            }
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
        
        readIntFromFile(fileInput,numberOfNodesInGraph);
        readIntFromFile(fileInput,numberOfEdgesInGraph);

        
        for (int i = 0; i < numberOfEdgesInGraph; i++)
        {
            edges.push_back(parseEdge(fileInput));
        }
     
        edgeToDelete = parseEdgeToDelete(fileInput);
        fileInput.close();

        
    }
        
};


#endif /* ConfigurationParser_hpp */
