//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYTESTCLIENTHANDLER_H
#define MAILSTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"
#include "Splitter.h"
#include "matrix.h"

template<class P, class S>
class MyTestClientHandler : public ClientHandler {
    Splitter splitter;
    Solver<P, S> *solver;
    CacheManger<P, S> *cacheManger;
public:
    MyTestClientHandler(Solver<P, S> *solve, CacheManger<P, S> *cacheManger) {
        this->solver = solve;
        this->cacheManger = cacheManger;
    }

    void handleClient(ConnectionManager *connectionManager){
        unsigned long row, colm;
        unsigned long counter = 0;
        vector<vector<int>> valuesOfMatrix;
        vector<int> matrixByLine;
        vector<string> valuesOfLine;
        pair<int, int> enterInState;
        pair<int, int> exitInState;
        string line;
        //this->cacheManger->loadMap();
        line = connectionManager->readLine();
        while (line != "end\r\n") {
            if (line == "end") {
                break;
            }
            valuesOfLine = this->splitter.splitBy(line);
            for (const auto &i : valuesOfLine) {
                matrixByLine.push_back(stoi(i));
            }
            valuesOfLine.clear();
            valuesOfMatrix.push_back(matrixByLine);
            matrixByLine.clear();
            line = connectionManager->readLine();
            counter++;
        }
        colm = valuesOfMatrix[0].size();
        exitInState = make_pair(valuesOfMatrix[counter - 1][0], valuesOfMatrix[counter - 1][1]);
        enterInState = make_pair(valuesOfMatrix[counter - 2][0], valuesOfMatrix[counter - 2][1]);
        int **theMatrix = new int *[row];
        for (int i = 0; i < row; i++)
            theMatrix[i] = new int[colm];
        matrix *m = new matrix(theMatrix, row, colm, enterInState, exitInState);
        if (cacheManger->isSolutionExist(*m)) {
            connectionManager->sendLine(cacheManger->getSolutionString(*m));
        } else if (!line.empty()) {
            S solution = this->solver->solve(m);
            this->cacheManger->saveSolution(*m, solution);
            connectionManager->sendLine(this->cacheManger->getSolutionString(*m));
        }
    }
};


#endif //MAILSTONE2_MYTESTCLIENTHANDLER_H
