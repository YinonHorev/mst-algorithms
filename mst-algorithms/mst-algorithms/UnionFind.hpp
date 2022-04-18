//
//  UnionFind.hpp
//  mst-algorithms
//
//  Created by Shiraz Shay on 17/04/2022.
//

#ifndef UnionFind_hpp
#define UnionFind_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct UnionFindNode {
    int parent;
    int size;
};

class UnionFind {
    
    int arrSize;
    UnionFindNode *arr;

public:
    
    UnionFind(int size)
    {
        arr = (UnionFindNode*)malloc(size * sizeof(UnionFindNode));
        this->arrSize = size;
    }

    void MakeSet(int i)
    {
        arr[i].parent = i;
        arr[i].size = 1;
        
    }
    
    int Parent(int x){
        return arr[x].parent;
    }
     
    // Finds with path compression
    int Find(int x);
    //Union by size
    void Union(int x, int y);
    
    void PrintForest() ;
    void PrintNode(int x);


};


#endif /* UnionFind_hpp */
