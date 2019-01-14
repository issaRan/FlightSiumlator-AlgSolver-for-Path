//
// Created by issa on 1/13/19.
//

#ifndef MAILSTONE2_MATRIXCONVERT_H
#define MAILSTONE2_MATRIXCONVERT_H

#include "StringConvert.h"
#include "matrix.h"
template<class Problem, class solution>
class matrixConvert : public StringConvert<matrix, vector<string>> {

    string ProblemToString(matrix problem) {
        //vector<string> string1;
        string str;
        return str;
    }

    matrix stringToProblem(const string &problem) {
        matrix matrix1(NULL, 3, 4, make_pair(3,4),make_pair(3,2));
        return matrix1;
    }

    string solutionToString(vector<string> theSolution) {
        string str;
        return str;
    }

    vector<string> stringToSolution(const string &problem){
        vector<string> s;
        return s;
    }

};
#endif //MAILSTONE2_MATRIXCONVERT_H
