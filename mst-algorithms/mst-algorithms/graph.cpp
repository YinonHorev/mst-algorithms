//
//  graph.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#include "graph.hpp"


void DirectedGraph::MakeEmptyGraph(unsigned int NumberOfNodes)
{
    head.resize(NumberOfNodes);
    this->NumberOfNodes = NumberOfNodes;
}

bool DirectedGraph::IsAdjacent(unsigned int vertex_u, unsigned int vertex_v)
{
    for (GraphEdge edge: head[vertex_u].edges)
    {
        if (edge.endVertex == vertex_v)
            return true;
    }
    return false;
}
//
std::vector<GraphEdge> DirectedGraph::GetAdjList(unsigned int vertex_v)
{
    return head[vertex_v].edges;
}
//
void DirectedGraph::AddEdge(unsigned int vertex_u, unsigned int vertex_v, int weight)
{
    head[vertex_u].edges.push_back(makeEdge(vertex_u,vertex_v, weight));
    this->NumberOfEdges++;
}
//
GraphEdge DirectedGraph::makeEdge(unsigned int vertex_u, unsigned int vertex_v, int weight)
{
    return  {.startVertex = vertex_u,.endVertex = vertex_v, .weight=weight};
}
//
//
void DirectedGraph::RemoveEdge(unsigned int vertex_u, unsigned int vertex_v)
{
    head[vertex_u].edges.erase(std::remove_if(head[vertex_u].edges.begin(),
                                     head[vertex_u].edges.end(),
                               [=](GraphEdge element) { return element.endVertex == vertex_v; }),
                      head[vertex_u].edges.end());
    this->NumberOfEdges--;
}

