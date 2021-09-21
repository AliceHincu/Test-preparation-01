//
// Created by Sakura on 5/23/2021.
//

#include "Service.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

Service::Service(Repository &repo) : repo(repo) {}

Service::~Service() = default;


void Service::addObject(const std::string &name, const std::string &model, const std::string &year, const std::string &color) {
    Object c{name, model, year, color};
    this->repo.addObjectRepo(c);
}


std::vector<Object> Service::sortObjects() {
    auto Objects = this->repo.getObjectsRepo();

    std::sort(Objects.begin(), Objects.end());

    return Objects;
}

int Service::getManufacturerObjects(std::string m) {
    auto Objects = this->repo.getObjectsRepo();
    auto nr = std::count_if(std::begin(Objects), std::end(Objects),
                                    [m] (const Object& Object) { return Object.getName() == m; });
    return nr;
}

void Service::readFile() {
    // Read from the text file
    std::ifstream myFile(this->fileName);
    Object Object;

    if(myFile.is_open()) {
        std::string line;

        while(std::getline(myFile, line)) {
            std::vector<std::string> attributes = this->tokenize(line, this->delimitator);
            this->addObject(attributes[0], attributes[1], attributes[2], attributes[3]);
        }
    }
    else std::cout << "Problem with opening file!";
    // Close the file
    myFile.close();
}

std::vector<std::string> Service::tokenize(const std::string& str, char delimiter){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}
