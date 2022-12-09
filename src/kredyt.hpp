#ifndef kredyt_hpp
#define kredyt_hpp

#include <iostream>

class Kredyt
{
    public:
    Kredyt (double kwota, int czas)
    {
        kwota_kredytu = kwota;
        czas_splacania = czas;
        rata = kwota/czas+(0.05*czas_splacania*kwota); //odsetki wynosza 5% kwoty za kazdy miesiac i sa stale 
    }
    double get_rata()
    {
        return rata;
    }
    double get_czas_splacania()
    {
        return czas_splacania;
    }
    void splac_rate()
    {
        czas_splacania--;
    }
    private:
    double kwota_kredytu;
    int czas_splacania;
    double rata;
};

#endif
