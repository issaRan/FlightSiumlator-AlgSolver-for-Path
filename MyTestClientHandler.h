//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_MYTESTCLIENTHANDLER_H
#define MAILSTONE2_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManger.h"

template <class P,class S>
class MyTestClientHandler : public ClientHandler{
    Solver<P,S> *solver;
    CacheManger<P,S> *cacheManger;
public:
    MyTestClientHandler(Solver<P,S> *solver,CacheManger<P,S> *cacheManger){
        this->solver = solver;
        this->cacheManger = cacheManger;
    }
    void handleCLient(string str);
};


#endif //MAILSTONE2_MYTESTCLIENTHANDLER_H
