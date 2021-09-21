//
// Created by Sakura on 5/23/2021.
//

#include <vector>
#include <sstream>
#include "Object.h"

Object::Object(const std::string &name, const std::string &model, const std::string &year, const std::string &color) : name(
        name), model(model), year(year), color(color) {}

Object::Object(): name{""}, model{""}, year{""}, color{""} {}

Object::~Object() = default;


const std::string &Object::getName() const {
    return name;
}

void Object::setName(const std::string &name) {
    Object::name = name;
}

const std::string &Object::getModel() const {
    return model;
}

void Object::setModel(const std::string &model) {
    Object::model = model;
}

const std::string &Object::getYear() const {
    return year;
}

void Object::setYear(const std::string &year) {
    Object::year = year;
}

const std::string &Object::getColor() const {
    return color;
}

void Object::setColor(const std::string &color) {
    Object::color = color;
}

bool Object::operator<(const Object &other) const {
    return this->getName()<other.getName();
}
