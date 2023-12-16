/*
Zadanie 1
Napisz funkcję, która posortuje tablicę jednowymiarową za pomocą algorytmu sortowania
szybkiego. Funkcja powinna działać na tablicy globalnej
*/



#include <iostream>
using namespace std;

//Tablica globalna
int tablica[] = { 9, 3, 4, 2, 1, 8 };
int wlkTab = 6;

void drukTab(){
	cout << endl << "Tablica o wymiarze " << wlkTab << " ma wartosci:" << endl;
	for(int i = 0; i < wlkTab; i++){
		cout << tablica[i] << " ";
	}
}

//Quicksort
int dziel(int start, int end){
	int pivot = tablica[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++){
		if (tablica[i] <= pivot)
			count++;
	}
	int pivotIndex = start + count;
	swap(tablica[pivotIndex], tablica[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex){

		while (tablica[i] <= pivot) {
			i++;
		}

		while (tablica[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex){
			swap(tablica[i++], tablica[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int start, int end){
	if (start >= end)
		return;
	int p = dziel(start, end);
	quickSort(start, p - 1);
	quickSort(p + 1, end);
}

//Main
int main(){
	drukTab();
	cout << endl << endl << "Sortowanie" << endl;
	quickSort(0, wlkTab - 1);
	drukTab();
	
	return 0;
}
