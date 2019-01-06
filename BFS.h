//
// Created by issa on 1/6/19.
//

#ifndef MAILSTONE2_BFS_H
#define MAILSTONE2_BFS_H

#include "Searcher.h"

template <class solution,class T>
class BFS : public Searcher<solution,T>{
    solution search(ISearchable<T>* searchable);
};

template<class solution, class T>
solution BFS<solution, T>::search(ISearchable<T> *searchable) {

}


#endif //MAILSTONE2_BFS_H
