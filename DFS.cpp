#include "DFS.h"
#include <stack>
#include <map>

template<class T>
Solution<T> DFS<T>::search(ISearchable<T> *searchable) {
    addToOpenList(searchable->getInitialState());
    map<State<T>, bool> visited;
    while (this->openListSize() > 0) {

    }
}