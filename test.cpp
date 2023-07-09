#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

int main()
{
    std::cout << "Approach I: __declspec(dllimport/dllexport)" << std::endl;
    A* a = new A("A");
    a->print();
    std::cout << "Approach II: DEF file" << std::endl;
    B* b =new B("B");
    b->print();
    std::cout << "Approach III: let cmake do it for us: CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS" << std::endl;
    C* c = new C("C");
    c->print();
    return 0;
}
