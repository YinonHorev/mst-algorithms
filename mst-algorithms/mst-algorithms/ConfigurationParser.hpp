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
#include "Logger.hpp"

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
            std::cout << "input invalid" << std::endl; //  bad vertex format
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
            std::cout << "input invalid" << std::endl; // bad number of vertex
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
                std::cout << "input invalid" << std::endl; //wrong value
                exit(1);
            }
        }
    
    
    public:
    int numberOfNodesInGraph;
    int numberOfEdgesInGraph;
    std::vector<GraphEdge> edges;
    GraphEdge edgeToDelete;
    std::string outputFilePath;
    
    void ParseFile(const char* filePath)
    {
        std::string line;
        std::ifstream fileInput;
        fileInput.open(filePath);
        
        if (!fileInput.is_open()) {
            std::cout << "input invalid"; // File Not found
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
    
    void ParseInputFromUser(int argc, const char** argv)
    {
        logger = Logger(argv[2])
        ParseFile(argv[1]);
    }
        
};


#endif /* ConfigurationParser_hpp */
