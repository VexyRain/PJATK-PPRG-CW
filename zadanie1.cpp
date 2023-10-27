// ### Zadanie 1 ###
// Napisz program, który wypisze na ekranie wszystkie liczby pierwsze z zadanego zakresu. Zakres mozna podać w kodzie programu.

// Liczba pierwsza ma dokładnie 2 dzielniki - 1 i samą siebie.

#include <iostream>
using namespace std;

bool czyPierwsza(int x) {
    for (int i = 2; i < x; i++) {
        if ((x % i) == 0) { return false; }
    }
    return true;
}

int main() {

    //Input od użytkownika
    int poczZakr, konZakr;
    for (bool i : { true, false }) {
        cout << "Prosze podac " << (i == true ? "poczatek" : "koniec")
            << " zakresu do wyszukiwania liczb pierwszych : "
            << endl;
        cin >> (i ? poczZakr : konZakr);
    }
    
    //Tu byłaby kontrola poprawności wartości, ale nie jest wymagana w zadaniu.
    cout << "dobrze, a wiec liczby pierwsze w tym zakresie to:" << endl;

    for (int x = poczZakr; x < konZakr; x++) {
        if (czyPierwsza(x)) {
            cout << x << " ";
        }
    }
    cout << endl;
}