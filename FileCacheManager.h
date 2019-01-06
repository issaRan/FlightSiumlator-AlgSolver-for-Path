//
// Created by issa on 1/4/19.
//

#ifndef MAILSTONE2_FILECACHEMANAGER_H
#define MAILSTONE2_FILECACHEMANAGER_H


#include <unordered_map>
#include "CacheManger.h"
template <class P,class S>
class FileCacheManager : public CacheManger<P,S>{
private:
    unordered_map<string,string> problemsAndSolutions;
public:
    virtual bool isSolutionExist(P problem);
    virtual S getSolution(P problem);
    virtual void saveSolution(P problem, S solution);
    void loadMap();
    void saveOnFile(string problem,string solution);
};
template<class P, class S>
bool FileCacheManager<P, S>::isSolutionExist(P problem) {

}
template<class P, class S>
S FileCacheManager<P, S>::getSolution(P problem) {
    return nullptr;
}
template<class P, class S>
void FileCacheManager<P, S>::saveSolution(P problem, S solution) {

}
template<class P, class S>
void FileCacheManager<P, S>::loadMap() {

}
template<class P, class S>
void FileCacheManager<P, S>::saveOnFile(string problem, string solution) {

}


#endif //MAILSTONE2_FILECACHEMANAGER_H
