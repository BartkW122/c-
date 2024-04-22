#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
void losowa_tablica(int *tab, int nm_zakres, int nw_zakres, int r) {
    srand(time(NULL));
       if (r > nw_zakres - nm_zakres + 1) {
        cout << "Za ma³y zakres do wygenerowania tablicy bez powtórzeñ." << endl;
        return;
    }


    int dostepne_liczby[nw_zakres - nm_zakres + 1];
    for (int i = 0; i < nw_zakres - nm_zakres + 1; ++i) {
        dostepne_liczby[i] = nm_zakres + i;
    }


    for (int i = 0; i < r; ++i) {

        int indeks = rand() % (nw_zakres - nm_zakres + 1 - i);

        tab[i] = dostepne_liczby[indeks];

        for (int j = indeks; j < nw_zakres - nm_zakres - i; ++j) {
            dostepne_liczby[j] = dostepne_liczby[j + 1];
        }
    }


    cout << "Wylosowana tablica bez powtorzen:";
    for (int i = 0; i < r; ++i) {
        cout << tab[i] << " ";
    }
}

void wyszukiwnie_liniowe(int *tab, int r, int szukana) {
    bool znaleziono = false;
    for (int i = 0; i < r; i++) {
        if (tab[i] == szukana) {
            cout << "\n (wysz._liniowe)liczba szukana jest na indeksie: " << i;
            znaleziono = true;
            break;
        }
    }
    if (!znaleziono) {
        cout << "\nnie ma takiej liczby";
    }
}

void wyszukiwnie_binarne(int *tab, int r, int szukana) {
    int l = 0;
    int p = r - 1;
    sort(tab, tab + r);
    cout<<"\nposortowana tablica:";
    for(int i = 0;i<r;i++){
        cout<<tab[i]<<" ";
    }
    while (l <= p) {
        int s = l + (p - l) / 2;
        if (tab[s] == szukana) {
            cout << "\n (wysz._binarne)liczba szukana jest na indeksie: " << s;
            return;
        }
        if (tab[s] < szukana) {
            l = s + 1;
        } else {
            p = s - 1;
        }
    }
    cout << "\nnie ma takiej liczby";
}
int main()
{
    int rozmiar,najmniesza_zakres,najwiekszy_zakres,szukana;
    cout<<"podaj rozmiar:";
    cin>>rozmiar;
    int tab[rozmiar];
    cout<<"podaj liczbe szukana:";
    cin>>szukana;
    cout<<"podaj najmniesza_zakres:";
    cin>>najmniesza_zakres;
    cout<<"podaj najwiekszy_zakres:";
    cin>>najwiekszy_zakres;
    losowa_tablica(tab,najmniesza_zakres,najwiekszy_zakres,rozmiar);
    wyszukiwnie_liniowe(tab,rozmiar,szukana);
    wyszukiwnie_binarne(tab,rozmiar,szukana);
    return 0;
}
