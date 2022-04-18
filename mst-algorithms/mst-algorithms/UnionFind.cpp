//
//  UnionFind.cpp
//  mst-algorithms
//
//  Created by Shiraz Shay on 17/04/2022.
//

#include "UnionFind.hpp"

void UnionFind::PrintForest() {
    for (int i=0; i < this->arrSize; i++) {
        cout << "i = "<< i << endl;
        cout << "parent = " << arr[i].parent << endl;
        cout << "size = " << arr[i].size << endl;

    }
}

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

void UnionFind::PrintNode(int x){
    cout << "arr["<<x<<"].parent = " << arr[x].parent << endl;
    cout << "arr["<<x<<"].size = " << arr[x].size << endl;
    
}


