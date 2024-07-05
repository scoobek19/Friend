#include<iostream>
#include<string>
#include<conio.h>
#include<windows.h>
#include "interfejs/Intr2.h"

using namespace std;

void Powitanie(){
    cout<<"Witaj w naszym programie!"<<endl;
    cout<<"Jest to ksiazka kontatkow"<<endl;
}

void Dewiza(){
    int n = 1;
    cout<<"FRienda v1.0"<<endl;
    cout<<"Wybierz funkcje: "<<endl;
    cout<<"1. Dodaj znajomego"<<endl;
    cout<<"2. Usun znajomego"<<endl;
    cout<<"3. Wyswietl danego znajomego"<<endl;
    cout<<"4. Wyswietl wszystkich znajomych"<<endl;
    cout<<"5. Odczytanie zbioru z pliku"<<endl;
    cout<<"6. Zapisanie zbioru do pliku"<<endl;
    cout<<"7. Dodaj wypożyczenie"<<endl;
    cout<<"8. Wypisz wypożyczenia"<<endl;
    cout<<"9. Pomoc"<<endl;
    cout<<"10. Wyjdz"<<endl;
}
int main(){
    SetConsoleOutputCP(65001);

    int i=1;
    Powitanie();
    Ksiazka ks;

    while (i == 1) {
        Dewiza();

        int a = 0;
        try {
            cin >> a;

            if (a > 10 || a < 1) {
                cout << "Niepoprawny numer" << endl;
                continue;
            }

        } catch (exception &err) {
            cout << "Niepoprawne dane!" << endl;
            continue;
        } catch (int ama) {
            cout << "Liczba spoza zakresu" << endl;
            continue;
        }
		switch (a){

            case 1:
                intr2::dodawanie(ks);
				break;

			case 2:
                intr2::usuwanie(ks);
				break;

            case 3:
                intr2::wyszuk_konk(ks);
                break;

            case 4:
                intr2::wyszuk_wszyst(ks);
                break;

            case 5:
                intr2::odczyt(ks);
                break;

            case 6:
                intr2::zapisz(ks);
                break;
            case 7:
                intr2::dodaj_wypozyczenie(ks);
                break;
            case 8:
                intr2::wypisz_wypozyczenia(ks);
                break;
            case 9:
                intr2::pomoc();
                break;
            case 10:
                intr2::wyjdz(i);
                break;
            default:
                cout<<"Dupson"<<endl;
                break;
        }
        if(i==1) {
            cout << "Nacisnij dowolny klawisz by wrocic do menu" << endl;
            getch();
            system("cls");
        }
	}


}
