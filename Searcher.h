#ifndef MAILSTONE2_SEARCHER_H
#define MAILSTONE2_SEARCHER_H

#include "State.h"
#include "ISearcher.h"
#include <queue>
#include <list>
#include <unordered_set>
template<typename T>
class Searcher : public ISearcher<T> {
    int NumberOfNodesEvaluated{};
    unordered_set <State<T>> closed;
protected:
    priority_queue <State<T>> openList;
    State<T> popOpenList(){
        NumberOfNodesEvaluated++;
        if(!this->openList.empty()){
            State<T> emptyTheList = this->openList.top();
            this->openList.pop();
            return emptyTheList;
        }
        return NULL;
    }
    void addToOpenList(State<T> state){
        openList.push(state);
    }
    bool openContains(State<T> state){
        for(State<T> i:openList){
            if(i.operator==(state)){
                return true;
            }
        }
        return false;
    }
    //TODO edit
    Solution<T> backTrace(State<T> start,State<T> final){
        Solution<T> solution;
        while (start != final){
            solution.
            final = final.getState();
        }
        return solution;
    }
    //TODO addSet
    void adjustPriority(priority_queue<State<T>> openList,State<T> state){
        State<T> nearByState = NULL;
        for(auto i : openList){
            if(nearByState == state){
                openList.pop();
                setDeterminedCost(nearByState);
                openList.push(nearByState);
                return;
            }
        }
    }
public:
    Searcher() : NumberOfNodesEvaluated(0) {}
    virtual Solution<T> search(ISearchable<T>* searchable) = 0;
    int openListSize(){
        return static_cast<int>(openList.size());
    }
    int getNumberOfNodesEvaluated(){
        return this->NumberOfNodesEvaluated;
    }
};

#endif //MAILSTONE2_SEARCHER_H
