#ifndef MAILSTONE2_ISEARCHER_H
#define MAILSTONE2_ISEARCHER_H

#include "ISearchable.h"
#include "Solution.h"
using namespace std;
template<class S,class T>
class ISearcher {
    virtual S search(ISearchable<T>* ISearchable) = 0;
    virtual int getNumberOfNodesEvaluted() = 0;
};

#endif //MAILSTONE2_ISEARCHER_H
