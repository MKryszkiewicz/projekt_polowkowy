#ifndef rob_hpp
#define rob_hpp

#include"pracownik.hpp"
#include <iostream>

using namespace std;

class Rob : public Pracownik
{
    public:
    Rob(double shoe_size)
    :Pracownik()
    {
        but = shoe_size;
    }
    void drukuj()
    {
        cout<<"Jestem "<<name;//<<". Moje wynagrodzenie wynosi: "<<salary<<" złotych.";
        cout<<"Jestem Robotnikiem i mam rozmiar buta:"<<but<<endl;
    }
    private:
    double but;
};
#endif
