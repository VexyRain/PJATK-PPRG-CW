/*
### Zadanie 1 ###
 Poproś użytkownika o wprowadzenie pierwszego elementu 
 ciągu arytmetycznego, różnicy oraz liczby elementów, 
 a następnie oblicz sumę tego ciągu
*/

#include <iostream>
using namespace std;

int main(){
	//Wprowadzanie danych przez użytkownika
	int pElem, roznice, lElem;
	string wariacje[3] = {"pierwszy element", "roznice", "liczbe elementow"};
	for (string x : wariacje){
		cout << "Prosze wprowadzic " << x << " ciagu arytmetycznego, dla ktorego mam obliczyc sume:" << endl;
		switch(int(x[0])){
			case int('p'):
				cin >> pElem;
				break;
			case int('r'):
				cin >> roznice;
				break;
			case int('l'):
				cin >> lElem;
				break;
		}
	}
	int wartOstElem = pElem;
	for(int i = 1 ; i < lElem ; i++){
		wartOstElem += wartOstElem + roznice;
		cout << "g" << endl;
	}
	cout << "Suma to: "<< wartOstElem;
}