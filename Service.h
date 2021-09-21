//
// Created by Sakura on 5/23/2021.
//

#ifndef PREGATEST_SERVICE_H
#define PREGATEST_SERVICE_H


#include "Repository.h"

class Service {
public:
    Service(Repository &repo);
    void addObject(const std::string&, const std::string&, const std::string&, const std::string&);
    void readFile();
    std::vector<std::string> tokenize(const std::string& str, char delimiter);
    std::vector<Object> sortObjects();
    int getManufacturerObjects(std::string m);
    ~Service();

private:
        Repository repo;
        std::string fileName = "Objects.txt";
        char delimitator = '|';


};


#endif //PREGATEST_SERVICE_H
