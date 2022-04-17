//
//  main.cpp
//  mst-algorithms
//
//  Created by Yinon Horev on 13/04/2022.
//

#include <iostream>
#include "graph.hpp"
#include "UnionFind.hpp"
using namespace std;



int main(int argc, const char * argv[]) {
    int n = 7;
    UnionFind test(n);
    for (int i=0; i <= n; i++) {
          test.MakeSet(i);
      }
      
    test.Union(0, 1);
    test.PrintNode(0);
    test.PrintNode(1);
    test.Union(1, 2);
    test.PrintNode(0);
    test.PrintNode(1);
    test.PrintNode(2);
    test.Union(2, 3);
    test.PrintForest();
    cout << test.Find(3) << endl;
    test.PrintForest();
    return 0;

}

