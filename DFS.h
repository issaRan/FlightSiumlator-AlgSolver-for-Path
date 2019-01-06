//
// Created by issa on 1/5/19.
//

#ifndef MAILSTONE2_DFS_H
#define MAILSTONE2_DFS_H


#include <stack>
#include "Searcher.h"

template<class S, class T>
class DFS : public Searcher<S, T> {
    S search(ISearchable<T> *searchable);
};

template<class S, class T>
S DFS<S, T>::search(ISearchable<T> *searchable) {
    unordered_set<State<T>> closet;
    stack<State<T>> stackForDFS;
    stackForDFS.push(searchable->getInitialState());
    while (!stackForDFS.empty()) {
        State<T> temp = stackForDFS.top();
        stackForDFS.pop();
        if (!closet.count(temp)) {
            closet.insert(temp);
        }
        if(searchable->isGoalState(temp)){
            this->backTrace(temp);
        }
        vector<State<T>> state = searchable->getAllPossibleState(temp);
        for(State<T> s:state){
            if(!closet.count(s)){
                stackForDFS.push(s);
            }
        }
    }
}

#endif //MAILSTONE2_DFS_H
