//
//  graph.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#include "graph.hpp"


void UnDirectedGraph::MakeEmptyGraph(unsigned int NumberOfNodes)
{
    NumberOfNodes++; 
    head.resize(NumberOfNodes);
    for (int i = 0; i < NumberOfNodes; i++) {
        head[i].vertex = i;
    }
    AddEdge(0, 1, 0); // workaround for not starting at vertex 0;
    this->NumberOfNodes = NumberOfNodes;
}

bool UnDirectedGraph::IsAdjacent(unsigned int vertex_u, unsigned int vertex_v)
{
    for (GraphEdge edge: head[vertex_u].edges)
    {
        if (edge.endVertex == vertex_v)
            return true;
    }
    return false;
}
//
std::vector<GraphEdge> UnDirectedGraph::GetAdjList(unsigned int vertex_v)
{
    return head[vertex_v].edges;
}
//
void UnDirectedGraph::AddEdge(unsigned int vertex_u, unsigned int vertex_v, int weight)
{
    head[vertex_u].edges.push_back(makeEdge(vertex_u,vertex_v, weight));
    head[vertex_v].edges.push_back(makeEdge(vertex_v,vertex_u, weight));
    this->NumberOfEdges++;
}

void UnDirectedGraph::AddEdge(GraphEdge edge)
{
    head[edge.startVertex].edges.push_back(edge);
    head[edge.endVertex].edges.push_back(makeEdge(edge.endVertex,
                                                  edge.startVertex,
                                                  edge.weight));
    this->NumberOfEdges++;
}

GraphEdge UnDirectedGraph::makeEdge(unsigned int vertex_u, unsigned int vertex_v, int weight)
{
    return  {.startVertex = vertex_u,.endVertex = vertex_v, .weight=weight};
}

void UnDirectedGraph::RemoveEdge(unsigned int vertex_u, unsigned int vertex_v)
{
    head[vertex_u].edges.erase(std::remove_if(head[vertex_u].edges.begin(),
                                     head[vertex_u].edges.end(),
                               [=](GraphEdge element) { return element.endVertex == vertex_v; }),
                      head[vertex_u].edges.end());
    head[vertex_v].edges.erase(std::remove_if(head[vertex_v].edges.begin(),
                                     head[vertex_v].edges.end(),
                               [=](GraphEdge element) { return element.endVertex == vertex_u; }),
                      head[vertex_v].edges.end());
    this->NumberOfEdges--;
}

bool UnDirectedGraph::IsGraphConnected()
{
    // DFS
    std::vector<Color> colors;
    colors.resize(NumberOfNodes);
    for (Color &color : colors) {
        color = white;
    }
    
    for (unsigned int i = 0; i < NumberOfNodes; i++) {
        if (colors[i] == white) {
            currentRoot = i;
            visit(i, colors);
        }
    }
    
    for (Color &color : colors) {
        if (color != black) {
            return false;
        }
    }
    return true;
}

void UnDirectedGraph::visit(unsigned int vertex , std::vector<Color> &colors)
{
    colors[vertex] = grey;
    
    for (GraphEdge edge : GetAdjList(vertex)) {
        if (colors[edge.endVertex] == white) {
            visit(edge.endVertex, colors);
        }
    }
    
    colors[vertex] = black;
}

