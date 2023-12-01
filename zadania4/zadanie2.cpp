/*
Zadanie 2
Napisz iteracyjną i rekurencyjną wersję funkcji obliczającej:
- dwumian Newtona
- największy wspólny dzielnik (algorytm Euklidesa)
Opierając się na programie z wykładu, zmierz czas działania algorytmów i określ granice
stosowalności w zależności od wartości parametrów.
*/

#include <iostream>
#include <cmath>
#include <chrono> //jak w zadaniu, kod z https://github.com/tborzyszkowski/PPrg_Cpp/blob/main/PPRG_03/RecursionTiming/RecursionTiming.cpp
using namespace std;

//Dwumian Newtona - iteracyjnie

int iterSilnia(int liczba){
	int lSilnia = 1;
	for(int i = 1; i <= liczba; i++){
		lSilnia = i * lSilnia;
	}
	return lSilnia;
}

int iterNewton(int n, int k){
	if(k == 0 || k == n)return 1; //Z definicji
	return iterSilnia(n) / ( iterSilnia(k) * iterSilnia(n - k) );
}

//Dwumian Newtona - rekurencyjnie

int rekurSilnia(int liczba){
	if(liczba <= 1)return 1;
	return liczba * rekurSilnia(liczba - 1);
}

int rekurNewton(int n, int k){
	if(k == 0 || k == n)return 1; //Z definicji
	return rekurSilnia(n) / ( rekurSilnia(k) * rekurSilnia(n - k) );
}

//Algorytm Euklidesa - iteracyjnie

int iterEuklid(int a, int b){
	int reszta = a%b;
	while(reszta != 0){
		a = b;
		b = reszta;
		reszta = a%b;
	}
	return b;
}

//Algorytm Euklidesa - rekurencyjnie

int rekurEuklid(int a, int b){
	int reszta = a%b;
	if(reszta == 0)return b;
	return rekurEuklid(b, reszta);
}

int main(){
	int n = 8;
	int k = 2;
	int a = 282;
	int b = 78;
	auto begin = chrono::high_resolution_clock::now(); //czasomierz
	cout << "[iteracyjnie]Dwumian Newtona z n = " << n << " i k = " << k << " to " << iterNewton(n, k);
	auto end = chrono::high_resolution_clock::now(); auto elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin); cout << " [" << elapsed.count() << "s]" << endl; begin = chrono::high_resolution_clock::now(); //czasomierz
	cout << "[iteracyjnie]NWD dla a = " << a << " i b = " << b << " to " << iterEuklid(n, k);
	end = chrono::high_resolution_clock::now(); elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin); cout << " [" << elapsed.count() << "s]" << endl; begin = chrono::high_resolution_clock::now(); //czasomierz
	cout << "[rekurencyjnie]Dwumian Newtona z n = " << n << " i k = " << k << " to " << rekurNewton(n, k);
	end = chrono::high_resolution_clock::now(); elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin); cout << " [" << elapsed.count() << "s]" << endl; begin = chrono::high_resolution_clock::now(); //czasomierz
	cout << "[rekurencyjnie]NWD dla a = " << a << " i b = " << b << " to " << rekurEuklid(n, k);
	end = chrono::high_resolution_clock::now(); elapsed = chrono::duration_cast<chrono::duration<float>>(end - begin); cout << " [" << elapsed.count() << "s]" << endl; //czasomierz
}