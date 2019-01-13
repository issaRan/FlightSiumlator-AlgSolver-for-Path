#include <iostream>
#include "Solver.h"
#include "stringReverser.h"
#include "DFS.h"
#include "ISearchable.h"
#include "ISearcher.h"
#include "matrix.h"
#include "matrixString.h"
#include "BFS.h"
#include "BestFirstSerch.h"
#include "Astar.h"

//#include "CommonSearcher.h"
int main() {
    int **theMap = new int *[3];
    for (int i = 0; i < 3; i++)
        theMap[i] = new int[3];
    theMap[0][0] = 1;
    theMap[0][1] = 2;
    theMap[0][2] = 100;
    theMap[1][0] = 200;
    theMap[1][1] = 3;
    theMap[1][2] = 4;
    theMap[2][0] = 1000;
    theMap[2][1] = 500000;
    theMap[2][2] = 5;
    ISearchable<pair<int, int>> *m = new matrix(theMap, 3, 3, make_pair(0,0), make_pair(2,2));
    ISearcher<vector<string>, pair<int, int>> *s = new Astar<vector<string>, pair<int,
            int>>();
    vector<string> sason = s->search(m);
    for (string i : sason){
        cout << i << endl;
    }
    //CommonSearcher<string,pair<int,int>>* salim = new  DFS<string,pair<int,int>>();
    //ISearchable<pair<int,int>> *Is = new theMap();
    //salim->search()
}