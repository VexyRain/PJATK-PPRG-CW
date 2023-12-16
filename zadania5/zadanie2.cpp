/*
Zadanie 2
Napisz funkcję, która realizuje mnożenie macierzy. Pamiętaj, że wymiary powinny być
zgodne.
*/

//Jako że w zadaniu nie ma napisane jakie macierze, będą mnożone 2x2

#include <iostream>
using namespace std;

//Macierz A
int kolumnyA = 2; int wierszeA = 2;
int arrA[2][2] = {{1, 2},
                  {3, 4}};

//Macierz B
int kolumnyB = 2; int wierszeB = 2;
int arrB[2][2] = {{3, 3},
                  {3, 3}};

//Rozwiązanie zadania:
void mnozMacierze() {
    //Sprawdzenie wymiarów
    if (kolumnyA != wierszeB){
        cout << "Niepoprawne wymiary macierzy" << endl;
        return;
    }

    int wynik[2][2] = {{0, 0},
                       {0, 0}};

    for (int y = 0; y < wierszeA; y++){
        for (int x = 0; x < kolumnyB; x++){
            for (int k = 0; k < kolumnyA; k++){
                wynik[y][x] += arrA[y][k] * arrB[k][x];
            }
        }
    }

    for(int y = 0; y < wierszeA; y++){
        for(int x = 0; x < kolumnyB; x++){
            cout << wynik[y][x] << " ";
        }
        cout << endl;
    }
}

//Main żeby działało
int main(){
    mnozMacierze();
    return 0;
}
