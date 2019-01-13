//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYTESTCLIENTHANDLER_H
#define MAILSTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "FileCacheManager.h"

template<class P, class S>
class MyTestClientHandler : public ClientHandler {
    Solver<P, S> *solver;
    CacheManger<P, S> *cacheManger;
public:
    MyTestClientHandler(Solver<P, S> *solve, CacheManger<P, S> *cacheManger) {
        this->solver = solve;
        //this->stringConvert = stringConvert;
        this->cacheManger = cacheManger;
    }

    void handleClient(ConnectionManager *connectionManager) override;
};

template<class P, class S>
void MyTestClientHandler<P, S>::handleClient(ConnectionManager *connectionManager) {
    string line;
    //this->cacheManger->loadMap();
    line = connectionManager->readLine();
    while (line != "end\r\n") {
        if(line == "end"){
            break;
        }
        if (cacheManger->isSolutionExist(line)) {
            connectionManager->sendLine(cacheManger->getSolution(line));
        }
        else if (!line.empty()) {
            S solution = this->solver->solve(line);
            this->cacheManger->saveSolution(line, solution);
            connectionManager->sendLine(solution);
        }
        line = connectionManager->readLine();
    }

}


#endif //MAILSTONE2_MYTESTCLIENTHANDLER_H
