//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_CACHEMANGER_H
#define MAILSTONE2_CACHEMANGER_H

#include <string>

using namespace std;
template <class P,class S>
class CacheManger {
public:
    virtual bool isSolutionExist(P problem) = 0;
    virtual string getSolutionString(P problem) = 0;
    virtual void saveSolution(P problem, S solution) = 0;
};


#endif //MAILSTONE2_CACHEMANGER_H
