#include <iostream>
using namespace std;
class Car{
    public:
        string marka;
        string model;
        string kolor;
        int rok_produkcji;
    protected:
        string vin;
    public:
        void dodaj_samochod();
        void pokaz_samochod();
        void jedz(int km);
        void dodaj_vin();
        void pokaz_vin();
};

class FuelCar{
    public:
        int pojemnosc_baku=0;
        int stan_baku;
        string spalanie;
    public:
        void pokaz_stan_baku();
        void zatankuj();
};
void Car::dodaj_samochod(){
    cout<<"----dodaj samochod----";
    cout<<"\npodaj marke:";
    cin>>marka;
    cout<<"podaj model:";
    cin>>model;
    cout<<"podaj kolor:";
    cin>>kolor;
    cout<<"podaj rok produkcji:";
    cin>>rok_produkcji;
}

void Car::pokaz_samochod(){
    cout<<"----samochod----";
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
    int ile,wynik=0;
    cout<<"\n----zatankuj----";
    cout<<"\npodaj ile chcesz zatankowac:";
    cin>>ile;
    //wynik=this->pojemnosc_baku+ile;
    cout<<"\nstan baku po zatankowaniu:"<<wynik;
    wynik=this->pojemnosc_baku;
}

void FuelCar::pokaz_stan_baku(){
    cout<<"\n----stan baku----";
    cout<<"\npojemnosc baku:"<<this->pojemnosc_baku;
    this->spalanie="";
    cout<<"\nspalanie:";
}
int main()
{
    Car car;
    car.dodaj_samochod();
    car.dodaj_vin();
    car.pokaz_samochod();
    car.pokaz_vin();
    FuelCar fuelcar;
    fuelcar.pokaz_stan_baku();
    fuelcar.zatankuj();
    return 0;
}
