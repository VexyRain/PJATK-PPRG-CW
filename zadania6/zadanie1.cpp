/*
Zadanie 1
Stwórz strukturę o nazwie Punkt, reprezentującą punkt na płaszczyźnie za pomocą
współrzędnych x i y. Napisz funkcję, która przyjmuje dwa punkty i oblicza odległość między
nimi.
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Punkt{
	int x;
	int y;
};

Punkt jeden = {1, 0};
Punkt dwa = {5, 8};

double obliczOdleglosc(Punkt pierwszy, Punkt drugi){
	//cout << endl << "Pierwszy pkt: [x: " << pierwszy.x << "] [y:" << pierwszy.y << "]" << endl;
	//cout << "Drugi pkt: [x: " << drugi.x << "] [y:" << drugi.y << "]" << endl;
	return sqrt((drugi.x - pierwszy.x) * (drugi.x - pierwszy.x) + (drugi.y - pierwszy.y) * (drugi.y - pierwszy.y));
}

//Main do testów
int main(){
	cout << "Odleglosc miedzy punktami wynosi: " << obliczOdleglosc(jeden, dwa) << endl;
	return 0;
}