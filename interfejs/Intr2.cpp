//
// Created by lip_k on 4/12/2024.
//
#include "Intr2.h"

#include <sstream>

static std::string formatuj_czas(const std::chrono::system_clock::time_point &t) {
    std::time_t time = std::chrono::system_clock::to_time_t(t);
    char time_buff[30] = {0};
    strftime(time_buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&time));
    return std::string(time_buff);
}

intr2::intr2()= default;

    void intr2::zapisz(Ksiazka &k) {
        string path = "d";
        path = wpisz_path();
        Utils::zapisz(path,k);
    }

    void intr2::odczyt(Ksiazka& k) {
        string path = "d";
        path = wpisz_path();
        k = Utils::wczytaj(path);
    }

    void intr2::dodawanie(Ksiazka &k){
        string im,naz,nb;
        cout<<"Podaj w kolejnych linijkach: "<<endl;
        cout<<"1.Imie"<<endl;
        cout<<"2.Nazwisko"<<endl;
        cout<<"3.Numer"<<endl;
        im = wpisz_argument("imie");
        naz = wpisz_argument("nazw");
        nb = wpisz_argument("num");
        k.dodaj(Osoba(im, naz, nb));
        cout<<endl;
        cout<<"Pomyslnie dodano znajomego!"<<endl;
        cout<<endl;
    }

    void intr2::usuwanie(Ksiazka &k) {
        if(k.czy_pusta()){
            cout<<"Zbior jest pusty!"<<endl;

        }
        else {
            vector<Osoba> znalezione;
            string nazw = wpisz_argument("nazwisko");

            for (const auto& wypo: k.lista()) {
                if (wypo.getNazw() == nazw) {
                    znalezione.push_back(wypo);
                }
            }
            if (znalezione.size() == 1) {
                string decyzja;
                cout << "Czy napewno usunac?" << endl;
                cout << znalezione[0].to_string() << endl;
                while (true) {
                    cout << "Odpowiedz TAK lub NIE" << endl;
                    cin >> decyzja;
                    if (decyzja == "TAK") {
                        k.usun(znalezione[0].getID());
                        cout << endl;
                        cout << "Pomyslnie usunieto";
                        cout << endl;
                        znalezione.clear();
                        break;
                    } else if (decyzja == "NIE") {
                        cout << "Nie usunieto zadnego znajomego" << endl;
                        znalezione.clear();
                        break;
                    } else if (decyzja.empty()) {
                        cout << "Nie wpisano decyzji!" << endl;
                        cout << endl;
                    } else {
                        cout << "Niepoprawny format odpowiedzi" << endl;
                    }
                }
            } else if (znalezione.empty()) {
                cout << "Nie znaleziono znajomego o podanym nazwisku" << endl;
                cout << "Mozliwa literowka lub podanego nazwisko nie figuruje na liscie" << endl;
            } else {
                cout << "Znaleziono nastepujacych znajomych:" << endl;
                int i = 1;
                for (auto wypo: znalezione) cout << i++ << " " << wypo.to_string() << endl;
                string decyzja;

                int decyzja_int;
                while (true) {
                    cout << "Ktorego usunac?" << endl;
                    cout << "Jezeli nie chcesz usuwac wpisz NIE" << endl;
                    cin >> decyzja;
                    if (decyzja == "NIE") {
                        cout << "Nie usunalem zadnego znajomego" << endl;
                        cout << endl;
                        znalezione.clear();
                        break;
                    } else {
                        regex pattern(R"(\d{1,6})");
                        if(regex_match(decyzja,pattern)==1){
                            cout<<"Niepoprawny format danych! sprobuj jeszcze raz"<<endl;
                            continue;
                        }
                        try {
                            decyzja_int = stoi(decyzja);
                        } catch (exception &e) {
                            cout << "Niepoprawny format danych! sprobuj jeszcze raz" << endl;
                            continue;
                        }

                        if (decyzja_int < 1 || decyzja_int > znalezione.size()) {
                            cout << "Numer poza zakresem znalezionych!" << endl;
                            cout << "Sprobuj jescze raz" << endl;
                            continue;
                        }else{
                        //else if (decyzja_int <= znalezione.size() && decyzja_int > 0) {
                            cout << "Znajomy usuniety!" << endl;
                            cout << endl;
                            znalezione.clear();
                            break;
                        }
                    }
                }

            }
        }
    }

    void intr2::wyszuk_konk(Ksiazka& k){
        if(k.czy_pusta()){
            cout<<"Zbior jest pusty!"<<endl;

        }
        else {
            vector<Osoba> znalezione;
            cout << endl;
            string nazw = wpisz_argument("nazwisko");
            for (auto wypo: k.lista()) {
                if (wypo.getNazw() == nazw) {
                    znalezione.push_back(wypo);
                    cout << wypo.to_string() << endl;
                }
            }
            if (znalezione.empty()) {
                cout << "Nie znaleziono znajomych" << endl;
                cout << endl;
            }
            getchar();
        }

    }

    void intr2::wyszuk_wszyst(Ksiazka& k ){
        if (!k.czy_pusta()) {
            cout << "Wypisuje caly zbior:" << endl;
            cout << endl;
            for (auto &wypo: k.lista()) {
                cout << wypo.to_string() << endl;
            }
        } else {
            cout << "Zbior jest pusty!" << endl;

        }
    }

     void intr2::pomoc() {
         cout<<"pomoc"<<endl;
        cout<<endl;
        cout<<"1. Funkcja dodawanie dodaje znajomego do zbioru"<<endl;
        cout<<" By dzialala prawidlowo musisz wpisac: imie, "<<endl;
        cout<<" nazwisko i numer po przejsciu do menu funkcji"<<endl;
        cout<<"2. Funkcja usuwanie usuwa znajomego ze zbioru"<<endl;
        cout<<" By dzialala prawidlowo musisz podac pelne nazwisko"<<endl;
        cout<<"Osoby ktora chcesz usunac, jezeli takiej nie ma"<<endl;
        cout<<"Nikt nie zostanie usuniety. Jesli jest kilka osob"<<endl;
        cout<<" o takim nazwisku, to pokaze wszystkich i ty "<<endl;
        cout<<"zdecydujesz ktorego usunac"<<endl;
        cout<<"3. Wyszukaj znajomego wyszukuje danego znajomego"<<endl;
        cout<<"By dzialala prawidlowo musisz wpisac pelnie nazwisko"<<endl;
        cout<<"Osoby ktora chcesz wyszukac. Jesli jest kilka osob"<<endl;
        cout<<"o tym nazwisku, to pokaze wszystkie"<<endl;
        cout<<"4. Wyszukaj wszystkich, pokazuje pelna liste znajomych"<<endl;
    }

     void intr2::wyjdz(int &i) {
        cout << "Dziekujemy za skorzystanie z programu!" << endl;
        cout << "Czesc!" << endl;
        i = 2;
    }

    string intr2::wpisz_numer(){
        string argus = "aaaa";
        cin>>argus;
        int d=0;
        regex pattern_num(R"((\d{1,12}))");
        while (regex_match(argus,pattern_num)==1) {
            if(d>0){
                cout<<"Niepoprawny format lub za dlugo numer!"<<endl;
            }
            try {
                cout << "Wpisz numer:" << endl;
                cin >> argus;
            } catch (overflow_error &o) {
                cout << "overflow!" << endl;
            }
            d++;
        }
        return argus;
    }

    string intr2::wpisz_argument(string brr) {
        string argus;
        cin>>argus;
        int d=0;
        regex pattern_nazwisko("\\[a-zA-Z]{1,20}");
        while (regex_match(argus,pattern_nazwisko)==1) {
            if(d>0){
                cout<<"Niepoprawny format!"<<endl;
            }
            try {
                cout << "Wpisz "<<brr<<":" << endl;
                cin >> argus;
            } catch (overflow_error &o) {
                cout << "overflow!" << endl;
            }
            d++;
        }
        for(auto &x:argus) {
            x = tolower(x);
        }
        argus[0] = toupper(argus[0]);
        return argus;
    }


    string intr2::wpisz_path() {
        string argus = "blad";
        try {
            cout<<endl;
            cout << "Wpisz sciezke do pliku:" << endl;
            cin >> argus;
        } catch (exception &e) {
            cout << "overflow!" << endl;
        }
        return argus;
    }

    void intr2::dodaj_wypozyczenie(Ksiazka &k) {
        wyszuk_wszyst(k);

        int idWlasciciel, idPozyczajacy;
        string tytul_ksiazki;

        cout << "Podaj ID właściciela książki: ";
        cin >> idWlasciciel;
        cout << "Podaj ID wypożyczającego: ";
        cin >> idPozyczajacy;
        cout << "Podaj tytuł książki: ";
        cin.ignore();
        getline(cin, tytul_ksiazki);

        try {
            k.wypozycz(
                    k.znajdz_osobe(idWlasciciel),
                    k.znajdz_osobe(idPozyczajacy),
                    tytul_ksiazki
            );
            cout << "Wypożyczono ksiązkę" << endl;
        } catch (string blad) {
            cout << "Błąd: " << blad << endl;
        }
    }

    void intr2::wypisz_wypozyczenia(Ksiazka &k) {
        cout << "Wypisuję wypożyczenia: " << endl;
        int i = 0;

        cout << "Nr Czas wypożyczenia Wypożyczający      Właściciel      Tytuł" << endl;
        for (auto &wypozyczenie : k.wszystkie_wypozyczenia()) {
            cout << i << "  "
                 << formatuj_czas(wypozyczenie.czas_wypozyczenia) << "  "
                 << wypozyczenie.wypozyczajacy.getImie() << " " << wypozyczenie.wypozyczajacy.getNazw() << "  "
                 << wypozyczenie.wlasciciel.getImie() << " " << wypozyczenie.wlasciciel.getNazw() << "  "
                 << wypozyczenie.tytul_ksiazki << endl;
            i++;
        }
        cout << "Wypisano wypożyczenia" << endl;
    }