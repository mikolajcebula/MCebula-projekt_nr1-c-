#include <iostream>
// #include <vector>
// #include <variant>
// #include <algorithm>
// #include "RandomNameGenerator.cpp"
// #include <memory>

using namespace std;

class Kredyt
{
    private:
        double kwota;
        int l_rat;// na początku kredytu
        // double odsetki= 0.05; // min. procent odsetki (zależny od długości spłacania kredytu)

    public:
        int akt_raty;
        Kredyt(double kwot,int raty):l_rat(raty), kwota(kwot), akt_raty(raty)
        {
            print();
        }
        ~Kredyt(){}
        double obliczenie_odsetek() const
        {
            return 0.05 + ((double)l_rat / 100);
        }
        double kwota_do_splacenia() const
        {
            return kwota*(1+obliczenie_odsetek());
        }
        double wys_raty() const
        {
            return kwota_do_splacenia()/l_rat;
        }
        int splacenie_raty()
        {
            return akt_raty--;
        }
        int get_akt_rat() const
        {
            return akt_raty;
        }
        void print(){
            cout << "Kwota kredytu: " << kwota << " Liczba rat: " << l_rat << " Wysokość raty: " << wys_raty() << " Kwota do spłacenia: " << kwota_do_splacenia();
        }
        
};
