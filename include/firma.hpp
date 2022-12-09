#ifndef firma_hpp
#define firma_hpp

#include "RandomNameGenerator.hpp"
#include "pracownik.hpp"
#include "kredyt.hpp"
#include "inz.hpp"
#include "mag.hpp"
#include "mkt.hpp"
#include "rob.hpp"
#include <iostream>


class Firma
{
    public:
    Firma()
    {
        stan_konta = 100;    
    }
    Firma (double s_k)
    {
        stan_konta = s_k;
    }

    //Gettery
    double get_wartosc_spolki()
    {
        return wartosc_spolki;
    }
    double get_stan_konta()
    {
        return stan_konta;
    }
    double get_l_pracownikow()
    {
        return l_pracownikow;
    }
    double get_l_kredytow()
    {
        return l_kredytow;
    }
    int get_miesiac()
    {
        return miesiac;
    }
    //Settery


    //Metody specjalne
    void drukuj_pracownikow()
    {
        for(int i = 0; i<l_pracownikow;i++)
        {
            lista_pracownikow[i]->drukuj();
        }
    }
    void wez_kredyt()
    {
        double kwota;
        int czas;
        cout<<"Określ kwote kredytu: ";
        cin>>kwota;
        cout<<endl<<"Określ czas splaty (max 20 miesiecy): ";
        cin>>czas;
        lista_kredytow[l_kredytow] = new Kredyt(kwota, czas);     
    }
    void zatrudnij_pracownika (int ktory)
    {     
        string wydzial;
        bool wozek;
        double but;
        int follow;
        switch (ktory)
        {
        case 1: //Tworzenie Inzyniera
            cout<<"Podaj wydzial inzyniera: ";
            cin>>wydzial;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Inz(wydzial);
            l_inz++;
            l_pracownikow++;
            break;
        case 2: //Tworzenie Magazyniera
            cout<<"Czy magazynier ma uprawnienia na wozek? (1 tak, 0 nie): ";
            cin>>wozek;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Mag(wozek);
            l_mag++;
            l_pracownikow++;
            break;
        case 3: //Tworzenie Marketingowca
            cout<<"Ile osob obserwuje marketingowca?: ";
            cin>>follow;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Mkt(follow);
            l_mkt++;
            l_pracownikow++;
            break;
        case 4: //Tworzenie Robotnika
            cout<<"Jaki jest rozmiar buta robotnika?: ";
            cin>>but;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Rob(but);
            l_rob++;
            l_pracownikow++;
            break;        
        default:
            break;
        }
        l_pracownikow++;  
    }
    double sprzedaz()
    {
        double cena = l_inz*CI;
        int pojem = l_mag*CMag;
        int popyt = l_mkt*CMkt;
        int podaz = l_rob*CR;
        int prod;
        int sprzed;
        if (pojem<=podaz)
            prod=pojem;
        else
            prod=podaz;
        if (prod<=popyt)
            return cena*prod;
        else 
            return cena*popyt;
    }

    double pensje()
    {
        return l_inz*I_salary +l_mag*Mag_salary+l_mkt*Mkt_salary+l_rob*Rob_salary;
    }
    double raty()
    {
        double raty;
        for (int i=0; i<l_kredytow;i++)
        {
            if (lista_kredytow[i]->get_czas_splacania()>0)
            raty += lista_kredytow[i]->get_rata();
            lista_kredytow[i]->splac_rate();
        } 
        return raty;
    }
    void dochod()
    {
        stan_konta += sprzedaz() - pensje() - raty();
    }

    private:
    const double CI = 1;
    const double CMag = 1;
    const double CMkt = 1;
    const double CR = 1;

    const double I_salary = 10;
    const double Mag_salary = 10;
    const double Mkt_salary = 10;
    const double Rob_salary = 10;

    double wartosc_spolki;
    double stan_konta;
    double max_kwota_kredytu;
    int l_kredytow;
    int l_pracownikow;
    int l_inz;
    int l_mag;
    int l_mkt;
    int l_rob;
    int miesiac = 0;

    Pracownik* lista_pracownikow[999];
    Kredyt *lista_kredytow[999];


};


#endif
