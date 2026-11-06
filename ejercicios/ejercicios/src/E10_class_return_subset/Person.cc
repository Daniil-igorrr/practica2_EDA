#include "Person.h"

Person::Person(const string& nombre, int edad) {
    name_ = nombre;
    age_ = edad;
}

string Person::get_name() const {
    return name_;
}

int Person::get_age() const {
    return age_;
}
