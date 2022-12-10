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
        miesiac = 0;
        f = unique_ptr<Firma>{new Firma{}};

    };
    void rozgrywka()
    {
        cout<<"START"<<endl;


        while((f->get_stan()) || (f->get_wartosc_spolki(miesiac)>win_condition))
        {
            int input;
            tura = 1;
            cout<<"Rozpoczyna sie "<<(miesiac+1)<<" miesiac gry."<<endl;
            cout<<"Twoj stan konta to: "<<f->get_stan_konta()<<endl;
            cout<<"Wartosc Twojej firmy to: "<<f->get_wartosc_spolki(miesiac-1)<<endl;
            while(tura)
            {
                cout<<endl<<"Wpisz cyfre odpowiadajaca akcji aby ja wykonac"<<endl;
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
            miesiac++;
        }
        cout<<"pograne..."<<endl;
        if(f->get_wartosc_spolki(miesiac)>win_condition)
            cout<<"Wygrales!!";
        if(!(f->get_stan()))
            cout<<"Przegrales :<"<<endl;
    }
    void akcja_gracza(int in)
    {
        switch (in)
        {
        case 1:
            f->drukuj_pracownikow();
            break;
        case 2:
            f->zatrudnij_pracownika(1); //zatrudnia pracownika nr.1 to jest inzynira
            break;
        case 3:
            f->zatrudnij_pracownika(2); //zatrudnia pracownika nr.2 to jest magazyniera
            break;
        case 4:
            f->zatrudnij_pracownika(3); //zatrudnia pracownika nr.3 to jest marketingowca
            break;
        case 5:
            f->zatrudnij_pracownika(4); //zatrudnia pracownika nr.4 to jest robotnika
            break;
        case 6:
            f->wez_kredyt(miesiac);
            break;
        case 7:
            f->zakoncz_ture(miesiac);
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
    unique_ptr<Firma>f;
};
#endif
