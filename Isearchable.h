//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_ISEARCHABLE_H
#define MAILSTONE2_ISEARCHABLE_H

#include "list"
#include "State.h"
using namespace std;
class Isearchable{
    template <class T>;
public:
    virtual State<T> getInitialState()=0;
    virtual State<T> getGoalState() = 0;
    list<State<T>> getAllPossibleState(State<T> state) = 0;
};
#endif //MAILSTONE2_ISEARCHABLE_H
