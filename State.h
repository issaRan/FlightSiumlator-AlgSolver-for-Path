//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_STATE_H
#define MAILSTONE2_STATE_H

template <class T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T State);
    void setcameFrom(State<T> cameFrom);
    bool operator==(const State<T>& state);
    T getState() const;
    double getCost() const;
};


#endif //MAILSTONE2_STATE_H
