//
// Created by issa on 1/13/19.
//

#ifndef MAILSTONE2_SEARCHABLESOLVER_H
#define MAILSTONE2_SEARCHABLESOLVER_H

#include "Solver.h"
#include "ISearcher.h"
#include "ISearchable.h"
#include "matrix.h"

//template<class S, class T>
class SearchableSolver : public Solver<matrix, vector<string>> {
    ISearcher<vector<string>,pair<int,int>> *searcher;
    //ISearchable<T> *iSearchable;
public:
    SearchableSolver(ISearcher<vector<string>,pair<int,int>> * search){
        this->searcher = search;
    }
    vector<string> solve(matrix* problem){
        return this->searcher->search(problem);
    }
};


#endif //MAILSTONE2_SEARCHABLESOLVER_H
