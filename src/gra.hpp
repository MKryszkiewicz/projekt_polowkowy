#ifndef gra_hpp
#define gra_hpp

#include <iostream>
#include <memory>
#include "firma.hpp"
#include "pracownik.hpp"
#include "inz.hpp"
#include "mag.hpp"
#include "mkt.hpp"
#include "rob.hpp"
#include "kredyt.hpp"


using namespace std;

class Gra
{
    public:
    Gra()
    {
        stan = 1;
        miesiac= 1;
    };
    void rozgrywka()
    {
        cout<<"START"<<endl;
        while((firma->get_stan()) || (firma->get_wartosc_spolki(miesiac)>win_condition))
        {
            int input;
            while(tura)
            {
                cout<<"Wpisz cyfre odpowiadajaca akcji aby ja wykonac"<<endl;
                cout<<"1. Wylistuj pracownikow."<<endl;
                cout<<"2, Zatrudnij inzyniera."<<endl;
                cout<<"3. Zatrudnij magazyniera."<<endl;
                cout<<"4. Zatrudnij marketingowca."<<endl;
                cout<<"5. Zatrudnij robotnika."<<endl;
                cout<<"6. Wez kredyt."<<endl;
                cout<<"7. Zakoncz ture."<<endl;
                cin>>input;
                akcja_gracza(input);
            }
        }
    }
    void akcja_gracza(int in)
    {
        switch (in)
        {
        case 1:
            firma->drukuj_pracownikow();
            break;
        case 2:
            firma->zatrudnij_pracownika(1); //zatrudnia pracownika nr.1 to jest inzynira
            break;
        case 3:
            firma->zatrudnij_pracownika(2); //zatrudnia pracownika nr.2 to jest magazyniera
            break;
        case 4:
            firma->zatrudnij_pracownika(3); //zatrudnia pracownika nr.3 to jest marketingowca
            break;
        case 5:
            firma->zatrudnij_pracownika(4); //zatrudnia pracownika nr.4 to jest robotnika
            break;
        case 6:
            firma->wez_kredyt();
            break;
        case 7:
            firma->zakoncz_ture(miesiac);
            tura=0;
            break;
        
        default:
            break;
        }
    }

    private:
    bool stan;
    bool tura;
    int miesiac;
    double win_condition = 1000000;
    unique_ptr<Firma> firma;
};
#endif
