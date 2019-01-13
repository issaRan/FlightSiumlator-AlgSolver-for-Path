//
// Created by issa on 1/7/19.
//

#include <sstream>
#include "StringConvertor.h"

#ifndef MAILSTONE2_MATRIXSTRING_H
#define MAILSTONE2_MATRIXSTRING_H

#endif //MAILSTONE2_MATRIXSTRING_H

//template <class Problem,class Solution>
/*
class matrixString : StringConvertor<matrix *, string> {
public:
    string ProblemToString(matrix *m) {
        int height = m->getHeight();
        int width = m->getWidth();
        int** arr = m->getArr();
        ostringstream ss;
        ss << height << " " << width << ";";
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                ss << arr[i][j] << ",";
            }
        }
        ss << "$";
        return ss.str();
    }

    matrix *stringToProblem(const string &problem) {
        int length, width;
        length = stoi(problem.substr(0, problem.find(' ')));
        width = stoi(problem.substr(problem.find(' ') + 1, problem.find(';')));
        int **arr = 0;
        arr = new int *[length];
        for (int i = 0; i < length; i++)
            arr[i] = new int[width];

        for (int j = 0, i = problem.find(';') + 1; j < length; j++) {
            for (int k = 0; k < width; k++) {
                arr[j][k] = stoi(problem.substr(i, problem.find(i, ',')));
                i = problem.find(i, ',') + 1;
            }
        }
        return new matrix(arr, length, width);
    }

    string solutionToString(string solutionOfProblem) {
        return solutionOfProblem;
    }

    string stringToSolution(const string &solution) {
        return solution;
    }
};
 */