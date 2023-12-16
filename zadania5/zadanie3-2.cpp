/*
Zadanie 3-2

Napisz funkcję, która przyjmie jako parametry trzy liczby 
(zmiennoprzecinkowa, zmiennoprzecinkowa, całkowita),
gdzie:
- pierwszy parametr będzie pierwszym wyrazem ciągu,
- drugi parametr będzie różnicą/ilorazem ciągu,
- trzeci parametr będzie liczbą elementów ciągu.

Funkcja powinna obliczać sumę wszystkich elementów ciągu arytmetycznego i
geometrycznego oraz wyświetlać odpowiednie informacje na ekranie.
*/

#include <iostream>
#include <cmath>

using namespace std;

void obliczISumujCiagi(double pierwszyWyraz, double roznicaIloraz, int liczbaElementow){
    //Ciąg arytmetyczny
    double sumaArytmetyczna = (liczbaElementow * (2 * pierwszyWyraz + (liczbaElementow - 1) * roznicaIloraz)) / 2;

    //Ciąg geometryczny
    double sumaGeometryczna = 0;
    for (int i = 0; i < liczbaElementow; i++){
        sumaGeometryczna += pierwszyWyraz * pow(roznicaIloraz, i);
    }

    //Wyświetlenie wyników
    cout << "[ARYTMETYCZNY]: pierwszy wyraz [" << pierwszyWyraz
         << "], roznica [" << roznicaIloraz
         << "], liczba elementow [" << liczbaElementow
         << "], suma [" << sumaArytmetyczna << "]" << endl;

    cout << "[GEOMETRYCZNY]: pierwszy wyraz [" << pierwszyWyraz
         << "], iloraz  [" << roznicaIloraz
         << "], liczba elementow [" << liczbaElementow
         << "], suma [" << sumaGeometryczna <<  "]" << endl;
}

//Main do testowania
int main() {
    double pierwszyWyraz = 2.0;
    double roznicaIloraz = 3.0;
    int liczbaElementow = 5;

    obliczISumujCiagi(pierwszyWyraz, roznicaIloraz, liczbaElementow);
    return 0;
}
