#ifndef inz_hpp
#define inz_hpp

#include <iostream>
#include "pracownik.hpp"

using namespace std;

class Inz : public Pracownik
{
    public:
    Inz(string wydzial)
    :Pracownik()
    {
        faculty = wydzial;;
    }
    void drukuj()
    {
        cout<<"Jestem "<<name;//<<". Moje wynagrodzenie wynosi: "<<salary<<" złotych.";
        cout<<"Jestem inzynierem po wydziale "<<faculty<<endl;
    }
    private:
    string faculty;
};
#endif
