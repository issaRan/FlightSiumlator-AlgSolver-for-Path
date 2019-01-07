#include <iostream>
#include "Solver.h"
#include "stringReverser.h"
//#include "DFS.h"
#include "ISearchable.h"
#include "matrix.h"
#include "matrixString.h"
//#include "Searcher.h"
int main() {
    int** theMap = new int*[2];
    for (int i = 0; i < 2; i++)
        theMap[i] = new int[3];
    theMap[0][0] = 1;
    theMap[0][1] = 2;
    theMap[0][2] = 3;
    theMap[1][0] = 4;
    theMap[1][1] = 5;
    theMap[1][2] = 7;
    matrixString a;
    auto * m = new matrix(theMap,2,3);
    cout << a.ProblemToString(m) << endl;
     //Searcher<string,pair<int,int>>* salim = new  DFS<string,pair<int,int>>();
     //ISearchable<pair<int,int>> *Is = new theMap();
     //salim->search()
}