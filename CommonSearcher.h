#ifndef MAILSTONE2_SEARCHER_H
#define MAILSTONE2_SEARCHER_H

#include "State.h"
#include "ISearcher.h"
#include <queue>
#include <list>
#include <unordered_set>
#include <sstream>
#include <set>
#include <algorithm>

template<class S, class T>
class CommonSearcher : public ISearcher<S, T> {
protected:
    //multiset<State<T> *> *opened;
    unordered_set<State<T> *> closed;
    int NumberOfNodesEvaluated{};

public:
    CommonSearcher() : NumberOfNodesEvaluated(0) {}

    virtual S search(ISearchable<T> *searchable) = 0;

    int getNumberOfNodesEvaluated() {
        return this->NumberOfNodesEvaluated;
    }

    // Pop and return the top vertex in the opened.
    State<T> *popOpenList() {
        if (!this->opened.empty()) {
            this->NumberOfNodesEvaluated++;
            State<T> *popped = this->opened.top();
            this->opened.pop();
            return popped;
        }
        return NULL;
    }

    // Add a vertex to the opened.
    void addToOpenList(State<T> *state) {
        this->opened.push(state);
    }

    // Check if opened contains a vertex.
    bool openContains(State<T> *state) {
        for (typename multiset<State<T> *>::iterator it = this->opened.begin(); it != this->opened.end(); it++) {
            if (*it == state) {
                return true;
            }
        }
        return false;
    }

    S backtrace(State<T> *state) {
        S v;
        State<T> *father;
        while ((father = state->getFather()) != NULL) {
            double pfirst = father->getState().first, psecond = father->getState().second;
            double sfirst = state->getState().first, ssecond = state->getState().second;
            if (pfirst > sfirst){
                v.push_back("up");
            }
            else if (pfirst < sfirst){
                v.push_back("down");
            }
            else if (psecond > ssecond){
                v.push_back("left");
            }
            else if (psecond < ssecond){
                v.push_back("right");
            }
            else {
                throw "Invalid path - A state does not change.";
            }
            state = father;
        }
        std::reverse(v.begin(), v.end());
        return v;
    }
};

#endif //MAILSTONE2_SEARCHER_H
