//
// Created by lip_k on 4/15/2024.
//

#include "Osoba.h"

    void Osoba::setImie(string im1){
        imie = im1;
    }

    string Osoba::getImie() const {
        return imie;
    }

    void Osoba::setNazw(string naz1){
        nazwisko=naz1;
    }

    string Osoba::getNazw() const {
        return nazwisko;
    }

    void Osoba::setNum(string num1){
        numer=num1;
    }

    string Osoba::getNum() const {
        return numer;
    }

    void Osoba::setID(int id1) {
        ID=id1;
    }

    int Osoba::getID() const {
        return ID;
    }

    Osoba::Osoba(string im1, string naz1, string num1) {
        setID(8);
        setImie(im1);
        setNazw(naz1);
        setNum(num1);
}

string Osoba::to_string() const {
    string s;
    s.append(std::to_string(ID));
    s.append("    ");
    s.append(imie);
    s.append("    ");
    s.append(nazwisko);
    s.append("    ");
    s.append(numer);
    return s;

}
