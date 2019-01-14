//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_FILECACHEMANAGER_H
#define MAILSTONE2_FILECACHEMANAGER_H


#include <unordered_map>
#include <fstream>
#include <vector>
#include <iterator>
#include <sstream>
#include "CacheManger.h"
#include "StringConvert.h"

#define space " "

template<class P, class S>
class FileCacheManager : public CacheManger<P, S> {
    unordered_map<string, string> problemsAndSolutions;
    StringConvert<P, S> *convert;
public:
    FileCacheManager(StringConvert<P, S> *convert) {
        this->convert = convert;
    }

    virtual bool isSolutionExist(P problem);

    virtual S getSolution(P problem);

    virtual void saveSolution(P problem, S solution);

    void loadMap();

    void saveOnFile(const string &problem, const string &solution);

    vector<string> splitValues(const string &line);
};

template<class P, class S>
bool FileCacheManager<P, S>::isSolutionExist(P problem) {
    this->problemsAndSolutions.count(problem) != 0;
}

template<class P, class S>
S FileCacheManager<P, S>::getSolution(P problem) {
    string problemRepresentByString = this->convert->ProblemToString(problem);
    auto it = problemsAndSolutions.find(problemRepresentByString);
    while (it != problemsAndSolutions.end()) {
        if (it->first == problemRepresentByString) {
            return this->convert->stringToSolution(it->second);
        }
    }
    return NULL;
}

template<class P, class S>
void FileCacheManager<P, S>::saveSolution(P problem, S solution) {
    string problemRepresentByString = this->convert->ProblemToString(problem);
    string solutionRepresentByString = this->convert->solutionToString(solution);
    this->problemsAndSolutions[problemRepresentByString] = solutionRepresentByString;
    saveOnFile(problemRepresentByString, solutionRepresentByString);
}

template<class P, class S>
void FileCacheManager<P, S>::loadMap() {
    ifstream solutions;
    string line;
    vector<string> problemsAnsSolutions;
    while (getline(solutions, line)) {
        problemsAnsSolutions = splitValues(line);
        this->problemsAndSolutions.insert(make_pair(problemsAnsSolutions[0], problemsAnsSolutions[1]));
    }
}

template<class P, class S>
void FileCacheManager<P, S>::saveOnFile(const string &problem, const string &solution) {
    ofstream sol;
    sol.open("solutionToProblem.txt", ios::app);
    if (sol.is_open()) {
        sol << problem << space << solution << "\n";
        sol.close();
    }
}

template<class P, class S>
vector<string> FileCacheManager<P, S>::splitValues(const string &line) {
    //function to split the line by spaces.
    stringstream ss(line);
    istream_iterator<string> begin(ss);
    istream_iterator<string> end;
    vector<string> vstrings(begin, end);
    return vstrings;
}


#endif //MAILSTONE2_FILECACHEMANAGER_H
