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
#include "ISearcher.h"
#include "SearchableSolver.h"
#include "matrixConvert.h"
#include "BestFirstSerch.h"

template<class P, class S>
class MyTestClientHandler : public ClientHandler {
    unsigned long row, colm, counter;
    Splitter splitter;
    Solver<P, S> *solver;
    CacheManger<P, S> *cacheManger;
public:
    MyTestClientHandler(Solver<P, S> *solve, CacheManger<P, S> *cacheManger) {
        this->solver = solve;
        //this->stringConvert = stringConvert;
        this->cacheManger = cacheManger;
    }

    void handleClient(int sockfd) {
        //ISearcher<vector<string>, pair<int, int>> *createSearch = new BestFirstSerch<vector<string>, pair<int, int>>();
        //this->solver = new SearchableSolver(createSearch);
        vector<vector<int>> valuesOfMatrix;
        vector<int> matrixByLine;
        vector<string> valuesOfLine;
        pair<int, int> enterInState;
        pair<int, int> exitInState;
        string line;
        ConnectionManager connectionManager(sockfd);
        //this->cacheManger->loadMap();
        line = connectionManager.readLine();
        while (line != "end\r\n") {
            if (line == "end") {
                break;
            }
            valuesOfLine = this->splitter.splitBy(line);
            this->colm = valuesOfLine.size();
            for (const auto &i : valuesOfLine) {
                matrixByLine.push_back(stoi(i));
            }
            valuesOfLine.clear();
            valuesOfMatrix.push_back(matrixByLine);
            matrixByLine.clear();
            line = connectionManager.readLine();
            counter++;
        }
        exitInState = make_pair(valuesOfMatrix[counter - 1][0], valuesOfMatrix[counter - 1][1]);
        enterInState = make_pair(valuesOfMatrix[counter - 2][0], valuesOfMatrix[counter - 2][1]);
        int **theMatrix = new int *[counter - 2];
        for (int i = 0; i < counter - 2; i++)
            theMatrix[i] = new int[colm];
        for (int i = 0; i < counter - 2; i++) {
            for (int j = 0; j < colm + 1; j++) {
                int score = valuesOfMatrix[i][j];
                theMatrix[i][j] = valuesOfMatrix[i][j];
            }
        }
        auto *m = new matrix(theMatrix, counter - 2, colm + 1, enterInState, exitInState);
        vector<string> solution = this->solver->solve(m);
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i] << " ";
        }
        cout << "\n";
        counter = 0;
        colm = 0;
        row = 0;
        /*
        if (cacheManger->isSolutionExist(*m)) {
            connectionManager->sendLine(cacheManger->getSolutionString(*m));
        } else if (!line.empty()) {
            S solution = this->solver->solve(m);
            this->cacheManger->saveSolution(*m, solution);
            connectionManager->sendLine(this->cacheManger->getSolutionString(*m));
        }
         */
        delete m;
        //delete[] theMatrix;
        //delete this->solver;
    }
};


#endif //MAILSTONE2_MYTESTCLIENTHANDLER_H
