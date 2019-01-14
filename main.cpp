#include <iostream>
#include "Solver.h"
#include "ISearchable.h"
#include "Server.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "stringReverser.h"
#include "convertTheString.h"
#include "matrix.h"
#include "ISearcher.h"
#include "BestFirstSerch.h"
#include "BFS.h"
#include "DFS.h"
#include "matrixConvert.h"
#include "SearchableSolver.h"

//#include "Searcher.h"
//template <class p,class solution>
int main(int argc, char* argv[]) {
    int port = 5400;
    StringConvert<matrix,vector<string>> *convert = new matrixConvert<matrix,vector<string>>();
    server_side::Server *s = new MySerialServer();
    ISearcher<vector<string>, pair<int, int>> *sason = new BestFirstSerch<vector<string>, pair<int, int>>();
    CacheManger<matrix,vector<string>> *cacheManger = new FileCacheManager<matrix,vector<string>>(convert);
    Solver<matrix,vector<string>> *rev = new SearchableSolver(sason);
    ClientHandler *c = new MyTestClientHandler<matrix,vector<string>>(rev,cacheManger);
    s->open(port, c);
    /*
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
    ISearcher<vector<string>, pair<int, int>> *s = new BestFirstSerch<vector<string>, pair<int,
            int>>();
    vector<string> sason = s->search(m);
    for (string i : sason){
        cout << i << endl;
    }
     */
    /*
    int port = 5400;
    StringConvert<string,string> *convert = new convertTheString<string,string>();
    server_side::Server *s = new MySerialServer();
    CacheManger<string,string> *cacheManger = new FileCacheManager<string,string>(convert);
    Solver<string, string> *rev = new stringReverser<string, string>();
    ClientHandler *c = new MyTestClientHandler<string, string>(rev,cacheManger);
    s->open(port, c);
     */
    // sleep(10);
    //s->close();
    /*
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
     */
}