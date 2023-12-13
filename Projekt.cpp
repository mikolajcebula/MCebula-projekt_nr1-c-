#include <iostream>
#include "Fabryka.cpp"

using namespace std;

int main()
{
    double pocz_wart_firmy = 100000;
    string akcja;
    unique_ptr<Fabryka> fabryka = make_unique<Fabryka>(pocz_wart_firmy);
    cout << "Początkowa wartość firmy wynosi: " << pocz_wart_firmy << "\n";
    while(1)
    {
        cout << "\nWpisz wybraną komende:\n\tlp - wylistuj pracowników \n\tzinz - zatrudnij inżyniera \n\tzmag - zatrudnij magazyniera \n\tzmkt - zatrudnij marketera \n\tzrob zatrudnij robotnika \n\tkred - weź kredyt \n\tkt - zakończ turę\n\t";
        cin >> akcja;

        if(akcja == "lp")
        {
            fabryka -> wypiszPracownikow();
        }
        else if(akcja == "zinz")
        {
            fabryka  -> dodajInz();
            cout << "Aktualna cena produktu: " << fabryka -> cena();

        }
        else if(akcja == "zmag")
        {
            fabryka -> dodajMag();
            cout << "Aktualna poj. magazynu: " << fabryka -> poj_magazynu();
        }
        else if(akcja == "zmkt")
        {
            fabryka -> dodajMkt();
            cout << "Aktualny popyt: " << fabryka -> popyt();

        }
        else if(akcja == "zrob")
        {
            fabryka -> dodajRob();
            cout << "Aktualna produktywność: " << fabryka -> teoretyczna_produkcja();
        }
        else if(akcja == "kred")
        {
            fabryka -> dodaj_kredyt();
        }
        else if(akcja == "kt")
        {
            cout << "\nDochód: "<< fabryka -> dochod();
            fabryka -> stan_konta();
            cout << "\nKoniec miesiąca. Aktualny stan konta:\t" << fabryka -> get_akt_stan_kont() <<"\nPrzychód: "<< fabryka -> przychod() <<"\n";
            fabryka -> uwuwanie_splaconychy_kredytow();
        }
        else
        {
            cout << "Nie poprawna komenda";
        }

        if(fabryka -> get_akt_stan_kont()<0)
        {
            cout << "\nPrzegrałeś. Stan konta mniejszy od 0";
            return 0;
        }
    }
    return 0;
}