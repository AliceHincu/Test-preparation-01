//
// Created by Sakura on 5/23/2021.
//

#ifndef PREGATEST_OBJECT_H
#define PREGATEST_OBJECT_H

#include <string>

class Object {
public:
    Object(const std::string &name, const std::string &model, const std::string &year, const std::string &color);

    Object();

    bool operator<(const Object&) const;


    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getModel() const;

    void setModel(const std::string &model);

    const std::string &getYear() const;

    void setYear(const std::string &year);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    virtual ~Object();

private:
    std::string name;
    std::string model;
    std::string year;
    std::string color;
};


#endif //PREGATEST_OBJECT_H
