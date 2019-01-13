
//
// Created by jokereed on 1/11/19.
//

#ifndef MAILSTONE2_MYPRIORITYQUEUE_H
#define MAILSTONE2_MYPRIORITYQUEUE_H


#include <queue>
#include <algorithm>


template<class T,class toComapre>
class MyPriorityQueue : public std::priority_queue<T, std::vector<T>, toComapre> {
private:

public:

    void remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return;
        }
        return;
    }

    bool contains(T value) {
        typename std::vector<T>::iterator it = std::find(this->c.begin(), this->c.end(), value);
        return it != this->c.end();
    }

    typename std::vector<T>::iterator findIt(T value) {
        return find(this->c.begin(), this->c.end(), value);
    }

};


#endif //MAILSTONE2_MYPRIORITYQUEUE_H