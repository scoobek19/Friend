//
// Created by lip_k on 4/15/2024.
//

#include <fstream>
#include "utils.h"
#include "../interfejs/Intr2.h"
#include <json.hpp>
using json = nlohmann::json;

Ksiazka Utils::wczytaj(const string &path) {

    ifstream plik(path);
    json json1 = json::parse(plik);

    Ksiazka ksiazka;
    int i = 1;

    string name;
    string sur;
    string numb;
    for (const json &osobaNode : json1) {
        try {
            name = osobaNode.value("imie", "not found");
            sur = osobaNode.value("nazw", "not found");
            numb = osobaNode.value("num", "not found");
            if (name != "not found" && sur != "not found" && numb != "not found")
                ksiazka.dodaj(Osoba(name, sur, numb));
            else {
                cout << endl;
                cout << "znajomy nr " << i << " nie wczytany! blad w formacie" << endl;
                cout << endl;
            }
        } catch (const exception& e) {
            cout << "W UTLISACH" << endl;
            exit(3);
        }
        i++;
    }


    cout<<endl;
    cout<<"Pomyslnie wczytano"<<endl;
    cout<<endl;

    if (ksiazka.lista().size()==0){
        cout<<"pusty plik lub niepoprawne dane, brak znajomych"<<endl;
    }
    return ksiazka;
}

void Utils::zapisz(const string& path,const  Ksiazka& ksiazka) {
    ofstream plik(path, ios::trunc);
    vector<json>papa;
    for (const auto & wypozyczenie : ksiazka.lista()) {
        papa.push_back(to_json(wypozyczenie));
    }

    json::array_t resultObject(papa);

    plik<<resultObject;
    cout<<"Zapisywanie przebieglo pomyslnie"<<endl;
    cout<<endl;


}

json Utils::to_json(const Osoba& przyj){
    return json{{"imie" , przyj.getImie()}, {"nazw", przyj.getNazw()}, {"num", przyj.getNum()}};
}
