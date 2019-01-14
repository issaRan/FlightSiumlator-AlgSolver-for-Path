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
#include <map>
#define space " "

template<class P, class S>
class FileCacheManager : public CacheManger<P, S> {
    map<vector<string>, vector<string>> problemsAndSolutions;
    StringConvert<P, S> *convert;
public:
    FileCacheManager(StringConvert<P, S> *convert) {
        this->convert = convert;
    }

    virtual bool isSolutionExist(P problem);

    virtual vector<string> getSolutionString(P problem);

    virtual void saveSolution(P problem, S solution);

    void loadMap();

    void saveOnFile(const vector<string> &problem, const vector<string> &solution);

    vector<string> splitValues(const string &line);
};

template<class P, class S>
bool FileCacheManager<P, S>::isSolutionExist(P problem) {
    //this->problemsAndSolutions.count(problem) != 0;
}
template<class P, class S>
vector<string> FileCacheManager<P, S>::getSolutionString(P problem) {
    vector<string> problemRepresentByString = this->convert->ProblemToString(problem);
    auto it = problemsAndSolutions.find(problemRepresentByString);
    if (it != problemsAndSolutions.end()) {
        if (it->first == problemRepresentByString) {
            return it->second;
        }
    }
    //return NULL;
}
template<class P, class S>
void FileCacheManager<P, S>::saveSolution(P problem, S solution) {
    vector<string> problemRepresentByString = this->convert->ProblemToString(problem);
    vector<string> solutionRepresentByString = this->convert->solutionToString(solution);
    this->problemsAndSolutions[problemRepresentByString] = solutionRepresentByString;
    saveOnFile(problemRepresentByString, solutionRepresentByString);
}

template<class P, class S>
void FileCacheManager<P, S>::loadMap() {
    ifstream solutions("solutionToProblem.txt");
    string line;
    vector<string> p, s;
    while (getline(solutions, line)) {
        do {
            p.push_back(line);
        } while (getline(solutions, line) && (line != "@"));
        while (getline(solutions, line) && (line != "$"));
        s.push_back(line);
    }
        this->problemsAndSolutions.insert(make_pair(p, s));
}

template<class P, class S>
void FileCacheManager<P, S>::saveOnFile(const vector<string> &problem, const vector<string> &solution) {
    ofstream sol;
    sol.open("solutionToProblem.txt", ios::app);
    for (string str : problem){
        sol << str << endl;
    }
    sol << "@" << endl;
    for (string str : solution){
        sol << str << endl;
    }
    sol << "$" << endl;
    sol.close();
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
