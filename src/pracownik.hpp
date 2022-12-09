#ifndef pracownik_hpp
#define pracownik_hpp

#include <iostream>
#include "RandomNameGenerator.hpp"

using namespace std;

class Pracownik
{
    protected:
    string name;
    Pracownik()
    {
        name = get_random_name();
    }
    public:
    virtual void drukuj()=0;
};
#endif
