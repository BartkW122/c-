#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string zamiana_liczby_na_litery(int l) {
    switch(l) {
        case 10:
            return "A";
        case 11:
            return "B";
        case 12:
            return "C";
        case 13:
            return "D";
        case 14:
            return "E";
        case 15:
            return "F";
        default:
            return to_string(l);
    }
}

int zamiana_litery_na_liczby(char l) {
    switch(l) {
        case 'A':
        case 'a':
            return 10;
        case 'B':
        case 'b':
            return 11;
        case 'C':
        case 'c':
            return 12;
        case 'D':
        case 'd':
            return 13;
        case 'E':
        case 'e':
            return 14;
        case 'F':
        case 'f':
            return 15;
        default:
            return l - '0'; // Jeśli nie jest to litera A-F, zwracamy wartość liczbową znaku
    }
}
string dex_bin(string l) {
    int l_1 = stoi(l);
    string wynik;
    while(l_1) {
        wynik += (l_1 % 2 == 0) ? '0' : '1';
        l_1 = l_1 / 2;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

string dex_hex(string l) {
    int l_1 = stoi(l);
    string wynik;
    while (l_1) {
        int reszta = l_1 % 16;
        wynik += zamiana_liczby_na_litery(reszta);
        l_1 /= 16;
    }
    reverse(wynik.begin(), wynik.end());
    return wynik;
}

int bin_dex(string l) {
    int suma = 0;
    reverse(l.begin(), l.end());
    for(int i = 0; i < l.length(); i++) {
        if (l[i] == '1') {
            suma += pow(2, i);
        }
    }
    return suma;
}

string bin_hex(string l) {
    int z_1 = bin_dex(l);
    return dex_hex(to_string(z_1));
}

int hex_dex(string l) {
    int suma = 0;
    for (int i = 0; i < l.length(); i++) {
        suma = suma * 16 + zamiana_litery_na_liczby(l[i]);
    }
    return suma;
}


string hex_bin(string l){
    string z_1=to_string(hex_dex(l));
    return dex_bin(z_1);
}
int main(){
    int wybor,wybor2;
    string liczba;
    char spr;
    do{
       cout<<"system dziesietny---(1)";
       cout<<"\nsystem binarny---(2)";
       cout<<"\nsystem szesnastkowy---(3)";

       cout<<"\n na co chcesz przeliczyc:";
       cin>>wybor;

       cout<<"\npodaj liczbe:";
       cin>>liczba;


       cout<<"\n w jakim systemie jest liczba(1-binanrny(np.101011),2-dziesietny(np.25),3-szestnastkowy(np.A7):";
       cin>>wybor2;
        if(wybor==1){
            if(wybor2==1){
                cout<<"wynik przeliczania to:"<<bin_dex(liczba);

            }
            if(wybor2==2){
                cout<<"liczba juz jest w systemie dziesietnym";
            }
            if(wybor2==3){
                cout<<"wynik przeliczania to:"<<hex_dex(liczba);
            }
       }
       if(wybor==2){
            if(wybor2==1){
                cout<<"liczba juz jest w systemie binarnym";

            }
            if(wybor2==2){
                cout<<"wynik przeliczania to:"<<dex_bin(liczba);

            }
            if(wybor2==3){
                cout<<"wynik przeliczania to:"<<hex_bin(liczba);

            }
       }
       if(wybor==3){
            if(wybor2==1){
                cout<<"wynik przeliczania to:"<<bin_hex(liczba);
            }
            if(wybor2==2){
            cout<<"wynik przeliczania to:"<<dex_hex(liczba);

            }
            if(wybor2==3){
                cout<<"liczba juz jest w systemie szestnastkowy";
            }
       }

       cout<<"\nczy chcesz jeszcze cos przeliczyc(y/n):";
       cin>>spr;
    }while(spr=='y');
}
