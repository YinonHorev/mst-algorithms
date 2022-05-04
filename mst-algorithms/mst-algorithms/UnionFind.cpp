//
//  UnionFind.cpp
//  mst-algorithms
//
//  Created by Shiraz Shay on 17/04/2022.
//

#include "UnionFind.hpp"

int UnionFind::Find(int x)
{
    if (arr[x].parent != x)
        arr[x].parent = Find(arr[x].parent);
     
    return arr[x].parent;
}

void UnionFind:: Union(int x, int y)
{
    if (arr[x].size < arr[y].size)
        arr[x].parent = y;
    else if (arr[y].size < arr[x].size)
        arr[y].parent = x;
        
    else {
        arr[y].parent = x;
        arr[x].size++;

        }
}


