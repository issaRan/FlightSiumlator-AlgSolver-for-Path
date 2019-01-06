//
// Created by issa on 1/6/19.
//

#ifndef MAILSTONE2_HILLCLIMBING_H
#define MAILSTONE2_HILLCLIMBING_H

#include "ISearchable.h"
#include "Searcher.h"

template <class S,class T>
class HillClimbing :public Searcher<S,T>{
    S search(ISearchable<T>* searchable);
};

template<class S, class T>
S HillClimbing<S, T>::search(ISearchable<T> *searchable) {

}


#endif //MAILSTONE2_HILLCLIMBING_H
