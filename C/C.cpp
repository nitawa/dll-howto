#include "C.hpp"
#include <iostream>

C::C(const char* name){
    this->name = name;
}

void C::print() const {
    std::cout << this->name << std::endl;
}
