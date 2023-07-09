#include "B.hpp"
#include <iostream>

B::B(const char* name){
    this->name = name;
}

void B::print() const {
    std::cout << this->name << std::endl;
}
