
#ifndef MAILSTONE2_MATRIX_H
#define MAILSTONE2_MATRIX_H

#include <map>
#include "ISearchable.h"

class matrix : ISearchable<pair<int, int>> {
private:
    int arr[2][2];
    map<pair<int, int>, vector<State<pair<int, int>>>> adj;
public:
    matrix() {

    }

    State<pair<int, int>> getInitialState() {
        State<pair<int, int>> startState(make_pair(0, 0));
        startState.setCost(arr[0][0]);
        return startState;
    }

    bool isGoalState(State<pair<int, int>> state) {
        return state ==
    }

    vector<State<pair<int, int>>> getAllPossibleState(State<pair<int, int>> state) {
        int height = sizeof(arr) / sizeof(arr[0]);
        int width = sizeof(this->arr[0]) / sizeof(int);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                pair<int, int> tempair = make_pair(i, j);
                if (i != 0) {
                    State<pair<int, int>> up = State<pair<int, int>>(make_pair(i - 1, j));
                    up.setCost(this->arr[i][j]);
                    this->adj[tempair].push_back(up);
                }
                if (i != height - 1) {
                    State<pair<int, int>> down = State<pair<int, int>>(make_pair(i + 1, j));
                    down.setCost(this->arr[i][j]);
                    this->adj[tempair].push_back(down);
                }
                if (j != 0) {
                    State<pair<int, int>> left = State<pair<int, int>>(make_pair(i, j - 1));
                    left.setCost(this->arr[i][j]);
                    this->adj[tempair].push_back(left);
                }
                if (i != width - 1) {
                    State<pair<int, int>> right = State<pair<int, int>>(make_pair(i, j + 1));
                    right.setCost(this->arr[i][j]);
                    this->adj[tempair].push_back(right);
                }

            }
        }
    }
};

#endif //MAILSTONE2_MATRIX_H