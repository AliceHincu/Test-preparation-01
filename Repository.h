//
// Created by Sakura on 5/23/2021.
//

#ifndef PREGATEST_REPOSITORY_H
#define PREGATEST_REPOSITORY_H


#include <vector>
#include "Object.h"

class Repository {
public:
    Repository();
    void addObjectRepo(const Object&);
    std::vector<Object> getObjectsRepo();
    ~Repository();

private:
    std::vector<Object> Objects;

};


#endif //PREGATEST_REPOSITORY_H
