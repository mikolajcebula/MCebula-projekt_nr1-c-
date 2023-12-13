#include <iostream>
// #include <vector>
#include <variant>
// #include <algorithm>
#include "RandomNameGenerator.cpp"
#include <memory>

using namespace std;

class Pracownik
{
    protected:
        string imie;
        variant<string, int, bool, double> cecha;
        
    public:
        Pracownik()
        {
            imie = generate_random_name();
        }
        ~Pracownik(){}
        virtual void wypisz() {} // wypisuje cechy danego pracownika
};

class Inz : public Pracownik
{
    public:
        static const int pensja = 7000;
        static const int wydajnosc = 10;
    Inz(string wydzial)
    {

        cecha = wydzial;

    }
    ~Inz(){}

    void wypisz()
    {
        cout << "\n Inżynier    Imię: " << imie << " pensja: " << pensja << " Wydział: " << get<string>(cecha) << endl; 
    }
};

class Mag : public Pracownik
{
    public:
        static const int pensja = 3500;
        static const int wydajnosc = 400;
    Mag(bool wozek)
    {
        cecha = wozek;
    }
    ~Mag(){}

    void wypisz()
    {
        if(get<bool>(cecha))
        {
            cout << "\n Magazynier    Imię: " << imie << " pensja: " << pensja << " Posiada uprawnienia na wózek widłowy." << endl; 
        }
        else
        {
            cout << "\n Magazynier    Imię: " << imie << " pensja: " << pensja << " Nie posiada uprawnienia na wózek widłowy." << endl; 
        }    
        
    }
};


class Mkt : public Pracownik
{

    public:
        static const int pensja = 5000;
        static const int wydajnosc = 450;    
    Mkt(int obser)
    {
        cecha = obser;
    }
    ~Mkt(){}
    void wypisz()
    {
        cout << "\n Marketer    Imię: " << imie << " pensja: " << pensja << " L. obserwujących: " << get<int>(cecha) << endl; 
    }
};

class Rob : public Pracownik
{
    public:
        static const int pensja = 3000;
        static const int wydajnosc = 250;
    Rob(double but)
    {
        cecha = but;
    }
    ~Rob(){}
    void wypisz()
    {
        cout << "\n Robotnik    Imię: " << imie << " pensja: " << pensja << " Rozmiar buta: " << get<double>(cecha) << endl; 
    }
};

