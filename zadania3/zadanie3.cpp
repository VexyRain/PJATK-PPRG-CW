
/*
### Zadanie 3 ###
 Stwórz grę, w której użytkownik rywalizuje z komputerem 
 w grze "kamień-papier-nożyce".
 Program powinien umożliwiać wielokrotną rundę gry.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool piszWybor(int wybor){
	switch (wybor) {
            case 1:
                cout << "Kamien" << endl;
                break;
            case 2:
                cout << "Papier" << endl;
                break;
            case 3:
                cout << "Nozyce" << endl;
                break;
            default:
                cout << "Niepoprawny wybor. Spróbuj ponownie." << endl;
                return true;
        }
        return false;
}

int main() {
    srand(time(0)); //Inicjalizacja generatora liczb losowych

    while(true) {
        //Wybór użytkownika
        cout << "Twoj wybor (1 - kamien, 2 - papier, 3 - nozyce): ";
        int graczWybor;
        cin >> graczWybor;

        //Wybór komputera
        int kompWybor = rand() % 3 + 1;

        //Wyświetlenie wyborów
        cout << "Twoj wybor: ";
        if(piszWybor(graczWybor))continue;
		
		cout << "Wybor komputera: ";
        piszWybor(kompWybor);
		
		cout << endl << endl << endl << endl; //Przestrzeń dla czytelności
        //Sprawdzenie wyniku rundy
        if (graczWybor == kompWybor) {
            cout << "Remis!" << endl << endl;
        } else if ((graczWybor == 1 && kompWybor == 3) ||
                   (graczWybor == 2 && kompWybor == 1) ||
                   (graczWybor == 3 && kompWybor == 2)) {
            cout << "Tryiumf ludzkosci nad maszyna!" << endl << endl;
        } else {
            cout << "Porazka ludzkosci." << endl << endl;
        }
        char gramyDalej = 'x';
        cout << "Gramy dalej? (t - tak; [cokolwiek innego] - nie, zakoncz program)" << endl;
        cin >> gramyDalej;
        if (gramyDalej == 'n')break;
    }

    cout << "Dowidzenia." << endl;
    return 0;
}
