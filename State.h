//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_STATE_H
#define MAILSTONE2_STATE_H

template<class T>
class State {
    T state;
    double cost;
    State<T> *cameFrom;
public:
    State(T State) : state(State) {}

    void setcameFrom(State<T> *cameFrom) {
        this->cameFrom = cameFrom;

    }

    bool operator==(const State<T> &state) {
        return (this->cameFrom = state.cameFrom) && (this->state = state.state);
    }

    T getState() const {
        return state;
    }

    double getCost() const {
        return cost;
    }

    State<T> *getFather() const {
        return cameFrom;
    }

    State<T> setCost(double cost) const {
        //this->cost = cost;
    }
};


#endif //MAILSTONE2_STATE_H
