//
// Created by issa on 1/7/19.
//

#include <string>

#ifndef MAILSTONE2_STRINGCONVECRTOR_H
#define MAILSTONE2_STRINGCONVECRTOR_H

#endif //MAILSTONE2_STRINGCONVECRTOR_H

using namespace std;
template <class Problem,class Solution>
class StringConvertor{
public:
    virtual string ProblemToString(Problem problem) = 0;
    virtual Problem stringToProblem(const string &problem) = 0;
    virtual string solutionToString(Solution solution) = 0;
    virtual Solution stringToSolution(const string &problem) = 0;
};