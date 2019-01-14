//
// Created by issa on 1/6/19.
//

#ifndef MAILSTONE2_ASTAR_H
#define MAILSTONE2_ASTAR_H

#include "Searcher.h"

template <class solution,class T>
class Astar :public Searcher<solution,T> {
    solution search(ISearchable<T>* searchable);
};

template<class solution, class T>
solution Astar<solution, T>::search(ISearchable<T> *searchable) {

}


#endif //MAILSTONE2_ASTAR_H
