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
    ~Firma()
    {
        \\Wydaje mi sie ze nie musze juz tutaj nic niszczyc, bo lista pracownikow i lista kredytow uzyja destruktorów ze swoich klas.
    }
    Firma()
    {
        stan_konta = 1000.0;
        wartosc_spolki=0;   
        stan=1;
        l_pracownikow = 0;
        l_kredytow = 0;
        l_inz = 0;
        l_mag = 0;
        l_mkt = 0;
        l_rob = 0; 
        cout<<"W twojej firmie pracuje juz kilku pracownikow. Podaj ich cechy ponizej."<<endl;
        zatrudnij_pracownika(1);
        zatrudnij_pracownika(2);
        zatrudnij_pracownika(3);
        zatrudnij_pracownika(4);
    }

    //Gettery
    double get_wartosc_spolki(int czas) // to chyba nie do konca jest getter ale niech juz tutaj bedzie
    {
        double suma;
        for (int i=0;i<N;i++)
        {
            if ((czas-i)>=0)
                suma = historia_przychodow[czas-i];
        }
        return suma;
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
    //Settery


    //Metody specjalne
    void drukuj_pracownikow()
    {
        for(int i = 0; i<l_pracownikow;i++)
        {
            lista_pracownikow[i]->drukuj();
        }
    }
    void wez_kredyt(int miesiac)
    {
        double kwota;
        int czas;
        double warunek;
        warunek = get_wartosc_spolki(miesiac)*N;
        do
        {
            cout<<"Określ kwote kredytu: ";
            cin>>kwota;
        } while (kwota>warunek);
        cout<<endl<<"Określ czas splaty (max 20 miesiecy): ";
        cin>>czas;
        lista_kredytow[l_kredytow] = new Kredyt(kwota, czas);  
        stan_konta +=(kwota+(0.05*czas*kwota));   //dodalem jedna rate zeby zaczac splacanieod nastepnego miesiaca
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
            break;
        case 2: //Tworzenie Magazyniera
            cout<<"Czy magazynier ma uprawnienia na wozek? (1 tak, 0 nie): ";
            cin>>wozek;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Mag(wozek);
            l_mag++;
            break;
        case 3: //Tworzenie Marketingowca
            cout<<"Ile osob obserwuje marketingowca?: ";
            cin>>follow;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Mkt(follow);
            l_mkt++;
            break;
        case 4: //Tworzenie Robotnika
            cout<<"Jaki jest rozmiar buta robotnika?: ";
            cin>>but;
            cout<<endl;
            lista_pracownikow[l_pracownikow] = new Rob(but);
            l_rob++;
            break;        
        default:
            break;
        }
        l_pracownikow++;  
    }

    void zakoncz_ture(int tura)
    {
        dochod();
        historia_przychodow[tura]=sprzedaz();
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
            {
                raty += lista_kredytow[i]->get_rata();
                lista_kredytow[i]->splac_rate();
            }
        } 
        return raty;
    }
    void dochod()
    {
        stan_konta += sprzedaz() - pensje() - raty();
    }

    bool get_stan()
    {
        if ((stan_konta)<0.0)
            return false;
        else
            return true;
    }
    private:
    const double CI = 10;
    const double CMag = 10;
    const double CMkt = 10;
    const double CR = 10;

    const double I_salary = 10;
    const double Mag_salary = 10;
    const double Mkt_salary = 10;
    const double Rob_salary = 10;

    double wartosc_spolki;
    double stan_konta;
    int l_kredytow;
    int l_pracownikow;
    int l_inz;
    int l_mag;
    int l_mkt;
    int l_rob;
    double historia_przychodow[999];
    bool stan;
    int N=5; //miesiace brane pod uwage przy wyliczaniu wartosci spolki
    int x=10;
    int M=10;
    Pracownik* lista_pracownikow[999];
    Kredyt *lista_kredytow[999];


};


#endif
