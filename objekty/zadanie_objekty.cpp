#include <iostream>
#include <string>
using namespace std;
class Car{
    public:
        string marka;
        string model;
        string kolor;
        int rok_produkcji;
        int pojemnosc;
    protected:
        string vin;
    public:
        void dodaj_samochod();
        void pokaz_samochod();
        void jedz(int ile_km);
        void dodaj_vin();
        void pokaz_vin();
};

class FuelCar: public Car{
    public:
        int pojemnosc_baku=0;
        int stan_baku;
        string spalanie;
    public:
        void pokaz_stan_baku();
        void zatankuj();
        void jedz(int ile_km);
};

class ElecricCar: public Car{
    public:
        int poziom_baterii;
        //string poziom_zu¿ycia_baterii;
    public:
        void laduj_baterie();
        void  pokaz_poziom_naladowania_baterii();
        void jedz(int ile_km);
};

void Car::dodaj_samochod(){
    cout<<"\n----dodaj samochod----";
    cout<<"\npodaj marke:";
    cin>>marka;
    cout<<"podaj model:";
    cin>>model;
    cout<<"podaj kolor:";
    cin>>kolor;
    cout<<"podaj rok produkcji:";
    cin>>rok_produkcji;
    cout<<"podaj pojemnosc:";
    cin>>pojemnosc;
    this->pojemnosc=pojemnosc;
}

void Car::pokaz_samochod(){
    cout<<"\n----samochod----";
    cout<<"\nmarka:"<<this->marka;
    cout<<"\nmodel:"<<this->model;
    cout<<"\nkolor:"<<this->kolor;
    cout<<"\nrok produkcji:"<<this->rok_produkcji;
}

void Car::dodaj_vin(){
    cout<<"\n----dodaj vin----";
    cout<<"\npodaj vin:";
    cin>>vin;
}

void Car::pokaz_vin(){
    cout<<"\n----vin----";
    cout<<"\nvin:"<<this->vin;
}

void FuelCar::zatankuj(){
    int ile,wynik;
    cout<<"\n----zatankuj----";
    cout<<"\nstan bak przed zatankowaniem:"<<this->stan_baku<<" litrow";
    cout<<"\npodaj ile chcesz zatankowac:";
    cin>>ile;
    wynik=this->stan_baku+ile;
    this->stan_baku=wynik;
    if(this->stan_baku<=this->pojemnosc_baku){
        cout<<"\nstan baku po zatankowaniu:"<<this->stan_baku<<" litrow";
    }else{
        cout<<"\nza duzo zatankowales!";
    }
}

void FuelCar::pokaz_stan_baku(){
    cout<<"\n----stan baku----";
    this->pojemnosc_baku=pojemnosc;
    cout<<"\npojemnosc baku:"<<this->pojemnosc_baku<<" litrow";
}

void ElecricCar::laduj_baterie(){
    int ile,wynik;
    cout<<"\n----naladuj----";
    cout<<"\npoziom baterii przed naladowaniem:"<<this->poziom_baterii<<" %";
    cout<<"\npodaj ile chcesz naladowac:";
    cin>>ile;
    wynik=this->poziom_baterii+ile;
    this->poziom_baterii=wynik;
    cout<<"\nstan baku po naladowaniu:"<<this->poziom_baterii<<" %";

}

void ElecricCar::pokaz_poziom_naladowania_baterii(){
    cout<<"\n----stan zuzycia baterii----";
    this->poziom_baterii=pojemnosc;
    cout<<"\npoziom baterii:"<<this->poziom_baterii<<" %";
}


void FuelCar::jedz(int ile_km){
    double wynik;
    cout<<"\n"<<this->stan_baku;
    wynik=ile_km*(this->stan_baku/100);
    cout<<"\n aktulany stan baku po przejechaniu "<<ile_km<<" wynosi:"<<wynik<<" Litrow";
}

void ElecricCar::jedz(int ile_km){
    double wynik;
    cout<<"\n"<<this->poziom_baterii;
    wynik=ile_km*(this->poziom_baterii/100);
    cout<<"\n aktulany stan baterii po przejechaniu "<<ile_km<<" wynosi:"<<wynik<<" %";
}
int main()
{
    FuelCar car;
    car.dodaj_samochod();
    car.dodaj_vin();
    car.pokaz_samochod();
    car.pokaz_vin();
    car.pokaz_stan_baku();
    car.zatankuj();
    car.jedz(20);

    ElecricCar car2;
    car.dodaj_samochod();
    car.dodaj_vin();
    car.pokaz_samochod();
    car.pokaz_vin();
    car2.pokaz_poziom_naladowania_baterii();
    car2.laduj_baterie();
    car2.jedz(20);
    return 0;
}
