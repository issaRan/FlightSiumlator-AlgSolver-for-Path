#ifndef MAILSTONE2_BESTFIRSTSERCH_H
#define MAILSTONE2_BESTFIRSTSERCH_H

#include "ISearcher.h"
#include "Searcher.h"

template <class T>
class BestFirstSerch :public Searcher<T>{
    Solution<T> search(ISearchable<T>* searchable);
};



#endif //MAILSTONE2_BESTFIRSTSERCH_H
