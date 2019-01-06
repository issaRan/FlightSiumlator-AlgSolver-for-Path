#ifndef MAILSTONE2_BESTFIRSTSERCH_H
#define MAILSTONE2_BESTFIRSTSERCH_H

#include "ISearcher.h"
#include "Searcher.h"

template <class S,class T>
class BestFirstSerch :public Searcher<S,T>{
    S search(ISearchable<T>* searchable);
};



#endif //MAILSTONE2_BESTFIRSTSERCH_H
