// ### Zadanie 3 ###
// Dla zadanego N, napisz program wyliczajacy N-ta liczbe Fibonacciego.

#include <iostream>
using namespace std;

int main() {
    int wyraz = 0;
    //Input od uzytkownika
    cout << "Prosze podac wyraz ciagu Fibonacciego, ktory mam obliczyc: " << endl;
    cin >> wyraz;
    cout << "liczenie dla " << wyraz << endl;
    //Kontrola tego czy jest podana jakakolwiek liczba
    if (wyraz == NULL) {
        cout << "Cos sie nie zgadza... Sproboj ponownie" << endl;
        return(200);
    }
	//Dwa pierwsze wyrazy sa zdefiniowane we wzorze, dlatego nie sa liczone.
    if (wyraz == 0) {
        cout << "0";
    }
    else if (wyraz == 1) {
        cout << "1";
    }
    //Obliczanie F(n-1) + F(n-2)
    else {
        int poprzedni1 = 1;
        int poprzedni2 = 1;
        for (int i = 1; i < (wyraz - 1); i++) {
            //cout << poprzedni1 << " " << poprzedni2 << endl;
            int aktualny = poprzedni1 + poprzedni2;
            poprzedni2 = poprzedni1;
            poprzedni1 = aktualny;
        }
        cout << poprzedni1;
    }
    cout << endl;

}