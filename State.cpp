//
// Created by issa on 1/4/19.
//

#include "State.h"

template<class T>
State<T>::State(T state):state(state) {}

template<class T>
void State<T>::setcameFrom(State<T> cameFrom) {}

template<class T>
T State<T>::getState() const {
    return state;
}

template<class T>
double State<T>::getCost() const {
    return cost;
}

template<class T>
bool State<T>::operator==(const State<T> &state) {
    return (this->cameFrom = state.cameFrom) && (this->state = state.state);
}

