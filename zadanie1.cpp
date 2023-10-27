
// ###### Zadanie 1 #########
// Napisz program obliczający sumę liczb nieparzystych z przedziału <x,y>. Wartości x i y podaje użytkownik.

#include <iostream>
using namespace std;

int main() {

    // Input od użytkownika
    int poczPrzedz, konPrzedz;
    for (bool i : { true, false }) {
        cout << "Prosze podac " << (i ? "poczatek" : "koniec")
            << " przedzialu do obliczania sumy liczb nieparzystych: "
            << endl;
        cin >> (i ? poczPrzedz : konPrzedz);
    }
    
    // Sprawdzenie poprawnosci wartosci nie zostalo zawarte w zadaniu
    // dlatego nie znajdzie się w rozwiązaniu
    cout << "suma liczb nieparzystych w tym zakresie to:" << endl;

    int sumaKoncowa = 0;

    for (int x = poczPrzedz; x <= konPrzedz; x++) {
        if ((x % 2) != 0) {
            sumaKoncowa += x;
        }
    }
    cout << sumaKoncowa << endl;
}