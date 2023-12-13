#include <iostream>
#include <vector>
#include <variant>
#include <algorithm>
#include <typeinfo>
#include <memory>
#include <limits>
#include "Kredyt.cpp"
#include "Pracownicy.cpp"
using namespace std;

class Fabryka
{
    private:
        vector<Pracownik*> pracownicy;
        int l_inz = 0;
        int l_mag = 0;
        int l_mkt = 0;
        int l_rob = 0;
        int N = 3;
        double pocz_wart_firmy;
        double akt_stan_konta;
    public:
        Fabryka(double wart) : pocz_wart_firmy(wart)
        {
            akt_stan_konta = pocz_wart_firmy;
        }
        void dodajInz()
        {
            string wydzial;
            cout << "podaj wydział: ";
            cin >> wydzial;

            pracownicy.push_back(new Inz(wydzial));
            l_inz++;
        }
        void dodajMag()
        {
            bool wozek;
            cout << "Podaj czy pracownik ma uprawnienia na wózek widłowy: tak(1), nie(0)";

            while (!(cin >> wozek) || (wozek != 0 && wozek != 1)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Błędne dane. Wprowadź poprawną wartość logiczną (0 lub 1): ";
            }
            pracownicy.push_back(new Mag(wozek));
            l_mag++;

        }
        void dodajMkt()
        {
            int obserwujacy;
            cout << "Podaj liczbę obserwujących na mediach społecznościowych: ";
            while (!(cin >> obserwujacy)) 
            {
                cin.clear(); // Wyczyszczenie błędu wejścia
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Usunięcie złych danych z bufora
                cout << "Błędne dane. Wprowadź liczbę całkowitą ponownie: ";
            }
            pracownicy.push_back(new Mkt(obserwujacy));
            l_mkt++;
        }
        void dodajRob()
        {
            int roz_but;
            cout << "Podaj rozmiar buta robotnika: ";
            while (!(cin >> roz_but)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Błędne dane. Wprowadź liczbę zmiennoprzecinkową ponownie: ";
            }
            pracownicy.push_back(new Rob(roz_but));
            l_rob++;
        }       
        void wypiszPracownikow()
        {
            for(const auto& p: pracownicy)
            {
                p->wypisz();
            }
        }
        int koszta_pracownicze_firmy()
        {
            return l_inz * Inz::pensja + l_mag * Mag::pensja + l_mkt * Mkt::pensja + l_rob * Rob::pensja;
        }
        int cena()
        {
            return l_inz * Inz::wydajnosc; 
        }
        int teoretyczna_produkcja()
        {
            return l_rob * Rob::wydajnosc;
        }
        int poj_magazynu()
        {
            return l_mag * Mag::wydajnosc;
        }
        int popyt()
        {
            return l_mkt * Mkt::wydajnosc;
        }
        int przychod()
        {
            int rzecz_prod = min(poj_magazynu(), teoretyczna_produkcja());
            return min(popyt(),rzecz_prod) * cena();
        }
        vector<int> wartosc;
        void zakoncz_miesiac()
        {
            if (wartosc.size()<N)
            {
                wartosc.push_back(przychod());
            }
            else
            {
                wartosc.erase(wartosc.begin());
                wartosc.push_back(przychod());
            }
        }
        double wartosc_firmy()
        {
            int suma = 0;
            for(int w:wartosc) suma+=w;
            return double(suma)/wartosc.size();
        }
        void wypisz_wartosc_firmy()
        {
            cout << "Aktualna wartość firmy: " << wartosc_firmy() << ". Koniec miesiąca.";
        }

        vector<Kredyt> kredyty;

        void dodaj_kredyt()
        {
            double kwota;
            int raty;
            cout << "Podaj kwotę kredytu:\n";
            cin >> kwota;
            cout << "Podaj l. rat:\n";
            cin >> raty;
            kredyty.push_back(Kredyt(kwota,raty));
            akt_stan_konta+=kwota;
            cout << " Stan konta po wzięciu kredytu: " << akt_stan_konta;
        }
        double zlicz_wys_rat()
        {
            double sum_rat=0;
            for(const auto& k : kredyty)
            {
                sum_rat += k.wys_raty();
            }
            return sum_rat;
        }
        void uwuwanie_splaconychy_kredytow()
        {
            for(auto& k : kredyty)
            {
                k.splacenie_raty();
            }

            kredyty.erase(remove_if(kredyty.begin(), kredyty.end(),
                            [](const Kredyt& kredyt) {return kredyt.get_akt_rat() == 0;
                            }),
                    kredyty.end());
        }
        double dochod()
        {
            return double(przychod()) - double(koszta_pracownicze_firmy())-zlicz_wys_rat();
        }
        void stan_konta()
        {

            akt_stan_konta += dochod();
        }
        double get_akt_stan_kont()
        {
            return akt_stan_konta;
        }
};
