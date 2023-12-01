/*
Zadanie 1
Napisz funkcję, która sprawdza, czy zadana jako parametr liczba całkowita jest sześcianem
pewnej liczby całkowitej. Wynikiem działania funkcji ma być jeden, jeśli liczba jest
sześcianem oraz zero w przeciwnym wypadku. Przetestuj funkcję na wybranych
przykładach.
*/

#include <iostream>
#include <cmath>
using namespace std;

int czySzescian(int liczba) {
    int pierwiastek = round(cbrt(liczba));
    if (pow(pierwiastek, 3) == liczba)return 1;
    return 0;
}

void wynik(int input){
	cout << "Wnynik dla " << input << " to " << czySzescian(input) << endl;
}

int main(){
	wynik(8);
	wynik(15);
	wynik(64);
	wynik(66);
}