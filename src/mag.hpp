#ifndef mag_hpp
#define mag_hpp

#include "pracownik.hpp"
#include <iostream>

using namespace std;

class Mag : public Pracownik
{
    public:
    Mag(bool w)
    :Pracownik()
    {
        wozek = w;
    }
    void drukuj()
    {
        cout<<"Jestem "<<name;//<<". Moje wynagrodzenie wynosi: "<<salary<<" złotych.";
        if(wozek)
            cout<<"Jestem Magazynierem i umiem jezdzic wozkiem"<<endl;
        else
            cout<<"Jestem Magazynierem i nie umiem jezdzic wozkiem"<<endl;
    }
    private:
    bool wozek;
};

#endif
