//
// Created by issa on 1/4/19.
//

#include "BestFirstSerch.h"
template<class T>
Solution<T> BestFirstSerch<T>::search(ISearchable<T> *searchable) {
    addToOpenList(searchable->getInitialState());
    unordered_set<State<T>> closeSet = new unordered_set<State<T>>();
    while (this->openListSize() > 0){
        State<T> n = this->popOpenList();
        closeSet.insert(n);
        if(n.operator==(searchable->isGoalState()))
            return this->backTrace();
        list<State<T>> successors = searchable->getAllPossibleState(n);
        for(State<T> s : successors){
            if(!closeSet.count(s) && !this->openContains(s)){
                this->addToOpenList(s);
            }else{

            }
        }
    }
}