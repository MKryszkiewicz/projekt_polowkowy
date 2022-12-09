#ifndef mkt_hpp
#define mkt_hpp

#include "pracownik.hpp"
#include <iostream>

using namespace std;

class Mkt : public Pracownik
{
    public:
    Mkt(int obserwujacy)
    :Pracownik()
    {
        followers = obserwujacy;
    }
    void drukuj()
    {
        cout<<"Jestem "<<name;//<<". Moje wynagrodzenie wynosi: "<<salary<<" złotych.";
        cout<<"Jestem Marketingowcem i mam "<<followers<<" obserwujacych"<<endl;
    }
    private:
    int followers;
};

#endif
