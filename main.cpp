#include<iostream>
#include<string>
#include<conio.h>
#include "interfejs/Intr2.h"

using namespace std;

void Powitanie(){
    cout<<"Witaj w naszym programie!"<<endl;
    cout<<"Jest to ksiazka kontatkow"<<endl;
}

void Dewiza(){
    system( "cls" );
    cout<<"FRienda v1.0"<<endl;
    cout<<"Wybierz funkcje: "<<endl;
    cout<<"1. Dodaj znajomego"<<endl;
    cout<<"2. Usun znajomego"<<endl;
    cout<<"3. Wyswietl danego znajomego"<<endl;
    cout<<"4. Wyswietl wszystkich znajomych"<<endl;
    cout<<"5. Odczytanie zbioru z pliku"<<endl;
    cout<<"6. Zapisanie zbioru do pliku"<<endl;
    cout<<"7. Pomoc"<<endl;
    cout<<"8. Wyjdz"<<endl;
}
int main(){
    int i=1;
    Powitanie();
    Ksiazka ks;
    string fun;

	while(i == 1){
        Dewiza();
		cin>>fun;
        system("cls");

        int a = 0;
		try{
            regex pattern_arg(R"((\d)");
            if(regex_match(fun,pattern_arg)!=0){
                cout<<"Niepoprawny argument"<<endl;
            }
		     a = stoi(fun);
             if(a>8 || a<1){
                 cout<<"Niepoprawny numer"<<endl;
                 continue;
             }

       }catch(exception &err){
            cout<<"Niepoprawne dane!"<<endl;
            continue;
       }catch(int ama){
            cout<<"Liczba z poza zakresu"<<endl;
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
                intr2::pomoc();
                break;

            case 8:
                intr2::wyjdz(i);
                break;
            default:
                cout<<"Dupson"<<endl;
                break;
        }
        if(i==1) {
            cout << "Nacisnij dowolny klawisz by wrocic do menu" << endl;
            getch();
        }
	}


}
