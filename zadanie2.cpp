// ### Zadanie 2 ###
// Liczby zaprzyjaźnione to dwie liczby naturalne, gdzie każda z nich
// jest równa sumie dzielników właściwych drugiej liczby. Napisz program
// wypisujący liczby zaprzyjaźnione z zadanego zakresu. Zakres mozna podać w kodzie programu.

#include <iostream>
using namespace std;

//Oblicza potencjalnego przyjaciela dla danej liczby x
int calcFriend(int x) {
    int potFriend = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) { potFriend += i; }
    }
    return potFriend;
}
//Porownuje x i wynik calcFriend z wyniku z calcFriend z x. Jezeli sa rowne, sa to liczby zaprzyjaznione
bool isFriend(int x) {
    int y = calcFriend(x);
    if (calcFriend(y) == x && x != y) {
        cout << x << " i " << y << endl;
        return true;
    }
    return false;

}

int main() {

    //Input od użytkownika
    int poczZakr, konZakr;
    for (bool i : { true, false }) {
        cout << "Prosze podac " << (i == true ? "poczatek" : "koniec")
            << " zakresu do wyszukiwania liczb zaprzyjaznionych : "
            << endl;
        cin >> (i ? poczZakr : konZakr);
    }
    //Sprawdzanie czy input jest ok, mimo tego że nie było to wymagane
    if (poczZakr > konZakr || poczZakr == NULL || konZakr == NULL) {
        cout << "Cos sie nie zgadza... Sproboj ponownie" << endl;
        return(200);
    }
    cout << "dobrze, a wiec liczby zaprzyjaznione w tym zakresie to:" << endl;

    for (int x = poczZakr; x < konZakr; x++) {
        isFriend(x);
    }
    cout << endl;
}