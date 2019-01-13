#ifndef MAILSTONE2_BESTFIRSTSERCH_H
#define MAILSTONE2_BESTFIRSTSERCH_H

#include "ISearcher.h"
#include "CommonSearcher.h"
#include "MyPriorityQueue.h"
#include "PrioritySearcher.h"
#include "Comparators.h"

template<class S, class T>
class BestFirstSerch : public PrioritySearcher<S,T>{
    MyPriorityQueue<State<T> *, ComparePriority<T>> opened;
public:
    S search(ISearchable<T> *searchable) {
        unordered_set<State<T>*> &salim = this->closed;
        this->addToOpenList(searchable->getInitialState());
        while (!this->opened.empty()) {
            State<T> *n = this->popOpenList();
            this->closed.insert(n);
            if (searchable->isGoalState(n)) {
                return this->backtrace(n);
            } else {
                for (State<T> *s : searchable->getAllPossibleState(n)) {
                    if (!this->opened.contains(s) && !this->closedContains(s)) {
                        this->addToOpenList(s);
                    } else if (!this->opened.contains(s)) {
                        updateStatePriority(s);
                    }
                }
            }
        }
    }

    void updateStatePriority(State<T> *state) {
        auto t = this->closed.find(state);
        if (t != this->closed.end()) {
            if ((*t)->getCost() > state->getCost()) {
                this->opened.remove(*t);
                this->opened.push(state);
            }
        }
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
        auto first = this->opened.cbegin();
        auto last = this->opened.cend();
        while (first != last) {
            if (**first == *state)
                return true;
            ++first;
        }
        return false;
    }

    bool closedContains(State<T> *state) {
        for (typename unordered_set<State<T> *>::iterator it = this->closed.begin();
             it != this->closed.end(); it++) {
            if (**it == *state) {
                return true;
            }
        }
        return false;
    }
};


#endif //MAILSTONE2_BESTFIRSTSERCH_H