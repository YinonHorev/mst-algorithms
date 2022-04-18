//
//  Kruskal.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 17/04/2022.
//

#include "Kruskal.hpp"


void Kruskal::swapGraphEdge(GraphEdge *a, GraphEdge *b)
{
    GraphEdge t = *a;
    *a = *b;
    *b = t;
}
 

int Kruskal::partition (GraphEdge * arr, int low, int high)
{

    int pivot = arr[high].weight; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j].weight < pivot)
        {
            i++; // increment index of smaller element
            swapGraphEdge(&arr[i], &arr[j]);
        }
    }
    swapGraphEdge(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void Kruskal::quickSort(GraphEdge * arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}