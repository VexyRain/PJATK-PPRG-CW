/*
Zadanie 2
1. Stwórz strukturę Osoba, która będzie przechowywała imię, nazwisko i wiek.
2. Napisz funkcję, która sortuje tablicę typu Osoba po nazwisku. Jeśli nazwisko nie
rozstrzyga kolejności (jest takie samo), brane pod uwagę jest imię. Jeśli natomiast
imię nie rozstrzyga, brany pod uwagę jest wiek (młodsze osoby najpierw).
3. Napisz funkcję do wyświetlenia tablicy z osobami z możliwością sparametryzowania
tej funkcji do wyświetlenia osób od indeksu A do indeksu B. Zabezpiecz się przed złą
kolejnością indeksów. Jeśli nie zostaną podane parametry, funkcja ma wyświetlić
wszystkie osoby.
4. Napisz funkcję, która wyświetla osoby nie starsze niż podany parametr.
5. Poproś użytkownika o podanie liczby i stwórz odpowiednią tablicę o podanym
rozmiarze, wypełniając ją danymi podanymi przez użytkownika.
6. Stwórz proste menu, w którym:
a. będzie istniało menu główne;
b. z każdego poziomu (oprócz podawania danych) jest możliwość powrotu do
menu głównego;
c. dasz użytkownikowi możliwość wyboru wszystkich osób lub tylko części;
d. w przypadku wybrania części osób, wczytaj odpowiednie dane (A i B indeksu)
- dane pobieraj tak długo, żeby nie wychodziły poza zakres tablicy;
e. po wybraniu opcji wyświetlenia Wszyscy/Wybrani, program daje
użytkownikowi możliwość wybrania, czy dane mają być posortowane;
7. Po przejściu przez menu i wyświetleniu danych, zakończ działanie programu.

// 7
(to po prostu dziala)
*/

// 8
//Tak, wystarczyloby dac wszystko w petle do ktorej konca przechodzilby program po wykonaniu jakiejkolwiek czynnosci, a rozpoczecie tej petli wypisywaloby ponownie menu, lub mozna po prostu na koncu kazdej funkcji dac wywolanie menu glownego na koncu ale to byloby brzydkie rozwiazanie

#include <iostream>
#include <algorithm>
using namespace std;

struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
};

void prosteMenu(); // Deklaracja, aby można było później wywołać

Osoba tablica[] = {{"Joe", "Biden", 81}, {"Carl", "Johnson", 25}, {"Napoleon", "Bonaparte", 254}, {"Gary", "Gary", 5}, {"Gary", "Gary", 4}};
int ileElem = sizeof(tablica) / sizeof(Osoba);

// Wyznaczanie porządku dla późniejszego sortowania
bool sorter(Osoba const& a, Osoba const& b) {
    if (a.nazwisko != b.nazwisko) return a.nazwisko < b.nazwisko;
    if (a.imie != b.imie) return a.imie < b.imie;
    return a.wiek < b.wiek;
}

// Sortowanie tablicy
void sortuj() {
    sort(tablica, (tablica + ileElem), sorter);
}

void drukuj(int poczatek = 0, int koniec = ileElem) {
    if (poczatek < 0) poczatek = 0;
    if (koniec > ileElem) koniec = ileElem;
    if (poczatek > koniec) swap(poczatek, koniec);

    for (int i = poczatek; i < koniec; i++) {
        cout << "Imie: " << tablica[i].imie << " Nazwisko: " << tablica[i].nazwisko << " Wiek: " << tablica[i].wiek << endl;
    }
}

void drukujMlodszychNiz(int wiekGraniczny) {
    for (int i = 0; i < ileElem; i++) {
        if (tablica[i].wiek < wiekGraniczny)
            cout << "Imie: " << tablica[i].imie << " Nazwisko: " << tablica[i].nazwisko << " Wiek: " << tablica[i].wiek << endl;
    }
}

void podajDane() {
    cout << "Prosze wprowadzic liczbe:" << endl;
    int liczba = 0;
    cin >> liczba;
    Osoba elementy[liczba];
    for (int i = 0; i < liczba; i++) {
        cout << "Wprowadz element o indeksie " << i << ":" << endl;
        cout << "Imie: ";
        cin >> elementy[i].imie;
        cout << "Nazwisko: ";
        cin >> elementy[i].nazwisko;
        cout << "Wiek: ";
        cin >> elementy[i].wiek;
    }
    cout << endl << endl;
    for (int i = 0; i < liczba; i++) {
        cout << "Imie: " << elementy[i].imie << " Nazwisko: " << elementy[i].nazwisko << " Wiek: " << elementy[i].wiek << endl;
    }
}

void drukMenu() {
    int wybor = 0;
    cout << endl << "=== DRUKOWANIE DANYCH ===" << endl
        << "[1] Wszyscy" << endl
        << "[2] Podany Zakres" << endl
        << "[3] Wyjscie do menu glownego" << endl;
    while (wybor != 1 && wybor != 2 && wybor != 3) {
        cout << endl << "Wybieram: ";
        cin >> wybor;
    }
    if (wybor == 1) {
        sortuj(); // Sortowanie przed wydrukowaniem
        drukuj();
    }
    if (wybor == 2) {
        int A, B;
        cout << "Podaj indeks poczatkowy (A) (rozpoczyna sie od 0): ";
        cin >> A;
        cout << "Podaj indeks koncowy (B): ";
        cin >> B;
        drukuj(A, B);
    }
    if (wybor == 3) prosteMenu(); // Powrot do menu glownego.
}

void prosteMenu() {
    int wybor = 0;
    cout << endl << "=== MENU GLOWNE ===" << endl
        << "Wprowadz liczbe i zatwierdz przyciskiem ENTER aby dokonac wyboru" << endl
        << "[1] Drukowanie Danych" << endl
        << "[2] Wprowadzanie Danych" << endl
        << "[3] Wyjscie" << endl;
    while (wybor != 1 && wybor != 2 && wybor != 3) {
        cout << endl << "Wybieram: ";
        cin >> wybor;
    }
    if (wybor == 1) drukMenu();
    if (wybor == 2) podajDane();
    if (wybor == 3) {
        cout << endl << "Dobranoc" << endl;
        exit(0); // Zakonczenie dzialania programu
    }
}

// Main do testow
int main() {
	/*
	// 1
	cout << "1" << endl;
	drukuj();
	
	// 2
	cout << endl << "2" << endl;
	cout << "=== SORTOWANIE ===" << endl << endl;
	sortuj();
	drukuj();

	// 3
	cout << endl << "3" << endl;
	drukuj(3, 2);
	
	// 4
	cout << endl << "4" << endl;
	drukujMlodszychNiz(50);
	
	// 5
	cout << endl << "5" << endl;
	podajDane();
	*/
	// 6
    prosteMenu();
    return 0;
}

