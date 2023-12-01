/*
Zadanie 3-1
Napisz program, który umożliwia użytkownikowi obliczanie pola powierzchni różnych figur
geometrycznych (kwadratu, prostokąta, koła i trójkąta). Wykorzystaj przeciążanie funkcji do
obsługi różnych przypadków.

NOTATKA: Oddać na te tylko jedno z trzecich, zgodnie z umiejętnościami
*/
#include <iostream>
using namespace std;
const double PI = 3.1415;

// pole kwadratu i kola
double pole(double bokLubPromien, bool kolo = false) {
    if (kolo)
        return PI * bokLubPromien * bokLubPromien; //kolo
    else
        return bokLubPromien * bokLubPromien;  //kwadrat
}


// pole trojkata i prostokata
double pole(double podstawaLubDlugosc, double wysokoscLubSzerokosc, bool trojkat = false) {
    if (trojkat)
        return 0.5 * podstawaLubDlugosc * wysokoscLubSzerokosc; //trojkat
    else
        return podstawaLubDlugosc * wysokoscLubSzerokosc;  //prostokat
}

int main() {
    char wybor;

    do {
        cout << "Wybierz figure geometryczna:\n";
        cout << "1. Kwadrat\n";
        cout << "2. Prostokat\n";
        cout << "3. Kolo\n";
        cout << "4. Trojkat\n";
        cout << "5. Wyjscie\n";
        cin >> wybor;

        switch (wybor) {
            case '1': {
                double bok;
                cout << "Podaj dlugosc boku kwadratu: ";
                cin >> bok;
                cout << "Pole kwadratu: " << pole(bok) << "\n";
                break;
            }
            case '2': {
                double dlugosc, szerokosc;
                cout << "Podaj dlugosc prostokata: ";
                cin >> dlugosc;
                cout << "Podaj szerokosc prostokata: ";
                cin >> szerokosc;
                cout << "Pole prostokata: " << pole(dlugosc, szerokosc) << "\n";
                break;
            }
            case '3': {
                double promien;
                cout << "Podaj promien kola: ";
                cin >> promien;
                cout << "Pole kola: " << pole(promien) << "\n";
                break;
            }
            case '4': {
                double podstawa, wysokosc;
                cout << "Podaj dlugosc podstawy trojkata: ";
                cin >> podstawa;
                cout << "Podaj wysokosc trojkata: ";
                cin >> wysokosc;
                cout << "Pole trojkata: " << pole(podstawa, wysokosc) << "\n";
                break;
            }
            case '5': {
                cout << "Dobranoc.\n";
                break;
            }
            default: {
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
                break;
            }
        }
    } while (wybor != '5');

    return 0;
}