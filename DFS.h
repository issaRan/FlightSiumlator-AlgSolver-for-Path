//
// Created by issa on 1/5/19.
//

#ifndef MAILSTONE2_DFS_H
#define MAILSTONE2_DFS_H


#include "Searcher.h"
template <class T>
class DFS : public Searcher<T>{
    Solution<T> search(ISearchable<T>* searchable);
};



#endif //MAILSTONE2_DFS_H
