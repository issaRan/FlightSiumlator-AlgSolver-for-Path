//
// Created by jokereed on 1/10/19.
//

#ifndef MAILSTONE2_COMPAREPRIORITY_H
#define MAILSTONE2_COMPAREPRIORITY_H

#include "State.h"
#include "Coordinates.h"

template<class T>
struct ComparePriority {
public:
    bool operator()(State<T>* a, State<T>* b){
        return a->getCost() > b->getCost();
    }
};

template<class T>
struct ManhattanDistances {
public:
    bool operator()(State<T>* a, State<T>* b){
        return a->getCost() + a->getHeuristic() > b->getCost() + b->getHeuristic();
    }
    double getHeuristic(pair<double, double> source){
        double sum = 0;
        sum += abs(source.first - this->goal.first);
        sum += abs(source.second - this->goal.second);
        return sum*10;

    }
};
#endif //MAILSTONE2_COMPAREPRIORITY_H
