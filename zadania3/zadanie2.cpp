/*
### Zadanie 2 ###
 Stwórz prostą grę, w której użytkownik musi odgadnąć hasło. 
 Jeśli poda nieprawidłowe hasło, pozwól mu próbować ponownie
 za pomocą pętli.
*/

#include <iostream>
using namespace std;

int main(){
	string haslo = "test";
	cout << "Odgadnij haslo!" << endl;
	while(true) {
		string proba;
		cin >> proba;
		if (proba == haslo){
			cout << "Gratulacje, udalo Ci sie!";
			break;
		}
		cout << "Nie udalo Ci sie odgadnac hasla. Sproboj ponownie: " << endl;
	}
}