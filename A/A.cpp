#include "A.hpp"
#include <iostream>

A::A(const char* name){
    this->name = name;
}

void A::print() const {
    std::cout << this->name << std::endl;
}
