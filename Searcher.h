#ifndef MAILSTONE2_SEARCHER_H
#define MAILSTONE2_SEARCHER_H

#include "State.h"
#include "ISearcher.h"
#include <queue>
#include <list>
#include <unordered_set>
#include <sstream>

template<class S, class T>
class Searcher : public ISearcher<S, T> {
    int NumberOfNodesEvaluated{};
    unordered_set<State<T>> closed;
protected:
    priority_queue<State<T>> openList;

    State<T> popOpenList() {
        NumberOfNodesEvaluated++;
        if (!this->openList.empty()) {
            State<T> emptyTheList = this->openList.top();
            this->openList.pop();
            return emptyTheList;
        }
        return NULL;
    }

    void addToOpenList(State<T> state) {
        openList.push(state);
    }

    bool openContains(State<T> state) {
        for (State<T> i:openList) {
            if (i.operator==(state)) {
                return true;
            }
        }
        return false;
    }

    //TODO edit
    S backTrace(State<T> final) {
        S solution;
        ostringstream ss;
        ss << final.getState();
        while (final = final.getFather() != NULL) {
            ss << "->" >> final.getState();
        }
        solution = ss.str();
        return solution;
    }

    //TODO addSet
    void adjustPriority(priority_queue<State<T>> openList, State<T> state) {
        State<T> nearByState = NULL;
        for (auto i : openList) {
            if (nearByState == state) {
                openList.pop();
                setDeterminedCost(nearByState);
                openList.push(nearByState);
                return;
            }
        }
    }

public:
    Searcher() : NumberOfNodesEvaluated(0) {}

    virtual S search(ISearchable<T> *searchable) = 0;

    int openListSize() {
        return static_cast<int>(openList.size());
    }

    int getNumberOfNodesEvaluated() {
        return this->NumberOfNodesEvaluated;
    }
};

#endif //MAILSTONE2_SEARCHER_H
