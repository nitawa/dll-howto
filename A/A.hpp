#ifndef _A_
#define _A_
#ifdef WIN32
    #ifdef A_EXPORTS
        #define A_API __declspec(dllexport)
    #else
        #define A_API __declspec(dllimport)
    #endif
#else
    #define A_API
#endif
#include <string>
class A{
public:
    A_API A(const char* );
    A_API void print() const;
private:
    std::string name;
};
#endif // _A_
